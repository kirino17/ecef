#pragma once

#include "stdafx.h"
#include "lib2.h"


#define DECL_DATA_TYPE_ProxyPostDataElement \
	{ /*22*/ \
		/*m_szName*/		 _WT("水星提交元素"), \
		/*m_szEgName*/		 _WT("ProxyPostDataElement"), \
		/*m_szExplain*/		 _WT("用于表示 Web 请求提交数据(PostData)中的单个元素的的类。"), \
		/*m_nCmdCount*/		 12, \
		/*m_pnCmdsIndex*/		 s_nProxyPostDataElementElementCmdIndex, \
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

#define DECL_DATA_TYPE_ProxyPostDataElement_ARGINFO \
	{ /****** ProxyPostDataElement::SetToFile ** 0 **/ \
		/*name*/	 _WT("文件名"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_TEXT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyPostDataElement::SetToBytes ** 1 **/ \
		/*name*/	 _WT("字节长度"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyPostDataElement::SetToBytes ** 2 **/ \
		/*name*/	 _WT("字节数据"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_BIN, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\


//==========================================

#define DECL_DATA_TYPE_ProxyPostDataElement_CMDINFO(BeginIndex) \
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
		/*ccname*/	_WT("是否只读"),\
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
	{ /*5*/ \
		/*ccname*/	_WT("置空元素"),\
		/*egname*/	_WT("SetToEmpty"), \
		/*explain*/	_WT("从提交数据元素中删除所有数据"), \
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
		/*ccname*/	_WT("置文件"),\
		/*egname*/	_WT("SetToFile"), \
		/*explain*/	_WT("设置此提交数据元素代表为一个文件。"), \
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
		/*ccname*/	_WT("置字节集"),\
		/*egname*/	_WT("SetToBytes"), \
		/*explain*/	_WT("设置此提交数据元素代表为一串字节流。传入的字节流会被复制。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	_SDT_NULL, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	2, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+1] \
	},\
	{ /*8*/ \
		/*ccname*/	_WT("取元素类型"),\
		/*egname*/	_WT("GetType"), \
		/*explain*/	_WT("返回此提交数据元素的类型。定义值为枚举常量： #提交元素类型.* 。"), \
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
	{ /*9*/ \
		/*ccname*/	_WT("取文件名"),\
		/*egname*/	_WT("GetFile"), \
		/*explain*/	_WT("返回此提交元素代表的文件名。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	SDT_TEXT, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	0, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+3] \
	},\
	{ /*10*/ \
		/*ccname*/	_WT("取字节长度"),\
		/*egname*/	_WT("GetBytesCount"), \
		/*explain*/	_WT("返回此提交元素代表的字节流长度。"), \
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
		/*ccname*/	_WT("取字节集"),\
		/*egname*/	_WT("GetBytes"), \
		/*explain*/	_WT("读取|读取长度|个字节流数据写入到字节流缓冲区, 返回值为实际写入的字节数。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	SDT_BIN, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	0, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+3] \
	},\


//==========================================

#define DECL_DATA_TYPE_ProxyPostDataElement_FUN_NAMES \
	EDITIONS("ProxyPostDataElement_Constructor"),\
	EDITIONS("ProxyPostDataElement_Destructor"),\
	EDITIONS("ProxyPostDataElement_CopyConstructor"),\
	EDITIONS("ProxyPostDataElement_IsValid"),\
	EDITIONS("ProxyPostDataElement_IsReadOnly"),\
	EDITIONS("ProxyPostDataElement_SetToEmpty"),\
	EDITIONS("ProxyPostDataElement_SetToFile"),\
	EDITIONS("ProxyPostDataElement_SetToBytes"),\
	EDITIONS("ProxyPostDataElement_GetType"),\
	EDITIONS("ProxyPostDataElement_GetFile"),\
	EDITIONS("ProxyPostDataElement_GetBytesCount"),\
	EDITIONS("ProxyPostDataElement_GetBytes"),\


//==========================================

#define DECL_DATA_TYPE_ProxyPostDataElement_FUN_CALLS \
	EDITIONF(ProxyPostDataElement_Constructor),\
	EDITIONF(ProxyPostDataElement_Destructor),\
	EDITIONF(ProxyPostDataElement_CopyConstructor),\
	EDITIONF(ProxyPostDataElement_IsValid),\
	EDITIONF(ProxyPostDataElement_IsReadOnly),\
	EDITIONF(ProxyPostDataElement_SetToEmpty),\
	EDITIONF(ProxyPostDataElement_SetToFile),\
	EDITIONF(ProxyPostDataElement_SetToBytes),\
	EDITIONF(ProxyPostDataElement_GetType),\
	EDITIONF(ProxyPostDataElement_GetFile),\
	EDITIONF(ProxyPostDataElement_GetBytesCount),\
	EDITIONF(ProxyPostDataElement_GetBytes),\


//==========================================

extern "C"
void EDITIONF(ProxyPostDataElement_Constructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyPostDataElement_Destructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyPostDataElement_CopyConstructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyPostDataElement_IsValid) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyPostDataElement_IsReadOnly) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyPostDataElement_SetToEmpty) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyPostDataElement_SetToFile) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyPostDataElement_SetToBytes) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyPostDataElement_GetType) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyPostDataElement_GetFile) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyPostDataElement_GetBytesCount) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyPostDataElement_GetBytes) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);


//==========================================

