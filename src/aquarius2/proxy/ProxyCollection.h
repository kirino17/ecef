#pragma once
#include "../def/def.h"
#include "../proxy/ProxyBrowser.h"
#include "../proxy/ProxyBrowserSettings.h"
#include "../proxy/ProxyCookieManager.h"
#include "../proxy/ProxyURLRequest.h"

class AQUADLL ProxyCollection : public refcounted {
public:
	ProxyCollection(void* ptr);
	~ProxyCollection();

public:
	// is valid
	bool IsValid();

	shrewd_ptr<ProxyBrowser> CreateBrowser(const char* url, shrewd_ptr<ProxyBrowserSettings> settings);
	
	void CloseBrowser(shrewd_ptr<ProxyBrowser> browser);

	int GetBrowserCount();

	shrewd_ptr<ProxyBrowser> GetBrowser(int index);

	shrewd_ptr<ProxyBrowser>** GetAllBrowser();

private:
	PRIME_IMPLEMENT_REFCOUNTING(ProxyCollection);
	AQUA_DECL_PUBLIC_ORIGIN;

private:
	void* _rawptr;
};