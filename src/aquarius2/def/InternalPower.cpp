#include "InternalPower.h"
#include "../client/InternalTaskVisitor.h"
#include "include/wrapper/cef_closure_task.h"
#include "include/cef_callback.h"
#include "include/base/cef_callback_forward.h"
#include "include/base/cef_template_util.h"
#include "include/base/internal/cef_callback_internal.h"
#include "include/base/cef_bind.h"
#include "include/cef_browser.h"
#include "InternalPage.h"
#include "include/capi/cef_parser_capi.h"
#include "auth_ecef_protocol.h"
#include <cpprest/json.h>
#include <codecvt>
#include <Windows.h>
#include <wincrypt.h>
#include "internalDef.h"

using namespace web;
using namespace websockets;
using namespace websockets::client;


namespace Local {
	bool initialized = false;
	CefRefPtr<InternalApp> app = nullptr;
	CefRefPtr<InternalHandler> handler = nullptr;

	std::wstring rootDir;
}

InternalPower::InternalPower() {
	
}

InternalPower::~InternalPower() {

}

void InternalPower::Initialize(int mode) {
	TCHAR buffer[MAX_PATH];

	std::wstring path;
	GetModuleFileName(GetModuleHandle(NULL), buffer, MAX_PATH);
	auto end = wcsstr(buffer, L"e.exe");
	if (!end) {
		return;
	}
	Local::rootDir.assign(buffer, end - buffer);
	
	InternalApp::GetInstance()->SetMode(mode);

	if (!Local::initialized) {
		CefMainArgs mainArgs(::GetModuleHandle(NULL));
		CefSettings settings;
		CefString(&settings.browser_subprocess_path) = L"spare-proc.exe";
		CefString(&settings.locale) = L"zh-CN";
		settings.multi_threaded_message_loop = true;
		CefExecuteProcess(mainArgs, InternalApp::GetInstance(), nullptr);
		CefInitialize(mainArgs, settings, InternalApp::GetInstance(), nullptr);
		Local::initialized = true;
		return;
	}
	if (mode) {
		CefPostTask(TID_UI, base::Bind(&InternalApp::OnContextInitialized, InternalApp::GetInstance()));
	}
}

void* InternalPower::GetCmdNames(HWND hWnd) {
	CefRefPtr<CefWaitableEvent> waitable = CefWaitableEvent::CreateWaitableEvent(false, false);
	CefRefPtr<InternalHandler> client = InternalHandler::GetInstance();
	void* data = NULL;
	CefPostTask(TID_UI, base::Bind(&InternalHandler::GetMetadata, client, waitable, &data,hWnd));
	WaitAwaking(waitable);
	if (!data) {
		WaitTimeout(2000);
	}
	return data;
}

InternalApp::InternalApp() {

}

InternalApp::~InternalApp() {

}

CefRefPtr<InternalApp> InternalApp::GetInstance() {
	if (!Local::app) {
		Local::app = new InternalApp();
	}
	return Local::app;
}

void InternalApp::OnContextInitialized() {
	if (_mode) {
		wchar_t buffer[MAX_PATH];
		POINT pt;
		CefWindowInfo windowInfo;
		CefBrowserSettings settings;

		::GetCursorPos(&pt);
		windowInfo.SetAsPopup(NULL, L"ECEF Authorization");

		std::wstring url(Local::rootDir);
		url += L"ecef_runtime\\authorization\\signin.html";

		if (pt.y < 250) {
			pt.y = 250;
		}
		else {
			pt.y -= 250;
		}

		if (pt.x < 190) {
			pt.x = 190;
		}
		else {
			pt.x -= 190;
		}

		windowInfo.x = pt.x;
		windowInfo.y = pt.y;
		windowInfo.width = 380;
		windowInfo.height = 680;

		CefBrowserHost::CreateBrowser(windowInfo, InternalHandler::GetInstance(), url, settings, nullptr, nullptr);
	}
}

InternalHandler::InternalHandler():
	_hasGui(false),
	_hasConnected(false),
	_retMetadata(nullptr),
	_waitable(nullptr)
{

}

InternalHandler::~InternalHandler() {

}

