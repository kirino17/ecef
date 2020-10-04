#include "ProxyRequestContext.h"
#include "include/cef_request_context.h"
#include "include/cef_request_context_handler.h"

AQUA_PROXY_AUTO_CONSTRUCTOR(ProxyRequestContext,CefRequestContext);

///
// Returns the global context object.
///
/*--cef()--*/
shrewd_ptr<ProxyRequestContext> ProxyRequestContext::GetGlobalContext() {
	return new ProxyRequestContext(CefRequestContext::GetGlobalContext());
}

///
// Creates a new context object with the specified |settings| and optional
// |handler|.
///
/*--cef(optional_param=handler)--*/
shrewd_ptr<ProxyRequestContext> ProxyRequestContext::CreateContext(
	shrewd_ptr<ProxyRequestContextSettings> settings
) {
	if (!settings) {
		return NULL;
	}
	return new ProxyRequestContext(CefRequestContext::CreateContext(
		*(CefRequestContextSettings*)settings->OriginPointer(),
		NULL
	));
}

bool ProxyRequestContext::IsValid() {
	return _rawptr != nullptr;
}

///
// Creates a new context object that shares storage with |other| and uses an
// optional |handler|.
///
/*--cef(capi_name=cef_create_context_shared,optional_param=handler)--*/
shrewd_ptr<ProxyRequestContext> ProxyRequestContext::CreateContextWith(shrewd_ptr<ProxyRequestContext> other) {
	if (!other || !ORIGIN(CefRequestContext, other)) {
		return NULL;
	}
	return new ProxyRequestContext(CefRequestContext::CreateContext(
		ORIGIN(CefRequestContext,other),NULL
	));
}

///
// Returns true if this object is pointing to the same context as |that|
// object.
///
/*--cef()--*/
bool ProxyRequestContext::IsSame(shrewd_ptr<ProxyRequestContext> other) {
	ASSERTQ(false);
	if (!other || !ORIGIN(CefRequestContext, other)) {
		return false;
	}
	return FORWARD(CefRequestContext)->IsSame(ORIGIN(CefRequestContext, other));
}

///
// Returns true if this object is sharing the same storage as |that| object.
///
/*--cef()--*/
bool ProxyRequestContext::IsSharingWith(shrewd_ptr<ProxyRequestContext> other) {
	ASSERTQ(false);
	if (!other || !ORIGIN(CefRequestContext, other)) {
		return false;
	}
	return FORWARD(CefRequestContext)->IsSharingWith(ORIGIN(CefRequestContext, other));
}

///
// Returns true if this object is the global context. The global context is
// used by default when creating a browser or URL request with a NULL context
// argument.
///
/*--cef()--*/
bool ProxyRequestContext::IsGlobal() {
	ASSERTQ(false);
	return FORWARD(CefRequestContext)->IsGlobal();
}

///
// Returns the cache path for this object. If empty an "incognito mode"
// in-memory cache is being used.
///
/*--cef()--*/
char* ProxyRequestContext::GetCachePath() {
	ASSERTQ(NULL);
	assert(NewBuffer);
	CefString string = FORWARD(CefRequestContext)->GetCachePath();
	return ToAnsi(string.c_str(), string.length());
}

///
// Returns the cookie manager for this object. If |callback| is non-NULL it
// will be executed asnychronously on the IO thread after the manager's
// storage has been initialized.
///
/*--cef(optional_param=callback)--*/
shrewd_ptr<ProxyCookieManager> ProxyRequestContext::GetCookieManager() {
	ASSERTQ(NULL);
	CefRefPtr<CefCookieManager> manager = FORWARD(CefRequestContext)->GetCookieManager(nullptr);
	if (manager) {
		return new ProxyCookieManager(manager);
	}
	return NULL;
}

///
// Tells all renderer processes associated with this context to throw away
// their plugin list cache. If |reload_pages| is true they will also reload
// all pages with plugins. ProxyRequestContextHandler::OnBeforePluginLoad may
// be called to rebuild the plugin list cache.
///
/*--cef()--*/
void ProxyRequestContext::PurgePluginListCache(bool reload_pages) {
	ASSERTN();
	FORWARD(CefRequestContext)->PurgePluginListCache(reload_pages);
}

///
// Clears all certificate exceptions that were added as part of handling
// CefRequestHandler::OnCertificateError(). If you call this it is
// recommended that you also call CloseAllConnections() or you risk not
// being prompted again for server certificates if you reconnect quickly.
// If |callback| is non-NULL it will be executed on the UI thread after
// completion.
///
/*--cef(optional_param=callback)--*/
void ProxyRequestContext::ClearCertificateExceptions() {
	ASSERTN();
	FORWARD(CefRequestContext)->ClearCertificateExceptions(nullptr);
}

///
// Clears all HTTP authentication credentials that were added as part of
// handling GetAuthCredentials. If |callback| is non-NULL it will be executed
// on the UI thread after completion.
///
/*--cef(optional_param=callback)--*/
void ProxyRequestContext::ClearHttpAuthCredentials() {
	ASSERTN();
	FORWARD(CefRequestContext)->ClearHttpAuthCredentials(nullptr);
}

///
// Clears all active and idle connections that Chromium currently has.
// This is only recommended if you have released all other CEF objects but
// don't yet want to call CefShutdown(). If |callback| is non-NULL it will be
// executed on the UI thread after completion.
///
/*--cef(optional_param=callback)--*/
void ProxyRequestContext::CloseAllConnections() {
	ASSERTN();
	FORWARD(CefRequestContext)->CloseAllConnections(nullptr);
}