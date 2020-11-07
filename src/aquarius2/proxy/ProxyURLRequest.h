#pragma once
#include "../def/def.h"
#include "ProxyRequest.h"
#include "ProxyResponse.h"
#include "ProxyCookieManager.h"

class AQUADLL ProxyURLRequest : public refcounted {
public:
	ProxyURLRequest(void* ptr);
	~ProxyURLRequest();

public:
	bool IsValid();

	shrewd_ptr<ProxyRequest> GetRequest();

	shrewd_ptr<ProxyResponse> GetResponse();

	int GetRequestStatus();

	int GetRequestError();

	bool ResponseWasCached();

	size_t GetResponseDataBytes();

	unsigned char* GetResponseData();

	shrewd_ptr<ProxyCookieManager> GetCookieManager();

public:
	AQUA_DECL_PUBLIC_ORIGIN;
	PRIME_IMPLEMENT_REFCOUNTING(ProxyURLRequest);


private:
	void* _rawptr;
};
