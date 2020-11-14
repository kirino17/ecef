#include "ProxyRequest.h"
#include "include/cef_request.h"
#include <atlconv.h>
#include <sstream>
#include "../def/internalDef.h"

AQUA_PROXY_AUTO_CONSTRUCTOR(ProxyRequest,CefRequest);

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
    USES_CONVERSION;
    FORWARD(CefRequest)->SetMethod(A2W(method));
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
    USES_CONVERSION;
    FORWARD(CefRequest)->SetReferrer(A2W(referrer_url), (cef_referrer_policy_t)policy);
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
// Get the referrer policy.
///
/*--cef(default_retval=REFERRER_POLICY_DEFAULT)--*/
int ProxyRequest::GetPostDataElementCount() {
    ASSERTQ(0);
    CefRefPtr<CefPostData> postData = FORWARD(CefRequest)->GetPostData();
    if (!postData) {
        return 0;
    }
    return postData->GetElementCount();
}

///
// Get the post data.
///
/*--cef()--*/
shrewd_ptr<ProxyPostDataElement>** ProxyRequest::GetPostDataElements() {
    ASSERTARRAY(shrewd_ptr<ProxyPostDataElement>);
    CefRefPtr<CefPostData> postData = FORWARD(CefRequest)->GetPostData();
    std::vector<CefRefPtr<CefPostDataElement>> elements;
    if (!postData || postData->GetElementCount() == 0) {

        DWORD* eplArray = (DWORD*)NewBuffer(2 * sizeof(DWORD));
        *(eplArray + 0) = 1;
        *(eplArray + 1) = 0;

        return (shrewd_ptr<ProxyPostDataElement>**)eplArray;
    }
    postData->GetElements(elements);
    DWORD* eplArray = (DWORD*)NewBuffer((2 + elements.size()) * sizeof(DWORD));
    *(eplArray + 0) = 1;
    *(eplArray + 1) = elements.size();
    shrewd_ptr<ProxyPostDataElement> tempElement = nullptr;

    for (size_t i = 0; i < elements.size(); i++){
        DWORD* item = (DWORD*)NewBuffer(sizeof(DWORD));
        tempElement = new ProxyPostDataElement(elements[i]);
        tempElement->retain();
        *item =(DWORD)tempElement.get();
        *&eplArray[i+2] = (DWORD)(item);
    }
    return (shrewd_ptr<ProxyPostDataElement>**)eplArray;
}

///
// Set the post data.
///
/*--cef()--*/
void ProxyRequest::AddPostDataElement(shrewd_ptr<ProxyPostDataElement> element) {
    ASSERTN();
    CefRefPtr<CefPostData> postData;
    if (!element || !ORIGIN(CefPostDataElement, element)) {
        return;
    }
    postData = FORWARD(CefRequest)->GetPostData();
    if (!postData) {
        postData = CefPostData::Create();
        FORWARD(CefRequest)->SetPostData(postData);
    }

    postData->AddElement(ORIGIN(CefPostDataElement, element));
}

///
// Set the post data.
///
/*--cef()--*/
void ProxyRequest::RemovePostDataElement(shrewd_ptr<ProxyPostDataElement> element) {
    ASSERTN();
    CefRefPtr<CefPostData> postData;
    if (!element || !ORIGIN(CefPostDataElement, element)) {
        return;
    }
    postData = FORWARD(CefRequest)->GetPostData();
    if (!postData) {
        return;
    }
    postData->RemoveElement(ORIGIN(CefPostDataElement, element));
}

///
// Set the post data.
///
/*--cef()--*/
void ProxyRequest::ClearPostDataElements() {
    ASSERTN();
    CefRefPtr<CefPostData> postData = FORWARD(CefRequest)->GetPostData();
    if (!postData) {
        return;
    }
    postData->RemoveElements();
}

///
// Get the header values. Will not include the Referer value if any.
///
/*--cef()--*/
char** ProxyRequest::GetHeaderMap() {
    ASSERTARRAY(char);
    CefRequest::HeaderMap headers;
    std::vector<CefString> items;
    FORWARD(CefRequest)->GetHeaderMap(headers);
    std::wstringstream strbuf;
    for (auto v: headers){
        strbuf.clear();
        strbuf.str(L"");
        if (v.first.length() > 0 && v.second.length() > 0) {
            strbuf << v.first.c_str() << L":" << v.second.c_str();
        }
        items.emplace_back(strbuf.str());
    }
    if (items.empty()) {
        DWORD* pointer = (DWORD*)NewBuffer(sizeof(INT) * (2));
        *(pointer + 0) = 1;
        *(pointer + 1) = 0;
        return (char**)pointer;
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
// Get the resource type for this request. Only available in the browser
// process.
///
/*--cef(default_retval=RT_SUB_RESOURCE)--*/
int ProxyRequest::GetResourceType() {
    ASSERTQ(0);
    return FORWARD(CefRequest)->GetResourceType();
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

int ProxyRequest::GetFlags() {
    ASSERTQ(0);
    return FORWARD(CefRequest)->GetFlags();
}

void ProxyRequest::SetFlags(int flags) {
    ASSERTN();
    FORWARD(CefRequest)->SetFlags(flags);
}

char* ProxyRequest::GetFirstPartyForCookies() {
    ASSERTQ(NULL);
    CefString string = FORWARD(CefRequest)->GetFirstPartyForCookies();
    if (!string.empty()) {
        return ToAnsi(string.c_str(),string.length());
    }
    return NULL;
}

void ProxyRequest::SetFirstPartyForCookies(const char* url) {
    ASSERTN();
    USES_CONVERSION;
    FORWARD(CefRequest)->SetFirstPartyForCookies(url);
}

int ProxyRequest::GetTransitionType() {
    ASSERTQ(0);
    return FORWARD(CefRequest)->GetTransitionType();
}