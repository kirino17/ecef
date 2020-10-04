#include "InternalStringVisitor.h"
#include <Windows.h>
#include "../def/def.h"

InternalStringVisitor::InternalStringVisitor(CefRefPtr<CefWaitableEvent> waitable, char** stringBuffer):
	_event(waitable),
	_outputBuffer(stringBuffer)
{

}

InternalStringVisitor::~InternalStringVisitor() {
	_event = NULL;
	_outputBuffer = NULL;
}

///
// Method that will be executed.
///
/*--cef(optional_param=string)--*/
void InternalStringVisitor::Visit(const CefString& string) {
	if (string.length() > 0) {
		*_outputBuffer = ToAnsi(string.c_str(), string.length());
	}
	_event->Signal();
}