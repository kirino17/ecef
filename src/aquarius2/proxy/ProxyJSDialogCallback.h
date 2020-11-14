#pragma once
#include "../def/def.h"

class AQUADLL ProxyJSDialogCallback : public refcounted {
public:
	ProxyJSDialogCallback(void* ptr);
	~ProxyJSDialogCallback();

public:
	///
	// Continue the JS dialog request. Set |success| to true if the OK button was
	// pressed. The |user_input| value should be specified for prompt dialogs.
	///
	/*--cef(capi_name=cont,optional_param=user_input)--*/
	void Continue(bool success, const char* user_input);

public:
	PRIME_IMPLEMENT_REFCOUNTING(ProxyJSDialogCallback);
	AQUA_DECL_PUBLIC_ORIGIN;

private:
	void* _rawptr;
};