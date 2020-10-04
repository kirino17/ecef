#pragma once

#include "stdafx.h"
#include "lib2.h"


#define DECL_DATA_TYPE_ProxyPopupFeatures \
	{ /*21*/ \
		/*m_szName*/		 _WT("Chromium窗口建议样式"), \
		/*m_szEgName*/		 _WT("ProxyPopupFeatures"), \
		/*m_szExplain*/		 _WT("为创建浏览器时用户所希望此所具有的样式信息。"), \
		/*m_nCmdCount*/		 17, \
		/*m_pnCmdsIndex*/		 s_nProxyPopupFeaturesElementCmdIndex, \
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

#define DECL_DATA_TYPE_ProxyPopupFeatures_ARGINFO \


//==========================================

#define DECL_DATA_TYPE_ProxyPopupFeatures_CMDINFO(BeginIndex) \
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
		/*ret*/	MAKELONG(22,0),  /*shrewd_ptr<ProxyPopupFeatures>*/ \
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
		/*ccname*/	_WT("GetX"),\
		/*egname*/	_WT("GetX"), \
		/*explain*/	_WT(""), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	SDT_INT, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	0, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+0] \
	},\
	{ /*6*/ \
		/*ccname*/	_WT("GetXSet"),\
		/*egname*/	_WT("GetXSet"), \
		/*explain*/	_WT(""), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	SDT_INT, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	0, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+0] \
	},\
	{ /*7*/ \
		/*ccname*/	_WT("GetY"),\
		/*egname*/	_WT("GetY"), \
		/*explain*/	_WT(""), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	SDT_INT, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	0, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+0] \
	},\
	{ /*8*/ \
		/*ccname*/	_WT("GetYSet"),\
		/*egname*/	_WT("GetYSet"), \
		/*explain*/	_WT(""), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	SDT_INT, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	0, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+0] \
	},\
	{ /*9*/ \
		/*ccname*/	_WT("GetWidth"),\
		/*egname*/	_WT("GetWidth"), \
		/*explain*/	_WT(""), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	SDT_INT, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	0, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+0] \
	},\
	{ /*10*/ \
		/*ccname*/	_WT("GetWidthSet"),\
		/*egname*/	_WT("GetWidthSet"), \
		/*explain*/	_WT(""), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	SDT_INT, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	0, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+0] \
	},\
	{ /*11*/ \
		/*ccname*/	_WT("GetHeight"),\
		/*egname*/	_WT("GetHeight"), \
		/*explain*/	_WT(""), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	SDT_INT, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	0, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+0] \
	},\
	{ /*12*/ \
		/*ccname*/	_WT("GetHeightSet"),\
		/*egname*/	_WT("GetHeightSet"), \
		/*explain*/	_WT(""), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	SDT_INT, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	0, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+0] \
	},\
	{ /*13*/ \
		/*ccname*/	_WT("GetMenuBarVisible"),\
		/*egname*/	_WT("GetMenuBarVisible"), \
		/*explain*/	_WT(""), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	SDT_INT, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	0, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+0] \
	},\
	{ /*14*/ \
		/*ccname*/	_WT("GetStatusBarVisible"),\
		/*egname*/	_WT("GetStatusBarVisible"), \
		/*explain*/	_WT(""), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	SDT_INT, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	0, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+0] \
	},\
	{ /*15*/ \
		/*ccname*/	_WT("GetToolBarVisible"),\
		/*egname*/	_WT("GetToolBarVisible"), \
		/*explain*/	_WT(""), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	SDT_INT, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	0, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+0] \
	},\
	{ /*16*/ \
		/*ccname*/	_WT("GetScrollbarsVisible"),\
		/*egname*/	_WT("GetScrollbarsVisible"), \
		/*explain*/	_WT(""), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	SDT_INT, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	0, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+0] \
	},\


//==========================================

#define DECL_DATA_TYPE_ProxyPopupFeatures_FUN_NAMES \
	EDITIONS("ProxyPopupFeatures_Constructor"),\
	EDITIONS("ProxyPopupFeatures_Destructor"),\
	EDITIONS("ProxyPopupFeatures_CopyConstructor"),\
	EDITIONS("ProxyPopupFeatures_Create"),\
	EDITIONS("ProxyPopupFeatures_IsValid"),\
	EDITIONS("ProxyPopupFeatures_GetX"),\
	EDITIONS("ProxyPopupFeatures_GetXSet"),\
	EDITIONS("ProxyPopupFeatures_GetY"),\
	EDITIONS("ProxyPopupFeatures_GetYSet"),\
	EDITIONS("ProxyPopupFeatures_GetWidth"),\
	EDITIONS("ProxyPopupFeatures_GetWidthSet"),\
	EDITIONS("ProxyPopupFeatures_GetHeight"),\
	EDITIONS("ProxyPopupFeatures_GetHeightSet"),\
	EDITIONS("ProxyPopupFeatures_GetMenuBarVisible"),\
	EDITIONS("ProxyPopupFeatures_GetStatusBarVisible"),\
	EDITIONS("ProxyPopupFeatures_GetToolBarVisible"),\
	EDITIONS("ProxyPopupFeatures_GetScrollbarsVisible"),\


//==========================================

#define DECL_DATA_TYPE_ProxyPopupFeatures_FUN_CALLS \
	EDITIONF(ProxyPopupFeatures_Constructor),\
	EDITIONF(ProxyPopupFeatures_Destructor),\
	EDITIONF(ProxyPopupFeatures_CopyConstructor),\
	EDITIONF(ProxyPopupFeatures_Create),\
	EDITIONF(ProxyPopupFeatures_IsValid),\
	EDITIONF(ProxyPopupFeatures_GetX),\
	EDITIONF(ProxyPopupFeatures_GetXSet),\
	EDITIONF(ProxyPopupFeatures_GetY),\
	EDITIONF(ProxyPopupFeatures_GetYSet),\
	EDITIONF(ProxyPopupFeatures_GetWidth),\
	EDITIONF(ProxyPopupFeatures_GetWidthSet),\
	EDITIONF(ProxyPopupFeatures_GetHeight),\
	EDITIONF(ProxyPopupFeatures_GetHeightSet),\
	EDITIONF(ProxyPopupFeatures_GetMenuBarVisible),\
	EDITIONF(ProxyPopupFeatures_GetStatusBarVisible),\
	EDITIONF(ProxyPopupFeatures_GetToolBarVisible),\
	EDITIONF(ProxyPopupFeatures_GetScrollbarsVisible),\


//==========================================

extern "C"
void EDITIONF(ProxyPopupFeatures_Constructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyPopupFeatures_Destructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyPopupFeatures_CopyConstructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyPopupFeatures_Create) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyPopupFeatures_IsValid) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyPopupFeatures_GetX) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyPopupFeatures_GetXSet) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyPopupFeatures_GetY) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyPopupFeatures_GetYSet) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyPopupFeatures_GetWidth) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyPopupFeatures_GetWidthSet) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyPopupFeatures_GetHeight) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyPopupFeatures_GetHeightSet) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyPopupFeatures_GetMenuBarVisible) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyPopupFeatures_GetStatusBarVisible) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyPopupFeatures_GetToolBarVisible) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyPopupFeatures_GetScrollbarsVisible) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);


//==========================================

