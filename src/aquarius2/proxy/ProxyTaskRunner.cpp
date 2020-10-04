#include "ProxyTaskRunner.h"
#include "include/cef_task.h"
#include "include/cef_values.h"
#include "include/cef_app.h"
#include "../client/InternalTaskVisitor.h"

ProxyTaskRunner::ProxyTaskRunner(void* ptr, int threadId) :_rawptr(ptr), _threadId(threadId) {
	if (_rawptr) {
		reinterpret_cast<CefTaskRunner*>(_rawptr)->AddRef();
	}
}

ProxyTaskRunner::~ProxyTaskRunner() {
	if (_rawptr) {
		reinterpret_cast<CefTaskRunner*>(_rawptr)->Release();
		_rawptr = nullptr;
	}
}

///
// Returns the task runner for the specified CEF thread.
///
/*--cef()--*/
shrewd_ptr<ProxyTaskRunner> ProxyTaskRunner::GetForThread(int threadId) {
	return new ProxyTaskRunner(CefTaskRunner::GetForThread((CefThreadId)threadId), threadId);
}

///
// Post a task for execution on the thread associated with this task runner.
// Execution will occur asynchronously.
///
/*--cef()--*/
bool ProxyTaskRunner::PostTask(int taskid, shrewd_ptr<ProxyValue> params) {
	ASSERTQ(false);
	CefRefPtr<CefValue> value;
	if (params && ORIGIN(CefValue, params)) {
		value = ORIGIN(CefValue, params);
	}
	CefRefPtr<InternalTaskVisitor> visitor = new InternalTaskVisitor(taskid, _threadId, value);
	return FORWARD(CefTaskRunner)->PostTask(visitor);
}

///
// Post a task for delayed execution on the thread associated with this task
// runner. Execution will occur asynchronously. Delayed tasks are not
// supported on V8 WebWorker threads and will be executed without the
// specified delay.
///
/*--cef()--*/
bool ProxyTaskRunner::PostDelayedTask(int taskid, shrewd_ptr<ProxyValue> params, __int64 delay_ms) {
	ASSERTQ(false);
	CefRefPtr<CefValue> value;
	if (params && ORIGIN(CefValue, params)) {
		value = ORIGIN(CefValue, params);
	}
	CefRefPtr<InternalTaskVisitor> visitor = new InternalTaskVisitor(taskid, _threadId, value);
	return FORWARD(CefTaskRunner)->PostDelayedTask(visitor, delay_ms);
}
