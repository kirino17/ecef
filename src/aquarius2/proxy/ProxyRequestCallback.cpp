#include "ProxyRequestCallback.h"
#include "include/cef_request_callback.h"

AQUA_PROXY_AUTO_CONSTRUCTOR(ProxyRequestCallback,CefRequestCallback);

///
// Continue the url request. If |allow| is true the request will be continued.
// Otherwise, the request will be canceled.
///
/*--cef(capi_name=cont)--*/
void ProxyRequestCallback::Continue(bool allow) {
	ASSERTN();
	FORWARD(CefRequestCallback)->Continue(allow);
}

///
// Cancel the url request.
///
/*--cef()--*/
void ProxyRequestCallback::Cancel() {
	ASSERTN();
	FORWARD(CefRequestCallback)->Cancel();
}
