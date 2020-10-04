#include "InternalCalculationVisitor.h"

InternalCalculationVisitior::InternalCalculationVisitior():
	_event(CefWaitableEvent::CreateWaitableEvent(false, false)),
	_result(nullptr),
	_exception(nullptr)
{

}

InternalCalculationVisitior::~InternalCalculationVisitior() {
	_event = nullptr;
	_result = nullptr;
	_exception = nullptr;
}

void InternalCalculationVisitior::SetResult(CefRefPtr<CefValue> value) {
	if (value) {
		_result = value->Copy();
	}
	
}

void InternalCalculationVisitior::SetException(CefRefPtr<CefValue> value) {
	if (value) {
		_exception = value->Copy();
	}
}

CefRefPtr<CefValue> InternalCalculationVisitior::GetResult(void) {
	return _result;
}

CefRefPtr<CefValue> InternalCalculationVisitior::GetException(void) {
	return _exception;
}

CefRefPtr<CefWaitableEvent> InternalCalculationVisitior::GetWaitable(void) {
	return _event;
}

void InternalCalculationVisitior::Awake(void) {
	_event->Signal();
}

void InternalCalculationVisitior::Wait(void) {
	_event->Wait();
}

bool InternalCalculationVisitior::IsAwake(void) {
	return _event->IsSignaled();
}