#pragma once
#include "include/cef_urlrequest.h"
#include <vector>
#include "../def/internalDef.h"
#include "include/cef_waitable_event.h"
#include "include/cef_task.h"
#include <sstream>

class InternalRequestClient : public CefURLRequestClient,
    public CefTask
{
public:
	InternalRequestClient(CefRefPtr<CefFrame> frame = nullptr);
	virtual ~InternalRequestClient();

protected:
    virtual void OnRequestComplete(CefRefPtr<CefURLRequest> request) override;

    virtual void OnDownloadData(CefRefPtr<CefURLRequest> request,
        const void* data,
        size_t data_length) override;

    virtual bool GetAuthCredentials(bool isProxy,
        const CefString& host,
        int port,
        const CefString& realm,
        const CefString& scheme,
        CefRefPtr<CefAuthCallback> callback) override;


public:
    virtual void OnUploadProgress(CefRefPtr<CefURLRequest> request,
        int64 current,
        int64 total) override;

    virtual void OnDownloadProgress(CefRefPtr<CefURLRequest> request,
        int64 current,
        int64 total) override;

public:
    virtual void Execute() override;

public:
    CefRefPtr<CefWaitableEvent> SendRequest(
            CefRefPtr<CefRequest> request, 
            CefRefPtr<CefRequestContext> request_context);

    CefRefPtr<CefURLRequest> GetURLRequest();

    CefRefPtr<CefRequestContext> GetRequestContext();

    void SetAuthInfo(const CefString& username, const CefString& password);

    void Reset();

    size_t GetTotalBytes();

    void GetBuffer(unsigned char* out, size_t length);

public:
    IMPLEMENT_REFCOUNTING(InternalRequestClient);

private:
    CefRefPtr<CefRequest> _sendRequest;
    CefRefPtr<CefRequestContext> _sendRequestContext;
    CefRefPtr<CefFrame> _sendFrame;
    CefRefPtr<CefURLRequest> _urlRequest;
    CefRefPtr<CefWaitableEvent> _awakingEvent;
    bool _hasAuth;
    CefString _authUsername;
    CefString _authPassword;
    std::stringstream _rdbuf;
    std::size_t _totalBytes;
};