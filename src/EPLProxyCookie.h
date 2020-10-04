#pragma once

#include "stdafx.h"
#include "lib2.h"


#define DECL_DATA_TYPE_ProxyCookie \
	{ /*9*/ \
		/*m_szName*/		 _WT("ChromiumCOOKIE"), \
		/*m_szEgName*/		 _WT("ProxyCookie"), \
		/*m_szExplain*/		 _WT("cookie 信息"), \
		/*m_nCmdCount*/		 25, \
		/*m_pnCmdsIndex*/		 s_nProxyCookieElementCmdIndex, \
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

#define DECL_DATA_TYPE_ProxyCookie_ARGINFO \
	{ /****** ProxyCookie::SetName ** 0 **/ \
		/*name*/	 _WT("name"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_TEXT, \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxyCookie::SetValue ** 1 **/ \
		/*name*/	 _WT("值"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_TEXT, \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxyCookie::SetDomain ** 2 **/ \
		/*name*/	 _WT("域值"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_TEXT, \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxyCookie::SetPath ** 3 **/ \
		/*name*/	 _WT("路径"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_TEXT, \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxyCookie::SetSecure ** 4 **/ \
		/*name*/	 _WT("安全性"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxyCookie::SetHttponly ** 5 **/ \
		/*name*/	 _WT("httponly"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxyCookie::SetCreation ** 6 **/ \
		/*name*/	 _WT("创建时间"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 MAKELONG(34,0),  /*shrewd_ptr<ProxyTime>*/ \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxyCookie::SetLastAccess ** 7 **/ \
		/*name*/	 _WT("最后访问时间"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 MAKELONG(34,0),  /*shrewd_ptr<ProxyTime>*/ \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxyCookie::SetHasExpires ** 8 **/ \
		/*name*/	 _WT("值"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxyCookie::SetExpires ** 9 **/ \
		/*name*/	 _WT("过期时间"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 MAKELONG(34,0),  /*shrewd_ptr<ProxyTime>*/ \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\


//==========================================

#define DECL_DATA_TYPE_ProxyCookie_CMDINFO(BeginIndex) \
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
		/*ccname*/	_WT("创建对象"),\
		/*egname*/	_WT("Create"), \
		/*explain*/	_WT("创建对象实例, 非静态对象, 需要调用此函数后才能够有效访问。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	MAKELONG(10,0),  /*shrewd_ptr<ProxyCookie>*/ \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	0, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+0] \
	},\
	{ /*4*/ \
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
	{ /*5*/ \
		/*ccname*/	_WT("设置名称"),\
		/*egname*/	_WT("SetName"), \
		/*explain*/	_WT("设置 cookie 名称。"), \
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
	{ /*6*/ \
		/*ccname*/	_WT("获取名称"),\
		/*egname*/	_WT("GetName"), \
		/*explain*/	_WT("获取 cookie 名称。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	SDT_TEXT, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	0, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+1] \
	},\
	{ /*7*/ \
		/*ccname*/	_WT("设置值"),\
		/*egname*/	_WT("SetValue"), \
		/*explain*/	_WT("设置 cookie 值。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	_SDT_NULL, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	1, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+1] \
	},\
	{ /*8*/ \
		/*ccname*/	_WT("获取值"),\
		/*egname*/	_WT("GetValue"), \
		/*explain*/	_WT("获取 cookie 值。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	SDT_TEXT, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	0, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+2] \
	},\
	{ /*9*/ \
		/*ccname*/	_WT("设置域"),\
		/*egname*/	_WT("SetDomain"), \
		/*explain*/	_WT("如果域值为空, 将创建主机cookie 而不是域cookie。域cookie应该以\".\"开头进行设置。并且对子域可见, 而对主机cookie则不可见。"), \
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
	{ /*10*/ \
		/*ccname*/	_WT("获取域"),\
		/*egname*/	_WT("GetDomain"), \
		/*explain*/	_WT(""), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	SDT_TEXT, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	0, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+3] \
	},\
	{ /*11*/ \
		/*ccname*/	_WT("设置路径"),\
		/*egname*/	_WT("SetPath"), \
		/*explain*/	_WT("如果路径值不为空, 则只有此路径中或路径以下的URL会获取cookie值。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	_SDT_NULL, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	1, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+3] \
	},\
	{ /*12*/ \
		/*ccname*/	_WT("获取路径"),\
		/*egname*/	_WT("GetPath"), \
		/*explain*/	_WT(""), \
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
	{ /*13*/ \
		/*ccname*/	_WT("设置安全性"),\
		/*egname*/	_WT("SetSecure"), \
		/*explain*/	_WT("设置此值为1, 将仅针对HTTPS请求才发送此cookie。"), \
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
	{ /*14*/ \
		/*ccname*/	_WT("获取安全性"),\
		/*egname*/	_WT("GetSecure"), \
		/*explain*/	_WT(""), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	SDT_INT, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	0, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+5] \
	},\
	{ /*15*/ \
		/*ccname*/	_WT("设置仅限HTTP属性"),\
		/*egname*/	_WT("SetHttponly"), \
		/*explain*/	_WT("设置此值为1, cookie将仅在HTTP会话中使用。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	_SDT_NULL, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	1, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+5] \
	},\
	{ /*16*/ \
		/*ccname*/	_WT("获取仅限HTTP属性"),\
		/*egname*/	_WT("GetHttponly"), \
		/*explain*/	_WT(""), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	SDT_INT, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	0, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+6] \
	},\
	{ /*17*/ \
		/*ccname*/	_WT("设置创建时间"),\
		/*egname*/	_WT("SetCreation"), \
		/*explain*/	_WT(""), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	_SDT_NULL, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	1, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+6] \
	},\
	{ /*18*/ \
		/*ccname*/	_WT("获取创建时间"),\
		/*egname*/	_WT("GetCreation"), \
		/*explain*/	_WT(""), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	MAKELONG(34,0),  /*shrewd_ptr<ProxyTime>*/ \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	0, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+7] \
	},\
	{ /*19*/ \
		/*ccname*/	_WT("设置最后访问时间"),\
		/*egname*/	_WT("SetLastAccess"), \
		/*explain*/	_WT(""), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	_SDT_NULL, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	1, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+7] \
	},\
	{ /*20*/ \
		/*ccname*/	_WT("获取最后访问时间"),\
		/*egname*/	_WT("GetLastAccess"), \
		/*explain*/	_WT(""), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	MAKELONG(34,0),  /*shrewd_ptr<ProxyTime>*/ \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	0, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+8] \
	},\
	{ /*21*/ \
		/*ccname*/	_WT("设置使用有效期"),\
		/*egname*/	_WT("SetHasExpires"), \
		/*explain*/	_WT("设置此值为1, cookie 将具有有效期。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	_SDT_NULL, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	1, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+8] \
	},\
	{ /*22*/ \
		/*ccname*/	_WT("获取使用有效期"),\
		/*egname*/	_WT("GetHasExpires"), \
		/*explain*/	_WT(""), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	SDT_INT, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	0, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+9] \
	},\
	{ /*23*/ \
		/*ccname*/	_WT("设置过期时间"),\
		/*egname*/	_WT("SetExpires"), \
		/*explain*/	_WT("设置 cookie 过期时间。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	_SDT_NULL, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	1, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+9] \
	},\
	{ /*24*/ \
		/*ccname*/	_WT("获取过期时间"),\
		/*egname*/	_WT("GetExpires"), \
		/*explain*/	_WT(""), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	MAKELONG(34,0),  /*shrewd_ptr<ProxyTime>*/ \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	0, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+10] \
	},\


//==========================================

#define DECL_DATA_TYPE_ProxyCookie_FUN_NAMES \
	EDITIONS("ProxyCookie_Constructor"),\
	EDITIONS("ProxyCookie_Destructor"),\
	EDITIONS("ProxyCookie_CopyConstructor"),\
	EDITIONS("ProxyCookie_Create"),\
	EDITIONS("ProxyCookie_IsValid"),\
	EDITIONS("ProxyCookie_SetName"),\
	EDITIONS("ProxyCookie_GetName"),\
	EDITIONS("ProxyCookie_SetValue"),\
	EDITIONS("ProxyCookie_GetValue"),\
	EDITIONS("ProxyCookie_SetDomain"),\
	EDITIONS("ProxyCookie_GetDomain"),\
	EDITIONS("ProxyCookie_SetPath"),\
	EDITIONS("ProxyCookie_GetPath"),\
	EDITIONS("ProxyCookie_SetSecure"),\
	EDITIONS("ProxyCookie_GetSecure"),\
	EDITIONS("ProxyCookie_SetHttponly"),\
	EDITIONS("ProxyCookie_GetHttponly"),\
	EDITIONS("ProxyCookie_SetCreation"),\
	EDITIONS("ProxyCookie_GetCreation"),\
	EDITIONS("ProxyCookie_SetLastAccess"),\
	EDITIONS("ProxyCookie_GetLastAccess"),\
	EDITIONS("ProxyCookie_SetHasExpires"),\
	EDITIONS("ProxyCookie_GetHasExpires"),\
	EDITIONS("ProxyCookie_SetExpires"),\
	EDITIONS("ProxyCookie_GetExpires"),\


//==========================================

#define DECL_DATA_TYPE_ProxyCookie_FUN_CALLS \
	EDITIONF(ProxyCookie_Constructor),\
	EDITIONF(ProxyCookie_Destructor),\
	EDITIONF(ProxyCookie_CopyConstructor),\
	EDITIONF(ProxyCookie_Create),\
	EDITIONF(ProxyCookie_IsValid),\
	EDITIONF(ProxyCookie_SetName),\
	EDITIONF(ProxyCookie_GetName),\
	EDITIONF(ProxyCookie_SetValue),\
	EDITIONF(ProxyCookie_GetValue),\
	EDITIONF(ProxyCookie_SetDomain),\
	EDITIONF(ProxyCookie_GetDomain),\
	EDITIONF(ProxyCookie_SetPath),\
	EDITIONF(ProxyCookie_GetPath),\
	EDITIONF(ProxyCookie_SetSecure),\
	EDITIONF(ProxyCookie_GetSecure),\
	EDITIONF(ProxyCookie_SetHttponly),\
	EDITIONF(ProxyCookie_GetHttponly),\
	EDITIONF(ProxyCookie_SetCreation),\
	EDITIONF(ProxyCookie_GetCreation),\
	EDITIONF(ProxyCookie_SetLastAccess),\
	EDITIONF(ProxyCookie_GetLastAccess),\
	EDITIONF(ProxyCookie_SetHasExpires),\
	EDITIONF(ProxyCookie_GetHasExpires),\
	EDITIONF(ProxyCookie_SetExpires),\
	EDITIONF(ProxyCookie_GetExpires),\


//==========================================

extern "C"
void EDITIONF(ProxyCookie_Constructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyCookie_Destructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyCookie_CopyConstructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyCookie_Create) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyCookie_IsValid) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyCookie_SetName) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyCookie_GetName) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyCookie_SetValue) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyCookie_GetValue) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyCookie_SetDomain) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyCookie_GetDomain) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyCookie_SetPath) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyCookie_GetPath) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyCookie_SetSecure) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyCookie_GetSecure) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyCookie_SetHttponly) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyCookie_GetHttponly) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyCookie_SetCreation) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyCookie_GetCreation) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyCookie_SetLastAccess) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyCookie_GetLastAccess) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyCookie_SetHasExpires) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyCookie_GetHasExpires) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyCookie_SetExpires) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyCookie_GetExpires) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);


//==========================================

