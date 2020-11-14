#include "ProxyDOMNode.h"
#include "../client/InternalDOMDocument.h"
#include "ProxyDOMDocument.h"
#include <atlconv.h>

AQUA_PROXY_AUTO_CONSTRUCTOR(ProxyDOMNode, InternalDOMNode);

// is valid
bool ProxyDOMNode::IsValid() {
	return _rawptr != nullptr && FORWARD(InternalDOMNode)->IsValid();
}

///
// Returns the type for this node.
///
/*--cef(default_retval=DOM_NODE_TYPE_UNSUPPORTED)--*/
int ProxyDOMNode::GetType(){
	ASSERTQ(0);
	return FORWARD(InternalDOMNode)->GetType();
}

///
// Returns true if this is a text node.
///
/*--cef()--*/
bool ProxyDOMNode::IsText(){
	ASSERTQ(false);
	return FORWARD(InternalDOMNode)->IsText();
}

///
// Returns true if this is an element node.
///
/*--cef()--*/
bool ProxyDOMNode::IsElement(){
	ASSERTQ(false);
	return FORWARD(InternalDOMNode)->IsElement();
}

///
// Returns true if this is an editable node.
///
/*--cef()--*/
bool ProxyDOMNode::IsEditable(){
	ASSERTQ(false);
	return FORWARD(InternalDOMNode)->IsElement();
}

///
// Returns true if this is a form control element node.
///
/*--cef()--*/
bool ProxyDOMNode::IsFormControlElement(){
	ASSERTQ(false);
	return FORWARD(InternalDOMNode)->IsFormControlElement();
}

///
// Returns the type of this form control element node.
///
/*--cef()--*/
char* ProxyDOMNode::GetFormControlElementType(){
	ASSERTQ(NULL);
	CefString string = FORWARD(InternalDOMNode)->GetFormControlElementType();
	if (string.empty()) {
		return NULL;
	}
	return ToAnsi(string.c_str(), string.length());
}

///
// Returns the name of this node.
///
/*--cef()--*/
char* ProxyDOMNode::GetName(){
	ASSERTQ(NULL);
	CefString string = FORWARD(InternalDOMNode)->GetName();
	if (string.empty()) {
		return NULL;
	}
	return ToAnsi(string.c_str(), string.length());
}

///
// Returns the value of this node.
///
/*--cef()--*/
char* ProxyDOMNode::GetValue(){
	ASSERTQ(NULL);
	CefString string = FORWARD(InternalDOMNode)->GetValue();
	if (string.empty()) {
		return NULL;
	}
	return ToAnsi(string.c_str(), string.length());
}

///
// Set the value of this node. Returns true on success.
///
/*--cef()--*/
bool ProxyDOMNode::SetValue(const char* value){
	ASSERTQ(NULL);
	if (!value) {
		return false;
	}
	USES_CONVERSION;
	size_t length = strlen(value);
	if (length <= 0x200) {
		return FORWARD(InternalDOMNode)->SetValue(A2W(value));
	}
	wchar_t* buffer = ToUnicode(value, length);
	bool result = FORWARD(InternalDOMNode)->SetValue(buffer);
	DeleteBuffer(buffer);
	return result;
}

///
// Returns the contents of this node as markup.
///
/*--cef()--*/
char* ProxyDOMNode::GetAsMarkup(){
	ASSERTQ(NULL);
	CefString string = FORWARD(InternalDOMNode)->GetAsMarkup();
	if (string.empty()) {
		return NULL;
	}
	return ToAnsi(string.c_str(), string.length());
}

///
// Returns the document associated with this node.
///
/*--cef()--*/
shrewd_ptr<ProxyDOMDocument> ProxyDOMNode::GetDocument(){
	ASSERTQ(NULL);
	CefRefPtr<InternalDOMDocument> document = FORWARD(InternalDOMNode)->GetDocument();
	if (!document) {
		return nullptr;
	}
	return new ProxyDOMDocument(document);
}

///
// Returns the parent node.
///
/*--cef()--*/
shrewd_ptr<ProxyDOMNode> ProxyDOMNode::GetParent(){
	ASSERTQ(NULL);
	CefRefPtr<InternalDOMNode> node = FORWARD(InternalDOMNode)->GetParent();
	if (!node) {
		return nullptr;
	}
	return new ProxyDOMNode(node);
}

///
// Returns the previous sibling node.
///
/*--cef()--*/
shrewd_ptr<ProxyDOMNode> ProxyDOMNode::GetPreviousSibling(){
	ASSERTQ(NULL);
	CefRefPtr<InternalDOMNode> node = FORWARD(InternalDOMNode)->GetPreviousSibling();
	if (!node) {
		return nullptr;
	}
	return new ProxyDOMNode(node);
}

///
// Returns the next sibling node.
///
/*--cef()--*/
shrewd_ptr<ProxyDOMNode> ProxyDOMNode::GetNextSibling(){
	ASSERTQ(NULL);
	CefRefPtr<InternalDOMNode> node = FORWARD(InternalDOMNode)->GetNextSibling();
	if (!node) {
		return nullptr;
	}
	return new ProxyDOMNode(node);
}

///
// Returns true if this node has child nodes.
///
/*--cef()--*/
bool ProxyDOMNode::HasChildren(){
	ASSERTQ(false);
	return FORWARD(InternalDOMNode)->HasChildren();
}

///
// Return the first child node.
///
/*--cef()--*/
shrewd_ptr<ProxyDOMNode> ProxyDOMNode::GetFirstChild(){
	ASSERTQ(NULL);
	CefRefPtr<InternalDOMNode> node = FORWARD(InternalDOMNode)->GetFirstChild();
	if (!node) {
		return nullptr;
	}
	return new ProxyDOMNode(node);
}

