#include "ProxyDownloadItemCallback.h"
#include "include/cef_download_handler.h"

AQUA_PROXY_AUTO_CONSTRUCTOR(ProxyDownloadItemCallback,CefDownloadItem);

///
// Call to cancel the download.
///
/*--cef()--*/
void ProxyDownloadItemCallback::Cancel() {
	ASSERTN();
	FORWARD(CefDownloadItemCallback)->Cancel();
}

///
// Call to pause the download.
///
/*--cef()--*/
void ProxyDownloadItemCallback::Pause() {
	ASSERTN();
	FORWARD(CefDownloadItemCallback)->Pause();
}

///
// Call to resume the download.
///
/*--cef()--*/
void ProxyDownloadItemCallback::Resume() {
	ASSERTN();
	FORWARD(CefDownloadItemCallback)->Resume();
}
