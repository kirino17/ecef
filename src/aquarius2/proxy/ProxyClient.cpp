#include "ProxyClient.h"
#include <vector>
#include <mutex>
#include <Windows.h>
#include "include/cef_browser.h"
#include <atlconv.h>
#include "../client/InternalClient.h"
#include "include/cef_app.h"
#include "../client/InternalCreateBrowser.h"
#include "ProxyWaitableEvent.h"
#include "ProxyBase.h"
#include "include/cef_render_handler.h"
#include "include/cef_waitable_event.h"
#include "../def/internalDef.h"



struct BrowserContext {
	CefRefPtr<CefBrowser> browser;
	CefString useragentOverride;
	CefString appversionOverride;
	CefString scriptOnNewDocument;
	CefRefPtr<CefListValue> userData;

	BrowserContext():
		browser(nullptr){
		userData = nullptr;
	}

	~BrowserContext() {
		browser = nullptr;
		userData = nullptr;
	}
};

struct ClientContext {
	std::vector<BrowserContext> browserArrays;
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
	BrowserContext now_bctx;
	now_bctx.browser = ORIGIN(CefBrowser, browser);
	CefRefPtr<CefRequestContext> request = ORIGIN(CefBrowser, browser)->GetHost()->GetRequestContext();
	CefRefPtr<CefRequestContext> target = nullptr;
	context->synchronous.lock();
	{
		for (size_t i = 0; i < context->browserArrays.size(); i++)
		{
			BrowserContext& bctx = context->browserArrays[i];
			target = bctx.browser->GetHost()->GetRequestContext();
			if ((!target && !request) || (request && request->IsSame(target))) {
				now_bctx.appversionOverride = bctx.appversionOverride;
				now_bctx.useragentOverride = bctx.useragentOverride;
				now_bctx.scriptOnNewDocument = bctx.scriptOnNewDocument;
				break;
			}
		}
		context->browserArrays.push_back(now_bctx);
	}
	context->synchronous.unlock();
}

void ProxyClient::OnBeforeClose(shrewd_ptr<ProxyBrowser> browser) {
	ClientContext* context = reinterpret_cast<ClientContext*>(_rawptr);
	context->synchronous.lock();
	{
		for (size_t i = 0; i < context->browserArrays.size(); i++)
		{
			BrowserContext& bctx = context->browserArrays[i];

			if (ORIGIN(CefBrowser, browser)->IsSame(bctx.browser)) {
				
				bctx.browser = nullptr;
				context->browserArrays.erase(context->browserArrays.begin() + i);
				break;
			}
		}
	}
	context->synchronous.unlock();
}

void ProxyClient::OnInternalOnBeforePopup(void* b, void** extra_info) {
	CefRefPtr<CefDictionaryValue>* dict = (CefRefPtr<CefDictionaryValue>*)extra_info;
	CefRefPtr<CefBrowser> browser = (CefBrowser*)b;
	CefRefPtr<CefRequestContext> request = browser->GetHost()->GetRequestContext();
	CefRefPtr<CefRequestContext> target = nullptr;

	ClientContext* context = reinterpret_cast<ClientContext*>(_rawptr);
	context->synchronous.lock();
	{
		for (size_t i = 0; i < context->browserArrays.size(); i++)
		{
			BrowserContext& bctx = context->browserArrays[i];
			target = bctx.browser->GetHost()->GetRequestContext();
			if ((!target && !request) || (request && request->IsSame(target))) {
				if (!bctx.useragentOverride.empty()) {
					if (!(*dict).get()) (*dict) = CefDictionaryValue::Create();
					(*dict)->SetString(L"user_agent_override", bctx.useragentOverride);
				}
				if (!bctx.appversionOverride.empty()) {
					if (!(*dict).get()) (*dict) = CefDictionaryValue::Create();
					(*dict)->SetString(L"app_version_override", bctx.appversionOverride);
				}
				if (!bctx.scriptOnNewDocument.empty()) {
					if (!(*dict).get()) (*dict) = CefDictionaryValue::Create();
					(*dict)->SetString(L"add_script_on_new_document", bctx.scriptOnNewDocument);
				}
				break;
			}
		}
	}
	context->synchronous.unlock();
}

