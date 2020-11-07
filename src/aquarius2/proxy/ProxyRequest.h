#pragma once
#include "../def/def.h"
#include "ProxyPostDataElement.h"

class AQUADLL ProxyRequest : public refcounted {
public:
	ProxyRequest(void* ptr = NULL);
	~ProxyRequest();

public:
    // is valid
    bool IsValid();

public:
    ///
    // Returns true if this object is read-only.
    ///
    /*--cef()--*/
     bool IsReadOnly();

    ///
    // Get the fully qualified URL.
    ///
    /*--cef()--*/
     char* GetURL();

    ///
    // Set the fully qualified URL.
    ///
    /*--cef()--*/
     void SetURL(const char* url);

    ///
    // Get the request method type. The value will default to POST if post data
    // is provided and GET otherwise.
    ///
    /*--cef()--*/
     char* GetMethod();

    ///
    // Set the request method type.
    ///
    /*--cef()--*/
     void SetMethod(const char* method);

    ///
    // Set the referrer URL and policy. If non-empty the referrer URL must be
    // fully qualified with an HTTP or HTTPS scheme component. Any username,
    // password or ref component will be removed.
    ///
    /*--cef(optional_param=referrer_url)--*/
     void SetReferrer(const char* referrer_url, int policy);

    ///
    // Get the referrer URL.
    ///
    /*--cef()--*/
     char* GetReferrerURL();

    ///
    // Get the referrer policy.
    ///
    /*--cef(default_retval=REFERRER_POLICY_DEFAULT)--*/
     int GetReferrerPolicy();

    ///
    // Get the referrer policy.
    ///
    /*--cef(default_retval=REFERRER_POLICY_DEFAULT)--*/
    int GetPostDataElementCount();

    ///
    // Get the post data.
    ///
    /*--cef()--*/
    shrewd_ptr<ProxyPostDataElement>** GetPostDataElements();

    ///
    // Set the post data.
    ///
    /*--cef()--*/
    void AddPostDataElement(shrewd_ptr<ProxyPostDataElement> element);

    ///
    // Set the post data.
    ///
    /*--cef()--*/
    void RemovePostDataElement(shrewd_ptr<ProxyPostDataElement> element);

    ///
    // Set the post data.
    ///
    /*--cef()--*/
    void ClearPostDataElements();

    ///
    // Get the header values. Will not include the Referer value if any.
    ///
    /*--cef()--*/
     char** GetHeaderMap();

    ///
    // Set the header values. If a Referer value exists in the header map it will
    // be removed and ignored.
    ///
    /*--cef()--*/
     void SetHeaderMap(const char* headerMap);

    ///
    // Returns the first header value for |name| or an empty string if not found.
    // Will not return the Referer value if any. Use GetHeaderMap instead if
    // |name| might have multiple values.
    ///
    /*--cef()--*/
     char* GetHeaderByName(const char* name);

    ///
    // Set the header |name| to |value|. If |overwrite| is true any existing
    // values will be replaced with the new value. If |overwrite| is false any
    // existing values will not be overwritten. The Referer value cannot be set
    // using this method.
    ///
    /*--cef(optional_param=value)--*/
     void SetHeaderByName(const char* name,
        const char* value,
        bool overwrite);


    ///
    // Get the resource type for this request. Only available in the browser
    // process.
    ///
    /*--cef(default_retval=RT_SUB_RESOURCE)--*/
     int GetResourceType();

    ///
    // Returns the globally unique identifier for this request or 0 if not
    // specified. Can be used by CefResourceRequestHandler implementations in the
    // browser process to track a single request across multiple callbacks.
    ///
    /*--cef()--*/
     unsigned __int64 GetIdentifier();

     int GetFlags();

     void SetFlags(int flags);

     char* GetFirstPartyForCookies();

     void SetFirstPartyForCookies(const char* url);

     int GetTransitionType();

public:
	PRIME_IMPLEMENT_REFCOUNTING(ProxyRequest);
	AQUA_DECL_PUBLIC_ORIGIN;

private:
	void* _rawptr;
};