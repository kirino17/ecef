#include "ProxyResponse.h"
#include "include/cef_response.h"
#include <vector>
#include "../def/internalDef.h"

AQUA_PROXY_AUTO_CONSTRUCTOR(ProxyResponse,CefResponse);


bool ProxyResponse::IsValid() {
    return _rawptr != nullptr;
}

///
// Returns true if this object is read-only.
///
/*--cef()--*/
bool ProxyResponse::IsReadOnly() {
    ASSERTQ(false);
    return FORWARD(CefResponse)->IsReadOnly();
}

///
// Get the response error code. Returns ERR_NONE if there was no error.
///
/*--cef(default_retval=ERR_NONE)--*/
int ProxyResponse::GetError() {
    ASSERTQ(0);
    return FORWARD(CefResponse)->GetError();
}

///
// Set the response error code. This can be used by custom scheme handlers
// to return errors during initial request processing.
///
/*--cef()--*/
void ProxyResponse::SetError(int error) {
    ASSERTN();
    FORWARD(CefResponse)->SetError((cef_errorcode_t)error);
}

///
// Get the response status code.
///
/*--cef()--*/
int ProxyResponse::GetStatus() {
    ASSERTQ(0);
    return FORWARD(CefResponse)->GetStatus();
}

///
// Set the response status code.
///
/*--cef()--*/
void ProxyResponse::SetStatus(int status) {
    ASSERTN();
    FORWARD(CefResponse)->SetStatus(status);
}

///
// Get the response status text.
///
/*--cef()--*/
char* ProxyResponse::GetStatusText() {
    ASSERTQ(NULL);
    CefString string = FORWARD(CefResponse)->GetStatusText();
    return ToAnsi(string.c_str(), string.length());
}

///
// Set the response status text.
///
/*--cef(optional_param=statusText)--*/
void ProxyResponse::SetStatusText(const char* statusText) {
    ASSERTN();
    if (!statusText) {
        return;
    }
    FORWARD(CefResponse)->SetStatusText(statusText);
}

///
// Get the response mime type.
///
/*--cef()--*/
char* ProxyResponse::GetMimeType() {
    ASSERTQ(NULL);
    CefString string = FORWARD(CefResponse)->GetMimeType();
    return ToAnsi(string.c_str(), string.length());
}

///
// Set the response mime type.
///
/*--cef(optional_param=mimeType)--*/
void ProxyResponse::SetMimeType(const char* mimeType) {
    ASSERTN();
    if (!mimeType) {
        return;
    }
    FORWARD(CefResponse)->SetMimeType(mimeType);
}

///
// Get the response charset.
///
/*--cef()--*/
char* ProxyResponse::GetCharset() {
    ASSERTQ(NULL);
    CefString string = FORWARD(CefResponse)->GetMimeType();
    return ToAnsi(string.c_str(), string.length());
}

///
// Set the response charset.
///
/*--cef(optional_param=charset)--*/
void ProxyResponse::SetCharset(const char* charset) {
    ASSERTN();
    if (!charset) {
        return;
    }
    FORWARD(CefResponse)->SetCharset(charset);
}

///
// Get the value for the specified response header field.
///
/*--cef()--*/
char* ProxyResponse::GetHeaderByName(const char* name) {
    ASSERTQ(NULL);
    if (!name) {
        return NULL;
    }
    CefString string = FORWARD(CefResponse)->GetHeaderByName(name);
    return ToAnsi(string.c_str(), string.length());
}

///
// Set the header |name| to |value|. If |overwrite| is true any existing
// values will be replaced with the new value. If |overwrite| is false any
// existing values will not be overwritten.
///
/*--cef(optional_param=value)--*/
void ProxyResponse::SetHeaderByName(const char* name,
    const char* value,
    bool overwrite) {
    ASSERTN();
    if (!name) {
        return;
    }
    FORWARD(CefResponse)->SetHeaderByName(name, value, overwrite);
}

///
// Get all response header fields.
///
/*--cef()--*/
char** ProxyResponse::GetHeaderMap() {
    ASSERTARRAY(char);
    CefRequest::HeaderMap headers;
    std::vector<CefString> items;
    FORWARD(CefResponse)->GetHeaderMap(headers);
    std::wstringstream strbuf;
    for (auto v : headers) {
        strbuf.clear();
        strbuf.str(L"");

        if (v.first.length() > 0 && v.second.length() > 0) {
            strbuf << v.first.c_str() << L":" << v.second.c_str();
            items.emplace_back(strbuf.str());
        }
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
// Set all response header fields.
///
/*--cef()--*/
void ProxyResponse::SetHeaderMap(const char* headerMap) {
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
            value.assign(&buffer[end + 1], stringArrays[i].length() - end - 1);
            headers.insert(std::make_pair(key, value));
        }
    }
    FORWARD(CefResponse)->SetHeaderMap(headers);
}

///
// Get the resolved URL after redirects or changed as a result of HSTS.
///
/*--cef()--*/
char* ProxyResponse::GetURL() {
    ASSERTQ(NULL);
    CefString string = FORWARD(CefResponse)->GetMimeType();
    return ToAnsi(string.c_str(), string.length());
}

///
// Set the resolved URL after redirects or changed as a result of HSTS.
///
/*--cef(optional_param=url)--*/
void ProxyResponse::SetURL(const char* url) {
    ASSERTN();
    if (!url) {
        return;
    }
    FORWARD(CefResponse)->SetURL(url);
}