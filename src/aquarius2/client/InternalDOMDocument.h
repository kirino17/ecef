#pragma once
#include "include/cef_app.h"
#include "include/cef_frame.h"
#include <functional>
#include "include/cef_waitable_event.h"

enum INTERNAL_DOM_COMMAND {
	IDC_GET_DOCUMENT = 1000,
	IDC_GET_TYPE,
	IDC_GET_ROOT,
	IDC_GET_BODY,
	IDC_GET_HEAD,
	IDC_GET_TITLE,
	IDC_GET_ELEMENT_BY_ID,
	IDC_GET_FOCUSED_NODE,
	IDC_HAS_SELECTION,
	IDC_GET_SELECTION_START_OFFSET,
	IDC_GET_SELECTION_END_OFFSET,
	IDC_GET_SELECTION_AS_MARKUP,
	IDC_GET_SELECTION_AS_TEXT,
	IDC_GET_BASE_URL,
	IDC_GET_COMPLETE_URL,
	IDC_FREE_DOCUMENT,
	IDC_QUERY_SELECTOR,
	IDC_QUERY_SELECTOR_ALL,
};

enum INTERNAL_NODE_COMMAND {
	INC_NODE_FREE = 8000,
	INC_NODE_GET_TYPE,
	INC_NODE_IS_TEXT,
	INC_NODE_IS_ELEMENT,
	INC_NODE_IS_EDITABLE,
	INC_NODE_IS_FORM_CONTROL_ELEMENT,
	INC_NODE_GET_FORM_CONTROL_ELEMENT_TYPE,
	INC_NODE_GET_NAME,
	INC_NODE_GET_VALUE,
	INC_NODE_SET_VALUE,
	INC_NODE_GET_AS_MARKUP,
	INC_NODE_GET_DOCUMENT,
	INC_NODE_GET_PARENT,
	INC_NODE_PREV_SIBLING,
	INC_NODE_NEXT_SIBLING,
	INC_NODE_HAS_CHILDREN,
	INC_NODE_GET_FIRST_CHILD,
	INC_NODE_GET_LAST_CHILD,
	INC_NODE_GET_ELEMENT_TAG_NAME,
	INC_NODE_HAS_ELEMENT_ATTRIBUTES,
	INC_NODE_HAS_ELEMENT_ATTRIBUTE,
	INC_NODE_GET_ELEMENT_ATTRIBUTE,
	INC_NODE_GET_ELEMENT_ATTRIBUTES,
	INC_NODE_SET_ELEMENT_ATTRIBUTE,
	INC_NODE_GET_ELEMENT_INNER_TEXT,
	INC_NODE_GET_ELEMENT_BOUNDS,
	INC_NODE_SEND_EVENT,
	INC_NODE_QUERY_SELECTOR,
	INC_NODE_QUERY_SELECTOR_ALL,
	INC_NODE_GET_CHILD_COUNT,
	INC_NODE_GET_SELECTOR
};

enum INTERNAL_RESULT_COMMAND {
	IRD_DOCUMENT_RESULT = 4000,
};

typedef std::function<void(CefRefPtr<CefFrame>,CefRefPtr<CefListValue>)> CallResult;


class InternalDOMNode;

class InternalDOMDocument : public CefBaseRefCounted {
public:
	InternalDOMDocument(CefRefPtr<CefFrame> frame, uint32_t pointer = 0);
	~InternalDOMDocument();

public:
	static CefRefPtr<InternalDOMDocument> GetDocument(CefRefPtr<CefFrame> frame);

public:
	static void OnDomMessageReceived(CefRefPtr<CefFrame> frame, CefRefPtr<CefListValue> arguments);

	static void DomSendMessage(CefRefPtr<CefFrame> frame,
		int command,
		CefRefPtr<CefListValue> params = nullptr,
		uint32_t pointer = 0,
		CallResult* callback = nullptr
	);

public:
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
	CefRefPtr<InternalDOMNode> GetDocument();

	///
	// Returns the BODY node of an HTML document.
	///
	/*--cef()--*/
	CefRefPtr<InternalDOMNode> GetBody();

	///
	// Returns the HEAD node of an HTML document.
	///
	/*--cef()--*/
	CefRefPtr<InternalDOMNode> GetHead();

	///
	// Returns the title of an HTML document.
	///
	/*--cef()--*/
	CefString GetTitle();

	///
	// Returns the document element with the specified ID value.
	///
	/*--cef()--*/
	CefRefPtr<InternalDOMNode> GetElementById(const CefString& id);

