#include "ProxyQueryCallback.h"
#include "include/wrapper/cef_message_router.h"
#include "../def/internalDef.h"
#include <atlconv.h>

AQUA_PROXY_AUTO_CONSTRUCTOR(ProxyQueryCallback, CefMessageRouterBrowserSide::Callback);


void ProxyQueryCallback::Success(const char* response) {
	ASSERTN();
	if (!response) {
		return;
	}
	size_t length = strlen(response);
	if (length <= 200) {
		USES_CONVERSION;
		FORWARD(CefMessageRouterBrowserSide::Callback)->Success(A2W(response));
	}
	else {
		wchar_t* buffer = ToUnicode(response,length);
		FORWARD(CefMessageRouterBrowserSide::Callback)->Success(buffer);
		DeleteBuffer(buffer);
	}
}

void ProxyQueryCallback::Failure(int error_code, const char* error_message) {
	ASSERTN();
	if (!error_message) {
		return;
	}
	size_t length = strlen(error_message);
	if (length <= 200) {
		USES_CONVERSION;
		FORWARD(CefMessageRouterBrowserSide::Callback)->Failure(error_code,A2W(error_message));
	}
	else {
		wchar_t* buffer = ToUnicode(error_message, length);
		FORWARD(CefMessageRouterBrowserSide::Callback)->Failure(error_code,error_message);
		DeleteBuffer(buffer);
	}
}