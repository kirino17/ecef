#include "InternalDOMDocument.h"
#include "InternalCollection.h"
#include "../def/internalDef.h"
#include "../proxy/ProxyDOMNode.h"

InternalDOMDocument::InternalDOMDocument(CefRefPtr<CefFrame> frame, uint32_t pointer):
	_domFrame(frame),_domPointer(pointer), _domEvent(nullptr)
{

}

InternalDOMDocument::~InternalDOMDocument() {
	if (_domFrame && _domFrame->IsValid()) {
		DomSendMessage(_domFrame, IDC_FREE_DOCUMENT, nullptr, _domPointer, nullptr);
	}
}

CefRefPtr<InternalDOMDocument> InternalDOMDocument::GetDocument(CefRefPtr<CefFrame> frame) {
	if (!frame) {
		return nullptr;
	}
	if (NO_CEF_THREAD()) {
		return nullptr;
	}
	CefRefPtr<CefWaitableEvent> waitable = CefWaitableEvent::CreateWaitableEvent(false, false);
	CefRefPtr<InternalDOMDocument> docuemnt = nullptr;
	
	CallResult* callback = new CallResult([&waitable,&docuemnt](CefRefPtr<CefFrame> frame, CefRefPtr<CefListValue> param) {
		if (!param || param->GetSize() == 0) {
			waitable->Signal();
			return;
		}
		docuemnt = new InternalDOMDocument(frame, param->GetInt(0));
		waitable->Signal();
	});

	DomSendMessage(frame, IDC_GET_DOCUMENT, nullptr, 0, callback);
	DomWaitAwaking(frame, waitable);
	return docuemnt;
}

void InternalDOMDocument::OnDomMessageReceived(CefRefPtr<CefFrame> frame, CefRefPtr<CefListValue> arguments) {
	INTERNAL_RESULT_COMMAND command = (INTERNAL_RESULT_COMMAND)arguments->GetInt(0);
	CefRefPtr<CefListValue> params = nullptr;
	CallResult* pointer = (CallResult*)arguments->GetInt(2);

	if (arguments->GetType(1) != VTYPE_NULL) {
		params = arguments->GetList(1);
	}

	if (pointer) {
		(*pointer)(frame, params);
		delete pointer; pointer = nullptr;
	}
}

void InternalDOMDocument::DomSendMessage(CefRefPtr<CefFrame> frame,
	int command, 
	CefRefPtr<CefListValue> params, 
	uint32_t pointer, 
	CallResult* callback) {
	CefRefPtr<CefProcessMessage> message = CefProcessMessage::Create(L"IPC_DOM_MESSAGE");
	CefRefPtr<CefListValue> arguments = message->GetArgumentList();
	arguments->SetInt(0, (int)command);
	if (params) {
		arguments->SetList(1, params);
	}
	else {
		arguments->SetNull(1);
	}
	arguments->SetInt(2, pointer);
	if (callback) {
		arguments->SetInt(3, (int)callback);
	}
	else {
		arguments->SetNull(3);
	}
	frame->SendProcessMessage(PID_RENDERER, message);
}

///
// Returns the type for this node.
///
/*--cef(default_retval=DOM_NODE_TYPE_UNSUPPORTED)--*/
int InternalDOMDocument::GetType() {
	if (NO_CEF_THREAD() || !_domFrame || _domFrame->IsValid() == false) {
		return 0;
	}
	CefRefPtr<CefWaitableEvent> waitable = CefWaitableEvent::CreateWaitableEvent(false, false);
	int result = 0;

	CallResult* callback = new CallResult([&waitable,&result](CefRefPtr<CefFrame> frame, CefRefPtr<CefListValue> param) {
		if (!param || param->GetSize() == 0) {
			waitable->Signal();
			return;
		}
		result = param->GetInt(0);
		waitable->Signal();
	});
	DomSendMessage(_domFrame, IDC_GET_TYPE, nullptr, _domPointer, callback);
	DomWaitAwaking(_domFrame, waitable);
	return result;
}

///
// Returns the root document node.
///
/*--cef()--*/
CefRefPtr<InternalDOMNode> InternalDOMDocument::GetDocument() {
	CefRefPtr<InternalDOMNode> result = nullptr;
	if (NO_CEF_THREAD() || !_domFrame || _domFrame->IsValid() == false) {
		return result;
	}
	CefRefPtr<CefWaitableEvent> waitable = CefWaitableEvent::CreateWaitableEvent(false, false);

	CallResult* callback = new CallResult([&waitable, &result](CefRefPtr<CefFrame> frame, CefRefPtr<CefListValue> param) {
		if (!param || param->GetSize() == 0) {
			waitable->Signal();
			return;
		}

		result = new InternalDOMNode(frame, param->GetInt(0));
		waitable->Signal();
		});
	DomSendMessage(_domFrame, IDC_GET_ROOT, nullptr, _domPointer, callback);
	DomWaitAwaking(_domFrame, waitable);
	return result;
}

///
// Returns the BODY node of an HTML document.
///
/*--cef()--*/
CefRefPtr<InternalDOMNode> InternalDOMDocument::GetBody() {
	CefRefPtr<InternalDOMNode> result = nullptr;
	if (NO_CEF_THREAD() || !_domFrame || _domFrame->IsValid() == false) {
		return result;
	}
	CefRefPtr<CefWaitableEvent> waitable = CefWaitableEvent::CreateWaitableEvent(false, false);

	CallResult* callback = new CallResult([&waitable, &result](CefRefPtr<CefFrame> frame, CefRefPtr<CefListValue> param) {
		if (!param || param->GetSize() == 0) {
			waitable->Signal();
			return;
		}

		result = new InternalDOMNode(frame, param->GetInt(0));
		waitable->Signal();
		});
	DomSendMessage(_domFrame, IDC_GET_BODY, nullptr, _domPointer, callback);
	DomWaitAwaking(_domFrame, waitable);
	return result;
}

