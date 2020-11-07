#include "InternalClient.h"
#include <atlconv.h>
#include "../proxy/ProxyWindowInfo.h"
#include <atlconv.h>
#include "../def/internalDef.h"
#include "InternalCalculationVisitor.h"
#include "InternalResponseFilter.h"
#include "InternalDOMDocument.h"
#include "InternalMessageRouterHandler.h"

#pragma comment(lib,"user32.lib")

namespace Local {
    CefRefPtr<InternalClient> shareInstance = nullptr;
    InternalMessageRouterHandler messageRouterHandler;
}

InternalClient::InternalClient(shrewd_ptr<ProxyClient> client):
	_proxyClient(client)
{
    CefMessageRouterConfig config;
    config.js_query_function = L"cefQuery";
    config.js_cancel_function = L"cefQueryCancel";
    _messageRouter = CefMessageRouterBrowserSide::Create(config);
    _messageRouter->AddHandler(&Local::messageRouterHandler, true);
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
            winInfo,
            browserSetting,
            nNoJavaScriptAccess);

        if (nNoJavaScriptAccess) *no_javascript_access = true;
        windowInfo.Set(*(CefWindowInfo*)winInfo->OriginPointer(), true);
        settings.Set(*(CefBrowserSettings*)browserSetting->OriginPointer(), true);
    
        _proxyClient->OnInternalOnBeforePopup(browser, (void**)&extra_info);
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
        result = _proxyClient->DoClose(new ProxyBrowser(browser));
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
    
    _messageRouter->OnBeforeClose(browser);
    
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

        if (message.length() > 0 && message.length() <= 200) {
            tempMessage = W2A(message.c_str());
        }
        else if(message.length() > 200) {
            tempMessage = ToAnsi(message.c_str(), message.length());
        }
        if (source.length() > 0) {
            tempSource = W2A(source.c_str());
        }
        result = _proxyClient->OnConsoleMessage(new ProxyBrowser(browser),
            (int)level, tempMessage, tempSource, line);

        if (message.length() > 200) {
            DeleteBuffer((void*)tempMessage); 
        }
    }
    return result;
}

bool InternalClient::OnAutoResize(CefRefPtr<CefBrowser> browser,
    const CefSize& new_size){
    bool result = false;
    return result;
}

