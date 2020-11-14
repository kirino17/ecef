#include "ProxyBrowser.h"
#include "include/cef_browser.h"
#include <sstream>
#include <codecvt>
#include <atlconv.h>
#include "ProxyFrame.h"
#include "../def/internalDef.h"
#include "../client/InternalDevToolsClient.h"
#include "../client/InternalClient.h"
#include "../client/InternalExtensionClient.h"
#include "include/base/cef_bind.h"
#include "include/cef_task.h"
#include "../client/InternalTaskVisitor.h"
#include <functional>
#include <thread>


AQUA_PROXY_AUTO_CONSTRUCTOR(ProxyBrowser,CefBrowser);



bool ProxyBrowser::IsValid() {
	return _rawptr != nullptr;
}

// Retrieve the window handle for this browser. If this browser is Proxyped in
// a CefBrowserView this method should be called on the browser process UI
// thread and it will return the handle for the top-level native window.
///
/*--cef()--*/
void* ProxyBrowser::GetWindowHandle() {
	ASSERTQ(NULL);
	return (void*)FORWARD(CefBrowser)->GetHost()->GetWindowHandle();
}

///
// Returns true if the browser can navigate backwards.
///
/*--cef()--*/
bool ProxyBrowser::CanGoBack() {
	ASSERTQ(false);
	return FORWARD(CefBrowser)->CanGoBack();
}

///
// Navigate backwards.
///
/*--cef()--*/
void ProxyBrowser::GoBack() {
	ASSERTN();
	FORWARD(CefBrowser)->GoBack();
}

///
// Returns true if the browser can navigate forwards.
///
/*--cef()--*/
bool ProxyBrowser::CanGoForward() {
	ASSERTQ(false);
	return FORWARD(CefBrowser)->CanGoForward();
}

///
// Navigate forwards.
///
/*--cef()--*/
void ProxyBrowser::GoForward() {
	ASSERTN();
	FORWARD(CefBrowser)->GoForward();
}

///
// Returns true if the browser is currently loading.
///
/*--cef()--*/
bool ProxyBrowser::IsLoading() {
	ASSERTQ(false);
	return FORWARD(CefBrowser)->IsLoading();
}

///
// Reload the current page.
///
/*--cef()--*/
void ProxyBrowser::Reload() {
	ASSERTN();
	FORWARD(CefBrowser)->Reload();
}

///
// Reload the current page ignoring any cached data.
///
/*--cef()--*/
void ProxyBrowser::ReloadIgnoreCache() {
	ASSERTN();
	FORWARD(CefBrowser)->ReloadIgnoreCache();
}

///
// Stop loading the page.
///
/*--cef()--*/
void ProxyBrowser::StopLoad() {
	ASSERTN();
	FORWARD(CefBrowser)->StopLoad();
}

///
// Returns the globally unique identifier for this browser. This value is also
// used as the tabId for extension APIs.
///
/*--cef()--*/
int ProxyBrowser::GetIdentifier() {
	ASSERTQ(-1);
	return FORWARD(CefBrowser)->GetIdentifier();
}

///
// Returns true if the window is a popup window.
///
/*--cef()--*/
bool ProxyBrowser::IsPopup() {
	ASSERTQ(false);
	return FORWARD(CefBrowser)->IsPopup();
}

///
// Returns true if a document has been loaded in the browser.
///
/*--cef()--*/
bool ProxyBrowser::HasDocument() {
	ASSERTQ(false);
	//CefRefPtr<CefFrame> frame = FORWARD(CefBrowser)->GetMainFrame();
	//CefRefPtr<CefProcessMessage> message = CefProcessMessage::Create(L"IPC_TEST");
	//frame->SendProcessMessage(PID_RENDERER, message);
	return FORWARD(CefBrowser)->HasDocument();
}

///
// Returns the main (top-level) frame for the browser window.
///
/*--cef()--*/
shrewd_ptr<ProxyFrame> ProxyBrowser::GetMainFrame() {
	ASSERTQ(NULL);
	return new ProxyFrame(FORWARD(CefBrowser)->GetMainFrame());
}

///
// Returns the focused frame for the browser window.
///
/*--cef()--*/
shrewd_ptr<ProxyFrame> ProxyBrowser::GetFocusedFrame() {
	ASSERTQ(NULL);
	return new ProxyFrame(FORWARD(CefBrowser)->GetFocusedFrame());
}

///
// Returns the frame with the specified name, or NULL if not found.
///
/*--cef(optional_param=name)--*/
shrewd_ptr<ProxyFrame> ProxyBrowser::GetFrame(const char* name) {
	ASSERTQ(NULL);
	if (!name) {
		return NULL;
	}
	USES_CONVERSION;
	return new ProxyFrame(FORWARD(CefBrowser)->GetFrame(A2W(name)));
}

///
// Returns the frame with the specified identity, or NULL if not found.
///
/*--cef(optional_param=name)--*/
shrewd_ptr<ProxyFrame> ProxyBrowser::GetFrameWithIdentity(__int64 identity) {
	ASSERTQ(0);
	CefRefPtr<CefFrame> frame = FORWARD(CefBrowser)->GetFrame((int64)identity);
	if (frame) {
		return new ProxyFrame(frame);
	}

	return nullptr;
}

