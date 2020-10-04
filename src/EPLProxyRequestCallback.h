#pragma once

#include "stdafx.h"
#include "lib2.h"


#define DECL_DATA_TYPE_ProxyRequestCallback \
	{ /*25*/ \
		/*m_szName*/		 _WT("Chromium请求回调"), \
		/*m_szEgName*/		 _WT("ProxyRequestCallback"), \
		/*m_szExplain*/		 _WT("用于处置浏览器 Web 请求的回调接口。"), \
		/*m_nCmdCount*/		 5, \
		/*m_pnCmdsIndex*/		 s_nProxyRequestCallbackElementCmdIndex, \
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

#define DECL_DATA_TYPE_ProxyRequestCallback_ARGINFO \
	{ /****** ProxyRequestCallback::Continue ** 0 **/ \
		/*name*/	 _WT("允许"), \
		/*explain*/	 _WT("此参数如果设置为真, 请求将继续执行, 否则请求将被取消。"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_BOOL, \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\


//==========================================

#define DECL_DATA_TYPE_ProxyRequestCallback_CMDINFO(BeginIndex) \
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
		/*ccname*/	_WT("请求处置"),\
		/*egname*/	_WT("Continue"), \
		/*explain*/	_WT("是否继续URL请求。"), \
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
	{ /*4*/ \
		/*ccname*/	_WT("取消"),\
		/*egname*/	_WT("Cancel"), \
		/*explain*/	_WT("取消该URL请求"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	_SDT_NULL, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	0, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+1] \
	},\


//==========================================

#define DECL_DATA_TYPE_ProxyRequestCallback_FUN_NAMES \
	EDITIONS("ProxyRequestCallback_Constructor"),\
	EDITIONS("ProxyRequestCallback_Destructor"),\
	EDITIONS("ProxyRequestCallback_CopyConstructor"),\
	EDITIONS("ProxyRequestCallback_Continue"),\
	EDITIONS("ProxyRequestCallback_Cancel"),\


//==========================================

#define DECL_DATA_TYPE_ProxyRequestCallback_FUN_CALLS \
	EDITIONF(ProxyRequestCallback_Constructor),\
	EDITIONF(ProxyRequestCallback_Destructor),\
	EDITIONF(ProxyRequestCallback_CopyConstructor),\
	EDITIONF(ProxyRequestCallback_Continue),\
	EDITIONF(ProxyRequestCallback_Cancel),\


//==========================================

extern "C"
void EDITIONF(ProxyRequestCallback_Constructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyRequestCallback_Destructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyRequestCallback_CopyConstructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyRequestCallback_Continue) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyRequestCallback_Cancel) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);


//==========================================

