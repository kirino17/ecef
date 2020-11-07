#pragma once
#include "../def/def.h"

class AQUADLL ProxyCookie : public refcounted {
public:
	ProxyCookie(void* ptr);
	~ProxyCookie();

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
    void SetCreation(double creation);

    /*--cef()--*/
    double GetCreation();

    ///
    // The cookie last access date. This is automatically populated by the system
    // on access.
    ///
    void SetLastAccess(double last_access);

    /*--cef()--*/
    double GetLastAccess();

    ///
    // The cookie expiration date is only valid if |has_expires| is true.
    ///
    void SetHasExpires(int has_expires);

    /*--cef()--*/
    int GetHasExpires();

    /*--cef()--*/
    void SetExpires(double expires);

    /*--cef()--*/
    double GetExpires();

public:
	PRIME_IMPLEMENT_REFCOUNTING(ProxyCookie);
	AQUA_DECL_PUBLIC_ORIGIN;

private:
	void* _rawptr;
};