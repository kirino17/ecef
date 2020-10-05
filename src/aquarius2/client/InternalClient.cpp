#include "InternalClient.h"
#include <atlconv.h>
#include "../proxy/ProxyWindowInfo.h"
#include <atlconv.h>
#include "../def/internalDef.h"
#include "InternalCalculationVisitor.h"
#include "InternalResponseFilter.h"

#pragma comment(lib,"user32.lib")

namespace Local {
    CefRefPtr<InternalClient> shareInstance = nullptr;
}

InternalClient::InternalClient(shrewd_ptr<ProxyClient> client):
	_proxyClient(client)
{

}

InternalClient::~InternalClient() {
	_proxyClient = NULL;
}

CefRefPtr<InternalClient> InternalClient::GetShareInatance() {
    if (!Local::shareInstance) {
        Local::shareInstance = new InternalClient();
    }
    return Local::shareInstance;
}

void InternalClient::SetClient(shrewd_ptr<ProxyClient> client) {
    _proxyClient = client;
}

shrewd_ptr<ProxyClient> InternalClient::GetClient(void) {
    return _proxyClient;
}

bool InternalClient::OnBeforePopup(CefRefPtr<CefBrowser> browser,
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
) {
    bool result = false;

    if (_proxyClient) {
        USES_CONVERSION;
        const char* tempTargetUri = NULL;
        const char* tempTargetName = NULL;

        shrewd_ptr<ProxyWindowInfo> winInfo = new ProxyWindowInfo(
            new CefWindowInfo(windowInfo)
        );
        shrewd_ptr<ProxyBrowserSettings> browserSetting = new ProxyBrowserSettings(
            new CefBrowserSettings(settings)
        );

        if (target_url.length() > 0) {
            tempTargetUri = W2A(target_url.c_str());
        }
        if (target_frame_name.length() > 0) {
            tempTargetName = W2A(target_frame_name.c_str());
        }

        int nNoJavaScriptAccess = (int)*no_javascript_access;

        result = _proxyClient->OnBeforePopup(
            new ProxyBrowser(browser),
            new ProxyFrame(frame),
            tempTargetUri,
            tempTargetName,
            target_disposition,
            user_gesture,
            new ProxyPopupFeatures(new CefPopupFeatures(popupFeatures)),
            winInfo,
            browserSetting,
            new ProxyDictionaryValue(extra_info),
            nNoJavaScriptAccess);
        if (nNoJavaScriptAccess) {
            *no_javascript_access = true;
        }
        windowInfo.Set(*(CefWindowInfo*)winInfo->OriginPointer(), true);
        settings.Set(*(CefBrowserSettings*)browserSetting->OriginPointer(), true);
    }

    return result;
}

void InternalClient::OnAfterCreated(CefRefPtr<CefBrowser> browser) {
    if (_proxyClient) {
        _proxyClient->OnAfterCreated(new ProxyBrowser(browser));
    }
}

bool InternalClient::DoClose(CefRefPtr<CefBrowser> browser) {
    bool result = false;
    if (_proxyClient) {
        result = !(_proxyClient->DoClose(new ProxyBrowser(browser)));
    }

    if (result == false) {
        CefRefPtr<CefBrowserHost> host = browser->GetHost();
        HWND hWnd = host->GetWindowHandle();
        ShowWindow(hWnd,SW_HIDE);
        SetParent(hWnd, NULL);
    }
    return result;
}

void InternalClient::OnBeforeClose(CefRefPtr<CefBrowser> browser) {
    if (_proxyClient) {
        _proxyClient->OnBeforeClose(new ProxyBrowser(browser));
    }
}

void InternalClient::OnLoadingStateChange(CefRefPtr<CefBrowser> browser,
    bool isLoading,
    bool canGoBack,
    bool canGoForward){
    if (_proxyClient) {
        _proxyClient->OnLoadingStateChange(new ProxyBrowser(browser), isLoading, canGoBack, canGoForward);
    }
}

void InternalClient::OnLoadStart(CefRefPtr<CefBrowser> browser,
    CefRefPtr<CefFrame> frame,
    TransitionType transition_type){
    if (_proxyClient) {
        _proxyClient->OnLoadStart(new ProxyBrowser(browser),
            new ProxyFrame(frame), (int)transition_type);
    }
}

