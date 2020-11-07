#include "ProxyActiveBrowserCallback.h"
#include "include/cef_browser.h"


ProxyActiveBrowserCallback::ProxyActiveBrowserCallback(void* ptr):_rawptr(ptr) {

}

ProxyActiveBrowserCallback::~ProxyActiveBrowserCallback() {
	_rawptr = nullptr;
}

void ProxyActiveBrowserCallback::SetBrowser(shrewd_ptr<ProxyBrowser> browser) {
	if (_rawptr && browser && ORIGIN(CefBrowser, browser)) {
		CefRefPtr<CefBrowser>* pointer = (CefRefPtr<CefBrowser>*)_rawptr;
		(*pointer) = ORIGIN(CefBrowser, browser);
		_rawptr = nullptr;
	}
}
