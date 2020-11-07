#include "TestDomProcess.h"
#include "TestDomVisitor.h"
#include "include/cef_app.h"
#include "TestThread.h"
#include "TestSelector.h"
#include <sstream>

void TestDomProcess(CefRefPtr<CefFrame> frame, CefRefPtr<CefListValue> arguments) {
	INTERNAL_DOM_COMMAND command = (INTERNAL_DOM_COMMAND)arguments->GetInt(0);
	CefRefPtr<CefListValue> params = nullptr;
	uint32_t pointer = (uint32_t)arguments->GetInt(2);
	uint32_t callback = 0;

	if (arguments->GetType(1) != VTYPE_NULL) {
		params = arguments->GetList(1);
	}

	if (arguments->GetType(3) != VTYPE_NULL) {
		callback = (uint32_t)arguments->GetInt(3);
	}

	switch (command)
	{
	case IDC_GET_DOCUMENT:
		DomGetDocument(frame,pointer, callback);
		return;
	case IDC_GET_TYPE:
		DomGetType(frame, pointer, callback);
		return;
	case IDC_GET_ROOT:
		DomGetRoot(frame, pointer, callback);
		return;
	case IDC_GET_BODY:
		DomGetBody(frame, pointer, callback);
		return;
	case IDC_GET_HEAD:
		DomGetHead(frame, pointer, callback);
		return;
	case IDC_GET_TITLE:
		DomGetTitle(frame, pointer, callback);
		return;
	case IDC_GET_ELEMENT_BY_ID:
		DomGetItemById(frame, pointer, params, callback);
		return;
	case IDC_GET_FOCUSED_NODE:
		DomFocusedNode(frame, pointer, callback);
		return;
	case IDC_HAS_SELECTION:
		DomHasSelection(frame, pointer, callback);
		return;
	case IDC_GET_SELECTION_START_OFFSET:
		DomSelectionStartOffset(frame, pointer, callback);
		return;
	case IDC_GET_SELECTION_END_OFFSET:
		DomSelectionEndOffset(frame, pointer, callback);
		return;
	case IDC_GET_SELECTION_AS_MARKUP:
		DomGetSelectionAsMarkup(frame, pointer, callback);
		return;
	case IDC_GET_SELECTION_AS_TEXT:
		DomGetSelectionAsText(frame, pointer, callback);
		return;
	case IDC_GET_BASE_URL:
		DomGetBaseURL(frame, pointer, callback);
		return;
	case IDC_GET_COMPLETE_URL:
		DomGetCompleteURL(frame, pointer, params, callback);
		return;
	case IDC_FREE_DOCUMENT:
		DomFreeDocument(frame, pointer, 0);
		return;
	case IDC_QUERY_SELECTOR:
		DomQuerySelector(frame, pointer, params, callback);
		return;
	case IDC_QUERY_SELECTOR_ALL:
		DomQuerySelectorAll(frame, pointer, params, callback);
		return;
	default:
		break;
	}

	INTERNAL_NODE_COMMAND node_command = (INTERNAL_NODE_COMMAND)command;
	switch (node_command)
	{
	case INC_NODE_FREE:
		DomNodeFree(frame,pointer,callback);
		return;
	case INC_NODE_GET_TYPE:
		DomNodeGetType(frame,pointer,callback);
		return;
	case INC_NODE_IS_TEXT:
		DomNodeIsType(frame, pointer, callback);
		return;
	case INC_NODE_IS_ELEMENT:
		DomNodeIsElement(frame, pointer, callback);
		return;
	case INC_NODE_IS_EDITABLE:
		DomNodeIsEditable(frame, pointer, callback);
		return;
	case INC_NODE_IS_FORM_CONTROL_ELEMENT:
		DomNodeIsFormControlElement(frame, pointer, callback);
		return;
	case INC_NODE_GET_FORM_CONTROL_ELEMENT_TYPE:
		DomNodeGetFormControlElementType(frame, pointer, callback);
		return;
	case INC_NODE_GET_NAME:
		DomNodeGetName(frame, pointer, callback);
		return;
	case INC_NODE_GET_VALUE:
		DomNodeGetValue(frame, pointer, callback);
		return;
	case INC_NODE_SET_VALUE:
		DomNodeSetValue(frame, pointer, params, callback);
		return;
	case INC_NODE_GET_AS_MARKUP:
		DomNodeAsMarkup(frame, pointer, callback);
		return;
	case INC_NODE_GET_DOCUMENT:
		DomNodeDocument(frame, pointer, callback);
		return;
	case INC_NODE_GET_PARENT:
		DomNodeParent(frame, pointer, callback);
		return;
	case INC_NODE_PREV_SIBLING:
		DomNodePrevSibling(frame, pointer, callback);
		return;
	case INC_NODE_NEXT_SIBLING:
		DomNodeNextSibling(frame, pointer, callback);
		return;
	case INC_NODE_HAS_CHILDREN:
		DomNodeHasChildren(frame, pointer, callback);
		return;
	case INC_NODE_GET_FIRST_CHILD:
		DomNodeGetFirstChild(frame, pointer, callback);
		return;
	case INC_NODE_GET_LAST_CHILD:
		DomNodeGetLastChild(frame, pointer, callback);
		return;
	case INC_NODE_GET_ELEMENT_TAG_NAME:
		DomNodeElementTagName(frame, pointer, callback);
		return;
	case INC_NODE_HAS_ELEMENT_ATTRIBUTES:
		DomNodeHasElementAttributes(frame, pointer, callback);
		return;
	case INC_NODE_HAS_ELEMENT_ATTRIBUTE:
		DomNodeHasElementAttribute(frame, pointer,params, callback);
		return;
	case INC_NODE_GET_ELEMENT_ATTRIBUTE:
		DomNodeGetElementAtrribute(frame, pointer, params, callback);
		return;
	case INC_NODE_GET_ELEMENT_ATTRIBUTES:
		DomNodeGetElementAttributes(frame, pointer, callback);
		return;
	case INC_NODE_SET_ELEMENT_ATTRIBUTE:
		DomNodeSetElementAttribute(frame, pointer, params, callback);
		return;
	case INC_NODE_GET_ELEMENT_INNER_TEXT:
		DomNodeGetElmentInnerText(frame, pointer, callback);
		return;
	case INC_NODE_GET_ELEMENT_BOUNDS:
		DomNodeGetElementBounds(frame, pointer, callback);
		return;
	case INC_NODE_QUERY_SELECTOR:
		DomNodeQuerySelector(frame, pointer, params, callback);
		return;
	case INC_NODE_QUERY_SELECTOR_ALL:
		DomNodeQuerySelectorAll(frame, pointer, params, callback);
		return;
	case INC_NODE_SEND_EVENT:
		DomNodeSendEvent(frame, pointer, params, callback);
		return;
	case INC_NODE_GET_CHILD_COUNT:
		DomNodeGetChildCount(frame, pointer, callback);
		return;
	case INC_NODE_GET_SELECTOR:
		DomNodeGetSelector(frame, pointer, callback);
		return;
	default:
		break;
	}
}

