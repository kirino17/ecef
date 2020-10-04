#include "ProxyCookieManager.h"
#include "include/cef_cookie.h"
#include "../def/internalDef.h"
#include "../client/InternalClient.h"
#include <atlconv.h>

AQUA_PROXY_AUTO_CONSTRUCTOR(ProxyCookieManager,CefCookieManager);

///
// Returns the global cookie manager. By default data will be stored at
// CefSettings.cache_path if specified or in memory otherwise. If |callback|
// is non-NULL it will be executed asnychronously on the UI thread after the
// manager's storage has been initialized. Using this method is equivalent to
// calling CefRequestContext::GetGlobalContext()->GetDefaultCookieManager().
///
/*--cef(optional_param=callback)--*/
shrewd_ptr<ProxyCookieManager> ProxyCookieManager::GetGlobalManager() {
    CefRefPtr<CefCookieManager> manager = CefCookieManager::GetGlobalManager(nullptr);
    return new ProxyCookieManager(manager);
}

bool ProxyCookieManager::IsValid() {
    return _rawptr != nullptr;
}

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
void ProxyCookieManager::SetSupportedSchemes(const char* schemes, bool include_defaults) {
    ASSERTN();
    std::vector<CefString> stringArrays;
    if (schemes) {
        SplitString(schemes, ";", stringArrays);
    }
    FORWARD(CefCookieManager)->SetSupportedSchemes(stringArrays, include_defaults, nullptr);
}

///
// Visit all cookies on the UI thread. The returned cookies are ordered by
// longest path, then by earliest creation date. Returns false if cookies
// cannot be accessed.
///
/*--cef()--*/
bool ProxyCookieManager::VisitAllCookies() {
    ASSERTQ(false);
    CefRefPtr<InternalClient> client = InternalClient::GetShareInatance();
    return FORWARD(CefCookieManager)->VisitAllCookies(client);
}

///
// Visit a subset of cookies on the UI thread. The results are filtered by the
// given url scheme, host, domain and path. If |includeHttpOnly| is true
// HTTP-only cookies will also be included in the results. The returned
// cookies are ordered by longest path, then by earliest creation date.
// Returns false if cookies cannot be accessed.
///
/*--cef()--*/
bool ProxyCookieManager::VisitUrlCookies(const char* url, bool includeHttpOnly) {
    ASSERTQ(false);
    if (!url) {
        return false;
    }
    bool result = false;
    {
        CefRefPtr<InternalClient> client = InternalClient::GetShareInatance();
        result = FORWARD(CefCookieManager)->VisitUrlCookies(url, includeHttpOnly, client);
    }
    return result;
}

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
bool ProxyCookieManager::SetCookie(const char* url, shrewd_ptr<ProxyCookie> cookie) {
    ASSERTQ(false);
    if (!cookie) {
        return false;
    }
    return FORWARD(CefCookieManager)->SetCookie(url, *(CefCookie*)cookie->OriginPointer(), nullptr);
}

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
bool ProxyCookieManager::DeleteCookies(const char* url, const char* cookie_name) {
    ASSERTQ(false);
    const wchar_t* tempUrl = L"";
    const wchar_t* tempName = L"";
    USES_CONVERSION;
    
    if (url || strlen(url) > 0) {
        tempUrl = A2W(url);
    }

    if (cookie_name || strlen(cookie_name) > 0) {
        tempName = A2W(cookie_name);
    }

    return FORWARD(CefCookieManager)->DeleteCookies(L"", L"", nullptr);
}

///
// Flush the backing store (if any) to disk. If |callback| is non-NULL it will
// be executed asnychronously on the UI thread after the flush is complete.
// Returns false if cookies cannot be accessed.
///
/*--cef(optional_param=callback)--*/
bool ProxyCookieManager::FlushStore() {
    ASSERTQ(false);
    return FORWARD(CefCookieManager)->FlushStore(nullptr);
}
