#pragma once

#include "stdafx.h"
#include "lib2.h"


#define DECL_DATA_TYPE_ProxyActiveBrowserCallback \
	{ /*1*/ \
		/*m_szName*/		 _WT("水星获取活动浏览器回调"), \
		/*m_szEgName*/		 _WT("ProxyActiveBrowserCallback"), \
		/*m_szExplain*/		 _WT("用于扩展程序事件扩展程序取活动浏览器。向扩展程序返回当前应用程序中的活动浏览器对象。"), \
		/*m_nCmdCount*/		 4, \
		/*m_pnCmdsIndex*/		 s_nProxyActiveBrowserCallbackElementCmdIndex, \
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

#define DECL_DATA_TYPE_ProxyActiveBrowserCallback_ARGINFO \
	{ /****** ProxyActiveBrowserCallback::SetBrowser ** 0 **/ \
		/*name*/	 _WT("浏览器"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 MAKELONG(4,0),  /*shrewd_ptr<ProxyBrowser>*/ \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\


//==========================================

#define DECL_DATA_TYPE_ProxyActiveBrowserCallback_CMDINFO(BeginIndex) \
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
		/*ccname*/	_WT("置活动浏览器"),\
		/*egname*/	_WT("SetBrowser"), \
		/*explain*/	_WT("设置活动浏览器。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	_SDT_NULL, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	1, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+0] \
	},\


//==========================================

#define DECL_DATA_TYPE_ProxyActiveBrowserCallback_FUN_NAMES \
	EDITIONS("ProxyActiveBrowserCallback_Constructor"),\
	EDITIONS("ProxyActiveBrowserCallback_Destructor"),\
	EDITIONS("ProxyActiveBrowserCallback_CopyConstructor"),\
	EDITIONS("ProxyActiveBrowserCallback_SetBrowser"),\


//==========================================

#define DECL_DATA_TYPE_ProxyActiveBrowserCallback_FUN_CALLS \
	EDITIONF(ProxyActiveBrowserCallback_Constructor),\
	EDITIONF(ProxyActiveBrowserCallback_Destructor),\
	EDITIONF(ProxyActiveBrowserCallback_CopyConstructor),\
	EDITIONF(ProxyActiveBrowserCallback_SetBrowser),\


//==========================================

extern "C"
void EDITIONF(ProxyActiveBrowserCallback_Constructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyActiveBrowserCallback_Destructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyActiveBrowserCallback_CopyConstructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyActiveBrowserCallback_SetBrowser) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);


//==========================================

