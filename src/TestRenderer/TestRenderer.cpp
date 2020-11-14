// TestRenderer.cpp : 定义应用程序的入口点。
//
#include <windows.h>
#include "include/cef_app.h"
#include <sstream>
#include <list>
#include "TestRenderer.h"
#include <iostream>
#include <fstream>
#include "Utility.h"
#include <thread>
#include "TestDomProcess.h"
#include <sstream>
#include "TestAuthorization.h"

namespace {
	CefRefPtr<InternalProgram> _sharedInstance = nullptr;
}

CefRefPtr<InternalProgram> InternalProgram::GetInstance() {
	if (!_sharedInstance) {
		_sharedInstance = new InternalProgram();
	}
	return _sharedInstance;
}

InternalProgram::InternalProgram() {

	CefMessageRouterConfig config;
	config.js_query_function = L"cefQuery";
	config.js_cancel_function = L"cefQueryCancel";
	_messageRouter = CefMessageRouterRendererSide::Create(config);
}

InternalProgram::~InternalProgram() {

}

void InternalProgram::OnRenderThreadCreated(CefRefPtr<CefListValue> extra_info) {
	size_t count = extra_info->GetSize();
	BROWSER_EXTRA_INFO info;
	CefRefPtr<CefDictionaryValue> dict = nullptr;
	for (size_t i = 0; i < count; i++)
	{
		if (extra_info->GetType(i) == VTYPE_DICTIONARY) {
			dict = extra_info->GetDictionary(i);
			if (dict->HasKey(L"browser-id")) {
				int browserId = dict->GetInt(L"browser-id");
				info.useragentOverride = dict->GetString(L"user_agent_override");
				info.appVersionOverride = dict->GetString(L"app_version_override");
				info.scriptOnNewDocument = dict->GetString(L"add_script_on_new_document");
				_extraInfos.insert(std::make_pair(browserId, info));
			}
		}
	}
}

