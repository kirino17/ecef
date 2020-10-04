#include "ProxyClient.h"
#include <vector>
#include <mutex>
#include <Windows.h>
#include "include/cef_browser.h"
#include <atlconv.h>
#include "ProxyRequestContext.h"
#include "ProxyRequestContextSettings.h"
#include "../client/InternalClient.h"
#include "include/cef_app.h"
#include "../client/InternalCreateBrowser.h"

struct ClientContext {
	std::vector<CefRefPtr<CefBrowser>> browserArrays;
	std::mutex synchronous;

	ClientContext() {
		browserArrays.clear();
	}

	~ClientContext() {
		browserArrays.clear();
	}
};

ProxyClient::ProxyClient():
	_rawptr( new ClientContext() )
{
	
}

ProxyClient::~ProxyClient() {
	delete reinterpret_cast<ClientContext*>(_rawptr);
	_rawptr = NULL;
}

void ProxyClient::OnAfterCreated(shrewd_ptr<ProxyBrowser> browser) {
	ClientContext* context = reinterpret_cast<ClientContext*>(_rawptr);
	context->synchronous.lock();
	{
		context->browserArrays.push_back(ORIGIN(CefBrowser, browser));
	}
	context->synchronous.unlock();
}

void ProxyClient::OnBeforeClose(shrewd_ptr<ProxyBrowser> browser) {
	ClientContext* context = reinterpret_cast<ClientContext*>(_rawptr);
	context->synchronous.lock();
	{
		for (size_t i = 0; i < context->browserArrays.size(); i++)
		{
			if (ORIGIN(CefBrowser, browser)->IsSame(context->browserArrays[i])) {
				context->browserArrays.erase(context->browserArrays.begin() + i);
				break;
			}
		}
	}
	context->synchronous.unlock();
}

bool ProxyClient::CreateBrowser(
	shrewd_ptr<ProxyWindowInfo> winInfo,
	const char* url,
	shrewd_ptr<ProxyBrowserSettings> settings,
	shrewd_ptr<ProxyRequestContext> request_context
) {
	CefRefPtr<InternalClient> client = InternalClient::GetShareInatance();
	CefRefPtr<CefRequestContext> requestContext = nullptr;
	CefRefPtr<CefBrowser> browser = nullptr;
	CefBrowserSettings browserSettings;
	CefWindowInfo windowInfo;
	CefString wUrl;

	

	if (url) {
		USES_CONVERSION;
		wUrl = A2W(url);
	}

	if (winInfo && winInfo->OriginPointer()) {
		windowInfo = (*(CefWindowInfo*)winInfo->OriginPointer());
	}

	if (settings && settings->OriginPointer()) {
		browserSettings = (*(CefBrowserSettings*)settings->OriginPointer());
	}

	if (request_context && ORIGIN(CefRequestContext, request_context)) {
		requestContext = ORIGIN(CefRequestContext, request_context);
	}

	bool result = CefBrowserHost::CreateBrowser(windowInfo, client, wUrl, browserSettings, nullptr, requestContext);

	return result;
}

void ProxyClient::CloseBrowser(shrewd_ptr<ProxyBrowser> browser, bool force_close) {
	if (browser && ORIGIN(CefBrowser, browser)) {
		shrewd_ptr<ProxyBrowserHost> host = browser->GetHost();
		if (host) {
			host->CloseBrowser(force_close);
		}
	}
}

void ProxyClient::SetForeground(unsigned int parent_window, shrewd_ptr<ProxyBrowser> browser) {
	if (browser && ORIGIN(CefBrowser, browser)) {
		ClientContext* context = reinterpret_cast<ClientContext*>(_rawptr);

		context->synchronous.lock();
		{
			for (size_t i = 0; i < context->browserArrays.size(); i++)
			{
				HWND hWnd = (HWND)context->browserArrays[i]->GetHost()->GetWindowHandle();
				if (GetParent(hWnd) == (HWND)(parent_window)) {
					ShowWindow(hWnd, SW_HIDE);
				}
			}
			HWND hWnd = ORIGIN(CefBrowser, browser)->GetHost()->GetWindowHandle();
			ShowWindow(hWnd, SW_SHOW);
		}
		context->synchronous.unlock();
	}
}

int ProxyClient::GetBrowserCount(void) {
	int count = 0;
	ClientContext* context = reinterpret_cast<ClientContext*>(_rawptr);
	context->synchronous.lock();
	{
		count = context->browserArrays.size();
	}
	context->synchronous.unlock();
	return count;
}

shrewd_ptr<ProxyBrowser> ProxyClient::GetBrowserWithIndex(int index) {
	if (index < 0) {
		return NULL;
	}
	shrewd_ptr<ProxyBrowser> browser = nullptr;
	ClientContext* context = reinterpret_cast<ClientContext*>(_rawptr);
	context->synchronous.lock();
	{
		if (index < context->browserArrays.size()) {
			browser = new ProxyBrowser(context->browserArrays[index]);
		}
	}
	context->synchronous.unlock();
	return browser;
}

shrewd_ptr<ProxyBrowser> ProxyClient::GetBrowserWithHandle(unsigned int handle) {
	if (handle == 0) {
		return NULL;
	}
	shrewd_ptr<ProxyBrowser> browser = nullptr;
	ClientContext* context = reinterpret_cast<ClientContext*>(_rawptr);
	CefRefPtr<CefBrowserHost> host = nullptr;
	context->synchronous.lock();
	{
		for (size_t i = 0; i < context->browserArrays.size(); i++)
		{
			host = context->browserArrays[i]->GetHost();
			if ((unsigned int)host->GetWindowHandle() == handle) {
				browser = new ProxyBrowser(context->browserArrays[i]);
				break;
			}
		}
	}
	context->synchronous.unlock();
	return browser;
}

void ProxyClient::OnSizeChanged(unsigned int parentWindow, int cx, int cy) {
	HWND hWnd = (HWND)parentWindow;
	ClientContext* context = reinterpret_cast<ClientContext*>(_rawptr);
	CefRefPtr<CefBrowserHost> host = nullptr;
	context->synchronous.lock();
	{
		for (int i = 0; i < context->browserArrays.size();i++) {
			host = context->browserArrays[i]->GetHost();
			HWND hBrowser = (HWND)host->GetWindowHandle();
			if (GetParent(hBrowser) == hWnd) {
				MoveWindow(hBrowser, 0, 0, cx, cy, TRUE);
				host->NotifyMoveOrResizeStarted();
				host->WasResized();
			}
		}
	}
	context->synchronous.unlock();
}
