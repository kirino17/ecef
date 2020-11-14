#pragma once
#include "../def/def.h"

class ProxyDOMNode;

class AQUADLL ProxyDOMDocument : public refcounted {
public:
	ProxyDOMDocument(void* ptr);
	~ProxyDOMDocument();

public:
    // is valid
    bool IsValid();

	///
	// Returns the type for this node.
	///
	/*--cef(default_retval=DOM_NODE_TYPE_UNSUPPORTED)--*/
	int GetType();

    ///
    // Returns the root document node.
    ///
    /*--cef()--*/
    shrewd_ptr<ProxyDOMNode> GetDocument();

    ///
    // Returns the BODY node of an HTML document.
    ///
    /*--cef()--*/
    shrewd_ptr<ProxyDOMNode> GetBody();

    ///
    // Returns the HEAD node of an HTML document.
    ///
    /*--cef()--*/
    shrewd_ptr<ProxyDOMNode> GetHead();

    ///
    // Returns the title of an HTML document.
    ///
    /*--cef()--*/
    char* GetTitle();

    ///
    // Returns the document element with the specified ID value.
    ///
    /*--cef()--*/
    shrewd_ptr<ProxyDOMNode> GetElementById(const char* id);

    ///
    // Returns the node that currently has keyboard focus.
    ///
    /*--cef()--*/
    shrewd_ptr<ProxyDOMNode> GetFocusedNode();

    ///
    // Returns true if a portion of the document is selected.
    ///
    /*--cef()--*/
    bool HasSelection();

    ///
    // Returns the selection offset within the start node.
    ///
    /*--cef()--*/
    int GetSelectionStartOffset();

    ///
    // Returns the selection offset within the end node.
    ///
    /*--cef()--*/
    int GetSelectionEndOffset();

    ///
    // Returns the contents of this selection as markup.
    ///
    /*--cef()--*/
    char* GetSelectionAsMarkup();

    ///
    // Returns the contents of this selection as text.
    ///
    /*--cef()--*/
    char* GetSelectionAsText();

    ///
    // Returns the base URL for the document.
    ///
    /*--cef()--*/
    char* GetBaseURL();

    ///
    // Returns a complete URL based on the document base URL and the specified
    // partial URL.
    ///
    /*--cef()--*/
    char* GetCompleteURL(const char* partialURL);

    shrewd_ptr<ProxyDOMNode> QuerySelector(const char* selectors);

    shrewd_ptr<ProxyDOMNode>** QuerySelectorAll(const char* selectors);

public:
	PRIME_IMPLEMENT_REFCOUNTING(ProxyDOMDocument);
	AQUA_DECL_PUBLIC_ORIGIN;

private:
	void* _rawptr;
};