#pragma once
#include "include/cef_string_visitor.h"
#include "include/cef_waitable_event.h"
#include <string>

class InternalStringVisitor : public CefStringVisitor {
public:
	InternalStringVisitor(CefRefPtr<CefWaitableEvent> waitable, char** stringBuffer);
	~InternalStringVisitor();

public:
    ///
	// Method that will be executed.
	///
	/*--cef(optional_param=string)--*/
    virtual void Visit(const CefString& string) OVERRIDE;

public:
	IMPLEMENT_REFCOUNTING(InternalStringVisitor);

private:
	char** _outputBuffer;
	CefRefPtr<CefWaitableEvent> _event;
};