void InternalClient::OnLoadEnd(CefRefPtr<CefBrowser> browser,
    CefRefPtr<CefFrame> frame,
    int httpStatusCode){
    if (_proxyClient) {
        _proxyClient->OnLoadEnd(new ProxyBrowser(browser),
            new ProxyFrame(frame), httpStatusCode);
    }
}

void InternalClient::OnLoadError(CefRefPtr<CefBrowser> browser,
    CefRefPtr<CefFrame> frame,
    ErrorCode errorCode,
    const CefString& errorText,
    const CefString& failedUrl){
    if (_proxyClient) {
        const char* tempErrorText = NULL;
        const char* tempFailedUrl = NULL;
        USES_CONVERSION;
        if (errorText.length() > 0) {
            tempErrorText = W2A(errorText.c_str());
        }
        if (failedUrl.length() > 0) {
            tempFailedUrl = W2A(failedUrl.c_str());
        }
        _proxyClient->OnLoadError(new ProxyBrowser(browser),
            new ProxyFrame(frame),(int)errorCode, tempErrorText, tempFailedUrl);
    }
}

void InternalClient::OnAddressChange(CefRefPtr<CefBrowser> browser,
    CefRefPtr<CefFrame> frame,
    const CefString& url){
    if (_proxyClient) {
        const char* tempUrl = NULL;
        if (url.length() > 0) {
            USES_CONVERSION;
            tempUrl = W2A(url.c_str());
        }
        _proxyClient->OnAddressChange(new ProxyBrowser(browser), new ProxyFrame(frame), tempUrl);
    }
}

void InternalClient::OnTitleChange(CefRefPtr<CefBrowser> browser,
    const CefString& title){
    if (_proxyClient) {
        const char* tempTitle = NULL;
        if (title.length() > 0) {
            USES_CONVERSION;
            tempTitle = W2A(title.c_str());
        }
        _proxyClient->OnTitleChange(new ProxyBrowser(browser), tempTitle);
    }
}

void InternalClient::OnFaviconURLChange(CefRefPtr<CefBrowser> browser,
    const std::vector<CefString>& icon_urls){
    if (_proxyClient) {
        assert(NewBuffer);
        char* buffer = NULL;
        if (icon_urls.size() > 0) {
            buffer = StringArrayToBuffer(icon_urls, L"\r\n");
        }
        _proxyClient->OnFaviconURLChange(new ProxyBrowser(browser), buffer);
        if(buffer) {
            DeleteBuffer(buffer);
        }
    }
}

void InternalClient::OnFullscreenModeChange(CefRefPtr<CefBrowser> browser,
    bool fullscreen){
    if (_proxyClient) {
        _proxyClient->OnFullscreenModeChange(new ProxyBrowser(browser), fullscreen);
    }
}

bool InternalClient::OnTooltip(CefRefPtr<CefBrowser> browser, CefString& text){
    bool result = false;
    if (_proxyClient) {
        const char* tempText = NULL;
        if (text.length() > 0) {
            USES_CONVERSION;
            tempText = W2A(text.c_str());
        }
        result = _proxyClient->OnTooltip(new ProxyBrowser(browser), tempText);
    }
    return result;
}

void InternalClient::OnStatusMessage(CefRefPtr<CefBrowser> browser,
    const CefString& value){
    if (_proxyClient) {
        const char* tempText = NULL;
        if (value.length() > 0) {
            USES_CONVERSION;
            tempText = W2A(value.c_str());
        }
        _proxyClient->OnStatusMessage(new ProxyBrowser(browser), tempText);
    }
}

bool InternalClient::OnConsoleMessage(CefRefPtr<CefBrowser> browser,
    cef_log_severity_t level,
    const CefString& message,
    const CefString& source,
    int line){
    bool result = false;
    if (_proxyClient) {
        const char* tempMessage = NULL;
        const char* tempSource = NULL;
        USES_CONVERSION;

        if (message.length() > 0) {
            tempMessage = W2A(message.c_str());
        }
        if (source.length() > 0) {
            tempSource = W2A(source.c_str());
        }
        result = _proxyClient->OnConsoleMessage(new ProxyBrowser(browser),
            (int)level, tempMessage, tempSource, line);
    }
    return result;
}

