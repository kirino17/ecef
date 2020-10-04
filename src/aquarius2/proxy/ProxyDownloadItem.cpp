#include "ProxyDownloadItem.h"
#include "include/cef_download_item.h"
#include <atlconv.h>

AQUA_PROXY_AUTO_CONSTRUCTOR(ProxyDownloadItem,CefDownloadItem);

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
shrewd_ptr<ProxyTime> ProxyDownloadItem::GetStartTime(){
	ASSERTQ(NULL);
	return new ProxyTime(new CefTime(FORWARD(CefDownloadItem)->GetStartTime()));
}

///
// Returns the time that the download ended.
///
/*--cef()--*/
shrewd_ptr<ProxyTime> ProxyDownloadItem::GetEndTime(){
	ASSERTQ(NULL);
	return new ProxyTime(new CefTime(FORWARD(CefDownloadItem)->GetEndTime()));
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