///
// Returns the HEAD node of an HTML document.
///
/*--cef()--*/
CefRefPtr<InternalDOMNode> InternalDOMDocument::GetHead() {
	CefRefPtr<InternalDOMNode> result = nullptr;
	if (NO_CEF_THREAD() || !_domFrame || _domFrame->IsValid() == false) {
		return result;
	}
	CefRefPtr<CefWaitableEvent> waitable = CefWaitableEvent::CreateWaitableEvent(false, false);

	CallResult* callback = new CallResult([&waitable, &result](CefRefPtr<CefFrame> frame, CefRefPtr<CefListValue> param) {
		if (!param || param->GetSize() == 0) {
			waitable->Signal();
			return;
		}

		result = new InternalDOMNode(frame, param->GetInt(0));
		waitable->Signal();
		});
	DomSendMessage(_domFrame, IDC_GET_HEAD, nullptr, _domPointer, callback);
	DomWaitAwaking(_domFrame, waitable);
	return result;
}

///
// Returns the title of an HTML document.
///
/*--cef()--*/
CefString InternalDOMDocument::GetTitle() {
	CefString result = "";
	if (NO_CEF_THREAD() || !_domFrame || _domFrame->IsValid() == false) {
		return result;
	}
	CefRefPtr<CefWaitableEvent> waitable = CefWaitableEvent::CreateWaitableEvent(false, false);

	CallResult* callback = new CallResult([&waitable, &result](CefRefPtr<CefFrame> frame, CefRefPtr<CefListValue> param) {
		if (!param || param->GetSize() == 0) {
			waitable->Signal();
			return;
		}
		result = param->GetString(0);
		waitable->Signal();
		});
	DomSendMessage(_domFrame, IDC_GET_TITLE, nullptr, _domPointer, callback);
	DomWaitAwaking(_domFrame, waitable);
	return result;
}

///
// Returns the document element with the specified ID value.
///
/*--cef()--*/
CefRefPtr<InternalDOMNode> InternalDOMDocument::GetElementById(const CefString& id) {
	CefRefPtr<InternalDOMNode> result = nullptr;
	if (NO_CEF_THREAD() || !_domFrame || _domFrame->IsValid() == false) {
		return result;
	}
	if (id.empty()) {
		return result;
	}
	CefRefPtr<CefWaitableEvent> waitable = CefWaitableEvent::CreateWaitableEvent(false, false);

	CallResult* callback = new CallResult([&waitable, &result](CefRefPtr<CefFrame> frame, CefRefPtr<CefListValue> param) {
		if (!param || param->GetSize() == 0) {
			waitable->Signal();
			return;
		}

		result = new InternalDOMNode(frame, param->GetInt(0));
		waitable->Signal();
		});
	CefRefPtr<CefListValue> params = CefListValue::Create();
	params->SetString(0, id);
	DomSendMessage(_domFrame, IDC_GET_ELEMENT_BY_ID, params, _domPointer, callback);
	DomWaitAwaking(_domFrame, waitable);
	return result;
}

///
// Returns the node that currently has keyboard focus.
///
/*--cef()--*/
CefRefPtr<InternalDOMNode> InternalDOMDocument::GetFocusedNode() {
	CefRefPtr<InternalDOMNode> result = nullptr;
	if (NO_CEF_THREAD() || !_domFrame || _domFrame->IsValid() == false) {
		return result;
	}
	CefRefPtr<CefWaitableEvent> waitable = CefWaitableEvent::CreateWaitableEvent(false, false);

	CallResult* callback = new CallResult([&waitable, &result](CefRefPtr<CefFrame> frame, CefRefPtr<CefListValue> param) {
		if (!param || param->GetSize() == 0) {
			waitable->Signal();
			return;
		}

		result = new InternalDOMNode(frame, param->GetInt(0));
		waitable->Signal();
		});
	DomSendMessage(_domFrame, IDC_GET_FOCUSED_NODE, nullptr, _domPointer, callback);
	DomWaitAwaking(_domFrame, waitable);
	return result;
}

///
// Returns true if a portion of the document is selected.
///
/*--cef()--*/
bool InternalDOMDocument::HasSelection() {
	bool result = false;
	if (NO_CEF_THREAD() || !_domFrame || _domFrame->IsValid() == false) {
		return result;
	}
	CefRefPtr<CefWaitableEvent> waitable = CefWaitableEvent::CreateWaitableEvent(false, false);

	CallResult* callback = new CallResult([&waitable, &result](CefRefPtr<CefFrame> frame, CefRefPtr<CefListValue> param) {
		if (!param || param->GetSize() == 0) {
			waitable->Signal();
			return;
		}
		result = param->GetBool(0);
		waitable->Signal();
		});
	DomSendMessage(_domFrame, IDC_HAS_SELECTION, nullptr, _domPointer, callback);
	DomWaitAwaking(_domFrame, waitable);
	return result;
}

///
// Returns the selection offset within the start node.
///
/*--cef()--*/
int InternalDOMDocument::GetSelectionStartOffset() {
	int result = 0;
	if (NO_CEF_THREAD() || !_domFrame || _domFrame->IsValid() == false) {
		return result;
	}
	CefRefPtr<CefWaitableEvent> waitable = CefWaitableEvent::CreateWaitableEvent(false, false);

	CallResult* callback = new CallResult([&waitable, &result](CefRefPtr<CefFrame> frame, CefRefPtr<CefListValue> param) {
		if (!param || param->GetSize() == 0) {
			waitable->Signal();
			return;
		}
		result = param->GetInt(0);
		waitable->Signal();
		});
	DomSendMessage(_domFrame, IDC_GET_SELECTION_START_OFFSET, nullptr, _domPointer, callback);
	DomWaitAwaking(_domFrame, waitable);
	return result;
}

///
// Returns the selection offset within the end node.
///
/*--cef()--*/
int InternalDOMDocument::GetSelectionEndOffset() {
	int result = 0;
	if (NO_CEF_THREAD() || !_domFrame || _domFrame->IsValid() == false) {
		return result;
	}
	CefRefPtr<CefWaitableEvent> waitable = CefWaitableEvent::CreateWaitableEvent(false, false);

	CallResult* callback = new CallResult([&waitable, &result](CefRefPtr<CefFrame> frame, CefRefPtr<CefListValue> param) {
		if (!param || param->GetSize() == 0) {
			waitable->Signal();
			return;
		}
		result = param->GetInt(0);
		waitable->Signal();
		});
	DomSendMessage(_domFrame, IDC_GET_SELECTION_END_OFFSET, nullptr, _domPointer, callback);
	DomWaitAwaking(_domFrame, waitable);
	return result;
}

