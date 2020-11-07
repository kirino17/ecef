#pragma once
#include "../def/def.h"
#include "ProxyDictionaryValue.h"
#include "ProxyListValue.h"

class ProxyDOMDocument;

class AQUADLL ProxyDOMNode : public refcounted {
public:
	ProxyDOMNode(void* ptr);
	~ProxyDOMNode();

public:
    // is valid
    bool IsValid();

    ///
    // Returns the type for this node.
    ///
    /*--cef(default_retval=DOM_NODE_TYPE_UNSUPPORTED)--*/
    int GetType();

    ///
    // Returns true if this is a text node.
    ///
    /*--cef()--*/
    bool IsText();

    ///
    // Returns true if this is an element node.
    ///
    /*--cef()--*/
    bool IsElement();

    ///
    // Returns true if this is an editable node.
    ///
    /*--cef()--*/
    bool IsEditable();

    ///
    // Returns true if this is a form control element node.
    ///
    /*--cef()--*/
    bool IsFormControlElement();

    ///
    // Returns the type of this form control element node.
    ///
    /*--cef()--*/
    char* GetFormControlElementType();

    ///
    // Returns the name of this node.
    ///
    /*--cef()--*/
    char* GetName();

    ///
    // Returns the value of this node.
    ///
    /*--cef()--*/
    char* GetValue();

    ///
    // Set the value of this node. Returns true on success.
    ///
    /*--cef()--*/
    bool SetValue(const char* value);

    ///
    // Returns the contents of this node as markup.
    ///
    /*--cef()--*/
    char* GetAsMarkup();

    ///
    // Returns the document associated with this node.
    ///
    /*--cef()--*/
    shrewd_ptr<ProxyDOMDocument> GetDocument();

    ///
    // Returns the parent node.
    ///
    /*--cef()--*/
    shrewd_ptr<ProxyDOMNode> GetParent();

    ///
    // Returns the previous sibling node.
    ///
    /*--cef()--*/
    shrewd_ptr<ProxyDOMNode> GetPreviousSibling();

    ///
    // Returns the next sibling node.
    ///
    /*--cef()--*/
    shrewd_ptr<ProxyDOMNode> GetNextSibling();

    ///
    // Returns true if this node has child nodes.
    ///
    /*--cef()--*/
    bool HasChildren();

    ///
    // Return the first child node.
    ///
    /*--cef()--*/
    shrewd_ptr<ProxyDOMNode> GetFirstChild();

    ///
    // Returns the last child node.
    ///
    /*--cef()--*/
    shrewd_ptr<ProxyDOMNode> GetLastChild();

    // The following methods are valid only for element nodes.

    ///
    // Returns the tag name of this element.
    ///
    /*--cef()--*/
    char* GetElementTagName();

    ///
    // Returns true if this element has attributes.
    ///
    /*--cef()--*/
    bool HasElementAttributes();

    ///
    // Returns true if this element has an attribute named |attrName|.
    ///
    /*--cef()--*/
    bool HasElementAttribute(const char* attrName);

    ///
    // Returns the element attribute named |attrName|.
    ///
    /*--cef()--*/
    char* GetElementAttribute(const char* attrName);

    ///
    // Returns a map of all element attributes.
    ///
    /*--cef()--*/
    shrewd_ptr<ProxyDictionaryValue> GetElementAttributes();

    ///
    // Set the value for the element attribute named |attrName|. Returns true on
    // success.
    ///
    /*--cef()--*/
    bool SetElementAttribute(const char* attrName, const char* value);

    ///
    // Returns the inner text of the element.
    ///
    /*--cef()--*/
    char* GetElementInnerText();

    ///
    // Returns the bounds of the element.
    ///
    /*--cef()--*/
    int** GetElementBounds();

    ///
    // send event.
    ///
    /*--cef()--*/
    void SendEvent(const char* evt_name, EPL_ALL arguments);

    ///
    // query selector
    ///
    /*--cef()--*/
    shrewd_ptr<ProxyDOMNode> QuerySelector(const char* selectors);

    ///
    // query selector all
    ///
    /*--cef()--*/
    shrewd_ptr<ProxyDOMNode>** QuerySelectorAll(const char* selectors);

    ///
    // get child count
    ///
    /*--cef()--*/
    int GetChildCount();

    ///
    // get selectors
    ///
    /*--cef()--*/
    char* GetSelector();

public:
	PRIME_IMPLEMENT_REFCOUNTING(ProxyDOMNode);
	AQUA_DECL_PUBLIC_ORIGIN;

private:
	void* _rawptr;
};