void DomSendMessage(CefRefPtr<CefFrame> frame, INTERNAL_RESULT_COMMAND command, CefRefPtr<CefListValue> params, uint32_t pointer) {
	CefRefPtr<CefProcessMessage> message = CefProcessMessage::Create(L"IPC_DOM_RESULT");
	CefRefPtr<CefListValue> arguments = message->GetArgumentList();
	arguments->SetInt(0, (int)command);
	if (params) {
		arguments->SetList(1, params);
	}
	else {
		arguments->SetNull(1);
	}
	arguments->SetInt(2, pointer);
	frame->SendProcessMessage(PID_RENDERER, message);
}

void DomGetDocument(CefRefPtr<CefFrame> frame, uint32_t pointer, uint32_t callback) {
	CefRefPtr<TestDomVisitor> visitor = new TestDomVisitor(frame, callback);
	frame->VisitDOM(visitor);
}

void DomFreeDocument(CefRefPtr<CefFrame> frame, uint32_t pointer, uint32_t callback) {
	CefRefPtr<CefDOMDocument> document = (CefDOMDocument*)pointer;
	if (pointer) {
		document->Release();
	}
}

void DomGetType(CefRefPtr<CefFrame> frame, uint32_t pointer, uint32_t callback) {
	if (pointer) {
		CefRefPtr<CefDOMDocument> document = (CefDOMDocument*)pointer;
		int type = (int)document->GetType();
		CefRefPtr<CefListValue> params = CefListValue::Create();
		params->SetInt(0, type);
		DomSendMessage(frame, IRD_DOCUMENT_RESULT, params, callback);
	}
	else {
		DomSendMessage(frame, IRD_DOCUMENT_RESULT, nullptr, callback);
	}
}

void DomGetRoot(CefRefPtr<CefFrame> frame, uint32_t pointer, uint32_t callback) {
	if (pointer) {
		CefRefPtr<CefDOMDocument> document = (CefDOMDocument*)pointer;
		CefRefPtr<CefDOMNode> root = document->GetDocument();
		CefRefPtr<CefListValue> params = CefListValue::Create();
		root->AddRef();
		params->SetInt(0, (int)root.get());
		DomSendMessage(frame, IRD_DOCUMENT_RESULT, params, callback);
	}
	else {
		DomSendMessage(frame, IRD_DOCUMENT_RESULT, nullptr, callback);
	}
}

void DomGetBody(CefRefPtr<CefFrame> frame, uint32_t pointer, uint32_t callback) {
	if (pointer) {
		CefRefPtr<CefDOMDocument> document = (CefDOMDocument*)pointer;
		CefRefPtr<CefDOMNode> root = document->GetBody();
		CefRefPtr<CefListValue> params = CefListValue::Create();
		root->AddRef();
		params->SetInt(0, (int)root.get());
		DomSendMessage(frame, IRD_DOCUMENT_RESULT, params, callback);
	}
	else {
		DomSendMessage(frame, IRD_DOCUMENT_RESULT, nullptr, callback);
	}
}

void DomGetHead(CefRefPtr<CefFrame> frame, uint32_t pointer, uint32_t callback) {
	if (pointer) {
		CefRefPtr<CefDOMDocument> document = (CefDOMDocument*)pointer;
		CefRefPtr<CefDOMNode> root = document->GetHead();
		CefRefPtr<CefListValue> params = CefListValue::Create();
		root->AddRef();
		params->SetInt(0, (int)root.get());
		DomSendMessage(frame, IRD_DOCUMENT_RESULT, params, callback);
	}
	else {
		DomSendMessage(frame, IRD_DOCUMENT_RESULT, nullptr, callback);
	}
}

void DomGetTitle(CefRefPtr<CefFrame> frame, uint32_t pointer, uint32_t callback) {
	if (pointer) {
		CefRefPtr<CefDOMDocument> document = (CefDOMDocument*)pointer;
		CefString s = document->GetTitle();
		CefRefPtr<CefListValue> params = CefListValue::Create();
		params->SetString(0, s);
		DomSendMessage(frame, IRD_DOCUMENT_RESULT, params, callback);
	}
	else {
		DomSendMessage(frame, IRD_DOCUMENT_RESULT, nullptr, callback);
	}
}

