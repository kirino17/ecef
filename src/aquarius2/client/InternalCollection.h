#pragma once
#include "include/cef_app.h"
#include "include/cef_browser.h"
#include "../proxy/ProxyBrowser.h"
#include "../proxy/ProxyWindowInfo.h"
#include "../proxy/ProxyBrowserSettings.h"
#include <vector>

#define NO_CEF_THREAD() (CefCurrentlyOn(TID_UI) || CefCurrentlyOn(TID_IO) || CefCurrentlyOn(TID_RENDERER))

class InternalCollection : public CefBaseRefCounted {
public:
	InternalCollection(bool shared_cache);
	~InternalCollection();

public:
	shrewd_ptr<ProxyBrowser> CreateBrowser(
		const char* url,
		shrewd_ptr<ProxyBrowserSettings> settings);

	int GetBrowserCount();

	shrewd_ptr<ProxyBrowser> GetBrowser(int index);

	void CloseBrowser(shrewd_ptr<ProxyBrowser> browser);

	shrewd_ptr<ProxyBrowser>** GetAllBrowser();

public:
	IMPLEMENT_REFCOUNTING(InternalCollection);

private:
	CefRefPtr<CefRequestContext> _context;
};