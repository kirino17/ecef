#pragma once
#include "../def/def.h"
#include "ProxyCookieManager.h"
#include "ProxyRequestContextSettings.h"

class AQUADLL ProxyRequestContext : public refcounted {
public:
	ProxyRequestContext(void* ptr);
	~ProxyRequestContext();

public:
	///
	// Returns the global context object.
	///
/*--cef()--*/
	static shrewd_ptr<ProxyRequestContext> GetGlobalContext();

	///
	// Creates a new context object with the specified |settings| and optional
	// |handler|.
	///
	/*--cef(optional_param=handler)--*/
	static shrewd_ptr<ProxyRequestContext> CreateContext(
		shrewd_ptr<ProxyRequestContextSettings> settings
    );

	///
	// Creates a new context object that shares storage with |other| and uses an
	// optional |handler|.
	///
	/*--cef(capi_name=cef_create_context_shared,optional_param=handler)--*/
	static shrewd_ptr<ProxyRequestContext> CreateContextWith(shrewd_ptr<ProxyRequestContext> other);

public:
    // is valid
    bool IsValid();

    ///
    // Returns true if this object is pointing to the same context as |that|
    // object.
    ///
    /*--cef()--*/
    bool IsSame(shrewd_ptr<ProxyRequestContext> other);

    ///
    // Returns true if this object is sharing the same storage as |that| object.
    ///
    /*--cef()--*/
    bool IsSharingWith(shrewd_ptr<ProxyRequestContext> other);

    ///
    // Returns true if this object is the global context. The global context is
    // used by default when creating a browser or URL request with a NULL context
    // argument.
    ///
    /*--cef()--*/
    bool IsGlobal();

    ///
    // Returns the cache path for this object. If empty an "incognito mode"
    // in-memory cache is being used.
    ///
    /*--cef()--*/
    char* GetCachePath();

    ///
    // Returns the cookie manager for this object. If |callback| is non-NULL it
    // will be executed asnychronously on the IO thread after the manager's
    // storage has been initialized.
    ///
    /*--cef(optional_param=callback)--*/
    shrewd_ptr<ProxyCookieManager> GetCookieManager();

    ///
    // Tells all renderer processes associated with this context to throw away
    // their plugin list cache. If |reload_pages| is true they will also reload
    // all pages with plugins. ProxyRequestContextHandler::OnBeforePluginLoad may
    // be called to rebuild the plugin list cache.
    ///
    /*--cef()--*/
    void PurgePluginListCache(bool reload_pages);

    ///
    // Clears all certificate exceptions that were added as part of handling
    // CefRequestHandler::OnCertificateError(). If you call this it is
    // recommended that you also call CloseAllConnections() or you risk not
    // being prompted again for server certificates if you reconnect quickly.
    // If |callback| is non-NULL it will be executed on the UI thread after
    // completion.
    ///
    /*--cef(optional_param=callback)--*/
    void ClearCertificateExceptions();

    ///
    // Clears all HTTP authentication credentials that were added as part of
    // handling GetAuthCredentials. If |callback| is non-NULL it will be executed
    // on the UI thread after completion.
    ///
    /*--cef(optional_param=callback)--*/
    void ClearHttpAuthCredentials();

    ///
    // Clears all active and idle connections that Chromium currently has.
    // This is only recommended if you have released all other CEF objects but
    // don't yet want to call CefShutdown(). If |callback| is non-NULL it will be
    // executed on the UI thread after completion.
    ///
    /*--cef(optional_param=callback)--*/
    void CloseAllConnections();

public:
	PRIME_IMPLEMENT_REFCOUNTING(ProxyRequestContext);
	AQUA_DECL_PUBLIC_ORIGIN;

private:
	void* _rawptr;
};