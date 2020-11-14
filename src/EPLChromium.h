#pragma once
#include "stdafx.h"
#include <windows.h>
#include <proxy/ProxyClient.h>
#include "lib2.h"
#include "resource.h"


#define DATA_TYPE_AQUARIUS_UNIT \
	{ \
		/*m_szName*/			_WT("水星铬浏览框"), \
		/*m_szEgName*/			_WT("Chromium"), \
		/*m_szExplain*/			_WT("提供浏览器对象的生命周期管理以及事件派发支持。"), \
		/*m_nCmdCount*/			sizeof(s_nChromiumElementCmdIndex) / sizeof(s_nChromiumElementCmdIndex[0]), \
		/*m_pnCmdsIndex*/ 		s_nChromiumElementCmdIndex, \
		/*m_dwState*/			_DT_OS (__OS_WIN) | LDT_WIN_UNIT, \
		/*m_dwUnitBmpID*/		IDB_AQUARIUS_CHROMIUM_BITMAP, \
		/*m_nEventCount*/		sizeof(s_ChromiumEvent) / sizeof(s_ChromiumEvent[0]), \
		/*m_pEventBegin*/		s_ChromiumEvent, \
		/*m_nPropertyCount*/	sizeof(s_ChromiumProperty) / sizeof(s_ChromiumProperty[0]), \
		/*m_pPropertyBegin*/	s_ChromiumProperty, \
		/*m_pfnGetInterface*/	EDITIONF(GetInterface_Chromium), \
		/*m_nElementCount*/		0, \
		/*m_pElementBegin*/		NULL \
	}, \


///////////////////////////////////////////////////////////////////////////

#include "untshare.h"
class AquariusProperty : public CPropertyInfo{

public:
	AquariusProperty():nBorderStyle(0){}
	~AquariusProperty(){}

public:
	int nBorderStyle;

public:
	virtual void init(void);
	virtual BOOL Serialize(CArchive& ar);
};


#define AQUARIUS_UNIT_VER (1)


extern"C"
PFN_INTERFACE WINAPI EDITIONF(GetInterface_Chromium)(INT nInterfaceNO);
HUNIT WINAPI EDITIONF(Create_Chromium)(LPBYTE pAllData, INT nAllDataSize,
	DWORD dwStyle, HWND hParentWnd, UINT uID, HMENU hMenu, INT x, INT y, INT cx, INT cy,
	DWORD dwWinFormID, DWORD dwUnitID, HWND hDesignWnd = 0, BOOL blInDesignMode = FALSE);
BOOL WINAPI EDITIONF(NotifyPropertyChanged_Chromium) (HUNIT hUnit, INT nPropertyIndex,
	PUNIT_PROPERTY_VALUE pPropertyVaule, LPCTSTR* ppszTipText);
BOOL WINAPI EDITIONF(GetPropertyData_Chromium) (HUNIT hUnit, INT nPropertyIndex,
PUNIT_PROPERTY_VALUE pPropertyVaule_Chromium);
HGLOBAL WINAPI EDITIONF(GetAllPropertyData_Chromium) (HUNIT hUnit);


class AquariusUnit : public CWnd, public ProxyClient {
public:
	AquariusUnit();
	~AquariusUnit();

public:
	AquariusProperty propertices;
	DWORD dwWinFormID;
	DWORD dwUnitID;
	BOOL inDesignMode;
	BOOL isDestory;

public:
	BOOL Create(HWND hParentWnd, DWORD dwStyle, UINT uID, INT x, INT y, INT cx, INT cy);

public:
	void SetBorder(int nType);

public:
	PRIME_IMPLEMENT_REFCOUNTING(AquariusUnit);

protected:
	virtual void PostNcDestroy(void);
public:
	afx_msg void OnSetFocus(CWnd* pOldWnd);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnDestroy();
	DECLARE_MESSAGE_MAP();
};


