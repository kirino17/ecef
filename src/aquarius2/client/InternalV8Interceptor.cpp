#include "InternalV8Interceptor.h"

InternalV8Interceptor::InternalV8Interceptor() {

}

InternalV8Interceptor::~InternalV8Interceptor() {

}

bool InternalV8Interceptor::Get(const CefString& name,
    const CefRefPtr<CefV8Value> object,
    CefRefPtr<CefV8Value>& retval,
    CefString& exception) {
    return false;
 }

bool InternalV8Interceptor::Get(int index,
    const CefRefPtr<CefV8Value> object,
    CefRefPtr<CefV8Value>& retval,
    CefString& exception) {
    return false;
 }

bool InternalV8Interceptor::Set(const CefString& name,
    const CefRefPtr<CefV8Value> object,
    const CefRefPtr<CefV8Value> value,
    CefString& exception) {
    return false;
 }

bool InternalV8Interceptor::Set(int index,
    const CefRefPtr<CefV8Value> object,
    const CefRefPtr<CefV8Value> value,
    CefString& exception) {
    return false;
 }