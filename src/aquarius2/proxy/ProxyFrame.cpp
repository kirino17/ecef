#include "ProxyFrame.h"
#include "include/cef_frame.h"
#include "include/cef_browser.h"
#include <atlconv.h>
#include <string>
#include "ProxyBrowser.h"
#include "ProxyRequest.h"
#include "../client/InternalStringVisitor.h"
#include "../client/InternalCalculationVisitor.h"
#include "include/cef_app.h"
#include "../def/internalDef.h"

ProxyFrame::ProxyFrame(void* ptr):_rawptr(ptr)
{
    if (_rawptr) {
        FORWARD(CefFrame)->AddRef();
    }
}

ProxyFrame::~ProxyFrame() {
    if (_rawptr) {
        FORWARD(CefFrame)->Release();
        _rawptr = NULL;
    }
}

///
// True if this object is currently attached to a valid frame.
///
/*--cef()--*/
bool ProxyFrame::IsValid() {
    ASSERTQ(false);
    return FORWARD(CefFrame)->IsValid();
}

///
// Execute undo in this frame.
///
/*--cef()--*/
void ProxyFrame::Undo() {
    ASSERTN();
    FORWARD(CefFrame)->Undo();
}

///
// Execute redo in this frame.
///
/*--cef()--*/
void ProxyFrame::Redo() {
    ASSERTN();
    FORWARD(CefFrame)->Redo();
}

///
// Execute cut in this frame.
///
/*--cef()--*/
void ProxyFrame::Cut() {
    ASSERTN();
    FORWARD(CefFrame)->Cut();
}

///
// Execute copy in this frame.
///
/*--cef()--*/
void ProxyFrame::Copy() {
    ASSERTN();
    FORWARD(CefFrame)->Copy();
}

///
// Execute paste in this frame.
///
/*--cef()--*/
void ProxyFrame::Paste() {
    ASSERTN();
    FORWARD(CefFrame)->Paste();
}

///
// Execute delete in this frame.
///
/*--cef(capi_name=del)--*/
void ProxyFrame::Delete() {
    ASSERTN();
    FORWARD(CefFrame)->Delete();
}

///
// Execute select all in this frame.
///
/*--cef()--*/
void ProxyFrame::SelectAll() {
    ASSERTN();
    FORWARD(CefFrame)->SelectAll();
}

///
// Save this frame's HTML source to a temporary file and open it in the
// default text viewing application. This method can only be called from the
// browser process.
///
/*--cef()--*/
void ProxyFrame::ViewSource() {
    ASSERTN();
    FORWARD(CefFrame)->ViewSource();
}

/////
//// Retrieve this frame's HTML source as a string sent to the specified
//// visitor.
/////
///*--cef()--*/
char* ProxyFrame::GetSource() {
    ASSERTQ(NULL);
    assert(NewBuffer);
    char* stringBuffer = NULL;
    {
        CefRefPtr<CefWaitableEvent> waitable = CefWaitableEvent::CreateWaitableEvent(false, false);
        CefRefPtr<InternalStringVisitor> stringVisitor = new InternalStringVisitor(waitable, &stringBuffer);
        
        FORWARD(CefFrame)->GetSource(stringVisitor);
        
        stringVisitor->AddRef();
        WaitAwaking(waitable);
        stringVisitor->Release();
    }
    return stringBuffer;
}

/////
//// Retrieve this frame's display text as a string sent to the specified
//// visitor.
/////
///*--cef()--*/
char* ProxyFrame::GetText() {
    ASSERTQ(NULL);
    assert(NewBuffer);
    char* stringBuffer = NULL;
    {
        CefRefPtr<CefWaitableEvent> waitable = CefWaitableEvent::CreateWaitableEvent(false, false);
        CefRefPtr<InternalStringVisitor> stringVisitor = new InternalStringVisitor(waitable, &stringBuffer);
        
        FORWARD(CefFrame)->GetText(stringVisitor);

        stringVisitor->AddRef();
        WaitAwaking(waitable);
        stringVisitor->Release();
    }
    return stringBuffer;
}

