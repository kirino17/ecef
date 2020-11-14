#pragma once
#include "../def/def.h"

class AQUADLL ProxyQueryCallback : public refcounted {
public:
	ProxyQueryCallback(void* ptr);
	~ProxyQueryCallback();

public:
    void Success(const char* response);

    void Failure(int error_code, const char* error_message);

public:
	PRIME_IMPLEMENT_REFCOUNTING(ProxyQueryCallback);
	AQUA_DECL_PUBLIC_ORIGIN; 

private:
	void* _rawptr;
};