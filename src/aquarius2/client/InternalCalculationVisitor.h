#pragma once
#include "include/cef_waitable_event.h"
#include "include/cef_values.h"

class InternalCalculationVisitior : public CefBaseRefCounted {
public:
	InternalCalculationVisitior();
	~InternalCalculationVisitior();

public:
	void SetResult(CefRefPtr<CefValue> value);

	void SetException(CefRefPtr<CefValue> value);

	CefRefPtr<CefValue> GetResult(void);

	CefRefPtr<CefValue> GetException(void);

	CefRefPtr<CefWaitableEvent> GetWaitable(void);

	void Awake(void);

	void Wait(void);

	bool IsAwake(void);

public:
	IMPLEMENT_REFCOUNTING(InternalCalculationVisitior);

private:
	CefRefPtr<CefWaitableEvent> _event;
	CefRefPtr<CefValue> _result;
	CefRefPtr<CefValue> _exception;
};