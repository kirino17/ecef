#pragma once
#include "../def/def.h"
#include "ProxyTime.h"

class AQUADLL ProxyCookie : public refcounted {
public:
	ProxyCookie(void* ptr);
	~ProxyCookie();

public:
    static shrewd_ptr<ProxyCookie> Create();

public:
    // is valid
    bool IsValid();

    ///
    // The cookie name.
    ///
    void SetName(const char* name);
    /*--cef()--*/
    char* GetName();

    ///
    // The cookie value.
    ///
    void SetValue(const char* value);
    /*--cef()--*/
    char* GetValue();

    ///
    // If |domain| is empty a host cookie will be created instead of a domain
    // cookie. Domain cookies are stored with a leading "." and are visible to
    // sub-domains whereas host cookies are not.
    ///
    void SetDomain(const char* domain);
    /*--cef()--*/
    char* GetDomain();

    ///
    // If |path| is non-empty only URLs at or below the path will get the cookie
    // value.
    ///
    void SetPath(const char* path);
    /*--cef()--*/
    char* GetPath();

    ///
    // If |secure| is true the cookie will only be sent for HTTPS requests.
    ///
    void SetSecure(int secure);
    /*--cef()--*/
    int GetSecure();

    ///
    // If |httponly| is true the cookie will only be sent for HTTP requests.
    ///
    void SetHttponly(int httponly);
    /*--cef()--*/
    int GetHttponly();

    ///
    // The cookie creation date. This is automatically populated by the system on
    // cookie creation.
    ///
    void SetCreation(shrewd_ptr<ProxyTime> creation);
    /*--cef()--*/
    shrewd_ptr<ProxyTime> GetCreation();

    ///
    // The cookie last access date. This is automatically populated by the system
    // on access.
    ///
    void SetLastAccess(shrewd_ptr<ProxyTime> last_access);
    /*--cef()--*/
    shrewd_ptr<ProxyTime> GetLastAccess();

    ///
    // The cookie expiration date is only valid if |has_expires| is true.
    ///
    void SetHasExpires(int has_expires);
    /*--cef()--*/
    int GetHasExpires();

    void SetExpires(shrewd_ptr<ProxyTime> expires);
    /*--cef()--*/
    shrewd_ptr<ProxyTime> GetExpires();

public:
	PRIME_IMPLEMENT_REFCOUNTING(ProxyCookie);
	AQUA_DECL_PUBLIC_ORIGIN;

private:
	void* _rawptr;
};