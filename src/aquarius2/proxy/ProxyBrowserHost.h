#pragma once
#include "../def/def.h"
#include "ProxyRequestContext.h"
#include "ProxyKeyEvent.h"
#include "ProxyMouseEvent.h"
#include "ProxyTouchEvent.h"
#include "ProxyBrowserSettings.h"
#include "ProxyWindowInfo.h"

class ProxyBrowser;

class AQUADLL ProxyBrowserHost : public refcounted {
public:
	ProxyBrowserHost(void* ptr);
	~ProxyBrowserHost();

public:
    // is valid
    bool IsValid();

    ///
    // Returns the hosted browser object.
    ///
    /*--cef()--*/
     shrewd_ptr<ProxyBrowser> GetBrowser();

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
     void CloseBrowser(bool force_close);

    ///
    // Helper for closing a browser. Call this method from the top-level window
    // close handler. Internally this calls CloseBrowser(false) if the close has
    // not yet been initiated. This method returns false while the close is
    // pending and true after the close has completed. See CloseBrowser() and
    // CefLifeSpanHandler::DoClose() documentation for additional usage
    // information. This method must be called on the browser process UI thread.
    ///
    /*--cef()--*/
     bool TryCloseBrowser();

    ///
    // Set whether the browser is focused.
    ///
    /*--cef()--*/
     void SetFocus(bool focus);

    ///
    // Retrieve the window handle for this browser. If this browser is Proxyped in
    // a CefBrowserView this method should be called on the browser process UI
    // thread and it will return the handle for the top-level native window.
    ///
    /*--cef()--*/
     void* GetWindowHandle();

    ///
    // Retrieve the window handle of the browser that opened this browser. Will
    // return NULL for non-popup windows or if this browser is Proxyped in a
    // CefBrowserView. This method can be used in combination with custom handling
    // of modal windows.
    ///
    /*--cef()--*/
     void* GetOpenerWindowHandle();

    ///
    // Returns the request context for this browser.
    ///
    /*--cef()--*/
     shrewd_ptr<ProxyRequestContext> GetRequestContext();

    ///
    // Get the current zoom level. The default zoom level is 0.0. This method can
    // only be called on the UI thread.
    ///
    /*--cef()--*/
     double GetZoomLevel();

    ///
    // Change the zoom level to the specified value. Specify 0.0 to reset the
    // zoom level. If called on the UI thread the change will be applied
    // immediately. Otherwise, the change will be applied asynchronously on the
    // UI thread.
    ///
    /*--cef()--*/
     void SetZoomLevel(double zoomLevel);

    ///
    // Download the file at |url| using CefDownloadHandler.
    ///
    /*--cef()--*/
     void StartDownload(const char* url);

    ///
    // Print the current browser contents.
    ///
    /*--cef()--*/
     void Print();

    ///
    // Set whether mouse cursor change is disabled.
    ///
    /*--cef()--*/
     void SetMouseCursorChangeDisabled(bool disabled);

    ///
    // Returns true if mouse cursor change is disabled.
    ///
    /*--cef()--*/
     bool IsMouseCursorChangeDisabled();

    ///
    // If a misspelled word is currently selected in an editable node calling
    // this method will replace it with the specified |word|.
    ///
    /*--cef()--*/
     void ReplaceMisspelling(const char* word);

    ///
    // Add the specified |word| to the spelling dictionary.
    ///
    /*--cef()--*/
     void AddWordToDictionary(const char* word);

    ///
    // Returns true if window rendering is disabled.
    ///
    /*--cef()--*/
     bool IsWindowRenderingDisabled();

    ///
    // Notify the browser that the widget has been resized. The browser will first
    // call CefRenderHandler::GetViewRect to get the new size and then call
    // CefRenderHandler::OnPaint asynchronously with the updated regions. This
    // method is only used when window rendering is disabled.
    ///
    /*--cef()--*/
     void WasResized();

    ///
    // Notify the browser that it has been hidden or shown. Layouting and
    // CefRenderHandler::OnPaint notification will stop when the browser is
    // hidden. This method is only used when window rendering is disabled.
    ///
    /*--cef()--*/
     void WasHidden(bool hidden);

