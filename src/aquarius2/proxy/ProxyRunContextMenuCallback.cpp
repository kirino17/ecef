#include "ProxyRunContextMenuCallback.h"
#include "include/cef_context_menu_handler.h"

AQUA_PROXY_AUTO_CONSTRUCTOR(ProxyRunContextMenuCallback,CefRunContextMenuCallback);

///
// Complete context menu display by selecting the specified |command_id| and
// |event_flags|.
///
/*--cef(capi_name=cont)--*/
void ProxyRunContextMenuCallback::Continue(int command_id, int event_flags) {
	ASSERTN();
	FORWARD(CefRunContextMenuCallback)->Continue(command_id,(cef_event_flags_t)event_flags);
}

///
// Cancel context menu display.
///
/*--cef()--*/
void ProxyRunContextMenuCallback::Cancel() {
	ASSERTN();
	FORWARD(CefRunContextMenuCallback)->Cancel();
}
