#pragma once
#include "../def/def.h"
#include "ProxyCommandLine.h"
#include "ProxyBrowser.h"
#include "ProxyRequest.h"
#include "ProxyFrame.h"
#include "ProxyBrowserSettings.h"
#include "ProxyCookie.h"
#include "ProxyJSDialogCallback.h"
#include "ProxyAuthCallback.h"
#include "ProxyResponse.h"
#include "ProxyDictionaryValue.h"
#include "ProxyFileDialogCallback.h"
#include "ProxyDownloadItem.h"
#include "ProxyResponseFilter.h"
#include "ProxyListValue.h"
#include "ProxyWindowInfo.h"
#include "ProxyServer.h"
#include "ProxyWebSocket.h"
#include "ProxyWaitableEvent.h"
#include "ProxyMenuModel.h"
#include "ProxyContextMenuParams.h"
#include "ProxyRunContextMenuCallback.h"
#include "ProxyExtension.h"
#include "ProxyGetExtensionResourceCallback.h"
#include "ProxyActiveBrowserCallback.h"
#include "ProxyQueryCallback.h"

#if _MSC_VER > 1200
#define EPL_EVENT /*override*/
#else
#define EPL_EVENT
#endif

#define INTERNAL_DEFINITION(ClassName) \
public: \
	void \
		OnSizeChanged(unsigned int parentWindow,int cx, int cy); \
	int \
		GetSameBrowserCount(void* context); \
	shrewd_ptr<ProxyBrowser>** \
		GetSameBrowser(void* context); \
	shrewd_ptr<ProxyBrowser> \
		GetSameBrowserWithIndex(void* context, int index); \
	void \
		CloseSameBrowser(void* context); \
	void \
		SetUserAgentOverride(shrewd_ptr<ProxyBrowser> browser,const wchar_t* useragent, const wchar_t* appversion); \
	const wchar_t* \
		GetUserAgentOverride(void* browser); \
	void \
		SetScriptOnNewDocument(shrewd_ptr<ProxyBrowser> browser,const wchar_t* script); \
	void \
		OnInternalOnBeforePopup(void* browser,void** extra_info); \
	shrewd_ptr<ProxyListValue> \
		GetUsetData(shrewd_ptr<ProxyBrowser> browser); 


class AQUADLL ProxyClient : public refcounted {
public:
	ProxyClient();
	~ProxyClient();

public:
	virtual void OnBeforeCommandLineProcessing(
		const char* process_type,
		shrewd_ptr<ProxyCommandLine> command_line) EPL_EVENT { return; }

	virtual void OnContextInitialized() EPL_EVENT { return; }

	virtual void OnBeforeChildProcessLaunch(shrewd_ptr<ProxyCommandLine> command_line) EPL_EVENT { return; }

	virtual void OnRenderProcessThreadCreated(shrewd_ptr<ProxyListValue> extra_info) EPL_EVENT;

public:
	virtual bool OnBeforePopup(
		shrewd_ptr<ProxyBrowser> browser,
		shrewd_ptr<ProxyFrame> frame,
		const char* target_uri,
		const char* target_frame_name,
		int target_disposition,
		bool user_gesture,
		shrewd_ptr<ProxyWindowInfo> window_info,
		shrewd_ptr<ProxyBrowserSettings> settings,
		int& no_javascript_access
	) EPL_EVENT { return false; }

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
	virtual void OnBeforeContextMenu(shrewd_ptr<ProxyBrowser> browser,
		shrewd_ptr<ProxyFrame> frame,
		shrewd_ptr<ProxyContextMenuParams> params,
		shrewd_ptr<ProxyMenuModel> model) EPL_EVENT { return;}

	virtual bool RunContextMenu(shrewd_ptr<ProxyBrowser> browser,
		shrewd_ptr<ProxyFrame> frame,
		shrewd_ptr<ProxyContextMenuParams> params,
		shrewd_ptr<ProxyMenuModel> model,
		shrewd_ptr<ProxyRunContextMenuCallback> callback) EPL_EVENT { return false;}

	virtual bool OnContextMenuCommand(shrewd_ptr<ProxyBrowser> browser,
		shrewd_ptr<ProxyFrame> frame,
		shrewd_ptr<ProxyContextMenuParams> params,
		int command_id,
		int event_flags) EPL_EVENT { return false;}