bool InternalClient::OnAutoResize(CefRefPtr<CefBrowser> browser,
    const CefSize& new_size){
    bool result = false;
    if (_proxyClient) {
        result = _proxyClient->OnAutoResize(new ProxyBrowser(browser), new_size.width, new_size.height);
    }
    return result;
}

void InternalClient::OnLoadingProgressChange(CefRefPtr<CefBrowser> browser,
    double progress){
    if (_proxyClient) {
        _proxyClient->OnLoadingProgressChange(new ProxyBrowser(browser), progress);
    }
}

void InternalClient::OnTakeFocus(CefRefPtr<CefBrowser> browser, bool next) {
    if (_proxyClient) {
        _proxyClient->OnTakeFocus(new ProxyBrowser(browser), next);
    }
}

bool InternalClient::OnSetFocus(CefRefPtr<CefBrowser> browser, FocusSource source) {
    bool result = false;
    if (_proxyClient) {
        result = _proxyClient->OnSetFocus(new ProxyBrowser(browser), source);
    }
    return result;
}

void InternalClient::OnGotFocus(CefRefPtr<CefBrowser> browser) {
    if (_proxyClient) {
        _proxyClient->OnGotFocus(new ProxyBrowser(browser));
    }
}

bool InternalClient::OnJSDialog(CefRefPtr<CefBrowser> browser,
    const CefString& origin_url,
    JSDialogType dialog_type,
    const CefString& message_text,
    const CefString& default_prompt_text,
    CefRefPtr<CefJSDialogCallback> callback,
    bool& suppress_message) {
    bool result = false;
    if (_proxyClient) {
        const char* strValue0 = NULL;
        const char* strValue1 = NULL;
        const char* strValue2 = NULL;
        USES_CONVERSION;

        if (!origin_url.empty()) {
            strValue0 = W2A(origin_url.c_str());
        }

        if (!message_text.empty()) {
            strValue1 = W2A(message_text.c_str());
        }

        if (!default_prompt_text.empty()) {
            strValue2 = W2A(default_prompt_text.c_str());
        }
        int nSupperessMessage = (int)suppress_message;
        result = _proxyClient->OnJSDialog(
            new ProxyBrowser(browser), 
            strValue0, dialog_type,
            strValue1, strValue2,
            new ProxyJSDialogCallback(callback),
            nSupperessMessage);
    }
    return result;
 }

bool InternalClient::OnBeforeUnloadDialog(CefRefPtr<CefBrowser> browser,
    const CefString& message_text,
    bool is_reload,
    CefRefPtr<CefJSDialogCallback> callback) {
    bool result = false;
    if (_proxyClient) {
        const char* strValue1 = NULL;
        USES_CONVERSION;

        if (!message_text.empty()) {
            strValue1 = W2A(message_text.c_str());
        }

        result = _proxyClient->OnBeforeUnloadDialog(
            new ProxyBrowser(browser), 
            strValue1,
            is_reload, new ProxyJSDialogCallback(callback));
    }
    return result;
}

void InternalClient::OnResetDialogState(CefRefPtr<CefBrowser> browser) {
    if (_proxyClient) {
        _proxyClient->OnResetDialogState(new ProxyBrowser(browser));
    }
}

void InternalClient::OnDialogClosed(CefRefPtr<CefBrowser> browser) {
    if (_proxyClient) {
        _proxyClient->OnDialogClosed(new ProxyBrowser(browser));
    }
}

bool InternalClient::OnBeforeBrowse(CefRefPtr<CefBrowser> browser,
    CefRefPtr<CefFrame> frame,
    CefRefPtr<CefRequest> request,
    bool user_gesture,
    bool is_redirect) {
    bool result = false;
    if (_proxyClient) {
        result = _proxyClient->OnBeforeBrowse(
            new ProxyBrowser(browser),
            new ProxyFrame(frame),
            new ProxyRequest(request),
            user_gesture, is_redirect);
    }
    return result;
 }

bool InternalClient::OnOpenURLFromTab(CefRefPtr<CefBrowser> browser,
    CefRefPtr<CefFrame> frame,
    const CefString& target_url,
    CefRequestHandler::WindowOpenDisposition target_disposition,
    bool user_gesture) {
    bool result = false;
    if (_proxyClient) {
        const char* strValue = NULL;
        USES_CONVERSION;
        if (!target_url.empty()) {
            strValue = W2A(target_url.c_str());
        }

        result = _proxyClient->OnOpenURLFromTab(
            new ProxyBrowser(browser),
            new ProxyFrame(frame),
            strValue,target_disposition, user_gesture);
    }
    return result;
 }

