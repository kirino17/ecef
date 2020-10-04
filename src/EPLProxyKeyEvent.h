#pragma once

#include "stdafx.h"
#include "lib2.h"


#define DECL_DATA_TYPE_ProxyKeyEvent \
	{ /*17*/ \
		/*m_szName*/		 _WT("Chromium键盘事件"), \
		/*m_szEgName*/		 _WT("ProxyKeyEvent"), \
		/*m_szExplain*/		 _WT("表示键盘事件的类。"), \
		/*m_nCmdCount*/		 13, \
		/*m_pnCmdsIndex*/		 s_nProxyKeyEventElementCmdIndex, \
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

#define DECL_DATA_TYPE_ProxyKeyEvent_ARGINFO \
	{ /****** ProxyKeyEvent::SetType ** 0 **/ \
		/*name*/	 _WT("事件类型"), \
		/*explain*/	 _WT("此键盘事件的类型"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxyKeyEvent::SetModifiers ** 1 **/ \
		/*name*/	 _WT("键位标志"), \
		/*explain*/	 _WT("键位标志, 用于描述功能键的按下状态, 定义值位枚举常量: #事件标志.* 。"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxyKeyEvent::SetWindowsKeyCode ** 2 **/ \
		/*name*/	 _WT("键代码"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxyKeyEvent::SetNativeKeyCode ** 3 **/ \
		/*name*/	 _WT("本机键代码"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxyKeyEvent::SetIsSystemKey ** 4 **/ \
		/*name*/	 _WT("系统键"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxyKeyEvent::SetCharacter ** 5 **/ \
		/*name*/	 _WT("字符代码"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxyKeyEvent::SetUnmodifiedCharacter ** 6 **/ \
		/*name*/	 _WT("原始字符代码"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxyKeyEvent::SetFocusOnEditableField ** 7 **/ \
		/*name*/	 _WT("focus_on_editable_field"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\


//==========================================

#define DECL_DATA_TYPE_ProxyKeyEvent_CMDINFO(BeginIndex) \
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
		/*ret*/	MAKELONG(18,0),  /*shrewd_ptr<ProxyKeyEvent>*/ \
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
		/*ccname*/	_WT("设置事件类型"),\
		/*egname*/	_WT("SetType"), \
		/*explain*/	_WT("设置键盘事件类型。定义值为枚举常量: #键盘事件类型.* 。"), \
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
		/*ccname*/	_WT("设置键位标志"),\
		/*egname*/	_WT("SetModifiers"), \
		/*explain*/	_WT("设置键位标志值。"), \
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
		/*ccname*/	_WT("设置WINDOWS键代码"),\
		/*egname*/	_WT("SetWindowsKeyCode"), \
		/*explain*/	_WT("设置按键事件的Windows按键代码。DOM规范使用此值。有时它直接来自事件(例如: 在windows上), 有时它使用映射函数确定。 有关值列表, 参见: WebCore/platform/chromium/KeyboardCodes.h"), \
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
		/*ccname*/	_WT("设置本机键代码"),\
		/*egname*/	_WT("SetNativeKeyCode"), \
		/*explain*/	_WT("设置本机操作系统所使用的实际键代码。"), \
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
		/*ccname*/	_WT("是否为系统键"),\
		/*egname*/	_WT("SetIsSystemKey"), \
		/*explain*/	_WT("指示该事件是否被视为\"系统键\"事件。有关详细信息, 请参见: http://msdn.microsoft.com/en-us/library/ms646286(VS.85).aspx  。在非windows平台上, 此值始终未false。"), \
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
		/*ccname*/	_WT("设置输入字符"),\
		/*egname*/	_WT("SetCharacter"), \
		/*explain*/	_WT("设置按下键盘所生成的字符。"), \
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
		/*ccname*/	_WT("设置原始字符输入"),\
		/*egname*/	_WT("SetUnmodifiedCharacter"), \
		/*explain*/	_WT("与|字符输入|相同但应该不经过任何修改(shift键除外)。这对于确定快捷键很有用。"), \
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
		/*ccname*/	_WT("SetFocusOnEditableField"),\
		/*egname*/	_WT("SetFocusOnEditableField"), \
		/*explain*/	_WT(""), \
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


//==========================================

#define DECL_DATA_TYPE_ProxyKeyEvent_FUN_NAMES \
	EDITIONS("ProxyKeyEvent_Constructor"),\
	EDITIONS("ProxyKeyEvent_Destructor"),\
	EDITIONS("ProxyKeyEvent_CopyConstructor"),\
	EDITIONS("ProxyKeyEvent_Create"),\
	EDITIONS("ProxyKeyEvent_IsValid"),\
	EDITIONS("ProxyKeyEvent_SetType"),\
	EDITIONS("ProxyKeyEvent_SetModifiers"),\
	EDITIONS("ProxyKeyEvent_SetWindowsKeyCode"),\
	EDITIONS("ProxyKeyEvent_SetNativeKeyCode"),\
	EDITIONS("ProxyKeyEvent_SetIsSystemKey"),\
	EDITIONS("ProxyKeyEvent_SetCharacter"),\
	EDITIONS("ProxyKeyEvent_SetUnmodifiedCharacter"),\
	EDITIONS("ProxyKeyEvent_SetFocusOnEditableField"),\


//==========================================

#define DECL_DATA_TYPE_ProxyKeyEvent_FUN_CALLS \
	EDITIONF(ProxyKeyEvent_Constructor),\
	EDITIONF(ProxyKeyEvent_Destructor),\
	EDITIONF(ProxyKeyEvent_CopyConstructor),\
	EDITIONF(ProxyKeyEvent_Create),\
	EDITIONF(ProxyKeyEvent_IsValid),\
	EDITIONF(ProxyKeyEvent_SetType),\
	EDITIONF(ProxyKeyEvent_SetModifiers),\
	EDITIONF(ProxyKeyEvent_SetWindowsKeyCode),\
	EDITIONF(ProxyKeyEvent_SetNativeKeyCode),\
	EDITIONF(ProxyKeyEvent_SetIsSystemKey),\
	EDITIONF(ProxyKeyEvent_SetCharacter),\
	EDITIONF(ProxyKeyEvent_SetUnmodifiedCharacter),\
	EDITIONF(ProxyKeyEvent_SetFocusOnEditableField),\


//==========================================

extern "C"
void EDITIONF(ProxyKeyEvent_Constructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyKeyEvent_Destructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyKeyEvent_CopyConstructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyKeyEvent_Create) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyKeyEvent_IsValid) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyKeyEvent_SetType) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyKeyEvent_SetModifiers) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyKeyEvent_SetWindowsKeyCode) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyKeyEvent_SetNativeKeyCode) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyKeyEvent_SetIsSystemKey) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyKeyEvent_SetCharacter) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyKeyEvent_SetUnmodifiedCharacter) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyKeyEvent_SetFocusOnEditableField) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);


//==========================================

