#pragma once

#include "stdafx.h"
#include "lib2.h"


#define DECL_DATA_TYPE_ProxyDownloadItem \
	{ /*12*/ \
		/*m_szName*/		 _WT("Chromium文件下载项"), \
		/*m_szEgName*/		 _WT("ProxyDownloadItem"), \
		/*m_szExplain*/		 _WT("用于表示下载项目的类。"), \
		/*m_nCmdCount*/		 20, \
		/*m_pnCmdsIndex*/		 s_nProxyDownloadItemElementCmdIndex, \
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

#define DECL_DATA_TYPE_ProxyDownloadItem_ARGINFO \


//==========================================

#define DECL_DATA_TYPE_ProxyDownloadItem_CMDINFO(BeginIndex) \
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
		/*ccname*/	_WT("是否正在下载"),\
		/*egname*/	_WT("IsInProgress"), \
		/*explain*/	_WT("如果下载正在进行返回真。"), \
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
	{ /*5*/ \
		/*ccname*/	_WT("是否已完成"),\
		/*egname*/	_WT("IsComplete"), \
		/*explain*/	_WT("如果下载已完成返回真"), \
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
	{ /*6*/ \
		/*ccname*/	_WT("是否已取消"),\
		/*egname*/	_WT("IsCanceled"), \
		/*explain*/	_WT("如果下载被取消或中断返回真"), \
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
		/*ccname*/	_WT("取下载速度"),\
		/*egname*/	_WT("GetCurrentSpeed"), \
		/*explain*/	_WT("返回以字节(Bytes)/每秒为单位的简单速度估算值。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	SDT_INT64, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	0, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+0] \
	},\
	{ /*8*/ \
		/*ccname*/	_WT("取下载百分比"),\
		/*egname*/	_WT("GetPercentComplete"), \
		/*explain*/	_WT("返回已下载完成的大致百分比, 如果接收的总大小未知则会返回-1。"), \
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
	{ /*9*/ \
		/*ccname*/	_WT("取字节总数"),\
		/*egname*/	_WT("GetTotalBytes"), \
		/*explain*/	_WT("返回字节总数"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	SDT_INT64, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	0, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+0] \
	},\
	{ /*10*/ \
		/*ccname*/	_WT("取已接收字节数"),\
		/*egname*/	_WT("GetReceivedBytes"), \
		/*explain*/	_WT("返回接收到的字节数"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	SDT_INT64, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	0, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+0] \
	},\
	{ /*11*/ \
		/*ccname*/	_WT("取开始时间"),\
		/*egname*/	_WT("GetStartTime"), \
		/*explain*/	_WT("返回下载开始的时间。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	MAKELONG(34,0),  /*shrewd_ptr<ProxyTime>*/ \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	0, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+0] \
	},\
	{ /*12*/ \
		/*ccname*/	_WT("取结束时间"),\
		/*egname*/	_WT("GetEndTime"), \
		/*explain*/	_WT("返回下载结束的时间。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	MAKELONG(34,0),  /*shrewd_ptr<ProxyTime>*/ \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	0, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+0] \
	},\
	{ /*13*/ \
		/*ccname*/	_WT("取文件路径"),\
		/*egname*/	_WT("GetFullPath"), \
		/*explain*/	_WT("返回该下载文件的完整路径。"), \
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
	{ /*14*/ \
		/*ccname*/	_WT("取ID"),\
		/*egname*/	_WT("GetId"), \
		/*explain*/	_WT("返回此下载文件的唯一标识符。"), \
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
		/*ccname*/	_WT("取URL"),\
		/*egname*/	_WT("GetURL"), \
		/*explain*/	_WT("返回此下载文件的URL"), \
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
	{ /*16*/ \
		/*ccname*/	_WT("取原始URL"),\
		/*egname*/	_WT("GetOriginalUrl"), \
		/*explain*/	_WT("返回此下载文件的原始URL。"), \
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
	{ /*17*/ \
		/*ccname*/	_WT("取建议名称"),\
		/*egname*/	_WT("GetSuggestedFileName"), \
		/*explain*/	_WT("返回此下载文件的建议名称。"), \
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
	{ /*18*/ \
		/*ccname*/	_WT("取内容处置"),\
		/*egname*/	_WT("GetContentDisposition"), \
		/*explain*/	_WT("返回此文件的内容处置"), \
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
	{ /*19*/ \
		/*ccname*/	_WT("取MIME类型"),\
		/*egname*/	_WT("GetMimeType"), \
		/*explain*/	_WT("返回此文件的MIME类型。"), \
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


//==========================================

#define DECL_DATA_TYPE_ProxyDownloadItem_FUN_NAMES \
	EDITIONS("ProxyDownloadItem_Constructor"),\
	EDITIONS("ProxyDownloadItem_Destructor"),\
	EDITIONS("ProxyDownloadItem_CopyConstructor"),\
	EDITIONS("ProxyDownloadItem_IsValid"),\
	EDITIONS("ProxyDownloadItem_IsInProgress"),\
	EDITIONS("ProxyDownloadItem_IsComplete"),\
	EDITIONS("ProxyDownloadItem_IsCanceled"),\
	EDITIONS("ProxyDownloadItem_GetCurrentSpeed"),\
	EDITIONS("ProxyDownloadItem_GetPercentComplete"),\
	EDITIONS("ProxyDownloadItem_GetTotalBytes"),\
	EDITIONS("ProxyDownloadItem_GetReceivedBytes"),\
	EDITIONS("ProxyDownloadItem_GetStartTime"),\
	EDITIONS("ProxyDownloadItem_GetEndTime"),\
	EDITIONS("ProxyDownloadItem_GetFullPath"),\
	EDITIONS("ProxyDownloadItem_GetId"),\
	EDITIONS("ProxyDownloadItem_GetURL"),\
	EDITIONS("ProxyDownloadItem_GetOriginalUrl"),\
	EDITIONS("ProxyDownloadItem_GetSuggestedFileName"),\
	EDITIONS("ProxyDownloadItem_GetContentDisposition"),\
	EDITIONS("ProxyDownloadItem_GetMimeType"),\


//==========================================

#define DECL_DATA_TYPE_ProxyDownloadItem_FUN_CALLS \
	EDITIONF(ProxyDownloadItem_Constructor),\
	EDITIONF(ProxyDownloadItem_Destructor),\
	EDITIONF(ProxyDownloadItem_CopyConstructor),\
	EDITIONF(ProxyDownloadItem_IsValid),\
	EDITIONF(ProxyDownloadItem_IsInProgress),\
	EDITIONF(ProxyDownloadItem_IsComplete),\
	EDITIONF(ProxyDownloadItem_IsCanceled),\
	EDITIONF(ProxyDownloadItem_GetCurrentSpeed),\
	EDITIONF(ProxyDownloadItem_GetPercentComplete),\
	EDITIONF(ProxyDownloadItem_GetTotalBytes),\
	EDITIONF(ProxyDownloadItem_GetReceivedBytes),\
	EDITIONF(ProxyDownloadItem_GetStartTime),\
	EDITIONF(ProxyDownloadItem_GetEndTime),\
	EDITIONF(ProxyDownloadItem_GetFullPath),\
	EDITIONF(ProxyDownloadItem_GetId),\
	EDITIONF(ProxyDownloadItem_GetURL),\
	EDITIONF(ProxyDownloadItem_GetOriginalUrl),\
	EDITIONF(ProxyDownloadItem_GetSuggestedFileName),\
	EDITIONF(ProxyDownloadItem_GetContentDisposition),\
	EDITIONF(ProxyDownloadItem_GetMimeType),\


//==========================================

extern "C"
void EDITIONF(ProxyDownloadItem_Constructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyDownloadItem_Destructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyDownloadItem_CopyConstructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyDownloadItem_IsValid) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyDownloadItem_IsInProgress) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyDownloadItem_IsComplete) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyDownloadItem_IsCanceled) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyDownloadItem_GetCurrentSpeed) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyDownloadItem_GetPercentComplete) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyDownloadItem_GetTotalBytes) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyDownloadItem_GetReceivedBytes) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyDownloadItem_GetStartTime) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyDownloadItem_GetEndTime) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyDownloadItem_GetFullPath) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyDownloadItem_GetId) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyDownloadItem_GetURL) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyDownloadItem_GetOriginalUrl) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyDownloadItem_GetSuggestedFileName) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyDownloadItem_GetContentDisposition) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyDownloadItem_GetMimeType) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);


//==========================================

