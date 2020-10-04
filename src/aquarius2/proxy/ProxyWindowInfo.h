#pragma once
#include "../def/def.h"

class AQUADLL ProxyWindowInfo : public refcounted {
public:
	ProxyWindowInfo(void* ptr);
	~ProxyWindowInfo();

public:
    static shrewd_ptr<ProxyWindowInfo> Create();

public:
    // is valid
    bool IsValid();

    /*--cef()--*/
    void SetExStyle(unsigned int ex_style);
    /*--cef()--*/
    void SetWindowName(const char* window_name);
    /*--cef()--*/
    void SetStyle(unsigned int style);
    /*--cef()--*/
    void SetX(int x);
    /*--cef()--*/
    void SetY(int y);
    /*--cef()--*/
    void SetWidth(int width);
    /*--cef()--*/
    void SetHeight(int height);
    /*--cef()--*/
    void SetParentWindow(unsigned int parent_window);
    /*--cef()--*/
    void SetMenu(unsigned int menu);

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
    void SetWindowlessRenderingEnabled(int value);

    ///
    // Set to true (1) to enable shared textures for windowless rendering. Only
    // valid if windowless_rendering_enabled above is also set to true. Currently
    // only supported on Windows (D3D11).
    ///
    void SetSharedtextureEnabled(int value);

    ///
    // Set to true (1) to enable the ability to issue BeginFrame requests from the
    // client application by calling CefBrowserHost::SendExternalBeginFrame.
    ///
    void SetExternalBeginFrameEnabled(int value);

    ///
    // Handle for the new browser window. Only used with windowed rendering.
    ///
    void SetWindow(unsigned int window);

    ///
    // Create the browser as a child window.
    ///
    void SetAsChild(unsigned int parent, int x, int y, int width, int height);

    ///
    // Create the browser as a popup window.
    ///
    void SetAsPopup(unsigned int parent, const char* windowName);

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
    void SetAsWindowless(unsigned int parent);

public:
	PRIME_IMPLEMENT_REFCOUNTING(ProxyWindowInfo);
    AQUA_DECL_PUBLIC_ORIGIN;

public:
    void* _rawptr;
};