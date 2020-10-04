#pragma once

#include "stdafx.h"
#include "lib2.h"


#define DECL_DATA_TYPE_ProxyRequestContext \
	{ /*26*/ \
		/*m_szName*/		 _WT("Chromium会话环境"), \
		/*m_szEgName*/		 _WT("ProxyRequestContext"), \
		/*m_szExplain*/		 _WT("Chromium 会话环境为一组相关的浏览器或URL请求对象提供会话管理。通过调用 \"创建浏览器\" 方法创建新的浏览器时 或是 \"创建URL请求\"创建新的URL请求时, 可以指定会话环境。具有不同会话环境的浏览器对象将永远不会托管在统一渲染过程中。具有相同会话环境的浏览器对象可能会也可能不会托管在同一浏览器进程中, 这取决于流程模型。 通过Javascript的window.open函数或目标链接间创建的浏览器的浏览器对象将与源浏览器共享一个相同的渲染过程和相同的会话环境。 "), \
		/*m_nCmdCount*/		 16, \
		/*m_pnCmdsIndex*/		 s_nProxyRequestContextElementCmdIndex, \
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

#define DECL_DATA_TYPE_ProxyRequestContext_ARGINFO \
	{ /****** ProxyRequestContext::CreateContext ** 0 **/ \
		/*name*/	 _WT("会话环境设置"), \
		/*explain*/	 _WT("会话环境设置信息"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 MAKELONG(28,0),  /*shrewd_ptr<ProxyRequestContextSettings>*/ \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxyRequestContext::CreateContextWith ** 1 **/ \
		/*name*/	 _WT("other"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 MAKELONG(27,0),  /*shrewd_ptr<ProxyRequestContext>*/ \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxyRequestContext::IsSame ** 2 **/ \
		/*name*/	 _WT("比较对象"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 MAKELONG(27,0),  /*shrewd_ptr<ProxyRequestContext>*/ \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxyRequestContext::IsSharingWith ** 3 **/ \
		/*name*/	 _WT("目标对象"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 MAKELONG(27,0),  /*shrewd_ptr<ProxyRequestContext>*/ \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxyRequestContext::PurgePluginListCache ** 4 **/ \
		/*name*/	 _WT("是否重新加载页面"), \
		/*explain*/	 _WT("如果此参数设置为真, 与此会话环境相关联的浏览器将重新使用插件并加载所有页面。"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_BOOL, \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\


//==========================================

#define DECL_DATA_TYPE_ProxyRequestContext_CMDINFO(BeginIndex) \
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
		/*ccname*/	_WT("取全局实例"),\
		/*egname*/	_WT("GetGlobalContext"), \
		/*explain*/	_WT("返回全局的会话环境对象, 对于此对象的改写将会应用至所有浏览器。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	MAKELONG(27,0),  /*shrewd_ptr<ProxyRequestContext>*/ \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	0, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+0] \
	},\
	{ /*4*/ \
		/*ccname*/	_WT("创建对象"),\
		/*egname*/	_WT("CreateContext"), \
		/*explain*/	_WT("实验知道的设置参数创建一个新的会话环境对象。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	MAKELONG(27,0),  /*shrewd_ptr<ProxyRequestContext>*/ \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	1, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+0] \
	},\
	{ /*5*/ \
		/*ccname*/	_WT("CreateContextWith"),\
		/*egname*/	_WT("CreateContextWith"), \
		/*explain*/	_WT(""), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	MAKELONG(27,0),  /*shrewd_ptr<ProxyRequestContext>*/ \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	1, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+1] \
	},\
	{ /*6*/ \
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
		/*arg lp*/	&s_ArgInfo[BeginIndex+2] \
	},\
	{ /*7*/ \
		/*ccname*/	_WT("是否相同"),\
		/*egname*/	_WT("IsSame"), \
		/*explain*/	_WT("比较两个会话环境对象是否相同。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	SDT_BOOL, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	1, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+2] \
	},\
	{ /*8*/ \
		/*ccname*/	_WT("是否共享缓存"),\
		/*egname*/	_WT("IsSharingWith"), \
		/*explain*/	_WT("如果该对象与目标对象使用相同的存储返回真。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	SDT_BOOL, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	1, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+3] \
	},\
	{ /*9*/ \
		/*ccname*/	_WT("是否为全局对象"),\
		/*egname*/	_WT("IsGlobal"), \
		/*explain*/	_WT("如果此对象是全局会话环境对象返回真。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	SDT_BOOL, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	0, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+4] \
	},\
	{ /*10*/ \
		/*ccname*/	_WT("取缓存目录"),\
		/*egname*/	_WT("GetCachePath"), \
		/*explain*/	_WT("获取该会话环境使用的缓存目录。如果为空, 则使用\"incognito mode(隐身模式)\"内存缓存。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	SDT_TEXT, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	0, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+4] \
	},\
	{ /*11*/ \
		/*ccname*/	_WT("取COOKIE管理器"),\
		/*egname*/	_WT("GetCookieManager"), \
		/*explain*/	_WT("获取该会话环境的COOKIE管理器。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	MAKELONG(11,0),  /*shrewd_ptr<ProxyCookieManager>*/ \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	0, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+4] \
	},\
	{ /*12*/ \
		/*ccname*/	_WT("清除插件列表缓存"),\
		/*egname*/	_WT("PurgePluginListCache"), \
		/*explain*/	_WT("清除与此会话环境相关联的浏览器的插件列表缓存。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	_SDT_NULL, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	1, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+4] \
	},\
	{ /*13*/ \
		/*ccname*/	_WT("ClearCertificateExceptions"),\
		/*egname*/	_WT("ClearCertificateExceptions"), \
		/*explain*/	_WT(""), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	_SDT_NULL, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	0, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+5] \
	},\
	{ /*14*/ \
		/*ccname*/	_WT("ClearHttpAuthCredentials"),\
		/*egname*/	_WT("ClearHttpAuthCredentials"), \
		/*explain*/	_WT(""), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	_SDT_NULL, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	0, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+5] \
	},\
	{ /*15*/ \
		/*ccname*/	_WT("CloseAllConnections"),\
		/*egname*/	_WT("CloseAllConnections"), \
		/*explain*/	_WT(""), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	_SDT_NULL, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	0, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+5] \
	},\


//==========================================

#define DECL_DATA_TYPE_ProxyRequestContext_FUN_NAMES \
	EDITIONS("ProxyRequestContext_Constructor"),\
	EDITIONS("ProxyRequestContext_Destructor"),\
	EDITIONS("ProxyRequestContext_CopyConstructor"),\
	EDITIONS("ProxyRequestContext_GetGlobalContext"),\
	EDITIONS("ProxyRequestContext_CreateContext"),\
	EDITIONS("ProxyRequestContext_CreateContextWith"),\
	EDITIONS("ProxyRequestContext_IsValid"),\
	EDITIONS("ProxyRequestContext_IsSame"),\
	EDITIONS("ProxyRequestContext_IsSharingWith"),\
	EDITIONS("ProxyRequestContext_IsGlobal"),\
	EDITIONS("ProxyRequestContext_GetCachePath"),\
	EDITIONS("ProxyRequestContext_GetCookieManager"),\
	EDITIONS("ProxyRequestContext_PurgePluginListCache"),\
	EDITIONS("ProxyRequestContext_ClearCertificateExceptions"),\
	EDITIONS("ProxyRequestContext_ClearHttpAuthCredentials"),\
	EDITIONS("ProxyRequestContext_CloseAllConnections"),\


//==========================================

#define DECL_DATA_TYPE_ProxyRequestContext_FUN_CALLS \
	EDITIONF(ProxyRequestContext_Constructor),\
	EDITIONF(ProxyRequestContext_Destructor),\
	EDITIONF(ProxyRequestContext_CopyConstructor),\
	EDITIONF(ProxyRequestContext_GetGlobalContext),\
	EDITIONF(ProxyRequestContext_CreateContext),\
	EDITIONF(ProxyRequestContext_CreateContextWith),\
	EDITIONF(ProxyRequestContext_IsValid),\
	EDITIONF(ProxyRequestContext_IsSame),\
	EDITIONF(ProxyRequestContext_IsSharingWith),\
	EDITIONF(ProxyRequestContext_IsGlobal),\
	EDITIONF(ProxyRequestContext_GetCachePath),\
	EDITIONF(ProxyRequestContext_GetCookieManager),\
	EDITIONF(ProxyRequestContext_PurgePluginListCache),\
	EDITIONF(ProxyRequestContext_ClearCertificateExceptions),\
	EDITIONF(ProxyRequestContext_ClearHttpAuthCredentials),\
	EDITIONF(ProxyRequestContext_CloseAllConnections),\


//==========================================

extern "C"
void EDITIONF(ProxyRequestContext_Constructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyRequestContext_Destructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyRequestContext_CopyConstructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyRequestContext_GetGlobalContext) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyRequestContext_CreateContext) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyRequestContext_CreateContextWith) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyRequestContext_IsValid) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyRequestContext_IsSame) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyRequestContext_IsSharingWith) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyRequestContext_IsGlobal) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyRequestContext_GetCachePath) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyRequestContext_GetCookieManager) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyRequestContext_PurgePluginListCache) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyRequestContext_ClearCertificateExceptions) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyRequestContext_ClearHttpAuthCredentials) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyRequestContext_CloseAllConnections) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);


//==========================================

