#pragma once
#include "../def/def.h"
#include "ProxyCommandLine.h"
#include "ProxyBrowser.h"
#include "ProxyRequest.h"
#include "ProxyFrame.h"
#include "ProxyWindowInfo.h"
#include "ProxyBrowserSettings.h"
#include "ProxyBrowserHost.h"
#include "ProxyCookie.h"
#include "ProxyJSDialogCallback.h"
#include "ProxyAuthCallback.h"
#include "ProxyRequestCallback.h"
#include "ProxyResponse.h"
#include "ProxyDictionaryValue.h"
#include "ProxyFileDialogCallback.h"
#include "ProxyContextMenuParams.h"
#include "ProxyMenuModel.h"
#include "ProxyRunContextMenuCallback.h"
#include "ProxyDownloadItem.h"
#include "ProxyDownloadItemCallback.h"
#include "ProxyBeforeDownloadCallback.h"
#include "ProxyPopupFeatures.h"
#include "ProxyResponseFilter.h"
#include "ProxyListValue.h"

#if _MSC_VER > 1200
#define EPL_EVENT /*override*/
#else
#define EPL_EVENT
#endif

#define INTERNAL_DEFINITION(ClassName) \
public: \
	void \
		OnSizeChanged(unsigned int parentWindow,int cx, int cy);


class AQUADLL ProxyClient : public refcounted {
public:
	ProxyClient();
	~ProxyClient();

public:
	virtual void OnBeforeCommandLineProcessing(
		shrewd_ptr<ProxyCommandLine> command_line) EPL_EVENT { return; }

	virtual void OnContextInitialized() EPL_EVENT { return; }

public:
	virtual bool OnBeforePopup(
		shrewd_ptr<ProxyBrowser> browser,
		shrewd_ptr<ProxyFrame> frame,
		const char* target_uri,
		const char* target_frame_name,
		int target_disposition,
		bool user_gesture,
		shrewd_ptr<ProxyPopupFeatures> popupFeatures,
		shrewd_ptr<ProxyWindowInfo> window_info,
		shrewd_ptr<ProxyBrowserSettings> settings,
		shrewd_ptr<ProxyDictionaryValue> extra_info,
		int& no_javascript_access
	) EPL_EVENT { return false;}

	virtual void OnAfterCreated(shrewd_ptr<ProxyBrowser> browser) EPL_EVENT;

	virtual void OnBeforeClose(shrewd_ptr<ProxyBrowser> browser) EPL_EVENT;

	virtual bool DoClose(shrewd_ptr<ProxyBrowser> browser) EPL_EVENT { return false; }

public:
	virtual void OnLoadingStateChange(shrewd_ptr<ProxyBrowser> browser,
		bool isLoading,
		bool canGoBack,
		bool canGoForward) EPL_EVENT { return;}

	virtual void OnLoadStart(shrewd_ptr<ProxyBrowser> browser,
		shrewd_ptr<ProxyFrame> frame,
		int transition_type) EPL_EVENT { return;}

	virtual void OnLoadEnd(shrewd_ptr<ProxyBrowser> browser,
		shrewd_ptr<ProxyFrame> frame,
		int httpStatusCode) EPL_EVENT { return;}

	virtual void OnLoadError(shrewd_ptr<ProxyBrowser> browser,
		shrewd_ptr<ProxyFrame> frame,
		int errorCode,
		const char* errorText,
		const char* failedUrl) EPL_EVENT { return;}

public:
	virtual void OnAddressChange(shrewd_ptr<ProxyBrowser> browser,
		shrewd_ptr<ProxyFrame> frame,
		const char* url) EPL_EVENT { return;}

	virtual void OnTitleChange(shrewd_ptr<ProxyBrowser> browser,
		const char* title) EPL_EVENT { return;}

	virtual void OnFaviconURLChange(shrewd_ptr<ProxyBrowser> browser,
		char* icon_urls) EPL_EVENT { return;}

	virtual void OnFullscreenModeChange(shrewd_ptr<ProxyBrowser> browser,
		bool fullscreen) EPL_EVENT { return;}

	virtual bool OnTooltip(shrewd_ptr<ProxyBrowser> browser, const char* text) EPL_EVENT { return false; }

	virtual void OnStatusMessage(shrewd_ptr<ProxyBrowser> browser,
		const char* value) EPL_EVENT { return;}