///
// Returns the contents of this selection as markup.
///
/*--cef()--*/
CefString InternalDOMDocument::GetSelectionAsMarkup() {
	CefString result = L"";
	if (NO_CEF_THREAD() || !_domFrame || _domFrame->IsValid() == false) {
		return result;
	}
	CefRefPtr<CefWaitableEvent> waitable = CefWaitableEvent::CreateWaitableEvent(false, false);

	CallResult* callback = new CallResult([&waitable, &result](CefRefPtr<CefFrame> frame, CefRefPtr<CefListValue> param) {
		if (!param || param->GetSize() == 0) {
			waitable->Signal();
			return;
		}
		result = param->GetString(0);
		waitable->Signal();
		});
	DomSendMessage(_domFrame, IDC_GET_SELECTION_AS_MARKUP, nullptr, _domPointer, callback);
	DomWaitAwaking(_domFrame, waitable);
	return result;
}

///
// Returns the contents of this selection as text.
///
/*--cef()--*/
CefString InternalDOMDocument::GetSelectionAsText() {
	CefString result = L"";
	if (NO_CEF_THREAD() || !_domFrame || _domFrame->IsValid() == false) {
		return result;
	}
	CefRefPtr<CefWaitableEvent> waitable = CefWaitableEvent::CreateWaitableEvent(false, false);

	CallResult* callback = new CallResult([&waitable, &result](CefRefPtr<CefFrame> frame, CefRefPtr<CefListValue> param) {
		if (!param || param->GetSize() == 0) {
			waitable->Signal();
			return;
		}
		result = param->GetString(0);
		waitable->Signal();
		});
	DomSendMessage(_domFrame, IDC_GET_SELECTION_AS_TEXT, nullptr, _domPointer, callback);
	DomWaitAwaking(_domFrame, waitable);
	return result;
}

///
// Returns the base URL for the document.
///
/*--cef()--*/
CefString InternalDOMDocument::GetBaseURL() {
	CefString result = L"";
	if (NO_CEF_THREAD() || !_domFrame || _domFrame->IsValid() == false) {
		return result;
	}
	CefRefPtr<CefWaitableEvent> waitable = CefWaitableEvent::CreateWaitableEvent(false, false);

	CallResult* callback = new CallResult([&waitable, &result](CefRefPtr<CefFrame> frame, CefRefPtr<CefListValue> param) {
		if (!param || param->GetSize() == 0) {
			waitable->Signal();
			return;
		}
		result = param->GetString(0);
		waitable->Signal();
		});
	DomSendMessage(_domFrame, IDC_GET_BASE_URL, nullptr, _domPointer, callback);
	DomWaitAwaking(_domFrame, waitable);
	return result;
}

///
// Returns a complete URL based on the document base URL and the specified
// partial URL.
///
/*--cef()--*/
CefString InternalDOMDocument::GetCompleteURL(const CefString& partialURL) {
	CefString result = L"";
	if (NO_CEF_THREAD() || !_domFrame || _domFrame->IsValid() == false) {
		return result;
	}
	CefRefPtr<CefWaitableEvent> waitable = CefWaitableEvent::CreateWaitableEvent(false, false);

	CallResult* callback = new CallResult([&waitable, &result](CefRefPtr<CefFrame> frame, CefRefPtr<CefListValue> param) {
		if (!param || param->GetSize() == 0) {
			waitable->Signal();
			return;
		}
		result = param->GetString(0);
		waitable->Signal();
		});
	CefRefPtr<CefListValue> params = CefListValue::Create();
	params->SetString(0, partialURL);

	DomSendMessage(_domFrame, IDC_GET_COMPLETE_URL, params, _domPointer, callback);
	DomWaitAwaking(_domFrame, waitable);
	return result;
}

///
// query selector
///
/*--cef()--*/
CefRefPtr<InternalDOMNode> InternalDOMDocument::QuerySelector(const CefString& selectors) {
	CefRefPtr<InternalDOMNode> result = nullptr;
	if (NO_CEF_THREAD() || !_domFrame || _domFrame->IsValid() == false) {
		return result;
	}
	CefRefPtr<CefWaitableEvent> waitable = CefWaitableEvent::CreateWaitableEvent(false, false);
	CallResult* callback = new CallResult([&waitable, &result](CefRefPtr<CefFrame> frame, CefRefPtr<CefListValue> param) {
		if (!param || param->GetSize() == 0) {
			waitable->Signal();
			return;
		}
		result = new InternalDOMNode(frame, param->GetInt(0));
		waitable->Signal();
		});
	CefRefPtr<CefListValue> params = CefListValue::Create();
	params->SetString(0, selectors);

	DomSendMessage(_domFrame, IDC_QUERY_SELECTOR, params, _domPointer, callback);
	DomWaitAwaking(_domFrame, waitable);
	return result;
}

///
// query selector all
///
/*--cef()--*/
void** InternalDOMDocument::QuerySelectorAll(const CefString& selectors) {
	void** result = nullptr;
	if (NO_CEF_THREAD() || !_domFrame || _domFrame->IsValid() == false) {
		DWORD* pointer = (DWORD*)NewBuffer(sizeof(INT) * (2));
		*(pointer + 0) = 1;
		*(pointer + 1) = 0;
		return (void**)pointer;
	}
	CefRefPtr<CefWaitableEvent> waitable = CefWaitableEvent::CreateWaitableEvent(false, false);
	CallResult* callback = new CallResult([&waitable, &result](CefRefPtr<CefFrame> frame, CefRefPtr<CefListValue> param) {
		if (!param || param->GetSize() == 0) {
			DWORD* pointer = (DWORD*)NewBuffer(sizeof(INT) * (2));
			*(pointer + 0) = 1;
			*(pointer + 1) = 0;
			result = (void**)pointer;
			waitable->Signal();
			return;
		}
		int count = param->GetSize();
		DWORD* pointer = (DWORD*)NewBuffer(sizeof(INT) * (2 + count));
		*(pointer + 0) = 1;
		*(pointer + 1) = count;
		CefRefPtr<InternalDOMNode> node = nullptr;
		shrewd_ptr<ProxyDOMNode> forward = nullptr;
		for (size_t i = 0; i < count; i++){
			node = new InternalDOMNode(frame, param->GetInt(i));
			forward = new ProxyDOMNode(node);
			forward->retain();
			DWORD* InternalPointer = (DWORD*)NewBuffer(sizeof(DWORD));
			*InternalPointer = (DWORD)forward.get();
			*(pointer + i + 2) = (DWORD)InternalPointer;
		}
		result = (void**)pointer;
		waitable->Signal();
		});
	CefRefPtr<CefListValue> params = CefListValue::Create();
	params->SetString(0, selectors);

	DomSendMessage(_domFrame, IDC_QUERY_SELECTOR_ALL, params, _domPointer, callback);
	DomWaitAwaking(_domFrame, waitable);
	return result;
}

