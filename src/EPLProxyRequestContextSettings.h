#pragma once

#include "stdafx.h"
#include "lib2.h"


#define DECL_DATA_TYPE_ProxyRequestContextSettings \
	{ /*27*/ \
		/*m_szName*/		 _WT("Chromium会话环境设置"), \
		/*m_szEgName*/		 _WT("ProxyRequestContextSettings"), \
		/*m_szExplain*/		 _WT("会话环境初始化设置。"), \
		/*m_nCmdCount*/		 10, \
		/*m_pnCmdsIndex*/		 s_nProxyRequestContextSettingsElementCmdIndex, \
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

#define DECL_DATA_TYPE_ProxyRequestContextSettings_ARGINFO \
	{ /****** ProxyRequestContextSettings::SetCachePath ** 0 **/ \
		/*name*/	 _WT("缓存目录"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_TEXT, \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxyRequestContextSettings::SetPersistSessionCookies ** 1 **/ \
		/*name*/	 _WT("值"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxyRequestContextSettings::SetPersistUserPreferences ** 2 **/ \
		/*name*/	 _WT("值"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxyRequestContextSettings::SetIgnoreCertificateErrors ** 3 **/ \
		/*name*/	 _WT("值"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxyRequestContextSettings::SetAcceptLanguageList ** 4 **/ \
		/*name*/	 _WT("值"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_TEXT, \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\


//==========================================

#define DECL_DATA_TYPE_ProxyRequestContextSettings_CMDINFO(BeginIndex) \
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
		/*ret*/	MAKELONG(28,0),  /*shrewd_ptr<ProxyRequestContextSettings>*/ \
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
		/*ccname*/	_WT("设置缓存目录"),\
		/*egname*/	_WT("SetCachePath"), \
		/*explain*/	_WT("设置使用的缓存目录。"), \
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
		/*ccname*/	_WT("设置保持会话COOKIES"),\
		/*egname*/	_WT("SetPersistSessionCookies"), \
		/*explain*/	_WT("设置此值为1, 在COOKIE管理器中保留会话COOKIES。"), \
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
	{ /*7*/ \
		/*ccname*/	_WT("设置保持用户首选项"),\
		/*egname*/	_WT("SetPersistUserPreferences"), \
		/*explain*/	_WT("设置此值为1, 用户首选项数据将使用JSON文件保留到缓存目录中。"), \
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
	{ /*8*/ \
		/*ccname*/	_WT("设置忽略SSL证书错误"),\
		/*egname*/	_WT("SetIgnoreCertificateErrors"), \
		/*explain*/	_WT("设置此值为1, 可在此会话环境中忽略与无效SSL证书有关的错误。"), \
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
	{ /*9*/ \
		/*ccname*/	_WT("设置HTTP接收语言字符串"),\
		/*egname*/	_WT("SetAcceptLanguageList"), \
		/*explain*/	_WT("设置全局的HTTP接收语言字符串,以逗号分隔的语言代码字符串数组,不可以使用空格, 这些字符串值将在\"Accept-Language\" HTTP标头中使用。"), \
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


//==========================================

#define DECL_DATA_TYPE_ProxyRequestContextSettings_FUN_NAMES \
	EDITIONS("ProxyRequestContextSettings_Constructor"),\
	EDITIONS("ProxyRequestContextSettings_Destructor"),\
	EDITIONS("ProxyRequestContextSettings_CopyConstructor"),\
	EDITIONS("ProxyRequestContextSettings_Create"),\
	EDITIONS("ProxyRequestContextSettings_IsValid"),\
	EDITIONS("ProxyRequestContextSettings_SetCachePath"),\
	EDITIONS("ProxyRequestContextSettings_SetPersistSessionCookies"),\
	EDITIONS("ProxyRequestContextSettings_SetPersistUserPreferences"),\
	EDITIONS("ProxyRequestContextSettings_SetIgnoreCertificateErrors"),\
	EDITIONS("ProxyRequestContextSettings_SetAcceptLanguageList"),\


//==========================================

#define DECL_DATA_TYPE_ProxyRequestContextSettings_FUN_CALLS \
	EDITIONF(ProxyRequestContextSettings_Constructor),\
	EDITIONF(ProxyRequestContextSettings_Destructor),\
	EDITIONF(ProxyRequestContextSettings_CopyConstructor),\
	EDITIONF(ProxyRequestContextSettings_Create),\
	EDITIONF(ProxyRequestContextSettings_IsValid),\
	EDITIONF(ProxyRequestContextSettings_SetCachePath),\
	EDITIONF(ProxyRequestContextSettings_SetPersistSessionCookies),\
	EDITIONF(ProxyRequestContextSettings_SetPersistUserPreferences),\
	EDITIONF(ProxyRequestContextSettings_SetIgnoreCertificateErrors),\
	EDITIONF(ProxyRequestContextSettings_SetAcceptLanguageList),\


//==========================================

extern "C"
void EDITIONF(ProxyRequestContextSettings_Constructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyRequestContextSettings_Destructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyRequestContextSettings_CopyConstructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyRequestContextSettings_Create) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyRequestContextSettings_IsValid) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyRequestContextSettings_SetCachePath) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyRequestContextSettings_SetPersistSessionCookies) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyRequestContextSettings_SetPersistUserPreferences) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyRequestContextSettings_SetIgnoreCertificateErrors) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyRequestContextSettings_SetAcceptLanguageList) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);


//==========================================

