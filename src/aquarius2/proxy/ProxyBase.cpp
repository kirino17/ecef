#include "ProxyBase.h"
#include "include/cef_app.h"
#include "../client/InternalClient.h"
#include "../client/InternalProgram.h"
#include "../client/InternalServerClient.h"
#include "ProxyClient.h"
#include <atlconv.h>
#include "include/cef_values.h"
#include "include/capi/cef_parser_capi.h"
#include "include/cef_values.h"
#include "include/capi/cef_values_capi.h"
#include "include/cef_command_line.h"
#include "include/cef_values.h"
#include "include/cef_urlrequest.h"
#include "../client/InternalRequestClient.h"
#include "include/cef_keyboard_handler.h"
#include "include/cef_waitable_event.h"
#include <ShlObj_core.h>
#include <shellapi.h>
#include "include/cef_menu_model.h"
#include "../client/InternalCollection.h"
#include "include/cef_thread.h"

#pragma comment(lib,"Shell32.lib")
#pragma comment(lib,"Ole32.lib")

ProxyBase::ProxyBase() {

}

ProxyBase::~ProxyBase() {

}


///
// This function should be called on the main application thread to initialize
// the CEF browser process. The |application| parameter may be empty. A return
// value of true indicates that it succeeded and false indicates that it failed.
// The |windows_sandbox_info| parameter is only used on Windows and may be NULL
// (see cef_sandbox_win.h for details).
///
/*--cef(api_hash_check,optional_param=application,
		optional_param=windows_sandbox_info)--*/
bool ProxyBase::Initialize(
	shrewd_ptr<ProxySettings> settings,
	unsigned int client
) {
	CefMainArgs mainArgs(GetModuleHandle(NULL));
	CefRefPtr<InternalProgram> program = InternalProgram::GetShareInatance();
	CefRefPtr<InternalClient> inclient = InternalClient::GetShareInatance();
	CefSettings _setting;
	CefEnableHighDPISupport();
	program->SetClient((ProxyClient*)client);
	inclient->SetClient((ProxyClient*)client);
	CefExecuteProcess(mainArgs, program, NULL);
	if (settings) {
		_setting = *(CefSettings*)settings->OriginPointer();
	}
	_setting.multi_threaded_message_loop = 1;
	CefString(&_setting.browser_subprocess_path) = L"spare-proc.exe";
	return CefInitialize(mainArgs, _setting, program, NULL);
}

///
//	Base64Encode
///
char* ProxyBase::Base64Encode(unsigned char* data, size_t size) {
	assert(NewBuffer);
	if (!data || size == 0) {
		return NULL;
	}
	cef_string_userfree_t string = cef_base64encode(&data[8], size);
	char* buffer = ToAnsi(string->str, string->length);
	cef_string_userfree_free(string);
	return buffer;
}

///
//	Base64Decode
///
unsigned char* ProxyBase::Base64Decode(char* data) {
	assert(NewBuffer);
	if (!data) {
		return NULL;
	}
	cef_string_t string;
	size_t length = strlen(data);
	unsigned char* buffer = nullptr;
	string.dtor = nullptr;
	string.str = ToUnicode(data, length);
	string.length = lstrlenW(string.str);
	_cef_binary_value_t* binary = cef_base64decode(&string);

	if (binary) {
		size_t dataSize = binary->get_size(binary);
		buffer = (unsigned char*)NewBuffer(dataSize + 8);
		*((int*)&buffer[0]) = 1;
		*((int*)&buffer[4]) = dataSize;
		binary->get_data(binary, &buffer[8], dataSize, 0);
	}

	return (unsigned char*)buffer;
}

///
//	UrlEncode
///
char* ProxyBase::UriEncode(char* data, bool use_plus) {
	assert(NewBuffer);
	cef_string_t inString;
	if (!data) {
		return nullptr;
	}

	inString.dtor = nullptr;
	inString.str = ToUnicode(data, strlen(data));
	inString.length = lstrlenW(inString.str);

	cef_string_userfree_t outString = cef_uriencode(&inString, use_plus);

	DeleteBuffer(inString.str); inString.str = nullptr;

	if (!outString) {
		return nullptr;
	}

	char* buffer = ToAnsi(outString->str, outString->length);
	cef_string_userfree_free(outString);
	return buffer;
}

///
//	UrlEncode
///
char* ProxyBase::UriDecode(char* data, bool convert_to_utf8, int unescape_rule) {
	assert(NewBuffer);
	cef_string_t inString;
	if (!data) {
		return nullptr;
	}

	inString.dtor = nullptr;
	inString.str = ToUnicode(data, strlen(data));
	inString.length = lstrlenW(inString.str);

	cef_string_userfree_t outString = cef_uridecode(&inString, convert_to_utf8, (cef_uri_unescape_rule_t)unescape_rule);

	DeleteBuffer(inString.str); inString.str = nullptr;

	if (!outString) {
		return nullptr;
	}

	char* buffer = ToAnsi(outString->str, outString->length);
	cef_string_userfree_free(outString);
	return buffer;
}