void DomGetItemById(CefRefPtr<CefFrame> frame, uint32_t pointer, CefRefPtr<CefListValue> arguments, uint32_t callback) {
	if (pointer && arguments) {
		CefRefPtr<CefDOMDocument> document = (CefDOMDocument*)pointer;
		CefRefPtr<CefDOMNode> root = document->GetElementById(arguments->GetString(0));
		CefRefPtr<CefListValue> params = CefListValue::Create();
		root->AddRef();
		params->SetInt(0, (int)root.get());
		DomSendMessage(frame, IRD_DOCUMENT_RESULT, params, callback);
	}
	else {
		DomSendMessage(frame, IRD_DOCUMENT_RESULT, nullptr, callback);
	}
}

void DomFocusedNode(CefRefPtr<CefFrame> frame, uint32_t pointer, uint32_t callback) {
	if (pointer) {
		CefRefPtr<CefDOMDocument> document = (CefDOMDocument*)pointer;
		CefRefPtr<CefDOMNode> node = document->GetFocusedNode();
		CefRefPtr<CefListValue> params = CefListValue::Create();
		node->AddRef();
		params->SetInt(0, (int)node.get());
		DomSendMessage(frame, IRD_DOCUMENT_RESULT, params, callback);
	}
	else {
		DomSendMessage(frame, IRD_DOCUMENT_RESULT, nullptr, callback);
	}
}

void DomHasSelection(CefRefPtr<CefFrame> frame, uint32_t pointer, uint32_t callback) {
	if (pointer) {
		CefRefPtr<CefDOMDocument> document = (CefDOMDocument*)pointer;
		bool result = document->HasSelection();
		CefRefPtr<CefListValue> params = CefListValue::Create();
		params->SetBool(0, result);
		DomSendMessage(frame, IRD_DOCUMENT_RESULT, params, callback);
	}
	else {
		DomSendMessage(frame, IRD_DOCUMENT_RESULT, nullptr, callback);
	}
}

void DomSelectionStartOffset(CefRefPtr<CefFrame> frame, uint32_t pointer, uint32_t callback) {
	if (pointer) {
		CefRefPtr<CefDOMDocument> document = (CefDOMDocument*)pointer;
		int result = document->GetSelectionStartOffset();
		CefRefPtr<CefListValue> params = CefListValue::Create();
		params->SetInt(0, result);
		DomSendMessage(frame, IRD_DOCUMENT_RESULT, params, callback);
	}
	else {
		DomSendMessage(frame, IRD_DOCUMENT_RESULT, nullptr, callback);
	}
}

void DomSelectionEndOffset(CefRefPtr<CefFrame> frame, uint32_t pointer, uint32_t callback) {
	if (pointer) {
		CefRefPtr<CefDOMDocument> document = (CefDOMDocument*)pointer;
		int result = document->GetSelectionEndOffset();
		CefRefPtr<CefListValue> params = CefListValue::Create();
		params->SetInt(0, result);
		DomSendMessage(frame, IRD_DOCUMENT_RESULT, params, callback);
	}
	else {
		DomSendMessage(frame, IRD_DOCUMENT_RESULT, nullptr, callback);
	}
}

void DomGetSelectionAsMarkup(CefRefPtr<CefFrame> frame, uint32_t pointer, uint32_t callback) {
	if (pointer) {
		CefRefPtr<CefDOMDocument> document = (CefDOMDocument*)pointer;
		CefString result = document->GetSelectionAsMarkup();
		CefRefPtr<CefListValue> params = CefListValue::Create();
		params->SetString(0, result);
		DomSendMessage(frame, IRD_DOCUMENT_RESULT, params, callback);
	}
	else {
		DomSendMessage(frame, IRD_DOCUMENT_RESULT, nullptr, callback);
	}
}

void DomGetSelectionAsText(CefRefPtr<CefFrame> frame, uint32_t pointer, uint32_t callback) {
	if (pointer) {
		CefRefPtr<CefDOMDocument> document = (CefDOMDocument*)pointer;
		CefString result = document->GetSelectionAsText();
		CefRefPtr<CefListValue> params = CefListValue::Create();
		params->SetString(0, result);
		DomSendMessage(frame, IRD_DOCUMENT_RESULT, params, callback);
	}
	else {
		DomSendMessage(frame, IRD_DOCUMENT_RESULT, nullptr, callback);
	}
}

void DomGetBaseURL(CefRefPtr<CefFrame> frame, uint32_t pointer, uint32_t callback) {
	if (pointer) {
		CefRefPtr<CefDOMDocument> document = (CefDOMDocument*)pointer;
		CefString result = document->GetBaseURL();
		CefRefPtr<CefListValue> params = CefListValue::Create();
		params->SetString(0, result);
		DomSendMessage(frame, IRD_DOCUMENT_RESULT, params, callback);
	}
	else {
		DomSendMessage(frame, IRD_DOCUMENT_RESULT, nullptr, callback);
	}
}

void DomGetCompleteURL(CefRefPtr<CefFrame> frame, uint32_t pointer, CefRefPtr<CefListValue> arguments, uint32_t callback) {
	if (pointer && arguments) {
		CefRefPtr<CefDOMDocument> document = (CefDOMDocument*)pointer;
		CefString result = document->GetCompleteURL(arguments->GetString(0));
		CefRefPtr<CefListValue> params = CefListValue::Create();
		params->SetString(0, result);
		DomSendMessage(frame, IRD_DOCUMENT_RESULT, params, callback);
	}
	else {
		DomSendMessage(frame, IRD_DOCUMENT_RESULT, nullptr, callback);
	}
}

