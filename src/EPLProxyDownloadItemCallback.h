#pragma once

#include "stdafx.h"
#include "lib2.h"


#define DECL_DATA_TYPE_ProxyDownloadItemCallback \
	{ /*13*/ \
		/*m_szName*/		 _WT("Chromium文件下载管理回调"), \
		/*m_szEgName*/		 _WT("ProxyDownloadItemCallback"), \
		/*m_szExplain*/		 _WT("用于提供下载管理的回调接口。"), \
		/*m_nCmdCount*/		 6, \
		/*m_pnCmdsIndex*/		 s_nProxyDownloadItemCallbackElementCmdIndex, \
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

#define DECL_DATA_TYPE_ProxyDownloadItemCallback_ARGINFO \


//==========================================

#define DECL_DATA_TYPE_ProxyDownloadItemCallback_CMDINFO(BeginIndex) \
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
		/*ccname*/	_WT("取消"),\
		/*egname*/	_WT("Cancel"), \
		/*explain*/	_WT("取消该文件的下载。"), \
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
	{ /*4*/ \
		/*ccname*/	_WT("暂停"),\
		/*egname*/	_WT("Pause"), \
		/*explain*/	_WT("暂停该文件的下载"), \
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
	{ /*5*/ \
		/*ccname*/	_WT("继续"),\
		/*egname*/	_WT("Resume"), \
		/*explain*/	_WT("继续该文件的下载。"), \
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


//==========================================

#define DECL_DATA_TYPE_ProxyDownloadItemCallback_FUN_NAMES \
	EDITIONS("ProxyDownloadItemCallback_Constructor"),\
	EDITIONS("ProxyDownloadItemCallback_Destructor"),\
	EDITIONS("ProxyDownloadItemCallback_CopyConstructor"),\
	EDITIONS("ProxyDownloadItemCallback_Cancel"),\
	EDITIONS("ProxyDownloadItemCallback_Pause"),\
	EDITIONS("ProxyDownloadItemCallback_Resume"),\


//==========================================

#define DECL_DATA_TYPE_ProxyDownloadItemCallback_FUN_CALLS \
	EDITIONF(ProxyDownloadItemCallback_Constructor),\
	EDITIONF(ProxyDownloadItemCallback_Destructor),\
	EDITIONF(ProxyDownloadItemCallback_CopyConstructor),\
	EDITIONF(ProxyDownloadItemCallback_Cancel),\
	EDITIONF(ProxyDownloadItemCallback_Pause),\
	EDITIONF(ProxyDownloadItemCallback_Resume),\


//==========================================

extern "C"
void EDITIONF(ProxyDownloadItemCallback_Constructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyDownloadItemCallback_Destructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyDownloadItemCallback_CopyConstructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyDownloadItemCallback_Cancel) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyDownloadItemCallback_Pause) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyDownloadItemCallback_Resume) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);


//==========================================

