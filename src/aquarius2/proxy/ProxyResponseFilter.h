#pragma once
#include "../def/def.h"
#include "ProxyValue.h"

class AQUADLL ProxyResponseFilter : refcounted {
public:
	ProxyResponseFilter(void* ptr);
	~ProxyResponseFilter();

public:
	///
	// is valid
	///
	bool IsValid();

	///
	// get url
	///
	char* GetURL();

	///
	// get mime type
	///
	char* GetMimeType();

	///
	// get total bytes
	//
	int GetTotalBytes();

	///
	// get buffer
	///
	unsigned char* GetResource();

	///
	// set buffer
	///
	void SetResource(unsigned char* buffer, int length) INTERNAL_CALL;

public:
	PRIME_IMPLEMENT_REFCOUNTING(ProxyResponseFilter);
	AQUA_DECL_PUBLIC_ORIGIN;

private:
	void* _rawptr;
};