void DomQuerySelector(CefRefPtr<CefFrame> frame, uint32_t pointer, CefRefPtr<CefListValue> arguments, uint32_t callback) {
	if (pointer && arguments) {
		CefRefPtr<CefDOMDocument> document = (CefDOMDocument*)pointer;
		CefRefPtr<CefDOMNode> root = document->GetDocument();
		CefRefPtr<CefDOMNode> result = nullptr;
		CefString selectors = arguments->GetString(0);
		TestSelector query(root, selectors, false);
		if (query.Find()) {
			CefRefPtr<CefListValue> params = CefListValue::Create();
			result = query.GetFirstElement();
			result->AddRef();
			params->SetInt(0, (int)result.get());
			DomSendMessage(frame, IRD_DOCUMENT_RESULT, params, callback);
		}
		else {
			DomSendMessage(frame, IRD_DOCUMENT_RESULT, nullptr, callback);
		}
	}
	else {
		DomSendMessage(frame, IRD_DOCUMENT_RESULT, nullptr, callback);
	}
}

void DomQuerySelectorAll(CefRefPtr<CefFrame> frame, uint32_t pointer, CefRefPtr<CefListValue> arguments, uint32_t callback) {
	if (pointer && arguments) {
		CefRefPtr<CefDOMDocument> document = (CefDOMDocument*)pointer;
		CefRefPtr<CefDOMNode> root = document->GetDocument();
		CefRefPtr<CefDOMNode> result = nullptr;
		CefString selectors = arguments->GetString(0);
		TestSelector query(root, selectors, false);
		if (query.Find()) {
			CefRefPtr<CefListValue> params = CefListValue::Create();
			std::vector<CefRefPtr<CefDOMNode>> result;
			query.GetAllElement(result);
			if (!result.empty()) {
				for (size_t i = 0; i < result.size(); i++) {
					result[i]->AddRef();
					params->SetInt(i, (int)result[i].get());
				}
				DomSendMessage(frame, IRD_DOCUMENT_RESULT, params, callback);
			}
			else {
				DomSendMessage(frame, IRD_DOCUMENT_RESULT, nullptr, callback);
			}
		}
		else {
			DomSendMessage(frame, IRD_DOCUMENT_RESULT, nullptr, callback);
		}
	}
	else {
		DomSendMessage(frame, IRD_DOCUMENT_RESULT, nullptr, callback);
	}
}

void DomNodeFree(CefRefPtr<CefFrame> frame, uint32_t pointer, uint32_t callback) {
	if (pointer) {
		CefRefPtr<CefDOMNode> node = (CefDOMNode*)pointer;
		node->Release();
	}
	else {
		DomSendMessage(frame, IRD_DOCUMENT_RESULT, nullptr, callback);
	}
}

void DomNodeGetType(CefRefPtr<CefFrame> frame, uint32_t pointer, uint32_t callback) {
	if (pointer) {
		CefRefPtr<CefDOMNode> node = (CefDOMNode*)pointer;
		int result = node->GetType();
		CefRefPtr<CefListValue> params = CefListValue::Create();
		params->SetInt(0, result);
		DomSendMessage(frame, IRD_DOCUMENT_RESULT, params, callback);
	}
	else {
		DomSendMessage(frame, IRD_DOCUMENT_RESULT, nullptr, callback);
	}
}

void DomNodeIsType(CefRefPtr<CefFrame> frame, uint32_t pointer, uint32_t callback) {
	if (pointer) {
		CefRefPtr<CefDOMNode> node = (CefDOMNode*)pointer;
		int result = node->GetType();
		CefRefPtr<CefListValue> params = CefListValue::Create();
		params->SetInt(0, result);
		DomSendMessage(frame, IRD_DOCUMENT_RESULT, params, callback);
	}
	else {
		DomSendMessage(frame, IRD_DOCUMENT_RESULT, nullptr, callback);
	}
}

void DomNodeIsElement(CefRefPtr<CefFrame> frame, uint32_t pointer, uint32_t callback) {
	if (pointer) {
		CefRefPtr<CefDOMNode> node = (CefDOMNode*)pointer;
		bool result = node->IsElement();
		CefRefPtr<CefListValue> params = CefListValue::Create();
		params->SetBool(0, result);
		DomSendMessage(frame, IRD_DOCUMENT_RESULT, params, callback);
	}
	else {
		DomSendMessage(frame, IRD_DOCUMENT_RESULT, nullptr, callback);
	}
}

void DomNodeIsEditable(CefRefPtr<CefFrame> frame, uint32_t pointer, uint32_t callback) {
	if (pointer) {
		CefRefPtr<CefDOMNode> node = (CefDOMNode*)pointer;
		bool result = node->IsEditable();
		CefRefPtr<CefListValue> params = CefListValue::Create();
		params->SetBool(0, result);
		DomSendMessage(frame, IRD_DOCUMENT_RESULT, params, callback);
	}
	else {
		DomSendMessage(frame, IRD_DOCUMENT_RESULT, nullptr, callback);
	}
}

void DomNodeIsFormControlElement(CefRefPtr<CefFrame> frame, uint32_t pointer, uint32_t callback) {
	if (pointer) {
		CefRefPtr<CefDOMNode> node = (CefDOMNode*)pointer;
		bool result = node->IsFormControlElement();
		CefRefPtr<CefListValue> params = CefListValue::Create();
		params->SetBool(0, result);
		DomSendMessage(frame, IRD_DOCUMENT_RESULT, params, callback);
	}
	else {
		DomSendMessage(frame, IRD_DOCUMENT_RESULT, nullptr, callback);
	}
}