///
// Returns the last child node.
///
/*--cef()--*/
shrewd_ptr<ProxyDOMNode> ProxyDOMNode::GetLastChild(){
	ASSERTQ(NULL);
	CefRefPtr<InternalDOMNode> node = FORWARD(InternalDOMNode)->GetLastChild();
	if (!node) {
		return nullptr;
	}
	return new ProxyDOMNode(node);
}

// The following methods are valid only for element nodes.

///
// Returns the tag name of this element.
///
/*--cef()--*/
char* ProxyDOMNode::GetElementTagName(){
	ASSERTQ(NULL);
	CefString string = FORWARD(InternalDOMNode)->GetElementTagName();
	if (string.empty()) {
		return nullptr;
	}
	return ToAnsi(string.c_str(),string.length());
}

///
// Returns true if this element has attributes.
///
/*--cef()--*/
bool ProxyDOMNode::HasElementAttributes(){
	ASSERTQ(NULL);
	return FORWARD(InternalDOMNode)->HasElementAttributes();
}

///
// Returns true if this element has an attribute named |attrName|.
///
/*--cef()--*/
bool ProxyDOMNode::HasElementAttribute(const char* attrName){
	ASSERTQ(false);
	USES_CONVERSION;
	if (!attrName) {
		return false;
	}
	return FORWARD(InternalDOMNode)->HasElementAttribute(A2W(attrName));
}

///
// Returns the element attribute named |attrName|.
///
/*--cef()--*/
char* ProxyDOMNode::GetElementAttribute(const char* attrName){
	ASSERTQ(NULL);
	USES_CONVERSION;
	if (!attrName) {
		return NULL;
	}
	CefString string = FORWARD(InternalDOMNode)->GetElementAttribute(A2W(attrName));
	if (string.empty()) {
		return NULL;
	}
	return ToAnsi(string.c_str(), string.length());
}

///
// Returns a map of all element attributes.
///
/*--cef()--*/
shrewd_ptr<ProxyDictionaryValue> ProxyDOMNode::GetElementAttributes(){
	ASSERTQ(NULL);
	CefRefPtr<CefDictionaryValue> value = nullptr;
	FORWARD(InternalDOMNode)->GetElementAttributes(value);
	if (!value) {
		return NULL;
	}
	return new ProxyDictionaryValue(value);
}

///
// Set the value for the element attribute named |attrName|. Returns true on
// success.
///
/*--cef()--*/
bool ProxyDOMNode::SetElementAttribute(const char* attrName, const char* value){
	ASSERTQ(false);
	USES_CONVERSION;
	if (!attrName) {
		return NULL;
	}
	const wchar_t* wideValue = L"";
	if (value) {
		wideValue = A2W(value);
	}
	return FORWARD(InternalDOMNode)->SetElementAttribute(A2W(attrName),wideValue);
}

///
// Returns the inner text of the element.
///
/*--cef()--*/
char* ProxyDOMNode::GetElementInnerText(){
	ASSERTQ(NULL);
	USES_CONVERSION;
	CefString string = FORWARD(InternalDOMNode)->GetElementInnerText();
	if (string.empty()) {
		return NULL;
	}
	return ToAnsi(string.c_str(), string.length());
}

///
// Returns the bounds of the element.
///
/*--cef()--*/
int** ProxyDOMNode::GetElementBounds(){
	ASSERTQ(NULL);
	return FORWARD(InternalDOMNode)->GetElementBounds();
}

///
// send event.
///
/*--cef()--*/
void ProxyDOMNode::SendEvent(const char* evt_name, EPL_ALL arguments) {
	ASSERTN();
	USES_CONVERSION;
	if (!evt_name) {
		return;
	}
	if (arguments && ORIGIN(CefListValue, ((ProxyDOMNode*)arguments))) {
		FORWARD(InternalDOMNode)->SendEvent(A2W(evt_name), ORIGIN(CefListValue, ((ProxyDOMNode*)arguments)));
	}
	else {
		FORWARD(InternalDOMNode)->SendEvent(A2W(evt_name), nullptr);
	}
}

///
// query selector
///
/*--cef()--*/
shrewd_ptr<ProxyDOMNode> ProxyDOMNode::QuerySelector(const char* selectors) {
	ASSERTQ(nullptr);
	USES_CONVERSION;
	CefRefPtr<InternalDOMNode> node = nullptr;
	if (!selectors) {
		return nullptr;
	}
	node = FORWARD(InternalDOMNode)->QuerySelector(A2W(selectors));
	if (!node) {
		return nullptr;
	}
	return new ProxyDOMNode(node);
}

///
// query selector
///
/*--cef()--*/
shrewd_ptr<ProxyDOMNode>** ProxyDOMNode::QuerySelectorAll(const char* selectors) {
	ASSERTQ(nullptr);
	USES_CONVERSION;
	if (!selectors) {
		return nullptr;
	}
	void** result = FORWARD(InternalDOMNode)->QuerySelectorAll(A2W(selectors));
	if (!result) {
		return nullptr;
	}
	return (shrewd_ptr<ProxyDOMNode>**)result;
}

///
// get child count
///
/*--cef()--*/
int ProxyDOMNode::GetChildCount() {
	ASSERTQ(0);
	return FORWARD(InternalDOMNode)->GetChildCount();
}

///
// get selectors
///
/*--cef()--*/
char* ProxyDOMNode::GetSelector() {
	ASSERTQ(NULL);
	return FORWARD(InternalDOMNode)->GetSelector();
}