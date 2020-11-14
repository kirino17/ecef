#include "ProxyCollection.h"
#include "../client/InternalCollection.h"
#include <atlconv.h>

AQUA_PROXY_AUTO_CONSTRUCTOR(ProxyCollection, InternalCollection);

bool ProxyCollection::IsValid() {
	return _rawptr != nullptr;
}

shrewd_ptr<ProxyBrowser> ProxyCollection::CreateBrowser(const char* url, shrewd_ptr<ProxyBrowserSettings> settings) {
	ASSERTQ(NULL);
	if (!url) {
		return NULL;
	}
	return FORWARD(InternalCollection)->CreateBrowser(url,settings);
}

void ProxyCollection::CloseBrowser(shrewd_ptr<ProxyBrowser> browser) {
	ASSERTN();
	if (!browser || !ORIGIN(CefBrowser, browser)) {
		return;
	}
	FORWARD(InternalCollection)->CloseBrowser(browser);
}

int ProxyCollection::GetBrowserCount() {
	ASSERTQ(0);
	return FORWARD(InternalCollection)->GetBrowserCount();
}

shrewd_ptr<ProxyBrowser> ProxyCollection::GetBrowser(int index) {
	ASSERTQ(NULL);
	if (index < 0) {
		return NULL;
	}
	return FORWARD(InternalCollection)->GetBrowser(index);
}

shrewd_ptr<ProxyBrowser>** ProxyCollection::GetAllBrowser() {
	ASSERTARRAY(shrewd_ptr<ProxyBrowser>);
	return FORWARD(InternalCollection)->GetAllBrowser();
}