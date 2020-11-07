#include "InternalServerTask.h"

InternalServerTask::InternalServerTask():
	_call(nullptr),
	_waitable(nullptr)
{

}

InternalServerTask::~InternalServerTask() {
	_waitable = nullptr;
	_call = nullptr;
}


CefRefPtr<CefWaitableEvent> InternalServerTask::Run(CefRefPtr<CefTaskRunner> runner, std::function<void(void)> call) {
	if (!runner) {
		return nullptr;
	}
	_call = call;
	_waitable = CefWaitableEvent::CreateWaitableEvent(false, false);
	runner->PostTask(this);
	return _waitable;
}

void InternalServerTask::Execute() {
	_call();
}