CefRefPtr<InternalHandler> InternalHandler::GetInstance() {
	if (!Local::handler) {
		Local::handler = new InternalHandler();
	}
	return Local::handler;
}

void InternalHandler::OnAfterCreated(CefRefPtr<CefBrowser> browser) {

}

void InternalHandler::OnBeforeClose(CefRefPtr<CefBrowser> browser) {
	_mainFrame = nullptr;
	_hasGui = false;

	DoClose();
}

bool InternalHandler::OnProcessMessageReceived(CefRefPtr<CefBrowser> browser,
	CefRefPtr<CefFrame> frame,
	CefProcessId source_process,
	CefRefPtr<CefProcessMessage> message) {
	CefString name = message->GetName();
	if (name == L"IPC_AUTH_MESSAGE") {
		CefRefPtr<CefListValue> params = message->GetArgumentList();

		_hasGui = true;
		_mainFrame = frame;

		int command = params->GetInt(0);
		if (command == ECEF_AUTH_CMD_LOGIN) {
			OnCommandLogin(frame, params->GetList(1));
		}
		else if (command == ECEF_AUTH_CMD_PAY) {
			OnCommandPay(frame, params->GetList(1));
		}
		else if (command == ECEF_AUTH_CMD_SIGNUP) {
			OnCommandSignup(frame, params->GetList(1));
		}
		else if (command == ECEF_AUTH_CMD_RESET) {
			OnCommandReset(frame, params->GetList(1));
		}
		return true;
	}
	return false;
}

void InternalHandler::GetMetadata(CefRefPtr<CefWaitableEvent> waitable, void** ret, HWND hWnd) {
	TCHAR buffer[MAX_PATH];
	std::wstring username;
	std::wstring password;
	std::wstring path(Local::rootDir);

	path += L"config.ini";

	_waitable = waitable;
	_retMetadata = ret;
	_outputWnd = hWnd;

	if (_cmdNamePointerArrays.empty()) {

		GetPrivateProfileString(L"ecef", L"username",NULL, buffer, MAX_PATH, path.c_str());
		username = buffer;

		GetPrivateProfileString(L"ecef", L"password", NULL, buffer, MAX_PATH, path.c_str());
		password = buffer;

		if (username.length() < 6 || password.length() < 6) {
			SetError(L"未注册授权许可证或许可证已过期。");
			_waitable->Signal();
			return;
		}

		if (!Connect()) {
			SetError(L"连接服务器失败!");
			_waitable->Signal();
		}

		Login(username, password);
		return;
	}

	*ret = &_cmdNamePointerArrays[0];
	waitable->Signal();
}

void InternalHandler::SendAuthMessage(CefRefPtr<CefFrame> frame, int command, CefRefPtr<CefListValue> params) {
	CefRefPtr<CefProcessMessage> message = CefProcessMessage::Create(L"IPC_AUTH_MESSAGE");
	CefRefPtr<CefListValue> arguments = message->GetArgumentList();
	arguments->SetInt(0, command);
	if (params) {
		arguments->SetList(1, params);
	}
	frame->SendProcessMessage(PID_BROWSER, message);
}

void InternalHandler::OnCommandLogin(CefRefPtr<CefFrame> frame, CefRefPtr<CefListValue> params) {
	CefString username = params->GetString(0);
	CefString password = params->GetString(1);

	if (!_hasConnected) {
		if (!Connect()) {
			SetError(L"连接服务器失败!");
			return;
		}
	}

	SetOk(L"正在登录中...");
	Login(username, password);
}

void InternalHandler::OnCommandPay(CefRefPtr<CefFrame> frame, CefRefPtr<CefListValue> params) {
	if (!_hasConnected) {
		SetError(L"未连接到服务器!");
		return;
	}

	bool product = params->GetBool(0);
	if (product) {
		Pay(ECEF_PRODUCT_NORMAL_USED);
	}
	else {
		Pay(ECEF_PRODUCT_FRIEND_USED);
	}
}