	virtual bool OnConsoleMessage(shrewd_ptr<ProxyBrowser> browser,
		int level,
		const char* message,
		const char* source,
		int line) EPL_EVENT { return false;}

	virtual bool OnAutoResize(shrewd_ptr<ProxyBrowser> browser,
		int width, int height) EPL_EVENT { return false;}

	virtual void OnLoadingProgressChange(shrewd_ptr<ProxyBrowser> browser,
		double progress) EPL_EVENT { return;}

public:
	virtual void OnTakeFocus(shrewd_ptr<ProxyBrowser> browser, bool next) EPL_EVENT { return; }

	virtual bool OnSetFocus(shrewd_ptr<ProxyBrowser> browser, int source) EPL_EVENT { return false; }

	virtual void OnGotFocus(shrewd_ptr<ProxyBrowser> browser) EPL_EVENT { return ; }
public:
	virtual bool OnJSDialog(shrewd_ptr<ProxyBrowser> browser,
		const char* origin_url,
		int dialog_type,
		const char* message_text,
		const char* default_prompt_text,
		shrewd_ptr<ProxyJSDialogCallback> callback,
		int& suppress_message) EPL_EVENT { return false;}

	virtual bool OnBeforeUnloadDialog(shrewd_ptr<ProxyBrowser> browser,
		const char* message_text,
		bool is_reload,
		shrewd_ptr<ProxyJSDialogCallback> callback) EPL_EVENT { return false; }

	virtual void OnResetDialogState(shrewd_ptr<ProxyBrowser> browser) EPL_EVENT { return; }

	virtual void OnDialogClosed(shrewd_ptr<ProxyBrowser> browser) EPL_EVENT { return; }

public:
	virtual bool OnBeforeBrowse(shrewd_ptr<ProxyBrowser> browser,
		shrewd_ptr<ProxyFrame> frame,
		shrewd_ptr<ProxyRequest> request,
		bool user_gesture,
		bool is_redirect) EPL_EVENT { return false; }

	virtual bool OnOpenURLFromTab(shrewd_ptr<ProxyBrowser> browser,
		shrewd_ptr<ProxyFrame> frame,
		const char* target_url,
		int target_disposition,
		bool user_gesture) EPL_EVENT { return false; }

	virtual bool GetResourceRequestHandler(
		shrewd_ptr<ProxyBrowser> browser,
		shrewd_ptr<ProxyFrame> frame,
		shrewd_ptr<ProxyRequest> request,
		bool is_navigation,
		bool is_download,
		const char* request_initiator) EPL_EVENT { return false; }

	virtual bool GetAuthCredentials(shrewd_ptr<ProxyBrowser> browser,
		const char* origin_url,
		bool isProxy,
		const char* host,
		int port,
		const char* realm,
		const char* scheme,
		shrewd_ptr<ProxyAuthCallback> callback) EPL_EVENT { return false; }

	virtual bool OnQuotaRequest(shrewd_ptr<ProxyBrowser> browser,
		const char* origin_url,
		__int64 new_size,
		shrewd_ptr<ProxyRequestCallback> callback) EPL_EVENT { return false; }

	virtual void OnPluginCrashed(shrewd_ptr<ProxyBrowser> browser,
		const char* plugin_path) EPL_EVENT { return; }

	virtual void OnRenderViewReady(shrewd_ptr<ProxyBrowser> browser) EPL_EVENT { return; }

	virtual void OnRenderProcessTerminated(shrewd_ptr<ProxyBrowser> browser,
		int status) EPL_EVENT { return; }

public:
	virtual int OnBeforeResourceLoad(
		shrewd_ptr<ProxyBrowser> browser,
		shrewd_ptr<ProxyFrame> frame,
		shrewd_ptr<ProxyRequest> request,
		shrewd_ptr<ProxyRequestCallback> callback
		) EPL_EVENT { return 1; }

	virtual void OnResourceRedirect(shrewd_ptr<ProxyBrowser> browser,
		shrewd_ptr<ProxyFrame> frame,
		shrewd_ptr<ProxyRequest> request,
		shrewd_ptr<ProxyResponse> response,
		char*& new_url) EPL_EVENT { return; }

	virtual bool OnResourceResponse(shrewd_ptr<ProxyBrowser> browser,
		shrewd_ptr<ProxyFrame> frame,
		shrewd_ptr<ProxyRequest> request,
		shrewd_ptr<ProxyResponse> response) EPL_EVENT { return false; }

