#include "ProxyDownloadItem.h"
#include "include/cef_download_item.h"
#include <atlconv.h>
#include "include/cef_download_handler.h"


ProxyDownloadItem::ProxyDownloadItem(void* ptr):
	_rawptr(ptr),
	_beforeDownloadCallback(nullptr),
	_downloadCallback(nullptr)
{
	if (_rawptr) {
		((CefDownloadItem*)_rawptr)->AddRef();
	}
}

ProxyDownloadItem::~ProxyDownloadItem() {
	if (_rawptr) {
		((CefDownloadItem*)_rawptr)->Release();
	}
	if (_beforeDownloadCallback) {
		((CefBeforeDownloadCallback*)_beforeDownloadCallback)->Release();
	}
	if (_downloadCallback) {
		((CefDownloadItemCallback*)_downloadCallback)->Release();
	}
}

///
// Returns true if this object is valid. Do not call any other methods if this
// function returns false.
///
/*--cef()--*/
bool ProxyDownloadItem::IsValid(){
	ASSERTQ(false);
	return FORWARD(CefDownloadItem)->IsValid();
}

///
// Returns true if the download is in progress.
///
/*--cef()--*/
bool ProxyDownloadItem::IsInProgress(){
	ASSERTQ(false);
	return FORWARD(CefDownloadItem)->IsInProgress();
}

///
// Returns true if the download is complete.
///
/*--cef()--*/
bool ProxyDownloadItem::IsComplete(){
	ASSERTQ(false);
	return FORWARD(CefDownloadItem)->IsCanceled();
}

///
// Returns true if the download has been canceled or interrupted.
///
/*--cef()--*/
bool ProxyDownloadItem::IsCanceled(){
	ASSERTQ(false);
	return FORWARD(CefDownloadItem)->IsCanceled();
}

///
// Returns a simple speed estimate in bytes/s.
///
/*--cef()--*/
__int64 ProxyDownloadItem::GetCurrentSpeed(){
	ASSERTQ(0);
	return FORWARD(CefDownloadItem)->GetCurrentSpeed();
}

///
// Returns the rough percent complete or -1 if the receive total size is
// unknown.
///
/*--cef()--*/
int ProxyDownloadItem::GetPercentComplete(){
	ASSERTQ(0);
	return FORWARD(CefDownloadItem)->GetPercentComplete();
}

///
// Returns the total number of bytes.
///
/*--cef()--*/
__int64 ProxyDownloadItem::GetTotalBytes(){
	ASSERTQ(0);
	return FORWARD(CefDownloadItem)->GetTotalBytes();
}

///
// Returns the number of received bytes.
///
/*--cef()--*/
__int64 ProxyDownloadItem::GetReceivedBytes(){
	ASSERTQ(0);
	return FORWARD(CefDownloadItem)->GetReceivedBytes();
}

///
// Returns the time that the download started.
///
/*--cef()--*/
double ProxyDownloadItem::GetStartTime(){
	ASSERTQ(NULL);
	return FORWARD(CefDownloadItem)->GetStartTime().GetDoubleT();
}

///
// Returns the time that the download ended.
///
/*--cef()--*/
double ProxyDownloadItem::GetEndTime(){
	ASSERTQ(NULL);
	return FORWARD(CefDownloadItem)->GetEndTime().GetDoubleT();
}

///
// Returns the full path to the downloaded or downloading file.
///
/*--cef()--*/
char* ProxyDownloadItem::GetFullPath(){
	ASSERTQ(NULL);
	CefString string = FORWARD(CefDownloadItem)->GetFullPath();
	if (string.empty()) {
		return NULL;
	}
	return ToAnsi(string.c_str(),string.length());
}

///
// Returns the unique identifier for this download.
///
/*--cef()--*/
int ProxyDownloadItem::GetId(){
	ASSERTQ(0);
	return FORWARD(CefDownloadItem)->GetId();
}

///
// Returns the URL.
///
/*--cef()--*/
char* ProxyDownloadItem::GetURL(){
	ASSERTQ(NULL);
	CefString string = FORWARD(CefDownloadItem)->GetURL();
	if (string.empty()) {
		return NULL;
	}
	return ToAnsi(string.c_str(), string.length());
}

///
// Returns the original URL before any redirections.
///
/*--cef()--*/
char* ProxyDownloadItem::GetOriginalUrl(){
	ASSERTQ(NULL);
	CefString string = FORWARD(CefDownloadItem)->GetOriginalUrl();
	if (string.empty()) {
		return NULL;
	}
	return ToAnsi(string.c_str(), string.length());
}

///
// Returns the suggested file name.
///
/*--cef()--*/
char* ProxyDownloadItem::GetSuggestedFileName(){
	ASSERTQ(NULL);
	CefString string = FORWARD(CefDownloadItem)->GetSuggestedFileName();
	if (string.empty()) {
		return NULL;
	}
	return ToAnsi(string.c_str(), string.length());
}


///
// Returns the content disposition.
///
/*--cef()--*/
char* ProxyDownloadItem::GetContentDisposition(){
	ASSERTQ(NULL);
	CefString string = FORWARD(CefDownloadItem)->GetContentDisposition();
	if (string.empty()) {
		return NULL;
	}
	return ToAnsi(string.c_str(), string.length());
}

///
// Returns the mime type.
///
/*--cef()--*/
char* ProxyDownloadItem::GetMimeType(){
	ASSERTQ(NULL);
	CefString string = FORWARD(CefDownloadItem)->GetMimeType();
	if (string.empty()) {
		return NULL;
	}
	return ToAnsi(string.c_str(), string.length());
}

///
// Call to continue the download. Set |download_path| to the full file path
// for the download including the file name or leave blank to use the
// suggested name and the default temp directory. Set |show_dialog| to true
// if you do wish to show the default "Save As" dialog.
///
/*--cef(capi_name=cont,optional_param=download_path)--*/
void ProxyDownloadItem::SaveTo(const char* download_path, bool show_dialog) {
	if(_beforeDownloadCallback) {
		USES_CONVERSION;
		((CefBeforeDownloadCallback*)_beforeDownloadCallback)->Continue(download_path ? A2W(download_path) : L"", show_dialog);
	}
}

///
// Call to cancel the download.
///
/*--cef()--*/
void ProxyDownloadItem::CancelDownload() {
	if (_downloadCallback) {
		((CefDownloadItemCallback*)_downloadCallback)->Cancel();
	}
}

///
// Call to pause the download.
///
/*--cef()--*/
void ProxyDownloadItem::PauseDownload() {
	if (_downloadCallback) {
		((CefDownloadItemCallback*)_downloadCallback)->Pause();
	}
}

///
// Call to resume the download.
///
/*--cef()--*/
void ProxyDownloadItem::ResumeDownload() {
	if (_downloadCallback) {
		((CefDownloadItemCallback*)_downloadCallback)->Resume();
	}
}

///
// 保存下载回调
///
/*--cef()--*/
void ProxyDownloadItem::SetBeforeDownloadCallback(void* ptr) INTERNAL_METHOD {
	ASSERTN();
	if (ptr) ((CefBeforeDownloadCallback*)ptr)->AddRef();
	_beforeDownloadCallback = ptr;
}

///
// 保存下载回调
///
/*--cef()--*/
void ProxyDownloadItem::SetDownloadCallback(void* ptr) INTERNAL_METHOD {
	ASSERTN();
	if (ptr) ((CefDownloadItemCallback*)ptr)->AddRef();
	_downloadCallback = ptr;
}
