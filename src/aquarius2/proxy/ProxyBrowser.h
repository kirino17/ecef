#pragma once
#include "../def/def.h"
#include "ProxyValue.h"
#include "ProxyCookieManager.h"
#include "ProxyExtension.h"

class ProxyFrame;
class ProxyBrowserHost;

class AQUADLL ProxyBrowser : public refcounted {
public:
	ProxyBrowser(void* ptr = NULL);
	~ProxyBrowser();

public:
    // is valid
    bool IsValid();

    ///
    // Retrieve the window handle for this browser. If this browser is Proxyped in
    // a CefBrowserView this method should be called on the browser process UI
    // thread and it will return the handle for the top-level native window.
    ///
    /*--cef()--*/
    void* GetWindowHandle();

    ///
    // Returns true if the browser can navigate backwards.
    ///
    /*--cef()--*/
     bool CanGoBack();

    ///
    // Navigate backwards.
    ///
    /*--cef()--*/
     void GoBack();

    ///
    // Returns true if the browser can navigate forwards.
    ///
    /*--cef()--*/
     bool CanGoForward();

    ///
    // Navigate forwards.
    ///
    /*--cef()--*/
     void GoForward();

    ///
    // Returns true if the browser is currently loading.
    ///
    /*--cef()--*/
     bool IsLoading();

    ///
    // Reload the current page.
    ///
    /*--cef()--*/
     void Reload();

    ///
    // Reload the current page ignoring any cached data.
    ///
    /*--cef()--*/
     void ReloadIgnoreCache();

    ///
    // Stop loading the page.
    ///
    /*--cef()--*/
     void StopLoad();

    ///
    // Returns the globally unique identifier for this browser. This value is also
    // used as the tabId for extension APIs.
    ///
    /*--cef()--*/
     int GetIdentifier();

    ///
    // Returns true if the window is a popup window.
    ///
    /*--cef()--*/
     bool IsPopup();

    ///
    // Returns true if a document has been loaded in the browser.
    ///
    /*--cef()--*/
     bool HasDocument();

    ///
    // Returns the main (top-level) frame for the browser window.
    ///
    /*--cef()--*/
     shrewd_ptr<ProxyFrame> GetMainFrame();

    ///
    // Returns the focused frame for the browser window.
    ///
    /*--cef()--*/
     shrewd_ptr<ProxyFrame> GetFocusedFrame();

    ///
    // Returns the frame with the specified name, or NULL if not found.
    ///
    /*--cef(optional_param=name)--*/
     shrewd_ptr<ProxyFrame> GetFrame(const char* name);

     ///
    // Returns the frame with the specified identity, or NULL if not found.
    ///
    /*--cef(optional_param=name)--*/
     shrewd_ptr<ProxyFrame> GetFrameWithIdentity(__int64 identity);

    ///
    // Returns the number of frames that currently exist.
    ///
    /*--cef()--*/
     size_t GetFrameCount();

    ///
    // names
    ///
    /*--cef()--*/
     char** GetFrameNames();

     ///
     // 获取ids
     ///
     __int64** GetFrameIdentifiers();

     ///
     // 获取frames
     ///
     shrewd_ptr<ProxyFrame>** GetFrames();

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
     // Set whether the browser is focused.
     ///
     /*--cef()--*/
     void SetFocus(bool focus);

     ///
     // Retrieve the window handle of the browser that opened this browser. Will
     // return NULL for non-popup windows or if this browser is Proxyped in a
     // CefBrowserView. This method can be used in combination with custom handling
     // of modal windows.
     ///
     /*--cef()--*/
     void* GetOpenerWindowHandle();

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

     void SendKeyDownEvent(int key, bool is_system_key, int modifiers);

     void SendKeyUpEvent(int key, bool is_system_key, int modifiers);

     void SendKeyPressEvent(int key, bool is_system_key,int duration,int modifiers);

     void SendCharEvent(char charactor);

     void SendCharArrayEvent(const char* charactor, int duration);

     ///
     // Send a mouse click event to the browser. The |x| and |y| coordinates are
     // relative to the upper-left corner of the view.
     ///
     /*--cef()--*/
     void SendMouseClickEvent(int x, int y, int type, bool mouseUp, int clickCount, int modifiers);

     ///
     // Send a mouse move event to the browser. The |x| and |y| coordinates are
     // relative to the upper-left corner of the view.
     ///
     /*--cef()--*/
     void SendMouseMoveEvent(int x, int y, bool mouseLeave, int modifiers);

     ///
     // Send a mouse wheel event to the browser. The |x| and |y| coordinates are
     // relative to the upper-left corner of the view. The |deltaX| and |deltaY|
     // values represent the movement delta in the X and Y directions respectively.
     // In order to scroll inside select popups with window rendering disabled
     // CefRenderHandler::GetScreenPoint should be implemented properly.
     ///
     /*--cef()--*/
     void SendMouseWheelEvent(int x, int y,int deltaX,int deltaY, int modifiers);

     ///
     // Send a touch event to the browser for a windowless browser.
     ///
     /*--cef()--*/
     void SendTouchEvent(int id, float x, float y, float radius_x, float radius_y, float rotation_angle, float pressure, int type, int modifiers, int pointer_type);

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
     int ShowDevTools(int inspect_element_at_x, int inspect_element_at_y);

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

     ///
     // GetCookieManager
     ///
     /*--cef()--*/
     shrewd_ptr<ProxyCookieManager> GetCookieManager();

    void AddFirstScriptOnNewDocument(const char* script_code);

    void SetUserAgentOverride(const char* user_agent, const char* app_version);

    void SetTouchEventEmulationEnabled(bool enabled, int maxTouchPoints);

    void SetGeolocationOverride(float latitude, float longitude, float accuracy);

    void SetEmulatedMedia(const char* media, shrewd_ptr<ProxyDictionaryValue> features);

    void ClearMediaFeatureOverrides();

    void EnableDeviceEmulation(shrewd_ptr<ProxyDictionaryValue> data);

    void DisableDeviceEmulation();

    void SetEmitTouchEventsForMouse(bool enabled, int configuration);

    void LoadExtension(const char* root_directory, shrewd_ptr<ProxyDictionaryValue> manifest);

    bool DidLoadExtension(const char* extension_id);

    bool HasExtension(const char* extension_id);

    char** GetExtensions();

    shrewd_ptr<ProxyExtension> GetExtension(const char* extension_id);

    bool IsBackgroundHost();

    shrewd_ptr<ProxyListValue> GetUserData();

    bool HasPreference(const char* name);

    shrewd_ptr<ProxyValue> GetPreference(const char* name);

    shrewd_ptr<ProxyDictionaryValue> GetAllPreferences(bool include_defaults);

    bool CanSetPreference(const char* name);

    bool SetPreference(const char* name, shrewd_ptr<ProxyValue> value);

public:
    PRIME_IMPLEMENT_REFCOUNTING(ProxyBrowser);
    AQUA_DECL_PUBLIC_ORIGIN;

private:
    void* _rawptr;
};