void DomNodeGetFormControlElementType(CefRefPtr<CefFrame> frame, uint32_t pointer, uint32_t callback) {
	if (pointer) {
		CefRefPtr<CefDOMNode> node = (CefDOMNode*)pointer;
		CefString result = node->GetFormControlElementType();
		CefRefPtr<CefListValue> params = CefListValue::Create();
		params->SetString(0, result);
		DomSendMessage(frame, IRD_DOCUMENT_RESULT, params, callback);
	}
	else {
		DomSendMessage(frame, IRD_DOCUMENT_RESULT, nullptr, callback);
	}
}

void DomNodeGetName(CefRefPtr<CefFrame> frame, uint32_t pointer, uint32_t callback) {
	if (pointer) {
		CefRefPtr<CefDOMNode> node = (CefDOMNode*)pointer;
		CefString result = node->GetName();
		CefRefPtr<CefListValue> params = CefListValue::Create();
		params->SetString(0, result);
		DomSendMessage(frame, IRD_DOCUMENT_RESULT, params, callback);
	}
	else {
		DomSendMessage(frame, IRD_DOCUMENT_RESULT, nullptr, callback);
	}
}

void DomNodeGetValue(CefRefPtr<CefFrame> frame, uint32_t pointer, uint32_t callback) {
	if (pointer) {
		CefRefPtr<CefDOMNode> node = (CefDOMNode*)pointer;
		CefString result = node->GetValue();
		CefRefPtr<CefListValue> params = CefListValue::Create();
		params->SetString(0, result);
		DomSendMessage(frame, IRD_DOCUMENT_RESULT, params, callback);
	}
	else {
		DomSendMessage(frame, IRD_DOCUMENT_RESULT, nullptr, callback);
	}
}

void DomNodeSetValue(CefRefPtr<CefFrame> frame, uint32_t pointer, CefRefPtr<CefListValue> arguments, uint32_t callback) {
	if (pointer && arguments) {
		CefRefPtr<CefDOMNode> node = (CefDOMNode*)pointer;
		CefString value = arguments->GetString(0);
		bool result = node->SetValue(value);
		CefRefPtr<CefListValue> params = CefListValue::Create();
		params->SetBool(0, result);
		DomSendMessage(frame, IRD_DOCUMENT_RESULT, params, callback);
	}
	else {
		DomSendMessage(frame, IRD_DOCUMENT_RESULT, nullptr, callback);
	}
}

void DomNodeAsMarkup(CefRefPtr<CefFrame> frame, uint32_t pointer, uint32_t callback) {
	if (pointer) {
		CefRefPtr<CefDOMNode> node = (CefDOMNode*)pointer;
		CefString result = node->GetAsMarkup();
		CefRefPtr<CefListValue> params = CefListValue::Create();
		params->SetString(0, result);
		DomSendMessage(frame, IRD_DOCUMENT_RESULT, params, callback);
	}
	else {
		DomSendMessage(frame, IRD_DOCUMENT_RESULT, nullptr, callback);
	}
}

void DomNodeDocument(CefRefPtr<CefFrame> frame, uint32_t pointer, uint32_t callback) {
	if (pointer) {
		CefRefPtr<CefDOMNode> node = (CefDOMNode*)pointer;
		CefRefPtr <CefDOMDocument> result = node->GetDocument();
		CefRefPtr<CefListValue> params = CefListValue::Create();
		result->AddRef();
		params->SetInt(0, (int)result.get());
		DomSendMessage(frame, IRD_DOCUMENT_RESULT, params, callback);
	}
	else {
		DomSendMessage(frame, IRD_DOCUMENT_RESULT, nullptr, callback);
	}
}

void DomNodeParent(CefRefPtr<CefFrame> frame, uint32_t pointer, uint32_t callback) {
	if (pointer) {
		CefRefPtr<CefDOMNode> node = (CefDOMNode*)pointer;
		CefRefPtr <CefDOMNode> result = node->GetParent();
		CefRefPtr<CefListValue> params = CefListValue::Create();
		if (result) {
			result->AddRef();
			params->SetInt(0, (int)result.get());
			DomSendMessage(frame, IRD_DOCUMENT_RESULT, params, callback);
		}
		else {
			DomSendMessage(frame, IRD_DOCUMENT_RESULT, nullptr, callback);
		}
	}
	else {
		DomSendMessage(frame, IRD_DOCUMENT_RESULT, nullptr, callback);
	}
}

void DomNodePrevSibling(CefRefPtr<CefFrame> frame, uint32_t pointer, uint32_t callback) {
	if (pointer) {
		CefRefPtr<CefDOMNode> node = (CefDOMNode*)pointer;
		CefRefPtr <CefDOMNode> sibling = node->GetPreviousSibling();
		CefRefPtr <CefDOMNode> result = nullptr;
		CefRefPtr<CefListValue> params = CefListValue::Create();
		CefString tag;
		while (sibling){
			tag = sibling->GetElementTagName();
			if (!tag.empty()) {
				result = sibling;
				break;
			}
			sibling = sibling->GetPreviousSibling();
		}

		if (result) {
			result->AddRef();
			params->SetInt(0, (int)result.get());
			DomSendMessage(frame, IRD_DOCUMENT_RESULT, params, callback);
		}
		else {
			DomSendMessage(frame, IRD_DOCUMENT_RESULT, nullptr, callback);
		}
	}
	else {
		DomSendMessage(frame, IRD_DOCUMENT_RESULT, nullptr, callback);
	}
}