///
// Called when a new message is received from a different process. Return true
// if the message was handled or false otherwise. Do not keep a reference to
// or attempt to access the message outside of this callback.
///
/*--cef()--*/
bool InternalProgram::OnProcessMessageReceived(CefRefPtr<CefBrowser> browser,
	CefRefPtr<CefFrame> frame,
	CefProcessId source_process,
	CefRefPtr<CefProcessMessage> message) {

	if (_messageRouter->OnProcessMessageReceived(browser,frame,source_process,message)) {
		return true;
	}

	wchar_t buffer[MAX_PATH];
	CefString name = message->GetName();
	if (name == L"IPC_V8_CALCULATE") {
		CefRefPtr<CefListValue> arguments = message->GetArgumentList();
		ExecuteScript(browser, frame, arguments);
		return true;
	}
	else if (name == L"IPC_DOM_MESSAGE") {
		CefRefPtr<CefListValue> arguments = message->GetArgumentList();
		TestDomProcess(frame, arguments);
		return true;
	}
	else if (name == L"IPC_ADD_SCRIPT_ON_NEW_DOCUMENT") {
		CefRefPtr<CefListValue> arguments = message->GetArgumentList();
		AddScriptOnNewDocument(browser, arguments->GetString(0));
		return true;
	}
	else if (name == L"IPC_ADD_USER_AGENT_OVERRIDE") {
		CefRefPtr<CefListValue> arguments = message->GetArgumentList();
		AddUserAgentOverride(browser, arguments->GetString(0), arguments->GetString(1));
		return true;
	}
	else if (name == L"IPC_TOUCH_EVENT_ENABLE") {
		CefRefPtr<CefListValue> arguments = message->GetArgumentList();
		bool enabled = arguments->GetBool(0);
		int maxTouchPoints = arguments->GetInt(1);
		browser->SetTouchEventEmulationEnabled(enabled, maxTouchPoints);
		return true;
	}
	else if (name == L"IPC_SET_MEDIA_FEATURES") {
		CefRefPtr<CefListValue> arguments = message->GetArgumentList();
		CefString media = arguments->GetString(0);
		CefRefPtr<CefDictionaryValue> features = nullptr;
		if (arguments->GetType(1)!=VTYPE_NULL) {
			features = arguments->GetDictionary(1);
		}
		browser->SetEmulatedMedia(media,features);
		return true;
	}
	else if (name == L"IPC_CLEAR_MEDIA_FEATURES") {
		browser->ClearMediaFeatureOverrides();
		return true;
	}
	else if (name == L"IPC_ENABLE_DEVICE_EMULATION") {
		CefRefPtr<CefListValue> arguments = message->GetArgumentList();
		CefRefPtr<CefDictionaryValue> data = arguments->GetDictionary(0);
		if (data) {
			CefRefPtr<CefDeviceEmulationParams> params = CefDeviceEmulationParams::Create();
			if (data->HasKey(L"screen-type")) {
				params->SetScreenType(data->GetInt(L"screen-type"));
			}
			int x = 0;
			int y = 0;
			if (data->HasKey(L"screen-width")) {
				x = data->GetInt(L"screen-width");
			}
			if (data->HasKey(L"screen-height")) {
				y = data->GetInt(L"screen-height");
			}
			params->SetScreenSize(x, y);
			x = y = 0;

			if (data->HasKey(L"view-position-x")) {
				x = data->GetInt(L"view-position-x");
			}
			if (data->HasKey(L"view-position-y")) {
				y = data->GetInt(L"view-position-y");
			}
			params->SetViewPosition(x, y);
			x = y = 0;

			if (data->HasKey(L"view-size-width")) {
				x = data->GetInt(L"view-size-width");
			}
			if (data->HasKey(L"view-size-height")) {
				y = data->GetInt(L"view-size-height");
			}
			params->SetViewSize(x, y);
			x = y = 0;

			if (data->HasKey(L"device-scale-factor")) {
				params->SetDeviceScaleFactor(data->GetDouble(L"device-scale-factor"));
			}
			
			if (data->HasKey(L"scale")) {
				params->SetScale(data->GetDouble(L"device-scale-factor"));
			}

			float fx = 0.0f, fy = 0.0f;

			if (data->HasKey(L"viewport-offset-x")) {
				fx = data->GetDouble(L"viewport-offset-x");
			}
			if (data->HasKey(L"viewport-offset-y")) {
				fy = data->GetDouble(L"viewport-offset-y");
			}
			params->SetViewportOffset(fx,fy);
			fx = fy = 0.0f;

			if (data->HasKey(L"viewport-scale")) {
				params->SetViewportScale(data->GetDouble(L"viewport-scale"));
			}

			if (data->HasKey(L"screen-orientation-type")) {
				params->SetScreenOrientationType(data->GetInt(L"screen-orientation-type"));
			}

			if (data->HasKey(L"screen-orientation-angle")) {
				params->SetScreenOrientationAngle(data->GetInt(L"screen-orientation-angle"));
			}

			browser->EnableDeviceEmulation(params);
		}
		else if (name == L"IPC_DISABLE_DEVICE_EMULATION") {
			browser->DisableDeviceEmulation();
			return true;
		}
		return true;
	}
	return false;
}

void InternalProgram::OnContextCreated(CefRefPtr<CefBrowser> browser,
	CefRefPtr<CefFrame> frame,
	CefRefPtr<CefV8Context> context)
{
	for (auto iter = _contexts.begin(); iter != _contexts.end(); iter++) {
		if (iter->browser->IsSame(browser)) {
			if (!iter->scriptOnNewDocument.empty()) {
				ExecuteScriptGlobal(frame, context, iter->scriptOnNewDocument);
			}
			if (!iter->useragentOverride.empty()) {

				SetUserAgentOverride(frame, context, iter->useragentOverride, iter->appVersionOverride);
			}
			break;
		}
	}


	_messageRouter->OnContextCreated(browser, frame, context);
}


void InternalProgram::OnContextReleased(CefRefPtr<CefBrowser> browser,
	CefRefPtr<CefFrame> frame,
	CefRefPtr<CefV8Context> context) 
{
	_messageRouter->OnContextReleased(browser, frame, context);
}

void InternalProgram::OnBrowserCreated(CefRefPtr<CefBrowser> browser,
	CefRefPtr<CefDictionaryValue> extra_info) {
	RENDERER_BROWSER_CONTEXT ctx(browser);
	if (extra_info) {
		if (extra_info->HasKey(L"add_script_on_new_document")) {
			ctx.scriptOnNewDocument = extra_info->GetString(L"add_script_on_new_document");
		}
		if (extra_info->HasKey(L"user_agent_override")) {
			ctx.useragentOverride = extra_info->GetString(L"user_agent_override");
		}
		if (extra_info->HasKey(L"app_version_override")) {
			ctx.appVersionOverride = extra_info->GetString(L"app_version_override");
		}
	}

	auto iter = _extraInfos.find(browser->GetIdentifier());
	if (iter != _extraInfos.end()) {
		ctx.scriptOnNewDocument =iter->second.scriptOnNewDocument;
		ctx.appVersionOverride = iter->second.appVersionOverride;
		ctx.useragentOverride = iter->second.useragentOverride;
	}

	_contexts.push_back(ctx);
}

