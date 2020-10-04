#include "ProxyAuthCallback.h"
#include "include/cef_auth_callback.h"
#include <atlconv.h>

AQUA_PROXY_AUTO_CONSTRUCTOR(ProxyAuthCallback,CefAuthCallback);

///
// Continue the authentication request.
///
/*--cef(capi_name=cont,optional_param=username,optional_param=password)--*/
void ProxyAuthCallback::Continue(const char* username, const char* password) {
	ASSERTN();
	CefString strUserName, strPassword;
	USES_CONVERSION;

	if (username) {
		strUserName = A2W(username);
	}

	if (password) {
		strUserName = A2W(password);
	}

	FORWARD(CefAuthCallback)->Continue(strUserName, strPassword);
}

///
// Cancel the authentication request.
///
/*--cef()--*/
void ProxyAuthCallback::Cancel() {
	ASSERTN();
	FORWARD(CefAuthCallback)->Cancel();
}
