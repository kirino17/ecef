#include "ProxyDOMDocument.h"
#include "../client/InternalDOMDocument.h"
#include "ProxyDOMNode.h"
#include <atlconv.h>

AQUA_PROXY_AUTO_CONSTRUCTOR(ProxyDOMDocument, InternalDOMDocument);

// is valid
bool ProxyDOMDocument::IsValid() {
    return _rawptr != nullptr && FORWARD(InternalDOMDocument)->IsValid();
}


///
// Returns the type for this node.
///
/*--cef(default_retval=DOM_NODE_TYPE_UNSUPPORTED)--*/
int ProxyDOMDocument::GetType() {
	ASSERTQ(0);
	return FORWARD(InternalDOMDocument)->GetType();
}

///
 // Returns the root document node.
 ///
 /*--cef()--*/
shrewd_ptr<ProxyDOMNode> ProxyDOMDocument::GetDocument() {
    ASSERTQ(NULL);
    CefRefPtr<InternalDOMNode> node = FORWARD(InternalDOMDocument)->GetDocument();
    if (!node) {
        return nullptr;
    }
    return new ProxyDOMNode(node);
}

///
// Returns the BODY node of an HTML document.
///
/*--cef()--*/
shrewd_ptr<ProxyDOMNode> ProxyDOMDocument::GetBody() {
    ASSERTQ(NULL);
    CefRefPtr<InternalDOMNode> node = FORWARD(InternalDOMDocument)->GetBody();
    if (!node) {
        return nullptr;
    }
    return new ProxyDOMNode(node);
}

///
// Returns the HEAD node of an HTML document.
///
/*--cef()--*/
shrewd_ptr<ProxyDOMNode> ProxyDOMDocument::GetHead() {
    ASSERTQ(NULL);
    CefRefPtr<InternalDOMNode> node = FORWARD(InternalDOMDocument)->GetHead();
    if (!node) {
        return nullptr;
    }
    return new ProxyDOMNode(node);
}

///
// Returns the title of an HTML document.
///
/*--cef()--*/
char* ProxyDOMDocument::GetTitle() {
    ASSERTQ(NULL);
    CefString string = FORWARD(InternalDOMDocument)->GetTitle();
    if (string.empty()) {
        return nullptr;
    }
    return ToAnsi(string.c_str(),string.length());
}

///
// Returns the document element with the specified ID value.
///
/*--cef()--*/
shrewd_ptr<ProxyDOMNode> ProxyDOMDocument::GetElementById(const char* id) {
    ASSERTQ(NULL);
    if (!id) {
        return nullptr;
    }
    CefRefPtr<InternalDOMNode> node = FORWARD(InternalDOMDocument)->GetElementById(id);
    if (!node) {
        return nullptr;
    }
    return new ProxyDOMNode(node);
}

///
// Returns the node that currently has keyboard focus.
///
/*--cef()--*/
shrewd_ptr<ProxyDOMNode> ProxyDOMDocument::GetFocusedNode() {
    ASSERTQ(NULL);
    CefRefPtr<InternalDOMNode> node = FORWARD(InternalDOMDocument)->GetFocusedNode();
    if (!node) {
        return nullptr;
    }
    return new ProxyDOMNode(node);
}

///
// Returns true if a portion of the document is selected.
///
/*--cef()--*/
bool ProxyDOMDocument::HasSelection() {
    ASSERTQ(false);
    return FORWARD(InternalDOMDocument)->HasSelection();
}

///
// Returns the selection offset within the start node.
///
/*--cef()--*/
int ProxyDOMDocument::GetSelectionStartOffset() {
    ASSERTQ(0);
    return FORWARD(InternalDOMDocument)->GetSelectionStartOffset();
}

///
// Returns the selection offset within the end node.
///
/*--cef()--*/
int ProxyDOMDocument::GetSelectionEndOffset() {
    ASSERTQ(0);
    return FORWARD(InternalDOMDocument)->GetSelectionEndOffset();
}

///
// Returns the contents of this selection as markup.
///
/*--cef()--*/
char* ProxyDOMDocument::GetSelectionAsMarkup() {
    ASSERTQ(NULL);
    CefString string = FORWARD(InternalDOMDocument)->GetSelectionAsMarkup();
    if (string.empty()) {
        return nullptr;
    }
    return ToAnsi(string.c_str(), string.length());
}

///
// Returns the contents of this selection as text.
///
/*--cef()--*/
char* ProxyDOMDocument::GetSelectionAsText() {
    ASSERTQ(NULL);
    CefString string = FORWARD(InternalDOMDocument)->GetSelectionAsText();
    if (string.empty()) {
        return nullptr;
    }
    return ToAnsi(string.c_str(), string.length());
}

///
// Returns the base URL for the document.
///
/*--cef()--*/
char* ProxyDOMDocument::GetBaseURL() {
    ASSERTQ(NULL);
    CefString string = FORWARD(InternalDOMDocument)->GetBaseURL();
    if (string.empty()) {
        return nullptr;
    }
    return ToAnsi(string.c_str(), string.length());
}

///
// Returns a complete URL based on the document base URL and the specified
// partial URL.
///
/*--cef()--*/
char* ProxyDOMDocument::GetCompleteURL(const char* partialURL) {
    ASSERTQ(NULL);
    USES_CONVERSION;
    if (!partialURL) {
        return nullptr;
    }
    CefString string = FORWARD(InternalDOMDocument)->GetCompleteURL(A2W(partialURL));
    if (string.empty()) {
        return nullptr;
    }
    return ToAnsi(string.c_str(), string.length());
}

shrewd_ptr<ProxyDOMNode> ProxyDOMDocument::QuerySelector(const char* selectors) {
    ASSERTQ(nullptr);
    USES_CONVERSION;
    CefRefPtr<InternalDOMNode> node = nullptr;
    if (!selectors) {
        return nullptr;
    }
    node = FORWARD(InternalDOMDocument)->QuerySelector(A2W(selectors));
    if (!node) {
        return nullptr;
    }
    return new ProxyDOMNode(node);
}

shrewd_ptr<ProxyDOMNode>** ProxyDOMDocument::QuerySelectorAll(const char* selectors) {
    ASSERTQ(nullptr);
    USES_CONVERSION;
    if (!selectors) {
        return nullptr;
    }
    void** result = FORWARD(InternalDOMDocument)->QuerySelectorAll(A2W(selectors));
    if (!result) {
        return nullptr;
    }
    return (shrewd_ptr<ProxyDOMNode>**)result;
}