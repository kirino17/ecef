#include "ProxyGetExtensionResourceCallback.h"
#include "include/cef_extension_handler.h"
#include <atlconv.h>

AQUA_PROXY_AUTO_CONSTRUCTOR(ProxyGetExtensionResourceCallback,CefGetExtensionResourceCallback);

void ProxyGetExtensionResourceCallback::ContinueWithData(unsigned char* data, int size) {
	ASSERTN();
	if (!data || ((size_t)size) <= 0) {
		return;
	}
	CefRefPtr<CefStreamReader> reader = CefStreamReader::CreateForData(&data[8], (size_t)size);
	FORWARD(CefGetExtensionResourceCallback)->Continue(reader);
}

void ProxyGetExtensionResourceCallback::ContinueWithFile(const char* filename) {
	ASSERTN();
	if (!filename) {
		return;
	}
	USES_CONVERSION;
	CefRefPtr<CefStreamReader> reader = CefStreamReader::CreateForFile(A2W(filename));
	FORWARD(CefGetExtensionResourceCallback)->Continue(reader);
}

void ProxyGetExtensionResourceCallback::Cancel() {
	ASSERTN();
	FORWARD(CefGetExtensionResourceCallback)->Cancel();
}