InternalDOMNode::InternalDOMNode(CefRefPtr<CefFrame> frame, uint32_t pointer):
	_domFrame(frame),_domPointer(pointer)
{

}

InternalDOMNode::~InternalDOMNode() {
	if (_domFrame && _domFrame->IsValid()) {
		InternalDOMDocument::DomSendMessage(_domFrame, INC_NODE_FREE, nullptr, _domPointer, nullptr);
	}
	_domFrame = nullptr;
	_domPointer = 0;
}

///
// Returns the type for this node.
///
/*--cef(default_retval=DOM_NODE_TYPE_UNSUPPORTED)--*/
int InternalDOMNode::GetType() {
	int result = 0;
	if (NO_CEF_THREAD() || !_domFrame || _domFrame->IsValid() == false) {
		return result;
	}
	CefRefPtr<CefWaitableEvent> waitable = CefWaitableEvent::CreateWaitableEvent(false, false);

	CallResult* callback = new CallResult([&waitable, &result](CefRefPtr<CefFrame> frame, CefRefPtr<CefListValue> param) {
		if (!param || param->GetSize() == 0) {
			waitable->Signal();
			return;
		}
		result = param->GetInt(0);
		waitable->Signal();
		});

	InternalDOMDocument::DomSendMessage(_domFrame, INC_NODE_GET_TYPE, nullptr, _domPointer, callback);
	DomWaitAwaking(_domFrame, waitable);
	return result;
}

///
// Returns true if this is a text node.
///
bool InternalDOMNode::IsText() {
	bool result = 0;
	if (NO_CEF_THREAD() || !_domFrame || _domFrame->IsValid() == false) {
		return result;
	}
	CefRefPtr<CefWaitableEvent> waitable = CefWaitableEvent::CreateWaitableEvent(false, false);

	CallResult* callback = new CallResult([&waitable, &result](CefRefPtr<CefFrame> frame, CefRefPtr<CefListValue> param) {
		if (!param || param->GetSize() == 0) {
			waitable->Signal();
			return;
		}
		result = param->GetBool(0);
		waitable->Signal();
		});

	InternalDOMDocument::DomSendMessage(_domFrame, INC_NODE_IS_TEXT, nullptr, _domPointer, callback);
	DomWaitAwaking(_domFrame, waitable);
	return result;
}

///
// Returns true if this is an element node.
///
/*--cef()--*/
bool InternalDOMNode::IsElement() {
	bool result = 0;
	if (NO_CEF_THREAD() || !_domFrame || _domFrame->IsValid() == false) {
		return result;
	}
	CefRefPtr<CefWaitableEvent> waitable = CefWaitableEvent::CreateWaitableEvent(false, false);

	CallResult* callback = new CallResult([&waitable, &result](CefRefPtr<CefFrame> frame, CefRefPtr<CefListValue> param) {
		if (!param || param->GetSize() == 0) {
			waitable->Signal();
			return;
		}
		result = param->GetBool(0);
		waitable->Signal();
		});

	InternalDOMDocument::DomSendMessage(_domFrame, INC_NODE_IS_ELEMENT, nullptr, _domPointer, callback);
	DomWaitAwaking(_domFrame, waitable);
	return result;
}

///
// Returns true if this is an editable node.
///
/*--cef()--*/
bool InternalDOMNode::IsEditable() {
	bool result = 0;
	if (NO_CEF_THREAD() || !_domFrame || _domFrame->IsValid() == false) {
		return result;
	}
	CefRefPtr<CefWaitableEvent> waitable = CefWaitableEvent::CreateWaitableEvent(false, false);

	CallResult* callback = new CallResult([&waitable, &result](CefRefPtr<CefFrame> frame, CefRefPtr<CefListValue> param) {
		if (!param || param->GetSize() == 0) {
			waitable->Signal();
			return;
		}
		result = param->GetBool(0);
		waitable->Signal();
		});

	InternalDOMDocument::DomSendMessage(_domFrame, INC_NODE_IS_EDITABLE, nullptr, _domPointer, callback);
	DomWaitAwaking(_domFrame, waitable);
	return result;
}

///
// Returns true if this is a form control element node.
///
/*--cef()--*/
bool InternalDOMNode::IsFormControlElement() {
	bool result = 0;
	if (NO_CEF_THREAD() || !_domFrame || _domFrame->IsValid() == false) {
		return result;
	}
	CefRefPtr<CefWaitableEvent> waitable = CefWaitableEvent::CreateWaitableEvent(false, false);

	CallResult* callback = new CallResult([&waitable, &result](CefRefPtr<CefFrame> frame, CefRefPtr<CefListValue> param) {
		if (!param || param->GetSize() == 0) {
			waitable->Signal();
			return;
		}
		result = param->GetBool(0);
		waitable->Signal();
		});

	InternalDOMDocument::DomSendMessage(_domFrame, INC_NODE_IS_FORM_CONTROL_ELEMENT, nullptr, _domPointer, callback);
	DomWaitAwaking(_domFrame, waitable);
	return result;
}

///
// Returns the type of this form control element node.
///
/*--cef()--*/
CefString InternalDOMNode::GetFormControlElementType() {
	CefString result = L"";
	if (NO_CEF_THREAD() || !_domFrame || _domFrame->IsValid() == false) {
		return result;
	}
	CefRefPtr<CefWaitableEvent> waitable = CefWaitableEvent::CreateWaitableEvent(false, false);

	CallResult* callback = new CallResult([&waitable, &result](CefRefPtr<CefFrame> frame, CefRefPtr<CefListValue> param) {
		if (!param || param->GetSize() == 0) {
			waitable->Signal();
			return;
		}
		result = param->GetString(0);
		waitable->Signal();
		});

	InternalDOMDocument::DomSendMessage(_domFrame, INC_NODE_GET_FORM_CONTROL_ELEMENT_TYPE, nullptr, _domPointer, callback);
	DomWaitAwaking(_domFrame, waitable);
	return result;
}

