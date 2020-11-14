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
    // Visit all cookies on the UI thread. The returned cookies are ordered by
    // longest path, then by earliest creation date. Returns false if cookies
    // cannot be accessed.
    ///
    /*--cef()--*/
    shrewd_ptr<ProxyCookie>** VisitAllCookies();

    ///
    // Visit a subset of cookies on the UI thread. The results are filtered by the
    // given url scheme, host, domain and path. If |includeHttpOnly| is true
    // HTTP-only cookies will also be included in the results. The returned
    // cookies are ordered by longest path, then by earliest creation date.
    // Returns false if cookies cannot be accessed.
    ///
    /*--cef()--*/
    shrewd_ptr<ProxyCookie>** VisitUrlCookies(const char* url, bool includeHttpOnly);

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
    bool SetCookie(const char* url, const char* domain, const char* name, const char* value);

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

    ///
    //  ExtractToString
    ///
    char* ExtractToString();

    ///
    //  ReduceFromString
    ///
    void ReduceFromString(const char* string);

    ///
    //  ExtractToHTTP
    ///
    char* ExtractToHTTP(const char* url);

public:
	PRIME_IMPLEMENT_REFCOUNTING(ProxyCookieManager);
	AQUA_DECL_PUBLIC_ORIGIN;

private:
	void* _rawptr;
};
