#pragma once
#include "../def/def.h"
#include "ProxyTime.h"

class AQUADLL ProxyDownloadItem : public refcounted {
public:
	ProxyDownloadItem(void* ptr);
	~ProxyDownloadItem();

public:
    ///
    // Returns true if this object is valid. Do not call any other methods if this
    // function returns false.
    ///
    /*--cef()--*/
    bool IsValid();

    ///
    // Returns true if the download is in progress.
    ///
    /*--cef()--*/
    bool IsInProgress();

    ///
    // Returns true if the download is complete.
    ///
    /*--cef()--*/
    bool IsComplete();

    ///
    // Returns true if the download has been canceled or interrupted.
    ///
    /*--cef()--*/
    bool IsCanceled();

    ///
    // Returns a simple speed estimate in bytes/s.
    ///
    /*--cef()--*/
    __int64 GetCurrentSpeed();

    ///
    // Returns the rough percent complete or -1 if the receive total size is
    // unknown.
    ///
    /*--cef()--*/
    int GetPercentComplete();

    ///
    // Returns the total number of bytes.
    ///
    /*--cef()--*/
    __int64 GetTotalBytes();

    ///
    // Returns the number of received bytes.
    ///
    /*--cef()--*/
    __int64 GetReceivedBytes();

    ///
    // Returns the time that the download started.
    ///
    /*--cef()--*/
    shrewd_ptr<ProxyTime> GetStartTime();

    ///
    // Returns the time that the download ended.
    ///
    /*--cef()--*/
    shrewd_ptr<ProxyTime> GetEndTime();

    ///
    // Returns the full path to the downloaded or downloading file.
    ///
    /*--cef()--*/
    char* GetFullPath();

    ///
    // Returns the unique identifier for this download.
    ///
    /*--cef()--*/
    int GetId();

    ///
    // Returns the URL.
    ///
    /*--cef()--*/
    char* GetURL();

    ///
    // Returns the original URL before any redirections.
    ///
    /*--cef()--*/
    char* GetOriginalUrl();

    ///
    // Returns the suggested file name.
    ///
    /*--cef()--*/
    char* GetSuggestedFileName();

    ///
    // Returns the content disposition.
    ///
    /*--cef()--*/
    char* GetContentDisposition();

    ///
    // Returns the mime type.
    ///
    /*--cef()--*/
    char* GetMimeType();

public:
	PRIME_IMPLEMENT_REFCOUNTING(ProxyDownloadItem);
	AQUA_DECL_PUBLIC_ORIGIN;

private:
	void* _rawptr;
};