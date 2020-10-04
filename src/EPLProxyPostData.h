#pragma once

#include "stdafx.h"
#include "lib2.h"


#define DECL_DATA_TYPE_ProxyPostData \
	{ /*22*/ \
		/*m_szName*/		 _WT("Chromium提交数据"), \
		/*m_szEgName*/		 _WT("ProxyPostData"), \
		/*m_szExplain*/		 _WT("用于表示 Web 请求的 PostData 的类"), \
		/*m_nCmdCount*/		 12, \
		/*m_pnCmdsIndex*/		 s_nProxyPostDataElementCmdIndex, \
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

#define DECL_DATA_TYPE_ProxyPostData_ARGINFO \
	{ /****** ProxyPostData::GetElement ** 0 **/ \
		/*name*/	 _WT("索引"), \
		/*explain*/	 _WT("元素索引,从0开始。"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxyPostData::RemoveElement ** 1 **/ \
		/*name*/	 _WT("元素"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 MAKELONG(24,0),  /*shrewd_ptr<ProxyPostDataElement>*/ \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxyPostData::AddElement ** 2 **/ \
		/*name*/	 _WT("元素"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 MAKELONG(24,0),  /*shrewd_ptr<ProxyPostDataElement>*/ \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\


//==========================================

#define DECL_DATA_TYPE_ProxyPostData_CMDINFO(BeginIndex) \
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
		/*ret*/	MAKELONG(23,0),  /*shrewd_ptr<ProxyPostData>*/ \
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
		/*ccname*/	_WT("是否为只读"),\
		/*egname*/	_WT("IsReadOnly"), \
		/*explain*/	_WT("如果对象是只读的返回真。"), \
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
		/*ccname*/	_WT("是否有未识别元素"),\
		/*egname*/	_WT("HasExcludedElements"), \
		/*explain*/	_WT("如果原始 POST Data 包含未被识别的元素(例如: 多文件上传数据部分), 则返回真。使用排除的元素修改此对象可能会导致请求失败。"), \
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
		/*ccname*/	_WT("取元素数量"),\
		/*egname*/	_WT("GetElementCount"), \
		/*explain*/	_WT("返回已发现的数据元素数量。"), \
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
		/*ccname*/	_WT("取提交元素"),\
		/*egname*/	_WT("GetElement"), \
		/*explain*/	_WT("获取指定的提交元素。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	MAKELONG(24,0),  /*shrewd_ptr<ProxyPostDataElement>*/ \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	1, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+0] \
	},\
	{ /*9*/ \
		/*ccname*/	_WT("移除元素"),\
		/*egname*/	_WT("RemoveElement"), \
		/*explain*/	_WT("删除指定的提交数据元素。如果删除成功返回真, 删除失败返回假。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	SDT_BOOL, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	1, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+1] \
	},\
	{ /*10*/ \
		/*ccname*/	_WT("添加元素"),\
		/*egname*/	_WT("AddElement"), \
		/*explain*/	_WT("添加指定的提交数据元素。如果添加成功返回真, 失败则返回假。"), \
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
	{ /*11*/ \
		/*ccname*/	_WT("移除所有元素"),\
		/*egname*/	_WT("RemoveElements"), \
		/*explain*/	_WT("删除现有的全部提交数据元素。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	_SDT_NULL, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	0, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+3] \
	},\


//==========================================

#define DECL_DATA_TYPE_ProxyPostData_FUN_NAMES \
	EDITIONS("ProxyPostData_Constructor"),\
	EDITIONS("ProxyPostData_Destructor"),\
	EDITIONS("ProxyPostData_CopyConstructor"),\
	EDITIONS("ProxyPostData_Create"),\
	EDITIONS("ProxyPostData_IsValid"),\
	EDITIONS("ProxyPostData_IsReadOnly"),\
	EDITIONS("ProxyPostData_HasExcludedElements"),\
	EDITIONS("ProxyPostData_GetElementCount"),\
	EDITIONS("ProxyPostData_GetElement"),\
	EDITIONS("ProxyPostData_RemoveElement"),\
	EDITIONS("ProxyPostData_AddElement"),\
	EDITIONS("ProxyPostData_RemoveElements"),\


//==========================================

#define DECL_DATA_TYPE_ProxyPostData_FUN_CALLS \
	EDITIONF(ProxyPostData_Constructor),\
	EDITIONF(ProxyPostData_Destructor),\
	EDITIONF(ProxyPostData_CopyConstructor),\
	EDITIONF(ProxyPostData_Create),\
	EDITIONF(ProxyPostData_IsValid),\
	EDITIONF(ProxyPostData_IsReadOnly),\
	EDITIONF(ProxyPostData_HasExcludedElements),\
	EDITIONF(ProxyPostData_GetElementCount),\
	EDITIONF(ProxyPostData_GetElement),\
	EDITIONF(ProxyPostData_RemoveElement),\
	EDITIONF(ProxyPostData_AddElement),\
	EDITIONF(ProxyPostData_RemoveElements),\


//==========================================

extern "C"
void EDITIONF(ProxyPostData_Constructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyPostData_Destructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyPostData_CopyConstructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyPostData_Create) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyPostData_IsValid) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyPostData_IsReadOnly) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyPostData_HasExcludedElements) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyPostData_GetElementCount) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyPostData_GetElement) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyPostData_RemoveElement) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyPostData_AddElement) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyPostData_RemoveElements) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);


//==========================================