CefRefPtr<CefResourceRequestHandler> InternalClient::GetResourceRequestHandler(
     CefRefPtr<CefBrowser> browser,
     CefRefPtr<CefFrame> frame,
     CefRefPtr<CefRequest> request,
     bool is_navigation,
     bool is_download,
     const CefString& request_initiator,
     bool& disable_default_handling) {
    bool result = false;
    if (_proxyClient) {
        const char* strValue = NULL;
        USES_CONVERSION;
        if (!request_initiator.empty()) {
            strValue = W2A(request_initiator.c_str());
        }

        result = _proxyClient->GetResourceRequestHandler(
            new ProxyBrowser(browser),
            new ProxyFrame(frame),
            new ProxyRequest(request),
            is_navigation, is_download, strValue);
    }
    return result ? this : nullptr;
}

bool InternalClient::GetAuthCredentials(CefRefPtr<CefBrowser> browser,
    const CefString& origin_url,
    bool isProxy,
    const CefString& host,
    int port,
    const CefString& realm,
    const CefString& scheme,
    CefRefPtr<CefAuthCallback> callback) {
    bool result = false;
    if (_proxyClient) {
        const char* strValue0 = NULL;
        const char* strValue1 = NULL;
        const char* strValue2 = NULL;
        const char* strValue3 = NULL;
        USES_CONVERSION;
        if (!origin_url.empty()) {
            strValue0 = W2A(origin_url.c_str());
        }
        if (!host.empty()) {
            strValue1 = W2A(host.c_str());
        }
        if (!realm.empty()) {
            strValue2 = W2A(realm.c_str());
        }
        if (!scheme.empty()) {
            strValue3 = W2A(scheme.c_str());
        }

        result = _proxyClient->GetAuthCredentials(
            new ProxyBrowser(browser),
            strValue0,isProxy, strValue1, port, strValue2, strValue3,
            new ProxyAuthCallback(callback));
    }
    return result;
 }

bool InternalClient::OnQuotaRequest(CefRefPtr<CefBrowser> browser,
    const CefString& origin_url,
    int64 new_size,
    CefRefPtr<CefRequestCallback> callback) {
    bool result = false;
    if (_proxyClient) {
        const char* strValue0 = NULL;
        USES_CONVERSION;
        if (!origin_url.empty()) {
            strValue0 = W2A(origin_url.c_str());
        }

        result = _proxyClient->OnQuotaRequest(
            new ProxyBrowser(browser),
            strValue0, new_size, 
            new ProxyRequestCallback(callback));
    }
    return result;
}


void InternalClient::OnPluginCrashed(CefRefPtr<CefBrowser> browser,
    const CefString& plugin_path) {
    if (_proxyClient) {
        const char* strValue0 = NULL;
        USES_CONVERSION;
        if (!plugin_path.empty()) {
            strValue0 = W2A(plugin_path.c_str());
        }
        _proxyClient->OnPluginCrashed(new ProxyBrowser(browser), strValue0);
    }
}

void InternalClient::OnRenderViewReady(CefRefPtr<CefBrowser> browser) {
    if (_proxyClient) {
        _proxyClient->OnRenderViewReady(new ProxyBrowser(browser));
    }
}

void InternalClient::OnRenderProcessTerminated(CefRefPtr<CefBrowser> browser,
    TerminationStatus status) {
    if (_proxyClient) {
        _proxyClient->OnRenderProcessTerminated(new ProxyBrowser(browser), status);
    }
}

CefResourceRequestHandler::ReturnValue InternalClient::OnBeforeResourceLoad(
    CefRefPtr<CefBrowser> browser,
    CefRefPtr<CefFrame> frame,
    CefRefPtr<CefRequest> request,
    CefRefPtr<CefRequestCallback> callback) {
    auto result = RV_CONTINUE;
    if (_proxyClient) {
        result = (ReturnValue)_proxyClient->OnBeforeResourceLoad(
            new ProxyBrowser(browser),
            new ProxyFrame(frame),
            new ProxyRequest(request),
            new ProxyRequestCallback(callback));
    }
    return result;
 }

