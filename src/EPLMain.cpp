#include "stdafx.h"
#include <stdio.h>
#include "lib2.h"
#include "lang.h"
#include <assert.h>
#include <string>
#include "resource.h"
#include "proxy/ProxyBase.h"
#include <shellapi.h>
#include "def/Power.h"

//headers
#include "EPLChromium.h"
#include "EPLProxyActiveBrowserCallback.h"
#include "EPLProxyAuthCallback.h"
#include "EPLProxyBase.h"
#include "EPLProxyBrowser.h"
#include "EPLProxyBrowserSettings.h"
#include "EPLProxyCollection.h"
#include "EPLProxyCommandLine.h"
#include "EPLProxyContextMenuParams.h"
#include "EPLProxyCookie.h"
#include "EPLProxyCookieManager.h"
#include "EPLProxyDictionaryValue.h"
#include "EPLProxyDOMDocument.h"
#include "EPLProxyDOMNode.h"
#include "EPLProxyDownloadItem.h"
#include "EPLProxyExtension.h"
#include "EPLProxyFileDialogCallback.h"
#include "EPLProxyFrame.h"
#include "EPLProxyGetExtensionResourceCallback.h"
#include "EPLProxyJSDialogCallback.h"
#include "EPLProxyListValue.h"
#include "EPLProxyMenuModel.h"
#include "EPLProxyPostDataElement.h"
#include "EPLProxyQueryCallback.h"
#include "EPLProxyRequest.h"
#include "EPLProxyResponse.h"
#include "EPLProxyResponseFilter.h"
#include "EPLProxyRunContextMenuCallback.h"
#include "EPLProxyServer.h"
#include "EPLProxySettings.h"
#include "EPLProxyURLRequest.h"
#include "EPLProxyValue.h"
#include "EPLProxyWaitableEvent.h"
#include "EPLProxyWebSocket.h"
#include "EPLProxyWindowInfo.h"



/////////////////////////////////////////////////////////////////////////////
INT g_nLastNotifyResult;
PFN_NOTIFY_SYS g_fnNotifySys = NULL;

INT WINAPI NotifySys (INT nMsg, DWORD dwParam1, DWORD dwParam2)
{
	assert(g_fnNotifySys != NULL);
	if (g_fnNotifySys != NULL)
		return g_nLastNotifyResult = g_fnNotifySys (nMsg, dwParam1, dwParam2);
	else
		return g_nLastNotifyResult = 0;
}


void* WEBCALLBACK EPLNewBuffer(size_t size){
	return (void*)NotifySys(NRS_MALLOC,(DWORD)size, 0 );
}

void* WEBCALLBACK EPLNewBufferInArray(size_t size){
	return (void*)NotifySys(NRS_MALLOC,(DWORD)size, 0 );
}

void WEBCALLBACK EPLDeleteBuffer(void* ptr){
	if(ptr){
		NotifySys(NRS_MFREE,(DWORD)ptr, 0 );
	}
}

void WEBCALLBACK EPLDeleteBufferInArray(void* ptr){
	if(ptr){
		NotifySys(NRS_MFREE,(DWORD)ptr, 0 );
	}
}

INT WINAPI AddInFunction (INT nAddInFnIndex){
	char buffer[128];

	if(nAddInFnIndex == 0){
		char libDir[MAX_PATH] = "";
		NotifySys(NAS_GET_PATH, 1005, (LPARAM)libDir);
		ProxyBase::ExportResourceToDir(libDir);
	}
	else if(nAddInFnIndex == 1){
		Power::GetInstance()->Initialize(1);
	}
	return 0;
}

INT WINAPI ProcessNotifyLib (INT nMsg, DWORD dwParam1, DWORD dwParam2)
{
	INT nRet = NR_OK;
	switch (nMsg)
	{
	case NL_SYS_NOTIFY_FUNCTION:
		g_fnNotifySys = (PFN_NOTIFY_SYS)dwParam1;
		NewBuffer = EPLNewBuffer;
		NewBufferInArray = EPLNewBufferInArray;
		DeleteBuffer = EPLDeleteBuffer;
		DeleteBufferInArray = EPLDeleteBufferInArray;
		break;
	default:
		nRet = NR_ERR;
		break;
	}

	return nRet;
}

/////////////////////////////////////////////////////////////////////////////
class EPLChromiumApp : public CWinApp
{
public:
	EPLChromiumApp(){

	}

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHtmlViewApp)
	public:
	//}}AFX_VIRTUAL

	//{{AFX_MSG(CHtmlViewApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


BEGIN_MESSAGE_MAP(EPLChromiumApp, CWinApp)
	//{{AFX_MSG_MAP(CHtmlViewApp)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


#ifndef __E_STATIC_LIB

EPLChromiumApp theApp;

#endif

/////////////////////////////////////////////////////////////////////////////

UNIT_PROPERTY s_ChromiumProperty [] =
{
	FIXED_WIN_UNIT_PROPERTY,
	{
		/*m_szName*/			_WT("边框"),
		/*m_szEgName*/			_WT("border"),
		/*m_szExplain*/			_WT(""),
		/*m_shtType*/			UD_PICK_INT,
		/*m_wState*/			NULL,
		/*m_szzPickStr*/		_WT("无边框\0凹入式\0凸出式\0浅凹入式\0镜框式\0单线边框式\0"),
	}
};