///
// Load the request represented by the |request| object.
//
// WARNING: This method will fail with "bad IPC message" reason
// INVALID_INITIATOR_ORIGIN (213) unless you first navigate to the
// request origin using some other mechanism (LoadURL, link click, etc).
///
/*--cef()--*/
void ProxyFrame::LoadRequest(shrewd_ptr<ProxyRequest> request) {
    ASSERTN();
    if (!request || !ORIGIN(CefRequest, request)) {
        return;
    }
    FORWARD(CefFrame)->LoadRequest(ORIGIN(CefRequest, request));
}

///
// Load the specified |url|.
///
/*--cef()--*/
void ProxyFrame::LoadURL(const char* url) {
    ASSERTN();
    if (!url) return;
    USES_CONVERSION;
    FORWARD(CefFrame)->LoadURL(A2W(url));
}

///
// Execute a string of JavaScript code in this frame. The |script_url|
// parameter is the URL where the script in question can be found, if any.
// The renderer may request this URL to show the developer the source of the
// error.  The |start_line| parameter is the base line number to use for error
// reporting.
///
/*--cef(optional_param=script_url)--*/
void ProxyFrame::ExecuteJavaScript(const char* code,
    const char* script_url,
    int start_line) {
    ASSERTN();
    assert(NewBuffer && DeleteBuffer);

    if (!code) return;
    size_t length = strlen(code);
    if (length <= 0x200) {
        USES_CONVERSION;
        FORWARD(CefFrame)->ExecuteJavaScript(A2W(code), script_url ? A2W(script_url) : nullptr, start_line);
    }
    else {
        wchar_t* codeBuffer = ToUnicode(code, length);
        USES_CONVERSION;
        if (!codeBuffer) {
            return;
        }
        FORWARD(CefFrame)->ExecuteJavaScript(codeBuffer, script_url ? A2W(script_url) : nullptr, start_line);
        DeleteBuffer(codeBuffer);
    }
}

///
// Execute a string of JavaScript code in this frame. The |script_url|
// parameter is the URL where the script in question can be found, if any.
// The renderer may request this URL to show the developer the source of the
// error.  The |start_line| parameter is the base line number to use for error
// reporting.
///
/*--cef(optional_param=script_url)--*/
shrewd_ptr<ProxyValue> ProxyFrame::ExecuteJavaScriptEx(const char* code,
    const char* script_url,
    int start_line, char** exception) {
    ASSERTQ(NULL);
    if (!code) {
        return NULL;
    }

    if (CefCurrentlyOn(TID_FILE) || CefCurrentlyOn(TID_UI) || CefCurrentlyOn(TID_IO) || CefCurrentlyOn(TID_RENDERER)) {
        return NULL;
    }

    CefString scriptUrl;
    CefString scriptCode;
    size_t length = 0;
    if ((length=strlen(code)) <= 0x200) {
        USES_CONVERSION;
        scriptCode = A2W(code);
    }
    else {
        wchar_t* buffer = ToUnicode(code, length);
        scriptCode = buffer;
        DeleteBuffer(buffer);
    }
    if (!script_url) {
        USES_CONVERSION;
        scriptUrl = A2W(script_url);
    }
    CefRefPtr<CefProcessMessage> message = CefProcessMessage::Create(L"IPC_V8_CALCULATE");
    CefRefPtr<CefListValue> arguments = message->GetArgumentList();
    CefRefPtr<CefFrame> self = FORWARD(CefFrame);
    CefRefPtr<InternalCalculationVisitior> calculation = new InternalCalculationVisitior();
    CefRefPtr<CefValue> result = nullptr;
    CefRefPtr<CefValue> exp = nullptr;

    arguments->SetSize(5);
    arguments->SetInt(0, self->GetIdentifier());
    arguments->SetInt(1, (int)calculation.get());
    arguments->SetString(2, scriptCode);
    arguments->SetString(3, scriptUrl);
    arguments->SetInt(4, start_line);
    
    self->SendProcessMessage(PID_RENDERER, message);

    calculation->AddRef();
    WaitAwaking(calculation->GetWaitable());
    calculation->Release();

    result = calculation->GetResult();
    exp = calculation->GetException();

    if (exp) {
        CefString string = exp->GetString();
        *exception = ToAnsi(string.c_str(), string.length());
    }

    if (result) {
        return new ProxyValue(result);
    }

    return NULL;
}

