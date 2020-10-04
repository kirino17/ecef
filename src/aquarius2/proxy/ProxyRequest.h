#pragma once
#include "../def/def.h"
#include "ProxyPostData.h"

class AQUADLL ProxyRequest : public refcounted {
public:
	ProxyRequest(void* ptr = NULL);
	~ProxyRequest();

public:
    // is valid
    bool IsValid();

	///
	// Create a new CefRequest object.
	///
	/*--cef()--*/
    static shrewd_ptr<ProxyRequest> Create();

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
    // Get the post data.
    ///
    /*--cef()--*/
     shrewd_ptr<ProxyPostData> GetPostData();

    ///
    // Set the post data.
    ///
    /*--cef()--*/
     void SetPostData(shrewd_ptr<ProxyPostData> postData);

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
    // Set all values at one time.
    ///
    /*--cef(optional_param=postData)--*/
     void Set(const char* url,
        const char* method,
        shrewd_ptr<ProxyPostData> postData,
        const char* headerMap);

    ///
    // Get the flags used in combination with CefURLRequest. See
    // cef_urlrequest_flags_t for supported values.
    ///
    /*--cef(default_retval=UR_FLAG_NONE)--*/
     int GetFlags();

    ///
    // Set the flags used in combination with CefURLRequest.  See
    // cef_urlrequest_flags_t for supported values.
    ///
    /*--cef()--*/
     void SetFlags(int flags);

    ///
    // Get the URL to the first party for cookies used in combination with
    // CefURLRequest.
    ///
    /*--cef()--*/
     char* GetFirstPartyForCookies();

    ///
    // Set the URL to the first party for cookies used in combination with
    // CefURLRequest.
    ///
    /*--cef(optional_param=url)--*/
     void SetFirstPartyForCookies(const char* url);

    ///
    // Get the resource type for this request. Only available in the browser
    // process.
    ///
    /*--cef(default_retval=RT_SUB_RESOURCE)--*/
     int GetResourceType();

    ///
    // Get the transition type for this request. Only available in the browser
    // process and only applies to requests that represent a main frame or
    // sub-frame navigation.
    ///
    /*--cef(default_retval=TT_EXPLICIT)--*/
     int GetTransitionType();

    ///
    // Returns the globally unique identifier for this request or 0 if not
    // specified. Can be used by CefResourceRequestHandler implementations in the
    // browser process to track a single request across multiple callbacks.
    ///
    /*--cef()--*/
     unsigned __int64 GetIdentifier();

public:
	PRIME_IMPLEMENT_REFCOUNTING(ProxyRequest);
	AQUA_DECL_PUBLIC_ORIGIN;

private:
	void* _rawptr;
};