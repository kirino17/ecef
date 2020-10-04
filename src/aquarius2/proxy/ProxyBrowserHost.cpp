#include "ProxyBrowserHost.h"
#include "include/cef_browser.h"
#include "ProxyBrowser.h"
#include "ProxyRequestContext.h"
#include "ProxyKeyEvent.h"
#include "ProxyMouseEvent.h"
#include "ProxyTouchEvent.h"
#include <atlconv.h>
#include "../client/InternalDevToolsClient.h"
#include "../client/InternalClient.h"

AQUA_PROXY_AUTO_CONSTRUCTOR(ProxyBrowserHost,CefBrowserHost);

///
// Returns the hosted browser object.
///
/*--cef()--*/
shrewd_ptr<ProxyBrowser> ProxyBrowserHost::GetBrowser() {
    ASSERTQ(NULL);
    return new ProxyBrowser(FORWARD(CefBrowserHost)->GetBrowser());
}


bool ProxyBrowserHost::IsValid() {
    return _rawptr != nullptr;
}

///
// Request that the browser close. The JavaScript 'onbeforeunload' event will
// be fired. If |force_close| is false the event handler, if any, will be
// allowed to prompt the user and the user can optionally cancel the close.
// If |force_close| is true the prompt will not be displayed and the close
// will proceed. Results in a call to CefLifeSpanHandler::DoClose() if the
// event handler allows the close or if |force_close| is true. See
// CefLifeSpanHandler::DoClose() documentation for additional usage
// information.
///
/*--cef()--*/
void ProxyBrowserHost::CloseBrowser(bool force_close) {
    ASSERTN();
    FORWARD(CefBrowserHost)->CloseBrowser(force_close);
}

///
// Helper for closing a browser. Call this method from the top-level window
// close handler. Internally this calls CloseBrowser(false) if the close has
// not yet been initiated. This method returns false while the close is
// pending and true after the close has completed. See CloseBrowser() and
// CefLifeSpanHandler::DoClose() documentation for additional usage
// information. This method must be called on the browser process UI thread.
///
/*--cef()--*/
bool ProxyBrowserHost::TryCloseBrowser() {
    ASSERTQ(false);
    return FORWARD(CefBrowserHost)->TryCloseBrowser();
}

///
// Set whether the browser is focused.
///
/*--cef()--*/
void ProxyBrowserHost::SetFocus(bool focus) {
    ASSERTN();
    FORWARD(CefBrowserHost)->SetFocus(focus);
}

///
// Retrieve the window handle for this browser. If this browser is Proxyped in
// a CefBrowserView this method should be called on the browser process UI
// thread and it will return the handle for the top-level native window.
///
/*--cef()--*/
void* ProxyBrowserHost::GetWindowHandle() {
    ASSERTQ(NULL);
    return FORWARD(CefBrowserHost)->GetWindowHandle();
}

///
// Retrieve the window handle of the browser that opened this browser. Will
// return NULL for non-popup windows or if this browser is Proxyped in a
// CefBrowserView. This method can be used in combination with custom handling
// of modal windows.
///
/*--cef()--*/
void* ProxyBrowserHost::GetOpenerWindowHandle() {
    ASSERTQ(NULL);
    return FORWARD(CefBrowserHost)->GetWindowHandle();
}

///
// Returns the request context for this browser.
///
/*--cef()--*/
shrewd_ptr<ProxyRequestContext> ProxyBrowserHost::GetRequestContext() {
    ASSERTQ(NULL);
    CefRefPtr<CefRequestContext> context = FORWARD(CefBrowserHost)->GetRequestContext();
    if (!context) {
        return NULL;
    }
    return new ProxyRequestContext(context);
}

/////
//// Returns true if this browser is Proxyped in a CefBrowserView.
/////
///*--cef()--*/
//bool ProxyBrowserHost::HasView() {
//    ASSERTQ(false);
//    return FORWARD(CefBrowserHost)->HasView();
//}

/////
//// Returns the client for this browser.
/////
///*--cef()--*/
//shrewd_ptr<ProxyClient> ProxyBrowserHost::GetClient() {
//
//}

