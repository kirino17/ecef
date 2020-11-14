#pragma once
#include "../def/def.h"
#include "ProxyDictionaryValue.h"

class AQUADLL ProxyExtension : public refcounted {
public:
	ProxyExtension(void* ptr);
	~ProxyExtension();

public:
	bool IsValid();

	char* GetIdentifier();

	char* GetPath();

	shrewd_ptr<ProxyDictionaryValue> GetManifest();

	bool IsSame(shrewd_ptr<ProxyExtension> that);

	bool IsLoaded();

	void Unload();

public:
	PRIME_IMPLEMENT_REFCOUNTING(ProxyExtension);
	AQUA_DECL_PUBLIC_ORIGIN;

private:
	void* _rawptr;
};