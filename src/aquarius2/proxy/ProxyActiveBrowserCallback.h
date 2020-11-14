#pragma once
#include "../def/def.h"
#include "ProxyBrowser.h"

class AQUADLL ProxyActiveBrowserCallback : public refcounted {
public:
	ProxyActiveBrowserCallback(void* ptr);
	~ProxyActiveBrowserCallback();

public:
	void SetBrowser(shrewd_ptr<ProxyBrowser> browser);

public:
	PRIME_IMPLEMENT_REFCOUNTING(ProxyActiveBrowserCallback);

private:
	void* _rawptr;
};