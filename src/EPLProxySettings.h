#pragma once

#include "stdafx.h"
#include "lib2.h"


#define DECL_DATA_TYPE_ProxySettings \
	{ /*31*/ \
		/*m_szName*/		 _WT("Chromium进程设置"), \
		/*m_szEgName*/		 _WT("ProxySettings"), \
		/*m_szExplain*/		 _WT("提供浏览器进程的初始化设置。这些设置用于配置Chromium全局运行参数, 设置为0或空时保持为建议的默认值, 这些设置也使用命令行开关(command-switch)进行配置。"), \
		/*m_nCmdCount*/		 26, \
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
	{ /****** ProxySettings::SetBrowserSubProcessPath ** 0 **/ \
		/*name*/	 _WT("进程名称"), \
		/*explain*/	 _WT("设置CEF/Chromium浏览器进程的分支进程程序。设置了此参数浏览器将会使用此参数提供的程序来启动子进程。"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_TEXT, \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxySettings::SetMultiThreadedMessageLoop ** 1 **/ \
		/*name*/	 _WT("值"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxySettings::SetExternalMessagePump ** 2 **/ \
		/*name*/	 _WT("value"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxySettings::SetWindowlessRenderingEnabled ** 3 **/ \
		/*name*/	 _WT("value"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxySettings::SetCommandLineArgsDisabled ** 4 **/ \
		/*name*/	 _WT("值"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxySettings::SetCachePath ** 5 **/ \
		/*name*/	 _WT("缓存路径"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_TEXT, \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxySettings::SetRootCachePath ** 6 **/ \
		/*name*/	 _WT("路径"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_TEXT, \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxySettings::SetUserDataPath ** 7 **/ \
		/*name*/	 _WT("路径"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_TEXT, \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxySettings::SetPersistSessionCookies ** 8 **/ \
		/*name*/	 _WT("值"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxySettings::SetPersistUserPreferences ** 9 **/ \
		/*name*/	 _WT("值"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxySettings::SetUserAgent ** 10 **/ \
		/*name*/	 _WT("标识字符串"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_TEXT, \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxySettings::SetProductVersion ** 11 **/ \
		/*name*/	 _WT("产品标识"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_TEXT, \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxySettings::SetLocale ** 12 **/ \
		/*name*/	 _WT("语言标识"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_TEXT, \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxySettings::SetJavascriptFlags ** 13 **/ \
		/*name*/	 _WT("自定义标志"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_TEXT, \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxySettings::SetPackLoadingDisabled ** 14 **/ \
		/*name*/	 _WT("值"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxySettings::SetRemoteDebuggingPort ** 15 **/ \
		/*name*/	 _WT("值"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxySettings::SetUncaughtExceptionStackSize ** 16 **/ \
		/*name*/	 _WT("value"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxySettings::SetIgnoreCertificateErrors ** 17 **/ \
		/*name*/	 _WT("值"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxySettings::SetBackgroundColor ** 18 **/ \
		/*name*/	 _WT("颜色值"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxySettings::SetAcceptLanguageList ** 19 **/ \
		/*name*/	 _WT("语言字符串"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_TEXT, \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxySettings::SetApplicationClientIdForFileScanning ** 20 **/ \
		/*name*/	 _WT("标识"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_TEXT, \
		/*default*/	 0,\
		/*state*/	 NULL\
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
		/*ccname*/	_WT("创建对象"),\
		/*egname*/	_WT("Create"), \
		/*explain*/	_WT("创建对象实例, 非静态对象, 需要调用此函数后才能够有效访问。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	MAKELONG(32,0),  /*shrewd_ptr<ProxySettings>*/ \
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
		/*ccname*/	_WT("设置子进程程序"),\
		/*egname*/	_WT("SetBrowserSubProcessPath"), \
		/*explain*/	_WT("设置多进程模式下, Chromium所使用的分支子进程, 由于本支持仅支持多进程模式, 所以此项参数必须设置有效值。"), \
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
		/*ccname*/	_WT("设置多线程消息循环"),\
		/*egname*/	_WT("SetMultiThreadedMessageLoop"), \
		/*explain*/	_WT("设置为1时启用, 多线程消息循环是CEF / Chromium浏览器进程消息循环的一种模式。它使得浏览器的消息循环运行在独立的线程中, 避免与程序主线程(UI 线程)消息循环之间相互影响。这种模式在CEF/Chromium消息循环模式中不是最高效的设置,但它与易语言的兼容性非常好(如果使用主线程消息循环模式, 程序主线程将与浏览器消息循环线程混杂, 易语言的某些组件消息会被浏览器吞掉), 所以推荐使用该模式。"), \
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
		/*ccname*/	_WT("SetExternalMessagePump"),\
		/*egname*/	_WT("SetExternalMessagePump"), \
		/*explain*/	_WT(""), \
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
		/*ccname*/	_WT("SetWindowlessRenderingEnabled"),\
		/*egname*/	_WT("SetWindowlessRenderingEnabled"), \
		/*explain*/	_WT(""), \
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
		/*ccname*/	_WT("设置禁用命令行开关"),\
		/*egname*/	_WT("SetCommandLineArgsDisabled"), \
		/*explain*/	_WT("此参数设置为1时, Chromium将不再读取命令行中的配置参数。"), \
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
	{ /*10*/ \
		/*ccname*/	_WT("设置全局缓存目录"),\
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
		/*arg lp*/	&s_ArgInfo[BeginIndex+5] \
	},\
	{ /*11*/ \
		/*ccname*/	_WT("设置根目录"),\
		/*egname*/	_WT("SetRootCachePath"), \
		/*explain*/	_WT("设置所有本类对象所使用的根目录。"), \
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
	{ /*12*/ \
		/*ccname*/	_WT("设置用户数据目录"),\
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
		/*arg lp*/	&s_ArgInfo[BeginIndex+7] \
	},\
	{ /*13*/ \
		/*ccname*/	_WT("设置保持会话COOKIES"),\
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
		/*arg lp*/	&s_ArgInfo[BeginIndex+8] \
	},\
	{ /*14*/ \
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
		/*arg lp*/	&s_ArgInfo[BeginIndex+9] \
	},\
	{ /*15*/ \
		/*ccname*/	_WT("设置用户代理标识"),\
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
		/*arg lp*/	&s_ArgInfo[BeginIndex+10] \
	},\
	{ /*16*/ \
		/*ccname*/	_WT("设置产品标识"),\
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
		/*arg lp*/	&s_ArgInfo[BeginIndex+11] \
	},\
	{ /*17*/ \
		/*ccname*/	_WT("设置语言环境"),\
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
		/*arg lp*/	&s_ArgInfo[BeginIndex+12] \
	},\
	{ /*18*/ \
		/*ccname*/	_WT("设置自定义JAVASCRIPT标志值"),\
		/*egname*/	_WT("SetJavascriptFlags"), \
		/*explain*/	_WT("V8 JavaScript引擎初始化时将使用此自定义标志值。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	_SDT_NULL, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	1, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+13] \
	},\
	{ /*19*/ \
		/*ccname*/	_WT("设置禁止加载资源"),\
		/*egname*/	_WT("SetPackLoadingDisabled"), \
		/*explain*/	_WT("设置此值为1, 将禁止浏览器加载资源(包括语言环境的打包文件)。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	_SDT_NULL, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	1, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+14] \
	},\
	{ /*20*/ \
		/*ccname*/	_WT("设置远程调试端口"),\
		/*egname*/	_WT("SetRemoteDebuggingPort"), \
		/*explain*/	_WT("设置浏览器开放的远程调试端口, 端口值应该在: 1024-65535 之间。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	_SDT_NULL, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	1, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+15] \
	},\
	{ /*21*/ \
		/*ccname*/	_WT("SetUncaughtExceptionStackSize"),\
		/*egname*/	_WT("SetUncaughtExceptionStackSize"), \
		/*explain*/	_WT(""), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	_SDT_NULL, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	1, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+16] \
	},\
	{ /*22*/ \
		/*ccname*/	_WT("设置忽略SSL证书错误"),\
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
		/*arg lp*/	&s_ArgInfo[BeginIndex+17] \
	},\
	{ /*23*/ \
		/*ccname*/	_WT("设置背景颜色"),\
		/*egname*/	_WT("SetBackgroundColor"), \
		/*explain*/	_WT("设置加载文档之前和未指定文档颜色时浏览器使用的背景色。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	_SDT_NULL, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	1, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+18] \
	},\
	{ /*24*/ \
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
		/*arg lp*/	&s_ArgInfo[BeginIndex+19] \
	},\
	{ /*25*/ \
		/*ccname*/	_WT("设置应用程序标识"),\
		/*egname*/	_WT("SetApplicationClientIdForFileScanning"), \
		/*explain*/	_WT("设置用于标识应用程序的GUID字符串。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	_SDT_NULL, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	1, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+20] \
	},\


//==========================================

#define DECL_DATA_TYPE_ProxySettings_FUN_NAMES \
	EDITIONS("ProxySettings_Constructor"),\
	EDITIONS("ProxySettings_Destructor"),\
	EDITIONS("ProxySettings_CopyConstructor"),\
	EDITIONS("ProxySettings_Create"),\
	EDITIONS("ProxySettings_IsValid"),\
	EDITIONS("ProxySettings_SetBrowserSubProcessPath"),\
	EDITIONS("ProxySettings_SetMultiThreadedMessageLoop"),\
	EDITIONS("ProxySettings_SetExternalMessagePump"),\
	EDITIONS("ProxySettings_SetWindowlessRenderingEnabled"),\
	EDITIONS("ProxySettings_SetCommandLineArgsDisabled"),\
	EDITIONS("ProxySettings_SetCachePath"),\
	EDITIONS("ProxySettings_SetRootCachePath"),\
	EDITIONS("ProxySettings_SetUserDataPath"),\
	EDITIONS("ProxySettings_SetPersistSessionCookies"),\
	EDITIONS("ProxySettings_SetPersistUserPreferences"),\
	EDITIONS("ProxySettings_SetUserAgent"),\
	EDITIONS("ProxySettings_SetProductVersion"),\
	EDITIONS("ProxySettings_SetLocale"),\
	EDITIONS("ProxySettings_SetJavascriptFlags"),\
	EDITIONS("ProxySettings_SetPackLoadingDisabled"),\
	EDITIONS("ProxySettings_SetRemoteDebuggingPort"),\
	EDITIONS("ProxySettings_SetUncaughtExceptionStackSize"),\
	EDITIONS("ProxySettings_SetIgnoreCertificateErrors"),\
	EDITIONS("ProxySettings_SetBackgroundColor"),\
	EDITIONS("ProxySettings_SetAcceptLanguageList"),\
	EDITIONS("ProxySettings_SetApplicationClientIdForFileScanning"),\


//==========================================

#define DECL_DATA_TYPE_ProxySettings_FUN_CALLS \
	EDITIONF(ProxySettings_Constructor),\
	EDITIONF(ProxySettings_Destructor),\
	EDITIONF(ProxySettings_CopyConstructor),\
	EDITIONF(ProxySettings_Create),\
	EDITIONF(ProxySettings_IsValid),\
	EDITIONF(ProxySettings_SetBrowserSubProcessPath),\
	EDITIONF(ProxySettings_SetMultiThreadedMessageLoop),\
	EDITIONF(ProxySettings_SetExternalMessagePump),\
	EDITIONF(ProxySettings_SetWindowlessRenderingEnabled),\
	EDITIONF(ProxySettings_SetCommandLineArgsDisabled),\
	EDITIONF(ProxySettings_SetCachePath),\
	EDITIONF(ProxySettings_SetRootCachePath),\
	EDITIONF(ProxySettings_SetUserDataPath),\
	EDITIONF(ProxySettings_SetPersistSessionCookies),\
	EDITIONF(ProxySettings_SetPersistUserPreferences),\
	EDITIONF(ProxySettings_SetUserAgent),\
	EDITIONF(ProxySettings_SetProductVersion),\
	EDITIONF(ProxySettings_SetLocale),\
	EDITIONF(ProxySettings_SetJavascriptFlags),\
	EDITIONF(ProxySettings_SetPackLoadingDisabled),\
	EDITIONF(ProxySettings_SetRemoteDebuggingPort),\
	EDITIONF(ProxySettings_SetUncaughtExceptionStackSize),\
	EDITIONF(ProxySettings_SetIgnoreCertificateErrors),\
	EDITIONF(ProxySettings_SetBackgroundColor),\
	EDITIONF(ProxySettings_SetAcceptLanguageList),\
	EDITIONF(ProxySettings_SetApplicationClientIdForFileScanning),\


//==========================================

extern "C"
void EDITIONF(ProxySettings_Constructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxySettings_Destructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxySettings_CopyConstructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxySettings_Create) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxySettings_IsValid) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxySettings_SetBrowserSubProcessPath) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxySettings_SetMultiThreadedMessageLoop) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxySettings_SetExternalMessagePump) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxySettings_SetWindowlessRenderingEnabled) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxySettings_SetCommandLineArgsDisabled) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxySettings_SetCachePath) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxySettings_SetRootCachePath) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
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
void EDITIONF(ProxySettings_SetJavascriptFlags) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxySettings_SetPackLoadingDisabled) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxySettings_SetRemoteDebuggingPort) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxySettings_SetUncaughtExceptionStackSize) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxySettings_SetIgnoreCertificateErrors) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxySettings_SetBackgroundColor) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxySettings_SetAcceptLanguageList) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxySettings_SetApplicationClientIdForFileScanning) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);


//==========================================

