#pragma once

#include "stdafx.h"
#include "lib2.h"


#define DECL_DATA_TYPE_ProxyRunContextMenuCallback \
	{ /*30*/ \
		/*m_szName*/		 _WT("Chromium菜单上下文回调"), \
		/*m_szEgName*/		 _WT("ProxyRunContextMenuCallback"), \
		/*m_szExplain*/		 _WT("用于输出自定义上下文显示菜单执行结果的回调接口。"), \
		/*m_nCmdCount*/		 5, \
		/*m_pnCmdsIndex*/		 s_nProxyRunContextMenuCallbackElementCmdIndex, \
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

#define DECL_DATA_TYPE_ProxyRunContextMenuCallback_ARGINFO \
	{ /****** ProxyRunContextMenuCallback::Continue ** 0 **/ \
		/*name*/	 _WT("菜单ID"), \
		/*explain*/	 _WT("有关具有默认实现的菜单命令ID, 参见枚举常量: #系统内置菜单.* "), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxyRunContextMenuCallback::Continue ** 1 **/ \
		/*name*/	 _WT("事件标志"), \
		/*explain*/	 _WT("有关菜单事件标志可以查看枚举常量: #菜单事件标志.* 的定义值。"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\


//==========================================

#define DECL_DATA_TYPE_ProxyRunContextMenuCallback_CMDINFO(BeginIndex) \
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
		/*ccname*/	_WT("执行命令"),\
		/*egname*/	_WT("Continue"), \
		/*explain*/	_WT("执行菜单ID所指定的命令。"), \
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
		/*ccname*/	_WT("取消"),\
		/*egname*/	_WT("Cancel"), \
		/*explain*/	_WT("取消该菜单的执行"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	_SDT_NULL, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	0, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+2] \
	},\


//==========================================

#define DECL_DATA_TYPE_ProxyRunContextMenuCallback_FUN_NAMES \
	EDITIONS("ProxyRunContextMenuCallback_Constructor"),\
	EDITIONS("ProxyRunContextMenuCallback_Destructor"),\
	EDITIONS("ProxyRunContextMenuCallback_CopyConstructor"),\
	EDITIONS("ProxyRunContextMenuCallback_Continue"),\
	EDITIONS("ProxyRunContextMenuCallback_Cancel"),\


//==========================================

#define DECL_DATA_TYPE_ProxyRunContextMenuCallback_FUN_CALLS \
	EDITIONF(ProxyRunContextMenuCallback_Constructor),\
	EDITIONF(ProxyRunContextMenuCallback_Destructor),\
	EDITIONF(ProxyRunContextMenuCallback_CopyConstructor),\
	EDITIONF(ProxyRunContextMenuCallback_Continue),\
	EDITIONF(ProxyRunContextMenuCallback_Cancel),\


//==========================================

extern "C"
void EDITIONF(ProxyRunContextMenuCallback_Constructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyRunContextMenuCallback_Destructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyRunContextMenuCallback_CopyConstructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyRunContextMenuCallback_Continue) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyRunContextMenuCallback_Cancel) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);


//==========================================

