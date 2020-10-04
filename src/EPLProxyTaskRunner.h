#pragma once

#include "stdafx.h"
#include "lib2.h"


#define DECL_DATA_TYPE_ProxyTaskRunner \
	{ /*32*/ \
		/*m_szName*/		 _WT("Chromium线程"), \
		/*m_szEgName*/		 _WT("ProxyTaskRunner"), \
		/*m_szExplain*/		 _WT("提供在相关线程上异步执行任务的类。在任何线程上调用此类的方法都是安全的。CEF维护多个内部线程，这些线程用于处理不同进程中的不同类型的任务。枚举常量: #浏览器线程.* 列出了场景的CEF线程。 任务运行程序还可用于其它CEF线程(例如: V8 WebWorker 线程)。"), \
		/*m_nCmdCount*/		 6, \
		/*m_pnCmdsIndex*/		 s_nProxyTaskRunnerElementCmdIndex, \
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

#define DECL_DATA_TYPE_ProxyTaskRunner_ARGINFO \
	{ /****** ProxyTaskRunner::GetForThread ** 0 **/ \
		/*name*/	 _WT("欲获取的线程"), \
		/*explain*/	 _WT("线程定义值为枚举常量: #浏览器线程.*"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxyTaskRunner::PostTask ** 1 **/ \
		/*name*/	 _WT("任务ID"), \
		/*explain*/	 _WT("自定义值"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxyTaskRunner::PostTask ** 2 **/ \
		/*name*/	 _WT("任务参数"), \
		/*explain*/	 _WT("自定义值"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 MAKELONG(36,0),  /*shrewd_ptr<ProxyValue>*/ \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxyTaskRunner::PostDelayedTask ** 3 **/ \
		/*name*/	 _WT("任务ID"), \
		/*explain*/	 _WT("自定义至"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxyTaskRunner::PostDelayedTask ** 4 **/ \
		/*name*/	 _WT("任务参数"), \
		/*explain*/	 _WT("自定义值"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 MAKELONG(36,0),  /*shrewd_ptr<ProxyValue>*/ \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxyTaskRunner::PostDelayedTask ** 5 **/ \
		/*name*/	 _WT("延迟时间"), \
		/*explain*/	 _WT("单位: 毫秒"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT64, \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\


//==========================================

#define DECL_DATA_TYPE_ProxyTaskRunner_CMDINFO(BeginIndex) \
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
		/*ccname*/	_WT("获取线程"),\
		/*egname*/	_WT("GetForThread"), \
		/*explain*/	_WT("获取浏览器线程。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	MAKELONG(33,0),  /*shrewd_ptr<ProxyTaskRunner>*/ \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	1, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+0] \
	},\
	{ /*4*/ \
		/*ccname*/	_WT("投递任务"),\
		/*egname*/	_WT("PostTask"), \
		/*explain*/	_WT("投递一个任务到指定的浏览器线程执行。"), \
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
		/*ccname*/	_WT("投递延迟任务"),\
		/*egname*/	_WT("PostDelayedTask"), \
		/*explain*/	_WT("投递一个任务到指定的浏览器线程该任务在目标线程中将会被延迟到指定的时间执行。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	SDT_BOOL, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	3, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+3] \
	},\


//==========================================

#define DECL_DATA_TYPE_ProxyTaskRunner_FUN_NAMES \
	EDITIONS("ProxyTaskRunner_Constructor"),\
	EDITIONS("ProxyTaskRunner_Destructor"),\
	EDITIONS("ProxyTaskRunner_CopyConstructor"),\
	EDITIONS("ProxyTaskRunner_GetForThread"),\
	EDITIONS("ProxyTaskRunner_PostTask"),\
	EDITIONS("ProxyTaskRunner_PostDelayedTask"),\


//==========================================

#define DECL_DATA_TYPE_ProxyTaskRunner_FUN_CALLS \
	EDITIONF(ProxyTaskRunner_Constructor),\
	EDITIONF(ProxyTaskRunner_Destructor),\
	EDITIONF(ProxyTaskRunner_CopyConstructor),\
	EDITIONF(ProxyTaskRunner_GetForThread),\
	EDITIONF(ProxyTaskRunner_PostTask),\
	EDITIONF(ProxyTaskRunner_PostDelayedTask),\


//==========================================

extern "C"
void EDITIONF(ProxyTaskRunner_Constructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyTaskRunner_Destructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyTaskRunner_CopyConstructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyTaskRunner_GetForThread) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyTaskRunner_PostTask) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyTaskRunner_PostDelayedTask) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);


//==========================================