///
// Returns the name of this node.
///
/*--cef()--*/
CefString InternalDOMNode::GetName() {
	CefString result = L"";
	if (NO_CEF_THREAD() || !_domFrame || _domFrame->IsValid() == false) {
		return result;
	}
	CefRefPtr<CefWaitableEvent> waitable = CefWaitableEvent::CreateWaitableEvent(false, false);

	CallResult* callback = new CallResult([&waitable, &result](CefRefPtr<CefFrame> frame, CefRefPtr<CefListValue> param) {
		if (!param || param->GetSize() == 0) {
			waitable->Signal();
			return;
		}
		result = param->GetString(0);
		waitable->Signal();
		});

	InternalDOMDocument::DomSendMessage(_domFrame, INC_NODE_GET_NAME, nullptr, _domPointer, callback);
	DomWaitAwaking(_domFrame, waitable);
	return result;
}

///
// Returns the value of this node.
///
/*--cef()--*/
CefString InternalDOMNode::GetValue() {
	CefString result = L"";
	if (NO_CEF_THREAD() || !_domFrame || _domFrame->IsValid() == false) {
		return result;
	}
	CefRefPtr<CefWaitableEvent> waitable = CefWaitableEvent::CreateWaitableEvent(false, false);

	CallResult* callback = new CallResult([&waitable, &result](CefRefPtr<CefFrame> frame, CefRefPtr<CefListValue> param) {
		if (!param || param->GetSize() == 0) {
			waitable->Signal();
			return;
		}
		result = param->GetString(0);
		waitable->Signal();
		});

	InternalDOMDocument::DomSendMessage(_domFrame, INC_NODE_GET_VALUE, nullptr, _domPointer, callback);
	DomWaitAwaking(_domFrame, waitable);
	return result;
}

///
// Set the value of this node. Returns true on success.
///
/*--cef()--*/
bool InternalDOMNode::SetValue(const CefString& value) {
	bool result = false;
	if (NO_CEF_THREAD() || !_domFrame || _domFrame->IsValid() == false) {
		return result;
	}
	CefRefPtr<CefWaitableEvent> waitable = CefWaitableEvent::CreateWaitableEvent(false, false);

	CallResult* callback = new CallResult([&waitable, &result](CefRefPtr<CefFrame> frame, CefRefPtr<CefListValue> param) {
		if (!param || param->GetSize() == 0) {
			waitable->Signal();
			return;
		}
		result = param->GetBool(0);
		waitable->Signal();
		});
	CefRefPtr<CefListValue> params = CefListValue::Create();
	params->SetString(0, value);
	InternalDOMDocument::DomSendMessage(_domFrame, INC_NODE_SET_VALUE, params, _domPointer, callback);
	DomWaitAwaking(_domFrame, waitable);
	return result;
}

///
// Returns the contents of this node as markup.
///
/*--cef()--*/
CefString InternalDOMNode::GetAsMarkup() {
	CefString result = L"";
	if (NO_CEF_THREAD() || !_domFrame || _domFrame->IsValid() == false) {
		return result;
	}
	CefRefPtr<CefWaitableEvent> waitable = CefWaitableEvent::CreateWaitableEvent(false, false);

	CallResult* callback = new CallResult([&waitable, &result](CefRefPtr<CefFrame> frame, CefRefPtr<CefListValue> param) {
		if (!param || param->GetSize() == 0) {
			waitable->Signal();
			return;
		}
		result = param->GetString(0);
		waitable->Signal();
		});

	InternalDOMDocument::DomSendMessage(_domFrame, INC_NODE_GET_AS_MARKUP, nullptr, _domPointer, callback);
	DomWaitAwaking(_domFrame, waitable);
	return result;
}

///
// Returns the document associated with this node.
///
/*--cef()--*/
CefRefPtr<InternalDOMDocument> InternalDOMNode::GetDocument() {
	CefRefPtr<InternalDOMDocument> result = nullptr;
	if (NO_CEF_THREAD() || !_domFrame || _domFrame->IsValid() == false) {
		return result;
	}
	CefRefPtr<CefWaitableEvent> waitable = CefWaitableEvent::CreateWaitableEvent(false, false);

	CallResult* callback = new CallResult([&waitable, &result](CefRefPtr<CefFrame> frame, CefRefPtr<CefListValue> param) {
		if (!param || param->GetSize() == 0) {
			waitable->Signal();
			return;
		}
		result = new InternalDOMDocument(frame, param->GetInt(0));
		waitable->Signal();
		});

	InternalDOMDocument::DomSendMessage(_domFrame, INC_NODE_GET_DOCUMENT, nullptr, _domPointer, callback);
	DomWaitAwaking(_domFrame, waitable);
	return result;
}

///
// Returns the parent node.
///
/*--cef()--*/
CefRefPtr<InternalDOMNode> InternalDOMNode::GetParent() {
	CefRefPtr<InternalDOMNode> result = nullptr;
	if (NO_CEF_THREAD() || !_domFrame || _domFrame->IsValid() == false) {
		return result;
	}
	CefRefPtr<CefWaitableEvent> waitable = CefWaitableEvent::CreateWaitableEvent(false, false);

	CallResult* callback = new CallResult([&waitable, &result](CefRefPtr<CefFrame> frame, CefRefPtr<CefListValue> param) {
		if (!param || param->GetSize() == 0) {
			waitable->Signal();
			return;
		}
		result = new InternalDOMNode(frame, param->GetInt(0));
		waitable->Signal();
		});

	InternalDOMDocument::DomSendMessage(_domFrame, INC_NODE_GET_PARENT, nullptr, _domPointer, callback);
	DomWaitAwaking(_domFrame, waitable);
	return result;
}

