#pragma once

#include "stdafx.h"
#include "lib2.h"


#define DECL_DATA_TYPE_ProxyFileDialogCallback \
	{ /*14*/ \
		/*m_szName*/		 _WT("Chromium文件对话框回调"), \
		/*m_szEgName*/		 _WT("ProxyFileDialogCallback"), \
		/*m_szExplain*/		 _WT("文件对话框回调接口, 如使用自定义文件对话框, 则使用该回调接口返回文件选择结果。"), \
		/*m_nCmdCount*/		 5, \
		/*m_pnCmdsIndex*/		 s_nProxyFileDialogCallbackElementCmdIndex, \
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

#define DECL_DATA_TYPE_ProxyFileDialogCallback_ARGINFO \
	{ /****** ProxyFileDialogCallback::Continue ** 0 **/ \
		/*name*/	 _WT("选择器索引"), \
		/*explain*/	 _WT("选择器索引是从传递给\"即将打开文件对话框\"事件的过滤器数组的下标值, 从0开始。"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxyFileDialogCallback::Continue ** 1 **/ \
		/*name*/	 _WT("选择的文件列表"), \
		/*explain*/	 _WT("提交选择的文件列表,可以为单个值或者多个值, 多个值使用 #换行符 分隔。"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_TEXT, \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\


//==========================================

#define DECL_DATA_TYPE_ProxyFileDialogCallback_CMDINFO(BeginIndex) \
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
		/*ccname*/	_WT("选择文件"),\
		/*egname*/	_WT("Continue"), \
		/*explain*/	_WT("提交选择的文件"), \
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
		/*explain*/	_WT("取消文件选择"), \
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

#define DECL_DATA_TYPE_ProxyFileDialogCallback_FUN_NAMES \
	EDITIONS("ProxyFileDialogCallback_Constructor"),\
	EDITIONS("ProxyFileDialogCallback_Destructor"),\
	EDITIONS("ProxyFileDialogCallback_CopyConstructor"),\
	EDITIONS("ProxyFileDialogCallback_Continue"),\
	EDITIONS("ProxyFileDialogCallback_Cancel"),\


//==========================================

#define DECL_DATA_TYPE_ProxyFileDialogCallback_FUN_CALLS \
	EDITIONF(ProxyFileDialogCallback_Constructor),\
	EDITIONF(ProxyFileDialogCallback_Destructor),\
	EDITIONF(ProxyFileDialogCallback_CopyConstructor),\
	EDITIONF(ProxyFileDialogCallback_Continue),\
	EDITIONF(ProxyFileDialogCallback_Cancel),\


//==========================================

extern "C"
void EDITIONF(ProxyFileDialogCallback_Constructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyFileDialogCallback_Destructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyFileDialogCallback_CopyConstructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyFileDialogCallback_Continue) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyFileDialogCallback_Cancel) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);


//==========================================