///
// Returns true if this is the main (top-level) frame.
///
/*--cef()--*/
bool ProxyFrame::IsMain() {
    ASSERTQ(false);
    return FORWARD(CefFrame)->IsMain();
}

///
// Returns true if this is the focused frame.
///
/*--cef()--*/
bool ProxyFrame::IsFocused() {
    ASSERTQ(false);
    return FORWARD(CefFrame)->IsFocused();
}

///
// Returns the name for this frame. If the frame has an assigned name (for
// example, set via the iframe "name" attribute) then that value will be
// returned. Otherwise a unique name will be constructed based on the frame
// parent hierarchy. The main (top-level) frame will always have an empty name
// value.
///
/*--cef()--*/
char* ProxyFrame::GetName() {
    ASSERTQ(NULL);
    assert(NewBuffer);
    CefString string = FORWARD(CefFrame)->GetName();
    return ToAnsi(string.c_str(), string.length());
}

///
// Returns the parent of this frame or NULL if this is the main (top-level)
// frame.
///
/*--cef()--*/
shrewd_ptr<ProxyFrame> ProxyFrame::GetParent() {
    ASSERTQ(NULL);
    CefRefPtr<CefFrame> parent = FORWARD(CefFrame)->GetParent();
    if (!parent) {
        return NULL;
    }
    return new ProxyFrame(parent.get());
}

///
// Returns the URL currently loaded in this frame.
///
/*--cef()--*/
char* ProxyFrame::GetURL() {
    ASSERTQ(NULL);
    assert(NewBuffer);
    CefString string = FORWARD(CefFrame)->GetURL();
    return ToAnsi(string.c_str(), string.length());
}

///
// Returns the browser that this frame belongs to.
///
/*--cef()--*/
shrewd_ptr<ProxyBrowser> ProxyFrame::GetBrowser() {
    ASSERTQ(NULL);
    CefRefPtr<CefBrowser> browser = FORWARD(CefFrame)->GetBrowser();
    if (!browser) {
        return NULL;
    }
    return new ProxyBrowser(browser);
}

///
// Returns the globally unique identifier for this frame or < 0 if the
// underlying frame does not yet exist.
///
/*--cef()--*/
__int64 ProxyFrame::GetIdentifier() {
    ASSERTQ(0);
    return FORWARD(CefFrame)->GetIdentifier();
}

///
// Create a new URL request that will be treated as originating from this
// frame and the associated browser. This request may be intercepted by the
// client via CefResourceRequestHandler or CefSchemeHandlerFactory. Use
// CefURLRequest::Create instead if you do not want the request to have this
// association, in which case it may be handled differently (see documentation
// on that method). Requests may originate from both the browser process and
// the render process.
//
// For requests originating from the browser process:
//   - POST data may only contain a single element of type PDE_TYPE_FILE or
//     PDE_TYPE_BYTES.
// For requests originating from the render process:
//   - POST data may only contain a single element of type PDE_TYPE_BYTES.
//   - If the response contains Content-Disposition or Mime-Type header values
//     that would not normally be rendered then the response may receive
//     special handling inside the browser (for example, via the file download
//     code path instead of the URL request code path).
//
// The |request| object will be marked as read-only after calling this method.
///
/*--cef()--*/
//shrewd_ptr<ProxyURLRequest> ProxyFrame::CreateURLRequest(
//    shrewd_ptr<ProxyRequest> request,
//    shrewd_ptr<ProxyURLRequestClient> client) {
//    ASSERTQ(NULL);
//    if (!request && !client) {
//        return NULL;
//    }
//    if (!ORIGIN(CefRequest, freqest) && !ORIGIN(ProxyURLRequestClient, client)) {
//        return NULL;
//    }
//}