/////
//// Returns the request context for this browser.
/////
///*--cef()--*/
//shrewd_ptr<ProxyRequestContext> ProxyBrowserHost::GetRequestContext() {
//    ASSERTQ(NULL);
//    return new ProxyRequestContext(FORWARD(CefBrowserHost)->GetRequestContext());
//}

///
// Get the current zoom level. The default zoom level is 0.0. This method can
// only be called on the UI thread.
///
/*--cef()--*/
double ProxyBrowserHost::GetZoomLevel() {
    ASSERTQ(0.0f);
    return FORWARD(CefBrowserHost)->GetZoomLevel();
}

///
// Change the zoom level to the specified value. Specify 0.0 to reset the
// zoom level. If called on the UI thread the change will be applied
// immediately. Otherwise, the change will be applied asynchronously on the
// UI thread.
///
/*--cef()--*/
void ProxyBrowserHost::SetZoomLevel(double zoomLevel) {
    ASSERTN();
    FORWARD(CefBrowserHost)->SetZoomLevel(zoomLevel);
}

/////
//// Call to run a file chooser dialog. Only a single file chooser dialog may be
//// pending at any given time. |mode| represents the type of dialog to display.
//// |title| to the title to be used for the dialog and may be empty to show the
//// default title ("Open" or "Save" depending on the mode). |default_file_path|
//// is the path with optional directory and/or file name component that will be
//// initially selected in the dialog. |accept_filters| are used to restrict the
//// selectable file types and may any combination of (a) valid lower-cased MIME
//// types (e.g. "text/*" or "image/*"), (b) individual file extensions (e.g.
//// ".txt" or ".png"), or (c) combined description and file extension delimited
//// using "|" and ";" (e.g. "Image Types|.png;.gif;.jpg").
//// |selected_accept_filter| is the 0-based index of the filter that will be
//// selected by default. |callback| will be executed after the dialog is
//// dismissed or immediately if another dialog is already pending. The dialog
//// will be initiated asynchronously on the UI thread.
/////
///*--cef(optional_param=title,optional_param=default_file_path,
//        optional_param=accept_filters,index_param=selected_accept_filter)--*/
//void RunFileDialog(int mode,
//    const char* title,
//    const char* default_file_path,
//    const char* accept_filters,
//    int selected_accept_filter,
//    shrewd_ptr<ProxyRunFileDialogCallback> callback) {
//
//}

///
// Download the file at |url| using CefDownloadHandler.
///
/*--cef()--*/
void ProxyBrowserHost::StartDownload(const char* url) {
    ASSERTN();
    FORWARD(CefBrowserHost)->StartDownload(url);
}

/////
//// Download |image_url| and execute |callback| on completion with the images
//// received from the renderer. If |is_favicon| is true then cookies are not
//// sent and not accepted during download. Images with density independent
//// pixel (DIP) sizes larger than |max_image_size| are filtered out from the
//// image results. Versions of the image at different scale factors may be
//// downloaded up to the maximum scale factor supported by the system. If there
//// are no image results <= |max_image_size| then the smallest image is resized
//// to |max_image_size| and is the only result. A |max_image_size| of 0 means
//// unlimited. If |bypass_cache| is true then |image_url| is requested from the
//// server even if it is present in the browser cache.
/////
///*--cef()--*/
//void DownloadImage(const CefString& image_url,
//    bool is_favicon,
//    uint32 max_image_size,
//    bool bypass_cache,
//    shrewd_ptr<CefDownloadImageCallback> callback);

///
// Print the current browser contents.
///
/*--cef()--*/
void ProxyBrowserHost::Print() {
    ASSERTN();
    FORWARD(CefBrowserHost)->Print();
}

/////
//// Print the current browser contents to the PDF file specified by |path| and
//// execute |callback| on completion. The caller is responsible for deleting
//// |path| when done. For PDF printing to work on Linux you must implement the
//// CefPrintHandler::GetPdfPaperSize method.
/////
///*--cef(optional_param=callback)--*/
//void PrintToPDF(const CefString& path,
//    const CefPdfPrintSettings& settings,
//    shrewd_ptr<CefPdfPrintCallback> callback);

