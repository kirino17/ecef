#pragma once
#include "../def/def.h"

class AQUADLL ProxyBeforeDownloadCallback : public refcounted {
public:
	ProxyBeforeDownloadCallback(void* ptr);
	~ProxyBeforeDownloadCallback();


public:
    ///
    // Call to continue the download. Set |download_path| to the full file path
    // for the download including the file name or leave blank to use the
    // suggested name and the default temp directory. Set |show_dialog| to true
    // if you do wish to show the default "Save As" dialog.
    ///
    /*--cef(capi_name=cont,optional_param=download_path)--*/
    void Continue(const char* download_path, bool show_dialog);

public:
	PRIME_IMPLEMENT_REFCOUNTING(ProxyBeforeDownloadCallback);
	AQUA_DECL_PUBLIC_ORIGIN;

private:
	void* _rawptr;
};