	virtual bool OnResourceResponseFilter(
		shrewd_ptr<ProxyBrowser> browser,
		shrewd_ptr<ProxyFrame> frame,
		shrewd_ptr<ProxyRequest> request,
		shrewd_ptr<ProxyResponse> response)  EPL_EVENT { return false; }

	virtual void OnResourceLoadComplete(shrewd_ptr<ProxyBrowser> browser,
		shrewd_ptr<ProxyFrame> frame,
		shrewd_ptr<ProxyRequest> request,
		shrewd_ptr<ProxyResponse> response,
		int status,
		__int64 received_content_length) EPL_EVENT { return; }

	virtual void OnProtocolExecution(shrewd_ptr<ProxyBrowser> browser,
		shrewd_ptr<ProxyFrame> frame,
		shrewd_ptr<ProxyRequest> request,
		int& allow_os_execution) EPL_EVENT { return; }

public:
	virtual bool OnFileDialog(shrewd_ptr<ProxyBrowser> browser,
		int mode,
		const char* title,
		const char* default_file_path,
		const char* accept_filters,
		int selected_accept_filter,
		shrewd_ptr<ProxyFileDialogCallback> callback) EPL_EVENT { return false; }

public:
	virtual void OnBeforeContextMenu(shrewd_ptr<ProxyBrowser> browser,
		shrewd_ptr<ProxyFrame> frame,
		shrewd_ptr<ProxyContextMenuParams> params,
		shrewd_ptr<ProxyMenuModel> model) EPL_EVENT { return ; }

	virtual bool RunContextMenu(shrewd_ptr<ProxyBrowser> browser,
		shrewd_ptr<ProxyFrame> frame,
		shrewd_ptr<ProxyContextMenuParams> params,
		shrewd_ptr<ProxyMenuModel> model,
		shrewd_ptr<ProxyRunContextMenuCallback> callback) EPL_EVENT { return false; }

	virtual bool OnContextMenuCommand(shrewd_ptr<ProxyBrowser> browser,
		shrewd_ptr<ProxyFrame> frame,
		shrewd_ptr<ProxyContextMenuParams> params,
		int command_id,
		int event_flags) EPL_EVENT { return false; }

	virtual void OnContextMenuDismissed(shrewd_ptr<ProxyBrowser> browser,
		shrewd_ptr<ProxyFrame> frame) EPL_EVENT { return ; }

public:
	virtual void OnBeforeDownload(
		shrewd_ptr<ProxyBrowser> browser,
		shrewd_ptr<ProxyDownloadItem> download_item,
		const char* suggested_name,
		shrewd_ptr<ProxyBeforeDownloadCallback> callback) EPL_EVENT { return ; }

	virtual void OnDownloadUpdated(shrewd_ptr<ProxyBrowser> browser,
		shrewd_ptr<ProxyDownloadItem> download_item,
		shrewd_ptr<ProxyDownloadItemCallback> callback) EPL_EVENT { return ; }

public:
	virtual bool OnCookieVisitor(shrewd_ptr<ProxyCookie> cookie, int count, int total) EPL_EVENT { return false; }
	
	virtual void OnTaskVisitor(int taskid, int threadid, shrewd_ptr<ProxyValue> params)  EPL_EVENT { return ; }

	virtual void OnRenderProcessThreadCreated(shrewd_ptr<ProxyListValue> extra_info) EPL_EVENT { return; }

	virtual void OnResourceFilter(shrewd_ptr<ProxyBrowser> browser, shrewd_ptr<ProxyResponseFilter> filter) EPL_EVENT { return; }

public:
	INTERNAL_DEFINITION(ProxyClient);

public:
	/*--cef()--*/
	bool CreateBrowser(
		shrewd_ptr<ProxyWindowInfo> winInfo,
		const char* url,
		shrewd_ptr<ProxyBrowserSettings> settings,
		shrewd_ptr<ProxyRequestContext> request_context
	);

	/*--cef()--*/
	void CloseBrowser(shrewd_ptr<ProxyBrowser> browser, bool force_close);

	/*--cef()--*/
	void SetForeground(unsigned int parent_window, shrewd_ptr<ProxyBrowser> browser);

	/*--cef()--*/
	int GetBrowserCount();

	/*--cef()--*/
	shrewd_ptr<ProxyBrowser> GetBrowserWithIndex(int index);

	/*--cef()--*/
	shrewd_ptr<ProxyBrowser> GetBrowserWithHandle(unsigned int handle);

	
private:
	void* _rawptr;
};