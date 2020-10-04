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

shrewd_ptr<ProxyWindowInfo> ProxyWindowInfo::Create() {
	return new ProxyWindowInfo( new CefWindowInfo );
}

// is valid
bool ProxyWindowInfo::IsValid() {
	return _rawptr != nullptr;
}

// Standard parameters required by CreateWindowEx()
void ProxyWindowInfo::SetExStyle(unsigned int ex_style) {
	if(!_rawptr) return; ((CefWindowInfo*)_rawptr)->ex_style = ex_style;
}

void ProxyWindowInfo::SetWindowName(const char* window_name) {
	if (!_rawptr) return;
	if (window_name) {
		USES_CONVERSION;
		CefString(&((CefWindowInfo*)_rawptr)->window_name) = A2W(window_name);
	}
}

void ProxyWindowInfo::SetStyle(unsigned int style) {
	if(!_rawptr) return; ((CefWindowInfo*)_rawptr)->style = style;
}

void ProxyWindowInfo::SetX(int x) {
	if(!_rawptr) return; ((CefWindowInfo*)_rawptr)->x = x;
}

void ProxyWindowInfo::SetY(int y) {
	if(!_rawptr) return; ((CefWindowInfo*)_rawptr)->y = y;
}

void ProxyWindowInfo::SetWidth(int width) {
	if(!_rawptr) return; ((CefWindowInfo*)_rawptr)->width = width;
}

void ProxyWindowInfo::SetHeight(int height) {
	if(!_rawptr) return; ((CefWindowInfo*)_rawptr)->height = height;
}

void ProxyWindowInfo::SetParentWindow(unsigned int parent_window) {
	if(!_rawptr) return; ((CefWindowInfo*)_rawptr)->parent_window = (HWND)parent_window;
}

void ProxyWindowInfo::SetMenu(unsigned int menu) {
	if(!_rawptr) return; ((CefWindowInfo*)_rawptr)->menu = (HMENU)menu;
}

///
// Set to true (1) to create the browser using windowless (off-screen)
// rendering. No window will be created for the browser and all rendering will
// occur via the CefRenderHandler interface. The |parent_window| value will be
// used to identify monitor info and to act as the parent window for dialogs,
// context menus, etc. If |parent_window| is not provided then the main screen
// monitor will be used and some functionality that requires a parent window
// may not function correctly. In order to create windowless browsers the
// CefSettings.windowless_rendering_enabled value must be set to true.
// Transparent painting is enabled by default but can be disabled by setting
// CefBrowserSettings.background_color to an opaque value.
///
void ProxyWindowInfo::SetWindowlessRenderingEnabled(int value) {
	if(!_rawptr) return; ((CefWindowInfo*)_rawptr)->windowless_rendering_enabled = value;
}

///
// Set to true (1) to enable shared textures for windowless rendering. Only
// valid if windowless_rendering_enabled above is also set to true. Currently
// only supported on Windows (D3D11).
///
void ProxyWindowInfo::SetSharedtextureEnabled(int value) {
	if(!_rawptr) return; ((CefWindowInfo*)_rawptr)->shared_texture_enabled = value;
}

///
// Set to true (1) to enable the ability to issue BeginFrame requests from the
// client application by calling CefBrowserHost::SendExternalBeginFrame.
///
void ProxyWindowInfo::SetExternalBeginFrameEnabled(int value) {
	if(!_rawptr) return; ((CefWindowInfo*)_rawptr)->external_begin_frame_enabled = value;
}

///
// Handle for the new browser window. Only used with windowed rendering.
///
void ProxyWindowInfo::SetWindow(unsigned int window) {
	if(!_rawptr) return; ((CefWindowInfo*)_rawptr)->window = (HWND)window;
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


///
// Create the browser using windowless (off-screen) rendering. No window
// will be created for the browser and all rendering will occur via the
// CefRenderHandler interface. The |parent| value will be used to identify
// monitor info and to act as the parent window for dialogs, context menus,
// etc. If |parent| is not provided then the main screen monitor will be used
// and some functionality that requires a parent window may not function
// correctly. In order to create windowless browsers the
// CefSettings.windowless_rendering_enabled value must be set to true.
// Transparent painting is enabled by default but can be disabled by setting
// CefBrowserSettings.background_color to an opaque value.
///
void ProxyWindowInfo::SetAsWindowless(unsigned int parent) {
	if(!_rawptr) return; 
	((CefWindowInfo*)_rawptr)->windowless_rendering_enabled = TRUE;
	((CefWindowInfo*)_rawptr)->parent_window = (HWND)parent;
}