static EVENT_ARG_INFO2 s_ChromiumEventArgInfo [] = 
{
	{	/*EPLClient_OnBeforeCommandLineProcessing*/ 
	/*name*/	_WT("进程类型"), 
	/*explain*/	_WT("启动进程类型, 为空时是浏览器进程,否则为其它子进程"), 
	/*state*/	NULL, 
	/*DataType*/	SDT_TEXT, 
	},
	{	/*EPLClient_OnBeforeCommandLineProcessing*/ 
	/*name*/	_WT("命令行"), 
	/*explain*/	_WT("将使用的命令行配置对象, 该对象允许对其持有的配置参数查看或者修改。不要再事件之外保留此对象的引用。"), 
	/*state*/	EAS_BY_REF, 
	/*DataType*/	MAKELONG(7,0), 
	},
	{	/*EPLClient_OnBeforeChildProcessLaunch*/ 
	/*name*/	_WT("命令行"), 
	/*explain*/	_WT("命令行信息"), 
	/*state*/	EAS_BY_REF, 
	/*DataType*/	MAKELONG(7,0), 
	},
	{	/*EPLClient_OnRenderProcessThreadCreated*/ 
	/*name*/	_WT("附加信息"), 
	/*explain*/	_WT("此参数为用于为渲染过程提供额外信息, 不要保留对此对象的引用。"), 
	/*state*/	EAS_BY_REF, 
	/*DataType*/	MAKELONG(20,0), 
	},
	{	/*EPLClient_OnBeforePopup*/ 
	/*name*/	_WT("浏览器"), 
	/*explain*/	_WT("此浏览器代表发出创建请求的来源浏览器"), 
	/*state*/	EAS_BY_REF, 
	/*DataType*/	MAKELONG(4,0), 
	},
	{	/*EPLClient_OnBeforePopup*/ 
	/*name*/	_WT("框架"), 
	/*explain*/	_WT("此框架代表发出创建请求的框架"), 
	/*state*/	EAS_BY_REF, 
	/*DataType*/	MAKELONG(17,0), 
	},
	{	/*EPLClient_OnBeforePopup*/ 
	/*name*/	_WT("目标URL"), 
	/*explain*/	_WT("该URL为来源浏览器期望新窗口应导航的URL。"), 
	/*state*/	NULL, 
	/*DataType*/	SDT_TEXT, 
	},
	{	/*EPLClient_OnBeforePopup*/ 
	/*name*/	_WT("目标框架名称"), 
	/*explain*/	_WT(""), 
	/*state*/	NULL, 
	/*DataType*/	SDT_TEXT, 
	},
	{	/*EPLClient_OnBeforePopup*/ 
	/*name*/	_WT("链接的打开方式"), 
	/*explain*/	_WT("该值定义在枚举常量: #链接打开方式.* , 该参数提供了来源浏览器所期望的链接的打开方式(如: 在当前标签打开, 或者是创建一个新的标签等)。"), 
	/*state*/	NULL, 
	/*DataType*/	SDT_INT, 
	},
	{	/*EPLClient_OnBeforePopup*/ 
	/*name*/	_WT("是否为手势点击"), 
	/*explain*/	_WT("如果该项请求(创建新的窗口)是由用户通过手势点击的, 则此参数将为真。"), 
	/*state*/	NULL, 
	/*DataType*/	SDT_BOOL, 
	},
	{	/*EPLClient_OnBeforePopup*/ 
	/*name*/	_WT("窗口设置"), 
	/*explain*/	_WT("在此项参数中提供浏览器用于窗口创建的设置信息。"), 
	/*state*/	EAS_BY_REF, 
	/*DataType*/	MAKELONG(34,0), 
	},
	{	/*EPLClient_OnBeforePopup*/ 
	/*name*/	_WT("浏览器设置"), 
	/*explain*/	_WT("在此项参数中提供新浏览器窗口的设置信息。"), 
	/*state*/	EAS_BY_REF, 
	/*DataType*/	MAKELONG(5,0), 
	},
	{	/*EPLClient_OnBeforePopup*/ 
	/*name*/	_WT("是否禁止脚本访问"), 
	/*explain*/	_WT("此项参数标明是否期望在新的浏览器窗口中是否可以执行Javascript代码。如果不希望浏览器执行Javascript代码, 则应将此参数设置为真"), 
	/*state*/	EAS_BY_REF, 
	/*DataType*/	SDT_INT, 
	},
	{	/*EPLClient_OnAfterCreated*/ 
	/*name*/	_WT("浏览器"), 
	/*explain*/	_WT("创建完毕的浏览器"), 
	/*state*/	EAS_BY_REF, 
	/*DataType*/	MAKELONG(4,0), 
	},
	{	/*EPLClient_OnBeforeClose*/ 
	/*name*/	_WT("浏览器"), 
	/*explain*/	_WT("即将销毁的浏览器"), 
	/*state*/	EAS_BY_REF, 
	/*DataType*/	MAKELONG(4,0), 
	},
	{	/*EPLClient_DoClose*/ 
	/*name*/	_WT("浏览器"), 
	/*explain*/	_WT("浏览器"), 
	/*state*/	EAS_BY_REF, 
	/*DataType*/	MAKELONG(4,0), 
	},
	{	/*EPLClient_OnLoadingStateChange*/ 
	/*name*/	_WT("浏览器"), 
	/*explain*/	_WT("浏览器"), 
	/*state*/	EAS_BY_REF, 
	/*DataType*/	MAKELONG(4,0), 
	},
	{	/*EPLClient_OnLoadingStateChange*/ 
	/*name*/	_WT("是否正在加载"), 
	/*explain*/	_WT("表示浏览器是否仍在持续加载中"), 
	/*state*/	NULL, 
	/*DataType*/	SDT_BOOL, 
	},
	{	/*EPLClient_OnLoadingStateChange*/ 
	/*name*/	_WT("可否回退"), 
	/*explain*/	_WT("如果当前浏览器可以接受回退请求则此项参数为真"), 
	/*state*/	NULL, 
	/*DataType*/	SDT_BOOL, 
	},
	{	/*EPLClient_OnLoadingStateChange*/ 
	/*name*/	_WT("可否前进"), 
	/*explain*/	_WT("如果当前浏览器可以接受前进请求则次项参数为真"), 
	/*state*/	NULL, 
	/*DataType*/	SDT_BOOL, 
	},
	{	/*EPLClient_OnLoadStart*/ 
	/*name*/	_WT("浏览器"), 
	/*explain*/	_WT("浏览器"), 
	/*state*/	EAS_BY_REF, 
	/*DataType*/	MAKELONG(4,0), 
	},
	{	/*EPLClient_OnLoadStart*/ 
	/*name*/	_WT("框架"), 
	/*explain*/	_WT("提交导航请求的框架, 此参数永远不会为空, 调用.是否为首要框架函数以检查该框架是否为首要(Top-Level)框架。"), 
	/*state*/	EAS_BY_REF, 
	/*DataType*/	MAKELONG(17,0), 
	},
	{	/*EPLClient_OnLoadStart*/ 
	/*name*/	_WT("导航来源"), 
	/*explain*/	_WT("导航来源定义值为枚举常量: #导航来源.* , 此参数提供了有关导航来源的信息。"), 
	/*state*/	NULL, 
	/*DataType*/	SDT_INT, 
	},
	{	/*EPLClient_OnLoadEnd*/ 
	/*name*/	_WT("浏览器"), 
	/*explain*/	_WT("加载完成的浏览器"), 
	/*state*/	EAS_BY_REF, 
	/*DataType*/	MAKELONG(4,0), 
	},
	{	/*EPLClient_OnLoadEnd*/ 
	/*name*/	_WT("框架"), 
	/*explain*/	_WT("完成加载的框架, 此参数永远不会为空, 调用.是否为首要框架函数以检查该框架是否为首要(Top-Level)框架。"), 
	/*state*/	EAS_BY_REF, 
	/*DataType*/	MAKELONG(17,0), 
	},
	{	/*EPLClient_OnLoadEnd*/ 
	/*name*/	_WT("状态码"), 
	/*explain*/	_WT("此参数标明框架的加载结果, 如果没有错误发生, 则此参数的状态值应为: HTTP-200"), 
	/*state*/	NULL, 
	/*DataType*/	SDT_INT, 
	},
	{	/*EPLClient_OnLoadError*/ 
	/*name*/	_WT("浏览器"), 
	/*explain*/	_WT("加载操作终止的浏览器"), 
	/*state*/	EAS_BY_REF, 
	/*DataType*/	MAKELONG(4,0), 
	},
	{	/*EPLClient_OnLoadError*/ 
	/*name*/	_WT("框架"), 
	/*explain*/	_WT("加载操作终止的框架"), 
	/*state*/	EAS_BY_REF, 
	/*DataType*/	MAKELONG(17,0), 
	},
	{	/*EPLClient_OnLoadError*/ 
	/*name*/	_WT("错误代码"), 
	/*explain*/	_WT("代表加载失败的错误代码"), 
	/*state*/	NULL, 
	/*DataType*/	SDT_INT, 
	},
	{	/*EPLClient_OnLoadError*/ 
	/*name*/	_WT("错误信息"), 
	/*explain*/	_WT("提供加载失败的原因"), 
	/*state*/	NULL, 
	/*DataType*/	SDT_TEXT, 
	},
	{	/*EPLClient_OnLoadError*/ 
	/*name*/	_WT("加载失败的URL"), 
	/*explain*/	_WT("加载失败的URL地址"), 
	/*state*/	NULL, 
	/*DataType*/	SDT_TEXT, 
	},
	{	/*EPLClient_OnBeforeContextMenu*/ 
	/*name*/	_WT("浏览器"), 
	/*explain*/	_WT(""), 
	/*state*/	EAS_BY_REF, 
	/*DataType*/	MAKELONG(4,0), 
	},
	{	/*EPLClient_OnBeforeContextMenu*/ 
	/*name*/	_WT("框架"), 
	/*explain*/	_WT(""), 
	/*state*/	EAS_BY_REF, 
	/*DataType*/	MAKELONG(17,0), 
	},
	{	/*EPLClient_OnBeforeContextMenu*/ 
	/*name*/	_WT("菜单信息"), 
	/*explain*/	_WT("包含有关菜单上下文的信息"), 
	/*state*/	EAS_BY_REF, 
	/*DataType*/	MAKELONG(8,0), 
	},
	{	/*EPLClient_OnBeforeContextMenu*/ 
	/*name*/	_WT("菜单"), 
	/*explain*/	_WT("上下文菜单"), 
	/*state*/	EAS_BY_REF, 
	/*DataType*/	MAKELONG(21,0), 
	},
	{	/*EPLClient_RunContextMenu*/ 
	/*name*/	_WT("浏览器"), 
	/*explain*/	_WT(""), 
	/*state*/	EAS_BY_REF, 
	/*DataType*/	MAKELONG(4,0), 
	},
	{	/*EPLClient_RunContextMenu*/ 
	/*name*/	_WT("框架"), 
	/*explain*/	_WT(""), 
	/*state*/	EAS_BY_REF, 
	/*DataType*/	MAKELONG(17,0), 
	},
	{	/*EPLClient_RunContextMenu*/ 
	/*name*/	_WT("菜单信息"), 
	/*explain*/	_WT("包含有关菜单上下文的信息"), 
	/*state*/	EAS_BY_REF, 
	/*DataType*/	MAKELONG(8,0), 
	},
	{	/*EPLClient_RunContextMenu*/ 
	/*name*/	_WT("菜单"), 
	/*explain*/	_WT("上下文菜单"), 
	/*state*/	EAS_BY_REF, 
	/*DataType*/	MAKELONG(21,0), 
	},
	{	/*EPLClient_RunContextMenu*/ 
	/*name*/	_WT("菜单回调"), 
	/*explain*/	_WT("使用自定义菜单的命令回调"), 
	/*state*/	EAS_BY_REF, 
	/*DataType*/	MAKELONG(27,0), 
	},
	{	/*EPLClient_OnContextMenuCommand*/ 
	/*name*/	_WT("浏览器"), 
	/*explain*/	_WT(""), 
	/*state*/	EAS_BY_REF, 
	/*DataType*/	MAKELONG(4,0), 
	},
	{	/*EPLClient_OnContextMenuCommand*/ 
	/*name*/	_WT("框架"), 
	/*explain*/	_WT(""), 
	/*state*/	EAS_BY_REF, 
	/*DataType*/	MAKELONG(17,0), 
	},
	{	/*EPLClient_OnContextMenuCommand*/ 
	/*name*/	_WT("菜单信息"), 
	/*explain*/	_WT("包含有关菜单上下文的信息"), 
	/*state*/	EAS_BY_REF, 
	/*DataType*/	MAKELONG(8,0), 
	},
	{	/*EPLClient_OnContextMenuCommand*/ 
	/*name*/	_WT("命令ID"), 
	/*explain*/	_WT("菜单命令ID"), 
	/*state*/	NULL, 
	/*DataType*/	SDT_INT, 
	},
	{	/*EPLClient_OnContextMenuCommand*/ 
	/*name*/	_WT("事件标志"), 
	/*explain*/	_WT("定义值为枚举常量, #事件标志.* 。"), 
	/*state*/	NULL, 
	/*DataType*/	SDT_INT, 
	},
	{	/*EPLClient_OnContextMenuDismissed*/ 
	/*name*/	_WT("浏览器"), 
	/*explain*/	_WT(""), 
	/*state*/	EAS_BY_REF, 
	/*DataType*/	MAKELONG(4,0), 
	},
	{	/*EPLClient_OnContextMenuDismissed*/ 
	/*name*/	_WT("框架"), 
	/*explain*/	_WT(""), 
	/*state*/	EAS_BY_REF, 
	/*DataType*/	MAKELONG(17,0), 
	},
	{	/*EPLClient_OnAddressChange*/ 
	/*name*/	_WT("浏览器"), 
	/*explain*/	_WT("发生改变的浏览器"), 
	/*state*/	EAS_BY_REF, 
	/*DataType*/	MAKELONG(4,0), 
	},
	{	/*EPLClient_OnAddressChange*/ 
	/*name*/	_WT("框架"), 
	/*explain*/	_WT("发生改变的框架"), 
	/*state*/	EAS_BY_REF, 
	/*DataType*/	MAKELONG(17,0), 
	},
	{	/*EPLClient_OnAddressChange*/ 
	/*name*/	_WT("变更地址"), 
	/*explain*/	_WT("即将变更到的地址"), 
	/*state*/	NULL, 
	/*DataType*/	SDT_TEXT, 
	},
	{	/*EPLClient_OnTitleChange*/ 
	/*name*/	_WT("浏览器"), 
	/*explain*/	_WT("发生改变的浏览器"), 
	/*state*/	EAS_BY_REF, 
	/*DataType*/	MAKELONG(4,0), 
	},
	{	/*EPLClient_OnTitleChange*/ 
	/*name*/	_WT("变更标题"), 
	/*explain*/	_WT("即将变更到的标题"), 
	/*state*/	NULL, 
	/*DataType*/	SDT_TEXT, 
	},
	{	/*EPLClient_OnTooltip*/ 
	/*name*/	_WT("浏览器"), 
	/*explain*/	_WT("发出提示的浏览器"), 
	/*state*/	EAS_BY_REF, 
	/*DataType*/	MAKELONG(4,0), 
	},
	{	/*EPLClient_OnTooltip*/ 
	/*name*/	_WT("提示信息"), 
	/*explain*/	_WT("提示信息, 包含将在工具提示中显示的文本。"), 
	/*state*/	NULL, 
	/*DataType*/	SDT_TEXT, 
	},
	{	/*EPLClient_OnStatusMessage*/ 
	/*name*/	_WT("浏览器"), 
	/*explain*/	_WT("收到状态消息的浏览器"), 
	/*state*/	EAS_BY_REF, 
	/*DataType*/	MAKELONG(4,0), 
	},
	{	/*EPLClient_OnStatusMessage*/ 
	/*name*/	_WT("消息内容"), 
	/*explain*/	_WT("收到的信息内容"), 
	/*state*/	NULL, 
	/*DataType*/	SDT_TEXT, 
	},
	{	/*EPLClient_OnConsoleMessage*/ 
	/*name*/	_WT("浏览器"), 
	/*explain*/	_WT("收到控制台消息的浏览器"), 
	/*state*/	EAS_BY_REF, 
	/*DataType*/	MAKELONG(4,0), 
	},
	{	/*EPLClient_OnConsoleMessage*/ 
	/*name*/	_WT("消息等级"), 
	/*explain*/	_WT("记录该控制台消息的严重性等级, 参数定义值为枚举常量: #消息记录等级.* 。"), 
	/*state*/	NULL, 
	/*DataType*/	SDT_INT, 
	},
	{	/*EPLClient_OnConsoleMessage*/ 
	/*name*/	_WT("消息内容"), 
	/*explain*/	_WT(""), 
	/*state*/	NULL, 
	/*DataType*/	SDT_TEXT, 
	},
	{	/*EPLClient_OnConsoleMessage*/ 
	/*name*/	_WT("消息源"), 
	/*explain*/	_WT(""), 
	/*state*/	NULL, 
	/*DataType*/	SDT_TEXT, 
	},
	{	/*EPLClient_OnConsoleMessage*/ 
	/*name*/	_WT("起始行"), 
	/*explain*/	_WT(""), 
	/*state*/	NULL, 
	/*DataType*/	SDT_INT, 
	},
	{	/*EPLClient_OnLoadingProgressChange*/ 
	/*name*/	_WT("浏览器"), 
	/*explain*/	_WT("加载进度改变的浏览器"), 
	/*state*/	EAS_BY_REF, 
	/*DataType*/	MAKELONG(4,0), 
	},
	{	/*EPLClient_OnLoadingProgressChange*/ 
	/*name*/	_WT("进度值"), 
	/*explain*/	_WT("进度值的范围是: 0.0 到 1.0"), 
	/*state*/	NULL, 
	/*DataType*/	SDT_DOUBLE, 
	},
	{	/*EPLClient_OnFullscreenModeChange*/ 
	/*name*/	_WT("浏览器"), 
	/*explain*/	_WT(""), 
	/*state*/	EAS_BY_REF, 
	/*DataType*/	MAKELONG(4,0), 
	},
	{	/*EPLClient_OnFullscreenModeChange*/ 
	/*name*/	_WT("全屏模式"), 
	/*explain*/	_WT("如果此参数为真网页显示内容将填充整个浏览器区域, 如果为假则还原回原始大小和位置。"), 
	/*state*/	NULL, 
	/*DataType*/	SDT_BOOL, 
	},
	{	/*EPLClient_OnJSDialog*/ 
	/*name*/	_WT("浏览器"), 
	/*explain*/	_WT("即将打开对话框的浏览器"), 
	/*state*/	EAS_BY_REF, 
	/*DataType*/	MAKELONG(4,0), 
	},
	{	/*EPLClient_OnJSDialog*/ 
	/*name*/	_WT("页面URL"), 
	/*explain*/	_WT("弹出该对话框的页面URL地址"), 
	/*state*/	NULL, 
	/*DataType*/	SDT_TEXT, 
	},
	{	/*EPLClient_OnJSDialog*/ 
	/*name*/	_WT("对话框类型"), 
	/*explain*/	_WT("对话框类型值定义于枚举常量: #脚本对话框.*"), 
	/*state*/	NULL, 
	/*DataType*/	SDT_INT, 
	},
	{	/*EPLClient_OnJSDialog*/ 
	/*name*/	_WT("消息内容"), 
	/*explain*/	_WT("对话框消息内容"), 
	/*state*/	NULL, 
	/*DataType*/	SDT_TEXT, 
	},
	{	/*EPLClient_OnJSDialog*/ 
	/*name*/	_WT("默认值"), 
	/*explain*/	_WT("提供默认输入的文本"), 
	/*state*/	NULL, 
	/*DataType*/	SDT_TEXT, 
	},
	{	/*EPLClient_OnJSDialog*/ 
	/*name*/	_WT("对话框回调"), 
	/*explain*/	_WT("执行该回调用以向Javascript返回对话框调用结果。"), 
	/*state*/	EAS_BY_REF, 
	/*DataType*/	MAKELONG(19,0), 
	},
	{	/*EPLClient_OnJSDialog*/ 
	/*name*/	_WT("禁止消息"), 
	/*explain*/	_WT("设置此参数为真并返回假可以抑制消息(抑制消息比立即执行回退更加高效, 因为它用于检查可能的恶意行为, 例如在onbeforeunload中发生警报消息)。"), 
	/*state*/	EAS_BY_REF, 
	/*DataType*/	SDT_INT, 
	},
	{	/*EPLClient_OnBeforeUnloadDialog*/ 
	/*name*/	_WT("浏览器"), 
	/*explain*/	_WT("发出询问的浏览器"), 
	/*state*/	EAS_BY_REF, 
	/*DataType*/	MAKELONG(4,0), 
	},
	{	/*EPLClient_OnBeforeUnloadDialog*/ 
	/*name*/	_WT("消息内容"), 
	/*explain*/	_WT("询问的消息内容"), 
	/*state*/	NULL, 
	/*DataType*/	SDT_TEXT, 
	},
	{	/*EPLClient_OnBeforeUnloadDialog*/ 
	/*name*/	_WT("是否重新加载"), 
	/*explain*/	_WT(""), 
	/*state*/	NULL, 
	/*DataType*/	SDT_BOOL, 
	},
	{	/*EPLClient_OnBeforeUnloadDialog*/ 
	/*name*/	_WT("对话框回调"), 
	/*explain*/	_WT("如果希望使用自定义对话框显示消息内容, 则该回退接口提供了对话框的功能实现, 调用此对话框接口以向浏览器返回执行结果。"), 
	/*state*/	EAS_BY_REF, 
	/*DataType*/	MAKELONG(19,0), 
	},
	{	/*EPLClient_OnResetDialogState*/ 
	/*name*/	_WT("浏览器"), 
	/*explain*/	_WT("重置对话框状态的浏览器"), 
	/*state*/	EAS_BY_REF, 
	/*DataType*/	MAKELONG(4,0), 
	},
	{	/*EPLClient_OnDialogClosed*/ 
	/*name*/	_WT("浏览器"), 
	/*explain*/	_WT("关闭对话框的浏览器"), 
	/*state*/	EAS_BY_REF, 
	/*DataType*/	MAKELONG(4,0), 
	},
	{	/*EPLClient_GetAuthCredentials*/ 
	/*name*/	_WT("浏览器"), 
	/*explain*/	_WT("发出请求的浏览器"), 
	/*state*/	EAS_BY_REF, 
	/*DataType*/	MAKELONG(4,0), 
	},
	{	/*EPLClient_GetAuthCredentials*/ 
	/*name*/	_WT("认证源"), 
	/*explain*/	_WT("此参数是发出此身份验证请求的来源URL。"), 
	/*state*/	NULL, 
	/*DataType*/	SDT_TEXT, 
	},
	{	/*EPLClient_GetAuthCredentials*/ 
	/*name*/	_WT("是否为代理服务器"), 
	/*explain*/	_WT("此参数指示目标主机是否为代理服务器。"), 
	/*state*/	NULL, 
	/*DataType*/	SDT_BOOL, 
	},
	{	/*EPLClient_GetAuthCredentials*/ 
	/*name*/	_WT("主机名称"), 
	/*explain*/	_WT("包含主机名称"), 
	/*state*/	NULL, 
	/*DataType*/	SDT_TEXT, 
	},
	{	/*EPLClient_GetAuthCredentials*/ 
	/*name*/	_WT("端口号"), 
	/*explain*/	_WT("包含端口号"), 
	/*state*/	NULL, 
	/*DataType*/	SDT_INT, 
	},
	{	/*EPLClient_GetAuthCredentials*/ 
	/*name*/	_WT("域"), 
	/*explain*/	_WT("访问的域。"), 
	/*state*/	NULL, 
	/*DataType*/	SDT_TEXT, 
	},
	{	/*EPLClient_GetAuthCredentials*/ 
	/*name*/	_WT("认证方案"), 
	/*explain*/	_WT("此参数表明使用的身份验证方案, 例如:\"base\" 或 \"digest\"。如果请求的源是FTP服务器, 则此参数为空。"), 
	/*state*/	NULL, 
	/*DataType*/	SDT_TEXT, 
	},
	{	/*EPLClient_GetAuthCredentials*/ 
	/*name*/	_WT("认证回调"), 
	/*explain*/	_WT("执行此回调用以向浏览器提交用户身份验证信息。"), 
	/*state*/	EAS_BY_REF, 
	/*DataType*/	MAKELONG(3,0), 
	},
	{	/*EPLClient_OnBeforeBrowse*/ 
	/*name*/	_WT("浏览器"), 
	/*explain*/	_WT("表示导航来源的浏览器"), 
	/*state*/	EAS_BY_REF, 
	/*DataType*/	MAKELONG(4,0), 
	},
	{	/*EPLClient_OnBeforeBrowse*/ 
	/*name*/	_WT("框架"), 
	/*explain*/	_WT("表示导航来源的框架"), 
	/*state*/	EAS_BY_REF, 
	/*DataType*/	MAKELONG(17,0), 
	},
	{	/*EPLClient_OnBeforeBrowse*/ 
	/*name*/	_WT("请求"), 
	/*explain*/	_WT("代表发生导航的请求, 该对象无法在此事件中修改。"), 
	/*state*/	EAS_BY_REF, 
	/*DataType*/	MAKELONG(24,0), 
	},
	{	/*EPLClient_OnBeforeBrowse*/ 
	/*name*/	_WT("是否为用户手势"), 
	/*explain*/	_WT("如果是用户在浏览器中明确的使用手势进行导航(例如, 单击链接),则此参数为真。"), 
	/*state*/	NULL, 
	/*DataType*/	SDT_BOOL, 
	},
	{	/*EPLClient_OnBeforeBrowse*/ 
	/*name*/	_WT("是否重定向"), 
	/*explain*/	_WT("指示此导航是否为重定向请求。"), 
	/*state*/	NULL, 
	/*DataType*/	SDT_BOOL, 
	},
	{	/*EPLClient_OnBeforeResourceLoad*/ 
	/*name*/	_WT("浏览器"), 
	/*explain*/	_WT("此资源请求的来源浏览器。"), 
	/*state*/	EAS_BY_REF, 
	/*DataType*/	MAKELONG(4,0), 
	},
	{	/*EPLClient_OnBeforeResourceLoad*/ 
	/*name*/	_WT("框架"), 
	/*explain*/	_WT("此资源请求的来源框架"), 
	/*state*/	EAS_BY_REF, 
	/*DataType*/	MAKELONG(17,0), 
	},
	{	/*EPLClient_OnBeforeResourceLoad*/ 
	/*name*/	_WT("请求"), 
	/*explain*/	_WT("代表取此资源的请求。允许对此请求进行修改以重定向或更改资源负载。"), 
	/*state*/	EAS_BY_REF, 
	/*DataType*/	MAKELONG(24,0), 
	},
	{	/*EPLClient_OnResourceRedirect*/ 
	/*name*/	_WT("浏览器"), 
	/*explain*/	_WT("代表请求来源的浏览器"), 
	/*state*/	EAS_BY_REF, 
	/*DataType*/	MAKELONG(4,0), 
	},
	{	/*EPLClient_OnResourceRedirect*/ 
	/*name*/	_WT("框架"), 
	/*explain*/	_WT("代表请求来源的框架"), 
	/*state*/	EAS_BY_REF, 
	/*DataType*/	MAKELONG(17,0), 
	},
	{	/*EPLClient_OnResourceRedirect*/ 
	/*name*/	_WT("请求"), 
	/*explain*/	_WT("此参数包含旧的URL或其它与请求有关的信息。只读对象。"), 
	/*state*/	EAS_BY_REF, 
	/*DataType*/	MAKELONG(24,0), 
	},
	{	/*EPLClient_OnResourceRedirect*/ 
	/*name*/	_WT("响应"), 
	/*explain*/	_WT("此参数将包含导致重定向的响应(response)。只读对象。"), 
	/*state*/	EAS_BY_REF, 
	/*DataType*/	MAKELONG(25,0), 
	},
	{	/*EPLClient_OnResourceRedirect*/ 
	/*name*/	_WT("新地址"), 
	/*explain*/	_WT("此参数将包含新的URL地址, 并可以根据需要更改。"), 
	/*state*/	EAS_BY_REF, 
	/*DataType*/	SDT_TEXT, 
	},
	{	/*EPLClient_OnResourceResponse*/ 
	/*name*/	_WT("浏览器"), 
	/*explain*/	_WT("代表请求来源的浏览器, 对于源自Service Worker或者 URLRequest的请求,该参数为空。"), 
	/*state*/	EAS_BY_REF, 
	/*DataType*/	MAKELONG(4,0), 
	},
	{	/*EPLClient_OnResourceResponse*/ 
	/*name*/	_WT("框架"), 
	/*explain*/	_WT("代表请求来源的框架, 对于源自Service Worker或者 URLRequest的请求,该参数为空。"), 
	/*state*/	EAS_BY_REF, 
	/*DataType*/	MAKELONG(17,0), 
	},
	{	/*EPLClient_OnResourceResponse*/ 
	/*name*/	_WT("请求"), 
	/*explain*/	_WT("用于取该资源的请求"), 
	/*state*/	EAS_BY_REF, 
	/*DataType*/	MAKELONG(24,0), 
	},
	{	/*EPLClient_OnResourceResponse*/ 
	/*name*/	_WT("响应"), 
	/*explain*/	_WT("该资源的响应(response), 只读对象。"), 
	/*state*/	EAS_BY_REF, 
	/*DataType*/	MAKELONG(25,0), 
	},
	{	/*EPLClient_OnResourceResponseFilter*/ 
	/*name*/	_WT("浏览器"), 
	/*explain*/	_WT("代表请求来源的浏览器"), 
	/*state*/	EAS_BY_REF, 
	/*DataType*/	MAKELONG(4,0), 
	},
	{	/*EPLClient_OnResourceResponseFilter*/ 
	/*name*/	_WT("框架"), 
	/*explain*/	_WT("代表请求来源的框架"), 
	/*state*/	EAS_BY_REF, 
	/*DataType*/	MAKELONG(17,0), 
	},
	{	/*EPLClient_OnResourceResponseFilter*/ 
	/*name*/	_WT("请求"), 
	/*explain*/	_WT("代表该资源的请求对象, 该对象不能在此事件中修改。"), 
	/*state*/	EAS_BY_REF, 
	/*DataType*/	MAKELONG(24,0), 
	},
	{	/*EPLClient_OnResourceResponseFilter*/ 
	/*name*/	_WT("响应"), 
	/*explain*/	_WT("代表该资源的响应对象, 该对象不能在此事件中修改。"), 
	/*state*/	EAS_BY_REF, 
	/*DataType*/	MAKELONG(25,0), 
	},
	{	/*EPLClient_OnResourceLoadComplete*/ 
	/*name*/	_WT("浏览器"), 
	/*explain*/	_WT("代表请求来源的浏览器, 对于源自Service Worker 或 URLRequest的请求, 该参数可以为空。"), 
	/*state*/	EAS_BY_REF, 
	/*DataType*/	MAKELONG(4,0), 
	},
	{	/*EPLClient_OnResourceLoadComplete*/ 
	/*name*/	_WT("框架"), 
	/*explain*/	_WT("代表请求来源的框架, 对于源自Service Worker 或 URLRequest的请求, 该参数可以为空。"), 
	/*state*/	EAS_BY_REF, 
	/*DataType*/	MAKELONG(17,0), 
	},
	{	/*EPLClient_OnResourceLoadComplete*/ 
	/*name*/	_WT("请求"), 
	/*explain*/	_WT("此参数代表该资源的请求, 只读对象。"), 
	/*state*/	EAS_BY_REF, 
	/*DataType*/	MAKELONG(24,0), 
	},
	{	/*EPLClient_OnResourceLoadComplete*/ 
	/*name*/	_WT("响应"), 
	/*explain*/	_WT("此参数代表该资源的响应, 只读对象。"), 
	/*state*/	EAS_BY_REF, 
	/*DataType*/	MAKELONG(25,0), 
	},
	{	/*EPLClient_OnResourceLoadComplete*/ 
	/*name*/	_WT("状态码"), 
	/*explain*/	_WT("此参数指示加载的完成状态。定义值为枚举常量： #请求状态.*"), 
	/*state*/	NULL, 
	/*DataType*/	SDT_INT, 
	},
	{	/*EPLClient_OnResourceLoadComplete*/ 
	/*name*/	_WT("接收长度"), 
	/*explain*/	_WT("此参数是实际读取的响应字节数。"), 
	/*state*/	NULL, 
	/*DataType*/	SDT_INT64, 
	},
	{	/*EPLClient_OnFileDialog*/ 
	/*name*/	_WT("浏览器"), 
	/*explain*/	_WT("代表索取文件对话框的浏览器"), 
	/*state*/	EAS_BY_REF, 
	/*DataType*/	MAKELONG(4,0), 
	},
	{	/*EPLClient_OnFileDialog*/ 
	/*name*/	_WT("打开模式"), 
	/*explain*/	_WT("文件对话框打开模式, 定义值为枚举常量: #文件对话框模式.* "), 
	/*state*/	NULL, 
	/*DataType*/	SDT_INT, 
	},
	{	/*EPLClient_OnFileDialog*/ 
	/*name*/	_WT("标题"), 
	/*explain*/	_WT("对话框要使用的标题"), 
	/*state*/	NULL, 
	/*DataType*/	SDT_TEXT, 
	},
	{	/*EPLClient_OnFileDialog*/ 
	/*name*/	_WT("默认文件名"), 
	/*explain*/	_WT("提供的具有可选目录或文件名的路径应该首先在对话框中选择该组件"), 
	/*state*/	NULL, 
	/*DataType*/	SDT_TEXT, 
	},
	{	/*EPLClient_OnFileDialog*/ 
	/*name*/	_WT("过滤器"), 
	/*explain*/	_WT("过滤器用于现在可选的文件类型, 并且可以任意组合: a.有效的小写MIME类型(例如: \"text/*\" 或 \"image/*\"), b.单个文件扩展名(例如: \".txt\" 或 \".png\"), c.组合说明与文件扩展名(例如: \"图像文件|.png;.gif.jpg \"), 符号\"|\"用于界定说明与扩展名列表,而\";\"则用于分隔每一个扩展名。"), 
	/*state*/	NULL, 
	/*DataType*/	SDT_TEXT, 
	},
	{	/*EPLClient_OnFileDialog*/ 
	/*name*/	_WT("选择过滤器"), 
	/*explain*/	_WT("从0开始, 默认情况下应选择过滤器索引。"), 
	/*state*/	NULL, 
	/*DataType*/	SDT_INT, 
	},
	{	/*EPLClient_OnFileDialog*/ 
	/*name*/	_WT("对话框回调"), 
	/*explain*/	_WT("如使用自定义文件对话框, 则使用该回调接口用于返回文件选择结果。"), 
	/*state*/	EAS_BY_REF, 
	/*DataType*/	MAKELONG(16,0), 
	},
	{	/*EPLClient_OnBeforeDownload*/ 
	/*name*/	_WT("浏览器"), 
	/*explain*/	_WT("发送下载请求的浏览器"), 
	/*state*/	EAS_BY_REF, 
	/*DataType*/	MAKELONG(4,0), 
	},
	{	/*EPLClient_OnBeforeDownload*/ 
	/*name*/	_WT("下载项"), 
	/*explain*/	_WT("文件的下载信息, 不要在事件之外保留该对象的引用。"), 
	/*state*/	EAS_BY_REF, 
	/*DataType*/	MAKELONG(14,0), 
	},
	{	/*EPLClient_OnBeforeDownload*/ 
	/*name*/	_WT("建议名称"), 
	/*explain*/	_WT("建议名称是下载文件的建议名称"), 
	/*state*/	NULL, 
	/*DataType*/	SDT_TEXT, 
	},
	{	/*EPLClient_OnDownloadUpdated*/ 
	/*name*/	_WT("浏览器"), 
	/*explain*/	_WT("发送下载请求的浏览器"), 
	/*state*/	EAS_BY_REF, 
	/*DataType*/	MAKELONG(4,0), 
	},
	{	/*EPLClient_OnDownloadUpdated*/ 
	/*name*/	_WT("下载项"), 
	/*explain*/	_WT("文件的下载信息, 不要在此事件之外保留该对象的引用。"), 
	/*state*/	EAS_BY_REF, 
	/*DataType*/	MAKELONG(14,0), 
	},
	{	/*EPLClient_OnResourceFilter*/ 
	/*name*/	_WT("浏览器"), 
	/*explain*/	_WT("与此资源过滤器相关的浏览器"), 
	/*state*/	EAS_BY_REF, 
	/*DataType*/	MAKELONG(4,0), 
	},
	{	/*EPLClient_OnResourceFilter*/ 
	/*name*/	_WT("过滤器"), 
	/*explain*/	_WT("用于进行资源可选化设置。"), 
	/*state*/	EAS_BY_REF, 
	/*DataType*/	MAKELONG(26,0), 
	},
	{	/*EPLClient_OnServerCreated*/ 
	/*name*/	_WT("服务器"), 
	/*explain*/	_WT("已启动就绪的服务器"), 
	/*state*/	EAS_BY_REF, 
	/*DataType*/	MAKELONG(28,0), 
	},
	{	/*EPLClient_OnServerDestroyed*/ 
	/*name*/	_WT("服务器"), 
	/*explain*/	_WT("停止运行的服务器"), 
	/*state*/	EAS_BY_REF, 
	/*DataType*/	MAKELONG(28,0), 
	},
	{	/*EPLClient_OnClientConnected*/ 
	/*name*/	_WT("服务器"), 
	/*explain*/	_WT(""), 
	/*state*/	EAS_BY_REF, 
	/*DataType*/	MAKELONG(28,0), 
	},
	{	/*EPLClient_OnClientConnected*/ 
	/*name*/	_WT("客户ID"), 
	/*explain*/	_WT("表示客户连接的唯一ID"), 
	/*state*/	NULL, 
	/*DataType*/	SDT_INT, 
	},
	{	/*EPLClient_OnClientDisconnected*/ 
	/*name*/	_WT("服务器"), 
	/*explain*/	_WT(""), 
	/*state*/	EAS_BY_REF, 
	/*DataType*/	MAKELONG(28,0), 
	},
	{	/*EPLClient_OnClientDisconnected*/ 
	/*name*/	_WT("客户ID"), 
	/*explain*/	_WT("表示客户连接的唯一ID"), 
	/*state*/	NULL, 
	/*DataType*/	SDT_INT, 
	},
	{	/*EPLClient_OnHttpRequest*/ 
	/*name*/	_WT("服务器"), 
	/*explain*/	_WT(""), 
	/*state*/	EAS_BY_REF, 
	/*DataType*/	MAKELONG(28,0), 
	},
	{	/*EPLClient_OnHttpRequest*/ 
	/*name*/	_WT("客户ID"), 
	/*explain*/	_WT("表示客户连接的唯一ID"), 
	/*state*/	NULL, 
	/*DataType*/	SDT_INT, 
	},
	{	/*EPLClient_OnHttpRequest*/ 
	/*name*/	_WT("客户地址"), 
	/*explain*/	_WT("客户端的连接地址,包括端口号"), 
	/*state*/	NULL, 
	/*DataType*/	SDT_TEXT, 
	},
	{	/*EPLClient_OnHttpRequest*/ 
	/*name*/	_WT("请求"), 
	/*explain*/	_WT("表示包含客户端请求内容参数。"), 
	/*state*/	EAS_BY_REF, 
	/*DataType*/	MAKELONG(24,0), 
	},
	{	/*EPLClient_OnWebSocketRequest*/ 
	/*name*/	_WT("服务器"), 
	/*explain*/	_WT(""), 
	/*state*/	EAS_BY_REF, 
	/*DataType*/	MAKELONG(28,0), 
	},
	{	/*EPLClient_OnWebSocketRequest*/ 
	/*name*/	_WT("客户ID"), 
	/*explain*/	_WT("表示客户连接的唯一ID"), 
	/*state*/	NULL, 
	/*DataType*/	SDT_INT, 
	},
	{	/*EPLClient_OnWebSocketRequest*/ 
	/*name*/	_WT("客户地址"), 
	/*explain*/	_WT("客户端的连接地址, 包括端口号"), 
	/*state*/	NULL, 
	/*DataType*/	SDT_TEXT, 
	},
	{	/*EPLClient_OnWebSocketRequest*/ 
	/*name*/	_WT("请求"), 
	/*explain*/	_WT("指示客户端请求内容的参数"), 
	/*state*/	EAS_BY_REF, 
	/*DataType*/	MAKELONG(24,0), 
	},
	{	/*EPLClient_OnWebSocketConnected*/ 
	/*name*/	_WT("服务器"), 
	/*explain*/	_WT(""), 
	/*state*/	EAS_BY_REF, 
	/*DataType*/	MAKELONG(28,0), 
	},
	{	/*EPLClient_OnWebSocketConnected*/ 
	/*name*/	_WT("客户ID"), 
	/*explain*/	_WT("表示客户连接的唯一ID"), 
	/*state*/	NULL, 
	/*DataType*/	SDT_INT, 
	},
	{	/*EPLClient_OnWebSocketMessage*/ 
	/*name*/	_WT("服务器"), 
	/*explain*/	_WT(""), 
	/*state*/	EAS_BY_REF, 
	/*DataType*/	MAKELONG(28,0), 
	},
	{	/*EPLClient_OnWebSocketMessage*/ 
	/*name*/	_WT("客户ID"), 
	/*explain*/	_WT("表示客户连接的唯一ID"), 
	/*state*/	NULL, 
	/*DataType*/	SDT_INT, 
	},
	{	/*EPLClient_OnWebSocketMessage*/ 
	/*name*/	_WT("消息内容"), 
	/*explain*/	_WT(""), 
	/*state*/	NULL, 
	/*DataType*/	SDT_BIN, 
	},
	{	/*EPLClient_OnWebSocketMessage*/ 
	/*name*/	_WT("消息长度"), 
	/*explain*/	_WT("以字节为单位"), 
	/*state*/	NULL, 
	/*DataType*/	SDT_INT, 
	},
	{	/*EPLClient_OnWebSocketClientConnected*/ 
	/*name*/	_WT("套接字"), 
	/*explain*/	_WT("连接套接字"), 
	/*state*/	EAS_BY_REF, 
	/*DataType*/	MAKELONG(33,0), 
	},
	{	/*EPLClient_OnWebSocketClientClosed*/ 
	/*name*/	_WT("套接字"), 
	/*explain*/	_WT("断开套接字"), 
	/*state*/	EAS_BY_REF, 
	/*DataType*/	MAKELONG(33,0), 
	},
	{	/*EPLClient_OnWebSocketClientMessage*/ 
	/*name*/	_WT("套接字"), 
	/*explain*/	_WT("接收套接字"), 
	/*state*/	EAS_BY_REF, 
	/*DataType*/	MAKELONG(33,0), 
	},
	{	/*EPLClient_OnWebSocketClientMessage*/ 
	/*name*/	_WT("流类型"), 
	/*explain*/	_WT("接收到的数据流类型, 定义值为枚举常量: #超文本流类型. * 。"), 
	/*state*/	NULL, 
	/*DataType*/	SDT_INT, 
	},
	{	/*EPLClient_OnWebSocketClientMessage*/ 
	/*name*/	_WT("流数据"), 
	/*explain*/	_WT("字节流数据。"), 
	/*state*/	NULL, 
	/*DataType*/	SDT_BIN, 
	},
	{	/*EPLClient_OnWebSocketClientError*/ 
	/*name*/	_WT("套接字"), 
	/*explain*/	_WT("错误套接字"), 
	/*state*/	EAS_BY_REF, 
	/*DataType*/	MAKELONG(33,0), 
	},
	{	/*EPLClient_OnWebSocketClientError*/ 
	/*name*/	_WT("错误信息"), 
	/*explain*/	_WT("报告的错误信息"), 
	/*state*/	NULL, 
	/*DataType*/	SDT_TEXT, 
	},
	{	/*EPLClient_OnExtensionLoadFailed*/ 
	/*name*/	_WT("错误代码"), 
	/*explain*/	_WT("错误代码"), 
	/*state*/	NULL, 
	/*DataType*/	SDT_INT, 
	},
	{	/*EPLClient_OnExtensionLoaded*/ 
	/*name*/	_WT("扩展程序"), 
	/*explain*/	_WT(""), 
	/*state*/	EAS_BY_REF, 
	/*DataType*/	MAKELONG(15,0), 
	},
	{	/*EPLClient_OnExtensionUnloaded*/ 
	/*name*/	_WT("扩展程序"), 
	/*explain*/	_WT(""), 
	/*state*/	EAS_BY_REF, 
	/*DataType*/	MAKELONG(15,0), 
	},
	{	/*EPLClient_OnBeforeBackgroundBrowser*/ 
	/*name*/	_WT("扩展程序"), 
	/*explain*/	_WT("正在加载脚本的扩展程序"), 
	/*state*/	EAS_BY_REF, 
	/*DataType*/	MAKELONG(15,0), 
	},
	{	/*EPLClient_OnBeforeBackgroundBrowser*/ 
	/*name*/	_WT("引用页面URL"), 
	/*explain*/	_WT("扩展程序内部引用HTML页面的URL地址。该HTML页面通过<script>的 src 属性加载后台脚本。"), 
	/*state*/	NULL, 
	/*DataType*/	SDT_TEXT, 
	},
	{	/*EPLClient_OnBeforeBrowser*/ 
	/*name*/	_WT("扩展程序"), 
	/*explain*/	_WT("调用API来源的扩展程序"), 
	/*state*/	EAS_BY_REF, 
	/*DataType*/	MAKELONG(15,0), 
	},
	{	/*EPLClient_OnBeforeBrowser*/ 
	/*name*/	_WT("浏览器"), 
	/*explain*/	_WT("调用API来源的扩展程序浏览器"), 
	/*state*/	EAS_BY_REF, 
	/*DataType*/	MAKELONG(4,0), 
	},
	{	/*EPLClient_OnBeforeBrowser*/ 
	/*name*/	_WT("活动浏览器"), 
	/*explain*/	_WT(""), 
	/*state*/	EAS_BY_REF, 
	/*DataType*/	MAKELONG(4,0), 
	},
	{	/*EPLClient_OnBeforeBrowser*/ 
	/*name*/	_WT("索引"), 
	/*explain*/	_WT("索引指示浏览器的位置属性, 可以通过index属性指定。"), 
	/*state*/	NULL, 
	/*DataType*/	SDT_INT, 
	},
	{	/*EPLClient_OnBeforeBrowser*/ 
	/*name*/	_WT("加载URL"), 
	/*explain*/	_WT("浏览器将要加载的URL"), 
	/*state*/	NULL, 
	/*DataType*/	SDT_TEXT, 
	},
	{	/*EPLClient_OnBeforeBrowser*/ 
	/*name*/	_WT("活动窗口"), 
	/*explain*/	_WT("活动窗口指示新浏览器是否为前台激活窗口。"), 
	/*state*/	NULL, 
	/*DataType*/	SDT_BOOL, 
	},
	{	/*EPLClient_OnBeforeBrowser*/ 
	/*name*/	_WT("窗口设置"), 
	/*explain*/	_WT("设置新浏览器的窗口样式信息。"), 
	/*state*/	EAS_BY_REF, 
	/*DataType*/	MAKELONG(34,0), 
	},
	{	/*EPLClient_CanAccessBrowser*/ 
	/*name*/	_WT("扩展程序"), 
	/*explain*/	_WT("扩展程序API的调用来源"), 
	/*state*/	EAS_BY_REF, 
	/*DataType*/	MAKELONG(15,0), 
	},
	{	/*EPLClient_CanAccessBrowser*/ 
	/*name*/	_WT("浏览器"), 
	/*explain*/	_WT("扩展程序API的调用来源"), 
	/*state*/	EAS_BY_REF, 
	/*DataType*/	MAKELONG(4,0), 
	},
	{	/*EPLClient_CanAccessBrowser*/ 
	/*name*/	_WT("隐身模式"), 
	/*explain*/	_WT("除非源扩展程序启用了隐身访问, 否则不允许访问隐身浏览器, 在这种情况下此参数为真。"), 
	/*state*/	NULL, 
	/*DataType*/	SDT_BOOL, 
	},
	{	/*EPLClient_CanAccessBrowser*/ 
	/*name*/	_WT("目标浏览器"), 
	/*explain*/	_WT(""), 
	/*state*/	EAS_BY_REF, 
	/*DataType*/	MAKELONG(4,0), 
	},
	{	/*EPLClient_GetActiveBrowser*/ 
	/*name*/	_WT("扩展程序"), 
	/*explain*/	_WT(""), 
	/*state*/	EAS_BY_REF, 
	/*DataType*/	MAKELONG(15,0), 
	},
	{	/*EPLClient_GetActiveBrowser*/ 
	/*name*/	_WT("浏览器"), 
	/*explain*/	_WT(""), 
	/*state*/	EAS_BY_REF, 
	/*DataType*/	MAKELONG(4,0), 
	},
	{	/*EPLClient_GetActiveBrowser*/ 
	/*name*/	_WT("隐身模式"), 
	/*explain*/	_WT("除非源扩展程序启用了隐身访问, 否则不考虑隐身浏览器, 在这种情况下此参数为真。"), 
	/*state*/	NULL, 
	/*DataType*/	SDT_BOOL, 
	},
	{	/*EPLClient_GetActiveBrowser*/ 
	/*name*/	_WT("获取回调"), 
	/*explain*/	_WT("使用此回调接口向扩展程序返回当前应用程序中的活动浏览器对象。"), 
	/*state*/	EAS_BY_REF, 
	/*DataType*/	MAKELONG(2,0), 
	},
	{	/*EPLClient_GetExtensionResource*/ 
	/*name*/	_WT("扩展程序"), 
	/*explain*/	_WT(""), 
	/*state*/	EAS_BY_REF, 
	/*DataType*/	MAKELONG(15,0), 
	},
	{	/*EPLClient_GetExtensionResource*/ 
	/*name*/	_WT("浏览器"), 
	/*explain*/	_WT(""), 
	/*state*/	EAS_BY_REF, 
	/*DataType*/	MAKELONG(4,0), 
	},
	{	/*EPLClient_GetExtensionResource*/ 
	/*name*/	_WT("资源文件名"), 
	/*explain*/	_WT("扩展程序将欲搜索并加载的资源文件名称,相对路径"), 
	/*state*/	NULL, 
	/*DataType*/	SDT_TEXT, 
	},
	{	/*EPLClient_GetExtensionResource*/ 
	/*name*/	_WT("资源获取回调"), 
	/*explain*/	_WT("如果要处理资源请求, 使用此回调接口向扩展程序返回资源获取结果。"), 
	/*state*/	EAS_BY_REF, 
	/*DataType*/	MAKELONG(18,0), 
	},
	{	/*EPLClient_OnQuery*/ 
	/*name*/	_WT("浏览器"), 
	/*explain*/	_WT("表示查询的浏览器来源"), 
	/*state*/	EAS_BY_REF, 
	/*DataType*/	MAKELONG(4,0), 
	},
	{	/*EPLClient_OnQuery*/ 
	/*name*/	_WT("框架"), 
	/*explain*/	_WT("表示查询的框架来源"), 
	/*state*/	EAS_BY_REF, 
	/*DataType*/	MAKELONG(17,0), 
	},
	{	/*EPLClient_OnQuery*/ 
	/*name*/	_WT("查询ID"), 
	/*explain*/	_WT("表示查询的唯一标识符, 用于路由传递时的生命周期查询。"), 
	/*state*/	NULL, 
	/*DataType*/	SDT_INT64, 
	},
	{	/*EPLClient_OnQuery*/ 
	/*name*/	_WT("请求"), 
	/*explain*/	_WT("查询请求"), 
	/*state*/	NULL, 
	/*DataType*/	SDT_TEXT, 
	},
	{	/*EPLClient_OnQuery*/ 
	/*name*/	_WT("持久性"), 
	/*explain*/	_WT(""), 
	/*state*/	NULL, 
	/*DataType*/	SDT_BOOL, 
	},
	{	/*EPLClient_OnQuery*/ 
	/*name*/	_WT("查询结果"), 
	/*explain*/	_WT("用于返回向 Javascript 返回查询执行结果。"), 
	/*state*/	EAS_BY_REF, 
	/*DataType*/	MAKELONG(23,0), 
	},
	{	/*EPLClient_OnQueryCanceled*/ 
	/*name*/	_WT("浏览器"), 
	/*explain*/	_WT("表示查询的浏览器来源"), 
	/*state*/	EAS_BY_REF, 
	/*DataType*/	MAKELONG(4,0), 
	},
	{	/*EPLClient_OnQueryCanceled*/ 
	/*name*/	_WT("框架"), 
	/*explain*/	_WT("表示查询的框架来源"), 
	/*state*/	EAS_BY_REF, 
	/*DataType*/	MAKELONG(17,0), 
	},
	{	/*EPLClient_OnQueryCanceled*/ 
	/*name*/	_WT("查询ID"), 
	/*explain*/	_WT("表示查询的唯一标识符, 用于路由传递时的生命周期查询。"), 
	/*state*/	NULL, 
	/*DataType*/	SDT_INT64, 
	},

};