///
// Returns the number of frames that currently exist.
///
/*--cef()--*/
size_t ProxyBrowser::GetFrameCount() {
	ASSERTQ(0);
	return FORWARD(CefBrowser)->GetFrameCount() - 1;
}

///
// Returns the names of all existing frames.
///
/*--cef()--*/
char** ProxyBrowser::GetFrameNames() {
	ASSERTARRAY(char);
	assert(NewBuffer);
	std::vector<CefString> originNameArrays;
	FORWARD(CefBrowser)->GetFrameNames(originNameArrays);
	int count = originNameArrays.size();
	DWORD* pointer = (DWORD*)NewBuffer( sizeof(INT)*(2 + count));
	*(pointer + 0) = 1;
	*(pointer + 1) = count;

	if (originNameArrays.empty()) {
		return (char**)pointer;
	}

	for (size_t i = 0; i < count; i++){
		if (originNameArrays[i].empty()) {
			*(pointer + i + 2) = NULL;
		}
		else {
			*(pointer + i + 2) = (DWORD)ToAnsi(originNameArrays[i].c_str(), originNameArrays[i].length());
		}
		
	}
	return (char**)pointer;
}

///
// 获取ids
///
__int64** ProxyBrowser::GetFrameIdentifiers() {
	ASSERTARRAY(__int64);
	assert(NewBuffer);
	std::vector<int64> originIdentityArrays;
	FORWARD(CefBrowser)->GetFrameIdentifiers(originIdentityArrays);
	int count = originIdentityArrays.size();
	DWORD* pointer = (DWORD*)NewBuffer(2*sizeof(INT) + count*sizeof(__int64));
	*(pointer + 0) = 1;
	*(pointer + 1) = count;

	if (originIdentityArrays.empty()) {
		return (__int64**)pointer;
	}

	__int64* base = (__int64*)&pointer[2];
	for (size_t i = 0; i < count; i++) {
		*(base + i) = originIdentityArrays[i];
	}
	return (__int64**)pointer;
}

///
// 获取frames
///
shrewd_ptr<ProxyFrame>** ProxyBrowser::GetFrames() {
	ASSERTARRAY(shrewd_ptr<ProxyFrame>);
	assert(NewBuffer);
	std::vector<int64> originIdentityArrays;
	FORWARD(CefBrowser)->GetFrameIdentifiers(originIdentityArrays);
	int count = originIdentityArrays.size();
	DWORD* pointer = (DWORD*)NewBuffer(2 * sizeof(INT) + count * sizeof(DWORD));
	shrewd_ptr<ProxyFrame> frame = nullptr;
	*(pointer + 0) = 1;
	*(pointer + 1) = count;

	if (originIdentityArrays.empty()) {
		(shrewd_ptr<ProxyFrame>**)pointer;
	}
	
	DWORD* base = (pointer + 2);
	for (size_t i = 0; i < count; i++) {
		DWORD* item = (DWORD*)NewBuffer(sizeof(DWORD));
		frame =  new ProxyFrame(FORWARD(CefBrowser)->GetFrame(originIdentityArrays[i]));
		frame->retain();
		*item = (DWORD)frame.get();
		*(base + i) = (DWORD)item;
	}
	return (shrewd_ptr<ProxyFrame>**)pointer;
}

///
// Request that the browser close. The JavaScript 'onbeforeunload' event will
// be fired. If |force_close| is false the event handler, if any, will be
// allowed to prompt the user and the user can optionally cancel the close.
// If |force_close| is true the prompt will not be displayed and the close
// will proceed. Results in a call to CefLifeSpanHandler::DoClose() if the
// event handler allows the close or if |force_close| is true. See
// CefLifeSpanHandler::DoClose() documentation for additional usage
// information.
///
/*--cef()--*/
void ProxyBrowser::CloseBrowser(bool force_close) {
	ASSERTN();
	FORWARD(CefBrowser)->GetHost()->CloseBrowser(force_close);
}

///
// Set whether the browser is focused.
///
/*--cef()--*/
void ProxyBrowser::SetFocus(bool focus) {
	ASSERTN();
	FORWARD(CefBrowser)->GetHost()->SetFocus(focus);
}


///
// Retrieve the window handle of the browser that opened this browser. Will
// return NULL for non-popup windows or if this browser is Proxyped in a
// CefBrowserView. This method can be used in combination with custom handling
// of modal windows.
///
/*--cef()--*/
void* ProxyBrowser::GetOpenerWindowHandle() {
	ASSERTQ(NULL);
	return FORWARD(CefBrowser)->GetHost()->GetOpenerWindowHandle();
}

///
// Get the current zoom level. The default zoom level is 0.0. This method can
// only be called on the UI thread.
///
/*--cef()--*/
double ProxyBrowser::GetZoomLevel() {
	ASSERTQ(0.0f);
	return FORWARD(CefBrowser)->GetHost()->GetZoomLevel();
}