///
// Returns the previous sibling node.
///
/*--cef()--*/
CefRefPtr<InternalDOMNode> InternalDOMNode::GetPreviousSibling() {
	CefRefPtr<InternalDOMNode> result = nullptr;
	if (NO_CEF_THREAD() || !_domFrame || _domFrame->IsValid() == false) {
		return result;
	}
	CefRefPtr<CefWaitableEvent> waitable = CefWaitableEvent::CreateWaitableEvent(false, false);

	CallResult* callback = new CallResult([&waitable, &result](CefRefPtr<CefFrame> frame, CefRefPtr<CefListValue> param) {
		if (!param || param->GetSize() == 0) {
			waitable->Signal();
			return;
		}
		result = new InternalDOMNode(frame, param->GetInt(0));
		waitable->Signal();
		});

	InternalDOMDocument::DomSendMessage(_domFrame, INC_NODE_PREV_SIBLING, nullptr, _domPointer, callback);
	DomWaitAwaking(_domFrame, waitable);
	return result;
}

///
// Returns the next sibling node.
///
/*--cef()--*/
CefRefPtr<InternalDOMNode> InternalDOMNode::GetNextSibling() {
	CefRefPtr<InternalDOMNode> result = nullptr;
	if (NO_CEF_THREAD() || !_domFrame || _domFrame->IsValid() == false) {
		return result;
	}
	CefRefPtr<CefWaitableEvent> waitable = CefWaitableEvent::CreateWaitableEvent(false, false);

	CallResult* callback = new CallResult([&waitable, &result](CefRefPtr<CefFrame> frame, CefRefPtr<CefListValue> param) {
		if (!param || param->GetSize() == 0) {
			waitable->Signal();
			return;
		}
		result = new InternalDOMNode(frame, param->GetInt(0));
		waitable->Signal();
		});

	InternalDOMDocument::DomSendMessage(_domFrame, INC_NODE_NEXT_SIBLING, nullptr, _domPointer, callback);
	DomWaitAwaking(_domFrame, waitable);
	return result;
}

///
// Returns true if this node has child nodes.
///
/*--cef()--*/
bool InternalDOMNode::HasChildren() {
	bool result = false;
	if (NO_CEF_THREAD() || !_domFrame || _domFrame->IsValid() == false) {
		return result;
	}
	CefRefPtr<CefWaitableEvent> waitable = CefWaitableEvent::CreateWaitableEvent(false, false);

	CallResult* callback = new CallResult([&waitable, &result](CefRefPtr<CefFrame> frame, CefRefPtr<CefListValue> param) {
		if (!param || param->GetSize() == 0) {
			waitable->Signal();
			return;
		}
		result = param->GetBool(0);
		waitable->Signal();
		});

	InternalDOMDocument::DomSendMessage(_domFrame, INC_NODE_HAS_CHILDREN, nullptr, _domPointer, callback);
	DomWaitAwaking(_domFrame, waitable);
	return result;
}

///
// Return the first child node.
///
/*--cef()--*/
CefRefPtr<InternalDOMNode> InternalDOMNode::GetFirstChild() {
	CefRefPtr<InternalDOMNode> result = false;
	if (NO_CEF_THREAD() || !_domFrame || _domFrame->IsValid() == false) {
		return result;
	}
	CefRefPtr<CefWaitableEvent> waitable = CefWaitableEvent::CreateWaitableEvent(false, false);

	CallResult* callback = new CallResult([&waitable, &result](CefRefPtr<CefFrame> frame, CefRefPtr<CefListValue> param) {
		if (!param || param->GetSize() == 0) {
			waitable->Signal();
			return;
		}
		result = new InternalDOMNode(frame, param->GetInt(0));
		waitable->Signal();
		});

	InternalDOMDocument::DomSendMessage(_domFrame, INC_NODE_GET_FIRST_CHILD, nullptr, _domPointer, callback);
	DomWaitAwaking(_domFrame, waitable);
	return result;
}

///
// Returns the last child node.
///
/*--cef()--*/
CefRefPtr<InternalDOMNode> InternalDOMNode::GetLastChild() {
	CefRefPtr<InternalDOMNode> result = false;
	if (NO_CEF_THREAD() || !_domFrame || _domFrame->IsValid() == false) {
		return result;
	}
	CefRefPtr<CefWaitableEvent> waitable = CefWaitableEvent::CreateWaitableEvent(false, false);

	CallResult* callback = new CallResult([&waitable, &result](CefRefPtr<CefFrame> frame, CefRefPtr<CefListValue> param) {
		if (!param || param->GetSize() == 0) {
			waitable->Signal();
			return;
		}
		result = new InternalDOMNode(frame, param->GetInt(0));
		waitable->Signal();
		});

	InternalDOMDocument::DomSendMessage(_domFrame, INC_NODE_GET_LAST_CHILD, nullptr, _domPointer, callback);
	DomWaitAwaking(_domFrame, waitable);
	return result;
}

///
// Returns the tag name of this element.
///
/*--cef()--*/
CefString InternalDOMNode::GetElementTagName() {
	CefString result = L"";
	if (NO_CEF_THREAD() || !_domFrame || _domFrame->IsValid() == false) {
		return result;
	}
	CefRefPtr<CefWaitableEvent> waitable = CefWaitableEvent::CreateWaitableEvent(false, false);

	CallResult* callback = new CallResult([&waitable, &result](CefRefPtr<CefFrame> frame, CefRefPtr<CefListValue> param) {
		if (!param || param->GetSize() == 0) {
			waitable->Signal();
			return;
		}
		result = param->GetString(0);
		waitable->Signal();
		});

	InternalDOMDocument::DomSendMessage(_domFrame, INC_NODE_GET_ELEMENT_TAG_NAME, nullptr, _domPointer, callback);
	DomWaitAwaking(_domFrame, waitable);
	return result;
}

///
// Returns true if this element has attributes.
///
/*--cef()--*/
bool InternalDOMNode::HasElementAttributes() {
	bool result = false;
	if (NO_CEF_THREAD() || !_domFrame || _domFrame->IsValid() == false) {
		return result;
	}
	CefRefPtr<CefWaitableEvent> waitable = CefWaitableEvent::CreateWaitableEvent(false, false);

	CallResult* callback = new CallResult([&waitable, &result](CefRefPtr<CefFrame> frame, CefRefPtr<CefListValue> param) {
		if (!param || param->GetSize() == 0) {
			waitable->Signal();
			return;
		}
		result = param->GetBool(0);
		waitable->Signal();
		});

	InternalDOMDocument::DomSendMessage(_domFrame, INC_NODE_HAS_ELEMENT_ATTRIBUTES, nullptr, _domPointer, callback);
	DomWaitAwaking(_domFrame, waitable);
	return result;
}

