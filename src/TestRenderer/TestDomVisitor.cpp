#include "TestDomVisitor.h"
#include "TestDomProcess.h"
#include "include/cef_thread.h"
#include "include/cef_app.h"

TestDomVisitor::TestDomVisitor(CefRefPtr<CefFrame> frame, uint32_t pointer):
	_domFrame(frame), _domPointer(pointer)
{

}

TestDomVisitor::~TestDomVisitor() {
	_domFrame = nullptr;
}

void TestDomVisitor::Visit(CefRefPtr<CefDOMDocument> document) {
	document->AddRef();
	CefRefPtr<CefListValue> params = CefListValue::Create();
	params->SetInt(0,(int)document.get());

	DomSendMessage(_domFrame, IRD_DOCUMENT_RESULT, params, _domPointer);
}