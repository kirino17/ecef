#pragma once
#include "../def/def.h"

class AQUADLL ProxyDownloadItemCallback : public refcounted {
public:
	ProxyDownloadItemCallback(void* ptr);
	~ProxyDownloadItemCallback(void);

public:
    ///
    // Call to cancel the download.
    ///
    /*--cef()--*/
    void Cancel();

    ///
    // Call to pause the download.
    ///
    /*--cef()--*/
    void Pause();

    ///
    // Call to resume the download.
    ///
    /*--cef()--*/
    void Resume();

public:
	PRIME_IMPLEMENT_REFCOUNTING(ProxyDownloadItemCallback);
	AQUA_DECL_PUBLIC_ORIGIN;

private:
	void* _rawptr;
};