///
// Returns true if this element has an attribute named |attrName|.
///
/*--cef()--*/
bool InternalDOMNode::HasElementAttribute(const CefString& attrName) {
	bool result = false;
	if (NO_CEF_THREAD() || !_domFrame || _domFrame->IsValid() == false) {
		return result;
	}
	CefRefPtr<CefWaitableEvent> waitable = CefWaitableEvent::CreateWaitableEvent(false, false);

	CallResult* callback = new CallResult([&waitable, &result](CefRefPtr<CefFrame> frame, CefRefPtr<CefListValue> param) {
		if (!param || param->GetSize() == 0) {
			waitable->Signal();
			return;
		}
		result = param->GetBool(0);
		waitable->Signal();
		});
	CefRefPtr<CefListValue> param = CefListValue::Create();
	param->SetString(0, attrName);
	InternalDOMDocument::DomSendMessage(_domFrame, INC_NODE_HAS_ELEMENT_ATTRIBUTES, param, _domPointer, callback);
	DomWaitAwaking(_domFrame, waitable);
	return result;
}

///
// Returns the element attribute named |attrName|.
///
/*--cef()--*/
CefString InternalDOMNode::GetElementAttribute(const CefString& attrName) {
	CefString result = L"";
	if (NO_CEF_THREAD() || !_domFrame || _domFrame->IsValid() == false) {
		return result;
	}
	CefRefPtr<CefWaitableEvent> waitable = CefWaitableEvent::CreateWaitableEvent(false, false);

	CallResult* callback = new CallResult([&waitable, &result](CefRefPtr<CefFrame> frame, CefRefPtr<CefListValue> param) {
		if (!param || param->GetSize() == 0) {
			waitable->Signal();
			return;
		}
		result = param->GetString(0);
		waitable->Signal();
		});
	CefRefPtr<CefListValue> param = CefListValue::Create();
	param->SetString(0, attrName);
	InternalDOMDocument::DomSendMessage(_domFrame, INC_NODE_GET_ELEMENT_ATTRIBUTE, param, _domPointer, callback);
	DomWaitAwaking(_domFrame, waitable);
	return result;
}

///
// Returns a map of all element attributes.
///
/*--cef()--*/
void InternalDOMNode::GetElementAttributes(CefRefPtr<CefDictionaryValue>& attrMap) {
	if (NO_CEF_THREAD() || !_domFrame || _domFrame->IsValid() == false) {
		return ;
	}
	CefRefPtr<CefWaitableEvent> waitable = CefWaitableEvent::CreateWaitableEvent(false, false);

	CallResult* callback = new CallResult([&waitable, &attrMap](CefRefPtr<CefFrame> frame, CefRefPtr<CefListValue> param) {
		if (!param || param->GetSize() == 0) {
			waitable->Signal();
			return;
		}
		CefRefPtr<CefDictionaryValue> dict = param->GetDictionary(0);
		attrMap = dict->Copy(true);
		waitable->Signal();
	});
	InternalDOMDocument::DomSendMessage(_domFrame, INC_NODE_GET_ELEMENT_ATTRIBUTES, nullptr, _domPointer, callback);
	DomWaitAwaking(_domFrame, waitable);

	return ;
}

///
// Set the value for the element attribute named |attrName|. Returns true on
// success.
///
/*--cef()--*/
bool InternalDOMNode::SetElementAttribute(const CefString& attrName,
	const CefString& value) {
	bool result = false;
	if (NO_CEF_THREAD() || !_domFrame || _domFrame->IsValid() == false) {
		return result;
	}
	CefRefPtr<CefWaitableEvent> waitable = CefWaitableEvent::CreateWaitableEvent(false, false);

	CallResult* callback = new CallResult([&waitable, &result](CefRefPtr<CefFrame> frame, CefRefPtr<CefListValue> param) {
		if (!param || param->GetSize() == 0) {
			waitable->Signal();
			return;
		}
		result = param->GetBool(0);
		waitable->Signal();
		});
	CefRefPtr<CefListValue> param = CefListValue::Create();
	param->SetString(0, attrName);
	param->SetString(1, value);
	InternalDOMDocument::DomSendMessage(_domFrame, INC_NODE_SET_ELEMENT_ATTRIBUTE, param, _domPointer, callback);
	DomWaitAwaking(_domFrame, waitable);
	return result;
}

///
// Returns the inner text of the element.
///
/*--cef()--*/
CefString InternalDOMNode::GetElementInnerText() {
	CefString result = L"";
	if (NO_CEF_THREAD() || !_domFrame || _domFrame->IsValid() == false) {
		return result;
	}
	CefRefPtr<CefWaitableEvent> waitable = CefWaitableEvent::CreateWaitableEvent(false, false);

	CallResult* callback = new CallResult([&waitable, &result](CefRefPtr<CefFrame> frame, CefRefPtr<CefListValue> param) {
		if (!param || param->GetSize() == 0) {
			waitable->Signal();
			return;
		}
		result = param->GetString(0);
		waitable->Signal();
		});
	InternalDOMDocument::DomSendMessage(_domFrame, INC_NODE_GET_ELEMENT_INNER_TEXT, nullptr, _domPointer, callback);
	DomWaitAwaking(_domFrame, waitable);
	return result;
}

///
// Returns the bounds of the element.
///
/*--cef()--*/
int** InternalDOMNode::GetElementBounds() {
	int** result = nullptr;
	if (NO_CEF_THREAD() || !_domFrame || _domFrame->IsValid() == false) {
		DWORD* pointer = (DWORD*)NewBuffer(sizeof(INT) * (2));
		*(pointer + 0) = 1;
		*(pointer + 1) = 0;
		return (int**)pointer;
	}
	CefRefPtr<CefWaitableEvent> waitable = CefWaitableEvent::CreateWaitableEvent(false, false);

	CallResult* callback = new CallResult([&waitable, &result](CefRefPtr<CefFrame> frame, CefRefPtr<CefListValue> param) {
		if (!param || param->GetSize() == 0) {
			DWORD* pointer = (DWORD*)NewBuffer(sizeof(INT) * (2));
			*(pointer + 0) = 1;
			*(pointer + 1) = 0;
			result = (int**)pointer;
			waitable->Signal();
			return;
		}
		DWORD* pointer = (DWORD*)NewBuffer(sizeof(INT) * (6));
		*(pointer + 0) = 1;
		*(pointer + 1) = 4;
		*(pointer + 2) = param->GetInt(0);
		*(pointer + 3) = param->GetInt(1);
		*(pointer + 4) = param->GetInt(2);
		*(pointer + 5) = param->GetInt(3);
		result = (int**)pointer;
		waitable->Signal();
	});
	InternalDOMDocument::DomSendMessage(_domFrame, INC_NODE_GET_ELEMENT_BOUNDS, nullptr, _domPointer, callback);
	DomWaitAwaking(_domFrame, waitable);
	return result;
}