EVENT_INFO2 s_ChromiumEvent [] = 
{
	{
	/*szName*/	_WT("进程即将初始化"),
	/*szExplain*/	_WT("浏览器进程上下文环境将要初始化时调用此事件。在此事件中浏览器进程提供了一次查看或者修改命令行参数的机会。"),
	/*dwState*/	EV_IS_VER2,
	/*nArgCount*/	2,
	/*pBeginArgInfo*/	&s_ChromiumEventArgInfo[0],
	/*nRet*/	_SDT_NULL,
	},
	{
	/*szName*/	_WT("进程初始化完毕"),
	/*szExplain*/	_WT("浏览器进程上下文初始化完毕后调用此事件。"),
	/*dwState*/	EV_IS_VER2,
	/*nArgCount*/	0,
	/*pBeginArgInfo*/	&s_ChromiumEventArgInfo[2],
	/*nRet*/	_SDT_NULL,
	},
	{
	/*szName*/	_WT("子进程即将启动"),
	/*szExplain*/	_WT("在启动子进程前调用此事件。"),
	/*dwState*/	EV_IS_VER2,
	/*nArgCount*/	1,
	/*pBeginArgInfo*/	&s_ChromiumEventArgInfo[2],
	/*nRet*/	_SDT_NULL,
	},
	{
	/*szName*/	_WT("渲染进程线程已创建"),
	/*szExplain*/	_WT("在为新的渲染过程创建主线程后调用此事件。这将提供一次机会用于为渲染过程提供额外的信息。"),
	/*dwState*/	EV_IS_VER2,
	/*nArgCount*/	1,
	/*pBeginArgInfo*/	&s_ChromiumEventArgInfo[3],
	/*nRet*/	_SDT_NULL,
	},
	{
	/*szName*/	_WT("浏览器将要打开"),
	/*szExplain*/	_WT("浏览器即将创建新的窗口前调用此事件, 如果不希望浏览器继续创建该窗口则应在此事件中返回真以促使浏览器取消创建过程, 如未设置返回值则浏览器将会默认继续执行该项操作。"),
	/*dwState*/	EV_IS_VER2,
	/*nArgCount*/	9,
	/*pBeginArgInfo*/	&s_ChromiumEventArgInfo[4],
	/*nRet*/	SDT_BOOL,
	},
	{
	/*szName*/	_WT("浏览器创建完毕"),
	/*szExplain*/	_WT("在创建新的浏览器后调用此事件, 这个事件是在浏览器创建后的第一个调用的事件。"),
	/*dwState*/	EV_IS_VER2,
	/*nArgCount*/	1,
	/*pBeginArgInfo*/	&s_ChromiumEventArgInfo[13],
	/*nRet*/	_SDT_NULL,
	},
	{
	/*szName*/	_WT("浏览器即将销毁"),
	/*szExplain*/	_WT("在浏览器被销毁之前调用此事件, 这个事件返回后浏览器将会释放所有对该对象的引用, 所以请不要在此事件之后尝试对再对该对象执行任何方法, 这个世界是该浏览器对象的最后一个调用事件。"),
	/*dwState*/	EV_IS_VER2,
	/*nArgCount*/	1,
	/*pBeginArgInfo*/	&s_ChromiumEventArgInfo[14],
	/*nRet*/	_SDT_NULL,
	},
	{
	/*szName*/	_WT("浏览器将要关闭"),
	/*szExplain*/	_WT("对于浏览器的关闭, 其关闭事件来源于它的关闭浏览器方法或是其父窗口接受了用户的关闭请求(用户点击了X按钮)。在此事件中如果不希望浏览器被立即关闭返回真, 以取消关闭请求。"),
	/*dwState*/	EV_IS_VER2,
	/*nArgCount*/	1,
	/*pBeginArgInfo*/	&s_ChromiumEventArgInfo[15],
	/*nRet*/	SDT_BOOL,
	},
	{
	/*szName*/	_WT("浏览器加载状态已改变"),
	/*szExplain*/	_WT("当浏览器加载状态更改时调用此事件。该事件通常将会被调用两次, 一次由通过用户操作启动, 另一次则由完成或者终止加载触发。该事件将会早于事件\"开始加载\"调用, 并在加载完成或终止时在\"加载完毕\" 或 \"加载失败\"事件之后调用。"),
	/*dwState*/	EV_IS_VER2,
	/*nArgCount*/	4,
	/*pBeginArgInfo*/	&s_ChromiumEventArgInfo[16],
	/*nRet*/	_SDT_NULL,
	},
	{
	/*szName*/	_WT("浏览器开始加载"),
	/*szExplain*/	_WT("在导航请求被提交后将会调用此事件。该事件可能会在所有框架发生导航变更后多次调用。"),
	/*dwState*/	EV_IS_VER2,
	/*nArgCount*/	3,
	/*pBeginArgInfo*/	&s_ChromiumEventArgInfo[20],
	/*nRet*/	_SDT_NULL,
	},
	{
	/*szName*/	_WT("浏览器加载完毕"),
	/*szExplain*/	_WT("当浏览器完成加载框架时调用此事件。如果当前页面中存在多个框架, 则该事件会被多次调用。"),
	/*dwState*/	EV_IS_VER2,
	/*nArgCount*/	3,
	/*pBeginArgInfo*/	&s_ChromiumEventArgInfo[23],
	/*nRet*/	_SDT_NULL,
	},
	{
	/*szName*/	_WT("浏览器加载失败"),
	/*szExplain*/	_WT("在浏览器加载页面失败或者执行被取消后调用此事件。"),
	/*dwState*/	EV_IS_VER2,
	/*nArgCount*/	5,
	/*pBeginArgInfo*/	&s_ChromiumEventArgInfo[26],
	/*nRet*/	_SDT_NULL,
	},
	{
	/*szName*/	_WT("浏览器菜单即将打开"),
	/*szExplain*/	_WT("显示上下文菜单前调用此事件。"),
	/*dwState*/	EV_IS_VER2,
	/*nArgCount*/	4,
	/*pBeginArgInfo*/	&s_ChromiumEventArgInfo[31],
	/*nRet*/	_SDT_NULL,
	},
	{
	/*szName*/	_WT("浏览器显示自定义菜单"),
	/*szExplain*/	_WT("显示上下文菜单前调用此事件, 如果需要显示自定义菜单返回真。否则返回假以显示系统默认菜单。"),
	/*dwState*/	EV_IS_VER2,
	/*nArgCount*/	5,
	/*pBeginArgInfo*/	&s_ChromiumEventArgInfo[35],
	/*nRet*/	SDT_BOOL,
	},
	{
	/*szName*/	_WT("浏览器菜单项被选择"),
	/*szExplain*/	_WT("执行菜单命令时调用此事件。如果菜单命令已处理返回真, 否则返回假交由系统处理。"),
	/*dwState*/	EV_IS_VER2,
	/*nArgCount*/	5,
	/*pBeginArgInfo*/	&s_ChromiumEventArgInfo[40],
	/*nRet*/	SDT_BOOL,
	},
	{
	/*szName*/	_WT("浏览器菜单即将关闭"),
	/*szExplain*/	_WT("关闭菜单前调用此事件, 无论菜单是否被选择或者取消都将会发生此事件。"),
	/*dwState*/	EV_IS_VER2,
	/*nArgCount*/	2,
	/*pBeginArgInfo*/	&s_ChromiumEventArgInfo[45],
	/*nRet*/	_SDT_NULL,
	},
	{
	/*szName*/	_WT("浏览器地址已改变"),
	/*szExplain*/	_WT("当浏览器框架地址更改时调用此事件。"),
	/*dwState*/	EV_IS_VER2,
	/*nArgCount*/	3,
	/*pBeginArgInfo*/	&s_ChromiumEventArgInfo[47],
	/*nRet*/	_SDT_NULL,
	},
	{
	/*szName*/	_WT("浏览器标题已改变"),
	/*szExplain*/	_WT("当浏览器页面标题变更时调用此事件。"),
	/*dwState*/	EV_IS_VER2,
	/*nArgCount*/	2,
	/*pBeginArgInfo*/	&s_ChromiumEventArgInfo[50],
	/*nRet*/	_SDT_NULL,
	},
	{
	/*szName*/	_WT("浏览器显示工具提示"),
	/*szExplain*/	_WT("在浏览器将显示工具提示时调用此事件, 如果需要将该提示信息放在您的自定义提示工具中显示则应当在此事件中返回真。"),
	/*dwState*/	EV_IS_VER2,
	/*nArgCount*/	2,
	/*pBeginArgInfo*/	&s_ChromiumEventArgInfo[52],
	/*nRet*/	SDT_BOOL,
	},
	{
	/*szName*/	_WT("浏览器状态消息"),
	/*szExplain*/	_WT("当浏览器收到状态消息时调用此事件。"),
	/*dwState*/	EV_IS_VER2,
	/*nArgCount*/	2,
	/*pBeginArgInfo*/	&s_ChromiumEventArgInfo[54],
	/*nRet*/	_SDT_NULL,
	},
	{
	/*szName*/	_WT("浏览器控制台消息"),
	/*szExplain*/	_WT("当浏览器收到控制台消息时调用此事件, 如果希望浏览器停止消息输出到控制台则应当返回真。"),
	/*dwState*/	EV_IS_VER2,
	/*nArgCount*/	5,
	/*pBeginArgInfo*/	&s_ChromiumEventArgInfo[56],
	/*nRet*/	SDT_BOOL,
	},
	{
	/*szName*/	_WT("浏览器加载进度已更新"),
	/*szExplain*/	_WT("当整体页面加载进度更改时调用此事件。"),
	/*dwState*/	EV_IS_VER2,
	/*nArgCount*/	2,
	/*pBeginArgInfo*/	&s_ChromiumEventArgInfo[61],
	/*nRet*/	_SDT_NULL,
	},
	{
	/*szName*/	_WT("浏览器全屏模式已改变"),
	/*szExplain*/	_WT("网页中的网页内容切换为全屏模式时调用此事件。"),
	/*dwState*/	EV_IS_VER2,
	/*nArgCount*/	2,
	/*pBeginArgInfo*/	&s_ChromiumEventArgInfo[63],
	/*nRet*/	_SDT_NULL,
	},
	{
	/*szName*/	_WT("浏览器脚本对话框将要打开"),
	/*szExplain*/	_WT("当浏览器接收到Javascript对话框调用时执行此事件。返回假使用系统默认对话框, 返回真使用自定义对话框。"),
	/*dwState*/	EV_IS_VER2,
	/*nArgCount*/	7,
	/*pBeginArgInfo*/	&s_ChromiumEventArgInfo[65],
	/*nRet*/	SDT_BOOL,
	},
	{
	/*szName*/	_WT("浏览器对话框页面刷新询问"),
	/*szExplain*/	_WT("弹出一个对话框, 询问用户是否要离开页面，如果希望使用自定义的对话框显示消息内容则应当在此事件中返回真。"),
	/*dwState*/	EV_IS_VER2,
	/*nArgCount*/	4,
	/*pBeginArgInfo*/	&s_ChromiumEventArgInfo[72],
	/*nRet*/	SDT_BOOL,
	},
	{
	/*szName*/	_WT("浏览器重置对话框状态"),
	/*szExplain*/	_WT("执行此事件以取消所有未决的对话框并重置所有保持的对话框状态。由于诸如页面导航之类的事件而将被调用, 而不管当前是否有任何对话框挂起。"),
	/*dwState*/	EV_IS_VER2,
	/*nArgCount*/	1,
	/*pBeginArgInfo*/	&s_ChromiumEventArgInfo[76],
	/*nRet*/	_SDT_NULL,
	},
	{
	/*szName*/	_WT("浏览器对话框关闭"),
	/*szExplain*/	_WT("当浏览器默认对话框被关闭时调用此事件。"),
	/*dwState*/	EV_IS_VER2,
	/*nArgCount*/	1,
	/*pBeginArgInfo*/	&s_ChromiumEventArgInfo[77],
	/*nRet*/	_SDT_NULL,
	},
	{
	/*szName*/	_WT("浏览器请求用户身份验证"),
	/*szExplain*/	_WT("当浏览器需要用户提供认证凭据时调用此事件, 如果希望浏览器继续执行该项请求则应当返回真, 并在此方法中或在后续获得身份验证信息之后调用认证回调接口。返回假立即取消该项请求。"),
	/*dwState*/	EV_IS_VER2,
	/*nArgCount*/	8,
	/*pBeginArgInfo*/	&s_ChromiumEventArgInfo[78],
	/*nRet*/	SDT_BOOL,
	},
	{
	/*szName*/	_WT("浏览器将要导航"),
	/*szExplain*/	_WT("浏览器将要导航之前调用此事件。返回真以取消导航, 返回假导航将继续进行。"),
	/*dwState*/	EV_IS_VER2,
	/*nArgCount*/	5,
	/*pBeginArgInfo*/	&s_ChromiumEventArgInfo[86],
	/*nRet*/	SDT_BOOL,
	},
	{
	/*szName*/	_WT("浏览器将要加载资源"),
	/*szExplain*/	_WT("浏览器加载资源之前调用此事件。通过返回枚举常量: #资源请求.* 中定义的值以决定浏览器是否取消或者继续该资源的请求。 "),
	/*dwState*/	EV_IS_VER2,
	/*nArgCount*/	3,
	/*pBeginArgInfo*/	&s_ChromiumEventArgInfo[91],
	/*nRet*/	SDT_INT,
	},
	{
	/*szName*/	_WT("浏览器资源重定向"),
	/*szExplain*/	_WT("浏览器重定向资源负载时调用此事件。"),
	/*dwState*/	EV_IS_VER2,
	/*nArgCount*/	5,
	/*pBeginArgInfo*/	&s_ChromiumEventArgInfo[94],
	/*nRet*/	_SDT_NULL,
	},
	{
	/*szName*/	_WT("浏览器资源请求收到响应"),
	/*szExplain*/	_WT("浏览器收到资源响应时调用此事件。若要允许资源加载而无需修改则应返回假, 要重定向或重试资源负载, 可以选择修改|请求|参数并返回真, 对请求URL的修改将被视为重定向。"),
	/*dwState*/	EV_IS_VER2,
	/*nArgCount*/	4,
	/*pBeginArgInfo*/	&s_ChromiumEventArgInfo[99],
	/*nRet*/	SDT_BOOL,
	},
	{
	/*szName*/	_WT("浏览器资源过滤器"),
	/*szExplain*/	_WT("提供此事件用以可选化的过滤资源响应内容。如果希望浏览器执行资源过滤器应当在此事件返回真, 并在事件\"浏览器资源过滤器已就绪\"中完成过滤设置, 如果返回假则请求资源将不经过过滤器而直接返回到浏览器。"),
	/*dwState*/	EV_IS_VER2,
	/*nArgCount*/	4,
	/*pBeginArgInfo*/	&s_ChromiumEventArgInfo[103],
	/*nRet*/	SDT_BOOL,
	},
	{
	/*szName*/	_WT("浏览器资源加载完毕"),
	/*szExplain*/	_WT("浏览器资源加载完成后调用此事件。所有的资源请求都会调用此事件, 包括印Chromium关闭或相关浏览器销毁而终止的请求。如果关联的浏览器被销毁, 则该事件可能在该浏览器的\"即将被销毁\"事件之后到达。对|框架|执行方法\"是否有效\"可以测试这种情况, 并且应注意不要调用\"取浏览器\"方法。"),
	/*dwState*/	EV_IS_VER2,
	/*nArgCount*/	6,
	/*pBeginArgInfo*/	&s_ChromiumEventArgInfo[107],
	/*nRet*/	_SDT_NULL,
	},
	{
	/*szName*/	_WT("浏览器将要打开文件对话框"),
	/*szExplain*/	_WT("浏览器运行文件选择对话框时调用此事件, 如果希望使用自定义的文件选择器对话框则应在此事件中返回真。"),
	/*dwState*/	EV_IS_VER2,
	/*nArgCount*/	7,
	/*pBeginArgInfo*/	&s_ChromiumEventArgInfo[113],
	/*nRet*/	SDT_BOOL,
	},
	{
	/*szName*/	_WT("浏览器即将下载"),
	/*szExplain*/	_WT("浏览器在下载开始之前调用此事件。默认请况下所有的下载都将被取消。执行|下载回调|接口可以使浏览器继续下载(如果需要)。"),
	/*dwState*/	EV_IS_VER2,
	/*nArgCount*/	3,
	/*pBeginArgInfo*/	&s_ChromiumEventArgInfo[120],
	/*nRet*/	_SDT_NULL,
	},
	{
	/*szName*/	_WT("浏览器下载进度已更新"),
	/*szExplain*/	_WT("当下载状态或进度信息已更新时调用此事件。该事件会在\"浏览器即将下载\"事件之后被多次调用。"),
	/*dwState*/	EV_IS_VER2,
	/*nArgCount*/	2,
	/*pBeginArgInfo*/	&s_ChromiumEventArgInfo[123],
	/*nRet*/	_SDT_NULL,
	},
	{
	/*szName*/	_WT("浏览器资源过滤器已就绪"),
	/*szExplain*/	_WT("该事件仅在启用资源过滤器后才会发生, 资源过滤器初始化完毕时调用此事件。"),
	/*dwState*/	EV_IS_VER2,
	/*nArgCount*/	2,
	/*pBeginArgInfo*/	&s_ChromiumEventArgInfo[125],
	/*nRet*/	_SDT_NULL,
	},
	{
	/*szName*/	_WT("服务器启动就绪"),
	/*szExplain*/	_WT("服务器启动就绪时调用此事件。"),
	/*dwState*/	EV_IS_VER2,
	/*nArgCount*/	1,
	/*pBeginArgInfo*/	&s_ChromiumEventArgInfo[127],
	/*nRet*/	_SDT_NULL,
	},
	{
	/*szName*/	_WT("服务器停止运行"),
	/*szExplain*/	_WT("服务器停止运行时调用此事件"),
	/*dwState*/	EV_IS_VER2,
	/*nArgCount*/	1,
	/*pBeginArgInfo*/	&s_ChromiumEventArgInfo[128],
	/*nRet*/	_SDT_NULL,
	},
	{
	/*szName*/	_WT("服务器客户进入"),
	/*szExplain*/	_WT("收到客户端连接时调用此事件。"),
	/*dwState*/	EV_IS_VER2,
	/*nArgCount*/	2,
	/*pBeginArgInfo*/	&s_ChromiumEventArgInfo[129],
	/*nRet*/	_SDT_NULL,
	},
	{
	/*szName*/	_WT("服务器客户离开"),
	/*szExplain*/	_WT("客户端与服务器断开连接时调用此事件。"),
	/*dwState*/	EV_IS_VER2,
	/*nArgCount*/	2,
	/*pBeginArgInfo*/	&s_ChromiumEventArgInfo[131],
	/*nRet*/	_SDT_NULL,
	},
	{
	/*szName*/	_WT("服务器收到请求"),
	/*szExplain*/	_WT("服务器收到一个HTTP请求时调用此事件。"),
	/*dwState*/	EV_IS_VER2,
	/*nArgCount*/	4,
	/*pBeginArgInfo*/	&s_ChromiumEventArgInfo[133],
	/*nRet*/	_SDT_NULL,
	},
	{
	/*szName*/	_WT("服务器收到套接字请求"),
	/*szExplain*/	_WT("服务器收到一个WebSocket请求时调用此事件。返回真允许客户连接套接字(Websocket)连接, 返回假忽略此请求。"),
	/*dwState*/	EV_IS_VER2,
	/*nArgCount*/	4,
	/*pBeginArgInfo*/	&s_ChromiumEventArgInfo[137],
	/*nRet*/	SDT_BOOL,
	},
	{
	/*szName*/	_WT("服务器套接字已连接"),
	/*szExplain*/	_WT("接受客户端Websocket连接后调用此事件。"),
	/*dwState*/	EV_IS_VER2,
	/*nArgCount*/	2,
	/*pBeginArgInfo*/	&s_ChromiumEventArgInfo[141],
	/*nRet*/	_SDT_NULL,
	},
	{
	/*szName*/	_WT("服务器收到套接字消息"),
	/*szExplain*/	_WT("服务器收到Websocket消息时调用此事件。"),
	/*dwState*/	EV_IS_VER2,
	/*nArgCount*/	4,
	/*pBeginArgInfo*/	&s_ChromiumEventArgInfo[143],
	/*nRet*/	_SDT_NULL,
	},
	{
	/*szName*/	_WT("网页套接字连接成功"),
	/*szExplain*/	_WT("成功连接到服务器时调用此事件。"),
	/*dwState*/	EV_IS_VER2,
	/*nArgCount*/	1,
	/*pBeginArgInfo*/	&s_ChromiumEventArgInfo[147],
	/*nRet*/	_SDT_NULL,
	},
	{
	/*szName*/	_WT("网页套接字连接断开"),
	/*szExplain*/	_WT("已断开与服务器的连接时调用此事件。"),
	/*dwState*/	EV_IS_VER2,
	/*nArgCount*/	1,
	/*pBeginArgInfo*/	&s_ChromiumEventArgInfo[148],
	/*nRet*/	_SDT_NULL,
	},
	{
	/*szName*/	_WT("网页套接字数据到达"),
	/*szExplain*/	_WT("接收到服务器数据时调用此事件。"),
	/*dwState*/	EV_IS_VER2,
	/*nArgCount*/	3,
	/*pBeginArgInfo*/	&s_ChromiumEventArgInfo[149],
	/*nRet*/	_SDT_NULL,
	},
	{
	/*szName*/	_WT("网页套接字连接错误"),
	/*szExplain*/	_WT("网页套接字连接产生错误时调用此事件。"),
	/*dwState*/	EV_IS_VER2,
	/*nArgCount*/	2,
	/*pBeginArgInfo*/	&s_ChromiumEventArgInfo[152],
	/*nRet*/	_SDT_NULL,
	},
	{
	/*szName*/	_WT("扩展程序载入失败"),
	/*szExplain*/	_WT("调用函数 水星浏览器.载入扩展程序() 请求失败时执行此事件。"),
	/*dwState*/	EV_IS_VER2,
	/*nArgCount*/	1,
	/*pBeginArgInfo*/	&s_ChromiumEventArgInfo[154],
	/*nRet*/	_SDT_NULL,
	},
	{
	/*szName*/	_WT("扩展程序载入完毕"),
	/*szExplain*/	_WT("如果调用函数 水星浏览器.载入扩展程序() 请求成功时执行此事件。"),
	/*dwState*/	EV_IS_VER2,
	/*nArgCount*/	1,
	/*pBeginArgInfo*/	&s_ChromiumEventArgInfo[155],
	/*nRet*/	_SDT_NULL,
	},
	{
	/*szName*/	_WT("扩展程序已卸载"),
	/*szExplain*/	_WT("调用函数 水星扩展程序.卸载() 请求成功时执行此事件。"),
	/*dwState*/	EV_IS_VER2,
	/*nArgCount*/	1,
	/*pBeginArgInfo*/	&s_ChromiumEventArgInfo[156],
	/*nRet*/	_SDT_NULL,
	},
	{
	/*szName*/	_WT("扩展程序托管脚本"),
	/*szExplain*/	_WT("当扩展程序需要浏览器来托管后台脚本运行时调用此事件。取消后台脚本的加载以及浏览器的创建返回真, 返回假则允许创建浏览器并运行脚本。"),
	/*dwState*/	EV_IS_VER2,
	/*nArgCount*/	2,
	/*pBeginArgInfo*/	&s_ChromiumEventArgInfo[157],
	/*nRet*/	SDT_BOOL,
	},
	{
	/*szName*/	_WT("扩展程序将要打开"),
	/*szExplain*/	_WT("当扩展程序API(例如: chrome.tabs.create)请求创建一个新的浏览器时调用此事件。取消浏览器的创建返回真, 返回假则允许创建此浏览器。"),
	/*dwState*/	EV_IS_VER2,
	/*nArgCount*/	7,
	/*pBeginArgInfo*/	&s_ChromiumEventArgInfo[159],
	/*nRet*/	SDT_BOOL,
	},
	{
	/*szName*/	_WT("扩展程序关联浏览器"),
	/*szExplain*/	_WT("当tabId与|目标浏览器|关联时调用此事件以指定给接受tabId参数的扩展程序API调用(例如: chrome.tabs.* )。允许扩展程序访问浏览器返回真, 取消访问返回假。"),
	/*dwState*/	EV_IS_VER2,
	/*nArgCount*/	4,
	/*pBeginArgInfo*/	&s_ChromiumEventArgInfo[166],
	/*nRet*/	SDT_BOOL,
	},
	{
	/*szName*/	_WT("扩展程序取活动浏览器"),
	/*szExplain*/	_WT("为未接受tabId参数的扩展API调用指定tabId时调用(例如, chrome.tabs.*)。"),
	/*dwState*/	EV_IS_VER2,
	/*nArgCount*/	4,
	/*pBeginArgInfo*/	&s_ChromiumEventArgInfo[170],
	/*nRet*/	_SDT_NULL,
	},
	{
	/*szName*/	_WT("扩展程序获取资源事件"),
	/*szExplain*/	_WT("扩展程序调用此事件从磁盘搜索并加载扩展资源(例如, 如果将文件参数指定为chrome.tabs.executeScript)。要处理资源请求请返回真并执行|资源获取回调|参数方法向扩展程序提交获取结果。"),
	/*dwState*/	EV_IS_VER2,
	/*nArgCount*/	4,
	/*pBeginArgInfo*/	&s_ChromiumEventArgInfo[174],
	/*nRet*/	SDT_BOOL,
	},
	{
	/*szName*/	_WT("脚本收到查询"),
	/*szExplain*/	_WT("收到新的 Javascript 查询时执行此事件。返回真表示查询已被处理, 返回假查询将会被传递至其它已注册的处理例程(如果有)。如果没有处理程序从此事件中返回真, 查询将会被取消, 并向Javascript onFailure 回调传递错误代码-1。如果此返回返回真必须执行异步参数回调|查询结果|以返回查询结果。"),
	/*dwState*/	EV_IS_VER2,
	/*nArgCount*/	6,
	/*pBeginArgInfo*/	&s_ChromiumEventArgInfo[178],
	/*nRet*/	SDT_BOOL,
	},
	{
	/*szName*/	_WT("脚本查询已取消"),
	/*szExplain*/	_WT("使用 Javascript 取消功能显示的取消了查询或由于浏览器被销毁, 发生导航或Renderer进程终止而隐式取消查询时调用此事件。调用此方法后, 不应在保留与查询关联的回调接口对象, 也不应在执行回调中的任何接口。"),
	/*dwState*/	EV_IS_VER2,
	/*nArgCount*/	3,
	/*pBeginArgInfo*/	&s_ChromiumEventArgInfo[184],
	/*nRet*/	_SDT_NULL,
	},

};

