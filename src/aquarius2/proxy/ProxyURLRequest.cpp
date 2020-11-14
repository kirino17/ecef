#include "ProxyURLRequest.h"
#include "../client/InternalRequestClient.h"
#include "../client/InternalTaskVisitor.h"

AQUA_PROXY_AUTO_CONSTRUCTOR(ProxyURLRequest, InternalRequestClient);

bool ProxyURLRequest::IsValid() {
	return _rawptr != nullptr;
}

shrewd_ptr<ProxyRequest> ProxyURLRequest::GetRequest() {
	ASSERTQ(NULL);
	CefRefPtr<CefURLRequest> url = FORWARD(InternalRequestClient)->GetURLRequest();
	if (!url) {
		return NULL;
	}

	CefRefPtr<CefRequest> request = nullptr;

	CefRefPtr<CefWaitableEvent> waitable = CefWaitableEvent::CreateWaitableEvent(false, false);
	auto f = [](CefRefPtr<CefURLRequest> url, CefRefPtr<CefWaitableEvent> waitable, CefRefPtr<CefRequest>* result) {
		*result = url->GetRequest();
		waitable->Signal();
	};
	CefRefPtr<InternalTaskVisitor> visitor = new InternalTaskVisitor(std::bind(f, url, waitable, &request));
	CefPostTask(TID_IO, visitor);
	WaitAwaking(waitable);
	if(request) {
		return new ProxyRequest(request);
	}
	return nullptr;
}

shrewd_ptr<ProxyResponse> ProxyURLRequest::GetResponse() {
	ASSERTQ(NULL);
	CefRefPtr<CefURLRequest> url = FORWARD(InternalRequestClient)->GetURLRequest();
	CefRefPtr<CefResponse> response = nullptr;
	if (!url) {
		return NULL;
	}

	CefRefPtr<CefWaitableEvent> waitable = CefWaitableEvent::CreateWaitableEvent(false, false);
	auto f = [](CefRefPtr<CefURLRequest> url, CefRefPtr<CefWaitableEvent> waitable, CefRefPtr<CefResponse>* result) {
		*result = url->GetResponse();
		waitable->Signal();
	};
	CefRefPtr<InternalTaskVisitor> visitor = new InternalTaskVisitor(std::bind(f, url, waitable, &response));
	CefPostTask(TID_IO, visitor);
	WaitAwaking(waitable);

	if (!response) {
		return nullptr;
	}
	
	return new ProxyResponse(response);
}

int ProxyURLRequest::GetRequestStatus() {
	ASSERTQ(0);
	CefRefPtr<CefURLRequest> url = FORWARD(InternalRequestClient)->GetURLRequest();
	if (!url) {
		return 0;
	}
	int result = 0;
	CefRefPtr<CefWaitableEvent> waitable = CefWaitableEvent::CreateWaitableEvent(false, false);
	auto f = [](CefRefPtr<CefURLRequest> url, CefRefPtr<CefWaitableEvent> waitable, int* result) {
		*result = url->GetRequestStatus();
		waitable->Signal();
	};
	CefRefPtr<InternalTaskVisitor> visitor = new InternalTaskVisitor(std::bind(f, url, waitable, &result));
	CefPostTask(TID_IO, visitor);
	WaitAwaking(waitable);
	return result;
}

int ProxyURLRequest::GetRequestError() {
	ASSERTQ(0);
	CefRefPtr<CefURLRequest> url = FORWARD(InternalRequestClient)->GetURLRequest();
	if (!url) {
		return 0;
	}
	
	int result = 0;
	CefRefPtr<CefWaitableEvent> waitable = CefWaitableEvent::CreateWaitableEvent(false, false);
	auto f = [](CefRefPtr<CefURLRequest> url, CefRefPtr<CefWaitableEvent> waitable, int* result) {
		*result = url->GetRequestError();
		waitable->Signal();
	};
	CefRefPtr<InternalTaskVisitor> visitor = new InternalTaskVisitor(std::bind(f, url, waitable, &result));
	CefPostTask(TID_IO, visitor);
	WaitAwaking(waitable);
	return result;
}

bool ProxyURLRequest::ResponseWasCached() {
	ASSERTQ(false);
	CefRefPtr<CefURLRequest> url = FORWARD(InternalRequestClient)->GetURLRequest();
	if (!url) {
		return false;
	}
	bool result = false;
	CefRefPtr<CefWaitableEvent> waitable = CefWaitableEvent::CreateWaitableEvent(false, false);
	auto f = [](CefRefPtr<CefURLRequest> url, CefRefPtr<CefWaitableEvent> waitable, bool* result) {
		*result = url->ResponseWasCached();
		waitable->Signal();
	};
	CefRefPtr<InternalTaskVisitor> visitor = new InternalTaskVisitor(std::bind(f, url, waitable, &result));
	CefPostTask(TID_IO, visitor);
	WaitAwaking(waitable);
	return result;
}

size_t ProxyURLRequest::GetResponseDataBytes() {
	ASSERTQ(0);
	return FORWARD(InternalRequestClient)->GetTotalBytes();
}

unsigned char* ProxyURLRequest::GetResponseData() {
	ASSERTQ(0);
	assert(NewBuffer);
	size_t length = FORWARD(InternalRequestClient)->GetTotalBytes();
	if (length <=0) {
		return NULL;
	}
	unsigned char* buffer = (unsigned char*)NewBuffer(8 + length);
	*(int*)&buffer[0] = 1;
	*(int*)&buffer[4] = length;
	FORWARD(InternalRequestClient)->GetBuffer(&buffer[8], length);
	return buffer;
}

shrewd_ptr<ProxyCookieManager> ProxyURLRequest::GetCookieManager() {
	ASSERTQ(NULL);
	CefRefPtr<CefRequestContext> context = FORWARD(InternalRequestClient)->GetRequestContext();
	if (!context) {
		return new ProxyCookieManager(CefCookieManager::GetGlobalManager(nullptr));
	}
	return new ProxyCookieManager(context->GetCookieManager(nullptr));
}
