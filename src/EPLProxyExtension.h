#pragma once

#include "stdafx.h"
#include "lib2.h"


#define DECL_DATA_TYPE_ProxyExtension \
	{ /*15*/ \
		/*m_szName*/		 _WT("水星扩展程序"), \
		/*m_szEgName*/		 _WT("ProxyExtension"), \
		/*m_szExplain*/		 _WT("用于管理 chrome extension 扩展应用程序的类。"), \
		/*m_nCmdCount*/		 10, \
		/*m_pnCmdsIndex*/		 s_nProxyExtensionElementCmdIndex, \
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

#define DECL_DATA_TYPE_ProxyExtension_ARGINFO \
	{ /****** ProxyExtension::IsSame ** 0 **/ \
		/*name*/	 _WT("比较对象"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 MAKELONG(15,0),  /*shrewd_ptr<ProxyExtension>*/ \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\


//==========================================

#define DECL_DATA_TYPE_ProxyExtension_CMDINFO(BeginIndex) \
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
		/*ccname*/	_WT("取标识符"),\
		/*egname*/	_WT("GetIdentifier"), \
		/*explain*/	_WT("返回唯一的扩展程序标识符(ID), 这是根据扩展公共密钥(如果有)或扩展路径来计算的。有关详细信息, 请参见: https://developer.chrome.com/extensions/manifest/key"), \
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
		/*ccname*/	_WT("取路径"),\
		/*egname*/	_WT("GetPath"), \
		/*explain*/	_WT("返回磁盘上扩展程序所在目录的绝对路径。如果载入扩展程序时使用的是相对路径, 则此值将返回带有PK_DIR_RESOURCES前缀的路径字符串。"), \
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
		/*ccname*/	_WT("取清单列表"),\
		/*egname*/	_WT("GetManifest"), \
		/*explain*/	_WT("返回扩展程序的清单内容。有关详细信息, 请参见: https://developer.chrome.com/extensions/manifest"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	MAKELONG(11,0),  /*shrewd_ptr<ProxyDictionaryValue>*/ \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	0, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+0] \
	},\
	{ /*7*/ \
		/*ccname*/	_WT("是否相同"),\
		/*egname*/	_WT("IsSame"), \
		/*explain*/	_WT("比较两个对象是否相同。"), \
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
	{ /*8*/ \
		/*ccname*/	_WT("是否已载入"),\
		/*egname*/	_WT("IsLoaded"), \
		/*explain*/	_WT("如果当前已加载此扩展程序返回真。"), \
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
	{ /*9*/ \
		/*ccname*/	_WT("卸载"),\
		/*egname*/	_WT("Unload"), \
		/*explain*/	_WT("如果此扩展程序非系统扩展程序则卸载此扩展程序。"), \
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

#define DECL_DATA_TYPE_ProxyExtension_FUN_NAMES \
	EDITIONS("ProxyExtension_Constructor"),\
	EDITIONS("ProxyExtension_Destructor"),\
	EDITIONS("ProxyExtension_CopyConstructor"),\
	EDITIONS("ProxyExtension_IsValid"),\
	EDITIONS("ProxyExtension_GetIdentifier"),\
	EDITIONS("ProxyExtension_GetPath"),\
	EDITIONS("ProxyExtension_GetManifest"),\
	EDITIONS("ProxyExtension_IsSame"),\
	EDITIONS("ProxyExtension_IsLoaded"),\
	EDITIONS("ProxyExtension_Unload"),\


//==========================================

#define DECL_DATA_TYPE_ProxyExtension_FUN_CALLS \
	EDITIONF(ProxyExtension_Constructor),\
	EDITIONF(ProxyExtension_Destructor),\
	EDITIONF(ProxyExtension_CopyConstructor),\
	EDITIONF(ProxyExtension_IsValid),\
	EDITIONF(ProxyExtension_GetIdentifier),\
	EDITIONF(ProxyExtension_GetPath),\
	EDITIONF(ProxyExtension_GetManifest),\
	EDITIONF(ProxyExtension_IsSame),\
	EDITIONF(ProxyExtension_IsLoaded),\
	EDITIONF(ProxyExtension_Unload),\


//==========================================

extern "C"
void EDITIONF(ProxyExtension_Constructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyExtension_Destructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyExtension_CopyConstructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyExtension_IsValid) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyExtension_GetIdentifier) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyExtension_GetPath) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyExtension_GetManifest) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyExtension_IsSame) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyExtension_IsLoaded) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyExtension_Unload) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);


//==========================================