#ifndef __E_STATIC_LIB

static LIB_DATA_TYPE_ELEMENT s_dtDataElemnet[]={
	{
		/*m_dtType*/            SDT_INT,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("内部指针"),
        /*m_szEgName*/          _T("InternalPointer"),
        /*m_szExplain*/         _T("存放对象的指针"),
        /*m_dwState*/           LES_HIDED,
        /*m_nDefault*/          0
    }
};

INT s_nChromiumElementCmdIndex[]={
	0,1,2,3,4,5,6,7,
};

INT s_nProxyActiveBrowserCallbackElementCmdIndex[]={
	8,9,10,11,
};

INT s_nProxyAuthCallbackElementCmdIndex[]={
	12,13,14,15,16,
};

INT s_nProxyBaseElementCmdIndex[]={
	17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,
};

INT s_nProxyBrowserElementCmdIndex[]={
	48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,96,97,98,99,100,101,102,103,104,105,106,107,108,109,110,111,112,113,114,115,116,117,
};

INT s_nProxyBrowserSettingsElementCmdIndex[]={
	118,119,120,121,122,123,124,125,126,127,128,129,130,131,132,133,134,135,136,137,138,139,140,141,142,143,144,145,146,147,148,149,150,151,
};

INT s_nProxyCollectionElementCmdIndex[]={
	152,153,154,155,156,157,158,159,160,
};

