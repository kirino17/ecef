#pragma once

#include "stdafx.h"
#include "lib2.h"


#define DECL_DATA_TYPE_ProxyRequest \
	{ /*24*/ \
		/*m_szName*/		 _WT("Chromium请求"), \
		/*m_szEgName*/		 _WT("ProxyRequest"), \
		/*m_szExplain*/		 _WT("用于表示 Web 请求的类。"), \
		/*m_nCmdCount*/		 27, \
		/*m_pnCmdsIndex*/		 s_nProxyRequestElementCmdIndex, \
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

#define DECL_DATA_TYPE_ProxyRequest_ARGINFO \
	{ /****** ProxyRequest::SetURL ** 0 **/ \
		/*name*/	 _WT("url"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_TEXT, \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxyRequest::SetMethod ** 1 **/ \
		/*name*/	 _WT("请求方法"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_TEXT, \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxyRequest::SetReferrer ** 2 **/ \
		/*name*/	 _WT("请求来源"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_TEXT, \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxyRequest::SetReferrer ** 3 **/ \
		/*name*/	 _WT("来源设置策略"), \
		/*explain*/	 _WT("来源设置策略, 设置值为枚举常量: #来源策略.*"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxyRequest::SetPostData ** 4 **/ \
		/*name*/	 _WT("提交数据"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 MAKELONG(23,0),  /*shrewd_ptr<ProxyPostData>*/ \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxyRequest::SetHeaderMap ** 5 **/ \
		/*name*/	 _WT("标头列表"), \
		/*explain*/	 _WT("(字符串数组), 使用\"#换行符\"分隔"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_TEXT, \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxyRequest::GetHeaderByName ** 6 **/ \
		/*name*/	 _WT("标头名称"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_TEXT, \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxyRequest::SetHeaderByName ** 7 **/ \
		/*name*/	 _WT("标头名称"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_TEXT, \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxyRequest::SetHeaderByName ** 8 **/ \
		/*name*/	 _WT("值"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_TEXT, \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxyRequest::SetHeaderByName ** 9 **/ \
		/*name*/	 _WT("是否覆盖"), \
		/*explain*/	 _WT("如果目标标头已存有值,是否覆盖写入"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_BOOL, \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxyRequest::Set ** 10 **/ \
		/*name*/	 _WT("请求地址"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_TEXT, \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxyRequest::Set ** 11 **/ \
		/*name*/	 _WT("请求方法"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_TEXT, \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxyRequest::Set ** 12 **/ \
		/*name*/	 _WT("提交数据"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 MAKELONG(23,0),  /*shrewd_ptr<ProxyPostData>*/ \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxyRequest::Set ** 13 **/ \
		/*name*/	 _WT("标头列表"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_TEXT, \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxyRequest::SetFlags ** 14 **/ \
		/*name*/	 _WT("flags"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxyRequest::SetFirstPartyForCookies ** 15 **/ \
		/*name*/	 _WT("url"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_TEXT, \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\


//==========================================

#define DECL_DATA_TYPE_ProxyRequest_CMDINFO(BeginIndex) \
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
		/*ccname*/	_WT("创建对象"),\
		/*egname*/	_WT("Create"), \
		/*explain*/	_WT("创建对象实例, 非静态对象, 需要调用此函数后才能够有效访问。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	MAKELONG(25,0),  /*shrewd_ptr<ProxyRequest>*/ \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	0, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+0] \
	},\
	{ /*5*/ \
		/*ccname*/	_WT("是否为只读"),\
		/*egname*/	_WT("IsReadOnly"), \
		/*explain*/	_WT("如果当前对象禁止改写返回真。"), \
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
		/*ccname*/	_WT("取RUL"),\
		/*egname*/	_WT("GetURL"), \
		/*explain*/	_WT("获取该请求的URL。"), \
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
	{ /*7*/ \
		/*ccname*/	_WT("设置URL"),\
		/*egname*/	_WT("SetURL"), \
		/*explain*/	_WT("设置该请求的URL。"), \
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
	{ /*8*/ \
		/*ccname*/	_WT("取请求方法"),\
		/*egname*/	_WT("GetMethod"), \
		/*explain*/	_WT("获取该请求的请求方法。"), \
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
	{ /*9*/ \
		/*ccname*/	_WT("设置请求方法"),\
		/*egname*/	_WT("SetMethod"), \
		/*explain*/	_WT("设置该请求的请求方法。"), \
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
	{ /*10*/ \
		/*ccname*/	_WT("设置来源地址"),\
		/*egname*/	_WT("SetReferrer"), \
		/*explain*/	_WT("设置该请求的来源(Referrer)地址。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	_SDT_NULL, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	2, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+2] \
	},\
	{ /*11*/ \
		/*ccname*/	_WT("取来源地址"),\
		/*egname*/	_WT("GetReferrerURL"), \
		/*explain*/	_WT("获取该请求的来源(Referrer)地址。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	SDT_TEXT, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	0, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+4] \
	},\
	{ /*12*/ \
		/*ccname*/	_WT("取来源策略"),\
		/*egname*/	_WT("GetReferrerPolicy"), \
		/*explain*/	_WT("获取该请求的来源策略(ReferrerPolicy)。"), \
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
		/*ccname*/	_WT("取提交数据"),\
		/*egname*/	_WT("GetPostData"), \
		/*explain*/	_WT("获取该请求的提交数据(PostData)。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	MAKELONG(23,0),  /*shrewd_ptr<ProxyPostData>*/ \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	0, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+4] \
	},\
	{ /*14*/ \
		/*ccname*/	_WT("设置提交数据"),\
		/*egname*/	_WT("SetPostData"), \
		/*explain*/	_WT("设置该请求的提交数据(PostData)。"), \
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
	{ /*15*/ \
		/*ccname*/	_WT("取标头列表"),\
		/*egname*/	_WT("GetHeaderMap"), \
		/*explain*/	_WT("获取该请求的HTTP标头列表。"), \
		/*category*/	-1, \
		/*state*/	CT_RETRUN_ARY_TYPE_DATA, \
		/*ret*/	SDT_TEXT, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	0, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+5] \
	},\
	{ /*16*/ \
		/*ccname*/	_WT("设置标头列表"),\
		/*egname*/	_WT("SetHeaderMap"), \
		/*explain*/	_WT("设置该请求的HTTP标头。"), \
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
	{ /*17*/ \
		/*ccname*/	_WT("取标头"),\
		/*egname*/	_WT("GetHeaderByName"), \
		/*explain*/	_WT("获取指定HTTP标头值。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	SDT_TEXT, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	1, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+6] \
	},\
	{ /*18*/ \
		/*ccname*/	_WT("设置标头"),\
		/*egname*/	_WT("SetHeaderByName"), \
		/*explain*/	_WT("设置指定HTTP标头值。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	_SDT_NULL, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	3, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+7] \
	},\
	{ /*19*/ \
		/*ccname*/	_WT("设置"),\
		/*egname*/	_WT("Set"), \
		/*explain*/	_WT("设置该请求。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	_SDT_NULL, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	4, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+10] \
	},\
	{ /*20*/ \
		/*ccname*/	_WT("GetFlags"),\
		/*egname*/	_WT("GetFlags"), \
		/*explain*/	_WT(""), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	SDT_INT, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	0, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+14] \
	},\
	{ /*21*/ \
		/*ccname*/	_WT("SetFlags"),\
		/*egname*/	_WT("SetFlags"), \
		/*explain*/	_WT(""), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	_SDT_NULL, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	1, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+14] \
	},\
	{ /*22*/ \
		/*ccname*/	_WT("GetFirstPartyForCookies"),\
		/*egname*/	_WT("GetFirstPartyForCookies"), \
		/*explain*/	_WT(""), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	SDT_TEXT, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	0, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+15] \
	},\
	{ /*23*/ \
		/*ccname*/	_WT("SetFirstPartyForCookies"),\
		/*egname*/	_WT("SetFirstPartyForCookies"), \
		/*explain*/	_WT(""), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	_SDT_NULL, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	1, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+15] \
	},\
	{ /*24*/ \
		/*ccname*/	_WT("取资源类型"),\
		/*egname*/	_WT("GetResourceType"), \
		/*explain*/	_WT("获取请求资源类型, 返回值为枚举常量: #资源类型.*"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	SDT_INT, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	0, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+16] \
	},\
	{ /*25*/ \
		/*ccname*/	_WT("GetTransitionType"),\
		/*egname*/	_WT("GetTransitionType"), \
		/*explain*/	_WT(""), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	SDT_INT, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	0, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+16] \
	},\
	{ /*26*/ \
		/*ccname*/	_WT("取标识符"),\
		/*egname*/	_WT("GetIdentifier"), \
		/*explain*/	_WT("返回此请求的标识符。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	SDT_INT64, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	0, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+16] \
	},\


//==========================================

#define DECL_DATA_TYPE_ProxyRequest_FUN_NAMES \
	EDITIONS("ProxyRequest_Constructor"),\
	EDITIONS("ProxyRequest_Destructor"),\
	EDITIONS("ProxyRequest_CopyConstructor"),\
	EDITIONS("ProxyRequest_IsValid"),\
	EDITIONS("ProxyRequest_Create"),\
	EDITIONS("ProxyRequest_IsReadOnly"),\
	EDITIONS("ProxyRequest_GetURL"),\
	EDITIONS("ProxyRequest_SetURL"),\
	EDITIONS("ProxyRequest_GetMethod"),\
	EDITIONS("ProxyRequest_SetMethod"),\
	EDITIONS("ProxyRequest_SetReferrer"),\
	EDITIONS("ProxyRequest_GetReferrerURL"),\
	EDITIONS("ProxyRequest_GetReferrerPolicy"),\
	EDITIONS("ProxyRequest_GetPostData"),\
	EDITIONS("ProxyRequest_SetPostData"),\
	EDITIONS("ProxyRequest_GetHeaderMap"),\
	EDITIONS("ProxyRequest_SetHeaderMap"),\
	EDITIONS("ProxyRequest_GetHeaderByName"),\
	EDITIONS("ProxyRequest_SetHeaderByName"),\
	EDITIONS("ProxyRequest_Set"),\
	EDITIONS("ProxyRequest_GetFlags"),\
	EDITIONS("ProxyRequest_SetFlags"),\
	EDITIONS("ProxyRequest_GetFirstPartyForCookies"),\
	EDITIONS("ProxyRequest_SetFirstPartyForCookies"),\
	EDITIONS("ProxyRequest_GetResourceType"),\
	EDITIONS("ProxyRequest_GetTransitionType"),\
	EDITIONS("ProxyRequest_GetIdentifier"),\


//==========================================

#define DECL_DATA_TYPE_ProxyRequest_FUN_CALLS \
	EDITIONF(ProxyRequest_Constructor),\
	EDITIONF(ProxyRequest_Destructor),\
	EDITIONF(ProxyRequest_CopyConstructor),\
	EDITIONF(ProxyRequest_IsValid),\
	EDITIONF(ProxyRequest_Create),\
	EDITIONF(ProxyRequest_IsReadOnly),\
	EDITIONF(ProxyRequest_GetURL),\
	EDITIONF(ProxyRequest_SetURL),\
	EDITIONF(ProxyRequest_GetMethod),\
	EDITIONF(ProxyRequest_SetMethod),\
	EDITIONF(ProxyRequest_SetReferrer),\
	EDITIONF(ProxyRequest_GetReferrerURL),\
	EDITIONF(ProxyRequest_GetReferrerPolicy),\
	EDITIONF(ProxyRequest_GetPostData),\
	EDITIONF(ProxyRequest_SetPostData),\
	EDITIONF(ProxyRequest_GetHeaderMap),\
	EDITIONF(ProxyRequest_SetHeaderMap),\
	EDITIONF(ProxyRequest_GetHeaderByName),\
	EDITIONF(ProxyRequest_SetHeaderByName),\
	EDITIONF(ProxyRequest_Set),\
	EDITIONF(ProxyRequest_GetFlags),\
	EDITIONF(ProxyRequest_SetFlags),\
	EDITIONF(ProxyRequest_GetFirstPartyForCookies),\
	EDITIONF(ProxyRequest_SetFirstPartyForCookies),\
	EDITIONF(ProxyRequest_GetResourceType),\
	EDITIONF(ProxyRequest_GetTransitionType),\
	EDITIONF(ProxyRequest_GetIdentifier),\


//==========================================

extern "C"
void EDITIONF(ProxyRequest_Constructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyRequest_Destructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyRequest_CopyConstructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyRequest_IsValid) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyRequest_Create) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyRequest_IsReadOnly) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyRequest_GetURL) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyRequest_SetURL) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyRequest_GetMethod) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyRequest_SetMethod) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyRequest_SetReferrer) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyRequest_GetReferrerURL) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyRequest_GetReferrerPolicy) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyRequest_GetPostData) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyRequest_SetPostData) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyRequest_GetHeaderMap) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyRequest_SetHeaderMap) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyRequest_GetHeaderByName) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyRequest_SetHeaderByName) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyRequest_Set) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyRequest_GetFlags) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyRequest_SetFlags) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyRequest_GetFirstPartyForCookies) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyRequest_SetFirstPartyForCookies) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyRequest_GetResourceType) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyRequest_GetTransitionType) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyRequest_GetIdentifier) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);


//==========================================

