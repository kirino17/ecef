#include "Power.h"
#include "InternalPower.h"

namespace Local {
	shrewd_ptr<Power> __objShared = nullptr;
}

AQUA_PROXY_AUTO_CONSTRUCTOR(Power,InternalPower);

shrewd_ptr<Power> Power::GetInstance() {
	if (!Local::__objShared) {
		Local::__objShared = new Power(new InternalPower());
	}
	return Local::__objShared;
}

void Power::Initialize(int mode) {
	ASSERTN();
	FORWARD(InternalPower)->Initialize(mode);
}

void Power::Shutdown(void) {
	CefShutdown();
}

void* Power::GetCmdNames(HWND hWnd) {
	return FORWARD(InternalPower)->GetCmdNames(hWnd);
}