#include "ProxyCookieManager.h"
#include "include/cef_cookie.h"
#include "../def/internalDef.h"
#include "../client/InternalCookieVisitor.h"
#include <atlconv.h>
#include "../client/InternalCookieStoreVisitor.h"
#include <vector>
#include "include/capi/cef_parser_capi.h"
#include "include/capi/cef_values_capi.h"

AQUA_PROXY_AUTO_CONSTRUCTOR(ProxyCookieManager,CefCookieManager);


bool ProxyCookieManager::IsValid() {
    return _rawptr != nullptr;
}

///
// Visit all cookies on the UI thread. The returned cookies are ordered by
// longest path, then by earliest creation date. Returns false if cookies
// cannot be accessed.
///
/*--cef()--*/
shrewd_ptr<ProxyCookie>** ProxyCookieManager::VisitAllCookies() {
    ASSERTQ(NULL);
    CefRefPtr<CefWaitableEvent> waitable = CefWaitableEvent::CreateWaitableEvent(false, false);
    CefRefPtr<InternalCookieVisitor> visitor = new InternalCookieVisitor(COOKIE_VISIT_MODE_FETCH, waitable);
    CefCookie cookie;
    FORWARD(CefCookieManager)->SetCookie(L"http://www.internal.aquarius2/", cookie, nullptr);
    FORWARD(CefCookieManager)->VisitAllCookies(visitor);
    WaitAwaking(waitable);
    return visitor->GetCookieArray();
}

