#include "ProxyRequest.h"
#include "include/cef_request.h"
#include <atlconv.h>
#include <sstream>
#include "../def/internalDef.h"

AQUA_PROXY_AUTO_CONSTRUCTOR(ProxyRequest,CefRequest);

///
// Create a new CefRequest object.
///
/*--cef()--*/
shrewd_ptr<ProxyRequest> ProxyRequest::Create() {
	return new ProxyRequest(CefRequest::Create());
}

bool ProxyRequest::IsValid() {
    return _rawptr != nullptr;
}

///
// Returns true if this object is read-only.
///
/*--cef()--*/
bool ProxyRequest::IsReadOnly() {
    ASSERTQ(false);
    return FORWARD(CefRequest)->IsReadOnly();
}

///
// Get the fully qualified URL.
///
/*--cef()--*/
char* ProxyRequest::GetURL() {
    ASSERTQ(NULL);
    CefString string = FORWARD(CefRequest)->GetURL();
    return ToAnsi(string.c_str(), string.length());
}

///
// Set the fully qualified URL.
///
/*--cef()--*/
void ProxyRequest::SetURL(const char* url) {
    ASSERTN();
    if (!url) {
        return;
    }
    USES_CONVERSION;
    FORWARD(CefRequest)->SetURL(A2W(url));
}

///
// Get the request method type. The value will default to POST if post data
// is provided and GET otherwise.
///
/*--cef()--*/
char* ProxyRequest::GetMethod() {
    ASSERTQ(NULL);
    CefString string = FORWARD(CefRequest)->GetMethod();
    return ToAnsi(string.c_str(), string.length());
}

///
// Set the request method type.
///
/*--cef()--*/
void ProxyRequest::SetMethod(const char* method) {
    ASSERTN();
    FORWARD(CefRequest)->SetMethod(method);
}

///
// Set the referrer URL and policy. If non-empty the referrer URL must be
// fully qualified with an HTTP or HTTPS scheme component. Any username,
// password or ref component will be removed.
///
/*--cef(optional_param=referrer_url)--*/
void ProxyRequest::SetReferrer(const char* referrer_url, int policy) {
    ASSERTN();
    if (!referrer_url) {
        return;
    }
    FORWARD(CefRequest)->SetReferrer(referrer_url, (cef_referrer_policy_t)policy);
}

///
// Get the referrer URL.
///
/*--cef()--*/
char* ProxyRequest::GetReferrerURL() {
    ASSERTQ(NULL);
    CefString string = FORWARD(CefRequest)->GetReferrerURL();
    return ToAnsi(string.c_str(), string.length());
}

///
// Get the referrer policy.
///
/*--cef(default_retval=REFERRER_POLICY_DEFAULT)--*/
int ProxyRequest::GetReferrerPolicy() {
    ASSERTQ(0);
    return FORWARD(CefRequest)->GetReferrerPolicy();
}

///
// Get the post data.
///
/*--cef()--*/
shrewd_ptr<ProxyPostData> ProxyRequest::GetPostData() {
    ASSERTQ(NULL);
    return new ProxyPostData( FORWARD(CefRequest)->GetPostData() );
}

///
// Set the post data.
///
/*--cef()--*/
void ProxyRequest::SetPostData(shrewd_ptr<ProxyPostData> postData) {
    ASSERTN();
    if (!postData || !ORIGIN(CefPostData, postData)) {
        return;
    }
    FORWARD(CefRequest)->SetPostData(ORIGIN(CefPostData, postData));
}

///
// Get the header values. Will not include the Referer value if any.
///
/*--cef()--*/
char** ProxyRequest::GetHeaderMap() {
    ASSERTQ(0);
    CefRequest::HeaderMap headers;
    std::vector<CefString> items;
    FORWARD(CefRequest)->GetHeaderMap(headers);
    std::wstringstream strbuf;
    for (auto v: headers){
        strbuf.clear();
        strbuf.str(L"");

        strbuf << v.first.c_str() << L":" << v.second.c_str();

        const auto& s = strbuf.str();
        items.emplace_back(s);
    }
    return CreateEPLStringArray(items);
}

///
// Set the header values. If a Referer value exists in the header map it will
// be removed and ignored.
///
/*--cef()--*/
void ProxyRequest::SetHeaderMap(const char* headerMap) {
    ASSERTN();
    if (!headerMap) {
        return;
    }
    std::vector<std::wstring> stringArrays;
    CefRequest::HeaderMap headers;
    int count = SplitString(headerMap, "\r\n", stringArrays);
    std::wstring key, value;
    for (size_t i = 0; i < count; i++)
    {
        const wchar_t* buffer = stringArrays[i].c_str();
        std::size_t end = stringArrays[i].find(':');
        if (end != std::wstring::npos) {
            key.assign(buffer, end);
            value.assign(&buffer[end+1], stringArrays[i].length() - end - 1);
            headers.insert(std::make_pair(key,value));
        }
    }
    FORWARD(CefRequest)->SetHeaderMap(headers);
}

