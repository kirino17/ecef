#pragma once

#include "stdafx.h"
#include "lib2.h"


#define DECL_DATA_TYPE_ProxyCookieManager \
	{ /*10*/ \
		/*m_szName*/		 _WT("ChromiumCOOKIE管理器"), \
		/*m_szEgName*/		 _WT("ProxyCookieManager"), \
		/*m_szExplain*/		 _WT("用于管理 cookie 的累。除非另有说明, 否则可以在任何线程上调用此类的方法。"), \
		/*m_nCmdCount*/		 11, \
		/*m_pnCmdsIndex*/		 s_nProxyCookieManagerElementCmdIndex, \
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

#define DECL_DATA_TYPE_ProxyCookieManager_ARGINFO \
	{ /****** ProxyCookieManager::SetSupportedSchemes ** 0 **/ \
		/*name*/	 _WT("schemes"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_TEXT, \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxyCookieManager::SetSupportedSchemes ** 1 **/ \
		/*name*/	 _WT("include_defaults"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_BOOL, \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxyCookieManager::VisitUrlCookies ** 2 **/ \
		/*name*/	 _WT("url"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_TEXT, \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxyCookieManager::VisitUrlCookies ** 3 **/ \
		/*name*/	 _WT("includeHttpOnly"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_BOOL, \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxyCookieManager::SetCookie ** 4 **/ \
		/*name*/	 _WT("url"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_TEXT, \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxyCookieManager::SetCookie ** 5 **/ \
		/*name*/	 _WT("cookie"), \
		/*explain*/	 _WT("cookie属性"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 MAKELONG(10,0),  /*shrewd_ptr<ProxyCookie>*/ \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxyCookieManager::DeleteCookies ** 6 **/ \
		/*name*/	 _WT("url"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_TEXT, \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxyCookieManager::DeleteCookies ** 7 **/ \
		/*name*/	 _WT("cookie_name"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_TEXT, \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\


//==========================================

#define DECL_DATA_TYPE_ProxyCookieManager_CMDINFO(BeginIndex) \
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
		/*ccname*/	_WT("取全局实例"),\
		/*egname*/	_WT("GetGlobalManager"), \
		/*explain*/	_WT("获取全局的Cookieg管理器实例。默认情况下, 数据将存储在全局缓存目录中(如果已指定), 否则这些数据将只会保留在内存中, 不会写出到磁盘上。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	MAKELONG(11,0),  /*shrewd_ptr<ProxyCookieManager>*/ \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	0, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+0] \
	},\
	{ /*5*/ \
		/*ccname*/	_WT("SetSupportedSchemes"),\
		/*egname*/	_WT("SetSupportedSchemes"), \
		/*explain*/	_WT("Set the schemes supported by this manager.If |include_defaults| is true the default schemes (\"http\", \"https\", \"ws\" and \"wss\") will also be supported. Calling this method with an empty |schemes| value and |include_defaults| set to false will disable all loading and saving of cookies for this manager."), \
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
	{ /*6*/ \
		/*ccname*/	_WT("VisitAllCookies"),\
		/*egname*/	_WT("VisitAllCookies"), \
		/*explain*/	_WT("访问所有cookies。 返回的cookie由事件\"OnCookieVisitor\"传递, cookie的传递顺序根据最长路径来选择, 在然后是最早的创建日期。"), \
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
		/*ccname*/	_WT("VisitUrlCookies"),\
		/*egname*/	_WT("VisitUrlCookies"), \
		/*explain*/	_WT("访问指定url下的所有cookies。返回的cookie由事件\"OnCookieVisitor\"传递, cookie的传递顺序根据最长路径来选择, 在然后是最早的创建日期。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	SDT_BOOL, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	2, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+2] \
	},\
	{ /*8*/ \
		/*ccname*/	_WT("SetCookie"),\
		/*egname*/	_WT("SetCookie"), \
		/*explain*/	_WT("设置一个具有有效URL和cookie属性的cookie。设置的cookie属性应该使用标准的格式输入, 在此函数中将会检查cookie中是否存在非法字符(例如: \";\"是不允许出现在cookie.value中的),如果出现了这样的字符此函数将不会设置此cookie属性并返回失败。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	SDT_BOOL, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	2, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+4] \
	},\
	{ /*9*/ \
		/*ccname*/	_WT("DeleteCookies"),\
		/*egname*/	_WT("DeleteCookies"), \
		/*explain*/	_WT("删除与指定参数匹配的cookie。如果指定了 |url| 和 |cookie_name| 那么将仅删除与其相符的cookie。如果仅指定|url|所有与其相符的cookie都将删除(但不包括域cookie)。如果|url|为空则将删除所有主机和域的cookies。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	SDT_BOOL, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	2, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+6] \
	},\
	{ /*10*/ \
		/*ccname*/	_WT("FlushStore"),\
		/*egname*/	_WT("FlushStore"), \
		/*explain*/	_WT("将在内存中的存储数据(如果有的话)写入到磁盘上。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	SDT_BOOL, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	0, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+8] \
	},\


//==========================================

#define DECL_DATA_TYPE_ProxyCookieManager_FUN_NAMES \
	EDITIONS("ProxyCookieManager_Constructor"),\
	EDITIONS("ProxyCookieManager_Destructor"),\
	EDITIONS("ProxyCookieManager_CopyConstructor"),\
	EDITIONS("ProxyCookieManager_IsValid"),\
	EDITIONS("ProxyCookieManager_GetGlobalManager"),\
	EDITIONS("ProxyCookieManager_SetSupportedSchemes"),\
	EDITIONS("ProxyCookieManager_VisitAllCookies"),\
	EDITIONS("ProxyCookieManager_VisitUrlCookies"),\
	EDITIONS("ProxyCookieManager_SetCookie"),\
	EDITIONS("ProxyCookieManager_DeleteCookies"),\
	EDITIONS("ProxyCookieManager_FlushStore"),\


//==========================================

#define DECL_DATA_TYPE_ProxyCookieManager_FUN_CALLS \
	EDITIONF(ProxyCookieManager_Constructor),\
	EDITIONF(ProxyCookieManager_Destructor),\
	EDITIONF(ProxyCookieManager_CopyConstructor),\
	EDITIONF(ProxyCookieManager_IsValid),\
	EDITIONF(ProxyCookieManager_GetGlobalManager),\
	EDITIONF(ProxyCookieManager_SetSupportedSchemes),\
	EDITIONF(ProxyCookieManager_VisitAllCookies),\
	EDITIONF(ProxyCookieManager_VisitUrlCookies),\
	EDITIONF(ProxyCookieManager_SetCookie),\
	EDITIONF(ProxyCookieManager_DeleteCookies),\
	EDITIONF(ProxyCookieManager_FlushStore),\


//==========================================

extern "C"
void EDITIONF(ProxyCookieManager_Constructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyCookieManager_Destructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyCookieManager_CopyConstructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyCookieManager_IsValid) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyCookieManager_GetGlobalManager) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyCookieManager_SetSupportedSchemes) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyCookieManager_VisitAllCookies) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyCookieManager_VisitUrlCookies) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyCookieManager_SetCookie) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyCookieManager_DeleteCookies) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyCookieManager_FlushStore) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);


//==========================================

