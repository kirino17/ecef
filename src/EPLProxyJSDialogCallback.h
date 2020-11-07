#pragma once

#include "stdafx.h"
#include "lib2.h"


#define DECL_DATA_TYPE_ProxyJSDialogCallback \
	{ /*19*/ \
		/*m_szName*/		 _WT("水星脚本对话框"), \
		/*m_szEgName*/		 _WT("ProxyJSDialogCallback"), \
		/*m_szExplain*/		 _WT("脚本对话框回调接口, 用于Javascript对话框请求的执行返回。"), \
		/*m_nCmdCount*/		 4, \
		/*m_pnCmdsIndex*/		 s_nProxyJSDialogCallbackElementCmdIndex, \
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

#define DECL_DATA_TYPE_ProxyJSDialogCallback_ARGINFO \
	{ /****** ProxyJSDialogCallback::Continue ** 0 **/ \
		/*name*/	 _WT("OK"), \
		/*explain*/	 _WT("如果按下\"确定\"按钮, 则此参数应设置为真。"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_BOOL, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyJSDialogCallback::Continue ** 1 **/ \
		/*name*/	 _WT("输入文本"), \
		/*explain*/	 _WT("回复对话框接受输入的指定值。"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_TEXT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\


//==========================================

#define DECL_DATA_TYPE_ProxyJSDialogCallback_CMDINFO(BeginIndex) \
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
		/*ccname*/	_WT("回复"),\
		/*egname*/	_WT("Continue"), \
		/*explain*/	_WT("向Javascript对话框回复对话框选择命令。"), \
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


//==========================================

#define DECL_DATA_TYPE_ProxyJSDialogCallback_FUN_NAMES \
	EDITIONS("ProxyJSDialogCallback_Constructor"),\
	EDITIONS("ProxyJSDialogCallback_Destructor"),\
	EDITIONS("ProxyJSDialogCallback_CopyConstructor"),\
	EDITIONS("ProxyJSDialogCallback_Continue"),\


//==========================================

#define DECL_DATA_TYPE_ProxyJSDialogCallback_FUN_CALLS \
	EDITIONF(ProxyJSDialogCallback_Constructor),\
	EDITIONF(ProxyJSDialogCallback_Destructor),\
	EDITIONF(ProxyJSDialogCallback_CopyConstructor),\
	EDITIONF(ProxyJSDialogCallback_Continue),\


//==========================================

extern "C"
void EDITIONF(ProxyJSDialogCallback_Constructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyJSDialogCallback_Destructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyJSDialogCallback_CopyConstructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyJSDialogCallback_Continue) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);


//==========================================