void InternalHandler::OnCommandSignup(CefRefPtr<CefFrame> frame, CefRefPtr<CefListValue> params) {
	CefString username = params->GetString(0);
	CefString password = params->GetString(1);

	if (!_hasConnected) {
		if (!Connect()) {
			SetError(L"连接服务器失败!");
			return;
		}
	}

	SetOk(L"正在提交中...");
	Register(username, password);
}

void InternalHandler::OnCommandReset(CefRefPtr<CefFrame> frame, CefRefPtr<CefListValue> params) {
	CefString username = params->GetString(0);
	CefString password = params->GetString(1);
	CefString trade_id = params->GetString(2);

	if (!_hasConnected) {
		if (!Connect()) {
			SetError(L"连接服务器失败!");
			return;
		}
	}

	SetOk(L"正在提交中...");
	Reset(username, password, trade_id);
}

void InternalHandler::Pay(int product) {
	if (!_hasConnected) {
		return;
	}

	json::value params = json::value::object();
	params[APF_PRODUCT] = json::value::number(product);

	SendRequest(AUTH_C_CMD_PURCHASE, params);
}

void InternalHandler::Register(const CefString& username, const CefString& password) {
	if (!_hasConnected) {
		return;
	}

	json::value params = json::value::object();
	params[APF_USERNAME] = json::value::string(username.ToWString());
	params[APF_PASSWORD] = json::value::string(password.ToWString());

	SendRequest(AUTH_C_CMD_REGISTER, params);
}

void InternalHandler::Reset(const CefString& username, const CefString& password, const CefString& trade_id) {
	if (!_hasConnected) {
		return;
	}

	json::value params = json::value::object();
	params[APF_USERNAME] = json::value::string(username.ToWString());
	params[APF_NEW_PASSWORD] = json::value::string(password.ToWString());
	params[APF_TRANSACTION_ID] = json::value::string(trade_id.ToWString());

	SendRequest(AUTH_C_CMD_LOST_PWD, params);
}

bool InternalHandler::Connect() {
	_connection = nullptr;
	_connection = new InternalConnection();

	_connection->wsconn.set_message_handler([this](websocket_incoming_message msg) {
		std::wstring_convert<std::codecvt_utf8<wchar_t>> conv;
		std::string buffer = msg.extract_string().get();
		std::string result;
		std::error_code ec;

		Decode(buffer, result);

		if (result.empty()) {
			SetError(L"连接出现错误, 请重新尝试! 1");
			DoClose();
			return;
		}

		json::value root = json::value::parse(conv.from_bytes(result), ec);
		if (0 != ec.value()) {
			SetError(L"连接出现错误, 请重新尝试! 1");
			DoClose();
			return;
		}

		json::value ret = root[APF_RET];
		int ok = ret[APF_OK].as_integer();
		if (ok != AUTH_ERR_OK) {
			std::wstring err = ret[APF_ERROR].as_string();
			SetError(err);
			if (!_hasGui) {
				DoClose();
				if (_waitable) {
					_waitable->Signal();
				}
			}
			return;
		}

		int command = root[APF_COMMAND].as_integer();
		if (command == AUTH_S_CMD_LOGIN) {
			json::value params = ret[APF_DATA];
			DoLogin(params);

			if (!_hasGui) {
				DoClose();
				if (_waitable) {
					_waitable->Signal();
				}
			}

		}
		else if (command == AUTH_S_CMD_PURCHASE) {
			json::value params = ret[APF_DATA];
			DoPay(params);
		}
		else if (command == AUTH_S_CMD_PURCHASE_CALLBACK) {
			json::value params = ret[APF_DATA];
			DoPayCallback(params);
		}
		else if (command == AUTH_S_CMD_PURCHASE_TIMEOUT) {
			json::value params = ret[APF_DATA];
			DoPayTimeout(params);
		}
		else if (command == AUTH_S_CMD_REGISTER) {
			std::wstring err = ret[APF_ERROR].as_string();
			SetOk(err);
		}
		else if (command == AUTH_S_CMD_LOST_PWD) {
			std::wstring err = ret[APF_ERROR].as_string();
			SetOk(err);
		}
	});

	_connection->wsconn.set_close_handler(
		[this](websocket_close_status close_status,
		const utility::string_t& reason,
		const std::error_code& error)
	{
		_hasConnected = false;
		SetError(L"连接已关闭!");
	});


	try
	{
		_connection->wsconn.connect(ECEF_AUTH_SERVER).wait();
	}
	catch (const std::exception&)
	{
		return false;
	}
	_hasConnected = true;
	return true;
}