bool InternalDOMDocument::IsValid() {
	return _domFrame->IsValid();
}

bool InternalDOMNode::IsValid() {
	return _domFrame->IsValid();
}

void InternalDOMNode::SendEvent(const CefString& name, CefRefPtr<CefListValue> arguments) {
	if (NO_CEF_THREAD() || !_domFrame || _domFrame->IsValid() == false) {
		return;
	}
	CefRefPtr<CefListValue> params = CefListValue::Create();
	params->SetString(0, name);
	if (arguments) {
		params->SetList(1, arguments);
	}
	else {
		params->SetNull(1);
	}
	InternalDOMDocument::DomSendMessage(_domFrame, INC_NODE_SEND_EVENT, params, _domPointer, nullptr);
}

CefRefPtr<InternalDOMNode> InternalDOMNode::QuerySelector(const CefString& selectors) {
	CefRefPtr<InternalDOMNode> result = nullptr;
	if (NO_CEF_THREAD() || !_domFrame || _domFrame->IsValid() == false) {
		return result;
	}
	CefRefPtr<CefWaitableEvent> waitable = CefWaitableEvent::CreateWaitableEvent(false, false);
	CallResult* callback = new CallResult([&waitable, &result](CefRefPtr<CefFrame> frame, CefRefPtr<CefListValue> param) {
		if (!param || param->GetSize() == 0) {
			waitable->Signal();
			return;
		}
		result = new InternalDOMNode(frame, param->GetInt(0));
		waitable->Signal();
	});
	CefRefPtr<CefListValue> params = CefListValue::Create();
	params->SetString(0, selectors);

	InternalDOMDocument::DomSendMessage(_domFrame, INC_NODE_QUERY_SELECTOR, params, _domPointer, callback);
	DomWaitAwaking(_domFrame, waitable);
	return result;
}

void** InternalDOMNode::QuerySelectorAll(const CefString& selectors) {
	void** result = nullptr;
	if (NO_CEF_THREAD() || !_domFrame || _domFrame->IsValid() == false) {
		DWORD* pointer = (DWORD*)NewBuffer(sizeof(INT) * (2));
		*(pointer + 0) = 1;
		*(pointer + 1) = 0;
		return (void**)pointer;
	}
	CefRefPtr<CefWaitableEvent> waitable = CefWaitableEvent::CreateWaitableEvent(false, false);
	CallResult* callback = new CallResult([&waitable, &result](CefRefPtr<CefFrame> frame, CefRefPtr<CefListValue> param) {
		if (!param || param->GetSize() == 0) {
			DWORD* pointer = (DWORD*)NewBuffer(sizeof(INT) * (2));
			*(pointer + 0) = 1;
			*(pointer + 1) = 0;
			result = (void**)pointer;
			waitable->Signal();
			return;
		}
		int count = param->GetSize();
		DWORD* pointer = (DWORD*)NewBuffer(sizeof(INT) * (2 + count));
		*(pointer + 0) = 1;
		*(pointer + 1) = count;
		CefRefPtr<InternalDOMNode> node = nullptr;
		shrewd_ptr<ProxyDOMNode> forward = nullptr;
		for (size_t i = 0; i < count; i++) {
			node = new InternalDOMNode(frame, param->GetInt(i));
			forward = new ProxyDOMNode(node);
			forward->retain();
			DWORD* InternalPointer = (DWORD*)NewBuffer(sizeof(DWORD));
			*InternalPointer = (DWORD)forward.get();
			*(pointer + i + 2) = (DWORD)InternalPointer;
		}
		result = (void**)pointer;
		waitable->Signal();
	});
	CefRefPtr<CefListValue> params = CefListValue::Create();
	params->SetString(0, selectors);

	InternalDOMDocument::DomSendMessage(_domFrame, INC_NODE_QUERY_SELECTOR_ALL, params, _domPointer, callback);
	DomWaitAwaking(_domFrame, waitable);
	return result;
}

int InternalDOMNode::GetChildCount() {
	int result = 0;
	if (NO_CEF_THREAD() || !_domFrame || _domFrame->IsValid() == false) {
		return result;
	}
	CefRefPtr<CefWaitableEvent> waitable = CefWaitableEvent::CreateWaitableEvent(false, false);
	CallResult* callback = new CallResult([&waitable, &result](CefRefPtr<CefFrame> frame, CefRefPtr<CefListValue> param) {
		if (!param || param->GetSize() == 0) {
			waitable->Signal();
			return;
		}
		result = param->GetInt(0);
		waitable->Signal();
	});
	InternalDOMDocument::DomSendMessage(_domFrame, INC_NODE_GET_CHILD_COUNT, nullptr, _domPointer, callback);
	DomWaitAwaking(_domFrame, waitable);
	return result;
}

char* InternalDOMNode::GetSelector() {
	char* result = nullptr;
	if (NO_CEF_THREAD() || !_domFrame || _domFrame->IsValid() == false) {
		return result;
	}
	CefRefPtr<CefWaitableEvent> waitable = CefWaitableEvent::CreateWaitableEvent(false, false);
	CallResult* callback = new CallResult([&waitable, &result](CefRefPtr<CefFrame> frame, CefRefPtr<CefListValue> param) {
		if (!param || param->GetSize() == 0) {
			waitable->Signal();
			return;
		}
		CefString string = param->GetString(0);
		if (!string.empty()) {
			result = ToAnsi(string.c_str(), string.length());
		}
		waitable->Signal();
		});
	InternalDOMDocument::DomSendMessage(_domFrame, INC_NODE_GET_SELECTOR, nullptr, _domPointer, callback);
	DomWaitAwaking(_domFrame, waitable);
	return result;
}