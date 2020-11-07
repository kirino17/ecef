#pragma once

#include "stdafx.h"
#include "lib2.h"


#define DECL_DATA_TYPE_ProxySettings \
	{ /*29*/ \
		/*m_szName*/		 _WT("水星初始化设置"), \
		/*m_szEgName*/		 _WT("ProxySettings"), \
		/*m_szExplain*/		 _WT("提供浏览器进程的初始化设置。这些设置用于配置Chromium全局运行参数, 设置为0或空时保持为建议的默认值, 这些设置也使用命令行开关(command-switch)进行配置。"), \
		/*m_nCmdCount*/		 13, \
		/*m_pnCmdsIndex*/		 s_nProxySettingsElementCmdIndex, \
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

#define DECL_DATA_TYPE_ProxySettings_ARGINFO \
	{ /****** ProxySettings::SetCachePath ** 0 **/ \
		/*name*/	 _WT("缓存路径"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_TEXT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxySettings::SetUserDataPath ** 1 **/ \
		/*name*/	 _WT("路径"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_TEXT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxySettings::SetPersistSessionCookies ** 2 **/ \
		/*name*/	 _WT("值"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxySettings::SetPersistUserPreferences ** 3 **/ \
		/*name*/	 _WT("值"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxySettings::SetUserAgent ** 4 **/ \
		/*name*/	 _WT("标识字符串"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_TEXT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxySettings::SetProductVersion ** 5 **/ \
		/*name*/	 _WT("产品标识"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_TEXT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxySettings::SetLocale ** 6 **/ \
		/*name*/	 _WT("语言标识"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_TEXT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxySettings::SetIgnoreCertificateErrors ** 7 **/ \
		/*name*/	 _WT("值"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxySettings::SetAcceptLanguageList ** 8 **/ \
		/*name*/	 _WT("语言字符串"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_TEXT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\


//==========================================

#define DECL_DATA_TYPE_ProxySettings_CMDINFO(BeginIndex) \
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
		/*ccname*/	_WT("全局缓存目录"),\
		/*egname*/	_WT("SetCachePath"), \
		/*explain*/	_WT("设置浏览器全局缓存目录, 此值作为所有浏览器创建时使用的缺省值, 如非特别指定, 所有的浏览器都将会共享此设置。保持为空时则默认不会将数据存储到磁盘上。"), \
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
	{ /*5*/ \
		/*ccname*/	_WT("用户数据目录"),\
		/*egname*/	_WT("SetUserDataPath"), \
		/*explain*/	_WT("设置用户数据存储(例如拼写检查字段文件)位置。此值作为所有浏览器创建时使用的缺省值, 如非特别指定, 所有的浏览器都将会共享此设置。保持为空时则默认不会将数据存储到磁盘上。"), \
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
	{ /*6*/ \
		/*ccname*/	_WT("保持会话COOKIES"),\
		/*egname*/	_WT("SetPersistSessionCookies"), \
		/*explain*/	_WT("设置此值为1, 在全局COOKIE管理器中保留会话COOKIE(它们将没有有效期)。"), \
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
	{ /*7*/ \
		/*ccname*/	_WT("保持用户首选项"),\
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
		/*arg lp*/	&s_ArgInfo[BeginIndex+3] \
	},\
	{ /*8*/ \
		/*ccname*/	_WT("用户代理标识"),\
		/*egname*/	_WT("SetUserAgent"), \
		/*explain*/	_WT("设置此值作为: User-Agent HTTP 标头的返回值。"), \
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
	{ /*9*/ \
		/*ccname*/	_WT("产品标识"),\
		/*egname*/	_WT("SetProductVersion"), \
		/*explain*/	_WT("设置此值作为默认 User-Agent 字符串的产品部分插入的值。"), \
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
	{ /*10*/ \
		/*ccname*/	_WT("语言环境"),\
		/*egname*/	_WT("SetLocale"), \
		/*explain*/	_WT("设置浏览器语言环境字符串。"), \
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
	{ /*11*/ \
		/*ccname*/	_WT("忽略SSL证书错误"),\
		/*egname*/	_WT("SetIgnoreCertificateErrors"), \
		/*explain*/	_WT("设置此值为1, 可忽略于无效SSL证书有关的错误。"), \
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
	{ /*12*/ \
		/*ccname*/	_WT("接收语言字符串"),\
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
		/*arg lp*/	&s_ArgInfo[BeginIndex+8] \
	},\


//==========================================

#define DECL_DATA_TYPE_ProxySettings_FUN_NAMES \
	EDITIONS("ProxySettings_Constructor"),\
	EDITIONS("ProxySettings_Destructor"),\
	EDITIONS("ProxySettings_CopyConstructor"),\
	EDITIONS("ProxySettings_IsValid"),\
	EDITIONS("ProxySettings_SetCachePath"),\
	EDITIONS("ProxySettings_SetUserDataPath"),\
	EDITIONS("ProxySettings_SetPersistSessionCookies"),\
	EDITIONS("ProxySettings_SetPersistUserPreferences"),\
	EDITIONS("ProxySettings_SetUserAgent"),\
	EDITIONS("ProxySettings_SetProductVersion"),\
	EDITIONS("ProxySettings_SetLocale"),\
	EDITIONS("ProxySettings_SetIgnoreCertificateErrors"),\
	EDITIONS("ProxySettings_SetAcceptLanguageList"),\


//==========================================

#define DECL_DATA_TYPE_ProxySettings_FUN_CALLS \
	EDITIONF(ProxySettings_Constructor),\
	EDITIONF(ProxySettings_Destructor),\
	EDITIONF(ProxySettings_CopyConstructor),\
	EDITIONF(ProxySettings_IsValid),\
	EDITIONF(ProxySettings_SetCachePath),\
	EDITIONF(ProxySettings_SetUserDataPath),\
	EDITIONF(ProxySettings_SetPersistSessionCookies),\
	EDITIONF(ProxySettings_SetPersistUserPreferences),\
	EDITIONF(ProxySettings_SetUserAgent),\
	EDITIONF(ProxySettings_SetProductVersion),\
	EDITIONF(ProxySettings_SetLocale),\
	EDITIONF(ProxySettings_SetIgnoreCertificateErrors),\
	EDITIONF(ProxySettings_SetAcceptLanguageList),\


//==========================================

extern "C"
void EDITIONF(ProxySettings_Constructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxySettings_Destructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxySettings_CopyConstructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxySettings_IsValid) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxySettings_SetCachePath) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxySettings_SetUserDataPath) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxySettings_SetPersistSessionCookies) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxySettings_SetPersistUserPreferences) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxySettings_SetUserAgent) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxySettings_SetProductVersion) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxySettings_SetLocale) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxySettings_SetIgnoreCertificateErrors) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxySettings_SetAcceptLanguageList) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);


//==========================================