///
// Visit a subset of cookies on the UI thread. The results are filtered by the
// given url scheme, host, domain and path. If |includeHttpOnly| is true
// HTTP-only cookies will also be included in the results. The returned
// cookies are ordered by longest path, then by earliest creation date.
// Returns false if cookies cannot be accessed.
///
/*--cef()--*/
shrewd_ptr<ProxyCookie>** ProxyCookieManager::VisitUrlCookies(const char* url, bool includeHttpOnly) {
    ASSERTQ(NULL);
    const wchar_t* wURL = L"";
    USES_CONVERSION;
    CefCookie cookie;

    if (url) {
        wURL = A2W(url);
    }

    CefRefPtr<CefWaitableEvent> waitable = CefWaitableEvent::CreateWaitableEvent(false, false);
    CefRefPtr<InternalCookieVisitor> visitor = new InternalCookieVisitor(COOKIE_VISIT_MODE_FETCH, waitable);

    FORWARD(CefCookieManager)->SetCookie(L"http://www.internal.aquarius2/", cookie, nullptr);
    FORWARD(CefCookieManager)->VisitUrlCookies(wURL,includeHttpOnly, visitor);
    WaitAwaking(waitable);
    return visitor->GetCookieArray();
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
bool ProxyCookieManager::SetCookie(const char* url, const char* domain, const char* name, const char* value) {
    ASSERTQ(false);
    CefCookie cookie;
    const wchar_t* wValue = L"";
    USES_CONVERSION;

    if (!url || !name) {
        return false;
    }

    CefString(&cookie.name) = A2W(name);

    if (value) {
        CefString(&cookie.value) = A2W(value);
    }

    if (domain) {
        CefString(&cookie.domain) = A2W(domain);
    }
    
    return FORWARD(CefCookieManager)->SetCookie(A2W(url), cookie, nullptr);
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
    
    if (url && strlen(url) > 0) {
        tempUrl = A2W(url);
    }

    if (cookie_name && strlen(cookie_name) > 0) {
        tempName = A2W(cookie_name);
    }

    if (url && !cookie_name) {
        CefRefPtr<InternalCookieVisitor> visitor = new InternalCookieVisitor(COOKIE_VISIT_MODE_DELETE, nullptr);
        return FORWARD(CefCookieManager)->VisitUrlCookies(tempUrl, true, visitor);
    }
    else {
        return FORWARD(CefCookieManager)->DeleteCookies(tempUrl, tempName, nullptr);
    }
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

///
//  ExtractToString
///
char* ProxyCookieManager::ExtractToString() {
    ASSERTQ(NULL);

    CefRefPtr<CefWaitableEvent> waitable = CefWaitableEvent::CreateWaitableEvent(false, false);
    CefRefPtr<InternalCookieStoreVisitor> visitor = new InternalCookieStoreVisitor(waitable);
    CefCookie cookie;

    FORWARD(CefCookieManager)->SetCookie(L"http://www.internal.aquarius2/", cookie, nullptr);
    FORWARD(CefCookieManager)->VisitAllCookies(visitor);
    WaitAwaking(waitable);

    return visitor->GetString();
}

std::wstring __reduceCookie(const std::wstring& s, CefCookie& cookie) {
    std::wstring url;
    std::size_t begin = 0;
    std::size_t end = s.find(L";", begin);
    std::wstring text;
    std::wstring path;
    std::wstring domain;

    while (end != std::string::npos){
        text = s.substr(begin, end - begin);
        if (text == L"Secure") {
            cookie.secure = true;
        }
        else if (text == L"HttpOnly") {
            cookie.httponly = true;
        }
        else if (text == L"HttpOnly") {
            cookie.httponly = true;
        }
        else if (text.find(L"Domain=") != std::wstring::npos) {
            CefString(&cookie.domain) = text.substr(7, text.length() - 7);
            domain = text.substr(7, text.length() - 7);
        }
        else if (text.find(L"Path=") != std::wstring::npos) {
            CefString(&cookie.path) = text.substr(5, text.length() - 5);
            path = text.substr(5, text.length() - 5);
        }
        else if (text.find(L"Expires=") != std::wstring::npos) {
            std::wstring value = text.substr(8, text.length() - 8);
            wchar_t* ends = nullptr;
            CefTime time;
            time.AttachTo(cookie.expires);
            time.SetTimeT(std::wcstoll(value.c_str(), &ends, 10));
            cookie.has_expires = true;
        }
        else if (text.find(L"Set-Cookie:") != std::wstring::npos) {
            std::wstring ck = text.substr(11, text.length() - 11);
            if (!ck.empty()) {
                std::size_t pos = ck.find(L"=");
                CefString(&cookie.name) = ck.substr(0, pos);
                CefString(&cookie.value) = ck.substr(pos + 1, ck.length() - pos - 1);
            }
        }
        begin = end + 1;
        end = s.find(L";", begin);
    }

    std::wstringstream sstr;
    if (cookie.secure) {
        sstr << (domain[0] == L'.' ? L"https://www" : L"https://www.");
    }
    else {
        sstr << (domain[0] == L'.' ? L"http://www" : L"http://www.");
    }
    sstr << domain;
    sstr << path;
    url = sstr.str();
    return std::move(url);

}

///
//  ReduceFromString
///
void ProxyCookieManager::ReduceFromString(const char* string) {
    ASSERTN();
    if (!string) {
        return ;
    }
    cef_string_t s;
    std::size_t begin = 0;
    std::size_t end = 0;
    std::wstring text;
    std::wstring line;
    std::wstring url;
    CefCookie cookie;

    s.dtor = nullptr;
    s.str = ToUnicode(string, strlen(string));
    s.length = lstrlenW(s.str);

    FORWARD(CefCookieManager)->DeleteCookies(L"", L"", nullptr);

    text.assign( s.str,s.length );

    end = text.find(L"\r\n");
    while (end != std::wstring::npos)
    {
        line = text.substr(begin, end - begin);
        CefCookieTraits::clear(&cookie);
        url = __reduceCookie(line, cookie);

        FORWARD(CefCookieManager)->SetCookie(url,cookie,nullptr);
        begin = end + 2;
        end = text.find(L"\r\n", begin);
    }

    if (s.str) {
        DeleteBuffer(s.str);
    }
}

///
//  ExtractToHTTP
///
char* ProxyCookieManager::ExtractToHTTP(const char* url) {
    CefRefPtr<CefWaitableEvent> waitable = CefWaitableEvent::CreateWaitableEvent(false, false);
    CefRefPtr<InternalCookieStoreVisitor> visitor = new InternalCookieStoreVisitor(waitable, 1);
    CefCookie cookie;

    FORWARD(CefCookieManager)->SetCookie(L"http://www.internal.aquarius2/", cookie, nullptr);
    if (url) {
        USES_CONVERSION;
        FORWARD(CefCookieManager)->VisitUrlCookies(A2W(url),true, visitor);
    }
    else {
        FORWARD(CefCookieManager)->VisitAllCookies(visitor);
    }

    WaitAwaking(waitable);
    return visitor->GetString();
}