#pragma once

#include "stdafx.h"
#include "lib2.h"


#define DECL_DATA_TYPE_ProxyBrowser \
	{ /*4*/ \
		/*m_szName*/		 _WT("Chromium浏览器"), \
		/*m_szEgName*/		 _WT("ProxyBrowser"), \
		/*m_szExplain*/		 _WT("用于表示浏览器窗口的类。在浏览器进程中使用时, 可以在任何线程上调用此类方法, 除非注释中另有说明。在渲染进程中使用时, 此类的方法只能在主线程上调用。"), \
		/*m_nCmdCount*/		 26, \
		/*m_pnCmdsIndex*/		 s_nProxyBrowserElementCmdIndex, \
		/*m_dwState*/		 NULL, \
		/*m_dwUnitBmpID*/		 NULL, \
		/*m_nEventCount*/		 0, \
		/*m_pEventBegin*/		 NULL, \
		/*m_nPropertyCount*/		 0, \
		/*m_pPropertyBegin*/		 NULL, \
		/*m_pfnGetInterface*/		 NULL, \
		/*m_nElementCount*/		 1, \
		/*m_pElementBegin*/		 s_dtDataElemnet \
	}, \


//==========================================

#define DECL_DATA_TYPE_ProxyBrowser_ARGINFO \
	{ /****** ProxyBrowser::IsSame ** 0 **/ \
		/*name*/	 _WT("目标浏览器"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 MAKELONG(5,0),  /*shrewd_ptr<ProxyBrowser>*/ \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxyBrowser::GetFrame ** 1 **/ \
		/*name*/	 _WT("框架名称"), \
		/*explain*/	 _WT("框架名称"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_TEXT, \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxyBrowser::GetFrameWithIdentity ** 2 **/ \
		/*name*/	 _WT("identity"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT64, \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\


//==========================================

#define DECL_DATA_TYPE_ProxyBrowser_CMDINFO(BeginIndex) \
	{ /*0*/ \
		/*ccname*/	_WT("Constructor"),\
		/*egname*/	_WT(""), \
		/*explain*/	_WT(""), \
		/*category*/	-1, \
		/*state*/	CT_IS_HIDED|CT_IS_OBJ_CONSTURCT_CMD, \
		/*ret*/	NULL, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	0, \
		/*arg lp*/	NULL, \
	},\
	{ /*1*/ \
		/*ccname*/	_WT("Destructor"),\
		/*egname*/	_WT(""), \
		/*explain*/	_WT("{0}"), \
		/*category*/	-1, \
		/*state*/	CT_IS_HIDED|CT_IS_OBJ_FREE_CMD, \
		/*ret*/	NULL, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	0, \
		/*arg lp*/	NULL, \
	},\
	{ /*2*/ \
		/*ccname*/	_WT("CopyConstructor"),\
		/*egname*/	_WT(""), \
		/*explain*/	_WT("{0}"), \
		/*category*/	-1, \
		/*state*/	CT_IS_HIDED|CT_IS_OBJ_COPY_CMD, \
		/*ret*/	 NULL, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	0, \
		/*arg lp*/	NULL, \
	},\
	{ /*3*/ \
		/*ccname*/	_WT("是否有效"),\
		/*egname*/	_WT("IsValid"), \
		/*explain*/	_WT("此函数检查本类中的对象实例是否有效。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	SDT_BOOL, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	0, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+0] \
	},\
	{ /*4*/ \
		/*ccname*/	_WT("取窗口句柄"),\
		/*egname*/	_WT("GetWindowHandle"), \
		/*explain*/	_WT("获取浏览器窗口句柄。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	SDT_INT, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	0, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+0] \
	},\
	{ /*5*/ \
		/*ccname*/	_WT("取浏览器宿主"),\
		/*egname*/	_WT("GetHost"), \
		/*explain*/	_WT("获取浏览器宿主对象。只能在浏览器进程中调用此方法。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	MAKELONG(6,0),  /*shrewd_ptr<ProxyBrowserHost>*/ \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	0, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+0] \
	},\
	{ /*6*/ \
		/*ccname*/	_WT("可否回退"),\
		/*egname*/	_WT("CanGoBack"), \
		/*explain*/	_WT("如果当前浏览器可回退至上一浏览页面返回真, 否则返回假。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	SDT_BOOL, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	0, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+0] \
	},\
	{ /*7*/ \
		/*ccname*/	_WT("回退"),\
		/*egname*/	_WT("GoBack"), \
		/*explain*/	_WT("设置浏览器回退到上一浏览页面。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	_SDT_NULL, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	0, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+0] \
	},\
	{ /*8*/ \
		/*ccname*/	_WT("可否前进"),\
		/*egname*/	_WT("CanGoForward"), \
		/*explain*/	_WT("如果当前浏览器可前进至下一浏览页面返回真, 否则返回假"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	SDT_BOOL, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	0, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+0] \
	},\
	{ /*9*/ \
		/*ccname*/	_WT("前进"),\
		/*egname*/	_WT("GoForward"), \
		/*explain*/	_WT("设置浏览器前进至下一浏览页面。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	_SDT_NULL, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	0, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+0] \
	},\
	{ /*10*/ \
		/*ccname*/	_WT("是否正在加载"),\
		/*egname*/	_WT("IsLoading"), \
		/*explain*/	_WT("如果当前浏览器正在加载中返回真。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	SDT_BOOL, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	0, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+0] \
	},\
	{ /*11*/ \
		/*ccname*/	_WT("重新加载"),\
		/*egname*/	_WT("Reload"), \
		/*explain*/	_WT("重新加载此页面。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	_SDT_NULL, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	0, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+0] \
	},\
	{ /*12*/ \
		/*ccname*/	_WT("重新加载忽略缓存"),\
		/*egname*/	_WT("ReloadIgnoreCache"), \
		/*explain*/	_WT("重新加载此页面, 不从缓冲中读取。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	_SDT_NULL, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	0, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+0] \
	},\
	{ /*13*/ \
		/*ccname*/	_WT("停止加载"),\
		/*egname*/	_WT("StopLoad"), \
		/*explain*/	_WT("停止加载页面。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	_SDT_NULL, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	0, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+0] \
	},\
	{ /*14*/ \
		/*ccname*/	_WT("取标识符"),\
		/*egname*/	_WT("GetIdentifier"), \
		/*explain*/	_WT("返回此浏览器的标识符"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	SDT_INT, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	0, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+0] \
	},\
	{ /*15*/ \
		/*ccname*/	_WT("是否相同"),\
		/*egname*/	_WT("IsSame"), \
		/*explain*/	_WT("比较两个浏览器窗口是否相同。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	SDT_BOOL, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	1, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+0] \
	},\
	{ /*16*/ \
		/*ccname*/	_WT("是否为弹出式窗口"),\
		/*egname*/	_WT("IsPopup"), \
		/*explain*/	_WT("如果当前浏览器为弹出式窗口返回真。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	SDT_BOOL, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	0, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+1] \
	},\
	{ /*17*/ \
		/*ccname*/	_WT("是否已加载文档"),\
		/*egname*/	_WT("HasDocument"), \
		/*explain*/	_WT("如果文档已加载到浏览器中返回真。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	SDT_BOOL, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	0, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+1] \
	},\
	{ /*18*/ \
		/*ccname*/	_WT("取主框架"),\
		/*egname*/	_WT("GetMainFrame"), \
		/*explain*/	_WT("获取第一个加载的(Top-Level)框架。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	MAKELONG(16,0),  /*shrewd_ptr<ProxyFrame>*/ \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	0, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+1] \
	},\
	{ /*19*/ \
		/*ccname*/	_WT("取焦点框架"),\
		/*egname*/	_WT("GetFocusedFrame"), \
		/*explain*/	_WT("获取当前拥有焦点的框架。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	MAKELONG(16,0),  /*shrewd_ptr<ProxyFrame>*/ \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	0, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+1] \
	},\
	{ /*20*/ \
		/*ccname*/	_WT("从名称取框架"),\
		/*egname*/	_WT("GetFrame"), \
		/*explain*/	_WT("使用名称检索浏览器中的指定框架, 检索成功返回对象实例, 检索失败返回空对象, 可调用IsValid() 函数检查对象有效性。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	MAKELONG(16,0),  /*shrewd_ptr<ProxyFrame>*/ \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	1, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+1] \
	},\
	{ /*21*/ \
		/*ccname*/	_WT("从标识符取框架"),\
		/*egname*/	_WT("GetFrameWithIdentity"), \
		/*explain*/	_WT("使用标识符检索浏览器中的指定框架, 检索成功返回对象实例, 检索失败返回空对象, 可调用IsValid() 函数检查对象有效性。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	MAKELONG(16,0),  /*shrewd_ptr<ProxyFrame>*/ \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	1, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+2] \
	},\
	{ /*22*/ \
		/*ccname*/	_WT("取框架数量"),\
		/*egname*/	_WT("GetFrameCount"), \
		/*explain*/	_WT("获取浏览器中已加载的框架数量。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	SDT_INT, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	0, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+3] \
	},\
	{ /*23*/ \
		/*ccname*/	_WT("取所有框架名称"),\
		/*egname*/	_WT("GetFrameNames"), \
		/*explain*/	_WT("获取浏览器中所有已加载框架的名称。"), \
		/*category*/	-1, \
		/*state*/	CT_RETRUN_ARY_TYPE_DATA, \
		/*ret*/	SDT_TEXT, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	0, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+3] \
	},\
	{ /*24*/ \
		/*ccname*/	_WT("取所有框架标识符"),\
		/*egname*/	_WT("GetFrameIdentifiers"), \
		/*explain*/	_WT("获取浏览器中所有已加载框架的标识符。"), \
		/*category*/	-1, \
		/*state*/	CT_RETRUN_ARY_TYPE_DATA, \
		/*ret*/	SDT_INT64, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	0, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+3] \
	},\
	{ /*25*/ \
		/*ccname*/	_WT("取所有框架"),\
		/*egname*/	_WT("GetFrames"), \
		/*explain*/	_WT("获取浏览器中所有已加载的框架。"), \
		/*category*/	-1, \
		/*state*/	CT_RETRUN_ARY_TYPE_DATA, \
		/*ret*/	MAKELONG(16,0),  /*shrewd_ptr<ProxyFrame>***/ \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	0, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+3] \
	},\


//==========================================

#define DECL_DATA_TYPE_ProxyBrowser_FUN_NAMES \
	EDITIONS("ProxyBrowser_Constructor"),\
	EDITIONS("ProxyBrowser_Destructor"),\
	EDITIONS("ProxyBrowser_CopyConstructor"),\
	EDITIONS("ProxyBrowser_IsValid"),\
	EDITIONS("ProxyBrowser_GetWindowHandle"),\
	EDITIONS("ProxyBrowser_GetHost"),\
	EDITIONS("ProxyBrowser_CanGoBack"),\
	EDITIONS("ProxyBrowser_GoBack"),\
	EDITIONS("ProxyBrowser_CanGoForward"),\
	EDITIONS("ProxyBrowser_GoForward"),\
	EDITIONS("ProxyBrowser_IsLoading"),\
	EDITIONS("ProxyBrowser_Reload"),\
	EDITIONS("ProxyBrowser_ReloadIgnoreCache"),\
	EDITIONS("ProxyBrowser_StopLoad"),\
	EDITIONS("ProxyBrowser_GetIdentifier"),\
	EDITIONS("ProxyBrowser_IsSame"),\
	EDITIONS("ProxyBrowser_IsPopup"),\
	EDITIONS("ProxyBrowser_HasDocument"),\
	EDITIONS("ProxyBrowser_GetMainFrame"),\
	EDITIONS("ProxyBrowser_GetFocusedFrame"),\
	EDITIONS("ProxyBrowser_GetFrame"),\
	EDITIONS("ProxyBrowser_GetFrameWithIdentity"),\
	EDITIONS("ProxyBrowser_GetFrameCount"),\
	EDITIONS("ProxyBrowser_GetFrameNames"),\
	EDITIONS("ProxyBrowser_GetFrameIdentifiers"),\
	EDITIONS("ProxyBrowser_GetFrames"),\


//==========================================

#define DECL_DATA_TYPE_ProxyBrowser_FUN_CALLS \
	EDITIONF(ProxyBrowser_Constructor),\
	EDITIONF(ProxyBrowser_Destructor),\
	EDITIONF(ProxyBrowser_CopyConstructor),\
	EDITIONF(ProxyBrowser_IsValid),\
	EDITIONF(ProxyBrowser_GetWindowHandle),\
	EDITIONF(ProxyBrowser_GetHost),\
	EDITIONF(ProxyBrowser_CanGoBack),\
	EDITIONF(ProxyBrowser_GoBack),\
	EDITIONF(ProxyBrowser_CanGoForward),\
	EDITIONF(ProxyBrowser_GoForward),\
	EDITIONF(ProxyBrowser_IsLoading),\
	EDITIONF(ProxyBrowser_Reload),\
	EDITIONF(ProxyBrowser_ReloadIgnoreCache),\
	EDITIONF(ProxyBrowser_StopLoad),\
	EDITIONF(ProxyBrowser_GetIdentifier),\
	EDITIONF(ProxyBrowser_IsSame),\
	EDITIONF(ProxyBrowser_IsPopup),\
	EDITIONF(ProxyBrowser_HasDocument),\
	EDITIONF(ProxyBrowser_GetMainFrame),\
	EDITIONF(ProxyBrowser_GetFocusedFrame),\
	EDITIONF(ProxyBrowser_GetFrame),\
	EDITIONF(ProxyBrowser_GetFrameWithIdentity),\
	EDITIONF(ProxyBrowser_GetFrameCount),\
	EDITIONF(ProxyBrowser_GetFrameNames),\
	EDITIONF(ProxyBrowser_GetFrameIdentifiers),\
	EDITIONF(ProxyBrowser_GetFrames),\


//==========================================

extern "C"
void EDITIONF(ProxyBrowser_Constructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyBrowser_Destructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyBrowser_CopyConstructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyBrowser_IsValid) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyBrowser_GetWindowHandle) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyBrowser_GetHost) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyBrowser_CanGoBack) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyBrowser_GoBack) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyBrowser_CanGoForward) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyBrowser_GoForward) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyBrowser_IsLoading) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyBrowser_Reload) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyBrowser_ReloadIgnoreCache) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyBrowser_StopLoad) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyBrowser_GetIdentifier) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyBrowser_IsSame) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyBrowser_IsPopup) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyBrowser_HasDocument) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyBrowser_GetMainFrame) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyBrowser_GetFocusedFrame) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyBrowser_GetFrame) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyBrowser_GetFrameWithIdentity) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyBrowser_GetFrameCount) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyBrowser_GetFrameNames) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyBrowser_GetFrameIdentifiers) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyBrowser_GetFrames) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);


//==========================================

