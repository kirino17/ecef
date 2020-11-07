#pragma once

#include "stdafx.h"
#include "lib2.h"


#define DECL_DATA_TYPE_ProxyDOMDocument \
	{ /*12*/ \
		/*m_szName*/		 _WT("水星网页文档对象"), \
		/*m_szEgName*/		 _WT("ProxyDOMDocument"), \
		/*m_szExplain*/		 _WT("表示DOM文档的类型。"), \
		/*m_nCmdCount*/		 20, \
		/*m_pnCmdsIndex*/		 s_nProxyDOMDocumentElementCmdIndex, \
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

#define DECL_DATA_TYPE_ProxyDOMDocument_ARGINFO \
	{ /****** ProxyDOMDocument::GetElementById ** 0 **/ \
		/*name*/	 _WT("标识符"), \
		/*explain*/	 _WT("元素标识符(ID)"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_TEXT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyDOMDocument::GetCompleteURL ** 1 **/ \
		/*name*/	 _WT("分段URL"), \
		/*explain*/	 _WT("文档的部分URL地址"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_TEXT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyDOMDocument::QuerySelector ** 2 **/ \
		/*name*/	 _WT("选择器"), \
		/*explain*/	 _WT("CSS 选择器。"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_TEXT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyDOMDocument::QuerySelectorAll ** 3 **/ \
		/*name*/	 _WT("选择器"), \
		/*explain*/	 _WT("CSS 选择器。"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_TEXT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\


//==========================================

#define DECL_DATA_TYPE_ProxyDOMDocument_CMDINFO(BeginIndex) \
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
		/*ccname*/	_WT("取文档类型"),\
		/*egname*/	_WT("GetType"), \
		/*explain*/	_WT("返回此网页文档的类型。定义值为枚举常量: #网页文档类型.* 。"), \
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
	{ /*5*/ \
		/*ccname*/	_WT("取根元素"),\
		/*egname*/	_WT("GetDocument"), \
		/*explain*/	_WT("返回最上层的文档元素(root document node)。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	MAKELONG(13,0),  /*shrewd_ptr<ProxyDOMNode>*/ \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	0, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+0] \
	},\
	{ /*6*/ \
		/*ccname*/	_WT("取BODY元素"),\
		/*egname*/	_WT("GetBody"), \
		/*explain*/	_WT("返回 Body 节点文档元素。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	MAKELONG(13,0),  /*shrewd_ptr<ProxyDOMNode>*/ \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	0, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+0] \
	},\
	{ /*7*/ \
		/*ccname*/	_WT("取HEAD元素"),\
		/*egname*/	_WT("GetHead"), \
		/*explain*/	_WT("返回 Head 节点文档元素。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	MAKELONG(13,0),  /*shrewd_ptr<ProxyDOMNode>*/ \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	0, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+0] \
	},\
	{ /*8*/ \
		/*ccname*/	_WT("取文档标题"),\
		/*egname*/	_WT("GetTitle"), \
		/*explain*/	_WT("返回文档标题。"), \
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
	{ /*9*/ \
		/*ccname*/	_WT("从标识符取元素"),\
		/*egname*/	_WT("GetElementById"), \
		/*explain*/	_WT("返回与符合指定标识符(ID)的文档元素。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	MAKELONG(13,0),  /*shrewd_ptr<ProxyDOMNode>*/ \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	1, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+0] \
	},\
	{ /*10*/ \
		/*ccname*/	_WT("取焦点元素"),\
		/*egname*/	_WT("GetFocusedNode"), \
		/*explain*/	_WT("返回当前焦点所在文档元素。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	MAKELONG(13,0),  /*shrewd_ptr<ProxyDOMNode>*/ \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	0, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+1] \
	},\
	{ /*11*/ \
		/*ccname*/	_WT("是否有选区"),\
		/*egname*/	_WT("HasSelection"), \
		/*explain*/	_WT("如果文档中存在选择区域返回真。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	SDT_BOOL, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	0, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+1] \
	},\
	{ /*12*/ \
		/*ccname*/	_WT("取选区起始位置"),\
		/*egname*/	_WT("GetSelectionStartOffset"), \
		/*explain*/	_WT("返回文档选择区的起始位置。"), \
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
	{ /*13*/ \
		/*ccname*/	_WT("取选区结束位置"),\
		/*egname*/	_WT("GetSelectionEndOffset"), \
		/*explain*/	_WT("返回文档选择区结束位置。"), \
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
	{ /*14*/ \
		/*ccname*/	_WT("取选区标记文本"),\
		/*egname*/	_WT("GetSelectionAsMarkup"), \
		/*explain*/	_WT("返回文档选择区域中的标记文本(HTML)。"), \
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
	{ /*15*/ \
		/*ccname*/	_WT("取选区文本"),\
		/*egname*/	_WT("GetSelectionAsText"), \
		/*explain*/	_WT("返回文档选择区域中的文本内容。"), \
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
	{ /*16*/ \
		/*ccname*/	_WT("取根URL"),\
		/*egname*/	_WT("GetBaseURL"), \
		/*explain*/	_WT("返回文档的起始URL。"), \
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
	{ /*17*/ \
		/*ccname*/	_WT("取完整URL"),\
		/*egname*/	_WT("GetCompleteURL"), \
		/*explain*/	_WT("根据文档的起始URL和指定的URL返回完整的URL地址。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	SDT_TEXT, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	1, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+1] \
	},\
	{ /*18*/ \
		/*ccname*/	_WT("查询元素"),\
		/*egname*/	_WT("QuerySelector"), \
		/*explain*/	_WT("查找并返回符合指定选择器索引的文档元素。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	MAKELONG(13,0),  /*shrewd_ptr<ProxyDOMNode>*/ \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	1, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+2] \
	},\
	{ /*19*/ \
		/*ccname*/	_WT("查询所有元素"),\
		/*egname*/	_WT("QuerySelectorAll"), \
		/*explain*/	_WT("查找并返回所有符合指定选择器索引的文档元素。"), \
		/*category*/	-1, \
		/*state*/	CT_RETRUN_ARY_TYPE_DATA, \
		/*ret*/	MAKELONG(13,0),  /*shrewd_ptr<ProxyDOMNode>***/ \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	1, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+3] \
	},\


//==========================================

#define DECL_DATA_TYPE_ProxyDOMDocument_FUN_NAMES \
	EDITIONS("ProxyDOMDocument_Constructor"),\
	EDITIONS("ProxyDOMDocument_Destructor"),\
	EDITIONS("ProxyDOMDocument_CopyConstructor"),\
	EDITIONS("ProxyDOMDocument_IsValid"),\
	EDITIONS("ProxyDOMDocument_GetType"),\
	EDITIONS("ProxyDOMDocument_GetDocument"),\
	EDITIONS("ProxyDOMDocument_GetBody"),\
	EDITIONS("ProxyDOMDocument_GetHead"),\
	EDITIONS("ProxyDOMDocument_GetTitle"),\
	EDITIONS("ProxyDOMDocument_GetElementById"),\
	EDITIONS("ProxyDOMDocument_GetFocusedNode"),\
	EDITIONS("ProxyDOMDocument_HasSelection"),\
	EDITIONS("ProxyDOMDocument_GetSelectionStartOffset"),\
	EDITIONS("ProxyDOMDocument_GetSelectionEndOffset"),\
	EDITIONS("ProxyDOMDocument_GetSelectionAsMarkup"),\
	EDITIONS("ProxyDOMDocument_GetSelectionAsText"),\
	EDITIONS("ProxyDOMDocument_GetBaseURL"),\
	EDITIONS("ProxyDOMDocument_GetCompleteURL"),\
	EDITIONS("ProxyDOMDocument_QuerySelector"),\
	EDITIONS("ProxyDOMDocument_QuerySelectorAll"),\


//==========================================

#define DECL_DATA_TYPE_ProxyDOMDocument_FUN_CALLS \
	EDITIONF(ProxyDOMDocument_Constructor),\
	EDITIONF(ProxyDOMDocument_Destructor),\
	EDITIONF(ProxyDOMDocument_CopyConstructor),\
	EDITIONF(ProxyDOMDocument_IsValid),\
	EDITIONF(ProxyDOMDocument_GetType),\
	EDITIONF(ProxyDOMDocument_GetDocument),\
	EDITIONF(ProxyDOMDocument_GetBody),\
	EDITIONF(ProxyDOMDocument_GetHead),\
	EDITIONF(ProxyDOMDocument_GetTitle),\
	EDITIONF(ProxyDOMDocument_GetElementById),\
	EDITIONF(ProxyDOMDocument_GetFocusedNode),\
	EDITIONF(ProxyDOMDocument_HasSelection),\
	EDITIONF(ProxyDOMDocument_GetSelectionStartOffset),\
	EDITIONF(ProxyDOMDocument_GetSelectionEndOffset),\
	EDITIONF(ProxyDOMDocument_GetSelectionAsMarkup),\
	EDITIONF(ProxyDOMDocument_GetSelectionAsText),\
	EDITIONF(ProxyDOMDocument_GetBaseURL),\
	EDITIONF(ProxyDOMDocument_GetCompleteURL),\
	EDITIONF(ProxyDOMDocument_QuerySelector),\
	EDITIONF(ProxyDOMDocument_QuerySelectorAll),\


//==========================================

extern "C"
void EDITIONF(ProxyDOMDocument_Constructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyDOMDocument_Destructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyDOMDocument_CopyConstructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyDOMDocument_IsValid) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyDOMDocument_GetType) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyDOMDocument_GetDocument) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyDOMDocument_GetBody) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyDOMDocument_GetHead) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyDOMDocument_GetTitle) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyDOMDocument_GetElementById) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyDOMDocument_GetFocusedNode) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyDOMDocument_HasSelection) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyDOMDocument_GetSelectionStartOffset) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyDOMDocument_GetSelectionEndOffset) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyDOMDocument_GetSelectionAsMarkup) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyDOMDocument_GetSelectionAsText) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyDOMDocument_GetBaseURL) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyDOMDocument_GetCompleteURL) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyDOMDocument_QuerySelector) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyDOMDocument_QuerySelectorAll) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);


//==========================================

