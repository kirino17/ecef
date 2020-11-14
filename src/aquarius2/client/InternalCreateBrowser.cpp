#include "InternalCreateBrowser.h"
#include "InternalClient.h"
#include <Windows.h>

InternalCreateBrowser::InternalCreateBrowser(
	CefRefPtr<CefWaitableEvent> waitable,
	CefWindowInfo& windowInfo,
	const CefString& url,
	const CefBrowserSettings& settings,
	CefRefPtr<CefRequestContext> request_context):
	_waitable(waitable),
	_windowInfo(windowInfo),
	_url(url),
	_browserSettings(settings),
	_requestContext(request_context)
{


}

InternalCreateBrowser::~InternalCreateBrowser() {
	_waitable = nullptr;
	_resultBrowser = nullptr;
	_requestContext = nullptr;
}

void InternalCreateBrowser::Execute() {
	_resultBrowser = CefBrowserHost::CreateBrowserSync(
		_windowInfo, 
		InternalClient::GetShareInatance(),
		_url,_browserSettings,nullptr,_requestContext);

	MessageBox(NULL, L"xxxx", NULL, NULL);
	_waitable->Signal();
}

CefRefPtr<CefBrowser> InternalCreateBrowser::GetBrowser() {
	return _resultBrowser;
}