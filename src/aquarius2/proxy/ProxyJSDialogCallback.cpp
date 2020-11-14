#include "ProxyJSDialogCallback.h"
#include "include/cef_jsdialog_handler.h"
#include <atlconv.h>

AQUA_PROXY_AUTO_CONSTRUCTOR(ProxyJSDialogCallback,CefJSDialogCallback);

///
// Continue the JS dialog request. Set |success| to true if the OK button was
// pressed. The |user_input| value should be specified for prompt dialogs.
///
/*--cef(capi_name=cont,optional_param=user_input)--*/
void ProxyJSDialogCallback::Continue(bool success, const char* user_input) {
	ASSERTN();
	CefString string;

	USES_CONVERSION;
	if (!user_input) {
		string = A2W(user_input);
	}

	FORWARD(CefJSDialogCallback)->Continue(success, string);
}