void InternalClient::OnLoadingProgressChange(CefRefPtr<CefBrowser> browser,
    double progress){
    if (_proxyClient) {
        _proxyClient->OnLoadingProgressChange(new ProxyBrowser(browser), progress);
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

CefRefPtr<CefResourceRequestHandler> InternalClient::GetResourceRequestHandler(
     CefRefPtr<CefBrowser> browser,
     CefRefPtr<CefFrame> frame,
     CefRefPtr<CefRequest> request,
     bool is_navigation,
     bool is_download,
     const CefString& request_initiator,
     bool& disable_default_handling) {
    //bool result = false;
    //if (_proxyClient) {
    //    const char* strValue = NULL;
    //    USES_CONVERSION;
    //    if (!request_initiator.empty()) {
    //        strValue = W2A(request_initiator.c_str());
    //    }

    //    result = _proxyClient->GetResourceRequestHandler(
    //        new ProxyBrowser(browser),
    //        new ProxyFrame(frame),
    //        new ProxyRequest(request),
    //        is_navigation, is_download, strValue);


    //}
    //return result ? this : nullptr;
    return this;
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
    return false;
}

void InternalClient::OnPluginCrashed(CefRefPtr<CefBrowser> browser,
    const CefString& plugin_path) {

}

void InternalClient::OnRenderViewReady(CefRefPtr<CefBrowser> browser) {
}

bool InternalClient::OnBeforeBrowse(CefRefPtr<CefBrowser> browser,
    CefRefPtr<CefFrame> frame,
    CefRefPtr<CefRequest> request,
    bool user_gesture,
    bool is_redirect) {
    _messageRouter->OnBeforeBrowse(browser, frame);

    bool result = false;
    if (_proxyClient) {
        result = _proxyClient->OnBeforeBrowse(
            new ProxyBrowser(browser),
            new ProxyFrame(frame),
            new ProxyRequest(request),
            user_gesture,
            is_redirect
        );
    }
    return result;
}

void InternalClient::OnRenderProcessTerminated(CefRefPtr<CefBrowser> browser,
    TerminationStatus status) {
    _messageRouter->OnRenderProcessTerminated(browser);
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
            new ProxyRequest(request));

        if (result == RV_CANCEL || result == RV_CONTINUE) {
            result =(ReturnValue)(1 - result);
        }

        if (result != RV_CANCEL) {
            const wchar_t* useragent = _proxyClient->GetUserAgentOverride(browser);
            if (useragent != nullptr && lstrlenW(useragent) > 0) {
                request->SetHeaderByName(L"User-Agent", useragent, true);
            }
        }
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

        if (!new_url.empty()) {
            setUrl = ToAnsi(new_url.c_str(), new_url.length());
        }

        _proxyClient->OnResourceRedirect(
            new ProxyBrowser(browser),
            new ProxyFrame(frame),
            new ProxyRequest(request),
            new ProxyResponse( response ), setUrl);

        if (setUrl) {
            wchar_t* buffer = ToUnicode(setUrl, strlen(setUrl));
            CefString target = buffer;

            if (target != new_url) {
                new_url = target;
            }

            DeleteBuffer(setUrl);
            DeleteBuffer(buffer);
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
       //TCHAR text[2048];
       //CefString url = request->GetURL();

       //wsprintf(text, L"GetResourceResponseFilter %s", url.c_str());
       //OutputDebugString(text);


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

    //TCHAR text[260];
    //CefString url = request->GetURL();
    //OutputDebugString(url.c_str());
    //wsprintf(text, L"OnResourceLoadComplete /// status = %d, length = %I64d", status, received_content_length);
    //OutputDebugString(text);


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
 }

bool InternalClient::OnProcessMessageReceived(CefRefPtr<CefBrowser> browser,
    CefRefPtr<CefFrame> frame,
    CefProcessId source_process,
    CefRefPtr<CefProcessMessage> message) {
    CefString name = message->GetName();

    if (_messageRouter->OnProcessMessageReceived(browser, frame, source_process, message)) {
        return true;
    }

    if (name == L"IPC_V8_RESULT") {
        CefRefPtr<CefListValue> arguments = message->GetArgumentList();
        if (arguments->GetSize() < 3) {
            return false;
        }
        DispatchJsResult(browser, frame, arguments);
        return true;
    }
    else if (name == L"IPC_DOM_RESULT") {
        CefRefPtr<CefListValue> arguments = message->GetArgumentList();
        InternalDOMDocument::OnDomMessageReceived(frame, arguments);
        return true;
    }
    return false;
}

void InternalClient::DispatchJsResult(CefRefPtr<CefBrowser> browser,
    CefRefPtr<CefFrame> frame,
    CefRefPtr<CefListValue> arguments) {
    CefRefPtr<InternalCalculationVisitior> calculation = (InternalCalculationVisitior*)arguments->GetInt(0);
    CefRefPtr<CefValue> value = nullptr;
    if (calculation) { 
        if (arguments->GetBool(1)) {
            calculation->SetResult(arguments->GetValue(2));
        }
        else {
            value = CefValue::Create();
            value->SetString(arguments->GetString(2));
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

        shrewd_ptr<ProxyDownloadItem> download = new ProxyDownloadItem(download_item);
        download->SetBeforeDownloadCallback(callback);

        _proxyClient->OnBeforeDownload(
            new ProxyBrowser(browser),
            download,
            szSuggestedName);

        download->SetBeforeDownloadCallback(nullptr);
    }
}

void InternalClient::OnDownloadUpdated(CefRefPtr<CefBrowser> browser,
    CefRefPtr<CefDownloadItem> download_item,
    CefRefPtr<CefDownloadItemCallback> callback) {
    if (_proxyClient) {

        shrewd_ptr<ProxyDownloadItem> download = new ProxyDownloadItem(download_item);
        download->SetDownloadCallback(callback);

        _proxyClient->OnDownloadUpdated(
            new ProxyBrowser(browser),
            download);

        download->SetDownloadCallback(nullptr);
    }
}

void InternalClient::OnBeforeContextMenu(CefRefPtr<CefBrowser> browser,
    CefRefPtr<CefFrame> frame,
    CefRefPtr<CefContextMenuParams> params,
    CefRefPtr<CefMenuModel> model) {
    if (_proxyClient) {
        _proxyClient->OnBeforeContextMenu(
            new ProxyBrowser(browser),
            new ProxyFrame(frame),
            new ProxyContextMenuParams(params),
            new ProxyMenuModel(model)
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
            command_id,event_flags);
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

void InternalClient::OnFullscreenModeChange(CefRefPtr<CefBrowser> browser,
    bool fullscreen) {
    if (_proxyClient) {
        _proxyClient->OnFullscreenModeChange(new ProxyBrowser(browser), fullscreen);
    }
}