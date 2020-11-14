#pragma once

#include "stdafx.h"
#include "lib2.h"


#define DECL_DATA_TYPE_ProxyWindowInfo \
	{ /*34*/ \
		/*m_szName*/		 _WT("水星窗口设置"), \
		/*m_szEgName*/		 _WT("ProxyWindowInfo"), \
		/*m_szExplain*/		 _WT("为浏览器提供窗口设置信息,它告诉浏览器该创建怎样的窗口。比如让浏览器呈现在某个窗口中作为它的子控件抑或是让它在独立的顶层窗口中( 调用 **.设置为弹出窗口** 函数 )运行。"), \
		/*m_nCmdCount*/		 6, \
		/*m_pnCmdsIndex*/		 s_nProxyWindowInfoElementCmdIndex, \
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

#define DECL_DATA_TYPE_ProxyWindowInfo_ARGINFO \
	{ /****** ProxyWindowInfo::SetAsChild ** 0 **/ \
		/*name*/	 _WT("父窗口"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyWindowInfo::SetAsChild ** 1 **/ \
		/*name*/	 _WT("横向位置"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyWindowInfo::SetAsChild ** 2 **/ \
		/*name*/	 _WT("纵向位置"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyWindowInfo::SetAsChild ** 3 **/ \
		/*name*/	 _WT("宽度"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyWindowInfo::SetAsChild ** 4 **/ \
		/*name*/	 _WT("高度"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyWindowInfo::SetAsPopup ** 5 **/ \
		/*name*/	 _WT("父窗口"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyWindowInfo::SetAsPopup ** 6 **/ \
		/*name*/	 _WT("窗口标题"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_TEXT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\


//==========================================

#define DECL_DATA_TYPE_ProxyWindowInfo_CMDINFO(BeginIndex) \
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
		/*ccname*/	_WT("置为子窗口"),\
		/*egname*/	_WT("SetAsChild"), \
		/*explain*/	_WT("设置浏览器在某窗口中显示。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	_SDT_NULL, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	5, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+0] \
	},\
	{ /*5*/ \
		/*ccname*/	_WT("置为弹出窗口"),\
		/*egname*/	_WT("SetAsPopup"), \
		/*explain*/	_WT("设置浏览器在独立的窗口中显示。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	_SDT_NULL, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	2, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+5] \
	},\


//==========================================

#define DECL_DATA_TYPE_ProxyWindowInfo_FUN_NAMES \
	EDITIONS("ProxyWindowInfo_Constructor"),\
	EDITIONS("ProxyWindowInfo_Destructor"),\
	EDITIONS("ProxyWindowInfo_CopyConstructor"),\
	EDITIONS("ProxyWindowInfo_IsValid"),\
	EDITIONS("ProxyWindowInfo_SetAsChild"),\
	EDITIONS("ProxyWindowInfo_SetAsPopup"),\


//==========================================

#define DECL_DATA_TYPE_ProxyWindowInfo_FUN_CALLS \
	EDITIONF(ProxyWindowInfo_Constructor),\
	EDITIONF(ProxyWindowInfo_Destructor),\
	EDITIONF(ProxyWindowInfo_CopyConstructor),\
	EDITIONF(ProxyWindowInfo_IsValid),\
	EDITIONF(ProxyWindowInfo_SetAsChild),\
	EDITIONF(ProxyWindowInfo_SetAsPopup),\


//==========================================

extern "C"
void EDITIONF(ProxyWindowInfo_Constructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyWindowInfo_Destructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyWindowInfo_CopyConstructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyWindowInfo_IsValid) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyWindowInfo_SetAsChild) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyWindowInfo_SetAsPopup) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);


//==========================================

