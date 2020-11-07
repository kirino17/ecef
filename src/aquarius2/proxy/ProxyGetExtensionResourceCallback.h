#pragma once
#include "../def/def.h"

class AQUADLL ProxyGetExtensionResourceCallback : refcounted {
public:
	ProxyGetExtensionResourceCallback(void* ptr);
	~ProxyGetExtensionResourceCallback();

public:
	void ContinueWithData(unsigned char* data, int size);

	void ContinueWithFile(const char* file);

	void Cancel();
public:
	PRIME_IMPLEMENT_REFCOUNTING(ProxyGetExtensionResourceCallback);
	AQUA_DECL_PUBLIC_ORIGIN;

private:
	void* _rawptr;
};