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
##{{0}}


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
##{{7}}
};


EVENT_INFO2 s_ChromiumEvent [] = 
{
##{{8}}
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

##{{6}}

#endif

/////////////////////////////////////////////////////////////////////////////


#ifndef __E_STATIC_LIB

#include "tenum.h"


//导出符号
static const char* const g_CmdNames[] = 
{
##{{1}}
};


//导出函数
PFN_EXECUTE_CMD s_RunFunc [] =	
{
##{{2}}
};


//导出参数签名
ARG_INFO s_ArgInfo[] = 
{
##{{3}}
};

//导出函数签名
static CMD_INFO s_CmdInfo[] = 
{
##{{4}}
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
##{{5}}
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