///
//	Utf8ToAnsi
///
char* ProxyBase::Utf8ToBytes(unsigned char* data, size_t length) {
	if (!data || length == 0) {
		return nullptr;
	}
	cef_string_t s;

	s.dtor = nullptr;
	s.length = 0;
	s.str = nullptr;

	cef_string_from_utf8((char*)&data[8], length, &s);

	if (s.length>0) {
		char* buffer = ToAnsi(s.str, s.length);
		cef_string_clear(&s);
		return buffer;
	}

	return nullptr;
}

///
//	AnsiToUtf8
///
unsigned char* ProxyBase::BytesToUtf8(char* data) {
	if (!data) {
		return nullptr;
	}
	cef_string_t s;

	s.dtor = nullptr;
	s.str = ToUnicode(data, strlen(data));
	s.length = lstrlenW(s.str);

	cef_string_utf8_t us;
	us.dtor = nullptr;
	us.str = nullptr;
	us.length = 0;

	cef_string_wide_to_utf8(s.str, s.length, &us);

	DeleteBuffer(s.str); s.str = nullptr; s.length = 0;

	if (us.length > 0) {
		unsigned char* buffer = (unsigned char*)NewBuffer(8+us.length);
		*(int*)&buffer[0] = 1;
		*(int*)&buffer[4] = us.length;
		memcpy(&buffer[8], us.str, us.length);
		cef_string_utf8_clear(&us);
		return buffer;
	}

	return nullptr;
}

///
//	CreateBrowserSettings
///
shrewd_ptr<ProxyBrowserSettings> ProxyBase::CreateBrowserSettings() {
	return new ProxyBrowserSettings(new CefBrowserSettings);
}

///
//	CreateCommandLine
///
shrewd_ptr<ProxyCommandLine> ProxyBase::CreateCommandLine() {
	return new ProxyCommandLine(CefCommandLine::CreateCommandLine());
}

///
//	GetGlobalCommandLine
///
shrewd_ptr<ProxyCommandLine> ProxyBase::GetGlobalCommandLine() {
	return new ProxyCommandLine(CefCommandLine::GetGlobalCommandLine());
}

///
//	GetGlobalCookieManager
///
shrewd_ptr<ProxyCookieManager> ProxyBase::GetGlobalCookieManager() {
	return new ProxyCookieManager(CefCookieManager::GetGlobalManager(nullptr));
}

///
//	CreateDictionartyValue
///
shrewd_ptr<ProxyDictionaryValue> ProxyBase::CreateDictionartyValue() {
	return new ProxyDictionaryValue(CefDictionaryValue::Create());
}

///
//	CreateListValue
///
shrewd_ptr<ProxyListValue> ProxyBase::CreateListValue(EPL_ALL value) {
	return new ProxyListValue(CefListValue::Create());
}

///
//	CreatePostDataElement
///
shrewd_ptr<ProxyPostDataElement> ProxyBase::CreatePostDataElement() {
	shrewd_ptr<ProxyPostDataElement> element =new ProxyPostDataElement(CefPostDataElement::Create());
	element->SetToEmpty();
	return element;
}

shrewd_ptr<ProxyPostDataElement> ProxyBase::CreatePostDataElementWithFile(const char* filename) {
	shrewd_ptr<ProxyPostDataElement> element = new ProxyPostDataElement(CefPostDataElement::Create());
	if (filename) {
		element->SetToFile(filename);
	}
	return element;
}

 shrewd_ptr<ProxyPostDataElement> ProxyBase::CreatePostDataElementWithData(const unsigned char* buffer) {
	 shrewd_ptr<ProxyPostDataElement> element = new ProxyPostDataElement(CefPostDataElement::Create());
	 if (buffer) {
		 element->SetToBytes(*(int*)&buffer[4], buffer);
	 }
	 return element;
}

///
//	CreateRequest
///
shrewd_ptr<ProxyRequest> ProxyBase::CreateRequest(const char* method, const char* url, const char* referrer, const char* headerMaps, shrewd_ptr<ProxyPostDataElement> postData) {
	shrewd_ptr<ProxyRequest> request = new ProxyRequest(CefRequest::Create());
	return request;
}

///
//	CreateResponse
///
shrewd_ptr<ProxyResponse> ProxyBase::CreateResponse() {
	return new ProxyResponse(CefResponse::Create());
}

