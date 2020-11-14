#pragma once
#include "include/cef_dom.h"
#include "include/cef_frame.h"
#include "include/cef_values.h"

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

void TestDomProcess(CefRefPtr<CefFrame> frame, CefRefPtr<CefListValue> arguments);

void DomSendMessage(CefRefPtr<CefFrame> frame, INTERNAL_RESULT_COMMAND command, CefRefPtr<CefListValue> params, uint32_t pointer);

void DomGetDocument(CefRefPtr<CefFrame> frame, uint32_t pointer, uint32_t callback);

void DomFreeDocument(CefRefPtr<CefFrame> frame, uint32_t pointer, uint32_t callback);

void DomGetType(CefRefPtr<CefFrame> frame, uint32_t pointer, uint32_t callback);

void DomGetRoot(CefRefPtr<CefFrame> frame, uint32_t pointer, uint32_t callback);

void DomGetBody(CefRefPtr<CefFrame> frame, uint32_t pointer, uint32_t callback);

void DomGetHead(CefRefPtr<CefFrame> frame, uint32_t pointer, uint32_t callback);

void DomGetTitle(CefRefPtr<CefFrame> frame, uint32_t pointer, uint32_t callback);

void DomGetItemById(CefRefPtr<CefFrame> frame, uint32_t pointer, CefRefPtr<CefListValue> params, uint32_t callback);

void DomFocusedNode(CefRefPtr<CefFrame> frame, uint32_t pointer, uint32_t callback);

void DomHasSelection(CefRefPtr<CefFrame> frame, uint32_t pointer, uint32_t callback);

void DomSelectionStartOffset(CefRefPtr<CefFrame> frame, uint32_t pointer, uint32_t callback);

void DomSelectionEndOffset(CefRefPtr<CefFrame> frame, uint32_t pointer, uint32_t callback);

void DomGetSelectionAsMarkup(CefRefPtr<CefFrame> frame, uint32_t pointer, uint32_t callback);

void DomGetSelectionAsText(CefRefPtr<CefFrame> frame, uint32_t pointer, uint32_t callback);

void DomGetBaseURL(CefRefPtr<CefFrame> frame, uint32_t pointer, uint32_t callback);

void DomGetCompleteURL(CefRefPtr<CefFrame> frame, uint32_t pointer, CefRefPtr<CefListValue> params, uint32_t callback);

void DomQuerySelector(CefRefPtr<CefFrame> frame, uint32_t pointer, CefRefPtr<CefListValue> params, uint32_t callback);

void DomQuerySelectorAll(CefRefPtr<CefFrame> frame, uint32_t pointer, CefRefPtr<CefListValue> params, uint32_t callback);

void DomNodeFree(CefRefPtr<CefFrame> frame, uint32_t pointer, uint32_t callback);

void DomNodeGetType(CefRefPtr<CefFrame> frame, uint32_t pointer, uint32_t callback);

void DomNodeIsType(CefRefPtr<CefFrame> frame, uint32_t pointer, uint32_t callback);

void DomNodeIsElement(CefRefPtr<CefFrame> frame, uint32_t pointer, uint32_t callback);

void DomNodeIsEditable(CefRefPtr<CefFrame> frame, uint32_t pointer, uint32_t callback);

void DomNodeIsFormControlElement(CefRefPtr<CefFrame> frame, uint32_t pointer, uint32_t callback);

void DomNodeGetFormControlElementType(CefRefPtr<CefFrame> frame, uint32_t pointer, uint32_t callback);

void DomNodeGetName(CefRefPtr<CefFrame> frame, uint32_t pointer, uint32_t callback);

void DomNodeGetValue(CefRefPtr<CefFrame> frame, uint32_t pointer, uint32_t callback);

void DomNodeSetValue(CefRefPtr<CefFrame> frame, uint32_t pointer, CefRefPtr<CefListValue> params, uint32_t callback);

void DomNodeAsMarkup(CefRefPtr<CefFrame> frame, uint32_t pointer, uint32_t callback);

void DomNodeDocument(CefRefPtr<CefFrame> frame, uint32_t pointer, uint32_t callback);

void DomNodeParent(CefRefPtr<CefFrame> frame, uint32_t pointer, uint32_t callback);

void DomNodePrevSibling(CefRefPtr<CefFrame> frame, uint32_t pointer, uint32_t callback);

void DomNodeNextSibling(CefRefPtr<CefFrame> frame, uint32_t pointer, uint32_t callback);

void DomNodeHasChildren(CefRefPtr<CefFrame> frame, uint32_t pointer, uint32_t callback);

void DomNodeGetFirstChild(CefRefPtr<CefFrame> frame, uint32_t pointer, uint32_t callback);

void DomNodeGetLastChild(CefRefPtr<CefFrame> frame, uint32_t pointer, uint32_t callback);

void DomNodeElementTagName(CefRefPtr<CefFrame> frame, uint32_t pointer, uint32_t callback);

void DomNodeHasElementAttributes(CefRefPtr<CefFrame> frame, uint32_t pointer, uint32_t callback);

void DomNodeHasElementAttribute(CefRefPtr<CefFrame> frame, uint32_t pointer, CefRefPtr<CefListValue> params, uint32_t callback);

void DomNodeGetElementAtrribute(CefRefPtr<CefFrame> frame, uint32_t pointer, CefRefPtr<CefListValue> params, uint32_t callback);

void DomNodeGetElementAttributes(CefRefPtr<CefFrame> frame, uint32_t pointer, uint32_t callback);

void DomNodeSetElementAttribute(CefRefPtr<CefFrame> frame, uint32_t pointer, CefRefPtr<CefListValue> params, uint32_t callback);

void DomNodeGetElmentInnerText(CefRefPtr<CefFrame> frame, uint32_t pointer, uint32_t callback);

void DomNodeGetElementBounds(CefRefPtr<CefFrame> frame, uint32_t pointer, uint32_t callback);

void DomNodeQuerySelector(CefRefPtr<CefFrame> frame, uint32_t pointer, CefRefPtr<CefListValue> params, uint32_t callback);

void DomNodeQuerySelectorAll(CefRefPtr<CefFrame> frame, uint32_t pointer, CefRefPtr<CefListValue> params, uint32_t callback);

void DomNodeSendEvent(CefRefPtr<CefFrame> frame, uint32_t pointer, CefRefPtr<CefListValue> params, uint32_t callback);

void DomNodeGetChildCount(CefRefPtr<CefFrame> frame, uint32_t pointer, uint32_t callback);

void DomNodeGetSelector(CefRefPtr<CefFrame> frame, uint32_t pointer, uint32_t callback);