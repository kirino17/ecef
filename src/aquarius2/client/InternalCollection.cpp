#include "InternalCollection.h"
#include <atlconv.h>
#include "InternalClient.h"
#include "InternalTaskVisitor.h"
#include "include/cef_waitable_event.h"
#include "../def/internalDef.h"

InternalCollection::InternalCollection(bool shared_cache)
{
	if (shared_cache) {
		_context = CefRequestContext::GetGlobalContext();
	}
	else {

		CefRequestContextSettings settings;
		settings.persist_session_cookies = true;
		settings.persist_user_preferences = true;
		settings.ignore_certificate_errors = true;
		_context = CefRequestContext::CreateContext(settings, nullptr);
	}
}

InternalCollection::~InternalCollection() {
	CefRefPtr<InternalClient> client = InternalClient::GetShareInatance();
	client->GetClient()->CloseSameBrowser(_context.get());
	_context = nullptr;
}

shrewd_ptr<ProxyBrowser> InternalCollection::CreateBrowser(
	const char* url,
	shrewd_ptr<ProxyBrowserSettings> settings) {
	CefRefPtr<CefBrowser> browser = nullptr;
	if (!NO_CEF_THREAD()) {
		
		CefBrowserSettings args;
		CefString wideURL = url;
		CefRefPtr<CefWaitableEvent> waitable = CefWaitableEvent::CreateWaitableEvent(false, false);

		auto f = [](CefString url,
			CefBrowserSettings* settings,
			CefRefPtr<CefRequestContext> context,
			CefRefPtr<CefWaitableEvent> waitable,
			CefRefPtr<CefBrowser>* result) {
			CefRefPtr<InternalClient> client = InternalClient::GetShareInatance();
			CefWindowInfo info;
			info.SetAsPopup(NULL, L"");
			*result = CefBrowserHost::CreateBrowserSync(info, client, url, (*settings), NULL, context);
			waitable->Signal();
		};

		if (settings && ORIGIN(CefBrowserSettings, settings)) {
			args = (*ORIGIN(CefBrowserSettings, settings));
		}

		CefRefPtr<InternalTaskVisitor> visitor = new InternalTaskVisitor(std::bind(
			f, wideURL,&args, _context,waitable,&browser));
		
		CefPostTask(TID_UI, visitor);
		WaitAwaking(waitable);
	}
	if (browser) {
		return new ProxyBrowser(browser);
	}
	return nullptr;
}

int InternalCollection::GetBrowserCount() {
	CefRefPtr<InternalClient> client = InternalClient::GetShareInatance();
	return client->GetClient()->GetSameBrowserCount(_context.get());
}

shrewd_ptr<ProxyBrowser> InternalCollection::GetBrowser(int index) {
	CefRefPtr<InternalClient> client = InternalClient::GetShareInatance();
	return client->GetClient()->GetSameBrowserWithIndex(_context.get(), index);
}

void InternalCollection::CloseBrowser(shrewd_ptr<ProxyBrowser> browser) {
	CefRefPtr<InternalClient> client = InternalClient::GetShareInatance();
	client->GetClient()->CloseBrowser(browser, true);
}

shrewd_ptr<ProxyBrowser>** InternalCollection::GetAllBrowser() {
	CefRefPtr<InternalClient> client = InternalClient::GetShareInatance();
	return client->GetClient()->GetSameBrowser(_context.get());
}