class EPLClient : public ProxyClient {
public:
	EPLClient();
	~EPLClient();

public:
	static shrewd_ptr<EPLClient> GetInstance();

public:
		virtual void OnBeforeCommandLineProcessing(
		const char* process_type,
		shrewd_ptr<ProxyCommandLine> command_line);
	virtual void OnContextInitialized();
	virtual void OnBeforeChildProcessLaunch(shrewd_ptr<ProxyCommandLine> command_line);
	virtual void OnRenderProcessThreadCreated(shrewd_ptr<ProxyListValue> extra_info);
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
	);
	virtual void OnAfterCreated(shrewd_ptr<ProxyBrowser> browser);
	virtual void OnBeforeClose(shrewd_ptr<ProxyBrowser> browser);
	virtual bool DoClose(shrewd_ptr<ProxyBrowser> browser);
	virtual void OnLoadingStateChange(shrewd_ptr<ProxyBrowser> browser,
		bool isLoading,
		bool canGoBack,
		bool canGoForward);
	virtual void OnLoadStart(shrewd_ptr<ProxyBrowser> browser,
		shrewd_ptr<ProxyFrame> frame,
		int transition_type);
	virtual void OnLoadEnd(shrewd_ptr<ProxyBrowser> browser,
		shrewd_ptr<ProxyFrame> frame,
		int httpStatusCode);
	virtual void OnLoadError(shrewd_ptr<ProxyBrowser> browser,
		shrewd_ptr<ProxyFrame> frame,
		int errorCode,
		const char* errorText,
		const char* failedUrl);
	virtual void OnBeforeContextMenu(shrewd_ptr<ProxyBrowser> browser,
		shrewd_ptr<ProxyFrame> frame,
		shrewd_ptr<ProxyContextMenuParams> params,
		shrewd_ptr<ProxyMenuModel> model);
	virtual bool RunContextMenu(shrewd_ptr<ProxyBrowser> browser,
		shrewd_ptr<ProxyFrame> frame,
		shrewd_ptr<ProxyContextMenuParams> params,
		shrewd_ptr<ProxyMenuModel> model,
		shrewd_ptr<ProxyRunContextMenuCallback> callback);
	virtual bool OnContextMenuCommand(shrewd_ptr<ProxyBrowser> browser,
		shrewd_ptr<ProxyFrame> frame,
		shrewd_ptr<ProxyContextMenuParams> params,
		int command_id,
		int event_flags);
	virtual void OnContextMenuDismissed(shrewd_ptr<ProxyBrowser> browser,
		shrewd_ptr<ProxyFrame> frame);
	virtual void OnAddressChange(shrewd_ptr<ProxyBrowser> browser,
		shrewd_ptr<ProxyFrame> frame,
		const char* url);
	virtual void OnTitleChange(shrewd_ptr<ProxyBrowser> browser,
		const char* title);
	virtual bool OnTooltip(shrewd_ptr<ProxyBrowser> browser, const char* text);
	virtual void OnStatusMessage(shrewd_ptr<ProxyBrowser> browser,
		const char* value);
	virtual bool OnConsoleMessage(shrewd_ptr<ProxyBrowser> browser,
		int level,
		const char* message,
		const char* source,
		int line);
	virtual void OnLoadingProgressChange(shrewd_ptr<ProxyBrowser> browser,
		double progress);
	virtual void OnFullscreenModeChange(shrewd_ptr<ProxyBrowser> browser, bool fullscreen);
	virtual bool OnJSDialog(shrewd_ptr<ProxyBrowser> browser,
		const char* origin_url,
		int dialog_type,
		const char* message_text,
		const char* default_prompt_text,
		shrewd_ptr<ProxyJSDialogCallback> callback,
		int& suppress_message);
	virtual bool OnBeforeUnloadDialog(shrewd_ptr<ProxyBrowser> browser,
		const char* message_text,
		bool is_reload,
		shrewd_ptr<ProxyJSDialogCallback> callback);
	virtual void OnResetDialogState(shrewd_ptr<ProxyBrowser> browser);
	virtual void OnDialogClosed(shrewd_ptr<ProxyBrowser> browser);
	virtual bool GetAuthCredentials(shrewd_ptr<ProxyBrowser> browser,
		const char* origin_url,
		bool isProxy,
		const char* host,
		int port,
		const char* realm,
		const char* scheme,
		shrewd_ptr<ProxyAuthCallback> callback);
	virtual bool OnBeforeBrowse(shrewd_ptr<ProxyBrowser> browser,
		shrewd_ptr<ProxyFrame> frame,
		shrewd_ptr<ProxyRequest> request,
		bool user_gesture,
		bool is_redirect);
	virtual int OnBeforeResourceLoad(
		shrewd_ptr<ProxyBrowser> browser,
		shrewd_ptr<ProxyFrame> frame,
		shrewd_ptr<ProxyRequest> request
		);
	virtual void OnResourceRedirect(shrewd_ptr<ProxyBrowser> browser,
		shrewd_ptr<ProxyFrame> frame,
		shrewd_ptr<ProxyRequest> request,
		shrewd_ptr<ProxyResponse> response,
		char*& new_url);
	virtual bool OnResourceResponse(shrewd_ptr<ProxyBrowser> browser,
		shrewd_ptr<ProxyFrame> frame,
		shrewd_ptr<ProxyRequest> request,
		shrewd_ptr<ProxyResponse> response);
	virtual bool OnResourceResponseFilter(
		shrewd_ptr<ProxyBrowser> browser,
		shrewd_ptr<ProxyFrame> frame,
		shrewd_ptr<ProxyRequest> request,
		shrewd_ptr<ProxyResponse> response);
	virtual void OnResourceLoadComplete(shrewd_ptr<ProxyBrowser> browser,
		shrewd_ptr<ProxyFrame> frame,
		shrewd_ptr<ProxyRequest> request,
		shrewd_ptr<ProxyResponse> response,
		int status,
		__int64 received_content_length);
	virtual bool OnFileDialog(shrewd_ptr<ProxyBrowser> browser,
		int mode,
		const char* title,
		const char* default_file_path,
		const char* accept_filters,
		int selected_accept_filter,
		shrewd_ptr<ProxyFileDialogCallback> callback);
	virtual void OnBeforeDownload(
		shrewd_ptr<ProxyBrowser> browser,
		shrewd_ptr<ProxyDownloadItem> download_item,
		const char* suggested_name);
	virtual void OnDownloadUpdated(shrewd_ptr<ProxyBrowser> browser,
		shrewd_ptr<ProxyDownloadItem> download_item);
	virtual void OnResourceFilter(shrewd_ptr<ProxyBrowser> browser, shrewd_ptr<ProxyResponseFilter> filter);
	virtual void OnServerCreated(shrewd_ptr<ProxyServer> server);
	virtual void OnServerDestroyed(shrewd_ptr<ProxyServer> server);
	virtual void OnClientConnected(shrewd_ptr<ProxyServer> server,
		int connection_id);
	virtual void OnClientDisconnected(shrewd_ptr<ProxyServer> server,
		int connection_id);
	virtual void OnHttpRequest(shrewd_ptr<ProxyServer> server,
		int connection_id,
		const char* client_address,
		shrewd_ptr<ProxyRequest> request);
	virtual bool OnWebSocketRequest(shrewd_ptr<ProxyServer> server,
		int connection_id,
		const char* client_address,
		shrewd_ptr<ProxyRequest> request);
	virtual void OnWebSocketConnected(shrewd_ptr<ProxyServer> server,
		int connection_id);
	virtual void OnWebSocketMessage(shrewd_ptr<ProxyServer> server,
		int connection_id,
		const unsigned char* data,
		int data_size);
	virtual void OnWebSocketClientConnected(shrewd_ptr<ProxyWebSocket> websocket);
	virtual void OnWebSocketClientClosed(shrewd_ptr<ProxyWebSocket> websocket);
	virtual void OnWebSocketClientMessage(shrewd_ptr<ProxyWebSocket> websocket, int type, const unsigned char* message);
	virtual void OnWebSocketClientError(shrewd_ptr<ProxyWebSocket> websocket, const char* error);
	virtual void OnExtensionLoadFailed(int result);
	virtual void OnExtensionLoaded(shrewd_ptr<ProxyExtension> extension);
	virtual void OnExtensionUnloaded(shrewd_ptr<ProxyExtension> extension);
	virtual bool OnBeforeBackgroundBrowser(shrewd_ptr<ProxyExtension> extension, const char* url);
	virtual bool OnBeforeBrowser(shrewd_ptr<ProxyExtension> extension,
		shrewd_ptr<ProxyBrowser> browser,
		shrewd_ptr<ProxyBrowser> active_browser,
		int index,
		const char* url,
		bool active,
		shrewd_ptr<ProxyWindowInfo>& windowInfo);
	virtual bool CanAccessBrowser(shrewd_ptr<ProxyExtension> extension,
		shrewd_ptr<ProxyBrowser> browser,
		bool include_incognito,
		shrewd_ptr<ProxyBrowser> target_browser);
	virtual void GetActiveBrowser(
		shrewd_ptr<ProxyExtension> extension,
		shrewd_ptr<ProxyBrowser> browser,
		bool include_incognito,
		shrewd_ptr<ProxyActiveBrowserCallback> callback);
	virtual bool GetExtensionResource(
		shrewd_ptr<ProxyExtension> extension,
		shrewd_ptr<ProxyBrowser> browser,
		const char* file,
		shrewd_ptr<ProxyGetExtensionResourceCallback> callback);
	virtual bool OnQuery(shrewd_ptr<ProxyBrowser> browser,
		shrewd_ptr<ProxyFrame> frame,
		__int64 query_id,
		const char* request,
		bool persistent,
		shrewd_ptr<ProxyQueryCallback> callback);
	virtual void OnQueryCanceled(shrewd_ptr<ProxyBrowser> browser,
		shrewd_ptr<ProxyFrame> frame,
		__int64 query_id);