INT s_nProxyCommandLineElementCmdIndex[]={
	161,162,163,164,165,166,167,168,169,170,171,172,173,174,175,176,177,
};

INT s_nProxyContextMenuParamsElementCmdIndex[]={
	178,179,180,181,182,183,184,185,186,187,188,189,190,191,192,193,194,195,196,197,198,199,200,201,
};

INT s_nProxyCookieElementCmdIndex[]={
	202,203,204,205,206,207,208,209,210,211,212,213,214,215,216,217,218,219,220,221,222,223,224,225,
};

INT s_nProxyCookieManagerElementCmdIndex[]={
	226,227,228,229,230,231,232,233,234,235,236,237,
};

INT s_nProxyDictionaryValueElementCmdIndex[]={
	238,239,240,241,242,243,244,245,246,247,248,249,250,251,252,253,254,255,256,257,258,259,260,261,262,263,264,265,266,267,268,269,
};

INT s_nProxyDOMDocumentElementCmdIndex[]={
	270,271,272,273,274,275,276,277,278,279,280,281,282,283,284,285,286,287,288,289,
};

INT s_nProxyDOMNodeElementCmdIndex[]={
	290,291,292,293,294,295,296,297,298,299,300,301,302,303,304,305,306,307,308,309,310,311,312,313,314,315,316,317,318,319,320,321,322,323,
};