///
// Change the zoom level to the specified value. Specify 0.0 to reset the
// zoom level. If called on the UI thread the change will be applied
// immediately. Otherwise, the change will be applied asynchronously on the
// UI thread.
///
/*--cef()--*/
void ProxyBrowser::SetZoomLevel(double zoomLevel) {
	ASSERTN();
	FORWARD(CefBrowser)->GetHost()->SetZoomLevel(zoomLevel);
}


///
// Download the file at |url| using CefDownloadHandler.
///
/*--cef()--*/
void ProxyBrowser::StartDownload(const char* url) {
	ASSERTN();
	FORWARD(CefBrowser)->GetHost()->StartDownload(url);
}

///
// Print the current browser contents.
///
/*--cef()--*/
void ProxyBrowser::Print() {
	ASSERTN();
	FORWARD(CefBrowser)->GetHost()->Print();
}

void ProxyBrowser::SendKeyDownEvent(int key, bool is_system_key, int modifiers) {
	ASSERTN();
	CefKeyEvent evt;
	evt.type = KEYEVENT_RAWKEYDOWN;
	evt.is_system_key = is_system_key;
	evt.modifiers = modifiers;
	evt.windows_key_code = key;
	FORWARD(CefBrowser)->GetHost()->SendKeyEvent(evt);
}

void ProxyBrowser::SendKeyUpEvent(int key, bool is_system_key, int modifiers) {
	ASSERTN();
	CefKeyEvent evt;
	evt.type = cef_key_event_type_t::KEYEVENT_KEYUP;
	evt.is_system_key = is_system_key;
	evt.modifiers = modifiers;
	evt.windows_key_code = key;
	FORWARD(CefBrowser)->GetHost()->SendKeyEvent(evt);
}

void ProxyBrowser::SendKeyPressEvent(int key, bool is_system_key, int duration, int modifiers) {
	ASSERTN();
	CefRefPtr<CefBrowserHost> host = FORWARD(CefBrowser)->GetHost();
	CefKeyEvent evt;
	evt.type = KEYEVENT_RAWKEYDOWN;
	evt.is_system_key = is_system_key;
	evt.modifiers = modifiers;
	evt.windows_key_code = key;
	FORWARD(CefBrowser)->GetHost()->SendKeyEvent(evt);

	if (duration > 0) {
		std::this_thread::sleep_for(std::chrono::milliseconds(duration));
	}
	evt.type = cef_key_event_type_t::KEYEVENT_KEYUP;
	FORWARD(CefBrowser)->GetHost()->SendKeyEvent(evt);
}

void ProxyBrowser::SendCharEvent(char charactor) {
	ASSERTN();
	CefRefPtr<CefBrowserHost> host = FORWARD(CefBrowser)->GetHost();
	CefKeyEvent evt;
	//evt.type = KEYEVENT_RAWKEYDOWN;
	//evt.windows_key_code = (charactor - 32);
	//FORWARD(CefBrowser)->GetHost()->SendKeyEvent(evt);

	if (charactor == '\b') {
		this->SendKeyPressEvent(VK_BACK, false, 0, 0);
		return;
	}
	else if (charactor == '\n' || charactor == '\r') {
		this->SendKeyPressEvent(charactor, false, 0, 0);
		return;
	}

	evt.type = KEYEVENT_CHAR;
	evt.character = charactor;
	evt.unmodified_character = charactor;
	evt.windows_key_code = charactor;
	FORWARD(CefBrowser)->GetHost()->SendKeyEvent(evt);

	//evt.type = KEYEVENT_KEYUP;
	//evt.windows_key_code = (charactor - 32);
	//evt.modifiers = 0;
	//evt.character = 0;
	//evt.unmodified_character = 0;
	//FORWARD(CefBrowser)->GetHost()->SendKeyEvent(evt);
}

void ProxyBrowser::SendCharArrayEvent(const char* charactor, int duration) {
	ASSERTN();
	if (!charactor) {
		return;
	}
	int length = strlen(charactor);
	if (length <= 0) {
		return;
	}

	for (size_t i = 0; i < length; i++) {
		this->SendCharEvent(charactor[i]);
		if (duration > 0) {
			WaitTimeout(duration);
		}
	}

}

///
// Send a mouse click event to the browser. The |x| and |y| coordinates are
// relative to the upper-left corner of the view.
///
/*--cef()--*/
void ProxyBrowser::SendMouseClickEvent(int x, int y, int type, bool mouseUp, int clickCount, int modifiers) {
	ASSERTN();
	CefMouseEvent evt;
	evt.x = x;
	evt.y = y;
	evt.modifiers = modifiers;
	FORWARD(CefBrowser)->GetHost()->SendMouseClickEvent(evt, (cef_mouse_button_type_t)type, mouseUp, clickCount);
}

///
// Send a mouse move event to the browser. The |x| and |y| coordinates are
// relative to the upper-left corner of the view.
///
/*--cef()--*/
void ProxyBrowser::SendMouseMoveEvent(int x, int y, bool mouseLeave, int modifiers) {
	ASSERTN();
	CefMouseEvent evt;
	evt.x = x;
	evt.y = y;
	evt.modifiers = modifiers;
	FORWARD(CefBrowser)->GetHost()->SendMouseMoveEvent(evt, mouseLeave);
}

