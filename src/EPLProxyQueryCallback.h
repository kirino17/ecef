#pragma once

#include "stdafx.h"
#include "lib2.h"


#define DECL_DATA_TYPE_ProxyQueryCallback \
	{ /*23*/ \
		/*m_szName*/		 _WT("水星脚本查询回调"), \
		/*m_szEgName*/		 _WT("ProxyQueryCallback"), \
		/*m_szExplain*/		 _WT("与单个挂起的Javascript异步查询关联的回调。执行 \"成功\" 或 \"失败\" 方法将异步响应发送到关联的Javascript处理程序。在不首先执行其中一共回调方法的情况下, 销毁与未取消查询相关联的回调对象时会报告运行时错误。"), \
		/*m_nCmdCount*/		 5, \
		/*m_pnCmdsIndex*/		 s_nProxyQueryCallbackElementCmdIndex, \
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

#define DECL_DATA_TYPE_ProxyQueryCallback_ARGINFO \
	{ /****** ProxyQueryCallback::Success ** 0 **/ \
		/*name*/	 _WT("响应"), \
		/*explain*/	 _WT("查询返回结果"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_TEXT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyQueryCallback::Failure ** 1 **/ \
		/*name*/	 _WT("错误代码"), \
		/*explain*/	 _WT("查询失败的错误代码"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyQueryCallback::Failure ** 2 **/ \
		/*name*/	 _WT("错误信息"), \
		/*explain*/	 _WT("查询失败的错误原因"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_TEXT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\


//==========================================

#define DECL_DATA_TYPE_ProxyQueryCallback_CMDINFO(BeginIndex) \
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
		/*ccname*/	_WT("成功"),\
		/*egname*/	_WT("Success"), \
		/*explain*/	_WT("通知关联的Javascript onSuccess回调, 以成功完成查询, 参数 | 响应 | 提供了查询结果。"), \
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
	{ /*4*/ \
		/*ccname*/	_WT("失败"),\
		/*egname*/	_WT("Failure"), \
		/*explain*/	_WT("通知关联的Javascript onFailure 回调, 查询已失败, 参数 |错误代码| , | 错误信息 | 提供了查询失败的原因。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	_SDT_NULL, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	2, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+1] \
	},\


//==========================================

#define DECL_DATA_TYPE_ProxyQueryCallback_FUN_NAMES \
	EDITIONS("ProxyQueryCallback_Constructor"),\
	EDITIONS("ProxyQueryCallback_Destructor"),\
	EDITIONS("ProxyQueryCallback_CopyConstructor"),\
	EDITIONS("ProxyQueryCallback_Success"),\
	EDITIONS("ProxyQueryCallback_Failure"),\


//==========================================

#define DECL_DATA_TYPE_ProxyQueryCallback_FUN_CALLS \
	EDITIONF(ProxyQueryCallback_Constructor),\
	EDITIONF(ProxyQueryCallback_Destructor),\
	EDITIONF(ProxyQueryCallback_CopyConstructor),\
	EDITIONF(ProxyQueryCallback_Success),\
	EDITIONF(ProxyQueryCallback_Failure),\


//==========================================

extern "C"
void EDITIONF(ProxyQueryCallback_Constructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyQueryCallback_Destructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyQueryCallback_CopyConstructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyQueryCallback_Success) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyQueryCallback_Failure) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);


//==========================================

