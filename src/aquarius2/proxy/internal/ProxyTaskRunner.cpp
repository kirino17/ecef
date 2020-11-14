#include "ProxyTaskRunner.h"
#include "include/cef_task.h"

AQUA_PROXY_AUTO_CONSTRUCTOR(ProxyTaskRunner, CefTaskRunner);

bool ProxyTaskRunner::IsValid() {
	return _rawptr != nullptr;
}

bool ProxyTaskRunner::IsSame(shrewd_ptr<ProxyTaskRunner> runner) {
	ASSERTQ(false);
	if (!runner || !ORIGIN(CefTaskRunner, runner)) {
		return false;
	}
	return FORWARD(CefTaskRunner)->IsSame(ORIGIN(CefTaskRunner, runner));
}

bool ProxyTaskRunner::BelongsToCurrentThread() {
	ASSERTQ(false);
	return FORWARD(CefTaskRunner)->BelongsToCurrentThread();
}

bool ProxyTaskRunner::PostTask(int cb, shrewd_ptr<ProxyTaskBind> binding) {
	ASSERTQ(false);
	return false;
}

bool ProxyTaskRunner::PostDelayedTask(int cb, shrewd_ptr<ProxyTaskBind> binding, int delay_ms) {
	ASSERTQ(false);
	return false;
}