///
// Send a mouse wheel event to the browser. The |x| and |y| coordinates are
// relative to the upper-left corner of the view. The |deltaX| and |deltaY|
// values represent the movement delta in the X and Y directions respectively.
// In order to scroll inside select popups with window rendering disabled
// CefRenderHandler::GetScreenPoint should be implemented properly.
///
/*--cef()--*/
void ProxyBrowser::SendMouseWheelEvent(int x, int y, int deltaX, int deltaY, int modifiers) {
	ASSERTN();
	CefMouseEvent evt;
	evt.x = x;
	evt.y = y;
	evt.modifiers = modifiers;
	FORWARD(CefBrowser)->GetHost()->SendMouseWheelEvent(evt,deltaX, deltaY);
}

///
// Send a touch event to the browser for a windowless browser.
///
/*--cef()--*/
void ProxyBrowser::SendTouchEvent(int id, float x, float y, float radius_x, float radius_y, float rotation_angle, float pressure, int type, int modifiers, int pointer_type) {
	ASSERTN();
	CefTouchEvent evt;
	evt.id = id;
	evt.x = x;
	evt.y = y;
	evt.radius_x = radius_x;
	evt.radius_y = radius_y;
	evt.rotation_angle = rotation_angle;
	evt.pressure = pressure;
	evt.type = (cef_touch_event_type_t)type;
	evt.modifiers = modifiers;
	evt.pointer_type = (cef_pointer_type_t)pointer_type;
	FORWARD(CefBrowser)->GetHost()->SendTouchEvent(evt);
}

///
// Send a focus event to the browser.
///
/*--cef()--*/
void ProxyBrowser::SendFocusEvent(bool setFocus) {
	ASSERTN();
	FORWARD(CefBrowser)->GetHost()->SendFocusEvent(setFocus);
}

///
// Send a capture lost event to the browser.
///
/*--cef()--*/
void ProxyBrowser::SendCaptureLostEvent() {
	ASSERTN();
	FORWARD(CefBrowser)->GetHost()->SendCaptureLostEvent();
}

///
// Notify the browser that the window hosting it is about to be moved or
// resized. This method is only used on Windows and Linux.
///
/*--cef()--*/
void ProxyBrowser::NotifyMoveOrResizeStarted() {
	ASSERTN();
	FORWARD(CefBrowser)->GetHost()->NotifyMoveOrResizeStarted();
}

///
//  Set whether the browser's audio is muted.
///
/*--cef()--*/
void ProxyBrowser::SetAudioMuted(bool mute) {
	ASSERTN();
	FORWARD(CefBrowser)->GetHost()->SetAudioMuted(mute);
}

///
// Returns true if the browser's audio is muted.  This method can only be
// called on the UI thread.
///
/*--cef()--*/
bool ProxyBrowser::IsAudioMuted() {
	ASSERTQ(false);
	return FORWARD(CefBrowser)->GetHost()->IsAudioMuted();
}

///
// Open developer tools (DevTools) in its own browser. The DevTools browser
// will remain associated with this browser. If the DevTools browser is
// already open then it will be focused, in which case the |windowInfo|,
// |client| and |settings| parameters will be ignored. If |inspect_element_at|
// is non-empty then the element at the specified (x,y) location will be
// inspected. The |windowInfo| parameter will be ignored if this browser is
// wrapped in a CefBrowserView.
///
/*--cef(optional_param=windowInfo,optional_param=client,
		optional_param=settings,optional_param=inspect_element_at)--*/
int ProxyBrowser::ShowDevTools(int inspect_element_at_x, int inspect_element_at_y) {
	ASSERTQ(0);
	CefWindowInfo winInfo;
	CefBrowserSettings browserSettings;
	std::wstringstream sstr;
	CefRefPtr<CefBrowserHost> host = FORWARD(CefBrowser)->GetHost();
	CefRefPtr<CefFrame> mainFrame = FORWARD(CefBrowser)->GetMainFrame();
	CefRefPtr<CefWaitableEvent> waitable = CefWaitableEvent::CreateWaitableEvent(false,false);
	HWND result = NULL;
	DWORD browserWnd = (DWORD)host->GetWindowHandle();

	sstr << L"DevTools - [Attach:" << std::to_wstring(browserWnd) << L"] - [Target: " << mainFrame->GetURL().c_str() << L"]";
	auto title = sstr.str();

	winInfo.SetAsPopup(NULL, title);

	host->ShowDevTools(
		winInfo, new InternalDevToolsClient(waitable,&result), browserSettings,
		CefPoint(inspect_element_at_x, inspect_element_at_y));
	WaitAwaking(waitable);

	return (int)result;
}

///
// Explicitly close the associated DevTools browser, if any.
///
/*--cef()--*/
void ProxyBrowser::CloseDevTools() {
	ASSERTN();
	FORWARD(CefBrowser)->GetHost()->CloseDevTools();
}

///
// Returns true if this browser currently has an associated DevTools browser.
// Must be called on the browser process UI thread.
///
/*--cef()--*/
bool ProxyBrowser::HasDevTools() {
	ASSERTQ(false);
	return FORWARD(CefBrowser)->GetHost()->HasDevTools();
}

