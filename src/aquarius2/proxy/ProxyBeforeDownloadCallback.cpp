#include "ProxyBeforeDownloadCallback.h"
#include "include/cef_download_handler.h"
#include <atlconv.h>

AQUA_PROXY_AUTO_CONSTRUCTOR(ProxyBeforeDownloadCallback,CefBeforeDownloadCallback);

///
// Call to continue the download. Set |download_path| to the full file path
// for the download including the file name or leave blank to use the
// suggested name and the default temp directory. Set |show_dialog| to true
// if you do wish to show the default "Save As" dialog.
///
/*--cef(capi_name=cont,optional_param=download_path)--*/
void ProxyBeforeDownloadCallback::Continue(const char* download_path, bool show_dialog) {
	ASSERTN();
	CefString string;
	USES_CONVERSION;
	if (download_path) {
		string = A2W(download_path);
	}
	FORWARD(CefBeforeDownloadCallback)->Continue(string,show_dialog);
}