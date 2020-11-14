#pragma once
#include "include/cef_dom.h"
#include "include/cef_task.h"
#include <functional>

class TestThread : public CefTask{
public:
	TestThread(std::function<void(void)> fun);
	~TestThread();

public:
	virtual void Execute() OVERRIDE;

public:
	IMPLEMENT_REFCOUNTING(TestThread);

private:
	std::function<void(void)> _callback;
};