void ProxyClient::OnRenderProcessThreadCreated(shrewd_ptr<ProxyListValue> extra_info) {
	ClientContext* context = reinterpret_cast<ClientContext*>(_rawptr);
	CefRefPtr<CefDictionaryValue> dict = nullptr;
	context->synchronous.lock();
	{
		int index = 0;
		for (size_t i = 0; i < context->browserArrays.size(); i++)
		{
			BrowserContext& bctx = context->browserArrays[i];
			if (!bctx.useragentOverride.empty() || !bctx.scriptOnNewDocument.empty()) {
				dict = CefDictionaryValue::Create();
				dict->SetString(L"user_agent_override", bctx.useragentOverride);
				dict->SetString(L"app_version_override", bctx.appversionOverride);
				dict->SetString(L"add_script_on_new_document", bctx.scriptOnNewDocument);
				dict->SetInt(L"browser-id", bctx.browser->GetIdentifier());
				ORIGIN(CefListValue,extra_info)->SetDictionary(index++, dict);
			}
		}
	}
	context->synchronous.unlock();
}

bool ProxyClient::CreateBrowser(
	shrewd_ptr<ProxyWindowInfo> winInfo,
	const char* url,
	shrewd_ptr<ProxyBrowserSettings> settings, bool incognito_mode
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

	if (incognito_mode) {
		CefRequestContextSettings contextSettings;
		contextSettings.persist_session_cookies = true;
		contextSettings.persist_user_preferences = true;
		contextSettings.ignore_certificate_errors = true;
		requestContext = CefRequestContext::CreateContext(contextSettings, nullptr);
	}

	return CefBrowserHost::CreateBrowser(windowInfo, client, wUrl, browserSettings, nullptr, requestContext);
}

void ProxyClient::CloseBrowser(shrewd_ptr<ProxyBrowser> browser, bool force_close) {
	if (browser && ORIGIN(CefBrowser, browser)) {
		browser->CloseBrowser(force_close);
	}
}