	virtual void OnContextMenuDismissed(shrewd_ptr<ProxyBrowser> browser,
		shrewd_ptr<ProxyFrame> frame) EPL_EVENT { return;}

public:
	virtual void OnAddressChange(shrewd_ptr<ProxyBrowser> browser,
		shrewd_ptr<ProxyFrame> frame,
		const char* url) EPL_EVENT { return;}

	virtual void OnTitleChange(shrewd_ptr<ProxyBrowser> browser,
		const char* title) EPL_EVENT { return;}

	virtual bool OnTooltip(shrewd_ptr<ProxyBrowser> browser, const char* text) EPL_EVENT { return false; }

	virtual void OnStatusMessage(shrewd_ptr<ProxyBrowser> browser,
		const char* value) EPL_EVENT { return;}

	virtual bool OnConsoleMessage(shrewd_ptr<ProxyBrowser> browser,
		int level,
		const char* message,
		const char* source,
		int line) EPL_EVENT { return false;}

	virtual void OnLoadingProgressChange(shrewd_ptr<ProxyBrowser> browser,
		double progress) EPL_EVENT { return;}

	virtual void OnFullscreenModeChange(shrewd_ptr<ProxyBrowser> browser, bool fullscreen) EPL_EVENT { return; }

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
	virtual bool GetAuthCredentials(shrewd_ptr<ProxyBrowser> browser,
		const char* origin_url,
		bool isProxy,
		const char* host,
		int port,
		const char* realm,
		const char* scheme,
		shrewd_ptr<ProxyAuthCallback> callback) EPL_EVENT { return false; }

public:
	virtual bool OnBeforeBrowse(shrewd_ptr<ProxyBrowser> browser,
		shrewd_ptr<ProxyFrame> frame,
		shrewd_ptr<ProxyRequest> request,
		bool user_gesture,
		bool is_redirect) EPL_EVENT { return false; }

