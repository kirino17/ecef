#pragma once
#include "include/cef_v8.h"

class TestAuthorization : public CefV8Handler
{
public:
	TestAuthorization();
	~TestAuthorization();

public:
    bool Execute(const CefString& name,
        CefRefPtr<CefV8Value> object,
        const CefV8ValueList& arguments,
        CefRefPtr<CefV8Value>& retval,
        CefString& exception) OVERRIDE;

public:
    IMPLEMENT_REFCOUNTING(TestAuthorization);
};