void InternalHandler::SendAuthHint(CefRefPtr<CefFrame> frame, const CefString& message, const CefString& color) {
	wchar_t buffer[260];
	if (!color.empty()) {
		swprintf_s(buffer,260, L"(function(){ var hint = document.getElementById('error-show'); hint.innerText = '%s'; hint.style.color='%s'; })();",
			message.c_str(), color.c_str());
	}
	else {
		swprintf_s(buffer, 260, L"(function(){ var hint = document.getElementById('error-show'); hint.innerText = '%s'; hint.removeAttribute('style'); })();",
			message.c_str());
	}
	frame->ExecuteJavaScript(buffer, L"internal_call", 0);

}

bool InternalHandler::RunContextMenu(CefRefPtr<CefBrowser> browser,
	CefRefPtr<CefFrame> frame,
	CefRefPtr<CefContextMenuParams> params,
	CefRefPtr<CefMenuModel> model,
	CefRefPtr<CefRunContextMenuCallback> callback) {
	return true;
}



void InternalHandler::Login(const CefString& username, const CefString& password) {
	std::wstring device = GetDeviceIdentity();

	if (!_hasConnected) {
		return;
	}

	_username = username.ToWString();
	_password = password.ToWString();

	json::value params = json::value::object();
	params[APF_VERSION_ID] = json::value::string(ECEF_AUTH_VERSION);
	params[APF_USERNAME] = json::value::string(username.ToWString());
	params[APF_PASSWORD] = json::value::string(password.ToWString());
	params[APF_MACHINE] = json::value::string(device);
	
	SendRequest(AUTH_C_CMD_LOGIN, params);
}

void InternalHandler::SendRequest(int command, web::json::value params) {
	std::wstring_convert<std::codecvt_utf8<wchar_t>> conv;
	
	json::value root = json::value::object();
	root[APF_ROUTE] = json::value::string(L"ecef");
	root[APF_COMMAND] = json::value::number(command);
	root[APF_PARAMS] = params;

	std::wstring data = root.serialize();

	websockets::client::websocket_outgoing_message msg;

	try
	{
		std::string payload;

		Encode(conv.to_bytes(data), payload);

		msg.set_utf8_message(payload);
		_connection->wsconn.send(msg).get();
	}
	catch (const std::exception &ex)
	{
		SetError(L"连接出现错误, 请重新尝试!2");
		DoClose();
	}
}

std::wstring InternalHandler::GetDeviceIdentity() {
	int cpuInfo[4] = { 0 };
	std::vector<int> mainFeatures;
	std::vector<int> extFeatures;

	__cpuidex(cpuInfo, 0, 0);
	mainFeatures.resize(cpuInfo[0] * 4);
	for (size_t i = 0; i < mainFeatures.size() / 4; i++) {
		__cpuidex(&mainFeatures[i * 4], i, 0);
	}

	__cpuidex(cpuInfo, 0x80000000, 0);
	unsigned int begin = (unsigned)cpuInfo[0] - (unsigned)0x80000000;

	extFeatures.resize(begin * 4);

	for (size_t i = 0; i < extFeatures.size() / 4; i++) {
		__cpuidex(&extFeatures[i * 4], 0x80000000 + i, 0);
	}

	std::vector<int> summary;
	summary.reserve(mainFeatures.size() + extFeatures.size() + 1);
	for (auto v : mainFeatures) {
		summary.push_back(v);
	}
	for (auto v : extFeatures) {
		summary.push_back(v);
	}

	summary[summary.size() - 1] = 0x10100701;
	for (int i = 0; i < summary.size();i++) {
		summary[i] ^= 0x13038711;
		summary[i] ^= 0x50531975;
	}

	cef_string_userfree_t s = cef_base64encode(&summary[0], summary.size() * sizeof(int));

	std::wstring data(s->str, s->length);

	cef_string_userfree_free(s);
	return std::move(data);
}

