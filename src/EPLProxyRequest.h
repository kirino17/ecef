#pragma once

#include "stdafx.h"
#include "lib2.h"


#define DECL_DATA_TYPE_ProxyRequest \
	{ /*24*/ \
		/*m_szName*/		 _WT("水星请求"), \
		/*m_szEgName*/		 _WT("ProxyRequest"), \
		/*m_szExplain*/		 _WT("用于表示 Web 请求的类。"), \
		/*m_nCmdCount*/		 28, \
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
		/*state*/	 NULL \
	},\
	{ /****** ProxyRequest::SetMethod ** 1 **/ \
		/*name*/	 _WT("请求方法"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_TEXT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyRequest::SetReferrer ** 2 **/ \
		/*name*/	 _WT("请求来源"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_TEXT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyRequest::SetReferrer ** 3 **/ \
		/*name*/	 _WT("来源设置策略"), \
		/*explain*/	 _WT("来源设置策略, 设置值为枚举常量: #来源策略.*"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyRequest::AddPostDataElement ** 4 **/ \
		/*name*/	 _WT("提交元素"), \
		/*explain*/	 _WT("提交元素(Post Data Element)。"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 MAKELONG(22,0),  /*shrewd_ptr<ProxyPostDataElement>*/ \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyRequest::RemovePostDataElement ** 5 **/ \
		/*name*/	 _WT("提交元素"), \
		/*explain*/	 _WT("提交元素(Post Data Element)。"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 MAKELONG(22,0),  /*shrewd_ptr<ProxyPostDataElement>*/ \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyRequest::SetHeaderMap ** 6 **/ \
		/*name*/	 _WT("标头列表"), \
		/*explain*/	 _WT("(字符串数组), 使用\"#换行符\"分隔"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_TEXT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyRequest::GetHeaderByName ** 7 **/ \
		/*name*/	 _WT("标头名称"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_TEXT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyRequest::SetHeaderByName ** 8 **/ \
		/*name*/	 _WT("标头名称"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_TEXT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyRequest::SetHeaderByName ** 9 **/ \
		/*name*/	 _WT("值"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_TEXT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyRequest::SetHeaderByName ** 10 **/ \
		/*name*/	 _WT("是否覆盖"), \
		/*explain*/	 _WT("如果目标标头已存有值,是否覆盖写入"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_BOOL, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyRequest::SetFlags ** 11 **/ \
		/*name*/	 _WT("标志值"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyRequest::SetFirstPartyForCookies ** 12 **/ \
		/*name*/	 _WT("url"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_TEXT, \
		/*default*/	 0,\
		/*state*/	 NULL \
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
	{ /*5*/ \
		/*ccname*/	_WT("取URL"),\
		/*egname*/	_WT("GetURL"), \
		/*explain*/	_WT("取该请求的URL。"), \
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
	{ /*6*/ \
		/*ccname*/	_WT("置URL"),\
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
	{ /*7*/ \
		/*ccname*/	_WT("取方法"),\
		/*egname*/	_WT("GetMethod"), \
		/*explain*/	_WT("取该请求的请求方法。"), \
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
	{ /*8*/ \
		/*ccname*/	_WT("置方法"),\
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
	{ /*9*/ \
		/*ccname*/	_WT("置来源"),\
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
	{ /*10*/ \
		/*ccname*/	_WT("取来源"),\
		/*egname*/	_WT("GetReferrerURL"), \
		/*explain*/	_WT("取该请求的来源(Referrer)地址。"), \
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
	{ /*11*/ \
		/*ccname*/	_WT("取来源策略"),\
		/*egname*/	_WT("GetReferrerPolicy"), \
		/*explain*/	_WT("取该请求的来源策略(ReferrerPolicy)。"), \
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
	{ /*12*/ \
		/*ccname*/	_WT("取提交元素数量"),\
		/*egname*/	_WT("GetPostDataElementCount"), \
		/*explain*/	_WT("返回请求包含的提交元素(Post Data Element)数量。"), \
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
		/*ccname*/	_WT("取所有提交元素"),\
		/*egname*/	_WT("GetPostDataElements"), \
		/*explain*/	_WT("返回请求包含的所有提交元素(Post Data Element)。"), \
		/*category*/	-1, \
		/*state*/	CT_RETRUN_ARY_TYPE_DATA, \
		/*ret*/	MAKELONG(22,0),  /*shrewd_ptr<ProxyPostDataElement>***/ \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	0, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+4] \
	},\
	{ /*14*/ \
		/*ccname*/	_WT("添加提交元素"),\
		/*egname*/	_WT("AddPostDataElement"), \
		/*explain*/	_WT("添加一个提交元素(Post Data Element)到请求中。"), \
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
		/*ccname*/	_WT("移除提交元素"),\
		/*egname*/	_WT("RemovePostDataElement"), \
		/*explain*/	_WT("从请求中移除一个提交元素(Post Data Element)。"), \
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
		/*ccname*/	_WT("清除提交元素"),\
		/*egname*/	_WT("ClearPostDataElements"), \
		/*explain*/	_WT("将请求体中的所有提交元素(Post Data Element)清除。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	_SDT_NULL, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	0, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+6] \
	},\
	{ /*17*/ \
		/*ccname*/	_WT("取标头列表"),\
		/*egname*/	_WT("GetHeaderMap"), \
		/*explain*/	_WT("取该请求的HTTP标头列表。"), \
		/*category*/	-1, \
		/*state*/	CT_RETRUN_ARY_TYPE_DATA, \
		/*ret*/	SDT_TEXT, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	0, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+6] \
	},\
	{ /*18*/ \
		/*ccname*/	_WT("置标头列表"),\
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
		/*arg lp*/	&s_ArgInfo[BeginIndex+6] \
	},\
	{ /*19*/ \
		/*ccname*/	_WT("取标头"),\
		/*egname*/	_WT("GetHeaderByName"), \
		/*explain*/	_WT("取指定HTTP标头值。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	SDT_TEXT, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	1, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+7] \
	},\
	{ /*20*/ \
		/*ccname*/	_WT("置标头"),\
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
		/*arg lp*/	&s_ArgInfo[BeginIndex+8] \
	},\
	{ /*21*/ \
		/*ccname*/	_WT("取资源类型"),\
		/*egname*/	_WT("GetResourceType"), \
		/*explain*/	_WT("取请求资源类型, 返回值为枚举常量: #资源类型.*"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	SDT_INT, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	0, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+11] \
	},\
	{ /*22*/ \
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
		/*arg lp*/	&s_ArgInfo[BeginIndex+11] \
	},\
	{ /*23*/ \
		/*ccname*/	_WT("取标志值"),\
		/*egname*/	_WT("GetFlags"), \
		/*explain*/	_WT("获取与 URL请求结合使用的标志参数。 定义值为枚举常量: #请求标志.* 。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	SDT_INT, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	0, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+11] \
	},\
	{ /*24*/ \
		/*ccname*/	_WT("置标志值"),\
		/*egname*/	_WT("SetFlags"), \
		/*explain*/	_WT("设置与 URL请求结合使用的标志参数。 定义值为枚举常量: #请求标志.* , 多个标志值可用使用位或相加。"), \
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
	{ /*25*/ \
		/*ccname*/	_WT("取首要关联URL"),\
		/*egname*/	_WT("GetFirstPartyForCookies"), \
		/*explain*/	_WT("获取与 URL请求结合使用的cookie的URL。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	SDT_TEXT, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	0, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+12] \
	},\
	{ /*26*/ \
		/*ccname*/	_WT("置首要关联URL"),\
		/*egname*/	_WT("SetFirstPartyForCookies"), \
		/*explain*/	_WT("设置与 URL请求结合使用的cookie的URL。"), \
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
	{ /*27*/ \
		/*ccname*/	_WT("取传输类型"),\
		/*egname*/	_WT("GetTransitionType"), \
		/*explain*/	_WT("获取请求的传输类型。有一共源值和0个活多个限定符组成。参见枚举常量: #请求传输类型.* 。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	SDT_INT, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	0, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+13] \
	},\


//==========================================

#define DECL_DATA_TYPE_ProxyRequest_FUN_NAMES \
	EDITIONS("ProxyRequest_Constructor"),\
	EDITIONS("ProxyRequest_Destructor"),\
	EDITIONS("ProxyRequest_CopyConstructor"),\
	EDITIONS("ProxyRequest_IsValid"),\
	EDITIONS("ProxyRequest_IsReadOnly"),\
	EDITIONS("ProxyRequest_GetURL"),\
	EDITIONS("ProxyRequest_SetURL"),\
	EDITIONS("ProxyRequest_GetMethod"),\
	EDITIONS("ProxyRequest_SetMethod"),\
	EDITIONS("ProxyRequest_SetReferrer"),\
	EDITIONS("ProxyRequest_GetReferrerURL"),\
	EDITIONS("ProxyRequest_GetReferrerPolicy"),\
	EDITIONS("ProxyRequest_GetPostDataElementCount"),\
	EDITIONS("ProxyRequest_GetPostDataElements"),\
	EDITIONS("ProxyRequest_AddPostDataElement"),\
	EDITIONS("ProxyRequest_RemovePostDataElement"),\
	EDITIONS("ProxyRequest_ClearPostDataElements"),\
	EDITIONS("ProxyRequest_GetHeaderMap"),\
	EDITIONS("ProxyRequest_SetHeaderMap"),\
	EDITIONS("ProxyRequest_GetHeaderByName"),\
	EDITIONS("ProxyRequest_SetHeaderByName"),\
	EDITIONS("ProxyRequest_GetResourceType"),\
	EDITIONS("ProxyRequest_GetIdentifier"),\
	EDITIONS("ProxyRequest_GetFlags"),\
	EDITIONS("ProxyRequest_SetFlags"),\
	EDITIONS("ProxyRequest_GetFirstPartyForCookies"),\
	EDITIONS("ProxyRequest_SetFirstPartyForCookies"),\
	EDITIONS("ProxyRequest_GetTransitionType"),\


//==========================================

#define DECL_DATA_TYPE_ProxyRequest_FUN_CALLS \
	EDITIONF(ProxyRequest_Constructor),\
	EDITIONF(ProxyRequest_Destructor),\
	EDITIONF(ProxyRequest_CopyConstructor),\
	EDITIONF(ProxyRequest_IsValid),\
	EDITIONF(ProxyRequest_IsReadOnly),\
	EDITIONF(ProxyRequest_GetURL),\
	EDITIONF(ProxyRequest_SetURL),\
	EDITIONF(ProxyRequest_GetMethod),\
	EDITIONF(ProxyRequest_SetMethod),\
	EDITIONF(ProxyRequest_SetReferrer),\
	EDITIONF(ProxyRequest_GetReferrerURL),\
	EDITIONF(ProxyRequest_GetReferrerPolicy),\
	EDITIONF(ProxyRequest_GetPostDataElementCount),\
	EDITIONF(ProxyRequest_GetPostDataElements),\
	EDITIONF(ProxyRequest_AddPostDataElement),\
	EDITIONF(ProxyRequest_RemovePostDataElement),\
	EDITIONF(ProxyRequest_ClearPostDataElements),\
	EDITIONF(ProxyRequest_GetHeaderMap),\
	EDITIONF(ProxyRequest_SetHeaderMap),\
	EDITIONF(ProxyRequest_GetHeaderByName),\
	EDITIONF(ProxyRequest_SetHeaderByName),\
	EDITIONF(ProxyRequest_GetResourceType),\
	EDITIONF(ProxyRequest_GetIdentifier),\
	EDITIONF(ProxyRequest_GetFlags),\
	EDITIONF(ProxyRequest_SetFlags),\
	EDITIONF(ProxyRequest_GetFirstPartyForCookies),\
	EDITIONF(ProxyRequest_SetFirstPartyForCookies),\
	EDITIONF(ProxyRequest_GetTransitionType),\


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
void EDITIONF(ProxyRequest_GetPostDataElementCount) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyRequest_GetPostDataElements) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyRequest_AddPostDataElement) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyRequest_RemovePostDataElement) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyRequest_ClearPostDataElements) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyRequest_GetHeaderMap) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyRequest_SetHeaderMap) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyRequest_GetHeaderByName) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyRequest_SetHeaderByName) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyRequest_GetResourceType) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyRequest_GetIdentifier) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyRequest_GetFlags) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyRequest_SetFlags) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyRequest_GetFirstPartyForCookies) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyRequest_SetFirstPartyForCookies) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyRequest_GetTransitionType) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);


//==========================================