void InternalProgram::OnBrowserDestroyed(CefRefPtr<CefBrowser> browser) {
	for (auto iter = _contexts.begin(); iter != _contexts.end();iter++) {
		if (iter->browser->IsSame(browser)) {
			_contexts.erase(iter);

			break;
		}
	}
}

void InternalProgram::OnWebKitInitialized() {
	std::wstring code = L"var vkinternal;if(!vkinternal) vkinternal={};(function(){vkinternal.call=function(c){ native function __internal_call(id); __internal_call(c); }})();";
	
	CefRegisterExtension(L"internal/call", code, new TestAuthorization);
}

void InternalProgram::ExecuteScript(
	CefRefPtr<CefBrowser> browser,
	CefRefPtr<CefFrame> frame,
	CefRefPtr<CefListValue> arguments) {
	CefRefPtr<CefV8Context> context = frame->GetV8Context();
	CefRefPtr<CefV8Value> retval = nullptr;
	CefRefPtr<CefV8Exception> exception = nullptr;

	CefString scriptCode = arguments->GetString(3);
	CefString scriptUrl = arguments->GetString(4);
	int startLine = arguments->GetInt(5);

	context->Enter();
	bool result = context->Eval(scriptCode, scriptUrl, startLine, retval, exception);
	context->Exit();

	CefRefPtr<CefProcessMessage> sendMessage = CefProcessMessage::Create(L"IPC_V8_RESULT");
	CefRefPtr<CefListValue> info = sendMessage->GetArgumentList();
	info->SetSize(3);
	info->SetInt(0, arguments->GetInt(2));
	info->SetBool(1, result);

	if (result) {

		if (retval) {
			CefRefPtr<CefValue> value = CefValue::Create();
			if (retval->IsUndefined() || retval->IsNull()) {
				value->SetNull();
			}
			else if (retval->IsBool()) {
				value->SetBool(retval->GetBoolValue());
			}
			else if (retval->IsInt()) {
				value->SetInt(retval->GetIntValue());
			}
			else if (retval->IsUInt()) {
				value->SetInt(retval->GetUIntValue());
			}
			else if (retval->IsDouble()) {
				value->SetDouble(retval->GetDoubleValue());
			}
			else if (retval->IsString()) {
				value->SetString(retval->GetStringValue());
			}
			else {
				value->SetNull();
			}
			info->SetValue(2, value);
		}
	}
	else {
		std::wstringstream error;
		if (exception) {
			CefString messageText = exception->GetMessage();
			CefString scripeResourceText = exception->GetScriptResourceName();
			if (!messageText.empty()) {
				error << messageText.c_str();
			}
			else {
				error << L"Unknown Error";
			}
			if (!scripeResourceText.empty()) {
				error << L"\t at <" << scripeResourceText.c_str() << ">";
			}
			else {
				error << L"\t at <Unknown>";
			}
			error << L":" << exception->GetLineNumber();
			error << L"/" << exception->GetStartPosition();
			error << L"/" << exception->GetEndPosition();
		}
		std::wstring buffer = error.str();
		info->SetString(2, buffer);
	}

	frame->SendProcessMessage(PID_BROWSER, sendMessage);
}

void InternalProgram::AddScriptOnNewDocument(CefRefPtr<CefBrowser> browser, const CefString& script_code) {
	for (auto iter = _contexts.begin(); iter != _contexts.end(); iter++) {
		if (iter->browser->IsSame(browser)) {
			iter->scriptOnNewDocument = script_code;
			break;
		}
	}
}

void InternalProgram::AddUserAgentOverride(CefRefPtr<CefBrowser> browser, const CefString& useragent, const CefString& appversion) {
	for (auto iter = _contexts.begin(); iter != _contexts.end(); iter++) {
		if (iter->browser->IsSame(browser)) {
			iter->useragentOverride = useragent;
			iter->appVersionOverride = appversion;
			break;
		}
	}
}

