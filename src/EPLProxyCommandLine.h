#pragma once

#include "stdafx.h"
#include "lib2.h"


#define DECL_DATA_TYPE_ProxyCommandLine \
	{ /*7*/ \
		/*m_szName*/		 _WT("Chromium命令行"), \
		/*m_szEgName*/		 _WT("ProxyCommandLine"), \
		/*m_szExplain*/		 _WT("用于创建和解析命令行参数的类。在windows中带有\"--\" 或 \"-\" 以及 \"/\" 前缀的参数被视为命令行开关。开关将始终在任何没有开关前缀的参数之前。 开关可以选择使用\"=\"分隔符指定一个值(例如: \"--switch=value\")。参数\"-\" 将终止所有后续标记的开关解析, 无论前缀如何, 都将被解释为非开关参数。开关名称不区分大小写。可以在调用\"Chromium进程.初始化\" 之前使用此类。"), \
		/*m_nCmdCount*/		 19, \
		/*m_pnCmdsIndex*/		 s_nProxyCommandLineElementCmdIndex, \
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

#define DECL_DATA_TYPE_ProxyCommandLine_ARGINFO \
	{ /****** ProxyCommandLine::InitFromString ** 0 **/ \
		/*name*/	 _WT("命令行字符串"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_TEXT, \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxyCommandLine::SetProgram ** 1 **/ \
		/*name*/	 _WT("程序名称"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_TEXT, \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxyCommandLine::HasSwitch ** 2 **/ \
		/*name*/	 _WT("配置项名称"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_TEXT, \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxyCommandLine::GetSwitchValue ** 3 **/ \
		/*name*/	 _WT("配置项"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_TEXT, \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxyCommandLine::AppendSwitch ** 4 **/ \
		/*name*/	 _WT("配置项开关名称"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_TEXT, \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxyCommandLine::AppendSwitchWithValue ** 5 **/ \
		/*name*/	 _WT("配置项名称"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_TEXT, \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxyCommandLine::AppendSwitchWithValue ** 6 **/ \
		/*name*/	 _WT("配置项值"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_TEXT, \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\


//==========================================

#define DECL_DATA_TYPE_ProxyCommandLine_CMDINFO(BeginIndex) \
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
		/*egname*/	_WT("CreateCommandLine"), \
		/*explain*/	_WT("创建一个新的Chromium命令行对象实例。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	MAKELONG(8,0),  /*shrewd_ptr<ProxyCommandLine>*/ \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	0, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+0] \
	},\
	{ /*4*/ \
		/*ccname*/	_WT("取全局对象"),\
		/*egname*/	_WT("GetGlobalCommandLine"), \
		/*explain*/	_WT("返回单例全局Chromium命令行对象, 该对象是只读的。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	MAKELONG(8,0),  /*shrewd_ptr<ProxyCommandLine>*/ \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	0, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+0] \
	},\
	{ /*5*/ \
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
	{ /*6*/ \
		/*ccname*/	_WT("是否为只读"),\
		/*egname*/	_WT("IsReadOnly"), \
		/*explain*/	_WT("如果此对象项为只读模式返回真。"), \
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
	{ /*7*/ \
		/*ccname*/	_WT("复制"),\
		/*egname*/	_WT("Copy"), \
		/*explain*/	_WT("创建一个新的Chromium对象,该对象为本此对象的副本。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	MAKELONG(8,0),  /*shrewd_ptr<ProxyCommandLine>*/ \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	0, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+0] \
	},\
	{ /*8*/ \
		/*ccname*/	_WT("从字符串初始化"),\
		/*egname*/	_WT("InitFromString"), \
		/*explain*/	_WT("从字符串初始化Chromium命令行对象。"), \
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
	{ /*9*/ \
		/*ccname*/	_WT("重置"),\
		/*egname*/	_WT("Reset"), \
		/*explain*/	_WT(""), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	_SDT_NULL, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	0, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+1] \
	},\
	{ /*10*/ \
		/*ccname*/	_WT("取原始命令行"),\
		/*egname*/	_WT("GetArgv"), \
		/*explain*/	_WT(""), \
		/*category*/	-1, \
		/*state*/	CT_RETRUN_ARY_TYPE_DATA, \
		/*ret*/	SDT_TEXT, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	0, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+1] \
	},\
	{ /*11*/ \
		/*ccname*/	_WT("取命令行字符串"),\
		/*egname*/	_WT("GetCommandLineString"), \
		/*explain*/	_WT("返回原始命令行字符串数据。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	SDT_TEXT, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	0, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+1] \
	},\
	{ /*12*/ \
		/*ccname*/	_WT("取程序名称"),\
		/*egname*/	_WT("GetProgram"), \
		/*explain*/	_WT("返回命令行参数中的路径名称。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	SDT_TEXT, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	0, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+1] \
	},\
	{ /*13*/ \
		/*ccname*/	_WT("设置程序名称"),\
		/*egname*/	_WT("SetProgram"), \
		/*explain*/	_WT("设置命令行参数中的路径名称。"), \
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
	{ /*14*/ \
		/*ccname*/	_WT("是否有命令行配置项"),\
		/*egname*/	_WT("HasSwitches"), \
		/*explain*/	_WT("如果命令行中存在配置项返回真。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	SDT_BOOL, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	0, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+2] \
	},\
	{ /*15*/ \
		/*ccname*/	_WT("是否有指定配置项"),\
		/*egname*/	_WT("HasSwitch"), \
		/*explain*/	_WT("如果命令行中有指定的配置项返回真"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	SDT_BOOL, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	1, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+2] \
	},\
	{ /*16*/ \
		/*ccname*/	_WT("取配置项值"),\
		/*egname*/	_WT("GetSwitchValue"), \
		/*explain*/	_WT("返回指定配置项的值。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	SDT_TEXT, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	1, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+3] \
	},\
	{ /*17*/ \
		/*ccname*/	_WT("追加配置项开关"),\
		/*egname*/	_WT("AppendSwitch"), \
		/*explain*/	_WT("追加一个配置项开关到命令行参数中。"), \
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
	{ /*18*/ \
		/*ccname*/	_WT("追加配置项值"),\
		/*egname*/	_WT("AppendSwitchWithValue"), \
		/*explain*/	_WT("追加一个配置项值到命令行参数中。"), \
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

#define DECL_DATA_TYPE_ProxyCommandLine_FUN_NAMES \
	EDITIONS("ProxyCommandLine_Constructor"),\
	EDITIONS("ProxyCommandLine_Destructor"),\
	EDITIONS("ProxyCommandLine_CopyConstructor"),\
	EDITIONS("ProxyCommandLine_CreateCommandLine"),\
	EDITIONS("ProxyCommandLine_GetGlobalCommandLine"),\
	EDITIONS("ProxyCommandLine_IsValid"),\
	EDITIONS("ProxyCommandLine_IsReadOnly"),\
	EDITIONS("ProxyCommandLine_Copy"),\
	EDITIONS("ProxyCommandLine_InitFromString"),\
	EDITIONS("ProxyCommandLine_Reset"),\
	EDITIONS("ProxyCommandLine_GetArgv"),\
	EDITIONS("ProxyCommandLine_GetCommandLineString"),\
	EDITIONS("ProxyCommandLine_GetProgram"),\
	EDITIONS("ProxyCommandLine_SetProgram"),\
	EDITIONS("ProxyCommandLine_HasSwitches"),\
	EDITIONS("ProxyCommandLine_HasSwitch"),\
	EDITIONS("ProxyCommandLine_GetSwitchValue"),\
	EDITIONS("ProxyCommandLine_AppendSwitch"),\
	EDITIONS("ProxyCommandLine_AppendSwitchWithValue"),\


//==========================================

#define DECL_DATA_TYPE_ProxyCommandLine_FUN_CALLS \
	EDITIONF(ProxyCommandLine_Constructor),\
	EDITIONF(ProxyCommandLine_Destructor),\
	EDITIONF(ProxyCommandLine_CopyConstructor),\
	EDITIONF(ProxyCommandLine_CreateCommandLine),\
	EDITIONF(ProxyCommandLine_GetGlobalCommandLine),\
	EDITIONF(ProxyCommandLine_IsValid),\
	EDITIONF(ProxyCommandLine_IsReadOnly),\
	EDITIONF(ProxyCommandLine_Copy),\
	EDITIONF(ProxyCommandLine_InitFromString),\
	EDITIONF(ProxyCommandLine_Reset),\
	EDITIONF(ProxyCommandLine_GetArgv),\
	EDITIONF(ProxyCommandLine_GetCommandLineString),\
	EDITIONF(ProxyCommandLine_GetProgram),\
	EDITIONF(ProxyCommandLine_SetProgram),\
	EDITIONF(ProxyCommandLine_HasSwitches),\
	EDITIONF(ProxyCommandLine_HasSwitch),\
	EDITIONF(ProxyCommandLine_GetSwitchValue),\
	EDITIONF(ProxyCommandLine_AppendSwitch),\
	EDITIONF(ProxyCommandLine_AppendSwitchWithValue),\


//==========================================

extern "C"
void EDITIONF(ProxyCommandLine_Constructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyCommandLine_Destructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyCommandLine_CopyConstructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyCommandLine_CreateCommandLine) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyCommandLine_GetGlobalCommandLine) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyCommandLine_IsValid) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyCommandLine_IsReadOnly) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyCommandLine_Copy) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyCommandLine_InitFromString) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyCommandLine_Reset) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyCommandLine_GetArgv) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyCommandLine_GetCommandLineString) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyCommandLine_GetProgram) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyCommandLine_SetProgram) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyCommandLine_HasSwitches) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyCommandLine_HasSwitch) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyCommandLine_GetSwitchValue) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyCommandLine_AppendSwitch) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyCommandLine_AppendSwitchWithValue) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);


//==========================================