///
//	CreateSetting
///
shrewd_ptr<ProxySettings> ProxyBase::CreateSetting() {
	return new ProxySettings(new CefSettings());
}

///
//	CreateValue
///
shrewd_ptr<ProxyValue> ProxyBase::CreateValue(EPL_ALL value) {
	return new ProxyValue(CefValue::Create());
}

///
//	CreateWindowInfo
///
shrewd_ptr<ProxyWindowInfo> ProxyBase::CreateWindowInfo() {
	return new ProxyWindowInfo(new CefWindowInfo());
}

shrewd_ptr<ProxyWindowInfo> ProxyBase::CreateAsChildWindow(int parent, int x, int y, int width, int height) {
	shrewd_ptr<ProxyWindowInfo> windowInfo = new ProxyWindowInfo(new CefWindowInfo());
	windowInfo->SetAsChild(parent, x, y, width, height);
	return windowInfo;
}

shrewd_ptr<ProxyWindowInfo> ProxyBase::CreateAsPopupWindow(int parent, const char* title) {
	shrewd_ptr<ProxyWindowInfo> windowInfo = new ProxyWindowInfo(new CefWindowInfo());
	windowInfo->SetAsPopup(parent, title);
	return windowInfo;
}

///
//	CreateWindowInfo
///
shrewd_ptr<ProxyURLRequest> ProxyBase::SendURLRequest(shrewd_ptr<ProxyRequest> request, bool incognito_mode, const char* proxy_username, const char* proxy_password) {
	if (!request || !ORIGIN(CefRequest, request)) {
		return nullptr;
	}
	CefRefPtr<InternalRequestClient> client = new InternalRequestClient(nullptr);
	CefRefPtr<CefRequestContext> context = nullptr;
	CefRefPtr<CefURLRequest> url = nullptr;
	CefRefPtr<CefWaitableEvent> waitable = nullptr;

	if (incognito_mode) {
		CefRequestContextSettings settings;
		settings.ignore_certificate_errors = true;
		settings.persist_session_cookies = true;
		settings.persist_user_preferences = true;
		context = CefRequestContext::CreateContext(settings, nullptr);
	}
	else {
		context = CefRequestContext::GetGlobalContext();
	}
	client->SetAuthInfo(proxy_username, proxy_password);
	
	waitable = client->SendRequest(ORIGIN(CefRequest, request), context);
	WaitAwaking(waitable);

	return new ProxyURLRequest( client );
}

///
//	CreateServer
///
void ProxyBase::CreateServer(const char* address, int port, int backlog) {
	if (!address) {
		return;
	}
	CefServer::CreateServer(address, port, backlog, new InternalServerClient());
}

///
//	CreateWebSocket
///
shrewd_ptr<ProxyWebSocket> ProxyBase::CreateWebSocket() {
	return new ProxyWebSocket(nullptr);
}

///
//	CreateWaitableEvent
///
shrewd_ptr<ProxyWaitableEvent> ProxyBase::CreateWaitableEvent() {
	return new ProxyWaitableEvent(CefWaitableEvent::CreateWaitableEvent(false, false));
}

///
//	CreateWaitableEvent
///
void ProxyBase::Awaking(shrewd_ptr<ProxyWaitableEvent> waitable) {
	if (!waitable || !ORIGIN(CefWaitableEvent, waitable)) {
		return;
	}
	WaitAwaking(ORIGIN(CefWaitableEvent, waitable));
}

///
//	TimedAwaking
///
bool ProxyBase::TimedAwaking(shrewd_ptr<ProxyWaitableEvent> waitable, float max_ms) {
	if (!waitable || !ORIGIN(CefWaitableEvent, waitable)) {
		return false;
	}
	return WaitAwakingTimeout(ORIGIN(CefWaitableEvent, waitable), max_ms);
}

///
//	创建菜单
///
shrewd_ptr<ProxyMenuModel> ProxyBase::CreateMenu() {
	return new ProxyMenuModel(CefMenuModel::CreateMenuModel(nullptr));
}

///
//	create collection
///
shrewd_ptr<ProxyCollection> ProxyBase::CreateCollection(bool shared_cache) {
	return new ProxyCollection(new InternalCollection(shared_cache));
}

//shrewd_ptr<ProxyThread> ProxyBase::CreateThread(int priority, int message_loop_type, bool stoppable, int com_init_mode) {
//	CefRefPtr<CefThread> thread = CefThread::CreateThread(
//		L"InternalThread",
//		(cef_thread_priority_t)priority,
//		(cef_message_loop_type_t)message_loop_type,
//		stoppable, (cef_com_init_mode_t)com_init_mode);
//
//	if (thread) {
//		return new ProxyThread(thread);
//	}
//	return nullptr;
//}
//
//shrewd_ptr<ProxyTaskRunner> ProxyBase::GetForCurrentThread() {
//	CefRefPtr<CefTaskRunner> runner = CefTaskRunner::GetForCurrentThread();
//	if (runner) {
//		return new ProxyTaskRunner(runner);
//	}
//	return nullptr;
//}
//
//shrewd_ptr<ProxyTaskBind> ProxyBase::CreateTaskBind(int params) {
//	return nullptr;
//}