public:
	void SetMainWindow(shrewd_ptr<AquariusUnit> window);

public:
	PRIME_IMPLEMENT_REFCOUNTING(EPLClient);

private:
	shrewd_ptr<AquariusUnit> m_mainWindow;
};

#define DECL_DATA_TYPE_ProxyClient_FUN_NAMES \
	EDITIONS("ProxyClient_CreateBrowser"),\
	EDITIONS("ProxyClient_CloseBrowser"),\
	EDITIONS("ProxyClient_SetForeground"),\
	EDITIONS("ProxyClient_GetBrowserCount"),\
	EDITIONS("ProxyClient_GetBrowserWithHandle"),\
	EDITIONS("ProxyClient_GetBrowserWithIndex"),\
	EDITIONS("ProxyClient_GetIndex"),\
	EDITIONS("ProxyClient_GetSameOriginBrowser"),\


#define DECL_DATA_TYPE_ProxyClient_FUN_CALLS \
	EDITIONF(ProxyClient_CreateBrowser),\
	EDITIONF(ProxyClient_CloseBrowser),\
	EDITIONF(ProxyClient_SetForeground),\
	EDITIONF(ProxyClient_GetBrowserCount),\
	EDITIONF(ProxyClient_GetBrowserWithHandle),\
	EDITIONF(ProxyClient_GetBrowserWithIndex),\
	EDITIONF(ProxyClient_GetIndex),\
	EDITIONF(ProxyClient_GetSameOriginBrowser),\


