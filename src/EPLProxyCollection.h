#pragma once

#include "stdafx.h"
#include "lib2.h"


#define DECL_DATA_TYPE_ProxyCollection \
	{ /*6*/ \
		/*m_szName*/		 _WT("水星网页驱动器"), \
		/*m_szEgName*/		 _WT("ProxyCollection"), \
		/*m_szExplain*/		 _WT("用作一次浏览器自动化测试过程表达。"), \
		/*m_nCmdCount*/		 9, \
		/*m_pnCmdsIndex*/		 s_nProxyCollectionElementCmdIndex, \
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

#define DECL_DATA_TYPE_ProxyCollection_ARGINFO \
	{ /****** ProxyCollection::CreateBrowser ** 0 **/ \
		/*name*/	 _WT("url"), \
		/*explain*/	 _WT("设置需要访问的地址(URL), 无需访问可设置: about:blank"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_TEXT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyCollection::CreateBrowser ** 1 **/ \
		/*name*/	 _WT("浏览器设置"), \
		/*explain*/	 _WT("设置浏览器的运行参数。"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 MAKELONG(5,0),  /*shrewd_ptr<ProxyBrowserSettings>*/ \
		/*default*/	 0,\
		/*state*/	 AS_DEFAULT_VALUE_IS_EMPTY \
	},\
	{ /****** ProxyCollection::CloseBrowser ** 2 **/ \
		/*name*/	 _WT("浏览器"), \
		/*explain*/	 _WT("需要关闭的浏览器。"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 MAKELONG(4,0),  /*shrewd_ptr<ProxyBrowser>*/ \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyCollection::GetBrowser ** 3 **/ \
		/*name*/	 _WT("索引"), \
		/*explain*/	 _WT("索引从0开始。"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\


//==========================================

#define DECL_DATA_TYPE_ProxyCollection_CMDINFO(BeginIndex) \
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
		/*ccname*/	_WT("创建浏览器"),\
		/*egname*/	_WT("CreateBrowser"), \
		/*explain*/	_WT("创建一个新的浏览器窗口, 创建成功返回新的窗口对象, 失败返回空, 可使用 IsValid 函数检查返回有效性。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	MAKELONG(4,0),  /*shrewd_ptr<ProxyBrowser>*/ \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	2, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+0] \
	},\
	{ /*5*/ \
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
		/*argcount*/	1, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+2] \
	},\
	{ /*6*/ \
		/*ccname*/	_WT("取浏览器数量"),\
		/*egname*/	_WT("GetBrowserCount"), \
		/*explain*/	_WT("返回当前采集上下文中的浏览器窗口数量。"), \
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
	{ /*7*/ \
		/*ccname*/	_WT("取浏览器索引"),\
		/*egname*/	_WT("GetBrowser"), \
		/*explain*/	_WT("使用索引在当前采集器上下文中查询浏览器, 索引从0开始, 成功返回浏览器对象, 失败返回空对象。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	MAKELONG(4,0),  /*shrewd_ptr<ProxyBrowser>*/ \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	1, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+3] \
	},\
	{ /*8*/ \
		/*ccname*/	_WT("取所有浏览器"),\
		/*egname*/	_WT("GetAllBrowser"), \
		/*explain*/	_WT("获取当前采集器上下文中所有的浏览器。"), \
		/*category*/	-1, \
		/*state*/	CT_RETRUN_ARY_TYPE_DATA, \
		/*ret*/	MAKELONG(4,0),  /*shrewd_ptr<ProxyBrowser>***/ \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	0, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+4] \
	},\


//==========================================

#define DECL_DATA_TYPE_ProxyCollection_FUN_NAMES \
	EDITIONS("ProxyCollection_Constructor"),\
	EDITIONS("ProxyCollection_Destructor"),\
	EDITIONS("ProxyCollection_CopyConstructor"),\
	EDITIONS("ProxyCollection_IsValid"),\
	EDITIONS("ProxyCollection_CreateBrowser"),\
	EDITIONS("ProxyCollection_CloseBrowser"),\
	EDITIONS("ProxyCollection_GetBrowserCount"),\
	EDITIONS("ProxyCollection_GetBrowser"),\
	EDITIONS("ProxyCollection_GetAllBrowser"),\


//==========================================

#define DECL_DATA_TYPE_ProxyCollection_FUN_CALLS \
	EDITIONF(ProxyCollection_Constructor),\
	EDITIONF(ProxyCollection_Destructor),\
	EDITIONF(ProxyCollection_CopyConstructor),\
	EDITIONF(ProxyCollection_IsValid),\
	EDITIONF(ProxyCollection_CreateBrowser),\
	EDITIONF(ProxyCollection_CloseBrowser),\
	EDITIONF(ProxyCollection_GetBrowserCount),\
	EDITIONF(ProxyCollection_GetBrowser),\
	EDITIONF(ProxyCollection_GetAllBrowser),\


//==========================================

extern "C"
void EDITIONF(ProxyCollection_Constructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyCollection_Destructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyCollection_CopyConstructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyCollection_IsValid) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyCollection_CreateBrowser) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyCollection_CloseBrowser) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyCollection_GetBrowserCount) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyCollection_GetBrowser) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyCollection_GetAllBrowser) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);


//==========================================

