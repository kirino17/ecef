#include "InternalTaskVisitor.h"

InternalTaskVisitor::InternalTaskVisitor(std::function<void(void)> callback):
	_call(callback)
{

}

InternalTaskVisitor::~InternalTaskVisitor() {
	_call = nullptr;
}

void InternalTaskVisitor::Execute() {
	if (_call) _call();
}