#define DECL_DATA_TYPE_ProxyClient_ARGINFO \
	{ /****** ProxyClient::CreateBrowser ** 0 **/ \
		/*name*/	 _WT("窗口设置"), \
		/*explain*/	 _WT("设置浏览器窗口信息。"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 MAKELONG(34,0),  /*shrewd_ptr<ProxyWindowInfo>*/ \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyClient::CreateBrowser ** 1 **/ \
		/*name*/	 _WT("url"), \
		/*explain*/	 _WT("设置需要访问的地址(URL), 无需访问可设置: about:blank"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_TEXT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyClient::CreateBrowser ** 2 **/ \
		/*name*/	 _WT("浏览器设置"), \
		/*explain*/	 _WT("设置浏览器的运行参数。"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 MAKELONG(5,0),  /*shrewd_ptr<ProxyBrowserSettings>*/ \
		/*default*/	 0,\
		/*state*/	 AS_DEFAULT_VALUE_IS_EMPTY \
	},\
	{ /****** ProxyClient::CreateBrowser ** 3 **/ \
		/*name*/	 _WT("隐身模式"), \
		/*explain*/	 _WT("此模式下浏览器不使用全局设置与缓存目录。"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_BOOL, \
		/*default*/	 0,\
		/*state*/	 AS_DEFAULT_VALUE_IS_EMPTY \
	},\
	{ /****** ProxyClient::CloseBrowser ** 4 **/ \
		/*name*/	 _WT("待关闭的浏览器"), \
		/*explain*/	 _WT("需要关闭的浏览器。"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 MAKELONG(4,0),  /*shrewd_ptr<ProxyBrowser>*/ \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyClient::CloseBrowser ** 5 **/ \
		/*name*/	 _WT("强制关闭"), \
		/*explain*/	 _WT("是否要求浏览器强制关闭。 设置为假时, 将会发送\"请求关闭\"事件, 在该事件中可进一步决定是否仍然关闭该浏览器, 详情请查看该事件说明。设置为真时, 浏览器将会被要求关闭并且不会发送\"请求关闭\"事件。"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_BOOL, \
		/*default*/	 0,\
		/*state*/	 AS_DEFAULT_VALUE_IS_EMPTY \
	},\
	{ /****** ProxyClient::SetForeground ** 6 **/ \
		/*name*/	 _WT("浏览器父窗口"), \
		/*explain*/	 _WT("对于同一父窗口下的浏览器窗口, 该函数会将除前台窗口之外的所有其它浏览器窗口设置为后台窗口。非同一父窗口的浏览器窗口不受此影响。"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyClient::SetForeground ** 7 **/ \
		/*name*/	 _WT("浏览器窗口"), \
		/*explain*/	 _WT("设置到前台的浏览器窗口。"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 MAKELONG(4,0),  /*shrewd_ptr<ProxyBrowser>*/ \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyClient::GetBrowserWithHandle ** 8 **/ \
		/*name*/	 _WT("窗口句柄"), \
		/*explain*/	 _WT("指定浏览器窗口的句柄。"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyClient::GetBrowserWithIndex ** 9 **/ \
		/*name*/	 _WT("索引"), \
		/*explain*/	 _WT("索引从0开始。"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyClient::GetIndex ** 10 **/ \
		/*name*/	 _WT("浏览器"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 MAKELONG(4,0),  /*shrewd_ptr<ProxyBrowser>*/ \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyClient::GetSameOriginBrowser ** 11 **/ \
		/*name*/	 _WT("浏览器"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 MAKELONG(4,0),  /*shrewd_ptr<ProxyBrowser>*/ \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\


#define DECL_DATA_TYPE_ProxyClient_CMDINFO(BeginIndex) \
	{ /*6*/ \
		/*ccname*/	_WT("创建浏览器"),\
		/*egname*/	_WT("CreateBrowser"), \
		/*explain*/	_WT("创建一个新的浏览器窗口, 创建成功返回新的窗口对象, 失败返回空, 可使用 IsValid 函数检查返回有效性。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	SDT_BOOL, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	4, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+0] \
	},\
	{ /*7*/ \
		/*ccname*/	_WT("关闭浏览器"),\
		/*egname*/	_WT("CloseBrowser"), \
		/*explain*/	_WT("向指定的浏览器发送关闭请求。发送此请求后JavaScript的\"onbeforeunload\"事件将被触发。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	_SDT_NULL, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	2, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+4] \
	},\
	{ /*8*/ \
		/*ccname*/	_WT("置前台窗口"),\
		/*egname*/	_WT("SetForeground"), \
		/*explain*/	_WT("设置显示指定的浏览器窗口。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	_SDT_NULL, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	2, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+6] \
	},\
	{ /*9*/ \
		/*ccname*/	_WT("取浏览器数量"),\
		/*egname*/	_WT("GetBrowserCount"), \
		/*explain*/	_WT("返回当前进程中的浏览器窗口数量。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	SDT_INT, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	0, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+8] \
	},\
	{ /*10*/ \
		/*ccname*/	_WT("取浏览器"),\
		/*egname*/	_WT("GetBrowserWithHandle"), \
		/*explain*/	_WT("使用窗口句柄取进程中的指定浏览器窗口, 成功返回窗口对象, 失败返回空, 可使用 IsValid 函数检查返回有效性。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	MAKELONG(4,0),  /*shrewd_ptr<ProxyBrowser>*/ \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	1, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+8] \
	},\
	{ /*11*/ \
		/*ccname*/	_WT("取浏览器索引"),\
		/*egname*/	_WT("GetBrowserWithIndex"), \
		/*explain*/	_WT("使用索引查询浏览器, 索引从0开始, 成功返回浏览器对象, 失败返回空对象。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	MAKELONG(4,0),  /*shrewd_ptr<ProxyBrowser>*/ \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	1, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+9] \
	},\
	{ /*12*/ \
		/*ccname*/	_WT("取索引"),\
		/*egname*/	_WT("GetIndex"), \
		/*explain*/	_WT("返回浏览器的索引编号。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	SDT_INT, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	1, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+10] \
	},\
	{ /*13*/ \
		/*ccname*/	_WT("取同源浏览器"),\
		/*egname*/	_WT("GetSameOriginBrowser"), \
		/*explain*/	_WT("返回与指定浏览器共享会话环境的所有浏览器。"), \
		/*category*/	-1, \
		/*state*/	CT_RETRUN_ARY_TYPE_DATA, \
		/*ret*/	MAKELONG(4,0),  /*shrewd_ptr<ProxyBrowser>***/ \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	1, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+11] \
	},\


extern "C"
void EDITIONF(ProxyClient_CreateBrowser) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyClient_CloseBrowser) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyClient_SetForeground) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyClient_GetBrowserCount) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyClient_GetBrowserWithHandle) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyClient_GetBrowserWithIndex) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyClient_GetIndex) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyClient_GetSameOriginBrowser) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);



