#pragma once
#include "include/cef_client.h"
#include "include/cef_waitable_event.h"

class InternalDevToolsClient : public CefClient,
	public CefLifeSpanHandler
{
public:
	InternalDevToolsClient(CefRefPtr<CefWaitableEvent> waitable, HWND* result);
	~InternalDevToolsClient();

public:
	virtual CefRefPtr<CefLifeSpanHandler> GetLifeSpanHandler() OVERRIDE { return this; }

public:
	virtual void OnAfterCreated(CefRefPtr<CefBrowser> browser) OVERRIDE;

public:
	IMPLEMENT_REFCOUNTING(InternalDevToolsClient);

private:
	CefRefPtr<CefWaitableEvent> _waitable;
	HWND* _result;
};