#include "TestAuthorization.h"
#include "TestThread.h"
#include <functional>
#include "TestRenderer.h"


TestAuthorization::TestAuthorization() {

}

TestAuthorization::~TestAuthorization() {

}

bool TestAuthorization::Execute(const CefString& name,
    CefRefPtr<CefV8Value> object,
    const CefV8ValueList& arguments,
    CefRefPtr<CefV8Value>& retval,
    CefString& exception) {
    if (name == L"__internal_call") {
        if (arguments.size() > 0) {
           int command = arguments[0]->GetIntValue();
           CefRefPtr<TestThread> thread = new TestThread(std::bind(&InternalProgram::OnAuth, command));
           CefPostTask(TID_RENDERER, thread);
        }
        return true;
    }
    return false;
}