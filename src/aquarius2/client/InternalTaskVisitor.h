#pragma once
#include "include/cef_task.h"
#include "../proxy/ProxyClient.h"
#include "include/cef_values.h"

class InternalTaskVisitor : public CefTask {
public:
	InternalTaskVisitor(int taskid ,int threadid, CefRefPtr<CefValue> params);
	~InternalTaskVisitor();

public:
	virtual void Execute() OVERRIDE;


public:
	IMPLEMENT_REFCOUNTING(InternalTaskVisitor);

private:
	int _taskId;
	int _threadId;
	CefRefPtr<CefValue> _params;
};