void InternalHandler::SetError(const std::wstring& error) {
	if (_hasGui) {

		if (_mainFrame) {
			SendAuthHint(_mainFrame, error, L"red");
		}
		
	}
	else {
		std::wstring text(error);
		if (error != L"连接已关闭") {
			text += L"\r\n";
			//MessageBox(NULL, text.c_str(), NULL, NULL);
			DWORD length = SendMessage(_outputWnd, WM_GETTEXTLENGTH, 0, 0);
			SendMessage(_outputWnd, EM_SETSEL, length, length);
			SendMessage(_outputWnd, EM_SCROLLCARET, 0, 0);
			SendMessage(_outputWnd, EM_REPLACESEL, 0, (LPARAM)&text[0]);
		}
	}

	CefPostDelayedTask(TID_UI, base::Bind(&InternalHandler::DoClose,this),3000);
}

void InternalHandler::Close() {
	if (_connection) {
		try
		{
			_connection->wsconn.close().get();
		}
		catch (const std::exception&)
		{

		}
		
		if (_waitable && _waitable->IsSignaled() == false) {
			_waitable->Signal();
		}
	}
}

void InternalHandler::SetOk(const std::wstring& hint) {
	if (_hasGui) {
		SendAuthHint(_mainFrame, hint);
	}
	else {
		std::wstring text(hint);
		text += L"\r\n";
		DWORD length = SendMessage(_outputWnd, WM_GETTEXTLENGTH, 0, 0);
		SendMessage(_outputWnd, EM_SETSEL, length, length);
		SendMessage(_outputWnd, EM_SCROLLCARET, 0, 0);
		SendMessage(_outputWnd, EM_REPLACESEL, 0, (LPARAM)&text[0]);
	}
}

void InternalHandler::DoLogin(web::json::value& data) {
	wchar_t url[MAX_PATH];
	std::wstring path(Local::rootDir);

	try
	{
		path += L"config.ini";

		WritePrivateProfileString(L"ecef", L"username", &_username[0], path.c_str());
		WritePrivateProfileString(L"ecef", L"password", &_password[0], path.c_str());

		if (_hasGui) {
			std::wstring expired = data[APF_EXPIRED].as_string();

			path = Local::rootDir;
			path += L"ecef_runtime\\authorization\\profile.html";

			swprintf_s(url, L"%s?username=%s&expired=%s",
				path.c_str(), _username.c_str(), expired.c_str());

			if (_mainFrame) {
				_mainFrame->LoadURL(url);
			}
		}
		else {
			if (data.has_string_field(APF_METADATA)) {
				std::wstring metadata = data[APF_METADATA].as_string();
				if (DecodeMetadata(metadata)) {
					
					*_retMetadata = (void*)&_cmdNamePointerArrays[0];
					_waitable->Signal();
				}
				else {
					SetError(L"参数解析失败!");
					_waitable->Signal();
				}
			}
			else {
				SetError(L"未注册授权许可证或许可证已过期。");
				_waitable->Signal();
			}
		}
	}
	catch (const std::exception&)
	{
	}
}

bool InternalHandler::DecodeMetadata(const std::wstring& metadata) {
	unsigned char maskchar[] = { 0x50,0x17,0x63,0x89,0x88,0x11,0x46,0x53 };
	int maskend = sizeof(maskchar);
	DWORD dwDataLength = 0;
	std::wstring buffer;
	std::wstring_convert<std::codecvt_utf8<wchar_t>> conv;

	CryptStringToBinary(&metadata[0], metadata.length(), CRYPT_STRING_BASE64, NULL, &dwDataLength,NULL,NULL);
	if (dwDataLength <= 0) {
		return false;
	}
	buffer.resize(dwDataLength / sizeof(wchar_t));
	CryptStringToBinary(&metadata[0], metadata.length(), CRYPT_STRING_BASE64, (BYTE*)&buffer[0], &dwDataLength, NULL, NULL);

	size_t pointer = 0;
	for (size_t i = 0; i < buffer.length(); i++) {
		buffer[i] ^= maskchar[pointer++];
		if (pointer >= maskend) {
			pointer = 0;
		}
	}
	std::string names = conv.to_bytes(buffer);
	size_t begin = 0;
	for (size_t i = 0; i < names.size(); i++){
		if (names[i] == ',') {
			int length = i - begin;
			if (length > 0) {
				_cmdNameArrays.emplace_back(&names[begin], i - begin);
				begin = i + 1;
			}
		}
	}

	if (begin < names.length()) {
		_cmdNameArrays.emplace_back(&names[begin], names.length() - begin);
	}
	_cmdNamePointerArrays.resize(_cmdNameArrays.size());
	for (size_t i = 0; i < _cmdNameArrays.size(); i++){
		_cmdNamePointerArrays[i] = (void*)_cmdNameArrays[i].c_str();
	}
	return true;
}