	///
	// Returns the node that currently has keyboard focus.
	///
	/*--cef()--*/
	CefRefPtr<InternalDOMNode> GetFocusedNode();

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
	CefString GetSelectionAsMarkup();

	///
	// Returns the contents of this selection as text.
	///
	/*--cef()--*/
	CefString GetSelectionAsText();

	///
	// Returns the base URL for the document.
	///
	/*--cef()--*/
	CefString GetBaseURL();

	///
	// Returns a complete URL based on the document base URL and the specified
	// partial URL.
	///
	/*--cef()--*/
	CefString GetCompleteURL(const CefString& partialURL);

	///
	// query selector
	///
	/*--cef()--*/
	CefRefPtr<InternalDOMNode> QuerySelector(const CefString& selectors);

	///
	// query selector all
	///
	/*--cef()--*/
	void** QuerySelectorAll(const CefString& selectors);

public:
	IMPLEMENT_REFCOUNTING(InternalDOMDocument);

private:
	CefRefPtr<CefFrame> _domFrame;
	uint32_t _domPointer;
	CefRefPtr<CefWaitableEvent> _domEvent;
};

class InternalDOMNode : public CefBaseRefCounted {
public:
	InternalDOMNode(CefRefPtr<CefFrame> frame, uint32_t pointer);
	~InternalDOMNode();

public:
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
	CefString GetFormControlElementType();

	///
	// Returns the name of this node.
	///
	/*--cef()--*/
	CefString GetName();

	///
	// Returns the value of this node.
	///
	/*--cef()--*/
	CefString GetValue();

	///
	// Set the value of this node. Returns true on success.
	///
	/*--cef()--*/
	bool SetValue(const CefString& value);

	///
	// Returns the contents of this node as markup.
	///
	/*--cef()--*/
	CefString GetAsMarkup();

	///
	// Returns the document associated with this node.
	///
	/*--cef()--*/
	CefRefPtr<InternalDOMDocument> GetDocument();

	///
	// Returns the parent node.
	///
	/*--cef()--*/
	CefRefPtr<InternalDOMNode> GetParent();

	///
	// Returns the previous sibling node.
	///
	/*--cef()--*/
	CefRefPtr<InternalDOMNode> GetPreviousSibling();

	///
	// Returns the next sibling node.
	///
	/*--cef()--*/
	CefRefPtr<InternalDOMNode> GetNextSibling();

	///
	// Returns true if this node has child nodes.
	///
	/*--cef()--*/
	bool HasChildren();

	///
	// Return the first child node.
	///
	/*--cef()--*/
	CefRefPtr<InternalDOMNode> GetFirstChild();

	///
	// Returns the last child node.
	///
	/*--cef()--*/
	CefRefPtr<InternalDOMNode> GetLastChild();

	// The following methods are valid only for element nodes.

	///
	// Returns the tag name of this element.
	///
	/*--cef()--*/
	CefString GetElementTagName();

	///
	// Returns true if this element has attributes.
	///
	/*--cef()--*/
	bool HasElementAttributes();

	///
	// Returns true if this element has an attribute named |attrName|.
	///
	/*--cef()--*/
	bool HasElementAttribute(const CefString& attrName);

	///
	// Returns the element attribute named |attrName|.
	///
	/*--cef()--*/
	CefString GetElementAttribute(const CefString& attrName);

	///
	// Returns a map of all element attributes.
	///
	/*--cef()--*/
	void GetElementAttributes(CefRefPtr<CefDictionaryValue>& attrMap);

	///
	// Set the value for the element attribute named |attrName|. Returns true on
	// success.
	///
	/*--cef()--*/
	bool SetElementAttribute(const CefString& attrName,
		const CefString& value);

	///
	// Returns the inner text of the element.
	///
	/*--cef()--*/
	CefString GetElementInnerText();

	///
	// Returns the bounds of the element.
	///
	/*--cef()--*/
	int** GetElementBounds();

	void SendEvent(const CefString& name, CefRefPtr<CefListValue> arguments);

	CefRefPtr<InternalDOMNode> QuerySelector(const CefString& selectors);

	void** QuerySelectorAll(const CefString& selectors);

	int GetChildCount();

	char* GetSelector();

public:
	IMPLEMENT_REFCOUNTING(InternalDOMNode);

private:
	CefRefPtr<CefFrame> _domFrame;
	uint32_t _domPointer;
};