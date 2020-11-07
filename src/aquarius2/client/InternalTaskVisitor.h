#pragma once
#include "include/cef_task.h"
#include <functional>

class InternalTaskVisitor : public CefTask {
public:
	InternalTaskVisitor(std::function<void(void)> callback);
	~InternalTaskVisitor();

public:
	virtual void Execute() OVERRIDE;

public:
	IMPLEMENT_REFCOUNTING(InternalTaskVisitor);

private:
	std::function<void(void)> _call;
};