#pragma once

#include "stdafx.h"
#include "lib2.h"


#define DECL_DATA_TYPE_ProxyWindowInfo \
	{ /*36*/ \
		/*m_szName*/		 _WT("Chromium窗口设置"), \
		/*m_szEgName*/		 _WT("ProxyWindowInfo"), \
		/*m_szExplain*/		 _WT("为浏览器提供窗口设置信息,它告诉浏览器该创建怎样的窗口。比如让浏览器呈现在某个窗口中作为它的子控件抑或是让它在独立的顶层窗口中( 调用 **.设置为弹出窗口** 函数 )运行。"), \
		/*m_nCmdCount*/		 21, \
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
	{ /****** ProxyWindowInfo::SetExStyle ** 0 **/ \
		/*name*/	 _WT("扩展样式掩码"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxyWindowInfo::SetWindowName ** 1 **/ \
		/*name*/	 _WT("标题名称"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_TEXT, \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxyWindowInfo::SetStyle ** 2 **/ \
		/*name*/	 _WT("基本样式掩码值"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxyWindowInfo::SetX ** 3 **/ \
		/*name*/	 _WT("横向位置"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxyWindowInfo::SetY ** 4 **/ \
		/*name*/	 _WT("纵向位置"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxyWindowInfo::SetWidth ** 5 **/ \
		/*name*/	 _WT("宽度"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxyWindowInfo::SetHeight ** 6 **/ \
		/*name*/	 _WT("上设置窗口高度"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxyWindowInfo::SetParentWindow ** 7 **/ \
		/*name*/	 _WT("父窗口"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxyWindowInfo::SetMenu ** 8 **/ \
		/*name*/	 _WT("菜单句柄"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxyWindowInfo::SetWindowlessRenderingEnabled ** 9 **/ \
		/*name*/	 _WT("value"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxyWindowInfo::SetSharedtextureEnabled ** 10 **/ \
		/*name*/	 _WT("value"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxyWindowInfo::SetExternalBeginFrameEnabled ** 11 **/ \
		/*name*/	 _WT("value"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxyWindowInfo::SetWindow ** 12 **/ \
		/*name*/	 _WT("window"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxyWindowInfo::SetAsChild ** 13 **/ \
		/*name*/	 _WT("父窗口"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxyWindowInfo::SetAsChild ** 14 **/ \
		/*name*/	 _WT("横向位置"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxyWindowInfo::SetAsChild ** 15 **/ \
		/*name*/	 _WT("纵向位置"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxyWindowInfo::SetAsChild ** 16 **/ \
		/*name*/	 _WT("宽度"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxyWindowInfo::SetAsChild ** 17 **/ \
		/*name*/	 _WT("高度"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxyWindowInfo::SetAsPopup ** 18 **/ \
		/*name*/	 _WT("父窗口"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxyWindowInfo::SetAsPopup ** 19 **/ \
		/*name*/	 _WT("窗口标题"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_TEXT, \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxyWindowInfo::SetAsWindowless ** 20 **/ \
		/*name*/	 _WT("parent"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL\
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
		/*ccname*/	_WT("创建对象"),\
		/*egname*/	_WT("Create"), \
		/*explain*/	_WT("创建对象实例, 非静态对象, 需要调用此函数后才能够有效访问。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	MAKELONG(37,0),  /*shrewd_ptr<ProxyWindowInfo>*/ \
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
		/*ccname*/	_WT("设置扩展样式"),\
		/*egname*/	_WT("SetExStyle"), \
		/*explain*/	_WT("设置窗口扩展样式"), \
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
		/*ccname*/	_WT("设置窗口标题"),\
		/*egname*/	_WT("SetWindowName"), \
		/*explain*/	_WT("设置浏览器窗口标题"), \
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
		/*ccname*/	_WT("设置基本样式"),\
		/*egname*/	_WT("SetStyle"), \
		/*explain*/	_WT("设置窗口基本样式"), \
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
		/*ccname*/	_WT("设置横向位置"),\
		/*egname*/	_WT("SetX"), \
		/*explain*/	_WT("设置浏览器窗口横向位置, 于父窗口或者屏幕中。"), \
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
		/*ccname*/	_WT("设置纵向位置"),\
		/*egname*/	_WT("SetY"), \
		/*explain*/	_WT("设置浏览器窗口纵向位置, 于父窗口或者屏幕中。"), \
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
		/*ccname*/	_WT("设置宽度"),\
		/*egname*/	_WT("SetWidth"), \
		/*explain*/	_WT("设置浏览器窗口宽度"), \
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
		/*ccname*/	_WT("设置高度"),\
		/*egname*/	_WT("SetHeight"), \
		/*explain*/	_WT(""), \
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
		/*ccname*/	_WT("设置父窗口"),\
		/*egname*/	_WT("SetParentWindow"), \
		/*explain*/	_WT("设置浏览器父窗口"), \
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
		/*ccname*/	_WT("设置菜单"),\
		/*egname*/	_WT("SetMenu"), \
		/*explain*/	_WT("设置浏览器菜单"), \
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
		/*arg lp*/	&s_ArgInfo[BeginIndex+9] \
	},\
	{ /*15*/ \
		/*ccname*/	_WT("SetSharedtextureEnabled"),\
		/*egname*/	_WT("SetSharedtextureEnabled"), \
		/*explain*/	_WT(""), \
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
		/*ccname*/	_WT("SetExternalBeginFrameEnabled"),\
		/*egname*/	_WT("SetExternalBeginFrameEnabled"), \
		/*explain*/	_WT(""), \
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
		/*ccname*/	_WT("SetWindow"),\
		/*egname*/	_WT("SetWindow"), \
		/*explain*/	_WT(""), \
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
		/*ccname*/	_WT("设置为子窗口"),\
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
		/*arg lp*/	&s_ArgInfo[BeginIndex+13] \
	},\
	{ /*19*/ \
		/*ccname*/	_WT("设置为弹出窗口"),\
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
		/*arg lp*/	&s_ArgInfo[BeginIndex+18] \
	},\
	{ /*20*/ \
		/*ccname*/	_WT("SetAsWindowless"),\
		/*egname*/	_WT("SetAsWindowless"), \
		/*explain*/	_WT(""), \
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

#define DECL_DATA_TYPE_ProxyWindowInfo_FUN_NAMES \
	EDITIONS("ProxyWindowInfo_Constructor"),\
	EDITIONS("ProxyWindowInfo_Destructor"),\
	EDITIONS("ProxyWindowInfo_CopyConstructor"),\
	EDITIONS("ProxyWindowInfo_Create"),\
	EDITIONS("ProxyWindowInfo_IsValid"),\
	EDITIONS("ProxyWindowInfo_SetExStyle"),\
	EDITIONS("ProxyWindowInfo_SetWindowName"),\
	EDITIONS("ProxyWindowInfo_SetStyle"),\
	EDITIONS("ProxyWindowInfo_SetX"),\
	EDITIONS("ProxyWindowInfo_SetY"),\
	EDITIONS("ProxyWindowInfo_SetWidth"),\
	EDITIONS("ProxyWindowInfo_SetHeight"),\
	EDITIONS("ProxyWindowInfo_SetParentWindow"),\
	EDITIONS("ProxyWindowInfo_SetMenu"),\
	EDITIONS("ProxyWindowInfo_SetWindowlessRenderingEnabled"),\
	EDITIONS("ProxyWindowInfo_SetSharedtextureEnabled"),\
	EDITIONS("ProxyWindowInfo_SetExternalBeginFrameEnabled"),\
	EDITIONS("ProxyWindowInfo_SetWindow"),\
	EDITIONS("ProxyWindowInfo_SetAsChild"),\
	EDITIONS("ProxyWindowInfo_SetAsPopup"),\
	EDITIONS("ProxyWindowInfo_SetAsWindowless"),\


//==========================================

#define DECL_DATA_TYPE_ProxyWindowInfo_FUN_CALLS \
	EDITIONF(ProxyWindowInfo_Constructor),\
	EDITIONF(ProxyWindowInfo_Destructor),\
	EDITIONF(ProxyWindowInfo_CopyConstructor),\
	EDITIONF(ProxyWindowInfo_Create),\
	EDITIONF(ProxyWindowInfo_IsValid),\
	EDITIONF(ProxyWindowInfo_SetExStyle),\
	EDITIONF(ProxyWindowInfo_SetWindowName),\
	EDITIONF(ProxyWindowInfo_SetStyle),\
	EDITIONF(ProxyWindowInfo_SetX),\
	EDITIONF(ProxyWindowInfo_SetY),\
	EDITIONF(ProxyWindowInfo_SetWidth),\
	EDITIONF(ProxyWindowInfo_SetHeight),\
	EDITIONF(ProxyWindowInfo_SetParentWindow),\
	EDITIONF(ProxyWindowInfo_SetMenu),\
	EDITIONF(ProxyWindowInfo_SetWindowlessRenderingEnabled),\
	EDITIONF(ProxyWindowInfo_SetSharedtextureEnabled),\
	EDITIONF(ProxyWindowInfo_SetExternalBeginFrameEnabled),\
	EDITIONF(ProxyWindowInfo_SetWindow),\
	EDITIONF(ProxyWindowInfo_SetAsChild),\
	EDITIONF(ProxyWindowInfo_SetAsPopup),\
	EDITIONF(ProxyWindowInfo_SetAsWindowless),\


//==========================================

extern "C"
void EDITIONF(ProxyWindowInfo_Constructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyWindowInfo_Destructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyWindowInfo_CopyConstructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyWindowInfo_Create) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyWindowInfo_IsValid) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyWindowInfo_SetExStyle) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyWindowInfo_SetWindowName) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyWindowInfo_SetStyle) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyWindowInfo_SetX) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyWindowInfo_SetY) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyWindowInfo_SetWidth) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyWindowInfo_SetHeight) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyWindowInfo_SetParentWindow) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyWindowInfo_SetMenu) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyWindowInfo_SetWindowlessRenderingEnabled) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyWindowInfo_SetSharedtextureEnabled) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyWindowInfo_SetExternalBeginFrameEnabled) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyWindowInfo_SetWindow) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyWindowInfo_SetAsChild) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyWindowInfo_SetAsPopup) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyWindowInfo_SetAsWindowless) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);


//==========================================

