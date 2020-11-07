#pragma once

#include "stdafx.h"
#include "lib2.h"


#define DECL_DATA_TYPE_ProxyURLRequest \
	{ /*30*/ \
		/*m_szName*/		 _WT("水星URL请求"), \
		/*m_szEgName*/		 _WT("ProxyURLRequest"), \
		/*m_szExplain*/		 _WT("表示HTTP请求的类。"), \
		/*m_nCmdCount*/		 12, \
		/*m_pnCmdsIndex*/		 s_nProxyURLRequestElementCmdIndex, \
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

#define DECL_DATA_TYPE_ProxyURLRequest_ARGINFO \


//==========================================

#define DECL_DATA_TYPE_ProxyURLRequest_CMDINFO(BeginIndex) \
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
		/*ccname*/	_WT("取请求"),\
		/*egname*/	_WT("GetRequest"), \
		/*explain*/	_WT("获取发出的HTTP请求。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	MAKELONG(24,0),  /*shrewd_ptr<ProxyRequest>*/ \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	0, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+0] \
	},\
	{ /*5*/ \
		/*ccname*/	_WT("取响应"),\
		/*egname*/	_WT("GetResponse"), \
		/*explain*/	_WT("获取收到的HTTP响应。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	MAKELONG(25,0),  /*shrewd_ptr<ProxyResponse>*/ \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	0, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+0] \
	},\
	{ /*6*/ \
		/*ccname*/	_WT("取请求状态"),\
		/*egname*/	_WT("GetRequestStatus"), \
		/*explain*/	_WT("获取本次请求的执行状态。定义值为枚举常量: #请求状态.* 。"), \
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
		/*ccname*/	_WT("取错误代码"),\
		/*egname*/	_WT("GetRequestError"), \
		/*explain*/	_WT("获取执行请求失败时的错误代码。"), \
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
	{ /*8*/ \
		/*ccname*/	_WT("是否从缓存加载"),\
		/*egname*/	_WT("ResponseWasCached"), \
		/*explain*/	_WT("如果响应数据是从缓存提供的返回真。"), \
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
		/*ccname*/	_WT("取响应数据长度"),\
		/*egname*/	_WT("GetResponseDataBytes"), \
		/*explain*/	_WT("获取响应数据字节长度。"), \
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
	{ /*10*/ \
		/*ccname*/	_WT("取响应数据"),\
		/*egname*/	_WT("GetResponseData"), \
		/*explain*/	_WT("获取接收到的响应数据   "), \
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
	{ /*11*/ \
		/*ccname*/	_WT("取会话管理器"),\
		/*egname*/	_WT("GetCookieManager"), \
		/*explain*/	_WT("获取本请求使用的会话凭证(Cookie)管理器。 未设置隐身模式时本请求共享使用全局的会话凭证管理器。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	MAKELONG(10,0),  /*shrewd_ptr<ProxyCookieManager>*/ \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	0, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+0] \
	},\


//==========================================

#define DECL_DATA_TYPE_ProxyURLRequest_FUN_NAMES \
	EDITIONS("ProxyURLRequest_Constructor"),\
	EDITIONS("ProxyURLRequest_Destructor"),\
	EDITIONS("ProxyURLRequest_CopyConstructor"),\
	EDITIONS("ProxyURLRequest_IsValid"),\
	EDITIONS("ProxyURLRequest_GetRequest"),\
	EDITIONS("ProxyURLRequest_GetResponse"),\
	EDITIONS("ProxyURLRequest_GetRequestStatus"),\
	EDITIONS("ProxyURLRequest_GetRequestError"),\
	EDITIONS("ProxyURLRequest_ResponseWasCached"),\
	EDITIONS("ProxyURLRequest_GetResponseDataBytes"),\
	EDITIONS("ProxyURLRequest_GetResponseData"),\
	EDITIONS("ProxyURLRequest_GetCookieManager"),\


//==========================================

#define DECL_DATA_TYPE_ProxyURLRequest_FUN_CALLS \
	EDITIONF(ProxyURLRequest_Constructor),\
	EDITIONF(ProxyURLRequest_Destructor),\
	EDITIONF(ProxyURLRequest_CopyConstructor),\
	EDITIONF(ProxyURLRequest_IsValid),\
	EDITIONF(ProxyURLRequest_GetRequest),\
	EDITIONF(ProxyURLRequest_GetResponse),\
	EDITIONF(ProxyURLRequest_GetRequestStatus),\
	EDITIONF(ProxyURLRequest_GetRequestError),\
	EDITIONF(ProxyURLRequest_ResponseWasCached),\
	EDITIONF(ProxyURLRequest_GetResponseDataBytes),\
	EDITIONF(ProxyURLRequest_GetResponseData),\
	EDITIONF(ProxyURLRequest_GetCookieManager),\


//==========================================

extern "C"
void EDITIONF(ProxyURLRequest_Constructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyURLRequest_Destructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyURLRequest_CopyConstructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyURLRequest_IsValid) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyURLRequest_GetRequest) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyURLRequest_GetResponse) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyURLRequest_GetRequestStatus) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyURLRequest_GetRequestError) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyURLRequest_ResponseWasCached) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyURLRequest_GetResponseDataBytes) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyURLRequest_GetResponseData) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyURLRequest_GetCookieManager) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);


//==========================================