void ExportFile(const char* inDir, const char* inFile, const char* outDir) {
	char src[MAX_PATH];
	char dst[MAX_PATH];
	sprintf_s(src, MAX_PATH, "%s%s", inDir, inFile);
	sprintf_s(dst, MAX_PATH, "%s\\%s", outDir, inFile);
	CopyFileA(src, dst, FALSE);
}

void ExportDir(const char* inDir, const char* inFile, const char* outDir) {
	SHFILEOPSTRUCTA FileOp = { 0 };
	FileOp.fFlags = FOF_NOCONFIRMATION |   //不出现确认对话框
		FOF_NOCONFIRMMKDIR; //需要时直接创建一个文件夹,不需用户确定

	char src[MAX_PATH];
	char dst[MAX_PATH];
	sprintf_s(src, MAX_PATH, "%s%s", inDir, inFile);
	sprintf_s(dst, MAX_PATH, "%s\\%s", outDir, inFile);
	
	FileOp.pFrom = src;
	FileOp.pTo = dst;
	FileOp.wFunc = FO_COPY;
	SHFileOperationA(&FileOp);
}

void ProxyBase::ExportResourceToDir(const char* inDir) {
	BROWSEINFOA info = { 0 };
	char targetDir[MAX_PATH] = "";
	std::string hint = "导出完成: ";
	std::string runtimeDir = inDir;
	
	if (!inDir) {
		return;
	}

	runtimeDir += "..\\ecef_runtime\\";

	info.ulFlags = BIF_DONTGOBELOWDOMAIN | BIF_NEWDIALOGSTYLE;
	info.lpszTitle = "导出支持库资源";

	PIDLIST_ABSOLUTE data = NULL;

	CoInitialize(0);
	data = SHBrowseForFolderA(&info);

	if (data) {
		SHGetPathFromIDListA(data, targetDir);

		IMalloc* imalloc = 0;
		if (SUCCEEDED(SHGetMalloc(&imalloc))) {
			imalloc->Free(data);
			imalloc->Release();
		}
	}

	CoUninitialize();

	ExportFile(runtimeDir.c_str(), "aquarius2.dll", targetDir);
	ExportFile(runtimeDir.c_str(), "libcef.dll", targetDir);
	ExportFile(runtimeDir.c_str(), "libEGL.dll", targetDir);
	ExportFile(runtimeDir.c_str(), "libGLESv2.dll", targetDir);
	ExportFile(runtimeDir.c_str(), "LICENSE.txt", targetDir);
	ExportFile(runtimeDir.c_str(), "README.txt", targetDir);
	ExportFile(runtimeDir.c_str(), "d3dcompiler_47.dll", targetDir);
	ExportFile(runtimeDir.c_str(), "chrome_elf.dll", targetDir);
	ExportFile(runtimeDir.c_str(), "cef_extensions.pak", targetDir);
	ExportFile(runtimeDir.c_str(), "cef_200_percent.pak", targetDir);
	ExportFile(runtimeDir.c_str(), "cef_100_percent.pak", targetDir);
	ExportFile(runtimeDir.c_str(), "cef.pak", targetDir);
	ExportFile(runtimeDir.c_str(), "icudtl.dat", targetDir);
	ExportFile(runtimeDir.c_str(), "devtools_resources.pak", targetDir);
	ExportFile(runtimeDir.c_str(), "snapshot_blob.bin", targetDir);
	ExportFile(runtimeDir.c_str(), "spare-proc.exe", targetDir);
	ExportFile(runtimeDir.c_str(), "v8_context_snapshot.bin", targetDir);
	ExportDir(runtimeDir.c_str(), "swiftshader", targetDir);
	ExportDir(runtimeDir.c_str(), "locales", targetDir);
	ExportFile(runtimeDir.c_str(), "locales\\en-US.pak", targetDir);
	ExportFile(runtimeDir.c_str(), "locales\\en-GB.pak", targetDir);
	ExportFile(runtimeDir.c_str(), "locales\\zh-CN.pak", targetDir);
	ExportFile(runtimeDir.c_str(), "locales\\zh-TW.pak", targetDir);

	hint += targetDir;
	MessageBoxA(NULL, hint.c_str(), NULL, NULL);
}