/////
//// Search for |searchText|. |identifier| must be a unique ID and these IDs
//// must strictly increase so that newer requests always have greater IDs than
//// older requests. If |identifier| is zero or less than the previous ID value
//// then it will be automatically assigned a new valid ID. |forward| indicates
//// whether to search forward or backward within the page. |matchCase|
//// indicates whether the search should be case-sensitive. |findNext| indicates
//// whether this is the first request or a follow-up. The CefFindHandler
//// instance, if any, returned via CefClient::GetFindHandler will be called to
//// report find results.
/////
///*--cef()--*/
//void Find(int identifier,
//    const CefString& searchText,
//    bool forward,
//    bool matchCase,
//    bool findNext);

/////
//// Cancel all searches that are currently going on.
/////
///*--cef()--*/
//void StopFinding(bool clearSelection);

/////
//// Open developer tools (DevTools) in its own browser. The DevTools browser
//// will remain associated with this browser. If the DevTools browser is
//// already open then it will be focused, in which case the |windowInfo|,
//// |client| and |settings| parameters will be ignored. If |inspect_element_at|
//// is non-empty then the element at the specified (x,y) location will be
//// inspected. The |windowInfo| parameter will be ignored if this browser is
//// Proxyped in a CefBrowserView.
/////
///*--cef(optional_param=windowInfo,optional_param=client,
//        optional_param=settings,optional_param=inspect_element_at)--*/
//void ShowDevTools(const CefWindowInfo& windowInfo,
//    shrewd_ptr<CefClient> client,
//    const CefBrowserSettings& settings,
//    const CefPoint& inspect_element_at);

/////
//// Explicitly close the associated DevTools browser, if any.
/////
///*--cef()--*/
//void CloseDevTools();

/////
//// Returns true if this browser currently has an associated DevTools browser.
//// Must be called on the browser process UI thread.
/////
///*--cef()--*/
//bool HasDevTools();

/////
//// Retrieve a snapshot of current navigation entries as values sent to the
//// specified visitor. If |current_only| is true only the current navigation
//// entry will be sent, otherwise all navigation entries will be sent.
/////
///*--cef()--*/
//void GetNavigationEntries(
//    shrewd_ptr<CefNavigationEntryVisitor> visitor,
//    bool current_only);

///
// Set whether mouse cursor change is disabled.
///
/*--cef()--*/
void ProxyBrowserHost::SetMouseCursorChangeDisabled(bool disabled) {
    ASSERTN();
    FORWARD(CefBrowserHost)->SetMouseCursorChangeDisabled(disabled);
}

///
// Returns true if mouse cursor change is disabled.
///
/*--cef()--*/
bool ProxyBrowserHost::IsMouseCursorChangeDisabled() {
    ASSERTQ(false);
    return FORWARD(CefBrowserHost)->IsMouseCursorChangeDisabled();
}

///
// If a misspelled word is currently selected in an editable node calling
// this method will replace it with the specified |word|.
///
/*--cef()--*/
void ProxyBrowserHost::ReplaceMisspelling(const char* word) {
    ASSERTN();
    if (!word) {
        return;
    }
    USES_CONVERSION;
    FORWARD(CefBrowserHost)->ReplaceMisspelling(A2W(word));
}

///
// Add the specified |word| to the spelling dictionary.
///
/*--cef()--*/
void ProxyBrowserHost::AddWordToDictionary(const char* word) {
    ASSERTN();
    if (!word) {
        return;
    }
    USES_CONVERSION;
    FORWARD(CefBrowserHost)->AddWordToDictionary(A2W(word));
}

///
// Returns true if window rendering is disabled.
///
/*--cef()--*/
bool ProxyBrowserHost::IsWindowRenderingDisabled() {
    ASSERTQ(false);
    return FORWARD(CefBrowserHost)->IsWindowRenderingDisabled();
}

