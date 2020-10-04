#pragma once
#include "../def/def.h"
#include "../proxy/ProxyValue.h"

class ProxyBrowser;
class ProxyRequest;

class AQUADLL ProxyFrame : public refcounted {
public:
	ProxyFrame(void* ptr = NULL);
	~ProxyFrame();

public:
    ///
    // True if this object is currently attached to a valid frame.
    ///
    /*--cef()--*/
     bool IsValid();

    ///
    // Execute undo in this frame.
    ///
    /*--cef()--*/
     void Undo();

    ///
    // Execute redo in this frame.
    ///
    /*--cef()--*/
     void Redo();

    ///
    // Execute cut in this frame.
    ///
    /*--cef()--*/
     void Cut();

    ///
    // Execute copy in this frame.
    ///
    /*--cef()--*/
     void Copy();

    ///
    // Execute paste in this frame.
    ///
    /*--cef()--*/
     void Paste();

    ///
    // Execute delete in this frame.
    ///
    /*--cef(capi_name=del)--*/
     void Delete();

    ///
    // Execute select all in this frame.
    ///
    /*--cef()--*/
     void SelectAll();

    ///
    // Save this frame's HTML source to a temporary file and open it in the
    // default text viewing application. This method can only be called from the
    // browser process.
    ///
    /*--cef()--*/
     void ViewSource();

    ///
    // Retrieve this frame's HTML source as a string sent to the specified
    // visitor.
    ///
    /*--cef()--*/
     char* GetSource();

    ///
    // Retrieve this frame's display text as a string sent to the specified
    // visitor.
    ///
    /*--cef()--*/
     char* GetText();

    ///
    // Load the request represented by the |request| object.
    //
    // WARNING: This method will fail with "bad IPC message" reason
    // INVALID_INITIATOR_ORIGIN (213) unless you first navigate to the
    // request origin using some other mechanism (LoadURL, link click, etc).
    ///
    /*--cef()--*/
     void LoadRequest(shrewd_ptr<ProxyRequest> request);

    ///
    // Load the specified |url|.
    ///
    /*--cef()--*/
     void LoadURL(const char* url);

    ///
    // Execute a string of JavaScript code in this frame. The |script_url|
    // parameter is the URL where the script in question can be found, if any.
    // The renderer may request this URL to show the developer the source of the
    // error.  The |start_line| parameter is the base line number to use for error
    // reporting.
    ///
    /*--cef(optional_param=script_url)--*/
     void ExecuteJavaScript(const char* code,
        const char* script_url,
        int start_line);

    ///
    // Execute a string of JavaScript code in this frame. The |script_url|
    // parameter is the URL where the script in question can be found, if any.
    // The renderer may request this URL to show the developer the source of the
    // error.  The |start_line| parameter is the base line number to use for error
    // reporting.
    ///
    /*--cef(optional_param=script_url)--*/
     shrewd_ptr<ProxyValue> ExecuteJavaScriptEx(const char* code,
         const char* script_url,
         int start_line, char** exception);

    ///
    // Returns true if this is the main (top-level) frame.
    ///
    /*--cef()--*/
     bool IsMain();

    ///
    // Returns true if this is the focused frame.
    ///
    /*--cef()--*/
     bool IsFocused();

    ///
    // Returns the name for this frame. If the frame has an assigned name (for
    // example, set via the iframe "name" attribute) then that value will be
    // returned. Otherwise a unique name will be constructed based on the frame
    // parent hierarchy. The main (top-level) frame will always have an empty name
    // value.
    ///
    /*--cef()--*/
     char* GetName();

    ///
    // Returns the parent of this frame or NULL if this is the main (top-level)
    // frame.
    ///
    /*--cef()--*/
     shrewd_ptr<ProxyFrame> GetParent();

    ///
    // Returns the URL currently loaded in this frame.
    ///
    /*--cef()--*/
     char* GetURL();

    ///
    // Returns the browser that this frame belongs to.
    ///
    /*--cef()--*/
     shrewd_ptr<ProxyBrowser> GetBrowser();

     ///
    // Returns the globally unique identifier for this frame or < 0 if the
    // underlying frame does not yet exist.
    ///
    /*--cef()--*/
     __int64 GetIdentifier();

public:
	PRIME_IMPLEMENT_REFCOUNTING(ProxyFrame);
    AQUA_DECL_PUBLIC_ORIGIN;
private:
	void* _rawptr;
};