INT s_nProxyDownloadItemElementCmdIndex[]={
	324,325,326,327,328,329,330,331,332,333,334,335,336,337,338,339,340,341,342,343,344,345,346,347,
};

INT s_nProxyExtensionElementCmdIndex[]={
	348,349,350,351,352,353,354,355,356,357,
};

INT s_nProxyFileDialogCallbackElementCmdIndex[]={
	358,359,360,361,362,
};

INT s_nProxyFrameElementCmdIndex[]={
	363,364,365,366,367,368,369,370,371,372,373,374,375,376,377,378,379,380,381,382,383,384,385,386,387,388,389,390,391,392,393,
};

INT s_nProxyGetExtensionResourceCallbackElementCmdIndex[]={
	394,395,396,397,398,399,
};

INT s_nProxyJSDialogCallbackElementCmdIndex[]={
	400,401,402,403,
};

INT s_nProxyListValueElementCmdIndex[]={
	404,405,406,407,408,409,410,411,412,413,414,415,416,417,418,419,420,421,422,423,424,425,426,427,428,429,430,431,432,433,434,
};

INT s_nProxyMenuModelElementCmdIndex[]={
	435,436,437,438,439,440,441,442,443,444,445,446,447,448,449,450,451,452,453,454,455,456,457,458,459,460,461,462,463,464,465,466,467,468,469,470,471,472,473,474,475,476,477,478,479,480,481,482,483,484,485,486,487,488,489,
};