///
// Notify the browser that the widget has been resized. The browser will first
// call CefRenderHandler::GetViewRect to get the new size and then call
// CefRenderHandler::OnPaint asynchronously with the updated regions. This
// method is only used when window rendering is disabled.
///
/*--cef()--*/
void ProxyBrowserHost::WasResized() {
    ASSERTN();
    FORWARD(CefBrowserHost)->WasResized();
}

///
// Notify the browser that it has been hidden or shown. Layouting and
// CefRenderHandler::OnPaint notification will stop when the browser is
// hidden. This method is only used when window rendering is disabled.
///
/*--cef()--*/
void ProxyBrowserHost::WasHidden(bool hidden) {
    ASSERTN();
    FORWARD(CefBrowserHost)->WasHidden(hidden);
}

///
// Send a notification to the browser that the screen info has changed. The
// browser will then call CefRenderHandler::GetScreenInfo to update the
// screen information with the new values. This simulates moving the webview
// window from one display to another, or changing the properties of the
// current display. This method is only used when window rendering is
// disabled.
///
/*--cef()--*/
void ProxyBrowserHost::NotifyScreenInfoChanged() {
    ASSERTN();
    FORWARD(CefBrowserHost)->NotifyScreenInfoChanged();
}

/////
//// Invalidate the view. The browser will call CefRenderHandler::OnPaint
//// asynchronously. This method is only used when window rendering is
//// disabled.
/////
///*--cef()--*/
// void Invalidate(PaintElementType type);

/////
//// Issue a BeginFrame request to Chromium.  Only valid when
//// CefWindowInfo::external_begin_frame_enabled is set to true.
/////
///*--cef()--*/
// void SendExternalBeginFrame();

///
// Send a key event to the browser.
///
/*--cef()--*/
void ProxyBrowserHost::SendKeyEvent(shrewd_ptr<ProxyKeyEvent> event) {
    ASSERTN();
    if (!event) {
        return;
    }
    CefKeyEvent* pEvent = (CefKeyEvent*)event->OriginPointer();

    FORWARD(CefBrowserHost)->SendKeyEvent((*pEvent));
 }

///
// Send a mouse click event to the browser. The |x| and |y| coordinates are
// relative to the upper-left corner of the view.
///
/*--cef()--*/
void ProxyBrowserHost::SendMouseClickEvent(shrewd_ptr<ProxyMouseEvent> event,
    int type,
    bool mouseUp,
    int clickCount) {
    ASSERTN();
    if (!event) {
        return;
    }
    CefMouseEvent* pEvent = (CefMouseEvent*)event->OriginPointer();

    FORWARD(CefBrowserHost)->SendMouseClickEvent((*pEvent),
        (cef_mouse_button_type_t)type, mouseUp, clickCount);
 }

///
// Send a mouse move event to the browser. The |x| and |y| coordinates are
// relative to the upper-left corner of the view.
///
/*--cef()--*/
void ProxyBrowserHost::SendMouseMoveEvent(shrewd_ptr<ProxyMouseEvent> event,
    bool mouseLeave) {
    ASSERTN();
    if (!event) {
        return;
    }
    CefMouseEvent* pEvent = (CefMouseEvent*)event->OriginPointer();
    FORWARD(CefBrowserHost)->SendMouseMoveEvent((*pEvent), mouseLeave);
 }

///
// Send a mouse wheel event to the browser. The |x| and |y| coordinates are
// relative to the upper-left corner of the view. The |deltaX| and |deltaY|
// values represent the movement delta in the X and Y directions respectively.
// In order to scroll inside select popups with window rendering disabled
// CefRenderHandler::GetScreenPoint should be implemented properly.
///
/*--cef()--*/
void ProxyBrowserHost::SendMouseWheelEvent(shrewd_ptr<ProxyMouseEvent> event,
    int deltaX,
    int deltaY) {
    ASSERTN();
    if (!event) {
        return;
    }
    CefMouseEvent* pEvent = (CefMouseEvent*)event->OriginPointer();
    FORWARD(CefBrowserHost)->SendMouseWheelEvent((*pEvent),
        deltaX,deltaY);
 }

