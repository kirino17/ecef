#pragma once
#include "../def/def.h"

class AQUADLL ProxyFileDialogCallback : public refcounted {
public:
	ProxyFileDialogCallback(void* ptr);
	~ProxyFileDialogCallback();

public:
    ///
    // Continue the file selection. |selected_accept_filter| should be the 0-based
    // index of the value selected from the accept filters array passed to
    // CefDialogHandler::OnFileDialog. |file_paths| should be a single value or a
    // list of values depending on the dialog mode. An empty |file_paths| value is
    // treated the same as calling Cancel.
    ///
    /*--cef(capi_name=cont,index_param=selected_accept_filter,
        optional_param=file_paths)--*/
    void Continue(int selected_accept_filter, const char* file_paths);

    ///
    // Cancel the file selection.
    ///
    /*--cef()--*/
    void Cancel();

public:
    PRIME_IMPLEMENT_REFCOUNTING(ProxyFileDialogCallback);
    AQUA_DECL_PUBLIC_ORIGIN;

private:
    void* _rawptr;
};