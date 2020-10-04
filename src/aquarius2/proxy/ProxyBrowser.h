#pragma once
#include "../def/def.h"
#include "ProxyValue.h"

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
    // Returns the browser host object. This method can only be called in the
    // browser process.
    ///
    /*--cef()--*/
    shrewd_ptr<ProxyBrowserHost> GetHost();

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
    // Returns true if this object is pointing to the same handle as |that|
    // object.
    ///
    /*--cef()--*/
     bool IsSame(shrewd_ptr<ProxyBrowser> that);

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

public:
    PRIME_IMPLEMENT_REFCOUNTING(ProxyBrowser);
    AQUA_DECL_PUBLIC_ORIGIN;
private:
    void* _rawptr;
};