	virtual int OnBeforeResourceLoad(
		shrewd_ptr<ProxyBrowser> browser,
		shrewd_ptr<ProxyFrame> frame,
		shrewd_ptr<ProxyRequest> request
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

public:
	virtual bool OnFileDialog(shrewd_ptr<ProxyBrowser> browser,
		int mode,
		const char* title,
		const char* default_file_path,
		const char* accept_filters,
		int selected_accept_filter,
		shrewd_ptr<ProxyFileDialogCallback> callback) EPL_EVENT { return false; }

public:
	virtual void OnBeforeDownload(
		shrewd_ptr<ProxyBrowser> browser,
		shrewd_ptr<ProxyDownloadItem> download_item,
		const char* suggested_name) EPL_EVENT { return ; }

	virtual void OnDownloadUpdated(shrewd_ptr<ProxyBrowser> browser,
		shrewd_ptr<ProxyDownloadItem> download_item) EPL_EVENT { return ; }

public:
	virtual void OnResourceFilter(shrewd_ptr<ProxyBrowser> browser, shrewd_ptr<ProxyResponseFilter> filter) EPL_EVENT { return; }

public:
	virtual void OnServerCreated(shrewd_ptr<ProxyServer> server) EPL_EVENT { return; }

	virtual void OnServerDestroyed(shrewd_ptr<ProxyServer> server) EPL_EVENT { return; }

	virtual void OnClientConnected(shrewd_ptr<ProxyServer> server,
		int connection_id) EPL_EVENT { return ; }

	virtual void OnClientDisconnected(shrewd_ptr<ProxyServer> server,
		int connection_id) EPL_EVENT { return ; }

	virtual void OnHttpRequest(shrewd_ptr<ProxyServer> server,
		int connection_id,
		const char* client_address,
		shrewd_ptr<ProxyRequest> request) EPL_EVENT { return ; }

	virtual bool OnWebSocketRequest(shrewd_ptr<ProxyServer> server,
		int connection_id,
		const char* client_address,
		shrewd_ptr<ProxyRequest> request) EPL_EVENT { return false; }

	virtual void OnWebSocketConnected(shrewd_ptr<ProxyServer> server,
		int connection_id) EPL_EVENT { return ; }

	virtual void OnWebSocketMessage(shrewd_ptr<ProxyServer> server,
		int connection_id,
		const unsigned char* data,
		int data_size) EPL_EVENT { return ; }

public:
	virtual void OnWebSocketClientConnected(shrewd_ptr<ProxyWebSocket> websocket) EPL_EVENT { return; }

	virtual void OnWebSocketClientClosed(shrewd_ptr<ProxyWebSocket> websocket) EPL_EVENT { return; }

	virtual void OnWebSocketClientMessage(shrewd_ptr<ProxyWebSocket> websocket, int type, const unsigned char* message) EPL_EVENT { return; }

	virtual void OnWebSocketClientError(shrewd_ptr<ProxyWebSocket> websocket, const char* error) EPL_EVENT { return; }

public:
	virtual void OnExtensionLoadFailed(int result) EPL_EVENT {}

	virtual void OnExtensionLoaded(shrewd_ptr<ProxyExtension> extension) EPL_EVENT {}

	virtual void OnExtensionUnloaded(shrewd_ptr<ProxyExtension> extension) EPL_EVENT {}

	virtual bool OnBeforeBackgroundBrowser(shrewd_ptr<ProxyExtension> extension, const char* url) EPL_EVENT { return false;}

	virtual bool OnBeforeBrowser(shrewd_ptr<ProxyExtension> extension,
		shrewd_ptr<ProxyBrowser> browser,
		shrewd_ptr<ProxyBrowser> active_browser,
		int index,
		const char* url,
		bool active,
		shrewd_ptr<ProxyWindowInfo>& windowInfo) EPL_EVENT { return false;}

	virtual bool CanAccessBrowser(shrewd_ptr<ProxyExtension> extension,
		shrewd_ptr<ProxyBrowser> browser,
		bool include_incognito,
		shrewd_ptr<ProxyBrowser> target_browser) EPL_EVENT { return false;}

	virtual void GetActiveBrowser(
		shrewd_ptr<ProxyExtension> extension,
		shrewd_ptr<ProxyBrowser> browser,
		bool include_incognito,
		shrewd_ptr<ProxyActiveBrowserCallback> callback) EPL_EVENT { return ; }

	virtual bool GetExtensionResource(
		shrewd_ptr<ProxyExtension> extension,
		shrewd_ptr<ProxyBrowser> browser,
		const char* file,
		shrewd_ptr<ProxyGetExtensionResourceCallback> callback) EPL_EVENT { return false; }

public:
	virtual bool OnQuery(shrewd_ptr<ProxyBrowser> browser,
		shrewd_ptr<ProxyFrame> frame,
		__int64 query_id,
		const char* request,
		bool persistent,
		shrewd_ptr<ProxyQueryCallback> callback) EPL_EVENT { return false; }

	virtual void OnQueryCanceled(shrewd_ptr<ProxyBrowser> browser,
		shrewd_ptr<ProxyFrame> frame,
		__int64 query_id) EPL_EVENT { return ; }


public:
	INTERNAL_DEFINITION(ProxyClient);

public:
	/*--cef()--*/
	bool CreateBrowser(
		shrewd_ptr<ProxyWindowInfo> winInfo,
		const char* url,
		shrewd_ptr<ProxyBrowserSettings> settings, bool incognito_mode);

	/*--cef()--*/
	void CloseBrowser(shrewd_ptr<ProxyBrowser> browser, bool force_close);

	/*--cef()--*/
	void SetForeground(unsigned int parent_window, shrewd_ptr<ProxyBrowser> browser);

	/*--cef()--*/
	int GetBrowserCount();

	/*--cef()--*/
	shrewd_ptr<ProxyBrowser> GetBrowserWithHandle(unsigned int handle);

	/*--cef()--*/
	shrewd_ptr<ProxyBrowser> GetBrowserWithIndex(unsigned int index);

	///
	// 获取索引
	///
	int GetIndex(shrewd_ptr<ProxyBrowser> browser);

	///
	// 取同源浏览器
	///
	shrewd_ptr<ProxyBrowser>** GetSameOriginBrowser(shrewd_ptr<ProxyBrowser> browser);

private:
	void* _rawptr;
};