#pragma once

#include "stdafx.h"
#include "lib2.h"


#define DECL_DATA_TYPE_ProxyGetExtensionResourceCallback \
	{ /*18*/ \
		/*m_szName*/		 _WT("水星扩展程序资源获取回调"), \
		/*m_szEgName*/		 _WT("ProxyGetExtensionResourceCallback"), \
		/*m_szExplain*/		 _WT("用于扩展程序获取资源事件的异步延续回调接口, 使用此接口回复扩展程序资源获取请求。"), \
		/*m_nCmdCount*/		 6, \
		/*m_pnCmdsIndex*/		 s_nProxyGetExtensionResourceCallbackElementCmdIndex, \
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

#define DECL_DATA_TYPE_ProxyGetExtensionResourceCallback_ARGINFO \
	{ /****** ProxyGetExtensionResourceCallback::ContinueWithData ** 0 **/ \
		/*name*/	 _WT("资源内容"), \
		/*explain*/	 _WT("获取资源的字节集内容"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_BIN, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyGetExtensionResourceCallback::ContinueWithData ** 1 **/ \
		/*name*/	 _WT("资源长度"), \
		/*explain*/	 _WT("获取资源的内容字节长度"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyGetExtensionResourceCallback::ContinueWithFile ** 2 **/ \
		/*name*/	 _WT("文件名"), \
		/*explain*/	 _WT("获取资源的文件名"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_TEXT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\


//==========================================

#define DECL_DATA_TYPE_ProxyGetExtensionResourceCallback_CMDINFO(BeginIndex) \
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
		/*ccname*/	_WT("允许获取提供字节集"),\
		/*egname*/	_WT("ContinueWithData"), \
		/*explain*/	_WT("允许扩展程序获取此资源, 并为扩展程序提供此资源的字节集数据。"), \
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
	{ /*4*/ \
		/*ccname*/	_WT("允许获取提供文件"),\
		/*egname*/	_WT("ContinueWithFile"), \
		/*explain*/	_WT("允许扩展程序获取此资源, 并为扩展程序提供此资源的文件数据。"), \
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
	{ /*5*/ \
		/*ccname*/	_WT("取消获取"),\
		/*egname*/	_WT("Cancel"), \
		/*explain*/	_WT("取消扩展程序的资源获取请求。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	_SDT_NULL, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	0, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+3] \
	},\


//==========================================

#define DECL_DATA_TYPE_ProxyGetExtensionResourceCallback_FUN_NAMES \
	EDITIONS("ProxyGetExtensionResourceCallback_Constructor"),\
	EDITIONS("ProxyGetExtensionResourceCallback_Destructor"),\
	EDITIONS("ProxyGetExtensionResourceCallback_CopyConstructor"),\
	EDITIONS("ProxyGetExtensionResourceCallback_ContinueWithData"),\
	EDITIONS("ProxyGetExtensionResourceCallback_ContinueWithFile"),\
	EDITIONS("ProxyGetExtensionResourceCallback_Cancel"),\


//==========================================

#define DECL_DATA_TYPE_ProxyGetExtensionResourceCallback_FUN_CALLS \
	EDITIONF(ProxyGetExtensionResourceCallback_Constructor),\
	EDITIONF(ProxyGetExtensionResourceCallback_Destructor),\
	EDITIONF(ProxyGetExtensionResourceCallback_CopyConstructor),\
	EDITIONF(ProxyGetExtensionResourceCallback_ContinueWithData),\
	EDITIONF(ProxyGetExtensionResourceCallback_ContinueWithFile),\
	EDITIONF(ProxyGetExtensionResourceCallback_Cancel),\


//==========================================

extern "C"
void EDITIONF(ProxyGetExtensionResourceCallback_Constructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyGetExtensionResourceCallback_Destructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyGetExtensionResourceCallback_CopyConstructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyGetExtensionResourceCallback_ContinueWithData) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyGetExtensionResourceCallback_ContinueWithFile) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyGetExtensionResourceCallback_Cancel) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);


//==========================================

