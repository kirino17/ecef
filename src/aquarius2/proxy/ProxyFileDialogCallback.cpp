#include "ProxyFileDialogCallback.h"
#include "include/cef_dialog_handler.h"
#include "../def/internalDef.h"

AQUA_PROXY_AUTO_CONSTRUCTOR(ProxyFileDialogCallback,CefFileDialogCallback);

///
// Continue the file selection. |selected_accept_filter| should be the 0-based
// index of the value selected from the accept filters array passed to
// CefDialogHandler::OnFileDialog. |file_paths| should be a single value or a
// list of values depending on the dialog mode. An empty |file_paths| value is
// treated the same as calling Cancel.
///
/*--cef(capi_name=cont,index_param=selected_accept_filter,
    optional_param=file_paths)--*/
void ProxyFileDialogCallback::Continue(int selected_accept_filter, const char* file_paths) {
    ASSERTN();
    std::vector<CefString> stringArrays;
    if (file_paths) {
        SplitString(file_paths, "\r\n", stringArrays);
    }
    FORWARD(CefFileDialogCallback)->Continue(selected_accept_filter, stringArrays);
}

///
// Cancel the file selection.
///
/*--cef()--*/
void ProxyFileDialogCallback::Cancel() {
    ASSERTN();
    FORWARD(CefFileDialogCallback)->Cancel();
}