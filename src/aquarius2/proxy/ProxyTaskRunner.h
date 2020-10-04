#pragma once
#include "../def/def.h"
#include "ProxyValue.h"

class AQUADLL ProxyTaskRunner : public refcounted {
public:
	ProxyTaskRunner(void* ptr, int threadId);
	~ProxyTaskRunner();

public:
	///
	// Returns the task runner for the specified CEF thread.
	///
	/*--cef()--*/
	static shrewd_ptr<ProxyTaskRunner> GetForThread(int threadId);

	///
	// Post a task for execution on the thread associated with this task runner.
	// Execution will occur asynchronously.
	///
	/*--cef()--*/
	bool PostTask(int taskid, shrewd_ptr<ProxyValue> params);

	///
	// Post a task for delayed execution on the thread associated with this task
	// runner. Execution will occur asynchronously. Delayed tasks are not
	// supported on V8 WebWorker threads and will be executed without the
	// specified delay.
	///
	/*--cef()--*/
	bool PostDelayedTask(int taskid, shrewd_ptr<ProxyValue> params, __int64 delay_ms);

public:
	PRIME_IMPLEMENT_REFCOUNTING(ProxyTaskRunner);
	AQUA_DECL_PUBLIC_ORIGIN;

private:
	void* _rawptr;
	int _threadId;
};