INT s_nProxyPostDataElementElementCmdIndex[]={
	490,491,492,493,494,495,496,497,498,499,500,501,
};

INT s_nProxyQueryCallbackElementCmdIndex[]={
	502,503,504,505,506,
};

INT s_nProxyRequestElementCmdIndex[]={
	507,508,509,510,511,512,513,514,515,516,517,518,519,520,521,522,523,524,525,526,527,528,529,530,531,532,533,534,
};

INT s_nProxyResponseElementCmdIndex[]={
	535,536,537,538,539,540,541,542,543,544,545,546,547,548,549,550,551,552,553,554,555,
};

INT s_nProxyResponseFilterElementCmdIndex[]={
	556,557,558,559,560,561,562,563,564,
};

INT s_nProxyRunContextMenuCallbackElementCmdIndex[]={
	565,566,567,568,569,
};

INT s_nProxyServerElementCmdIndex[]={
	570,571,572,573,574,575,576,577,578,579,580,581,582,583,584,
};

INT s_nProxySettingsElementCmdIndex[]={
	585,586,587,588,589,590,591,592,593,594,595,596,597,
};

INT s_nProxyURLRequestElementCmdIndex[]={
	598,599,600,601,602,603,604,605,606,607,608,609,
};

INT s_nProxyValueElementCmdIndex[]={
	610,611,612,613,614,615,616,617,618,619,620,621,622,623,624,625,626,627,628,629,630,631,632,633,634,
};

INT s_nProxyWaitableEventElementCmdIndex[]={
	635,636,637,638,639,640,641,642,643,644,645,
};

INT s_nProxyWebSocketElementCmdIndex[]={
	646,647,648,649,650,651,652,653,654,655,656,657,
};

INT s_nProxyWindowInfoElementCmdIndex[]={
	658,659,660,661,662,663,
};



#endif

/////////////////////////////////////////////////////////////////////////////


#ifndef __E_STATIC_LIB

#include "tenum.h"


//导出符号
static const char* const g_CmdNames[] = 
{
DECL_DATA_TYPE_ProxyClient_FUN_NAMES
DECL_DATA_TYPE_ProxyActiveBrowserCallback_FUN_NAMES
DECL_DATA_TYPE_ProxyAuthCallback_FUN_NAMES
DECL_DATA_TYPE_ProxyBase_FUN_NAMES
DECL_DATA_TYPE_ProxyBrowser_FUN_NAMES
DECL_DATA_TYPE_ProxyBrowserSettings_FUN_NAMES
DECL_DATA_TYPE_ProxyCollection_FUN_NAMES
DECL_DATA_TYPE_ProxyCommandLine_FUN_NAMES
DECL_DATA_TYPE_ProxyContextMenuParams_FUN_NAMES
DECL_DATA_TYPE_ProxyCookie_FUN_NAMES
DECL_DATA_TYPE_ProxyCookieManager_FUN_NAMES
DECL_DATA_TYPE_ProxyDictionaryValue_FUN_NAMES
DECL_DATA_TYPE_ProxyDOMDocument_FUN_NAMES
DECL_DATA_TYPE_ProxyDOMNode_FUN_NAMES
DECL_DATA_TYPE_ProxyDownloadItem_FUN_NAMES
DECL_DATA_TYPE_ProxyExtension_FUN_NAMES
DECL_DATA_TYPE_ProxyFileDialogCallback_FUN_NAMES
DECL_DATA_TYPE_ProxyFrame_FUN_NAMES
DECL_DATA_TYPE_ProxyGetExtensionResourceCallback_FUN_NAMES
DECL_DATA_TYPE_ProxyJSDialogCallback_FUN_NAMES
DECL_DATA_TYPE_ProxyListValue_FUN_NAMES
DECL_DATA_TYPE_ProxyMenuModel_FUN_NAMES
DECL_DATA_TYPE_ProxyPostDataElement_FUN_NAMES
DECL_DATA_TYPE_ProxyQueryCallback_FUN_NAMES
DECL_DATA_TYPE_ProxyRequest_FUN_NAMES
DECL_DATA_TYPE_ProxyResponse_FUN_NAMES
DECL_DATA_TYPE_ProxyResponseFilter_FUN_NAMES
DECL_DATA_TYPE_ProxyRunContextMenuCallback_FUN_NAMES
DECL_DATA_TYPE_ProxyServer_FUN_NAMES
DECL_DATA_TYPE_ProxySettings_FUN_NAMES
DECL_DATA_TYPE_ProxyURLRequest_FUN_NAMES
DECL_DATA_TYPE_ProxyValue_FUN_NAMES
DECL_DATA_TYPE_ProxyWaitableEvent_FUN_NAMES
DECL_DATA_TYPE_ProxyWebSocket_FUN_NAMES
DECL_DATA_TYPE_ProxyWindowInfo_FUN_NAMES

};


//导出函数
PFN_EXECUTE_CMD s_RunFunc [] =	
{
DECL_DATA_TYPE_ProxyClient_FUN_CALLS
DECL_DATA_TYPE_ProxyActiveBrowserCallback_FUN_CALLS
DECL_DATA_TYPE_ProxyAuthCallback_FUN_CALLS
DECL_DATA_TYPE_ProxyBase_FUN_CALLS
DECL_DATA_TYPE_ProxyBrowser_FUN_CALLS
DECL_DATA_TYPE_ProxyBrowserSettings_FUN_CALLS
DECL_DATA_TYPE_ProxyCollection_FUN_CALLS
DECL_DATA_TYPE_ProxyCommandLine_FUN_CALLS
DECL_DATA_TYPE_ProxyContextMenuParams_FUN_CALLS
DECL_DATA_TYPE_ProxyCookie_FUN_CALLS
DECL_DATA_TYPE_ProxyCookieManager_FUN_CALLS
DECL_DATA_TYPE_ProxyDictionaryValue_FUN_CALLS
DECL_DATA_TYPE_ProxyDOMDocument_FUN_CALLS
DECL_DATA_TYPE_ProxyDOMNode_FUN_CALLS
DECL_DATA_TYPE_ProxyDownloadItem_FUN_CALLS
DECL_DATA_TYPE_ProxyExtension_FUN_CALLS
DECL_DATA_TYPE_ProxyFileDialogCallback_FUN_CALLS
DECL_DATA_TYPE_ProxyFrame_FUN_CALLS
DECL_DATA_TYPE_ProxyGetExtensionResourceCallback_FUN_CALLS
DECL_DATA_TYPE_ProxyJSDialogCallback_FUN_CALLS
DECL_DATA_TYPE_ProxyListValue_FUN_CALLS
DECL_DATA_TYPE_ProxyMenuModel_FUN_CALLS
DECL_DATA_TYPE_ProxyPostDataElement_FUN_CALLS
DECL_DATA_TYPE_ProxyQueryCallback_FUN_CALLS
DECL_DATA_TYPE_ProxyRequest_FUN_CALLS
DECL_DATA_TYPE_ProxyResponse_FUN_CALLS
DECL_DATA_TYPE_ProxyResponseFilter_FUN_CALLS
DECL_DATA_TYPE_ProxyRunContextMenuCallback_FUN_CALLS
DECL_DATA_TYPE_ProxyServer_FUN_CALLS
DECL_DATA_TYPE_ProxySettings_FUN_CALLS
DECL_DATA_TYPE_ProxyURLRequest_FUN_CALLS
DECL_DATA_TYPE_ProxyValue_FUN_CALLS
DECL_DATA_TYPE_ProxyWaitableEvent_FUN_CALLS
DECL_DATA_TYPE_ProxyWebSocket_FUN_CALLS
DECL_DATA_TYPE_ProxyWindowInfo_FUN_CALLS

};


//导出参数签名
ARG_INFO s_ArgInfo[] = 
{
DECL_DATA_TYPE_ProxyClient_ARGINFO
DECL_DATA_TYPE_ProxyActiveBrowserCallback_ARGINFO
DECL_DATA_TYPE_ProxyAuthCallback_ARGINFO
DECL_DATA_TYPE_ProxyBase_ARGINFO
DECL_DATA_TYPE_ProxyBrowser_ARGINFO
DECL_DATA_TYPE_ProxyBrowserSettings_ARGINFO
DECL_DATA_TYPE_ProxyCollection_ARGINFO
DECL_DATA_TYPE_ProxyCommandLine_ARGINFO
DECL_DATA_TYPE_ProxyContextMenuParams_ARGINFO
DECL_DATA_TYPE_ProxyCookie_ARGINFO
DECL_DATA_TYPE_ProxyCookieManager_ARGINFO
DECL_DATA_TYPE_ProxyDictionaryValue_ARGINFO
DECL_DATA_TYPE_ProxyDOMDocument_ARGINFO
DECL_DATA_TYPE_ProxyDOMNode_ARGINFO
DECL_DATA_TYPE_ProxyDownloadItem_ARGINFO
DECL_DATA_TYPE_ProxyExtension_ARGINFO
DECL_DATA_TYPE_ProxyFileDialogCallback_ARGINFO
DECL_DATA_TYPE_ProxyFrame_ARGINFO
DECL_DATA_TYPE_ProxyGetExtensionResourceCallback_ARGINFO
DECL_DATA_TYPE_ProxyJSDialogCallback_ARGINFO
DECL_DATA_TYPE_ProxyListValue_ARGINFO
DECL_DATA_TYPE_ProxyMenuModel_ARGINFO
DECL_DATA_TYPE_ProxyPostDataElement_ARGINFO
DECL_DATA_TYPE_ProxyQueryCallback_ARGINFO
DECL_DATA_TYPE_ProxyRequest_ARGINFO
DECL_DATA_TYPE_ProxyResponse_ARGINFO
DECL_DATA_TYPE_ProxyResponseFilter_ARGINFO
DECL_DATA_TYPE_ProxyRunContextMenuCallback_ARGINFO
DECL_DATA_TYPE_ProxyServer_ARGINFO
DECL_DATA_TYPE_ProxySettings_ARGINFO
DECL_DATA_TYPE_ProxyURLRequest_ARGINFO
DECL_DATA_TYPE_ProxyValue_ARGINFO
DECL_DATA_TYPE_ProxyWaitableEvent_ARGINFO
DECL_DATA_TYPE_ProxyWebSocket_ARGINFO
DECL_DATA_TYPE_ProxyWindowInfo_ARGINFO

};