    ///
    // Send a notification to the browser that the screen info has changed. The
    // browser will then call CefRenderHandler::GetScreenInfo to update the
    // screen information with the new values. This simulates moving the webview
    // window from one display to another, or changing the properties of the
    // current display. This method is only used when window rendering is
    // disabled.
    ///
    /*--cef()--*/
     void NotifyScreenInfoChanged();

    ///
    // Send a key event to the browser.
    ///
    /*--cef()--*/
     void SendKeyEvent(shrewd_ptr<ProxyKeyEvent> event);

    ///
    // Send a mouse click event to the browser. The |x| and |y| coordinates are
    // relative to the upper-left corner of the view.
    ///
    /*--cef()--*/
     void SendMouseClickEvent(shrewd_ptr<ProxyMouseEvent> event,
        int type,
        bool mouseUp,
        int clickCount);

    ///
    // Send a mouse move event to the browser. The |x| and |y| coordinates are
    // relative to the upper-left corner of the view.
    ///
    /*--cef()--*/
     void SendMouseMoveEvent(shrewd_ptr<ProxyMouseEvent> event,
        bool mouseLeave);

    ///
    // Send a mouse wheel event to the browser. The |x| and |y| coordinates are
    // relative to the upper-left corner of the view. The |deltaX| and |deltaY|
    // values represent the movement delta in the X and Y directions respectively.
    // In order to scroll inside select popups with window rendering disabled
    // CefRenderHandler::GetScreenPoint should be implemented properly.
    ///
    /*--cef()--*/
     void SendMouseWheelEvent(shrewd_ptr<ProxyMouseEvent> event,
        int deltaX,
        int deltaY);

    ///
    // Send a touch event to the browser for a windowless browser.
    ///
    /*--cef()--*/
     void SendTouchEvent(shrewd_ptr<ProxyTouchEvent> event);

    ///
    // Send a focus event to the browser.
    ///
    /*--cef()--*/
     void SendFocusEvent(bool setFocus);

    ///
    // Send a capture lost event to the browser.
    ///
    /*--cef()--*/
     void SendCaptureLostEvent();

    ///
    // Notify the browser that the window hosting it is about to be moved or
    // resized. This method is only used on Windows and Linux.
    ///
    /*--cef()--*/
     void NotifyMoveOrResizeStarted();

    ///
    // Returns the maximum rate in frames per second (fps) that CefRenderHandler::
    // OnPaint will be called for a windowless browser. The actual fps may be
    // lower if the browser cannot generate frames at the requested rate. The
    // minimum value is 1 and the maximum value is 60 (default 30). This method
    // can only be called on the UI thread.
    ///
    /*--cef()--*/
     int GetWindowlessFrameRate();

    ///
    // Set the maximum rate in frames per second (fps) that CefRenderHandler::
    // OnPaint will be called for a windowless browser. The actual fps may be
    // lower if the browser cannot generate frames at the requested rate. The
    // minimum value is 1 and the maximum value is 60 (default 30). Can also be
    // set at browser creation via CefBrowserSettings.windowless_frame_rate.
    ///
    /*--cef()--*/
     void SetWindowlessFrameRate(int frame_rate);

    ///
    //  Set whether the browser's audio is muted.
    ///
    /*--cef()--*/
     void SetAudioMuted(bool mute);

    ///
    // Returns true if the browser's audio is muted.  This method can only be
    // called on the UI thread.
    ///
    /*--cef()--*/
     bool IsAudioMuted();


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
      void ShowDevTools(shrewd_ptr<ProxyWindowInfo> windowInfo,
         shrewd_ptr<ProxyBrowserSettings> settings,
         int inspect_element_at_x, int inspect_element_at_y);

     ///
     // Explicitly close the associated DevTools browser, if any.
     ///
     /*--cef()--*/
      void CloseDevTools();

     ///
     // Returns true if this browser currently has an associated DevTools browser.
     // Must be called on the browser process UI thread.
     ///
     /*--cef()--*/
      bool HasDevTools();

public:
	PRIME_IMPLEMENT_REFCOUNTING(ProxyBrowserHost);
	AQUA_DECL_PUBLIC_ORIGIN;

private:
	void* _rawptr;
};