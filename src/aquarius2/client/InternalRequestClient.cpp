#include "InternalRequestClient.h"

#define DOWNLOAD_BUFFER_SIZE    (0x8000)

InternalRequestClient::InternalRequestClient(CefRefPtr<CefFrame> frame):
    _sendRequest(nullptr),
    _sendRequestContext(nullptr),
    _sendFrame(frame),
    _urlRequest(nullptr),
    _hasAuth(false),
    _authUsername(L""),
    _authPassword(L""){
    _totalBytes = 0;
    _awakingEvent = CefWaitableEvent::CreateWaitableEvent(false, false);
}

InternalRequestClient::~InternalRequestClient() {
    _urlRequest = nullptr;
    _awakingEvent = nullptr;
    _sendRequest = nullptr;
    _sendRequestContext = nullptr;
    _sendFrame = nullptr;
}

void InternalRequestClient::OnRequestComplete(CefRefPtr<CefURLRequest> request){
    if (_awakingEvent) {
        _awakingEvent->Signal();
    }
}

void InternalRequestClient::OnDownloadData(CefRefPtr<CefURLRequest> request,
    const void* data,
    size_t data_length){
    _rdbuf.write((char*)data, data_length);
    _totalBytes += data_length;
}

void InternalRequestClient::OnUploadProgress(CefRefPtr<CefURLRequest> request,
    int64 current,
    int64 total) {

}

void InternalRequestClient::OnDownloadProgress(CefRefPtr<CefURLRequest> request,
    int64 current,
    int64 total) {
}

bool InternalRequestClient::GetAuthCredentials(bool isProxy,
    const CefString& host,
    int port,
    const CefString& realm,
    const CefString& scheme,
    CefRefPtr<CefAuthCallback> callback){
    bool result = false;
    if (_hasAuth) {
        callback->Continue(_authUsername, _authPassword);
        return true;
    }
    return result;
}

CefRefPtr<CefWaitableEvent> InternalRequestClient::SendRequest(
    CefRefPtr<CefRequest> request,
    CefRefPtr<CefRequestContext> request_context) {
    this->Reset();

    this->_sendRequest = request;
    this->_sendRequestContext = request_context;

    CefPostTask(TID_IO, this);

    return _awakingEvent;
}

void InternalRequestClient::Execute() {
    if (_sendFrame) {
        _sendFrame->CreateURLRequest(_sendRequest, this);
    }
    else {
        _urlRequest = CefURLRequest::Create(_sendRequest, this, _sendRequestContext);
    }
}

CefRefPtr<CefURLRequest> InternalRequestClient::GetURLRequest() {
    return _urlRequest;
}

CefRefPtr<CefRequestContext> InternalRequestClient::GetRequestContext() {
    return _sendRequestContext;
}

void InternalRequestClient::SetAuthInfo(const CefString& username, const CefString& password) {
    _hasAuth = true;
    _authUsername = username;
    _authPassword = password;
}

void InternalRequestClient::Reset() {
    _urlRequest = nullptr;
    _awakingEvent->Reset();
    _rdbuf.clear();
    _totalBytes = 0;
}

size_t InternalRequestClient::GetTotalBytes() {
    return _totalBytes;
}

void InternalRequestClient::GetBuffer(unsigned char* out, size_t length) {
    if (length > _totalBytes) {
        return;
    }
  
    _rdbuf.seekg(0, std::ios_base::beg);
    _rdbuf.read((char*)out, length);
    _rdbuf.seekg(0, std::ios_base::beg);
}