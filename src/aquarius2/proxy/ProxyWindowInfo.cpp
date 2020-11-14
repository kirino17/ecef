#include "ProxyWindowInfo.h"
#include "include/cef_browser.h"
#include <atlconv.h>

ProxyWindowInfo::ProxyWindowInfo(void* ptr):_rawptr(ptr) {

}

ProxyWindowInfo::~ProxyWindowInfo() {
	if (_rawptr) {
		delete (CefWindowInfo*)_rawptr;
		_rawptr = NULL;
	}
}

// is valid
bool ProxyWindowInfo::IsValid() {
	return _rawptr != nullptr;
}

///
// Create the browser as a child window.
///
void ProxyWindowInfo::SetAsChild(unsigned int parent, int x, int y, int width, int height) {
	if(!_rawptr) return;
	((CefWindowInfo*)_rawptr)->style =
		WS_CHILD | WS_CLIPCHILDREN | WS_CLIPSIBLINGS | WS_TABSTOP | WS_VISIBLE;
	((CefWindowInfo*)_rawptr)->parent_window = (HWND)parent;
	((CefWindowInfo*)_rawptr)->x = x;
	((CefWindowInfo*)_rawptr)->y = y;
	((CefWindowInfo*)_rawptr)->width = width;
	((CefWindowInfo*)_rawptr)->height = height;
}

///
// Create the browser as a popup window.
///
void ProxyWindowInfo::SetAsPopup(unsigned int parent, const char* windowName) {
	if(!_rawptr) return; 
	((CefWindowInfo*)_rawptr)->style =
		WS_OVERLAPPEDWINDOW | WS_CLIPCHILDREN | WS_CLIPSIBLINGS | WS_VISIBLE;
	((CefWindowInfo*)_rawptr)->parent_window = (HWND)parent;
	((CefWindowInfo*)_rawptr)->x = CW_USEDEFAULT;
	((CefWindowInfo*)_rawptr)->y = CW_USEDEFAULT;
	((CefWindowInfo*)_rawptr)->width = CW_USEDEFAULT;
	((CefWindowInfo*)_rawptr)->height = CW_USEDEFAULT;
	if (windowName) {
		USES_CONVERSION;
		CefString(&((CefWindowInfo*)_rawptr)->window_name) = A2W(windowName);
	}
}