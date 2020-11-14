#pragma once

#include "resource.h"
#include <vector>
#include <list>
#include "include/cef_app.h"
#include "include/cef_values.h"
#include "include/cef_waitable_event.h"
#include "include/wrapper/cef_message_router.h"
#include <map>

struct RENDERER_BROWSER_CONTEXT {
	CefRefPtr<CefBrowser> browser;
	CefString scriptOnNewDocument;
	CefString useragentOverride;
	CefString appVersionOverride;

	RENDERER_BROWSER_CONTEXT(CefRefPtr<CefBrowser> b):
		browser(b),
		scriptOnNewDocument(L""),
		useragentOverride(L""){

	}

	~RENDERER_BROWSER_CONTEXT() {
		browser = nullptr;
	}
};

struct BROWSER_EXTRA_INFO {
	CefString scriptOnNewDocument;
	CefString useragentOverride;
	CefString appVersionOverride;
};

class InternalProgram : public CefApp,
	public CefRenderProcessHandler,
	public CefLoadHandler
{
public:
	InternalProgram();
	~InternalProgram();

public:
	static CefRefPtr<InternalProgram> GetInstance();

public:
	///
	// Return the handler for functionality specific to the render process. This
	// method is called on the render process main thread.
	///
	/*--cef()--*/
	virtual CefRefPtr<CefRenderProcessHandler> GetRenderProcessHandler() OVERRIDE {
		return this;
	}

public:
	virtual void OnRenderThreadCreated(CefRefPtr<CefListValue> extra_info) OVERRIDE;


	///
	// Called when a new message is received from a different process. Return true
	// if the message was handled or false otherwise. Do not keep a reference to
	// or attempt to access the message outside of this callback.
	///
	/*--cef()--*/
	virtual bool OnProcessMessageReceived(CefRefPtr<CefBrowser> browser,
		CefRefPtr<CefFrame> frame,
		CefProcessId source_process,
		CefRefPtr<CefProcessMessage> message) OVERRIDE;

	virtual void OnContextCreated(CefRefPtr<CefBrowser> browser,
		CefRefPtr<CefFrame> frame,
		CefRefPtr<CefV8Context> context) OVERRIDE;

	virtual void OnContextReleased(CefRefPtr<CefBrowser> browser,
		CefRefPtr<CefFrame> frame,
		CefRefPtr<CefV8Context> context) OVERRIDE;

	virtual void OnBrowserCreated(CefRefPtr<CefBrowser> browser,
		CefRefPtr<CefDictionaryValue> extra_info) OVERRIDE;

	virtual void OnBrowserDestroyed(CefRefPtr<CefBrowser> browser) OVERRIDE;

	virtual void OnWebKitInitialized() OVERRIDE;

public:
	CefRefPtr<CefFrame> GetFrame(int64 identifier);

public:
	void ExecuteScript(
		CefRefPtr<CefBrowser> browser,
		CefRefPtr<CefFrame> frame,
		CefRefPtr<CefListValue> arguments);

	void ExecuteScriptGlobal(CefRefPtr<CefFrame> frame, CefRefPtr<CefV8Context> context, const CefString& script);

	void SetUserAgentOverride(CefRefPtr<CefFrame> frame, 
		CefRefPtr<CefV8Context> context, 
		const CefString& useragent,
		const CefString& appVersion);

public:
#define ECEF_AUTH_CMD_LOGIN		(3030)
#define ECEF_AUTH_CMD_SIGNUP	(3031)
#define ECEF_AUTH_CMD_RESET		(3032)
#define ECEF_AUTH_CMD_HINT		(3033)
#define ECEF_AUTH_CMD_PAY		(3034)


	static void OnAuth(int command);

	void OnCommandLogin(CefRefPtr<CefFrame> frame);
	void OnCommandPay(CefRefPtr<CefFrame> frame);
	void OnCommandSignup(CefRefPtr<CefFrame> frame);
	void OnCommandReset(CefRefPtr<CefFrame> frame);

	void SendAuthMessage(CefRefPtr<CefFrame> frame, int command, CefRefPtr<CefListValue> params);
public:
	void AddScriptOnNewDocument(CefRefPtr<CefBrowser> browser, const CefString& script_code);

	void AddUserAgentOverride(CefRefPtr<CefBrowser> browser, const CefString& useragent, const CefString& appversion);

private:
	std::list<RENDERER_BROWSER_CONTEXT> _contexts;
	CefRefPtr<CefMessageRouterRendererSide> _messageRouter;
	std::map<int, BROWSER_EXTRA_INFO> _extraInfos;

public:
	IMPLEMENT_REFCOUNTING(InternalProgram);
};


/**
 *  线程同步等待
 *
 *  @param waitable 等待对象
*/
void WaitAwaking(CefRefPtr<CefWaitableEvent> waitable);