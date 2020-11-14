#pragma once
#include "include/cef_task.h"
#include "include/cef_waitable_event.h"
#include <functional>

class InternalServerTask : public CefTask {
public:
	InternalServerTask();
	~InternalServerTask();

public:
	CefRefPtr<CefWaitableEvent> Run(CefRefPtr<CefTaskRunner> runner, std::function<void(void)> call);

public:
	virtual void Execute();

public:
	IMPLEMENT_REFCOUNTING(InternalServerTask);

private:
	std::function<void(void)> _call;
	CefRefPtr<CefWaitableEvent> _waitable;
};