#pragma once

#include "stdafx.h"
#include "lib2.h"


#define DECL_DATA_TYPE_ProxyTouchEvent \
	{ /*34*/ \
		/*m_szName*/		 _WT("Chromium触摸事件"), \
		/*m_szEgName*/		 _WT("ProxyTouchEvent"), \
		/*m_szExplain*/		 _WT("表示触摸事件的类。"), \
		/*m_nCmdCount*/		 15, \
		/*m_pnCmdsIndex*/		 s_nProxyTouchEventElementCmdIndex, \
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

#define DECL_DATA_TYPE_ProxyTouchEvent_ARGINFO \
	{ /****** ProxyTouchEvent::SetId ** 0 **/ \
		/*name*/	 _WT("触点ID"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxyTouchEvent::SetX ** 1 **/ \
		/*name*/	 _WT("x"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxyTouchEvent::SetY ** 2 **/ \
		/*name*/	 _WT("y"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxyTouchEvent::SetRadiusX ** 3 **/ \
		/*name*/	 _WT("半径"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxyTouchEvent::SetRadiusY ** 4 **/ \
		/*name*/	 _WT("半径"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxyTouchEvent::SetRotationAngle ** 5 **/ \
		/*name*/	 _WT("角度"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxyTouchEvent::SetPressure ** 6 **/ \
		/*name*/	 _WT("输入压力"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxyTouchEvent::SetType ** 7 **/ \
		/*name*/	 _WT("触点状态"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxyTouchEvent::SetModifiers ** 8 **/ \
		/*name*/	 _WT("键位标志"), \
		/*explain*/	 _WT("键位标志, 用于描述功能键的按下状态, 定义值位枚举常量: #事件标志.* 。"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxyTouchEvent::SetPointerType ** 9 **/ \
		/*name*/	 _WT("指针类型"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\


//==========================================

#define DECL_DATA_TYPE_ProxyTouchEvent_CMDINFO(BeginIndex) \
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
		/*ret*/	MAKELONG(35,0),  /*shrewd_ptr<ProxyTouchEvent>*/ \
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
		/*ccname*/	_WT("设置触点ID"),\
		/*egname*/	_WT("SetId"), \
		/*explain*/	_WT("设置接触点ID, 每次触摸必须唯一,可以是-1以外的任何数字。请注意, 最多可以跟踪16个并发触摸。超出部分将被忽略。"), \
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
		/*ccname*/	_WT("设置X坐标"),\
		/*egname*/	_WT("SetX"), \
		/*explain*/	_WT("相对于视图左侧的X坐标。"), \
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
		/*ccname*/	_WT("设置Y坐标"),\
		/*egname*/	_WT("SetY"), \
		/*explain*/	_WT("设置相对于视图顶部的Y坐标。"), \
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
		/*ccname*/	_WT("设置X半径"),\
		/*egname*/	_WT("SetRadiusX"), \
		/*explain*/	_WT("以像素为单位。如果不适用, 则设置为0."), \
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
		/*ccname*/	_WT("设置Y半径"),\
		/*egname*/	_WT("SetRadiusY"), \
		/*explain*/	_WT("以像素为单位。如果不适用, 则设置为0"), \
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
		/*ccname*/	_WT("设置角度"),\
		/*egname*/	_WT("SetRotationAngle"), \
		/*explain*/	_WT("以弧度为单位。如果不适用, 则设置为0"), \
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
		/*ccname*/	_WT("设置输入压力"),\
		/*egname*/	_WT("SetPressure"), \
		/*explain*/	_WT("设置指针的标准化输入压力在[0,1]的范围内。如果不适用, 则设置为0."), \
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
		/*ccname*/	_WT("设置触点状态"),\
		/*egname*/	_WT("SetType"), \
		/*explain*/	_WT("设置接触点的状态。定义值为枚举常量: #触点状态.*。触摸从一个 TET_PRESSED 事件开始, 然后是零个或多个 TET_MOVED 事件, 最后一个是 TET_RELEASED 或是 TET_CANCELLED 事件。不遵守此顺序的事件将被忽略。"), \
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
		/*ccname*/	_WT("设置键位标志"),\
		/*egname*/	_WT("SetModifiers"), \
		/*explain*/	_WT("设置键位标志值"), \
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
		/*ccname*/	_WT("设置指针类型"),\
		/*egname*/	_WT("SetPointerType"), \
		/*explain*/	_WT("设置发出此事件的设备类型。定义值见枚举常量: #设备指针类型.* 。"), \
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


//==========================================

#define DECL_DATA_TYPE_ProxyTouchEvent_FUN_NAMES \
	EDITIONS("ProxyTouchEvent_Constructor"),\
	EDITIONS("ProxyTouchEvent_Destructor"),\
	EDITIONS("ProxyTouchEvent_CopyConstructor"),\
	EDITIONS("ProxyTouchEvent_Create"),\
	EDITIONS("ProxyTouchEvent_IsValid"),\
	EDITIONS("ProxyTouchEvent_SetId"),\
	EDITIONS("ProxyTouchEvent_SetX"),\
	EDITIONS("ProxyTouchEvent_SetY"),\
	EDITIONS("ProxyTouchEvent_SetRadiusX"),\
	EDITIONS("ProxyTouchEvent_SetRadiusY"),\
	EDITIONS("ProxyTouchEvent_SetRotationAngle"),\
	EDITIONS("ProxyTouchEvent_SetPressure"),\
	EDITIONS("ProxyTouchEvent_SetType"),\
	EDITIONS("ProxyTouchEvent_SetModifiers"),\
	EDITIONS("ProxyTouchEvent_SetPointerType"),\


//==========================================

#define DECL_DATA_TYPE_ProxyTouchEvent_FUN_CALLS \
	EDITIONF(ProxyTouchEvent_Constructor),\
	EDITIONF(ProxyTouchEvent_Destructor),\
	EDITIONF(ProxyTouchEvent_CopyConstructor),\
	EDITIONF(ProxyTouchEvent_Create),\
	EDITIONF(ProxyTouchEvent_IsValid),\
	EDITIONF(ProxyTouchEvent_SetId),\
	EDITIONF(ProxyTouchEvent_SetX),\
	EDITIONF(ProxyTouchEvent_SetY),\
	EDITIONF(ProxyTouchEvent_SetRadiusX),\
	EDITIONF(ProxyTouchEvent_SetRadiusY),\
	EDITIONF(ProxyTouchEvent_SetRotationAngle),\
	EDITIONF(ProxyTouchEvent_SetPressure),\
	EDITIONF(ProxyTouchEvent_SetType),\
	EDITIONF(ProxyTouchEvent_SetModifiers),\
	EDITIONF(ProxyTouchEvent_SetPointerType),\


//==========================================

extern "C"
void EDITIONF(ProxyTouchEvent_Constructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyTouchEvent_Destructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyTouchEvent_CopyConstructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyTouchEvent_Create) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyTouchEvent_IsValid) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyTouchEvent_SetId) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyTouchEvent_SetX) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyTouchEvent_SetY) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyTouchEvent_SetRadiusX) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyTouchEvent_SetRadiusY) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyTouchEvent_SetRotationAngle) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyTouchEvent_SetPressure) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyTouchEvent_SetType) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyTouchEvent_SetModifiers) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyTouchEvent_SetPointerType) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);


//==========================================

