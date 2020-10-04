#pragma once
#include "../def/def.h"
#include "ProxyCookie.h"

class AQUADLL ProxyCookieManager : public refcounted {
public:
	ProxyCookieManager(void* ptr);
	~ProxyCookieManager();

public:
    // is valid
    bool IsValid();

    ///
    // Returns the global cookie manager. By default data will be stored at
    // CefSettings.cache_path if specified or in memory otherwise. If |callback|
    // is non-NULL it will be executed asnychronously on the UI thread after the
    // manager's storage has been initialized. Using this method is equivalent to
    // calling CefRequestContext::GetGlobalContext()->GetDefaultCookieManager().
    ///
    /*--cef(optional_param=callback)--*/
    static shrewd_ptr<ProxyCookieManager> GetGlobalManager();

    ///
    // Set the schemes supported by this manager. If |include_defaults| is true
    // the default schemes ("http", "https", "ws" and "wss") will also be
    // supported. Calling this method with an empty |schemes| value and
    // |include_defaults| set to false will disable all loading and saving of
    // cookies for this manager. If |callback| is non-NULL it will be executed
    // asnychronously on the UI thread after the change has been applied. Must be
    // called before any cookies are accessed.
    ///
    /*--cef(optional_param=callback)--*/
    void SetSupportedSchemes(const char* schemes, bool include_defaults);

    ///
    // Visit all cookies on the UI thread. The returned cookies are ordered by
    // longest path, then by earliest creation date. Returns false if cookies
    // cannot be accessed.
    ///
    /*--cef()--*/
    bool VisitAllCookies();

    ///
    // Visit a subset of cookies on the UI thread. The results are filtered by the
    // given url scheme, host, domain and path. If |includeHttpOnly| is true
    // HTTP-only cookies will also be included in the results. The returned
    // cookies are ordered by longest path, then by earliest creation date.
    // Returns false if cookies cannot be accessed.
    ///
    /*--cef()--*/
    bool VisitUrlCookies(const char* url, bool includeHttpOnly);

    ///
    // Sets a cookie given a valid URL and explicit user-provided cookie
    // attributes. This function expects each attribute to be well-formed. It will
    // check for disallowed characters (e.g. the ';' character is disallowed
    // within the cookie value attribute) and fail without setting the cookie if
    // such characters are found. If |callback| is non-NULL it will be executed
    // asnychronously on the UI thread after the cookie has been set. Returns
    // false if an invalid URL is specified or if cookies cannot be accessed.
    ///
    /*--cef(optional_param=callback)--*/
    bool SetCookie(const char* url, shrewd_ptr<ProxyCookie> cookie);

    ///
    // Delete all cookies that match the specified parameters. If both |url| and
    // |cookie_name| values are specified all host and domain cookies matching
    // both will be deleted. If only |url| is specified all host cookies (but not
    // domain cookies) irrespective of path will be deleted. If |url| is empty all
    // cookies for all hosts and domains will be deleted. If |callback| is
    // non-NULL it will be executed asnychronously on the UI thread after the
    // cookies have been deleted. Returns false if a non-empty invalid URL is
    // specified or if cookies cannot be accessed. Cookies can alternately be
    // deleted using the Visit*Cookies() methods.
    ///
    /*--cef(optional_param=url,optional_param=cookie_name,
            optional_param=callback)--*/
    bool DeleteCookies(const char* url, const char* cookie_name);

    ///
    // Flush the backing store (if any) to disk. If |callback| is non-NULL it will
    // be executed asnychronously on the UI thread after the flush is complete.
    // Returns false if cookies cannot be accessed.
    ///
    /*--cef(optional_param=callback)--*/
    bool FlushStore();

public:
	PRIME_IMPLEMENT_REFCOUNTING(ProxyCookieManager);
	AQUA_DECL_PUBLIC_ORIGIN;

private:
	void* _rawptr;
};
