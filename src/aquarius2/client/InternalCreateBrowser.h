#pragma once
#include "include/cef_browser.h"
#include "include/cef_task.h"
#include "include/cef_waitable_event.h"

class InternalCreateBrowser : public CefTask {
public:
	InternalCreateBrowser(
		CefRefPtr<CefWaitableEvent> waitable, 
		CefWindowInfo& windowInfo,
		const CefString& url,
		const CefBrowserSettings& settings,
		CefRefPtr<CefRequestContext> request_context);
	~InternalCreateBrowser();

public:
	virtual void Execute() override;


public:
	CefRefPtr<CefBrowser> GetBrowser();

public:
	IMPLEMENT_REFCOUNTING(InternalCreateBrowser);

private:
	CefRefPtr<CefWaitableEvent> _waitable;
	CefRefPtr<CefBrowser> _resultBrowser;
	CefWindowInfo _windowInfo;
	CefBrowserSettings _browserSettings;
	CefString _url;
	CefRefPtr<CefRequestContext> _requestContext;
};