void InternalProgram::ExecuteScriptGlobal(CefRefPtr<CefFrame> frame, CefRefPtr<CefV8Context> context, const CefString& script) {
	CefRefPtr<CefV8Value> retval = nullptr;
	CefRefPtr<CefV8Exception> exception = nullptr;
	if (context->Eval(script, L"internal_call", 0, retval, exception)) {
		retval = nullptr;
		exception = nullptr;
	}
}

void InternalProgram::SetUserAgentOverride(CefRefPtr<CefFrame> frame, CefRefPtr<CefV8Context> context, const CefString& useragent, const CefString& appVersion) {
	std::wstringstream sstr;
	sstr << L"Object.defineProperty(window.navigator,\"userAgent\",{value: \"" << useragent.c_str() << L"\", writable: false});";
	sstr << L"Object.defineProperty(window.navigator,\"appVersion\",{value: \"" << appVersion.c_str() << L"\", writable: false});";
	std::wstring s = sstr.str();
	ExecuteScriptGlobal(frame, context, s);
}

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    CefMainArgs mainArgs(hInstance);
    return CefExecuteProcess(mainArgs, InternalProgram::GetInstance(), nullptr);
}

/**
 *  线程同步等待
 *
 *  @param 等待对象
*/
void WaitAwaking(CefRefPtr<CefWaitableEvent> waitable) {
	MSG uiMsg;
	if (!waitable) {
		return;
	}
	while (!waitable->IsSignaled()) {
		if (PeekMessage(&uiMsg, NULL, 0, 0, PM_REMOVE)) {
			TranslateMessage(&uiMsg);
			DispatchMessage(&uiMsg);
			if (uiMsg.message == WM_QUIT) {
				break;
			}
		}
		std::this_thread::yield();
	}
}

void InternalProgram::OnAuth(int command) {
	CefRefPtr<InternalProgram> program = InternalProgram::GetInstance();
	if (!program->_contexts.empty()) {
		CefRefPtr<CefBrowser> browser = program->_contexts.front().browser;
		CefRefPtr<CefFrame> frame = browser->GetMainFrame();
		if (command == ECEF_AUTH_CMD_LOGIN) {
			program->OnCommandLogin(frame);
		}
		else if (command == ECEF_AUTH_CMD_PAY) {
			program->OnCommandPay(frame);
		}
		else if (command == ECEF_AUTH_CMD_SIGNUP) {
			program->OnCommandSignup(frame);
		}
		else if (command == ECEF_AUTH_CMD_RESET) {
			program->OnCommandReset(frame);
		}
	}
}

void InternalProgram::OnCommandLogin(CefRefPtr<CefFrame> frame) {
	CefRefPtr<CefV8Context> context = frame->GetV8Context();
	CefRefPtr<CefV8Value> retval = nullptr;
	CefRefPtr<CefV8Exception> exception = nullptr;
	CefString username;
	CefString password;

	context->Enter();

	bool result = context->Eval(L"document.getElementById('username').value", L"internal_call", 0, retval, exception);

	if (result) {
		username = retval->GetStringValue();
	}

	result = context->Eval(L"document.getElementById('password').value", L"internal_call", 0, retval, exception);
	if (result) {
		password = retval->GetStringValue();
	}

	context->Exit();

	if (username.empty() || password.empty()) {
		frame->ExecuteJavaScript(L"(function(){ var hint = document.getElementById('error-show'); hint.innerText = '用户名和密码不能为空!'; hint.style.color='red'; })();", L"internal_call", 0);
		return;
	}
	else {
		frame->ExecuteJavaScript(L"(function(){ var hint = document.getElementById('error-show'); hint.innerText = '等待响应中...'; hint.removeAttribute('style'); })();", L"internal_call", 0);
	}

	CefRefPtr<CefListValue> params = CefListValue::Create();
	params->SetString(0, username);
	params->SetString(1, password);
	SendAuthMessage(frame, ECEF_AUTH_CMD_LOGIN, params);
}

void InternalProgram::OnCommandPay(CefRefPtr<CefFrame> frame) {
	CefRefPtr<CefV8Context> context = frame->GetV8Context();
	CefRefPtr<CefV8Value> retval = nullptr;
	CefRefPtr<CefV8Exception> exception = nullptr;
	bool product;

	context->Enter();

	bool result = context->Eval(L"document.getElementById('radio-normal').checked", L"internal_call", 0, retval, exception);

	if (result) {
		product = retval->GetBoolValue();
	}

	context->Exit();

	CefRefPtr<CefListValue> params = CefListValue::Create();
	params->SetBool(0, product);
	SendAuthMessage(frame, ECEF_AUTH_CMD_PAY, params);
}