void ProxyClient::SetForeground(unsigned int parent_window, shrewd_ptr<ProxyBrowser> browser) {
	if (browser && ORIGIN(CefBrowser, browser)) {
		ClientContext* context = reinterpret_cast<ClientContext*>(_rawptr);

		context->synchronous.lock();
		{
			for (size_t i = 0; i < context->browserArrays.size(); i++)
			{
				BrowserContext& bctx = context->browserArrays[i];
				HWND hWnd = (HWND)bctx.browser->GetHost()->GetWindowHandle();
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

int ProxyClient::GetSameBrowserCount(void* context) {
	CefRefPtr<CefRequestContext> requestContext((CefRequestContext*)context);
	CefRefPtr<CefRequestContext> targetContext = nullptr;
	ClientContext* client = reinterpret_cast<ClientContext*>(_rawptr);
	CefRefPtr<CefBrowserHost> host = nullptr;
	int count = 0;
	if (requestContext) {
		client->synchronous.lock();
		{
			for (size_t i = 0; i < client->browserArrays.size(); i++) {
				host = client->browserArrays[i].browser->GetHost();
				targetContext = host->GetRequestContext();
				if (requestContext->IsSame(targetContext)) {
					count++;
				}
			}
		}
		client->synchronous.lock();
		host = nullptr;
		targetContext = nullptr;
	}
	return count;
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
			BrowserContext& bctx = context->browserArrays[i];
			host = bctx.browser->GetHost();
			if ((unsigned int)host->GetWindowHandle() == handle) {
				browser = new ProxyBrowser(bctx.browser);
				break;
			}
		}
	}
	context->synchronous.unlock();
	return browser;
}

/*--cef()--*/
shrewd_ptr<ProxyBrowser> ProxyClient::GetBrowserWithIndex(unsigned int index) {
	if (index < 0) {
		return NULL;
	}
	shrewd_ptr<ProxyBrowser> browser = nullptr;
	ClientContext* context = reinterpret_cast<ClientContext*>(_rawptr);
	context->synchronous.lock();
	{
		if (index < context->browserArrays.size()) {
			browser = new ProxyBrowser(context->browserArrays[index].browser);
		}
	}
	context->synchronous.unlock();
	return browser;
}

///
// 获取索引
///
int ProxyClient::GetIndex(shrewd_ptr<ProxyBrowser> browser) {
	int index = -1;
	if (!browser || !ORIGIN(CefBrowser, browser)) {
		return index;
	}
	ClientContext* context = reinterpret_cast<ClientContext*>(_rawptr);
	context->synchronous.lock();
	{
		for (size_t i = 0; i < context->browserArrays.size(); i++) {
			BrowserContext& bctx = context->browserArrays[i];
			if (bctx.browser->IsSame(ORIGIN(CefBrowser, browser))) {
				index = i;
				break;
			}
		}
	}
	context->synchronous.unlock();
	return index;
}

void ProxyClient::SetUserAgentOverride(shrewd_ptr<ProxyBrowser> browser, const wchar_t* useragent, const wchar_t* appversion) {
	if (browser && ORIGIN(CefBrowser,browser)) {
		ClientContext* context = reinterpret_cast<ClientContext*>(_rawptr);
		CefRefPtr<CefRequestContext> request = ORIGIN(CefBrowser, browser)->GetHost()->GetRequestContext();
		CefRefPtr<CefRequestContext> target = nullptr;
		context->synchronous.lock();
		{
			for (size_t i = 0; i < context->browserArrays.size(); i++) {
				BrowserContext& bctx = context->browserArrays[i];
				target = bctx.browser->GetHost()->GetRequestContext();
				if ((!target && !request) || (request && request->IsSame(target))) {
					bctx.useragentOverride = useragent;
					bctx.appversionOverride = appversion;
				}
			}
		}
		context->synchronous.unlock();
	}
}

void ProxyClient::SetScriptOnNewDocument(shrewd_ptr<ProxyBrowser> browser, const wchar_t* script) {
	if (browser && ORIGIN(CefBrowser, browser)) {
		ClientContext* context = reinterpret_cast<ClientContext*>(_rawptr);
		CefRefPtr<CefRequestContext> request = ORIGIN(CefBrowser, browser)->GetHost()->GetRequestContext();
		CefRefPtr<CefRequestContext> target = nullptr;
		context->synchronous.lock();
		{
			for (size_t i = 0; i < context->browserArrays.size(); i++) {
				BrowserContext& bctx = context->browserArrays[i];
				target = bctx.browser->GetHost()->GetRequestContext();
				if ((!target && !request) || (request && request->IsSame(target))) {
					bctx.scriptOnNewDocument = script;
				}
			}
		}
		context->synchronous.unlock();
	}
}

const wchar_t* ProxyClient::GetUserAgentOverride(void* pointer) {
	const wchar_t* result = L"";
	ClientContext* context = reinterpret_cast<ClientContext*>(_rawptr);
	CefRefPtr<CefBrowser> browser = (CefBrowser*)pointer;
	context->synchronous.lock();
	{
		for (size_t i = 0; i < context->browserArrays.size(); i++) {
			BrowserContext& bctx = context->browserArrays[i];
			if (bctx.browser->IsSame(browser)) {
				if (!bctx.useragentOverride.empty()) {
					result = bctx.useragentOverride.c_str();
				}
				break;
			}
		}
	}
	context->synchronous.unlock();
	return result;
}

///
// 取同源浏览器
///
shrewd_ptr<ProxyBrowser>** ProxyClient::GetSameOriginBrowser(shrewd_ptr<ProxyBrowser> browser) {
	if (!browser || !ORIGIN(CefBrowser, browser)) {
		DWORD* pointer = (DWORD*)NewBuffer(2*sizeof(INT));
		pointer[0] = 1;
		pointer[1] = 0;
		return (shrewd_ptr<ProxyBrowser>**)pointer;
	}
	ClientContext* client = reinterpret_cast<ClientContext*>(_rawptr);
	CefRefPtr<CefRequestContext> originRC = ORIGIN(CefBrowser, browser)->GetHost()->GetRequestContext();
	std::vector<CefRefPtr<CefBrowser>> originBrowser;

	client->synchronous.lock();
	{
		CefRefPtr<CefRequestContext> itemRC = nullptr;

		for (size_t i = 0; i < client->browserArrays.size(); i++) {
			BrowserContext& bctx = client->browserArrays[i];
			itemRC = bctx.browser->GetHost()->GetRequestContext();

			if (!originRC && !itemRC) {
				originBrowser.push_back(bctx.browser);
			}
			else if (originRC && itemRC && originRC->IsSame(itemRC)) {
				originBrowser.push_back(bctx.browser);
			}
		}
	}
	client->synchronous.unlock();

	size_t count = originBrowser.size();

	DWORD* pointer = (DWORD*)NewBuffer((2 + count) * sizeof(INT));
	pointer[0] = 1;
	pointer[1] = count;
	shrewd_ptr<ProxyBrowser> tempBrowser = nullptr;
	for (size_t i = 0; i < count; i++)
	{
		DWORD* item = (DWORD*)NewBuffer(sizeof(DWORD));
		tempBrowser = new ProxyBrowser(originBrowser[i]);
		tempBrowser->retain();
		*item = (DWORD)(tempBrowser.get());
		*&pointer[2 + i] = (DWORD)item;
	}

	return (shrewd_ptr<ProxyBrowser>**)pointer;
}

shrewd_ptr<ProxyBrowser>** ProxyClient::GetSameBrowser(void* context) {
	if (!context) {
		DWORD* pointer = (DWORD*)NewBuffer(2 * sizeof(INT));
		pointer[0] = 1;
		pointer[1] = 0;
		return (shrewd_ptr<ProxyBrowser>**)pointer;
	}
	ClientContext* client = reinterpret_cast<ClientContext*>(_rawptr);
	CefRefPtr<CefRequestContext> originRC((CefRequestContext*)context);
	std::vector<CefRefPtr<CefBrowser>> originBrowser;
	client->synchronous.lock();
	{
		CefRefPtr<CefRequestContext> itemRC = nullptr;

		for (size_t i = 0; i < client->browserArrays.size(); i++) {
			BrowserContext& bctx = client->browserArrays[i];
			itemRC = bctx.browser->GetHost()->GetRequestContext();
			if (itemRC && originRC->IsSame(itemRC)) {
				originBrowser.push_back(bctx.browser);
			}
		}
	}
	client->synchronous.unlock();
	size_t count = originBrowser.size();
	DWORD* pointer = (DWORD*)NewBuffer((2 + count) * sizeof(INT));
	pointer[0] = 1;
	pointer[1] = count;
	shrewd_ptr<ProxyBrowser> tempBrowser = nullptr;
	for (size_t i = 0; i < count; i++)
	{
		DWORD* item = (DWORD*)NewBuffer(sizeof(DWORD));
		tempBrowser = new ProxyBrowser(originBrowser[i]);
		tempBrowser->retain();
		*item = (DWORD)(tempBrowser.get());
		*&pointer[2 + i] = (DWORD)item;
	}
	return (shrewd_ptr<ProxyBrowser>**)pointer;
}

shrewd_ptr<ProxyBrowser> ProxyClient::GetSameBrowserWithIndex(void* context, int index) {
	if (!context || index < 0) {
		return nullptr;
	}
	ClientContext* client = reinterpret_cast<ClientContext*>(_rawptr);
	CefRefPtr<CefRequestContext> originRC((CefRequestContext*)context);
	shrewd_ptr<ProxyBrowser> browser = nullptr;

	client->synchronous.lock();
	{
		CefRefPtr<CefRequestContext> itemRC = nullptr;
		int count = 0;
		for (size_t i = 0; i < client->browserArrays.size(); i++) {
			BrowserContext& bctx = client->browserArrays[i];
			itemRC = bctx.browser->GetHost()->GetRequestContext();
			if (itemRC && originRC->IsSame(itemRC)) {
				if (count == index) {
					browser = new ProxyBrowser(bctx.browser);
				}
				else {
					count++;
				}
			}
		}
	}
	client->synchronous.unlock();
	return browser;
}

void ProxyClient::CloseSameBrowser(void* context) {
	if (!context) {
		return;
	}
	ClientContext* client = reinterpret_cast<ClientContext*>(_rawptr);
	CefRefPtr<CefRequestContext> originRC((CefRequestContext*)context);
	shrewd_ptr<ProxyBrowser> browser = nullptr;

	client->synchronous.lock();
	{
		CefRefPtr<CefRequestContext> itemRC = nullptr;
		int count = 0;
		for (size_t i = 0; i < client->browserArrays.size(); i++) {
			BrowserContext& bctx = client->browserArrays[i];
			itemRC = bctx.browser->GetHost()->GetRequestContext();
			if (itemRC && originRC->IsSame(itemRC)) {
				bctx.browser->GetHost()->CloseBrowser(true);
			}
		}
	}
	client->synchronous.unlock();
	return ;
}

void ProxyClient::OnSizeChanged(unsigned int parentWindow, int cx, int cy) {
	HWND hWnd = (HWND)parentWindow;
	ClientContext* context = reinterpret_cast<ClientContext*>(_rawptr);
	CefRefPtr<CefBrowserHost> host = nullptr;
	context->synchronous.lock();
	{
		for (int i = 0; i < context->browserArrays.size();i++) {
			BrowserContext& bctx = context->browserArrays[i];
			host = bctx.browser->GetHost();
			HWND hBrowser = (HWND)host->GetWindowHandle();
			if (GetParent(hBrowser) == hWnd) {
				host->NotifyMoveOrResizeStarted();
				MoveWindow(hBrowser, 0, 0, cx, cy, TRUE);
			}
		}
	}
	context->synchronous.unlock();
}

shrewd_ptr<ProxyListValue> ProxyClient::GetUsetData(shrewd_ptr<ProxyBrowser> browser) {
	CefRefPtr<CefListValue> userData = nullptr;
	ClientContext* context = reinterpret_cast<ClientContext*>(_rawptr);
	if (!browser || !ORIGIN(CefBrowser,browser)) {
		return nullptr;
	}
	context->synchronous.lock();
	{
		for (int i = 0; i < context->browserArrays.size(); i++) {
			BrowserContext& bctx = context->browserArrays[i];
			userData = bctx.userData;
			if (!userData) {
				bctx.userData = userData = CefListValue::Create();
			}
		}
	}
	context->synchronous.unlock();
	if (userData) {
		return new ProxyListValue(userData);
	}
	return nullptr;
}