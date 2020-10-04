#pragma once

#include "stdafx.h"
#include "lib2.h"


#define DECL_DATA_TYPE_ProxyBase \
	{ /*2*/ \
		/*m_szName*/		 _WT("Chromium进程"), \
		/*m_szEgName*/		 _WT("ProxyBase"), \
		/*m_szExplain*/		 _WT("Chromium进程是Chromium浏览器进程的简称, 该对象包含了对浏览器多进程分支的调度管理, 全局设置,初始化和消息循环等功能的实现。"), \
		/*m_nCmdCount*/		 13, \
		/*m_pnCmdsIndex*/		 s_nProxyBaseElementCmdIndex, \
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

#define DECL_DATA_TYPE_ProxyBase_ARGINFO \
	{ /****** ProxyBase::ExecuteProcess ** 0 **/ \
		/*name*/	 _WT("保留"), \
		/*explain*/	 _WT("请设置为0。"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxyBase::Initialize ** 1 **/ \
		/*name*/	 _WT("设置参数"), \
		/*explain*/	 _WT("Chromium浏览器进程全局配置参数。"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 MAKELONG(32,0),  /*shrewd_ptr<ProxySettings>*/ \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxyBase::Initialize ** 2 **/ \
		/*name*/	 _WT("保留"), \
		/*explain*/	 _WT("请设置为0."), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxyBase::SetOSModalLoop ** 3 **/ \
		/*name*/	 _WT("osModalLoop"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_BOOL, \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxyBase::SetV8Interceptor ** 4 **/ \
		/*name*/	 _WT("附加信息"), \
		/*explain*/	 _WT("由事件\"渲染进程线程已创建\"事件提供的参数对象。"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 MAKELONG(19,0),  /*shrewd_ptr<ProxyListValue>*/ \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxyBase::SetV8Interceptor ** 5 **/ \
		/*name*/	 _WT("属性路径名称"), \
		/*explain*/	 _WT("使用以符号\"/\"进行分隔的属性名路径, 通常所有的浏览器内置对象以及自定义创建的对象都应在'window'对象下, 例如: window/clientInformation/appVersion 。"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_TEXT, \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxyBase::SetV8Interceptor ** 6 **/ \
		/*name*/	 _WT("设置返回值"), \
		/*explain*/	 _WT("使用此参数的值覆盖原对象的值。"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 MAKELONG(36,0),  /*shrewd_ptr<ProxyValue>*/ \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxyBase::SetV8Interceptor ** 7 **/ \
		/*name*/	 _WT("访问权限"), \
		/*explain*/	 _WT("设置目标属性访问权限, 定义值为枚举常量: #访问权限.* 。"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxyBase::CreateV8Object ** 8 **/ \
		/*name*/	 _WT("附加信息"), \
		/*explain*/	 _WT("由事件\"渲染进程线程已创建\"事件提供的参数对象。"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 MAKELONG(19,0),  /*shrewd_ptr<ProxyListValue>*/ \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxyBase::CreateV8Object ** 9 **/ \
		/*name*/	 _WT("属性路径名称"), \
		/*explain*/	 _WT("使用以符号\"/\"进行分隔的属性名路径, 通常所有的浏览器内置对象以及自定义创建的对象都应在'window'对象下, 例如: window/clientInformation/appVersion 。"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_TEXT, \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxyBase::CreateV8Object ** 10 **/ \
		/*name*/	 _WT("访问权限"), \
		/*explain*/	 _WT("设置目标属性访问权限, 定义值为枚举常量: #访问权限.* 。"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\


//==========================================

#define DECL_DATA_TYPE_ProxyBase_CMDINFO(BeginIndex) \
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
		/*ccname*/	_WT("调度进程"),\
		/*egname*/	_WT("ExecuteProcess"), \
		/*explain*/	_WT("此函数应在程序启动位置调用, 它用于帮助Chromium启动辅助进程, 辅助进程程序名由设置参数指定。如果该函数返回-1, 则标识此进程为浏览器进程, 否则则为其它辅助进程。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	SDT_INT, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	1, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+0] \
	},\
	{ /*4*/ \
		/*ccname*/	_WT("初始化"),\
		/*egname*/	_WT("Initialize"), \
		/*explain*/	_WT("此函数应该在程序启动位置调用, 且应该于浏览器进程中执行, 执行此函数以初始化Chromium浏览器进程。初始化成功返回真, 失败返回假。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	SDT_BOOL, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	2, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+1] \
	},\
	{ /*5*/ \
		/*ccname*/	_WT("Shutdown"),\
		/*egname*/	_WT("Shutdown"), \
		/*explain*/	_WT(""), \
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
	{ /*6*/ \
		/*ccname*/	_WT("DoMessageLoopWork"),\
		/*egname*/	_WT("DoMessageLoopWork"), \
		/*explain*/	_WT(""), \
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
	{ /*7*/ \
		/*ccname*/	_WT("启动消息循环"),\
		/*egname*/	_WT("RunMessageLoop"), \
		/*explain*/	_WT("启动Chromium消息循环。仅当未启用多线程消息循环设置时, 才应该调用此函数。此函数被执行后将一直阻塞, 直到收到系统退出消息为止。"), \
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
	{ /*8*/ \
		/*ccname*/	_WT("停止消息讯息"),\
		/*egname*/	_WT("QuitMessageLoop"), \
		/*explain*/	_WT("调用此函数以退出Chromium消息循环, 仅当启动了Chromium消息循环时才应该调用此函数。"), \
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
	{ /*9*/ \
		/*ccname*/	_WT("SetOSModalLoop"),\
		/*egname*/	_WT("SetOSModalLoop"), \
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
	{ /*10*/ \
		/*ccname*/	_WT("启用高DPI支持"),\
		/*egname*/	_WT("EnableHighDPISupport"), \
		/*explain*/	_WT("仅在程序启动时调用, 以在Windows 7 或者更高版本上启用High-DPI支持。较旧版本的Windows不支持DPI, 因为它们不支持DirectWrite, 并且GDI字体的字距非常差。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	_SDT_NULL, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	0, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+4] \
	},\
	{ /*11*/ \
		/*ccname*/	_WT("设置V8属性拦截器"),\
		/*egname*/	_WT("SetV8Interceptor"), \
		/*explain*/	_WT("设置Javascript V8引擎对象属性访问拦截器。此函数只能在事件\"渲染进程线程已创建\"中调用。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	_SDT_NULL, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	4, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+4] \
	},\
	{ /*12*/ \
		/*ccname*/	_WT("创建V8对象"),\
		/*egname*/	_WT("CreateV8Object"), \
		/*explain*/	_WT("创建 Javascript 对象。此函数只能在事件\"渲染进程线程已创建\"中调用。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	_SDT_NULL, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	3, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+8] \
	},\


//==========================================

#define DECL_DATA_TYPE_ProxyBase_FUN_NAMES \
	EDITIONS("ProxyBase_Constructor"),\
	EDITIONS("ProxyBase_Destructor"),\
	EDITIONS("ProxyBase_CopyConstructor"),\
	EDITIONS("ProxyBase_ExecuteProcess"),\
	EDITIONS("ProxyBase_Initialize"),\
	EDITIONS("ProxyBase_Shutdown"),\
	EDITIONS("ProxyBase_DoMessageLoopWork"),\
	EDITIONS("ProxyBase_RunMessageLoop"),\
	EDITIONS("ProxyBase_QuitMessageLoop"),\
	EDITIONS("ProxyBase_SetOSModalLoop"),\
	EDITIONS("ProxyBase_EnableHighDPISupport"),\
	EDITIONS("ProxyBase_SetV8Interceptor"),\
	EDITIONS("ProxyBase_CreateV8Object"),\


//==========================================

#define DECL_DATA_TYPE_ProxyBase_FUN_CALLS \
	EDITIONF(ProxyBase_Constructor),\
	EDITIONF(ProxyBase_Destructor),\
	EDITIONF(ProxyBase_CopyConstructor),\
	EDITIONF(ProxyBase_ExecuteProcess),\
	EDITIONF(ProxyBase_Initialize),\
	EDITIONF(ProxyBase_Shutdown),\
	EDITIONF(ProxyBase_DoMessageLoopWork),\
	EDITIONF(ProxyBase_RunMessageLoop),\
	EDITIONF(ProxyBase_QuitMessageLoop),\
	EDITIONF(ProxyBase_SetOSModalLoop),\
	EDITIONF(ProxyBase_EnableHighDPISupport),\
	EDITIONF(ProxyBase_SetV8Interceptor),\
	EDITIONF(ProxyBase_CreateV8Object),\


//==========================================

extern "C"
void EDITIONF(ProxyBase_Constructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyBase_Destructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyBase_CopyConstructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyBase_ExecuteProcess) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyBase_Initialize) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyBase_Shutdown) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyBase_DoMessageLoopWork) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyBase_RunMessageLoop) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyBase_QuitMessageLoop) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyBase_SetOSModalLoop) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyBase_EnableHighDPISupport) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyBase_SetV8Interceptor) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyBase_CreateV8Object) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);


//==========================================