///
// Send a touch event to the browser for a windowless browser.
///
/*--cef()--*/
void ProxyBrowserHost::SendTouchEvent(shrewd_ptr<ProxyTouchEvent> event) {
    ASSERTN();
    if (!event) {
        return;
    }
    CefTouchEvent* pEvent = (CefTouchEvent*)event->OriginPointer();
    FORWARD(CefBrowserHost)->SendTouchEvent((*pEvent));
 }

///
// Send a focus event to the browser.
///
/*--cef()--*/
void ProxyBrowserHost::SendFocusEvent(bool setFocus) {
    ASSERTN();
    FORWARD(CefBrowserHost)->SendFocusEvent(setFocus);
}

///
// Send a capture lost event to the browser.
///
/*--cef()--*/
void ProxyBrowserHost::SendCaptureLostEvent() {
    ASSERTN();
    FORWARD(CefBrowserHost)->SendCaptureLostEvent();
}

///
// Notify the browser that the window hosting it is about to be moved or
// resized. This method is only used on Windows and Linux.
///
/*--cef()--*/
void ProxyBrowserHost::NotifyMoveOrResizeStarted() {
    ASSERTN();
    FORWARD(CefBrowserHost)->NotifyMoveOrResizeStarted();
}

///
// Returns the maximum rate in frames per second (fps) that CefRenderHandler::
// OnPaint will be called for a windowless browser. The actual fps may be
// lower if the browser cannot generate frames at the requested rate. The
// minimum value is 1 and the maximum value is 60 (default 30). This method
// can only be called on the UI thread.
///
/*--cef()--*/
int ProxyBrowserHost::GetWindowlessFrameRate() {
    ASSERTQ(0);
    return FORWARD(CefBrowserHost)->GetWindowlessFrameRate();
 }

///
// Set the maximum rate in frames per second (fps) that CefRenderHandler::
// OnPaint will be called for a windowless browser. The actual fps may be
// lower if the browser cannot generate frames at the requested rate. The
// minimum value is 1 and the maximum value is 60 (default 30). Can also be
// set at browser creation via CefBrowserSettings.windowless_frame_rate.
///
/*--cef()--*/
void ProxyBrowserHost::SetWindowlessFrameRate(int frame_rate) {
    ASSERTN();
    FORWARD(CefBrowserHost)->SetWindowlessFrameRate(frame_rate);
 }

/////
//// Begins a new composition or updates the existing composition. Blink has a
//// special node (a composition node) that allows the input method to change
//// text without affecting other DOM nodes. |text| is the optional text that
//// will be inserted into the composition node. |underlines| is an optional set
//// of ranges that will be underlined in the resulting text.
//// |replacement_range| is an optional range of the existing text that will be
//// replaced. |selection_range| is an optional range of the resulting text that
//// will be selected after insertion or replacement. The |replacement_range|
//// value is only used on OS X.
////
//// This method may be called multiple times as the composition changes. When
//// the client is done making changes the composition should either be canceled
//// or completed. To cancel the composition call ImeCancelComposition. To
//// complete the composition call either ImeCommitText or
//// ImeFinishComposingText. Completion is usually signaled when:
////   A. The client receives a WM_IME_COMPOSITION message with a GCS_RESULTSTR
////      flag (on Windows), or;
////   B. The client receives a "commit" signal of GtkIMContext (on Linux), or;
////   C. insertText of NSTextInput is called (on Mac).
////
//// This method is only used when window rendering is disabled.
/////
///*--cef(optional_param=text, optional_param=underlines)--*/
// void ImeSetComposition(
//    const CefString& text,
//    const std::vector<CefCompositionUnderline>& underlines,
//    const CefRange& replacement_range,
//    const CefRange& selection_range);

/////
//// Completes the existing composition by optionally inserting the specified
//// |text| into the composition node. |replacement_range| is an optional range
//// of the existing text that will be replaced. |relative_cursor_pos| is where
//// the cursor will be positioned relative to the current cursor position. See
//// comments on ImeSetComposition for usage. The |replacement_range| and
//// |relative_cursor_pos| values are only used on OS X.
//// This method is only used when window rendering is disabled.
/////
///*--cef(optional_param=text)--*/
// void ImeCommitText(const CefString& text,
//    const CefRange& replacement_range,
//    int relative_cursor_pos);