//导出函数签名
static CMD_INFO s_CmdInfo[] = 
{
DECL_DATA_TYPE_ProxyClient_CMDINFO(0)
DECL_DATA_TYPE_ProxyActiveBrowserCallback_CMDINFO(12)
DECL_DATA_TYPE_ProxyAuthCallback_CMDINFO(13)
DECL_DATA_TYPE_ProxyBase_CMDINFO(15)
DECL_DATA_TYPE_ProxyBrowser_CMDINFO(55)
DECL_DATA_TYPE_ProxyBrowserSettings_CMDINFO(127)
DECL_DATA_TYPE_ProxyCollection_CMDINFO(157)
DECL_DATA_TYPE_ProxyCommandLine_CMDINFO(161)
DECL_DATA_TYPE_ProxyContextMenuParams_CMDINFO(168)
DECL_DATA_TYPE_ProxyCookie_CMDINFO(168)
DECL_DATA_TYPE_ProxyCookieManager_CMDINFO(178)
DECL_DATA_TYPE_ProxyDictionaryValue_CMDINFO(188)
DECL_DATA_TYPE_ProxyDOMDocument_CMDINFO(220)
DECL_DATA_TYPE_ProxyDOMNode_CMDINFO(224)
DECL_DATA_TYPE_ProxyDownloadItem_CMDINFO(233)
DECL_DATA_TYPE_ProxyExtension_CMDINFO(235)
DECL_DATA_TYPE_ProxyFileDialogCallback_CMDINFO(236)
DECL_DATA_TYPE_ProxyFrame_CMDINFO(238)
DECL_DATA_TYPE_ProxyGetExtensionResourceCallback_CMDINFO(278)
DECL_DATA_TYPE_ProxyJSDialogCallback_CMDINFO(281)
DECL_DATA_TYPE_ProxyListValue_CMDINFO(283)
DECL_DATA_TYPE_ProxyMenuModel_CMDINFO(314)
DECL_DATA_TYPE_ProxyPostDataElement_CMDINFO(401)
DECL_DATA_TYPE_ProxyQueryCallback_CMDINFO(404)
DECL_DATA_TYPE_ProxyRequest_CMDINFO(407)
DECL_DATA_TYPE_ProxyResponse_CMDINFO(420)
DECL_DATA_TYPE_ProxyResponseFilter_CMDINFO(431)
DECL_DATA_TYPE_ProxyRunContextMenuCallback_CMDINFO(433)
DECL_DATA_TYPE_ProxyServer_CMDINFO(435)
DECL_DATA_TYPE_ProxySettings_CMDINFO(455)
DECL_DATA_TYPE_ProxyURLRequest_CMDINFO(464)
DECL_DATA_TYPE_ProxyValue_CMDINFO(464)
DECL_DATA_TYPE_ProxyWaitableEvent_CMDINFO(474)
DECL_DATA_TYPE_ProxyWebSocket_CMDINFO(476)
DECL_DATA_TYPE_ProxyWindowInfo_CMDINFO(485)

};

//导出常量签名
LIB_CONST_INFO s_ConstInfo [] =
{
	NULL
};

//导出数据类型签名
static LIB_DATA_TYPE_INFO s_DataType[] = 
{
DATA_TYPE_AQUARIUS_UNIT
DECL_DATA_TYPE_ProxyActiveBrowserCallback
DECL_DATA_TYPE_ProxyAuthCallback
DECL_DATA_TYPE_ProxyBrowser
DECL_DATA_TYPE_ProxyBrowserSettings
DECL_DATA_TYPE_ProxyCollection
DECL_DATA_TYPE_ProxyCommandLine
DECL_DATA_TYPE_ProxyContextMenuParams
DECL_DATA_TYPE_ProxyCookie
DECL_DATA_TYPE_ProxyCookieManager
DECL_DATA_TYPE_ProxyDictionaryValue
DECL_DATA_TYPE_ProxyDOMDocument
DECL_DATA_TYPE_ProxyDOMNode
DECL_DATA_TYPE_ProxyDownloadItem
DECL_DATA_TYPE_ProxyExtension
DECL_DATA_TYPE_ProxyFileDialogCallback
DECL_DATA_TYPE_ProxyFrame
DECL_DATA_TYPE_ProxyGetExtensionResourceCallback
DECL_DATA_TYPE_ProxyJSDialogCallback
DECL_DATA_TYPE_ProxyListValue
DECL_DATA_TYPE_ProxyMenuModel
DECL_DATA_TYPE_ProxyPostDataElement
DECL_DATA_TYPE_ProxyQueryCallback
DECL_DATA_TYPE_ProxyRequest
DECL_DATA_TYPE_ProxyResponse
DECL_DATA_TYPE_ProxyResponseFilter
DECL_DATA_TYPE_ProxyRunContextMenuCallback
DECL_DATA_TYPE_ProxyServer
DECL_DATA_TYPE_ProxySettings
DECL_DATA_TYPE_ProxyURLRequest
DECL_DATA_TYPE_ProxyValue
DECL_DATA_TYPE_ProxyWaitableEvent
DECL_DATA_TYPE_ProxyWebSocket
DECL_DATA_TYPE_ProxyWindowInfo

DATA_TYPE_ENUM_DEFINITION("点击事件","ClickEvent", ENUM_MOUSE_EVENT_EXPLAIN, s_ChromiumMouseEventEnumList)
DATA_TYPE_ENUM_DEFINITION("来源策略","ReferrerPolicy", ENUM_REFERRER_POLICY_EXPLAIN, s_RequestReferrerPolicyEnumList)
DATA_TYPE_ENUM_DEFINITION("资源类型","ResourceType", ENUM_RESOURCE_TYPE_EXPLAIN, s_ResourceTypeEnumList)
DATA_TYPE_ENUM_DEFINITION("脚本对话框","JavacriptDialogType", ENUM_JAVASCRIPTDIALOG_TYPE_EXPLAIN, s_JavaScriptDialogTypeEnumList)
DATA_TYPE_ENUM_DEFINITION("资源请求","ResourceRequest", ENUM_RESOURCE_RETVALUE_TYPE_EXPLAIN, s_ResourceRetValueEnumList)
DATA_TYPE_ENUM_DEFINITION("文件对话框模式","FileMode", ENUM_FILEMODE_TYPE_EXPLAIN, s_FileModeEnumList)
DATA_TYPE_ENUM_DEFINITION("事件标志","EventFlags", ENUM_EVENTFLAGS_EXPLAIN, s_EventFlagsEnumList)
DATA_TYPE_ENUM_DEFINITION("状态开关","StateSwitch", ENUM_COMMANDSWITCH_EXPLAIN, s_CommandSwitchEnumList)
DATA_TYPE_ENUM_DEFINITION("导航来源","TransitionType", ENUM_TRANSITION_TYPE_EXPLAIN, s_TransitionTypeEnumList)
DATA_TYPE_ENUM_DEFINITION("值类型","ValueType", ENUM_VALUE_TYPE_EXPLAIN, s_ValueTypeEnumList)
DATA_TYPE_ENUM_DEFINITION("链接打开方式","ValueType", ENUM_WINDOW_OPEN_DISPOSITION_EXPLAIN, s_WindowOpenDispositionEnumList)
DATA_TYPE_ENUM_DEFINITION("消息记录等级","MessageLevel", ENUM_MESSAGE_LEVEL_EXPLAIN, s_MessageLevelEnumList)
DATA_TYPE_ENUM_DEFINITION("系统内置菜单","SystemMenuId",ENUM_SYSTEM_MENU_ID_EXPLAIN,s_SystemMenuIdEnumList)
DATA_TYPE_ENUM_DEFINITION("属性拦截器","V8Interecptor", ENUM_V8_PROPERTY_ATTRI_EXPLAIN, s_V8PropertyAttriEnumList)
DATA_TYPE_ENUM_DEFINITION("键盘事件类型","KeyEventType", ENUM_KEY_EVENT_EXPLAIN, s_KeyEventEnumList)
DATA_TYPE_ENUM_DEFINITION("触点状态","TouchEventTYPE", ENUM_TOUCH_EVENT_TYPE_EXPLAIN, s_TouchEventTypeEnumList)
DATA_TYPE_ENUM_DEFINITION("设备指针类型","TouchPointType", ENUM_TOUCH_POINTER_TYPE_EXPLAIN, s_TouchPointerTypeEnumList)
DATA_TYPE_ENUM_DEFINITION("提交元素类型","PostDataElementType", ENUM_POST_DATA_ELEMENT_TYPE_EXPLAIN, s_PostDataElementTypeEnumList)
DATA_TYPE_ENUM_DEFINITION("转义规则","UriUnescapeRule", ENUM_POST_DATA_ELEMENT_TYPE_EXPLAIN, s_UriUnescapeRuleEnumList)
DATA_TYPE_ENUM_DEFINITION("请求状态","UrlRequestStatus", ENUM_URL_REQUEST_STATUS_EXPLAIN, s_UrlRequestStatusEnumList)
DATA_TYPE_ENUM_DEFINITION("套接字流类型","WebSocketDataType", ENUM_WEB_SOCKET_DATA_TYPE_EXPLAIN, s_WebSocketDataTypeEnumList)
DATA_TYPE_ENUM_DEFINITION("菜单类型","MenuType", ENUM_MENU_TYPE_EXPLAIN, s_MenuTypeEnumList)
DATA_TYPE_ENUM_DEFINITION("多媒体类型","MediaType", ENUM_MEDIA_TYPE_EXPLAIN, s_MediaTypeEnumList)
DATA_TYPE_ENUM_DEFINITION("网页文档类型","DocumentType","网页文档类型",s_DocumentTypeEnumList)
DATA_TYPE_ENUM_DEFINITION("网页元素类型","DocumentElementType","网页文档元素类型",s_DocumentElementTypeEnumList)
DATA_TYPE_ENUM_DEFINITION("手势输出源","GestureSourceType","指示生成何种类型的输入事件",s_GestureSourceTypeEnumList)
DATA_TYPE_ENUM_DEFINITION("触摸传感器配置","GestureProviderConfig","触摸传感器参数配置",s_GestureProviderConfigTypeEnumList)
DATA_TYPE_ENUM_DEFINITION("设备屏幕类型","DeviceScreenType","设备屏幕类型",s_DeviceScreenTypeEnumList)
DATA_TYPE_ENUM_DEFINITION("屏幕方向","ScreenOrientation","设备屏幕方向",s_ScreenOrientationTypeEnumList)
DATA_TYPE_ENUM_DEFINITION("请求标志","URLRequestFlags","URL请求标志设置值",s_URLRequestFlagsEnumList)
DATA_TYPE_ENUM_DEFINITION("请求传输类型","RequestTransitionType","请求传输类型",s_RequestTransitionTypeEnumList)
};

#endif

/////////////////////////////////////////////////////////////////////////////

EXTERN_C INT WINAPI EDITIONF(ProcessNotifyLib) (INT nMsg, DWORD dwParam1, DWORD dwParam2)
{
#ifndef __E_STATIC_LIB
	if(nMsg == NL_GET_CMD_FUNC_NAMES){
		return (INT) g_CmdNames;
	}
	else if(nMsg == NL_GET_NOTIFY_LIB_FUNC_NAME)
		return (INT) EDITIONS("ProcessNotifyLib");
	else if(nMsg == NL_GET_DEPENDENT_LIBS)
		return (INT)"aquarius2.lib\0\0";
#endif
	return ProcessNotifyLib(nMsg, dwParam1, dwParam2);
}

/////////////////////////////////////////////////////////////////////////////

#ifndef __E_STATIC_LIB
/////////////////////////////////////////////////////////////////////////////

//////////// 库定义开始
static LIB_INFO s_LibInfo =
{
/*Lib Format Ver*/		LIB_FORMAT_VER,		// 保留未用。

// 本支持库的GUID串：
// {369F969F-2DB0-42bc-86DF-23AE68BF0553}
#define		LI_LIB_GUID_STR	"369F969F2DB042bc86DF23AE68BF0553"
/*guid str*/			_WT (LI_LIB_GUID_STR),

/*m_nMajorVersion*/		2,
/*m_nMinorVersion*/		0,

//!!!	注意：凡是增删或更改了命令、窗口组件、数据类型、帮助信息等，只要对帮助
//!!! 文件生成会产生影响，都必须升级版本号，而不能只修改BuildNumber。
//!!!   改动后尽量升级版本号!!!
/*m_nBuildNumber*/		51,	// 1: 2.5;  2: 2.5补遗版; 3: 3.0版;  50: 3.39; 51: 4.11
		// 构建版本号，无需对此版本号作任何处理。
		//   本版本号仅用作区分相同正式版本号的库（譬如仅仅修改了几个 BUG）。
		// 任何公布过给用户使用的版本其此版本号都应该不一样。
		//   赋值时应该顺序递增。

/*m_nRqSysMajorVer*/		3,
/*m_nRqSysMinorVer*/		0,
/*m_nRqSysKrnlLibMajorVer*/	3,
/*m_nRqSysKrnlLibMinorVer*/	0,

/*name*/				_WT ("水星浏览器支持库"),
/*lang*/				__GBK_LANG_VER,
/*explain*/				_WT("本支持库提供了嵌入式Chromium浏览器支持。")
						_WT("本支持库基于CEF开发, CEF版本为: CEF 80.1.15 / Chromium 80.0.3987.163。")
                        _WT("获取支持库请访问: http://www.itwitch.cc/ecef/。")
                        _WT("本支持库需要操作系统: Win7 / Win2008 及以上,  32bit or 64bit。"),
/*dwState*/				NULL,

/*szAuthor*/	_WT("黑猫"),
/*szZipCode*/	_WT("10032"),
/*szAddress*/	_WT("欢迎加入水星讨论组: 89456201、649931225"),
/*szPhoto*/		_WT(""),
/*szFax*/		_WT(""),
/*szEmail*/		_WT("kirno17@hotmail.com"),
/*szHomePage*/	_WT("http://www.itwitch.cc/ecef/"),
/*szOther*/		_WT("祝您一帆风顺，心想事成！"),

/*type count*/			sizeof (s_DataType) / sizeof (s_DataType[0]),
/*PLIB_DATA_TYPE_INFO*/	s_DataType,

/*CategoryCount*/ 1,	// 加了类别需加此值。
/*category*/_WT("0000静态方法\0"	// 类别说明表每项为一字符串,前四位数字表示图象索引号(从1开始,0无).
				"\0"),
/*CmdCount*/				sizeof (s_CmdInfo) / sizeof (s_CmdInfo [0]),
/*BeginCmd*/				s_CmdInfo,
/*m_pCmdsFunc*/             s_RunFunc,
/*pfnRunAddInFn*/			AddInFunction,
/*szzAddInFnInfo*/			_WT("[水星] 发布应用程序\0导出浏览器运行时需要资源到安装程序目录。\0\0"),

/*pfnNotify*/				(PFN_NOTIFY_LIB)EDITIONF(ProcessNotifyLib),

/*pfnRunSuperTemplate*/		NULL,
/*szzSuperTemplateInfo*/	NULL,

/*nLibConstCount*/			0,//sizeof (s_ConstInfo) / sizeof (s_ConstInfo [0]),
/*pLibConst*/				NULL,//s_ConstInfo,

/*szzDependFiles*/			NULL,
};

PLIB_INFO WINAPI GetNewInf ()
{
	return &s_LibInfo;
}

#endif
