#pragma once
#include "include/cef_app.h"
#include "include/cef_client.h"
#include <cpprest/ws_client.h>
#include <cpprest/json.h>
#include "include/cef_waitable_event.h"

#define ECEF_AUTH_CMD_LOGIN		(3030)
#define ECEF_AUTH_CMD_SIGNUP	(3031)
#define ECEF_AUTH_CMD_RESET		(3032)
#define ECEF_AUTH_CMD_HINT		(3033)
#define ECEF_AUTH_CMD_PAY		(3034)

//#define ECEF_AUTH_SERVER		L"ws://124.71.103.102:9098"
#define ECEF_AUTH_SERVER		L"ws://127.0.0.1:9098"


#define ECEF_AUTH_VERSION		L"ecef_v2.0.19c"


class InternalPower : public CefBaseRefCounted {
public:
	InternalPower();
	~InternalPower();

public:
	void Initialize(int mode);

	void* GetCmdNames(HWND hWnd);
public:
	IMPLEMENT_REFCOUNTING(InternalPower);
};

class InternalApp : public CefApp,
	CefBrowserProcessHandler
{
public:
	InternalApp();
	~InternalApp();

public:
	static CefRefPtr<InternalApp> GetInstance();

public:
	virtual CefRefPtr<CefBrowserProcessHandler> GetBrowserProcessHandler() OVERRIDE {
		return this;
	}

public:
	virtual void OnContextInitialized() OVERRIDE;

	void SetMode(int mode) { _mode = mode; }

public:
	IMPLEMENT_REFCOUNTING(InternalApp);

private:
	bool _mode;
};

class InternalConnection : public CefBaseRefCounted {
public:
	InternalConnection() {

	}
	~InternalConnection() {

	}

public:
	web::websockets::client::websocket_callback_client wsconn;

public:
	IMPLEMENT_REFCOUNTING(InternalConnection);
};


class InternalHandler : public CefClient,
	public CefLifeSpanHandler,
	public CefLoadHandler,
	public CefContextMenuHandler
{
public:
	InternalHandler();
	~InternalHandler();

public:
	static CefRefPtr<InternalHandler> GetInstance();

public:
	virtual void OnAfterCreated(CefRefPtr<CefBrowser> browser) OVERRIDE;

	virtual void OnBeforeClose(CefRefPtr<CefBrowser> browser) OVERRIDE;

public:
	virtual CefRefPtr<CefLifeSpanHandler> GetLifeSpanHandler() OVERRIDE { return this; }
	virtual CefRefPtr<CefLoadHandler> GetLoadHandler() OVERRIDE { return this; }
	virtual CefRefPtr<CefContextMenuHandler> GetContextMenuHandler() OVERRIDE { return this; }
public:
	virtual bool RunContextMenu(CefRefPtr<CefBrowser> browser,
		CefRefPtr<CefFrame> frame,
		CefRefPtr<CefContextMenuParams> params,
		CefRefPtr<CefMenuModel> model,
		CefRefPtr<CefRunContextMenuCallback> callback) OVERRIDE;

public:
	virtual bool OnProcessMessageReceived(CefRefPtr<CefBrowser> browser,
		CefRefPtr<CefFrame> frame,
		CefProcessId source_process,
		CefRefPtr<CefProcessMessage> message) OVERRIDE;

public:
	void SendAuthMessage(CefRefPtr<CefFrame> frame, int command, CefRefPtr<CefListValue> params);

	void SendAuthHint(CefRefPtr<CefFrame> frame, const CefString& message, const CefString& color = L"");
public:
	void OnCommandLogin(CefRefPtr<CefFrame> frame, CefRefPtr<CefListValue> params);
	void OnCommandPay(CefRefPtr<CefFrame> frame, CefRefPtr<CefListValue> params);
	void OnCommandSignup(CefRefPtr<CefFrame> frame, CefRefPtr<CefListValue> params);
	void OnCommandReset(CefRefPtr<CefFrame> frame, CefRefPtr<CefListValue> params);


public:
	void GetMetadata(CefRefPtr<CefWaitableEvent> waitable, void** ret, HWND hWnd);

	bool DecodeMetadata(const std::wstring& metadata);
public:
	bool Connect();

	void Login(const CefString& username, const CefString& password);

	void Pay(int product);

	void Register(const CefString& username, const CefString& password);

	void Reset(const CefString& username, const CefString& password, const CefString& trade_id);

	void SendRequest(int command, web::json::value params = web::json::value::null());

	void SetError(const std::wstring& error);

	void SetOk(const std::wstring& hint);

	void Close();
public:
	void DoLogin(web::json::value& data);

	void DoPay(web::json::value& data);

	void DoPayCallback(web::json::value& data);

	void DoPayTimeout(web::json::value& data);

	void DoClose();

private:
	std::wstring GetDeviceIdentity();

	void Encode(const std::string& data, std::string& buffer);

	void Decode(const std::string& data, std::string& buffer);

public:
	IMPLEMENT_REFCOUNTING(InternalHandler);

private:
	bool _hasGui;
	CefRefPtr<CefFrame> _mainFrame;
	std::wstring _expired;
	bool _hasConnected;
	std::wstring _username;
	std::wstring _password;
	CefRefPtr<InternalConnection> _connection;
	CefRefPtr<CefWaitableEvent> _waitable;
	void** _retMetadata;
	std::vector<std::string> _cmdNameArrays;
	std::vector<void*> _cmdNamePointerArrays;
	HWND _outputWnd;
};