/////
//// Completes the existing composition by applying the current composition node
//// contents. If |keep_selection| is false the current selection, if any, will
//// be discarded. See comments on ImeSetComposition for usage.
//// This method is only used when window rendering is disabled.
/////
///*--cef()--*/
// void ImeFinishComposingText(bool keep_selection);

/////
//// Cancels the existing composition and discards the composition node
//// contents without applying them. See comments on ImeSetComposition for
//// usage.
//// This method is only used when window rendering is disabled.
/////
///*--cef()--*/
// void ImeCancelComposition();

/////
//// Call this method when the user drags the mouse into the web view (before
//// calling DragTargetDragOver/DragTargetLeave/DragTargetDrop).
//// |drag_data| should not contain file contents as this type of data is not
//// allowed to be dragged into the web view. File contents can be removed using
//// CefDragData::ResetFileContents (for example, if |drag_data| comes from
//// CefRenderHandler::StartDragging).
//// This method is only used when window rendering is disabled.
/////
///*--cef()--*/
// void DragTargetDragEnter(shrewd_ptr<CefDragData> drag_data,
//    const CefMouseEvent& event,
//    DragOperationsMask allowed_ops);

/////
//// Call this method each time the mouse is moved across the web view during
//// a drag operation (after calling DragTargetDragEnter and before calling
//// DragTargetDragLeave/DragTargetDrop).
//// This method is only used when window rendering is disabled.
/////
///*--cef()--*/
// void DragTargetDragOver(const CefMouseEvent& event,
//    DragOperationsMask allowed_ops);

/////
//// Call this method when the user drags the mouse out of the web view (after
//// calling DragTargetDragEnter).
//// This method is only used when window rendering is disabled.
/////
///*--cef()--*/
// void DragTargetDragLeave();

/////
//// Call this method when the user completes the drag operation by dropping
//// the object onto the web view (after calling DragTargetDragEnter).
//// The object being dropped is |drag_data|, given as an argument to
//// the previous DragTargetDragEnter call.
//// This method is only used when window rendering is disabled.
/////
///*--cef()--*/
// void DragTargetDrop(const CefMouseEvent& event);

/////
//// Call this method when the drag operation started by a
//// CefRenderHandler::StartDragging call has ended either in a drop or
//// by being cancelled. |x| and |y| are mouse coordinates relative to the
//// upper-left corner of the view. If the web view is both the drag source
//// and the drag target then all DragTarget* methods should be called before
//// DragSource* mthods.
//// This method is only used when window rendering is disabled.
/////
///*--cef()--*/
// void DragSourceEndedAt(int x, int y, DragOperationsMask op);

/////
//// Call this method when the drag operation started by a
//// CefRenderHandler::StartDragging call has completed. This method may be
//// called immediately without first calling DragSourceEndedAt to cancel a
//// drag operation. If the web view is both the drag source and the drag
//// target then all DragTarget* methods should be called before DragSource*
//// mthods.
//// This method is only used when window rendering is disabled.
/////
///*--cef()--*/
// void DragSourceSystemDragEnded();

/////
//// Returns the current visible navigation entry for this browser. This method
//// can only be called on the UI thread.
/////
///*--cef()--*/
// shrewd_ptr<CefNavigationEntry> GetVisibleNavigationEntry();