void InternalClient::OnResourceRedirect(CefRefPtr<CefBrowser> browser,
    CefRefPtr<CefFrame> frame,
    CefRefPtr<CefRequest> request,
    CefRefPtr<CefResponse> response,
    CefString& new_url) {
    if (_proxyClient) {
        char* setUrl = NULL;
        _proxyClient->OnResourceRedirect(
            new ProxyBrowser(browser),
            new ProxyFrame(frame),
            new ProxyRequest(request),
            new ProxyResponse( response ), setUrl);
        if (setUrl) {
            USES_CONVERSION;
            new_url = A2W(setUrl);
            DeleteBuffer(setUrl);
        }
    }
 }

bool InternalClient::OnResourceResponse(CefRefPtr<CefBrowser> browser,
    CefRefPtr<CefFrame> frame,
    CefRefPtr<CefRequest> request,
    CefRefPtr<CefResponse> response) {
    bool result = false;
    if (_proxyClient) {
        result = _proxyClient->OnResourceResponse(
            new ProxyBrowser(browser),
            new ProxyFrame(frame),
            new ProxyRequest(request),
            new ProxyResponse(response));
    }
    return result;
 }

CefRefPtr<CefResponseFilter> InternalClient::GetResourceResponseFilter(
    CefRefPtr<CefBrowser> browser,
    CefRefPtr<CefFrame> frame,
    CefRefPtr<CefRequest> request,
    CefRefPtr<CefResponse> response) {
    CefRefPtr<InternalResponseFilter> result = nullptr;
    if (_proxyClient) {
       bool enable = _proxyClient->OnResourceResponseFilter(
            new ProxyBrowser(browser),
            new ProxyFrame(frame),
            new ProxyRequest(request),
            new ProxyResponse(response)
        );
       if (enable) {
           result = new InternalResponseFilter(browser, request->GetURL(), response->GetMimeType());
       }
    }

    return result;
}

void InternalClient::OnResourceLoadComplete(CefRefPtr<CefBrowser> browser,
    CefRefPtr<CefFrame> frame,
    CefRefPtr<CefRequest> request,
    CefRefPtr<CefResponse> response,
    URLRequestStatus status,
    int64 received_content_length) {
    if (_proxyClient) {
        _proxyClient->OnResourceLoadComplete(
            new ProxyBrowser(browser),
            new ProxyFrame(frame),
            new ProxyRequest(request),
            new ProxyResponse(response),
            status, received_content_length);
    }
 }

void InternalClient::OnProtocolExecution(CefRefPtr<CefBrowser> browser,
    CefRefPtr<CefFrame> frame,
    CefRefPtr<CefRequest> request,
    bool& allow_os_execution) {
    if (_proxyClient) {
        int nAllowOsExecution = (int)allow_os_execution;
        _proxyClient->OnProtocolExecution(
            new ProxyBrowser(browser),
            new ProxyFrame(frame),
            new ProxyRequest(request),
            nAllowOsExecution);
    }
 }

bool InternalClient::OnProcessMessageReceived(CefRefPtr<CefBrowser> browser,
    CefRefPtr<CefFrame> frame,
    CefProcessId source_process,
    CefRefPtr<CefProcessMessage> message) {
    CefString string = message->GetName();
    if (string == L"IPC_V8_RESULT") {
        CefRefPtr<CefListValue> arguments = message->GetArgumentList();
        if (arguments->GetSize() < 4) {
            return false;
        }
        DispatchResult(browser, frame, arguments);
        return true;
    }
    return false;
}

void InternalClient::DispatchResult(CefRefPtr<CefBrowser> browser,
    CefRefPtr<CefFrame> frame,
    CefRefPtr<CefListValue> arguments) {
    CefRefPtr<InternalCalculationVisitior> calculation = (InternalCalculationVisitior*)arguments->GetInt(1);
    CefRefPtr<CefValue> value = nullptr;
    if (calculation) { 
        if (arguments->GetBool(2)) {
            calculation->SetResult(arguments->GetValue(3));
        }
        else {
            value = CefValue::Create();
            value->SetString(arguments->GetString(3));
            calculation->SetException(value);
        }
        calculation->Awake();
    }
}