///
// Returns the first header value for |name| or an empty string if not found.
// Will not return the Referer value if any. Use GetHeaderMap instead if
// |name| might have multiple values.
///
/*--cef()--*/
char* ProxyRequest::GetHeaderByName(const char* name) {
    ASSERTQ(NULL);
    assert(NewBuffer);
    if (!name) {
        return NULL;
    }
    CefString value = FORWARD(CefRequest)->GetHeaderByName(name);
    return ToAnsi(value.c_str(),value.length());
}

///
// Set the header |name| to |value|. If |overwrite| is true any existing
// values will be replaced with the new value. If |overwrite| is false any
// existing values will not be overwritten. The Referer value cannot be set
// using this method.
///
/*--cef(optional_param=value)--*/
void ProxyRequest::SetHeaderByName(const char* name,
    const char* value,
    bool overwrite) {
    ASSERTN();
    if (!name) {
        return;
    }
    USES_CONVERSION;
    if (value) {
        FORWARD(CefRequest)->SetHeaderByName(name, A2W(value), overwrite);
    }
    else {
        FORWARD(CefRequest)->SetHeaderByName(name, L"", overwrite);
    }
}

///
// Set all values at one time.
///
/*--cef(optional_param=postData)--*/
void ProxyRequest::Set(const char* url,
    const char* method,
    shrewd_ptr<ProxyPostData> postData,
    const char* headerMap) {
    ASSERTN();
    if (!url || !method) {
        return;
    }
    CefRequest::HeaderMap headers;
    if (headerMap) {
        std::vector<std::wstring> stringArrays;
        int count = SplitString(headerMap, "\r\n", stringArrays);
        std::wstring key, value;
        for (size_t i = 0; i < count; i++)
        {
            const wchar_t* buffer = stringArrays[i].c_str();
            std::size_t end = stringArrays[i].find(':');
            if (end != std::wstring::npos) {
                key.assign(buffer, end);
                value.assign(&buffer[end + 1], stringArrays[i].length() - end - 1);
                headers.insert(std::make_pair(key, value));
            }
        }
    }
    USES_CONVERSION;
    if (!postData || !ORIGIN(CefPostData, postData)) {
        FORWARD(CefRequest)->Set(A2W(url), method, nullptr, headers);
    }
    else {
        FORWARD(CefRequest)->Set(A2W(url), method, ORIGIN(CefPostData, postData), headers);
    }
}

///
// Get the flags used in combination with CefURLRequest. See
// cef_urlrequest_flags_t for supported values.
///
/*--cef(default_retval=UR_FLAG_NONE)--*/
int ProxyRequest::GetFlags() {
    ASSERTQ(0);
    return FORWARD(CefRequest)->GetFlags();
}

///
// Set the flags used in combination with CefURLRequest.  See
// cef_urlrequest_flags_t for supported values.
///
/*--cef()--*/
void ProxyRequest::SetFlags(int flags) {
    ASSERTN();
    FORWARD(CefRequest)->SetFlags(flags);
}

///
// Get the URL to the first party for cookies used in combination with
// CefURLRequest.
///
/*--cef()--*/
char* ProxyRequest::GetFirstPartyForCookies() {
    ASSERTQ(NULL);
    assert(NewBuffer);
    CefString string = FORWARD(CefRequest)->GetFirstPartyForCookies();
    return ToAnsi(string.c_str(), string.length());
}

///
// Set the URL to the first party for cookies used in combination with
// CefURLRequest.
///
/*--cef(optional_param=url)--*/
void ProxyRequest::SetFirstPartyForCookies(const char* url) {
    ASSERTN();
    if (!url) {
        return;
    }
    USES_CONVERSION;
    FORWARD(CefRequest)->SetFirstPartyForCookies(A2W(url));
}

///
// Get the resource type for this request. Only available in the browser
// process.
///
/*--cef(default_retval=RT_SUB_RESOURCE)--*/
int ProxyRequest::GetResourceType() {
    ASSERTQ(0);
    return FORWARD(CefRequest)->GetResourceType();
}

///
// Get the transition type for this request. Only available in the browser
// process and only applies to requests that represent a main frame or
// sub-frame navigation.
///
/*--cef(default_retval=TT_EXPLICIT)--*/
int ProxyRequest::GetTransitionType() {
    ASSERTQ(0);
    return FORWARD(CefRequest)->GetTransitionType();
}

///
// Returns the globally unique identifier for this request or 0 if not
// specified. Can be used by CefResourceRequestHandler implementations in the
// browser process to track a single request across multiple callbacks.
///
/*--cef()--*/
unsigned __int64 ProxyRequest::GetIdentifier() {
    ASSERTQ(0);
    return FORWARD(CefRequest)->GetIdentifier();
}