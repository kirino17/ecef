#pragma once
#include "../def/def.h"

class AQUADLL ProxyRequestCallback : public refcounted {
public:
    ProxyRequestCallback(void* ptr);
    ~ProxyRequestCallback();

public:
    ///
    // Continue the url request. If |allow| is true the request will be continued.
    // Otherwise, the request will be canceled.
    ///
    /*--cef(capi_name=cont)--*/
    void Continue(bool allow);

    ///
    // Cancel the url request.
    ///
    /*--cef()--*/
    void Cancel();

public:
    PRIME_IMPLEMENT_REFCOUNTING(ProxyRequestCallback);
    AQUA_DECL_PUBLIC_ORIGIN;

private:
    void* _rawptr;
};