void InternalHandler::DoClose() {
	if (_hasConnected) {
		_connection->wsconn.close().then([this]() {
			_hasConnected = false;
			_connection->wsconn.set_close_handler(nullptr);
			_connection->wsconn.set_message_handler(nullptr);
		})
		.then([](pplx::task<void> t) {
			try
			{
				t.get();
			}
			catch (const std::exception&)
			{

			}
		});

	}
}

void InternalHandler::DoPay(web::json::value& data) {
	try
	{
		std::wstring qrcode = data[APF_QRCODE].as_string();
		if(_mainFrame){
			wchar_t buffer[MAX_PATH];
			swprintf_s(buffer, MAX_PATH, L"(function(){ setQRCode('%s') })();", qrcode.c_str());
			_mainFrame->ExecuteJavaScript(buffer,L"internal_call",0);
		}
	}
	catch (const std::exception &)
	{
		SetError(L"请求支付错误!");
	}
}

void InternalHandler::DoPayCallback(web::json::value& data) {
	wchar_t buffer[MAX_PATH];
	try
	{
		std::wstring expired = data[APF_EXPIRED].as_string();
		if (_mainFrame) {

			swprintf_s(buffer, L"%secef_runtime\\authorization\\profile.html?username=%s&expired=%s",
				Local::rootDir.c_str(), _username.c_str(), expired.c_str());

			_mainFrame->LoadURL(buffer);
		}
	}
	catch (const std::exception &ex)
	{
		SetError(L"请求支付错误!");
	}
}

void InternalHandler::DoPayTimeout(web::json::value& data) {
	try
	{
		if (_mainFrame) {
			_mainFrame->GetBrowser()->Reload();
		}
	}
	catch (const std::exception&)
	{

	}
}

void InternalHandler::Encode(const std::string& data, std::string& buffer) {
	unsigned char mark[] = { 0x53,0x71,0x88,0x12,0xac,0xe6,0xf1,0x49,0x7b };
	int pointer = 0;
	std::string s;

	s.resize(data.length());
	for (size_t i = 0; i < data.length(); i++) {
		s[i] = data[i] ^ mark[pointer++];
		if (pointer >= sizeof(mark)) {
			pointer = 0;
		}
	}

	DWORD length = 0;
	CryptBinaryToStringA((BYTE*)&s[0], data.length(), CRYPT_STRING_BASE64, NULL, &length);
	buffer.resize(length);
	CryptBinaryToStringA((BYTE*)&s[0], data.length(), CRYPT_STRING_BASE64, &buffer[0], &length);

}

void InternalHandler::Decode(const std::string& data, std::string& buffer) {
	DWORD length = 0;
	buffer.clear();

	CryptStringToBinaryA(data.c_str(), data.length(), CRYPT_STRING_BASE64, NULL, &length, NULL, NULL);
	if (length > 0) {
		buffer.resize(length);
		CryptStringToBinaryA(data.c_str(), data.length(), CRYPT_STRING_BASE64, (BYTE*)&buffer[0], &length, NULL, NULL);
		unsigned char mark[] = { 0x53,0x71,0x88,0x12,0xac,0xe6,0xf1,0x49,0x7b };
		int pointer = 0;
		for (size_t i = 0; i < buffer.length(); i++) {
			buffer[i] = buffer[i] ^ mark[pointer++];
			if (pointer >= sizeof(mark)) {
				pointer = 0;
			}
		}
	}
}