void DomNodeNextSibling(CefRefPtr<CefFrame> frame, uint32_t pointer, uint32_t callback) {
	if (pointer) {
		CefRefPtr<CefDOMNode> node = (CefDOMNode*)pointer;
		CefRefPtr <CefDOMNode> sibling = node->GetNextSibling();
		CefRefPtr <CefDOMNode> result = nullptr;
		CefRefPtr<CefListValue> params = CefListValue::Create();
		CefString tag;
		while (sibling) {
			tag = sibling->GetElementTagName();
			if (!tag.empty()) {
				result = sibling;
				break;
			}
			sibling = sibling->GetNextSibling();
		}

		if (result) {
			result->AddRef();
			params->SetInt(0, (int)result.get());
			DomSendMessage(frame, IRD_DOCUMENT_RESULT, params, callback);
		}
		else {
			DomSendMessage(frame, IRD_DOCUMENT_RESULT, nullptr, callback);
		}
	}
	else {
		DomSendMessage(frame, IRD_DOCUMENT_RESULT, nullptr, callback);
	}
}

void DomNodeHasChildren(CefRefPtr<CefFrame> frame, uint32_t pointer, uint32_t callback) {
	if (pointer) {
		CefRefPtr<CefDOMNode> node = (CefDOMNode*)pointer;
		bool result = node->HasChildren();
		CefRefPtr<CefListValue> params = CefListValue::Create();
		params->SetBool(0, result);
		DomSendMessage(frame, IRD_DOCUMENT_RESULT, params, callback);
	}
	else {
		DomSendMessage(frame, IRD_DOCUMENT_RESULT, nullptr, callback);
	}
}

void DomNodeGetFirstChild(CefRefPtr<CefFrame> frame, uint32_t pointer, uint32_t callback) {
	if (pointer) {
		CefRefPtr<CefDOMNode> node = (CefDOMNode*)pointer;
		CefRefPtr <CefDOMNode> child = node->GetFirstChild();
		CefRefPtr <CefDOMNode> result = nullptr;
		CefRefPtr<CefListValue> params = CefListValue::Create();
		CefString tag;
		while (child)
		{
			tag = child->GetElementTagName();
			if (!tag.empty()) {
				result = child;
				break;
			}
			child = child->GetNextSibling();
		}
		if (result) {
			result->AddRef();
			params->SetInt(0, (int)result.get());
			DomSendMessage(frame, IRD_DOCUMENT_RESULT, params, callback);
		}
		else {
			DomSendMessage(frame, IRD_DOCUMENT_RESULT, nullptr, callback);
		}
	}
	else {
		DomSendMessage(frame, IRD_DOCUMENT_RESULT, nullptr, callback);
	}
}

void DomNodeGetLastChild(CefRefPtr<CefFrame> frame, uint32_t pointer, uint32_t callback) {
	if (pointer) {
		CefRefPtr<CefDOMNode> node = (CefDOMNode*)pointer;
		CefRefPtr <CefDOMNode> child = node->GetLastChild();
		CefRefPtr <CefDOMNode> result = nullptr;
		CefRefPtr<CefListValue> params = CefListValue::Create();
		CefString tag;
		while (child)
		{
			tag = child->GetElementTagName();
			if (!tag.empty()) {
				result = child;
				break;
			}
			child = child->GetPreviousSibling();
		}
		if (result) {
			result->AddRef();
			params->SetInt(0, (int)result.get());
			DomSendMessage(frame, IRD_DOCUMENT_RESULT, params, callback);
		}
		else {
			DomSendMessage(frame, IRD_DOCUMENT_RESULT, nullptr, callback);
		}
	}
	else {
		DomSendMessage(frame, IRD_DOCUMENT_RESULT, nullptr, callback);
	}
}

void DomNodeElementTagName(CefRefPtr<CefFrame> frame, uint32_t pointer, uint32_t callback) {
	if (pointer) {
		CefRefPtr<CefDOMNode> node = (CefDOMNode*)pointer;
		CefString result = node->GetElementTagName();
		CefRefPtr<CefListValue> params = CefListValue::Create();
		params->SetString(0, result);
		DomSendMessage(frame, IRD_DOCUMENT_RESULT, params, callback);
	}
	else {
		DomSendMessage(frame, IRD_DOCUMENT_RESULT, nullptr, callback);
	}
}

void DomNodeHasElementAttributes(CefRefPtr<CefFrame> frame, uint32_t pointer, uint32_t callback) {
	if (pointer) {
		CefRefPtr<CefDOMNode> node = (CefDOMNode*)pointer;
		bool result = node->HasElementAttributes();
		CefRefPtr<CefListValue> params = CefListValue::Create();
		params->SetBool(0, result);
		DomSendMessage(frame, IRD_DOCUMENT_RESULT, params, callback);
	}
	else {
		DomSendMessage(frame, IRD_DOCUMENT_RESULT, nullptr, callback);
	}
}

void DomNodeHasElementAttribute(CefRefPtr<CefFrame> frame, uint32_t pointer, CefRefPtr<CefListValue> arguments, uint32_t callback) {
	if (pointer && arguments) {
		CefRefPtr<CefDOMNode> node = (CefDOMNode*)pointer;
		bool result = node->HasElementAttribute(arguments->GetString(0));
		CefRefPtr<CefListValue> params = CefListValue::Create();
		params->SetBool(0, result);
		DomSendMessage(frame, IRD_DOCUMENT_RESULT, params, callback);
	}
	else {
		DomSendMessage(frame, IRD_DOCUMENT_RESULT, nullptr, callback);
	}
}

