#include "ProxyBrowser.h"
#include "include/cef_browser.h"
#include <sstream>
#include <codecvt>
#include <atlconv.h>
#include "ProxyFrame.h"
#include "ProxyBrowserHost.h"
#include "../def/internalDef.h"

AQUA_PROXY_AUTO_CONSTRUCTOR(ProxyBrowser,CefBrowser);

///
// Returns the browser host object. This method can only be called in the
// browser process.
///
/*--cef()--*/
shrewd_ptr<ProxyBrowserHost> ProxyBrowser::GetHost() {
	ASSERTQ(NULL);
	return new ProxyBrowserHost(FORWARD(CefBrowser)->GetHost());
}

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
// Returns true if this object is pointing to the same handle as |that|
// object.
///
/*--cef()--*/
bool ProxyBrowser::IsSame(shrewd_ptr<ProxyBrowser> that) {
	ASSERTQ(false);
	if (!that || !ORIGIN(CefBrowser, that)) return false;
	return FORWARD(CefBrowser)->IsSame(ORIGIN(CefBrowser,that));
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
	return new ProxyFrame(FORWARD(CefBrowser)->GetFrame((int64)identity));
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
	ASSERTQ(0);
	assert(NewBuffer);
	std::vector<CefString> originNameArrays;
	FORWARD(CefBrowser)->GetFrameNames(originNameArrays);
	int count = originNameArrays.size() - 1;
	DWORD* pointer = (DWORD*)NewBuffer( sizeof(INT)*(2 + count));
	*(pointer + 0) = 1;
	*(pointer + 1) = count;
	for (size_t i = 0; i < count; i++){
		*(pointer + i + 2) = (DWORD)ToAnsi(originNameArrays[i+1].c_str(), originNameArrays[i+1].length());
	}
	return (char**)pointer;
}

///
// 获取ids
///
__int64** ProxyBrowser::GetFrameIdentifiers() {
	ASSERTQ(0);
	assert(NewBuffer);
	std::vector<int64> originIdentityArrays;
	FORWARD(CefBrowser)->GetFrameIdentifiers(originIdentityArrays);
	int count = originIdentityArrays.size() - 1;
	DWORD* pointer = (DWORD*)NewBuffer(2*sizeof(INT) + count*sizeof(__int64));
	*(pointer + 0) = 1;
	*(pointer + 1) = count;

	__int64* base = (__int64*)(pointer + 2);
	for (size_t i = 0; i < count; i++) {
		*(base + i) = originIdentityArrays[i+1];
	}
	return (__int64**)pointer;
}

///
// 获取frames
///
shrewd_ptr<ProxyFrame>** ProxyBrowser::GetFrames() {
	ASSERTQ(0);
	assert(NewBuffer);
	std::vector<int64> originIdentityArrays;
	FORWARD(CefBrowser)->GetFrameIdentifiers(originIdentityArrays);
	int count = originIdentityArrays.size() - 1;
	DWORD* pointer = (DWORD*)NewBuffer(2 * sizeof(INT) + count * sizeof(DWORD));
	shrewd_ptr<ProxyFrame> frame = nullptr;
	*(pointer + 0) = 1;
	*(pointer + 1) = count;
	
	DWORD* base = (pointer + 2);
	for (size_t i = 0; i < count; i++) {
		DWORD* item = (DWORD*)NewBuffer(sizeof(DWORD));
		frame =  new ProxyFrame(FORWARD(CefBrowser)->GetFrame(originIdentityArrays[i+1]));
		frame->retain();
		*item = (DWORD)frame.get();
		*(base + i) = (DWORD)item;
	}
	return (shrewd_ptr<ProxyFrame>**)pointer;
}