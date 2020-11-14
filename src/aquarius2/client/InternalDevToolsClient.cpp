#include "InternalDevToolsClient.h"


InternalDevToolsClient::InternalDevToolsClient(CefRefPtr<CefWaitableEvent> waitable, HWND* result):
	_waitable(waitable),
	_result(result)
{

}

InternalDevToolsClient::~InternalDevToolsClient() {
	_waitable = nullptr;
}

void InternalDevToolsClient::OnAfterCreated(CefRefPtr<CefBrowser> browser) {
	if (_result) {
		*_result = browser->GetHost()->GetWindowHandle();
		_waitable->Signal();
	}
}