void DomNodeGetElementAtrribute(CefRefPtr<CefFrame> frame, uint32_t pointer, CefRefPtr<CefListValue> arguments, uint32_t callback) {
	if (pointer && arguments) {
		CefRefPtr<CefDOMNode> node = (CefDOMNode*)pointer;
		CefString result = node->GetElementAttribute(arguments->GetString(0));
		CefRefPtr<CefListValue> params = CefListValue::Create();
		params->SetString(0, result);
		DomSendMessage(frame, IRD_DOCUMENT_RESULT, params, callback);
	}
	else {
		DomSendMessage(frame, IRD_DOCUMENT_RESULT, nullptr, callback);
	}
}

void DomNodeGetElementAttributes(CefRefPtr<CefFrame> frame, uint32_t pointer, uint32_t callback) {
	if (pointer) {
		CefDOMNode::AttributeMap attribMaps;
		CefRefPtr<CefDOMNode> node = (CefDOMNode*)pointer;
		node->GetElementAttributes(attribMaps);
		CefRefPtr<CefListValue> params = CefListValue::Create();
		if (!attribMaps.empty()) {
			CefRefPtr<CefDictionaryValue> dict = CefDictionaryValue::Create();
			for (auto v : attribMaps) {
				dict->SetString(v.first, v.second);
			}
			params->SetDictionary(0, dict);
			DomSendMessage(frame, IRD_DOCUMENT_RESULT, params, callback);
		}
		else {
			DomSendMessage(frame, IRD_DOCUMENT_RESULT, nullptr, callback);
		}
	}
	else {
		DomSendMessage(frame, IRD_DOCUMENT_RESULT, nullptr, callback);
	}
}

void DomNodeSetElementAttribute(CefRefPtr<CefFrame> frame, uint32_t pointer, CefRefPtr<CefListValue> arguments, uint32_t callback) {
	if (pointer && arguments) {
		CefRefPtr<CefDOMNode> node = (CefDOMNode*)pointer;
		bool result = node->SetElementAttribute(arguments->GetString(0), arguments->GetString(1));
		CefRefPtr<CefListValue> params = CefListValue::Create();
		params->SetBool(0, result);
		DomSendMessage(frame, IRD_DOCUMENT_RESULT, params, callback);
	}
	else {
		DomSendMessage(frame, IRD_DOCUMENT_RESULT, nullptr, callback);
	}
}

void DomNodeGetElmentInnerText(CefRefPtr<CefFrame> frame, uint32_t pointer, uint32_t callback) {
	if (pointer) {
		CefRefPtr<CefDOMNode> node = (CefDOMNode*)pointer;
		CefString result = node->GetElementInnerText();
		CefRefPtr<CefListValue> params = CefListValue::Create();
		params->SetString(0, result);
		DomSendMessage(frame, IRD_DOCUMENT_RESULT, params, callback);
	}
	else {
		DomSendMessage(frame, IRD_DOCUMENT_RESULT, nullptr, callback);
	}
}

void DomNodeGetElementBounds(CefRefPtr<CefFrame> frame, uint32_t pointer, uint32_t callback) {
	if (pointer) {
		CefRect rect;
		CefRefPtr<CefDOMNode> node = (CefDOMNode*)pointer;
		CefRefPtr<CefListValue> params = CefListValue::Create();
		rect = node->GetElementBounds();
		params->SetInt(0, rect.x);
		params->SetInt(1, rect.y);
		params->SetInt(2, rect.width);
		params->SetInt(3, rect.height);
		DomSendMessage(frame, IRD_DOCUMENT_RESULT, params, callback);
	}
	else {
		DomSendMessage(frame, IRD_DOCUMENT_RESULT, nullptr, callback);
	}
}

void DomNodeGetChildCount(CefRefPtr<CefFrame> frame, uint32_t pointer, uint32_t callback) {
	if (pointer) {
		CefRect rect;
		CefRefPtr<CefDOMNode> node = (CefDOMNode*)pointer;
		CefRefPtr<CefDOMNode> child = node->GetFirstChild();
		CefString tag;
		int count = 0;
		while (child){
			tag = child->GetElementTagName();
			if (!tag.empty()) {
				count++;
			}
			child = child->GetNextSibling();
		}
		if (count > 0) {
			CefRefPtr<CefListValue> params = CefListValue::Create();
			params->SetInt(0, count);
			DomSendMessage(frame, IRD_DOCUMENT_RESULT, params, callback);
		}
		else {
			DomSendMessage(frame, IRD_DOCUMENT_RESULT, nullptr, callback);
		}
	}
	else {
		DomSendMessage(frame, IRD_DOCUMENT_RESULT, nullptr, callback);
	}
}

void DomNodeGetSelector(CefRefPtr<CefFrame> frame, uint32_t pointer, uint32_t callback) {
	if (pointer) {
		CefRefPtr<CefDOMNode> node = (CefDOMNode*)pointer;
		CefRefPtr<CefDOMNode> parent = node->GetParent();
		CefRefPtr<CefDOMNode> child = nullptr;

		CefRefPtr<CefListValue> params = nullptr;
		std::vector<std::wstring> paths;
		CefString tag;
		std::wstring mytag = node->GetElementTagName().ToWString();
		wchar_t buffer[128] = L"";
		std::wstringstream selectors;

		while (parent) {
			child = parent->GetFirstChild();
			int count = 0;
			while (child) {
				tag = child->GetElementTagName();
				if (!tag.empty()) {
					if (child->IsSame(node)) {
						swprintf_s(buffer, 128, L"%s:nth-child(%d)", mytag.c_str(), count + 1);
						paths.push_back(buffer);
						break;
					}
					count++;
				}
				child = child->GetNextSibling();
			}

			node = parent;
			mytag = parent->GetElementTagName();
			parent = parent->GetParent();
		}
		for (int i = paths.size() - 1; i >= 0; i--) {
			selectors << paths[i];
			if (i > 0) {
				selectors << L" > ";
			}
		}
		std::wstring s = selectors.str();
		params = CefListValue::Create();
		params->SetString(0, s);
		DomSendMessage(frame, IRD_DOCUMENT_RESULT, params, callback);
	}
	else {
		DomSendMessage(frame, IRD_DOCUMENT_RESULT, nullptr, callback);
	}
}

