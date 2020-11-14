#pragma once
#include "include/cef_frame.h"
#include "include/cef_dom.h"

class TestDomVisitor : public CefDOMVisitor {
public:
	TestDomVisitor(CefRefPtr<CefFrame> frame, uint32_t pointer);
	~TestDomVisitor();

public:
	virtual void Visit(CefRefPtr<CefDOMDocument> document) OVERRIDE;

public:
	IMPLEMENT_REFCOUNTING(TestDomVisitor);

private:
	CefRefPtr<CefFrame> _domFrame;
	uint32_t _domPointer;
};


