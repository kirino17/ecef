#pragma once
#include "include/cef_v8.h"

class InternalV8Interceptor : public CefV8Interceptor {
public:
	InternalV8Interceptor();
	~InternalV8Interceptor();

public:
    virtual bool Get(const CefString& name,
        const CefRefPtr<CefV8Value> object,
        CefRefPtr<CefV8Value>& retval,
        CefString& exception) OVERRIDE;

    virtual bool Get(int index,
        const CefRefPtr<CefV8Value> object,
        CefRefPtr<CefV8Value>& retval,
        CefString& exception) OVERRIDE;

    virtual bool Set(const CefString& name,
        const CefRefPtr<CefV8Value> object,
        const CefRefPtr<CefV8Value> value,
        CefString& exception) OVERRIDE;

    virtual bool Set(int index,
        const CefRefPtr<CefV8Value> object,
        const CefRefPtr<CefV8Value> value,
        CefString& exception) OVERRIDE;

public:
    IMPLEMENT_REFCOUNTING(InternalV8Interceptor);

};