void InternalProgram::OnCommandSignup(CefRefPtr<CefFrame> frame) {
	CefRefPtr<CefV8Context> context = frame->GetV8Context();
	CefRefPtr<CefV8Value> retval = nullptr;
	CefRefPtr<CefV8Exception> exception = nullptr;
	CefString username;
	CefString password;
	CefString repatpwd;

	context->Enter();

	bool result = context->Eval(L"document.getElementById('username').value", L"internal_call", 0, retval, exception);

	if (result) {
		username = retval->GetStringValue();
	}

	result = context->Eval(L"document.getElementById('password').value", L"internal_call", 0, retval, exception);
	if (result) {
		password = retval->GetStringValue();
	}

	result = context->Eval(L"document.getElementById('repatpwd').value", L"internal_call", 0, retval, exception);
	if (result) {
		repatpwd = retval->GetStringValue();
	}

	context->Exit();

	if (username.empty() || password.empty() || repatpwd.empty()) {
		frame->ExecuteJavaScript(L"(function(){ var hint = document.getElementById('error-show'); hint.innerText = '用户名和密码不能为空!'; hint.style.color='red'; })();", L"internal_call", 0);
		return;
	}
	else if(password != repatpwd) {
		frame->ExecuteJavaScript(L"(function(){ var hint = document.getElementById('error-show'); hint.innerText = '两次密码输入不一致!'; hint.style.color='red'; })();", L"internal_call", 0);
		return;
	}
	else {
		frame->ExecuteJavaScript(L"(function(){ var hint = document.getElementById('error-show'); hint.innerText = '等待响应中...'; hint.removeAttribute('style'); })();", L"internal_call", 0);
	}
	CefRefPtr<CefListValue> params = CefListValue::Create();
	params->SetString(0, username);
	params->SetString(1, password);
	SendAuthMessage(frame, ECEF_AUTH_CMD_SIGNUP, params);
}

void InternalProgram::OnCommandReset(CefRefPtr<CefFrame> frame) {
	CefRefPtr<CefV8Context> context = frame->GetV8Context();
	CefRefPtr<CefV8Value> retval = nullptr;
	CefRefPtr<CefV8Exception> exception = nullptr;
	CefString username;
	CefString password;
	CefString trade_id;

	context->Enter();

	bool result = context->Eval(L"document.getElementById('username').value", L"internal_call", 0, retval, exception);

	if (result) {
		username = retval->GetStringValue();
	}

	result = context->Eval(L"document.getElementById('password').value", L"internal_call", 0, retval, exception);
	if (result) {
		password = retval->GetStringValue();
	}

	result = context->Eval(L"document.getElementById('trade_id').value", L"internal_call", 0, retval, exception);
	if (result) {
		trade_id = retval->GetStringValue();
	}

	context->Exit();

	if (username.empty() || password.empty() || trade_id.empty()) {
		frame->ExecuteJavaScript(L"(function(){ var hint = document.getElementById('error-show'); hint.innerText = '输入字段不可留空!'; hint.style.color='red'; })();", L"internal_call", 0);
		return;
	}
	else {
		frame->ExecuteJavaScript(L"(function(){ var hint = document.getElementById('error-show'); hint.innerText = '等待响应中...'; hint.removeAttribute('style'); })();", L"internal_call", 0);
	}
	CefRefPtr<CefListValue> params = CefListValue::Create();
	params->SetString(0, username);
	params->SetString(1, password);
	params->SetString(2, trade_id);
	SendAuthMessage(frame, ECEF_AUTH_CMD_RESET, params);
}

void InternalProgram::SendAuthMessage(CefRefPtr<CefFrame> frame, int command, CefRefPtr<CefListValue> params) {
	CefRefPtr<CefProcessMessage> message = CefProcessMessage::Create(L"IPC_AUTH_MESSAGE");
	CefRefPtr<CefListValue> arguments = message->GetArgumentList();
	arguments->SetInt(0, command);
	if (params) {
		arguments->SetList(1, params);
	}
	frame->SendProcessMessage(PID_BROWSER, message);
}