void DomNodeQuerySelector(CefRefPtr<CefFrame> frame, uint32_t pointer, CefRefPtr<CefListValue> arguments, uint32_t callback) {
	if (pointer && arguments) {
		CefRefPtr<CefDOMNode> root = (CefDOMNode*)pointer;
		CefRefPtr<CefDOMNode> result = nullptr;
		CefString selectors = arguments->GetString(0);
		TestSelector query(root, selectors, false);
		if (query.Find()) {
			CefRefPtr<CefListValue> params = CefListValue::Create();
			result = query.GetFirstElement();
			result->AddRef();
			params->SetInt(0, (int)result.get());
			DomSendMessage(frame, IRD_DOCUMENT_RESULT, params, callback);
		}
		else {
			DomSendMessage(frame, IRD_DOCUMENT_RESULT, nullptr, callback);
		}
	}
	else {
		DomSendMessage(frame, IRD_DOCUMENT_RESULT, nullptr, callback);
	}
}

void DomNodeQuerySelectorAll(CefRefPtr<CefFrame> frame, uint32_t pointer, CefRefPtr<CefListValue> arguments, uint32_t callback) {
	if (pointer && arguments) {
		CefRefPtr<CefDOMNode> root = (CefDOMNode*)pointer;
		CefRefPtr<CefDOMNode> result = nullptr;
		CefString selectors = arguments->GetString(0);
		TestSelector query(root, selectors, false);
		if (query.Find()) {
			CefRefPtr<CefListValue> params = CefListValue::Create();
			std::vector<CefRefPtr<CefDOMNode>> result;
			query.GetAllElement(result);
			if (!result.empty()) {
				for (size_t i = 0; i < result.size(); i++) {
					result[i]->AddRef();
					params->SetInt(i, (int)result[i].get());
				}
				DomSendMessage(frame, IRD_DOCUMENT_RESULT, params, callback);
			}
			else {
				DomSendMessage(frame, IRD_DOCUMENT_RESULT, nullptr, callback);
			}
		}
		else {
			DomSendMessage(frame, IRD_DOCUMENT_RESULT, nullptr, callback);
		}
	}
	else {
		DomSendMessage(frame, IRD_DOCUMENT_RESULT, nullptr, callback);
	}
}

void DomNodeSendEvent(CefRefPtr<CefFrame> frame, uint32_t pointer, CefRefPtr<CefListValue> arguments, uint32_t callback) {
	if (pointer && arguments) {
		CefRefPtr<CefDOMNode> node = (CefDOMNode*)pointer;
		CefRefPtr<CefDOMNode> parent = node->GetParent();
		CefRefPtr<CefDOMNode> child = nullptr;
		CefString name = arguments->GetString(0);
		CefRefPtr<CefListValue> params = nullptr;
		std::vector<std::wstring> paths;
		CefString tag;
		std::wstring mytag = node->GetElementTagName().ToWString();
		wchar_t buffer[128] = L"";
		std::wstringstream selectors;

		if (arguments->GetType(1) != VTYPE_NULL) {
			params = arguments->GetList(1);
		}

		while (parent){
			child = parent->GetFirstChild();
			int count = 0;
			while (child){
				tag = child->GetElementTagName();
				if (!tag.empty()) {
					if (child->IsSame(node)) {
						swprintf_s(buffer, 128, L"%s:nth-child(%d)", mytag.c_str(), count+1);
						paths.push_back(buffer);
						break;
					}
					count++;
				}
				child = child->GetNextSibling();
			}

			node = parent;
			mytag = parent->GetElementTagName();
			parent = parent->GetParent();
		}
		selectors << L"document.querySelector(\"";
		for (int i = paths.size() - 1; i >= 0;i--) {
			selectors << paths[i];
			if (i > 0) {
				selectors << L" > ";
			}
		}
		selectors << L"\")." <<name.ToWString();
		if (!params || params->GetSize() <= 0) {
			selectors << L"();";
		}
		else {
			selectors << L"(";
			for (size_t i = 0; i < params->GetSize(); i++){
				switch (params->GetType(i))
				{
				case VTYPE_NULL:
					selectors << L"null";
					break;
				case VTYPE_BOOL:
					selectors << (params->GetBool(i) ? L"true" : L"false");
					break;
				case VTYPE_INT:
					selectors << params->GetInt(i);
					break;
				case VTYPE_DOUBLE:
					selectors << params->GetDouble(i);
					break;
				case VTYPE_STRING:
					selectors << L"\"" <<params->GetString(i).ToWString() << L"\"";
					break;
				default:
					break;
				}
				if ((i+1) < params->GetSize()) {
					selectors << L",";
				}
			}
			selectors << L");";
		}
		std::wstring s = selectors.str();
		frame->ExecuteJavaScript(s, L"script_url_event", 0);
	}
}