///
//  GetCookieManager
///
/*--cef()--*/
shrewd_ptr<ProxyCookieManager> ProxyBrowser::GetCookieManager() {
	ASSERTQ(NULL);
	CefRefPtr<CefRequestContext> context = FORWARD(CefBrowser)->GetHost()->GetRequestContext();
	if (context) {
		return new ProxyCookieManager(context->GetCookieManager(nullptr));
	}
	return new ProxyCookieManager(CefCookieManager::GetGlobalManager(nullptr));
}

/*--cef()--*/
void ProxyBrowser::AddFirstScriptOnNewDocument(const char* script_code) {
	ASSERTN();
	if (!script_code) {
		return;
	}
	CefRefPtr<CefFrame> mainFrame = FORWARD(CefBrowser)->GetMainFrame();
	CefRefPtr<CefProcessMessage> message = CefProcessMessage::Create(L"IPC_ADD_SCRIPT_ON_NEW_DOCUMENT");
	CefRefPtr<CefListValue> params = message->GetArgumentList();
	wchar_t* buffer = ToUnicode(script_code, strlen(script_code));
	params->SetString(0, buffer);
	mainFrame->SendProcessMessage(PID_RENDERER, message);
	shrewd_ptr<ProxyClient> client = InternalClient::GetShareInatance()->GetClient();
	if (client) {
		client->SetScriptOnNewDocument(this, buffer);
	}
	DeleteBuffer(buffer);
}

void ProxyBrowser::SetUserAgentOverride(const char* user_agent, const char* app_version) {
	ASSERTN();
	USES_CONVERSION;
	const wchar_t* wideUserAgent = L"";
	const wchar_t* wideAppVersion = L"";
	CefRefPtr<CefFrame> mainFrame = FORWARD(CefBrowser)->GetMainFrame();
	CefRefPtr<CefProcessMessage> message = CefProcessMessage::Create(L"IPC_ADD_USER_AGENT_OVERRIDE");
	CefRefPtr<CefListValue> params = message->GetArgumentList();

	if (user_agent) {
		wideUserAgent = A2W(user_agent);
	}

	if (app_version) {
		wideAppVersion = A2W(app_version);
	}

	params->SetString(0, wideUserAgent);
	params->SetString(1, wideAppVersion);
	mainFrame->SendProcessMessage(PID_RENDERER, message);

	shrewd_ptr<ProxyClient> client = InternalClient::GetShareInatance()->GetClient();
	if (client) {
		client->SetUserAgentOverride(this, wideUserAgent, wideAppVersion);
	}
}

void ProxyBrowser::SetTouchEventEmulationEnabled(bool enabled, int maxTouchPoints) {
	ASSERTN();
	CefRefPtr<CefFrame> mainFrame = FORWARD(CefBrowser)->GetMainFrame();
	CefRefPtr<CefProcessMessage> message = CefProcessMessage::Create(L"IPC_TOUCH_EVENT_ENABLE");
	CefRefPtr<CefListValue> params = message->GetArgumentList();
	params->SetBool(0, enabled);
	params->SetInt(1, maxTouchPoints);
	mainFrame->SendProcessMessage(PID_RENDERER, message);
	FORWARD(CefBrowser)->SetTouchEventEmulationEnabled(true, 1);
}

void ProxyBrowser::SetGeolocationOverride(float latitude, float longitude, float accuracy) {
	ASSERTN();
	FORWARD(CefBrowser)->SetGeolocationOverride(latitude,longitude,accuracy);
}

void ProxyBrowser::SetEmulatedMedia(const char* media, shrewd_ptr<ProxyDictionaryValue> features) {
	ASSERTN();
	if (!media) {
		return;
	}
	CefRefPtr<CefFrame> mainFrame = FORWARD(CefBrowser)->GetMainFrame();
	CefRefPtr<CefProcessMessage> message = CefProcessMessage::Create(L"IPC_SET_MEDIA_FEATURES");
	CefRefPtr<CefListValue> params = message->GetArgumentList();
	USES_CONVERSION;

	params->SetString(0, A2W(media));
	if (!features || !ORIGIN(CefDictionaryValue,features)) {
		params->SetNull(1);
	}
	else {
		params->SetDictionary(1,ORIGIN(CefDictionaryValue, features));
	}
	mainFrame->SendProcessMessage(PID_RENDERER, message);

}

void ProxyBrowser::ClearMediaFeatureOverrides() {
	ASSERTN();
	CefRefPtr<CefFrame> mainFrame = FORWARD(CefBrowser)->GetMainFrame();
	CefRefPtr<CefProcessMessage> message = CefProcessMessage::Create(L"IPC_CLEAR_MEDIA_FEATURES");
	mainFrame->SendProcessMessage(PID_RENDERER, message);
}

