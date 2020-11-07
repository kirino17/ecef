#include "ProxyThread.h"
#include "include/cef_thread.h"

AQUA_PROXY_AUTO_CONSTRUCTOR(ProxyThread, CefThread);

bool ProxyThread::IsValid() {
	return _rawptr != nullptr;
}

shrewd_ptr<ProxyTaskRunner> ProxyThread::GetTaskRunner() {
	ASSERTQ(nullptr);
	CefRefPtr<CefTaskRunner> runner = FORWARD(CefThread)->GetTaskRunner();
	if (runner) {
		return new ProxyTaskRunner(runner);
	}
	return nullptr;
}

int ProxyThread::GetPlatformThreadId() {
	ASSERTQ(-1);
	return FORWARD(CefThread)->GetPlatformThreadId();
}

void ProxyThread::Stop() {
	ASSERTN();
	FORWARD(CefThread)->Stop();
}

bool ProxyThread::IsRunning() {
	ASSERTQ(false);
	return FORWARD(CefThread)->IsRunning();
}