#pragma once
#include "include/cef_client.h"
#include "include/cef_cookie.h"
#include "../proxy/ProxyClient.h"
#include "include/cef_request_context_handler.h"
#include "include/cef_task.h"
#include "include/wrapper/cef_message_router.h"

class InternalClient : public CefClient,
	public CefLifeSpanHandler,
    public CefLoadHandler,
    public CefDisplayHandler,
    public CefJSDialogHandler,
    public CefRequestHandler,
    public CefResourceRequestHandler,
    public CefDialogHandler,
    public CefDownloadHandler,
    public CefContextMenuHandler
{
public:
	InternalClient(shrewd_ptr<ProxyClient> client = NULL);
	~InternalClient();

public:
    static CefRefPtr<InternalClient> GetShareInatance();

public:
    void SetClient(shrewd_ptr<ProxyClient> client);
    shrewd_ptr<ProxyClient> GetClient(void);

public:
	virtual CefRefPtr<CefLifeSpanHandler> GetLifeSpanHandler() override { return this; }
    virtual CefRefPtr<CefLoadHandler> GetLoadHandler() override { return this; }
    virtual CefRefPtr<CefDisplayHandler> GetDisplayHandler() override { return this; }
    virtual CefRefPtr<CefJSDialogHandler> GetJSDialogHandler() override { return this; }
    virtual CefRefPtr<CefRequestHandler> GetRequestHandler() override { return this; }
    virtual CefRefPtr<CefDialogHandler> GetDialogHandler() override { return this; }
    virtual CefRefPtr<CefDownloadHandler> GetDownloadHandler() override { return this; }
    virtual CefRefPtr<CefContextMenuHandler> GetContextMenuHandler() override { return this; }
public:
    virtual bool OnBeforePopup(CefRefPtr<CefBrowser> browser,
        CefRefPtr<CefFrame> frame,
        const CefString& target_url,
        const CefString& target_frame_name,
        CefLifeSpanHandler::WindowOpenDisposition target_disposition,
        bool user_gesture,
        const CefPopupFeatures& popupFeatures,
        CefWindowInfo& windowInfo,
        CefRefPtr<CefClient>& client,
        CefBrowserSettings& settings,
        CefRefPtr<CefDictionaryValue>& extra_info,
        bool* no_javascript_access
    ) OVERRIDE;

    virtual void OnAfterCreated(CefRefPtr<CefBrowser> browser) OVERRIDE;
    virtual bool DoClose(CefRefPtr<CefBrowser> browser) OVERRIDE;
    virtual void OnBeforeClose(CefRefPtr<CefBrowser> browser) OVERRIDE;

public:
    virtual void OnLoadingStateChange(CefRefPtr<CefBrowser> browser,
        bool isLoading,
        bool canGoBack,
        bool canGoForward) OVERRIDE;

    virtual void OnLoadStart(CefRefPtr<CefBrowser> browser,
        CefRefPtr<CefFrame> frame,
        TransitionType transition_type) OVERRIDE;

    virtual void OnLoadEnd(CefRefPtr<CefBrowser> browser,
        CefRefPtr<CefFrame> frame,
        int httpStatusCode) OVERRIDE;

    virtual void OnLoadError(CefRefPtr<CefBrowser> browser,
        CefRefPtr<CefFrame> frame,
        ErrorCode errorCode,
        const CefString& errorText,
        const CefString& failedUrl) OVERRIDE;

public:
    virtual void OnBeforeContextMenu(CefRefPtr<CefBrowser> browser,
        CefRefPtr<CefFrame> frame,
        CefRefPtr<CefContextMenuParams> params,
        CefRefPtr<CefMenuModel> model) OVERRIDE;

    virtual bool RunContextMenu(CefRefPtr<CefBrowser> browser,
        CefRefPtr<CefFrame> frame,
        CefRefPtr<CefContextMenuParams> params,
        CefRefPtr<CefMenuModel> model,
        CefRefPtr<CefRunContextMenuCallback> callback) OVERRIDE;

    virtual bool OnContextMenuCommand(CefRefPtr<CefBrowser> browser,
        CefRefPtr<CefFrame> frame,
        CefRefPtr<CefContextMenuParams> params,
        int command_id,
        EventFlags event_flags) OVERRIDE;

    virtual void OnContextMenuDismissed(CefRefPtr<CefBrowser> browser,
        CefRefPtr<CefFrame> frame) OVERRIDE;

public:
    virtual void OnAddressChange(CefRefPtr<CefBrowser> browser,
        CefRefPtr<CefFrame> frame,
        const CefString& url) OVERRIDE;

    virtual void OnTitleChange(CefRefPtr<CefBrowser> browser,
        const CefString& title) OVERRIDE;

    virtual void OnFaviconURLChange(CefRefPtr<CefBrowser> browser,
        const std::vector<CefString>& icon_urls) OVERRIDE;

    virtual bool OnTooltip(CefRefPtr<CefBrowser> browser, CefString& text) OVERRIDE;

    virtual void OnStatusMessage(CefRefPtr<CefBrowser> browser,
        const CefString& value) OVERRIDE;

    virtual bool OnConsoleMessage(CefRefPtr<CefBrowser> browser,
        cef_log_severity_t level,
        const CefString& message,
        const CefString& source,
        int line) OVERRIDE;

    virtual bool OnAutoResize(CefRefPtr<CefBrowser> browser,
        const CefSize& new_size) OVERRIDE;

    virtual void OnLoadingProgressChange(CefRefPtr<CefBrowser> browser,
        double progress) OVERRIDE;

public:
    virtual bool OnJSDialog(CefRefPtr<CefBrowser> browser,
        const CefString& origin_url,
        JSDialogType dialog_type,
        const CefString& message_text,
        const CefString& default_prompt_text,
        CefRefPtr<CefJSDialogCallback> callback,
        bool& suppress_message) override;

    virtual bool OnBeforeUnloadDialog(CefRefPtr<CefBrowser> browser,
        const CefString& message_text,
        bool is_reload,
        CefRefPtr<CefJSDialogCallback> callback) override;

    virtual void OnResetDialogState(CefRefPtr<CefBrowser> browser) override;

    virtual void OnDialogClosed(CefRefPtr<CefBrowser> browser) override;

public:
    virtual CefRefPtr<CefResourceRequestHandler> GetResourceRequestHandler(
        CefRefPtr<CefBrowser> browser,
        CefRefPtr<CefFrame> frame,
        CefRefPtr<CefRequest> request,
        bool is_navigation,
        bool is_download,
        const CefString& request_initiator,
        bool& disable_default_handling) override;

    virtual bool GetAuthCredentials(CefRefPtr<CefBrowser> browser,
        const CefString& origin_url,
        bool isProxy,
        const CefString& host,
        int port,
        const CefString& realm,
        const CefString& scheme,
        CefRefPtr<CefAuthCallback> callback) override;

    virtual bool OnQuotaRequest(CefRefPtr<CefBrowser> browser,
        const CefString& origin_url,
        int64 new_size,
        CefRefPtr<CefRequestCallback> callback) override;


    virtual void OnPluginCrashed(CefRefPtr<CefBrowser> browser,
        const CefString& plugin_path) OVERRIDE;

    virtual void OnRenderViewReady(CefRefPtr<CefBrowser> browser) OVERRIDE;

    virtual void OnRenderProcessTerminated(CefRefPtr<CefBrowser> browser,
        TerminationStatus status) OVERRIDE;

    virtual CefRefPtr<CefResponseFilter> GetResourceResponseFilter(
        CefRefPtr<CefBrowser> browser,
        CefRefPtr<CefFrame> frame,
        CefRefPtr<CefRequest> request,
        CefRefPtr<CefResponse> response)  OVERRIDE;
public:
    virtual ReturnValue OnBeforeResourceLoad(
        CefRefPtr<CefBrowser> browser,
        CefRefPtr<CefFrame> frame,
        CefRefPtr<CefRequest> request,
        CefRefPtr<CefRequestCallback> callback) OVERRIDE;

    virtual void OnResourceRedirect(CefRefPtr<CefBrowser> browser,
        CefRefPtr<CefFrame> frame,
        CefRefPtr<CefRequest> request,
        CefRefPtr<CefResponse> response,
        CefString& new_url) OVERRIDE;

    virtual bool OnResourceResponse(CefRefPtr<CefBrowser> browser,
        CefRefPtr<CefFrame> frame,
        CefRefPtr<CefRequest> request,
        CefRefPtr<CefResponse> response) OVERRIDE;

    virtual void OnResourceLoadComplete(CefRefPtr<CefBrowser> browser,
        CefRefPtr<CefFrame> frame,
        CefRefPtr<CefRequest> request,
        CefRefPtr<CefResponse> response,
        URLRequestStatus status,
        int64 received_content_length) OVERRIDE;

    virtual void OnProtocolExecution(CefRefPtr<CefBrowser> browser,
        CefRefPtr<CefFrame> frame,
        CefRefPtr<CefRequest> request,
        bool& allow_os_execution) OVERRIDE;

public:
    virtual bool OnFileDialog(CefRefPtr<CefBrowser> browser,
        FileDialogMode mode,
        const CefString& title,
        const CefString& default_file_path,
        const std::vector<CefString>& accept_filters,
        int selected_accept_filter,
        CefRefPtr<CefFileDialogCallback> callback) OVERRIDE;

public:
    virtual void OnBeforeDownload(
        CefRefPtr<CefBrowser> browser,
        CefRefPtr<CefDownloadItem> download_item,
        const CefString& suggested_name,
        CefRefPtr<CefBeforeDownloadCallback> callback) OVERRIDE;

    virtual void OnDownloadUpdated(CefRefPtr<CefBrowser> browser,
        CefRefPtr<CefDownloadItem> download_item,
        CefRefPtr<CefDownloadItemCallback> callback) OVERRIDE;

    virtual void OnFullscreenModeChange(CefRefPtr<CefBrowser> browser,
        bool fullscreen) OVERRIDE;

    ///
    // Called on the UI thread before browser navigation. Return true to cancel
    // the navigation or false to allow the navigation to proceed. The |request|
    // object cannot be modified in this callback.
    // CefLoadHandler::OnLoadingStateChange will be called twice in all cases.
    // If the navigation is allowed CefLoadHandler::OnLoadStart and
    // CefLoadHandler::OnLoadEnd will be called. If the navigation is canceled
    // CefLoadHandler::OnLoadError will be called with an |errorCode| value of
    // ERR_ABORTED. The |user_gesture| value will be true if the browser
    // navigated via explicit user gesture (e.g. clicking a link) or false if it
    // navigated automatically (e.g. via the DomContentLoaded event).
    ///
    /*--cef()--*/
    virtual bool OnBeforeBrowse(CefRefPtr<CefBrowser> browser,
        CefRefPtr<CefFrame> frame,
        CefRefPtr<CefRequest> request,
        bool user_gesture,
        bool is_redirect) OVERRIDE;

public:
    virtual bool OnProcessMessageReceived(CefRefPtr<CefBrowser> browser,
        CefRefPtr<CefFrame> frame,
        CefProcessId source_process,
        CefRefPtr<CefProcessMessage> message) OVERRIDE;

public:
    void DispatchJsResult(CefRefPtr<CefBrowser> browser, 
        CefRefPtr<CefFrame> frame,
        CefRefPtr<CefListValue> arguments);

public:
	IMPLEMENT_REFCOUNTING(InternalClient);

private:
	shrewd_ptr<ProxyClient> _proxyClient;
    CefRefPtr<CefMessageRouterBrowserSide> _messageRouter;
};