void ProxyBrowser::EnableDeviceEmulation(shrewd_ptr<ProxyDictionaryValue> data) {
	ASSERTN();
	if (!data || !ORIGIN(CefDictionaryValue,data)) {
		return;
	}
	CefRefPtr<CefFrame> mainFrame = FORWARD(CefBrowser)->GetMainFrame();
	CefRefPtr<CefProcessMessage> message = CefProcessMessage::Create(L"IPC_ENABLE_DEVICE_EMULATION");
	CefRefPtr<CefListValue> params = message->GetArgumentList();
	params->SetDictionary(0, ORIGIN(CefDictionaryValue, data));
	mainFrame->SendProcessMessage(PID_RENDERER, message);
}

void ProxyBrowser::DisableDeviceEmulation() {
	ASSERTN();
	CefRefPtr<CefFrame> mainFrame = FORWARD(CefBrowser)->GetMainFrame();
	CefRefPtr<CefProcessMessage> message = CefProcessMessage::Create(L"IPC_DISABLE_DEVICE_EMULATION");
	mainFrame->SendProcessMessage(PID_RENDERER, message);
}

void ProxyBrowser::SetEmitTouchEventsForMouse(bool enabled, int configuration) {
	ASSERTN();
	CefRefPtr<CefFrame> mainFrame = FORWARD(CefBrowser)->GetMainFrame();
	mainFrame->SetEmitTouchEventsForMouse(enabled, configuration);
}

void ProxyBrowser::LoadExtension(const char* root_directory, shrewd_ptr<ProxyDictionaryValue> manifest) {
	ASSERTN();
	if (!root_directory) {
		return;
	}
	USES_CONVERSION;
	CefRefPtr<CefBrowserHost> host = FORWARD(CefBrowser)->GetHost();
	CefRefPtr<CefRequestContext> request = host->GetRequestContext();
	CefRefPtr<CefDictionaryValue> extra_info = nullptr;

	if (!request) {
		request = CefRequestContext::GetGlobalContext();
	}

	//if (manifest && ORIGIN(CefDictionaryValue,manifest)) {
	//	extra_info = ORIGIN(CefDictionaryValue, manifest);
	//}

	if (CefCurrentlyOn(TID_UI)) {
		request->LoadExtension(A2W(root_directory), extra_info, new InternalExtensionClient);
	}
	else {
		auto f = [](CefRefPtr<CefRequestContext> request, CefString path, CefRefPtr<CefDictionaryValue> extra_info) {
			request->LoadExtension(path, extra_info, new InternalExtensionClient);
		};
		CefRefPtr<InternalTaskVisitor> visitor = new InternalTaskVisitor(std::bind(f,request, CefString(A2W(root_directory)), extra_info));
		CefPostTask(TID_UI, visitor);
	}
	
}

bool ProxyBrowser::DidLoadExtension(const char* extension_id) {
	ASSERTQ(false);
	USES_CONVERSION;
	if (!extension_id) {
		return false;
	}
	CefRefPtr<CefBrowserHost> host = FORWARD(CefBrowser)->GetHost();
	CefRefPtr<CefRequestContext> request = host->GetRequestContext();
	CefRefPtr<CefDictionaryValue> extra_info = nullptr;

	if (!request) {
		request = CefRequestContext::GetGlobalContext();
	}

	if (CefCurrentlyOn(TID_UI)) {
		return request->DidLoadExtension(A2W(extension_id));
	}


	bool result = false;
	CefRefPtr<CefWaitableEvent> waitable = CefWaitableEvent::CreateWaitableEvent(false, false);
	auto f = [](CefRefPtr<CefRequestContext> request, CefRefPtr<CefWaitableEvent> waitable, CefString extension_id, bool* result) {
		*result = request->DidLoadExtension(extension_id);
		waitable->Signal();
	};
	CefRefPtr<InternalTaskVisitor> task = new InternalTaskVisitor(std::bind(f,request, waitable,CefString(A2W(extension_id)),&result));
	CefPostTask(TID_UI, task);
	WaitAwaking(waitable);
	return result;
}

bool ProxyBrowser::HasExtension(const char* extension_id) {
	ASSERTQ(false);
	USES_CONVERSION;
	if (!extension_id) {
		return false;
	}
	CefRefPtr<CefBrowserHost> host = FORWARD(CefBrowser)->GetHost();
	CefRefPtr<CefRequestContext> request = host->GetRequestContext();
	CefRefPtr<CefDictionaryValue> extra_info = nullptr;

	if (!request) {
		request = CefRequestContext::GetGlobalContext();
	}

	if (CefCurrentlyOn(TID_UI)) {
		return request->HasExtension(A2W(extension_id));
	}

	bool result = false;
	CefRefPtr<CefWaitableEvent> waitable = CefWaitableEvent::CreateWaitableEvent(false, false);
	auto f = [](CefRefPtr<CefRequestContext> request, CefRefPtr<CefWaitableEvent> waitable, CefString extension_id, bool* result) {
		*result = request->HasExtension(extension_id);
		waitable->Signal();
	};
	CefRefPtr<InternalTaskVisitor> task = new InternalTaskVisitor(std::bind(f, request, waitable, CefString(A2W(extension_id)), &result));
	CefPostTask(TID_UI, task);
	WaitAwaking(waitable);
	return result;
}

