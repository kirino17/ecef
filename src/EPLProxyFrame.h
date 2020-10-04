#pragma once

#include "stdafx.h"
#include "lib2.h"


#define DECL_DATA_TYPE_ProxyFrame \
	{ /*15*/ \
		/*m_szName*/		 _WT("Chromium框架"), \
		/*m_szEgName*/		 _WT("ProxyFrame"), \
		/*m_szExplain*/		 _WT("用于在浏览器窗口中表示框架的类。在浏览器进程中使用时, 可以在任何线程上调用此类中的方法。除非注释另有说明。"), \
		/*m_nCmdCount*/		 25, \
		/*m_pnCmdsIndex*/		 s_nProxyFrameElementCmdIndex, \
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

#define DECL_DATA_TYPE_ProxyFrame_ARGINFO \
	{ /****** ProxyFrame::LoadRequest ** 0 **/ \
		/*name*/	 _WT("请求"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 MAKELONG(25,0),  /*shrewd_ptr<ProxyRequest>*/ \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxyFrame::LoadURL ** 1 **/ \
		/*name*/	 _WT("url"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_TEXT, \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxyFrame::ExecuteJavaScript ** 2 **/ \
		/*name*/	 _WT("脚本代码"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_TEXT, \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxyFrame::ExecuteJavaScript ** 3 **/ \
		/*name*/	 _WT("脚本别名"), \
		/*explain*/	 _WT("用作在控制台中显示的url标识符"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_TEXT, \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxyFrame::ExecuteJavaScript ** 4 **/ \
		/*name*/	 _WT("起始行"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxyFrame::ExecuteJavaScriptEx ** 5 **/ \
		/*name*/	 _WT("脚本代码"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_TEXT, \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxyFrame::ExecuteJavaScriptEx ** 6 **/ \
		/*name*/	 _WT("脚本别名"), \
		/*explain*/	 _WT("用作在控制台中显示的url标识符。"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_TEXT, \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxyFrame::ExecuteJavaScriptEx ** 7 **/ \
		/*name*/	 _WT("起始行"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxyFrame::ExecuteJavaScriptEx ** 8 **/ \
		/*name*/	 _WT("异常信息"), \
		/*explain*/	 _WT("执行异常时报告的错误信息。"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_TEXT, \
		/*default*/	 0,\
		/*state*/	 AS_RECEIVE_VAR,\
	},\


//==========================================

#define DECL_DATA_TYPE_ProxyFrame_CMDINFO(BeginIndex) \
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
		/*ccname*/	_WT("撤销"),\
		/*egname*/	_WT("Undo"), \
		/*explain*/	_WT(""), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	_SDT_NULL, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	0, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+0] \
	},\
	{ /*5*/ \
		/*ccname*/	_WT("重做"),\
		/*egname*/	_WT("Redo"), \
		/*explain*/	_WT(""), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	_SDT_NULL, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	0, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+0] \
	},\
	{ /*6*/ \
		/*ccname*/	_WT("剪切"),\
		/*egname*/	_WT("Cut"), \
		/*explain*/	_WT(""), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	_SDT_NULL, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	0, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+0] \
	},\
	{ /*7*/ \
		/*ccname*/	_WT("复制"),\
		/*egname*/	_WT("Copy"), \
		/*explain*/	_WT(""), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	_SDT_NULL, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	0, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+0] \
	},\
	{ /*8*/ \
		/*ccname*/	_WT("粘贴"),\
		/*egname*/	_WT("Paste"), \
		/*explain*/	_WT(""), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	_SDT_NULL, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	0, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+0] \
	},\
	{ /*9*/ \
		/*ccname*/	_WT("删除"),\
		/*egname*/	_WT("Delete"), \
		/*explain*/	_WT(""), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	_SDT_NULL, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	0, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+0] \
	},\
	{ /*10*/ \
		/*ccname*/	_WT("全选"),\
		/*egname*/	_WT("SelectAll"), \
		/*explain*/	_WT(""), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	_SDT_NULL, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	0, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+0] \
	},\
	{ /*11*/ \
		/*ccname*/	_WT("源文件视图"),\
		/*egname*/	_WT("ViewSource"), \
		/*explain*/	_WT(""), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	_SDT_NULL, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	0, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+0] \
	},\
	{ /*12*/ \
		/*ccname*/	_WT("取页面源代码"),\
		/*egname*/	_WT("GetSource"), \
		/*explain*/	_WT("获取此框架中的页面HTML源代码, 注意: 此函数禁止在事件中调用。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	SDT_TEXT, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	0, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+0] \
	},\
	{ /*13*/ \
		/*ccname*/	_WT("取页面文本"),\
		/*egname*/	_WT("GetText"), \
		/*explain*/	_WT("获取此框架中的页面文本, 注意: 此函数禁止在事件中调用。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	SDT_TEXT, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	0, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+0] \
	},\
	{ /*14*/ \
		/*ccname*/	_WT("加载请求"),\
		/*egname*/	_WT("LoadRequest"), \
		/*explain*/	_WT("在此框架中加载指定的请求。"), \
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
	{ /*15*/ \
		/*ccname*/	_WT("加载URL"),\
		/*egname*/	_WT("LoadURL"), \
		/*explain*/	_WT("在此框架中加载指定的URL。"), \
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
	{ /*16*/ \
		/*ccname*/	_WT("执行脚本"),\
		/*egname*/	_WT("ExecuteJavaScript"), \
		/*explain*/	_WT("在此框架值执行指定的Javascript脚本代码。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	_SDT_NULL, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	3, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+2] \
	},\
	{ /*17*/ \
		/*ccname*/	_WT("执行脚本2"),\
		/*egname*/	_WT("ExecuteJavaScriptEx"), \
		/*explain*/	_WT("在此框架中执行指定的javacript脚本代码。执行成功返回计算结果, 执行失败返回空对象, 可调用IsValid() 函数检查对象有效性。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	MAKELONG(36,0),  /*shrewd_ptr<ProxyValue>*/ \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	4, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+5] \
	},\
	{ /*18*/ \
		/*ccname*/	_WT("是否为首要框架"),\
		/*egname*/	_WT("IsMain"), \
		/*explain*/	_WT("如果此框架为首要框架(Top-Level)返回真。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	SDT_BOOL, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	0, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+9] \
	},\
	{ /*19*/ \
		/*ccname*/	_WT("是否拥有焦点"),\
		/*egname*/	_WT("IsFocused"), \
		/*explain*/	_WT("如果此框架拥有焦点返回真。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	SDT_BOOL, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	0, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+9] \
	},\
	{ /*20*/ \
		/*ccname*/	_WT("取名称"),\
		/*egname*/	_WT("GetName"), \
		/*explain*/	_WT("获取此框架的名称。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	SDT_TEXT, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	0, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+9] \
	},\
	{ /*21*/ \
		/*ccname*/	_WT("取父框架"),\
		/*egname*/	_WT("GetParent"), \
		/*explain*/	_WT("获取此框架的父框架, 如果此框架没有父框架将返回空对象。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	MAKELONG(16,0),  /*shrewd_ptr<ProxyFrame>*/ \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	0, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+9] \
	},\
	{ /*22*/ \
		/*ccname*/	_WT("取URL"),\
		/*egname*/	_WT("GetURL"), \
		/*explain*/	_WT("获取此框架中加载的URL。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	SDT_TEXT, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	0, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+9] \
	},\
	{ /*23*/ \
		/*ccname*/	_WT("取浏览器"),\
		/*egname*/	_WT("GetBrowser"), \
		/*explain*/	_WT("获取此框架所属的浏览器。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	MAKELONG(5,0),  /*shrewd_ptr<ProxyBrowser>*/ \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	0, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+9] \
	},\
	{ /*24*/ \
		/*ccname*/	_WT("取标识符"),\
		/*egname*/	_WT("GetIdentifier"), \
		/*explain*/	_WT("返回此框架的标识符"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	SDT_INT64, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	0, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+9] \
	},\


//==========================================

#define DECL_DATA_TYPE_ProxyFrame_FUN_NAMES \
	EDITIONS("ProxyFrame_Constructor"),\
	EDITIONS("ProxyFrame_Destructor"),\
	EDITIONS("ProxyFrame_CopyConstructor"),\
	EDITIONS("ProxyFrame_IsValid"),\
	EDITIONS("ProxyFrame_Undo"),\
	EDITIONS("ProxyFrame_Redo"),\
	EDITIONS("ProxyFrame_Cut"),\
	EDITIONS("ProxyFrame_Copy"),\
	EDITIONS("ProxyFrame_Paste"),\
	EDITIONS("ProxyFrame_Delete"),\
	EDITIONS("ProxyFrame_SelectAll"),\
	EDITIONS("ProxyFrame_ViewSource"),\
	EDITIONS("ProxyFrame_GetSource"),\
	EDITIONS("ProxyFrame_GetText"),\
	EDITIONS("ProxyFrame_LoadRequest"),\
	EDITIONS("ProxyFrame_LoadURL"),\
	EDITIONS("ProxyFrame_ExecuteJavaScript"),\
	EDITIONS("ProxyFrame_ExecuteJavaScriptEx"),\
	EDITIONS("ProxyFrame_IsMain"),\
	EDITIONS("ProxyFrame_IsFocused"),\
	EDITIONS("ProxyFrame_GetName"),\
	EDITIONS("ProxyFrame_GetParent"),\
	EDITIONS("ProxyFrame_GetURL"),\
	EDITIONS("ProxyFrame_GetBrowser"),\
	EDITIONS("ProxyFrame_GetIdentifier"),\


//==========================================

#define DECL_DATA_TYPE_ProxyFrame_FUN_CALLS \
	EDITIONF(ProxyFrame_Constructor),\
	EDITIONF(ProxyFrame_Destructor),\
	EDITIONF(ProxyFrame_CopyConstructor),\
	EDITIONF(ProxyFrame_IsValid),\
	EDITIONF(ProxyFrame_Undo),\
	EDITIONF(ProxyFrame_Redo),\
	EDITIONF(ProxyFrame_Cut),\
	EDITIONF(ProxyFrame_Copy),\
	EDITIONF(ProxyFrame_Paste),\
	EDITIONF(ProxyFrame_Delete),\
	EDITIONF(ProxyFrame_SelectAll),\
	EDITIONF(ProxyFrame_ViewSource),\
	EDITIONF(ProxyFrame_GetSource),\
	EDITIONF(ProxyFrame_GetText),\
	EDITIONF(ProxyFrame_LoadRequest),\
	EDITIONF(ProxyFrame_LoadURL),\
	EDITIONF(ProxyFrame_ExecuteJavaScript),\
	EDITIONF(ProxyFrame_ExecuteJavaScriptEx),\
	EDITIONF(ProxyFrame_IsMain),\
	EDITIONF(ProxyFrame_IsFocused),\
	EDITIONF(ProxyFrame_GetName),\
	EDITIONF(ProxyFrame_GetParent),\
	EDITIONF(ProxyFrame_GetURL),\
	EDITIONF(ProxyFrame_GetBrowser),\
	EDITIONF(ProxyFrame_GetIdentifier),\


//==========================================

extern "C"
void EDITIONF(ProxyFrame_Constructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyFrame_Destructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyFrame_CopyConstructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyFrame_IsValid) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyFrame_Undo) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyFrame_Redo) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyFrame_Cut) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyFrame_Copy) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyFrame_Paste) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyFrame_Delete) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyFrame_SelectAll) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyFrame_ViewSource) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyFrame_GetSource) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyFrame_GetText) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyFrame_LoadRequest) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyFrame_LoadURL) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyFrame_ExecuteJavaScript) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyFrame_ExecuteJavaScriptEx) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyFrame_IsMain) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyFrame_IsFocused) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyFrame_GetName) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyFrame_GetParent) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyFrame_GetURL) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyFrame_GetBrowser) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyFrame_GetIdentifier) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);


//==========================================

