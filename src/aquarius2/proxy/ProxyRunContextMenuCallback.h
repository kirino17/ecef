#pragma once
#include "../def/def.h"

class AQUADLL ProxyRunContextMenuCallback : public refcounted {
public:
	ProxyRunContextMenuCallback(void* ptr);
	~ProxyRunContextMenuCallback();

public:
    ///
    // Complete context menu display by selecting the specified |command_id| and
    // |event_flags|.
    ///
    /*--cef(capi_name=cont)--*/
    void Continue(int command_id, int event_flags);

    ///
    // Cancel context menu display.
    ///
    /*--cef()--*/
    void Cancel();

public:
	PRIME_IMPLEMENT_REFCOUNTING(ProxyRunContextMenuCallback);
	AQUA_DECL_PUBLIC_ORIGIN;

private:
	void* _rawptr;
};