char** ProxyBrowser::GetExtensions() {
	ASSERTARRAY(char);
	assert(NewBuffer);
	std::vector<CefString> originNameArrays;
	CefRefPtr<CefBrowserHost> host = FORWARD(CefBrowser)->GetHost();
	CefRefPtr<CefRequestContext> request = host->GetRequestContext();
	CefRefPtr<CefDictionaryValue> extra_info = nullptr;

	if (!request) {
		request = CefRequestContext::GetGlobalContext();
	}


	if (CefCurrentlyOn(TID_UI)) {
		request->GetExtensions(originNameArrays);

		int count = originNameArrays.size() - 1;
		DWORD* pointer = (DWORD*)NewBuffer(sizeof(INT) * (2 + count));
		*(pointer + 0) = 1;
		*(pointer + 1) = count;

		if (originNameArrays.empty()) {
			return (char**)pointer;
		}

		for (size_t i = 0; i < count; i++) {
			*(pointer + i + 2) = (DWORD)ToAnsi(originNameArrays[i + 1].c_str(), originNameArrays[i + 1].length());
		}
		return (char**)pointer;
	}


	CefRefPtr<CefWaitableEvent> waitable = CefWaitableEvent::CreateWaitableEvent(false, false);
	auto f = [](CefRefPtr<CefRequestContext> request, CefRefPtr<CefWaitableEvent> waitable, std::vector<CefString>* result) {
		request->GetExtensions((*result));
		waitable->Signal();
	};
	CefRefPtr<InternalTaskVisitor> task = new InternalTaskVisitor(std::bind(f, request, waitable, &originNameArrays));
	CefPostTask(TID_UI, task);
	WaitAwaking(waitable);

	int count = originNameArrays.size() - 1;
	DWORD* pointer = (DWORD*)NewBuffer(sizeof(INT) * (2 + count));
	*(pointer + 0) = 1;
	*(pointer + 1) = count;

	if (originNameArrays.empty()) {
		return (char**)pointer;
	}

	for (size_t i = 0; i < count; i++) {
		*(pointer + i + 2) = (DWORD)ToAnsi(originNameArrays[i + 1].c_str(), originNameArrays[i + 1].length());
	}
	return (char**)pointer;
}

shrewd_ptr<ProxyExtension> ProxyBrowser::GetExtension(const char* extension_id) {
	ASSERTQ(false);
	USES_CONVERSION;
	if (!extension_id) {
		return false;
	}
	CefRefPtr<CefBrowserHost> host = FORWARD(CefBrowser)->GetHost();
	CefRefPtr<CefRequestContext> request = host->GetRequestContext();
	CefRefPtr<CefDictionaryValue> extra_info = nullptr;
	CefRefPtr<CefExtension> extension = nullptr;

	if (!request) {
		request = CefRequestContext::GetGlobalContext();
	}

	if (CefCurrentlyOn(TID_UI)) {
		extension = request->GetExtension(A2W(extension_id));

		if (!extension) {
			return nullptr;
		}
		return new ProxyExtension(extension);
	}

	CefRefPtr<CefWaitableEvent> waitable = CefWaitableEvent::CreateWaitableEvent(false, false);
	auto f = [](CefRefPtr<CefRequestContext> request, CefRefPtr<CefWaitableEvent> waitable, CefString extension_id, CefRefPtr<CefExtension>* result) {
		*result = request->GetExtension(extension_id);
		waitable->Signal();
	};
	CefRefPtr<InternalTaskVisitor> task = new InternalTaskVisitor(std::bind(f, request, waitable, CefString(A2W(extension_id)), &extension));
	CefPostTask(TID_UI, task);
	WaitAwaking(waitable);

	if (extension) {
		return new ProxyExtension(extension);
	}

	return nullptr;
}

bool ProxyBrowser::IsBackgroundHost() {
	ASSERTQ(false);
	return FORWARD(CefBrowser)->GetHost()->IsBackgroundHost();
}

shrewd_ptr<ProxyListValue> ProxyBrowser::GetUserData() {
	ASSERTQ(NULL);
	shrewd_ptr<ProxyClient> client = InternalClient::GetShareInatance()->GetClient();
	return client->GetUsetData(this);
}

bool ProxyBrowser::HasPreference(const char* name) {
	ASSERTQ(false);
	USES_CONVERSION;
	if (!name) {
		return false;
	}
	CefRefPtr<CefRequestContext> request = FORWARD(CefBrowser)->GetHost()->GetRequestContext();
	if (!request) {
		request = CefRequestContext::GetGlobalContext();
	}

	if (CefCurrentlyOn(TID_UI)) {
		return request->HasPreference(A2W(name));
	}

	bool result = false;
	CefRefPtr<CefWaitableEvent> waitable = CefWaitableEvent::CreateWaitableEvent(false, false);
	auto f = [](CefRefPtr<CefRequestContext> request, CefRefPtr<CefWaitableEvent> waitable, CefString name , bool* result) {
		*result = request->HasPreference(name);
		waitable->Signal();
	};
	CefRefPtr<InternalTaskVisitor> task = new InternalTaskVisitor(std::bind(f,request, waitable, CefString(A2W(name)),&result));
	CefPostTask(TID_UI, task);
	WaitAwaking(waitable);
	return result;
}

