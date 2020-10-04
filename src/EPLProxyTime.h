#pragma once

#include "stdafx.h"
#include "lib2.h"


#define DECL_DATA_TYPE_ProxyTime \
	{ /*33*/ \
		/*m_szName*/		 _WT("Chromium时间"), \
		/*m_szEgName*/		 _WT("ProxyTime"), \
		/*m_szExplain*/		 _WT("时间信息。时间值应始终为UTC。"), \
		/*m_nCmdCount*/		 27, \
		/*m_pnCmdsIndex*/		 s_nProxyTimeElementCmdIndex, \
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

#define DECL_DATA_TYPE_ProxyTime_ARGINFO \
	{ /****** ProxyTime::SetYear ** 0 **/ \
		/*name*/	 _WT("年"), \
		/*explain*/	 _WT("四位数或五位数的年份如\"2007\"(在Windows 上为1601至30827)。"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxyTime::SetMonth ** 1 **/ \
		/*name*/	 _WT("月"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxyTime::SetDayOfWeek ** 2 **/ \
		/*name*/	 _WT("星期"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxyTime::SetDayOfMonth ** 3 **/ \
		/*name*/	 _WT("天"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxyTime::SetHour ** 4 **/ \
		/*name*/	 _WT("小时"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxyTime::SetMinute ** 5 **/ \
		/*name*/	 _WT("分钟数"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxyTime::SetSecond ** 6 **/ \
		/*name*/	 _WT("秒数"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxyTime::SetMillisecond ** 7 **/ \
		/*name*/	 _WT("毫秒数"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxyTime::SetTime ** 8 **/ \
		/*name*/	 _WT("时间"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT64, \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxyTime::SetTimeDouble ** 9 **/ \
		/*name*/	 _WT("小数时间"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_DOUBLE, \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxyTime::Delta ** 10 **/ \
		/*name*/	 _WT("取值时间"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 MAKELONG(34,0),  /*shrewd_ptr<ProxyTime>*/ \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\


//==========================================

#define DECL_DATA_TYPE_ProxyTime_CMDINFO(BeginIndex) \
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
		/*ret*/	MAKELONG(34,0),  /*shrewd_ptr<ProxyTime>*/ \
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
		/*ccname*/	_WT("设置年"),\
		/*egname*/	_WT("SetYear"), \
		/*explain*/	_WT(""), \
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
		/*ccname*/	_WT("获取年"),\
		/*egname*/	_WT("GetYear"), \
		/*explain*/	_WT("获取年数。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	SDT_INT, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	0, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+1] \
	},\
	{ /*7*/ \
		/*ccname*/	_WT("设置月"),\
		/*egname*/	_WT("SetMonth"), \
		/*explain*/	_WT("月份从1开始, 1 = 一月, 依此类推。"), \
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
	{ /*8*/ \
		/*ccname*/	_WT("获取月"),\
		/*egname*/	_WT("GetMonth"), \
		/*explain*/	_WT(""), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	SDT_INT, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	0, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+2] \
	},\
	{ /*9*/ \
		/*ccname*/	_WT("设置星期"),\
		/*egname*/	_WT("SetDayOfWeek"), \
		/*explain*/	_WT("星期从0开始, 0 = 星期日。"), \
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
	{ /*10*/ \
		/*ccname*/	_WT("获取星期"),\
		/*egname*/	_WT("GetDayOfWeek"), \
		/*explain*/	_WT(""), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	SDT_INT, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	0, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+3] \
	},\
	{ /*11*/ \
		/*ccname*/	_WT("设置日"),\
		/*egname*/	_WT("SetDayOfMonth"), \
		/*explain*/	_WT("从1开始的天数, 1 - 31。"), \
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
	{ /*12*/ \
		/*ccname*/	_WT("获取日"),\
		/*egname*/	_WT("GetDayOfMonth"), \
		/*explain*/	_WT(""), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	SDT_INT, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	0, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+4] \
	},\
	{ /*13*/ \
		/*ccname*/	_WT("设置小时"),\
		/*egname*/	_WT("SetHour"), \
		/*explain*/	_WT("当日的小时, 0 - 23"), \
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
	{ /*14*/ \
		/*ccname*/	_WT("获取小时"),\
		/*egname*/	_WT("GetHour"), \
		/*explain*/	_WT(""), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	SDT_INT, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	0, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+5] \
	},\
	{ /*15*/ \
		/*ccname*/	_WT("设置分钟"),\
		/*egname*/	_WT("SetMinute"), \
		/*explain*/	_WT("当小时内的分钟数, 0 - 59。"), \
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
	{ /*16*/ \
		/*ccname*/	_WT("获取分钟"),\
		/*egname*/	_WT("GetMinute"), \
		/*explain*/	_WT(""), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	SDT_INT, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	0, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+6] \
	},\
	{ /*17*/ \
		/*ccname*/	_WT("设置秒"),\
		/*egname*/	_WT("SetSecond"), \
		/*explain*/	_WT("当分钟内的秒数, (0 - 59 加上进位秒, 最多可能到60秒)。"), \
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
	{ /*18*/ \
		/*ccname*/	_WT("获取秒"),\
		/*egname*/	_WT("GetSecond"), \
		/*explain*/	_WT(""), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	SDT_INT, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	0, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+7] \
	},\
	{ /*19*/ \
		/*ccname*/	_WT("设置毫秒"),\
		/*egname*/	_WT("SetMillisecond"), \
		/*explain*/	_WT("设置当秒内的毫秒数, 0 - 999。"), \
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
	{ /*20*/ \
		/*ccname*/	_WT("获取毫秒"),\
		/*egname*/	_WT("GetMillisecond"), \
		/*explain*/	_WT(""), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	SDT_INT, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	0, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+8] \
	},\
	{ /*21*/ \
		/*ccname*/	_WT("设置UTC时间"),\
		/*egname*/	_WT("SetTime"), \
		/*explain*/	_WT(""), \
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
	{ /*22*/ \
		/*ccname*/	_WT("获取UTC时间"),\
		/*egname*/	_WT("GetTime"), \
		/*explain*/	_WT(""), \
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
	{ /*23*/ \
		/*ccname*/	_WT("设置UTC时间小数值"),\
		/*egname*/	_WT("SetTimeDouble"), \
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
	{ /*24*/ \
		/*ccname*/	_WT("获取UTC时间小数值"),\
		/*egname*/	_WT("GetTimeDouble"), \
		/*explain*/	_WT(""), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	SDT_DOUBLE, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	0, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+10] \
	},\
	{ /*25*/ \
		/*ccname*/	_WT("设置现在时间"),\
		/*egname*/	_WT("SetNow"), \
		/*explain*/	_WT("设置为现在的UTC时间。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	_SDT_NULL, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	0, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+10] \
	},\
	{ /*26*/ \
		/*ccname*/	_WT("取时间间隔"),\
		/*egname*/	_WT("Delta"), \
		/*explain*/	_WT("获取两个UTC时间的间隔时长。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	SDT_INT64, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	1, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+10] \
	},\


//==========================================

#define DECL_DATA_TYPE_ProxyTime_FUN_NAMES \
	EDITIONS("ProxyTime_Constructor"),\
	EDITIONS("ProxyTime_Destructor"),\
	EDITIONS("ProxyTime_CopyConstructor"),\
	EDITIONS("ProxyTime_Create"),\
	EDITIONS("ProxyTime_IsValid"),\
	EDITIONS("ProxyTime_SetYear"),\
	EDITIONS("ProxyTime_GetYear"),\
	EDITIONS("ProxyTime_SetMonth"),\
	EDITIONS("ProxyTime_GetMonth"),\
	EDITIONS("ProxyTime_SetDayOfWeek"),\
	EDITIONS("ProxyTime_GetDayOfWeek"),\
	EDITIONS("ProxyTime_SetDayOfMonth"),\
	EDITIONS("ProxyTime_GetDayOfMonth"),\
	EDITIONS("ProxyTime_SetHour"),\
	EDITIONS("ProxyTime_GetHour"),\
	EDITIONS("ProxyTime_SetMinute"),\
	EDITIONS("ProxyTime_GetMinute"),\
	EDITIONS("ProxyTime_SetSecond"),\
	EDITIONS("ProxyTime_GetSecond"),\
	EDITIONS("ProxyTime_SetMillisecond"),\
	EDITIONS("ProxyTime_GetMillisecond"),\
	EDITIONS("ProxyTime_SetTime"),\
	EDITIONS("ProxyTime_GetTime"),\
	EDITIONS("ProxyTime_SetTimeDouble"),\
	EDITIONS("ProxyTime_GetTimeDouble"),\
	EDITIONS("ProxyTime_SetNow"),\
	EDITIONS("ProxyTime_Delta"),\


//==========================================

#define DECL_DATA_TYPE_ProxyTime_FUN_CALLS \
	EDITIONF(ProxyTime_Constructor),\
	EDITIONF(ProxyTime_Destructor),\
	EDITIONF(ProxyTime_CopyConstructor),\
	EDITIONF(ProxyTime_Create),\
	EDITIONF(ProxyTime_IsValid),\
	EDITIONF(ProxyTime_SetYear),\
	EDITIONF(ProxyTime_GetYear),\
	EDITIONF(ProxyTime_SetMonth),\
	EDITIONF(ProxyTime_GetMonth),\
	EDITIONF(ProxyTime_SetDayOfWeek),\
	EDITIONF(ProxyTime_GetDayOfWeek),\
	EDITIONF(ProxyTime_SetDayOfMonth),\
	EDITIONF(ProxyTime_GetDayOfMonth),\
	EDITIONF(ProxyTime_SetHour),\
	EDITIONF(ProxyTime_GetHour),\
	EDITIONF(ProxyTime_SetMinute),\
	EDITIONF(ProxyTime_GetMinute),\
	EDITIONF(ProxyTime_SetSecond),\
	EDITIONF(ProxyTime_GetSecond),\
	EDITIONF(ProxyTime_SetMillisecond),\
	EDITIONF(ProxyTime_GetMillisecond),\
	EDITIONF(ProxyTime_SetTime),\
	EDITIONF(ProxyTime_GetTime),\
	EDITIONF(ProxyTime_SetTimeDouble),\
	EDITIONF(ProxyTime_GetTimeDouble),\
	EDITIONF(ProxyTime_SetNow),\
	EDITIONF(ProxyTime_Delta),\


//==========================================

extern "C"
void EDITIONF(ProxyTime_Constructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyTime_Destructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyTime_CopyConstructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyTime_Create) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyTime_IsValid) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyTime_SetYear) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyTime_GetYear) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyTime_SetMonth) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyTime_GetMonth) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyTime_SetDayOfWeek) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyTime_GetDayOfWeek) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyTime_SetDayOfMonth) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyTime_GetDayOfMonth) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyTime_SetHour) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyTime_GetHour) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyTime_SetMinute) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyTime_GetMinute) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyTime_SetSecond) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyTime_GetSecond) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyTime_SetMillisecond) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyTime_GetMillisecond) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyTime_SetTime) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyTime_GetTime) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyTime_SetTimeDouble) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyTime_GetTimeDouble) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyTime_SetNow) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyTime_Delta) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);


//==========================================

