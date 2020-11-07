#pragma once

#include "stdafx.h"
#include "lib2.h"


#define DECL_DATA_TYPE_ProxyResponseFilter \
	{ /*26*/ \
		/*m_szName*/		 _WT("水星资源过滤器"), \
		/*m_szEgName*/		 _WT("ProxyResponseFilter"), \
		/*m_szExplain*/		 _WT("用于提供资源可选化配置的类。"), \
		/*m_nCmdCount*/		 9, \
		/*m_pnCmdsIndex*/		 s_nProxyResponseFilterElementCmdIndex, \
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

#define DECL_DATA_TYPE_ProxyResponseFilter_ARGINFO \
	{ /****** ProxyResponseFilter::SetResource ** 0 **/ \
		/*name*/	 _WT("资源数据"), \
		/*explain*/	 _WT("资源数据"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_BIN, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyResponseFilter::SetResource ** 1 **/ \
		/*name*/	 _WT("资源长度"), \
		/*explain*/	 _WT("该只有所占的字节长度"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\


//==========================================

#define DECL_DATA_TYPE_ProxyResponseFilter_CMDINFO(BeginIndex) \
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
		/*ccname*/	_WT("取URL"),\
		/*egname*/	_WT("GetURL"), \
		/*explain*/	_WT("取该资源的URL。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	SDT_TEXT, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	0, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+0] \
	},\
	{ /*5*/ \
		/*ccname*/	_WT("取MIME类型"),\
		/*egname*/	_WT("GetMimeType"), \
		/*explain*/	_WT("取该资源的Mime类型."), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	SDT_TEXT, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	0, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+0] \
	},\
	{ /*6*/ \
		/*ccname*/	_WT("取总字节长度"),\
		/*egname*/	_WT("GetTotalBytes"), \
		/*explain*/	_WT("取该资源所占用的总字节数。"), \
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
	{ /*7*/ \
		/*ccname*/	_WT("取资源"),\
		/*egname*/	_WT("GetResource"), \
		/*explain*/	_WT("取该资源"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	SDT_BIN, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	0, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+0] \
	},\
	{ /*8*/ \
		/*ccname*/	_WT("置资源"),\
		/*egname*/	_WT("SetResource"), \
		/*explain*/	_WT("设置一个新的资源对资源进行替换"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	_SDT_NULL, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	2, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+0] \
	},\


//==========================================

#define DECL_DATA_TYPE_ProxyResponseFilter_FUN_NAMES \
	EDITIONS("ProxyResponseFilter_Constructor"),\
	EDITIONS("ProxyResponseFilter_Destructor"),\
	EDITIONS("ProxyResponseFilter_CopyConstructor"),\
	EDITIONS("ProxyResponseFilter_IsValid"),\
	EDITIONS("ProxyResponseFilter_GetURL"),\
	EDITIONS("ProxyResponseFilter_GetMimeType"),\
	EDITIONS("ProxyResponseFilter_GetTotalBytes"),\
	EDITIONS("ProxyResponseFilter_GetResource"),\
	EDITIONS("ProxyResponseFilter_SetResource"),\


//==========================================

#define DECL_DATA_TYPE_ProxyResponseFilter_FUN_CALLS \
	EDITIONF(ProxyResponseFilter_Constructor),\
	EDITIONF(ProxyResponseFilter_Destructor),\
	EDITIONF(ProxyResponseFilter_CopyConstructor),\
	EDITIONF(ProxyResponseFilter_IsValid),\
	EDITIONF(ProxyResponseFilter_GetURL),\
	EDITIONF(ProxyResponseFilter_GetMimeType),\
	EDITIONF(ProxyResponseFilter_GetTotalBytes),\
	EDITIONF(ProxyResponseFilter_GetResource),\
	EDITIONF(ProxyResponseFilter_SetResource),\


//==========================================

extern "C"
void EDITIONF(ProxyResponseFilter_Constructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyResponseFilter_Destructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyResponseFilter_CopyConstructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyResponseFilter_IsValid) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyResponseFilter_GetURL) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyResponseFilter_GetMimeType) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyResponseFilter_GetTotalBytes) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyResponseFilter_GetResource) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyResponseFilter_SetResource) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);


//==========================================

