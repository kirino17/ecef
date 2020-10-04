#pragma once
#include "include/cef_app.h"
#include "../proxy/ProxyClient.h"

class InternalProgram : public CefApp,
	public CefBrowserProcessHandler
{
public:
	InternalProgram(shrewd_ptr<ProxyClient> client = NULL);
	~InternalProgram();

public:
	static CefRefPtr<InternalProgram> GetShareInatance();

public:
	virtual void OnBeforeCommandLineProcessing(
		const CefString& process_type,
		CefRefPtr<CefCommandLine> command_line) OVERRIDE;

	virtual CefRefPtr<CefBrowserProcessHandler> GetBrowserProcessHandler() OVERRIDE {
		return this;
	}
public:
	virtual void OnContextInitialized() OVERRIDE;

public:
	virtual void OnBeforeChildProcessLaunch(
		CefRefPtr<CefCommandLine> command_line) OVERRIDE;

	virtual void OnRenderProcessThreadCreated(
		CefRefPtr<CefListValue> extra_info) OVERRIDE;
public:
    void CalcuateExpression(
        CefRefPtr<CefBrowser> browser, 
        CefRefPtr<CefFrame> frame,
        CefRefPtr<CefListValue> arguments);

public:
	void SetClient(shrewd_ptr<ProxyClient> client);

	shrewd_ptr<ProxyClient> GetClient(void);

public:
	IMPLEMENT_REFCOUNTING(InternalProgram);

private:
	shrewd_ptr<ProxyClient> _proxyClient;
};