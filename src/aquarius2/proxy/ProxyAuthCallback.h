#pragma once
#include "../def/def.h"

class AQUADLL ProxyAuthCallback : public refcounted {
public:
	ProxyAuthCallback(void* ptr);
	~ProxyAuthCallback();

public:
    ///
    // Continue the authentication request.
    ///
    /*--cef(capi_name=cont,optional_param=username,optional_param=password)--*/
    void Continue(const char* username, const char* password);

    ///
    // Cancel the authentication request.
    ///
    /*--cef()--*/
    void Cancel();
public:
	PRIME_IMPLEMENT_REFCOUNTING(ProxyAuthCallback);
	AQUA_DECL_PUBLIC_ORIGIN;

private:
	void* _rawptr;
};