bool InternalClient::OnFileDialog(CefRefPtr<CefBrowser> browser,
    FileDialogMode mode,
    const CefString& title,
    const CefString& default_file_path,
    const std::vector<CefString>& accept_filters,
    int selected_accept_filter,
    CefRefPtr<CefFileDialogCallback> callback) {
    bool result = false;

    if (_proxyClient) {
        const char* szTitle = NULL;
        const char* szDefaultFilePath = NULL;
        char* szAcceptFilters = NULL;
        USES_CONVERSION;

        if (!title.empty()) {
            szTitle = W2A(title.c_str());
        }

        if (!default_file_path.empty()) {
            szDefaultFilePath = W2A(default_file_path.c_str());
        }

        if (!accept_filters.empty()) {
            szAcceptFilters = StringArrayToBuffer(accept_filters,L";");
        }

        result = _proxyClient->OnFileDialog(
            new ProxyBrowser(browser),
            mode,
            szTitle,szDefaultFilePath, szAcceptFilters,
            selected_accept_filter,new ProxyFileDialogCallback( callback ));

        if (szAcceptFilters) {
            DeleteBuffer(szAcceptFilters);
        }
    }

    return result;
}

void InternalClient::OnBeforeContextMenu(CefRefPtr<CefBrowser> browser,
    CefRefPtr<CefFrame> frame,
    CefRefPtr<CefContextMenuParams> params,
    CefRefPtr<CefMenuModel> model) {
    if (_proxyClient) {
        _proxyClient->OnBeforeContextMenu(
            new ProxyBrowser(browser),
            new ProxyFrame(frame),
            new ProxyContextMenuParams( params ),
            new ProxyMenuModel( model )
        );
    }
}

bool InternalClient::RunContextMenu(CefRefPtr<CefBrowser> browser,
    CefRefPtr<CefFrame> frame,
    CefRefPtr<CefContextMenuParams> params,
    CefRefPtr<CefMenuModel> model,
    CefRefPtr<CefRunContextMenuCallback> callback) {
    bool result = false;
    if (_proxyClient) {
        result = _proxyClient->RunContextMenu(
            new ProxyBrowser(browser),
            new ProxyFrame(frame),
            new ProxyContextMenuParams(params),
            new ProxyMenuModel(model),
            new ProxyRunContextMenuCallback(callback)
        );
    }
    return result;
}

bool InternalClient::OnContextMenuCommand(CefRefPtr<CefBrowser> browser,
    CefRefPtr<CefFrame> frame,
    CefRefPtr<CefContextMenuParams> params,
    int command_id,
    EventFlags event_flags) {
    bool result = false;
    if (_proxyClient) {
        result = _proxyClient->OnContextMenuCommand(
            new ProxyBrowser(browser),
            new ProxyFrame(frame),
            new ProxyContextMenuParams(params),
            command_id,
            event_flags
        );
    }
    return result;
}

void InternalClient::OnContextMenuDismissed(CefRefPtr<CefBrowser> browser,
    CefRefPtr<CefFrame> frame) {
    if (_proxyClient) {
        _proxyClient->OnContextMenuDismissed(
            new ProxyBrowser(browser),
            new ProxyFrame(frame));
    }
}

void InternalClient::OnBeforeDownload(
    CefRefPtr<CefBrowser> browser,
    CefRefPtr<CefDownloadItem> download_item,
    const CefString& suggested_name,
    CefRefPtr<CefBeforeDownloadCallback> callback) {
    if (_proxyClient) {
        const char* szSuggestedName = NULL;
        USES_CONVERSION;
        if (!suggested_name.empty()) {
            szSuggestedName = W2A(suggested_name.c_str());
        }

        _proxyClient->OnBeforeDownload(
            new ProxyBrowser(browser),
            new ProxyDownloadItem(browser),
            szSuggestedName,
            new ProxyBeforeDownloadCallback( callback ));
    }
}

void InternalClient::OnDownloadUpdated(CefRefPtr<CefBrowser> browser,
    CefRefPtr<CefDownloadItem> download_item,
    CefRefPtr<CefDownloadItemCallback> callback) {
    if (_proxyClient) {
        _proxyClient->OnDownloadUpdated(
            new ProxyBrowser(browser),
            new ProxyDownloadItem(browser),
            new ProxyDownloadItemCallback(callback));
    }
}