shrewd_ptr<ProxyValue> ProxyBrowser::GetPreference(const char* name) {
	ASSERTQ(nullptr);
	USES_CONVERSION;
	if (!name) {
		return nullptr;
	}
	CefRefPtr<CefRequestContext> request = FORWARD(CefBrowser)->GetHost()->GetRequestContext();
	if (!request) {
		request = CefRequestContext::GetGlobalContext();
	}

	CefRefPtr<CefValue> result = nullptr;

	if (CefCurrentlyOn(TID_UI)) {
		result = request->GetPreference(A2W(name));
		if (!result) {
			return nullptr;
		}
		return new ProxyValue(result);
	}

	
	CefRefPtr<CefWaitableEvent> waitable = CefWaitableEvent::CreateWaitableEvent(false, false);
	auto f = [](CefRefPtr<CefRequestContext> request, CefRefPtr<CefWaitableEvent> waitable, CefString name, CefRefPtr<CefValue>* result) {
		*result = request->GetPreference(name);
		waitable->Signal();
	};
	CefRefPtr<InternalTaskVisitor> task = new InternalTaskVisitor(std::bind(f, request, waitable, CefString(A2W(name)), &result));
	CefPostTask(TID_UI, task);
	WaitAwaking(waitable);
	if(result){
		return new ProxyValue(result);
	}
	return nullptr;
}

shrewd_ptr<ProxyDictionaryValue> ProxyBrowser::GetAllPreferences(bool include_defaults) {
	ASSERTQ(nullptr);
	USES_CONVERSION;
	CefRefPtr<CefRequestContext> request = FORWARD(CefBrowser)->GetHost()->GetRequestContext();
	if (!request) {
		request = CefRequestContext::GetGlobalContext();
	}

	CefRefPtr<CefDictionaryValue> result = nullptr;

	if (CefCurrentlyOn(TID_UI)) {
		result = request->GetAllPreferences(include_defaults);
		if (!result) {
			return nullptr;
		}
		return new ProxyDictionaryValue(result);
	}

	
	CefRefPtr<CefWaitableEvent> waitable = CefWaitableEvent::CreateWaitableEvent(false, false);
	auto f = [](CefRefPtr<CefRequestContext> request, CefRefPtr<CefWaitableEvent> waitable, bool include_defaults, CefRefPtr<CefDictionaryValue>* result) {
		*result = request->GetAllPreferences(include_defaults);
		waitable->Signal();
	};
	CefRefPtr<InternalTaskVisitor> task = new InternalTaskVisitor(std::bind(f, request, waitable, include_defaults, &result));
	CefPostTask(TID_UI, task);
	WaitAwaking(waitable);
	if (result) {
		return new ProxyDictionaryValue(result);
	}
	return nullptr;
}

bool ProxyBrowser::CanSetPreference(const char* name) {
	ASSERTQ(false);
	USES_CONVERSION;
	if (!name) {
		return false;
	}
	CefRefPtr<CefRequestContext> request = FORWARD(CefBrowser)->GetHost()->GetRequestContext();
	if (!request) {
		request = CefRequestContext::GetGlobalContext();
	}
	bool result = false;

	if (CefCurrentlyOn(TID_UI)) {
		return request->CanSetPreference(A2W(name));;
	}


	CefRefPtr<CefWaitableEvent> waitable = CefWaitableEvent::CreateWaitableEvent(false, false);
	auto f = [](CefRefPtr<CefRequestContext> request, CefRefPtr<CefWaitableEvent> waitable, CefString name, bool* result) {
		*result = request->CanSetPreference(name);
		waitable->Signal();
	};
	CefRefPtr<InternalTaskVisitor> task = new InternalTaskVisitor(std::bind(f, request, waitable, CefString(A2W(name)), &result));
	CefPostTask(TID_UI, task);
	WaitAwaking(waitable);
	return result;
}

bool ProxyBrowser::SetPreference(const char* name, shrewd_ptr<ProxyValue> value) {
	ASSERTQ(false);
	USES_CONVERSION;
	if (!name) {
		return false;
	}
	if (!value || !ORIGIN(CefValue,value)) {
		return false;
	}
	CefRefPtr<CefRequestContext> request = FORWARD(CefBrowser)->GetHost()->GetRequestContext();
	if (!request) {
		request = CefRequestContext::GetGlobalContext();
	}
	bool result = false;

	if (CefCurrentlyOn(TID_UI)) {
		CefString error;
		return request->SetPreference(A2W(name), ORIGIN(CefValue, value),error);
	}

	CefRefPtr<CefWaitableEvent> waitable = CefWaitableEvent::CreateWaitableEvent(false, false);
	auto f = [](CefRefPtr<CefRequestContext> request, CefRefPtr<CefWaitableEvent> waitable, CefString name, CefRefPtr<CefValue> value, bool* result) {
		CefString error;
		*result = request->SetPreference(name,value, error);
		waitable->Signal();
	};
	CefRefPtr<InternalTaskVisitor> task = new InternalTaskVisitor(std::bind(f, request, waitable, CefString(A2W(name)), ORIGIN(CefValue,value), &result));
	CefPostTask(TID_UI, task);
	WaitAwaking(waitable);
	return result;
}