/////
//// Set accessibility state for all frames. |accessibility_state| may be
//// default, enabled or disabled. If |accessibility_state| is STATE_DEFAULT
//// then accessibility will be disabled by default and the state may be further
//// controlled with the "force-renderer-accessibility" and
//// "disable-renderer-accessibility" command-line switches. If
//// |accessibility_state| is STATE_ENABLED then accessibility will be enabled.
//// If |accessibility_state| is STATE_DISABLED then accessibility will be
//// completely disabled.
////
//// For windowed browsers accessibility will be enabled in Complete mode (which
//// corresponds to kAccessibilityModeComplete in Chromium). In this mode all
//// platform accessibility objects will be created and managed by Chromium's
//// internal implementation. The client needs only to detect the screen reader
//// and call this method appropriately. For example, on macOS the client can
//// handle the @"AXEnhancedUserInterface" accessibility attribute to detect
//// VoiceOver state changes and on Windows the client can handle WM_GETOBJECT
//// with OBJID_CLIENT to detect accessibility readers.
////
//// For windowless browsers accessibility will be enabled in TreeOnly mode
//// (which corresponds to kAccessibilityModeWebContentsOnly in Chromium). In
//// this mode renderer accessibility is enabled, the full tree is computed, and
//// events are passed to CefAccessibiltyHandler, but platform accessibility
//// objects are not created. The client may implement platform accessibility
//// objects using CefAccessibiltyHandler callbacks if desired.
/////
///*--cef()--*/
// void SetAccessibilityState(cef_state_t accessibility_state);

/////
//// Enable notifications of auto resize via CefDisplayHandler::OnAutoResize.
//// Notifications are disabled by default. |min_size| and |max_size| define the
//// range of allowed sizes.
/////
///*--cef()--*/
// void SetAutoResizeEnabled(bool enabled,
//    const CefSize& min_size,
//    const CefSize& max_size);

/////
//// Returns the extension hosted in this browser or NULL if no extension is
//// hosted. See CefRequestContext::LoadExtension for details.
/////
///*--cef()--*/
// shrewd_ptr<CefExtension> GetExtension();

/////
//// Returns true if this browser is hosting an extension background script.
//// Background hosts do not have a window and are not displayable. See
//// CefRequestContext::LoadExtension for details.
/////
///*--cef()--*/
// bool IsBackgroundHost();

///
//  Set whether the browser's audio is muted.
///
/*--cef()--*/
void ProxyBrowserHost::SetAudioMuted(bool mute) {
    ASSERTN();
    FORWARD(CefBrowserHost)->SetAudioMuted(mute);
}

///
// Returns true if the browser's audio is muted.  This method can only be
// called on the UI thread.
///
/*--cef()--*/
bool ProxyBrowserHost::IsAudioMuted() {
    ASSERTQ(false);
    return FORWARD(CefBrowserHost)->IsAudioMuted();
}

///
// Open developer tools (DevTools) in its own browser. The DevTools browser
// will remain associated with this browser. If the DevTools browser is
// already open then it will be focused, in which case the |windowInfo|,
// |client| and |settings| parameters will be ignored. If |inspect_element_at|
// is non-empty then the element at the specified (x,y) location will be
// inspected. The |windowInfo| parameter will be ignored if this browser is
// wrapped in a CefBrowserView.
///
/*--cef(optional_param=windowInfo,optional_param=client,
        optional_param=settings,optional_param=inspect_element_at)--*/
void ProxyBrowserHost::ShowDevTools(shrewd_ptr<ProxyWindowInfo> windowInfo,
    shrewd_ptr<ProxyBrowserSettings> settings,
    int inspect_element_at_x, int inspect_element_at_y) {
    CefWindowInfo winInfo;
    CefBrowserSettings browserSettings;
    ASSERTN();
    if (windowInfo && windowInfo->OriginPointer()) {
        winInfo = *((CefWindowInfo*)windowInfo->OriginPointer());
    }
    if (settings && settings->OriginPointer()) {
        browserSettings = *((CefBrowserSettings*)settings->OriginPointer());
    }
    FORWARD(CefBrowserHost)->ShowDevTools(
        winInfo, new InternalDevToolsClient, browserSettings,
        CefPoint(inspect_element_at_x, inspect_element_at_y)
    );
}

///
// Explicitly close the associated DevTools browser, if any.
///
/*--cef()--*/
void ProxyBrowserHost::CloseDevTools() {
    ASSERTN();
    FORWARD(CefBrowserHost)->CloseDevTools();
}

///
// Returns true if this browser currently has an associated DevTools browser.
// Must be called on the browser process UI thread.
///
/*--cef()--*/
bool ProxyBrowserHost::HasDevTools() {
    ASSERTQ(false);
    return FORWARD(CefBrowserHost)->HasDevTools();
}