#pragma once

#include "stdafx.h"
#include "lib2.h"


#define DECL_DATA_TYPE_ProxyDOMNode \
	{ /*13*/ \
		/*m_szName*/		 _WT("水星网页文档元素"), \
		/*m_szEgName*/		 _WT("ProxyDOMNode"), \
		/*m_szExplain*/		 _WT("用于表示 DOM 节点的类型。"), \
		/*m_nCmdCount*/		 34, \
		/*m_pnCmdsIndex*/		 s_nProxyDOMNodeElementCmdIndex, \
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

#define DECL_DATA_TYPE_ProxyDOMNode_ARGINFO \
	{ /****** ProxyDOMNode::SetValue ** 0 **/ \
		/*name*/	 _WT("值"), \
		/*explain*/	 _WT("元素的值"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_TEXT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyDOMNode::HasElementAttribute ** 1 **/ \
		/*name*/	 _WT("属性名称"), \
		/*explain*/	 _WT("元素属性名称"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_TEXT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyDOMNode::GetElementAttribute ** 2 **/ \
		/*name*/	 _WT("属性名称"), \
		/*explain*/	 _WT("元素属性名称"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_TEXT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyDOMNode::SetElementAttribute ** 3 **/ \
		/*name*/	 _WT("属性名称"), \
		/*explain*/	 _WT("元素属性名称"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_TEXT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyDOMNode::SetElementAttribute ** 4 **/ \
		/*name*/	 _WT("属性值"), \
		/*explain*/	 _WT("元素属性值"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_TEXT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyDOMNode::SendEvent ** 5 **/ \
		/*name*/	 _WT("方法名"), \
		/*explain*/	 _WT("方法名称"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_TEXT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyDOMNode::SendEvent ** 6 **/ \
		/*name*/	 _WT("参数"), \
		/*explain*/	 _WT("方法参数, 仅支持基本数据类型数值。"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 _SDT_ALL, \
		/*default*/	 0,\
		/*state*/	 AS_DEFAULT_VALUE_IS_EMPTY \
	},\
	{ /****** ProxyDOMNode::QuerySelector ** 7 **/ \
		/*name*/	 _WT("选择器"), \
		/*explain*/	 _WT("CSS 选择器"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_TEXT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyDOMNode::QuerySelectorAll ** 8 **/ \
		/*name*/	 _WT("选择器"), \
		/*explain*/	 _WT("CSS 选择器"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_TEXT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\


//==========================================

#define DECL_DATA_TYPE_ProxyDOMNode_CMDINFO(BeginIndex) \
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
		/*ccname*/	_WT("取类型"),\
		/*egname*/	_WT("GetType"), \
		/*explain*/	_WT("返回文档元素的类型。定义值为枚举常量: #网页文档元素.* 。"), \
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
		/*ccname*/	_WT("是否为文本"),\
		/*egname*/	_WT("IsText"), \
		/*explain*/	_WT("如果此文档元素为文本返回真。"), \
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
		/*ccname*/	_WT("是否为元素"),\
		/*egname*/	_WT("IsElement"), \
		/*explain*/	_WT("如果此元素为文档元素返回真。"), \
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
		/*ccname*/	_WT("是否可编辑"),\
		/*egname*/	_WT("IsEditable"), \
		/*explain*/	_WT("如果此元素允许更改返回真。"), \
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
	{ /*8*/ \
		/*ccname*/	_WT("是否为表单元素"),\
		/*egname*/	_WT("IsFormControlElement"), \
		/*explain*/	_WT("如果此元素为表单控件元素返回真。"), \
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
	{ /*9*/ \
		/*ccname*/	_WT("取表单元素类型"),\
		/*egname*/	_WT("GetFormControlElementType"), \
		/*explain*/	_WT("返回此表单元素的类型。"), \
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
	{ /*10*/ \
		/*ccname*/	_WT("取名称"),\
		/*egname*/	_WT("GetName"), \
		/*explain*/	_WT("返回此文档元素的名称(name)。"), \
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
	{ /*11*/ \
		/*ccname*/	_WT("取值"),\
		/*egname*/	_WT("GetValue"), \
		/*explain*/	_WT("返回此文档元素的值(value)。"), \
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
	{ /*12*/ \
		/*ccname*/	_WT("置值"),\
		/*egname*/	_WT("SetValue"), \
		/*explain*/	_WT("设置此文档元素的值(value)."), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	SDT_BOOL, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	1, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+0] \
	},\
	{ /*13*/ \
		/*ccname*/	_WT("取标记文本"),\
		/*egname*/	_WT("GetAsMarkup"), \
		/*explain*/	_WT("获取此元素的标记文本(HTML)。"), \
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
	{ /*14*/ \
		/*ccname*/	_WT("取文档对象"),\
		/*egname*/	_WT("GetDocument"), \
		/*explain*/	_WT("返回与此元素关联的文档对象。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	MAKELONG(12,0),  /*shrewd_ptr<ProxyDOMDocument>*/ \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	0, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+1] \
	},\
	{ /*15*/ \
		/*ccname*/	_WT("取父元素"),\
		/*egname*/	_WT("GetParent"), \
		/*explain*/	_WT("返回此元素的父元素对象。"), \
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
	{ /*16*/ \
		/*ccname*/	_WT("取上一兄弟元素"),\
		/*egname*/	_WT("GetPreviousSibling"), \
		/*explain*/	_WT("返回此元素的上一个兄弟元素(previous sibling)。"), \
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
	{ /*17*/ \
		/*ccname*/	_WT("取下一兄弟元素"),\
		/*egname*/	_WT("GetNextSibling"), \
		/*explain*/	_WT("返回此元素的下一个兄弟元素(next sibling)。"), \
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
	{ /*18*/ \
		/*ccname*/	_WT("是否有子元素"),\
		/*egname*/	_WT("HasChildren"), \
		/*explain*/	_WT("如果此元素具有子元素对象返回真。"), \
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
	{ /*19*/ \
		/*ccname*/	_WT("取首个子元素"),\
		/*egname*/	_WT("GetFirstChild"), \
		/*explain*/	_WT("返回此元素的第一个子元素对象。"), \
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
	{ /*20*/ \
		/*ccname*/	_WT("取最后一个子元素"),\
		/*egname*/	_WT("GetLastChild"), \
		/*explain*/	_WT("返回此元素的最后一个子元素对象。"), \
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
	{ /*21*/ \
		/*ccname*/	_WT("取标签名称"),\
		/*egname*/	_WT("GetElementTagName"), \
		/*explain*/	_WT("返回此元素的标签名称(tag)。此方法仅对元素类型对象有效。"), \
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
	{ /*22*/ \
		/*ccname*/	_WT("是否有属性"),\
		/*egname*/	_WT("HasElementAttributes"), \
		/*explain*/	_WT("如果此元素具有属性(attributes)返回真。此方法仅对元素类型对象有效。"), \
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
	{ /*23*/ \
		/*ccname*/	_WT("是否存在属性"),\
		/*egname*/	_WT("HasElementAttribute"), \
		/*explain*/	_WT("如果此元素具有符合指定名称的属性返回真。"), \
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
	{ /*24*/ \
		/*ccname*/	_WT("取属性"),\
		/*egname*/	_WT("GetElementAttribute"), \
		/*explain*/	_WT("返回此元素中符合指定名称的属性值。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	SDT_TEXT, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	1, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+2] \
	},\
	{ /*25*/ \
		/*ccname*/	_WT("取所有属性"),\
		/*egname*/	_WT("GetElementAttributes"), \
		/*explain*/	_WT("返回此元素中的所有属性。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	MAKELONG(11,0),  /*shrewd_ptr<ProxyDictionaryValue>*/ \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	0, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+3] \
	},\
	{ /*26*/ \
		/*ccname*/	_WT("置属性"),\
		/*egname*/	_WT("SetElementAttribute"), \
		/*explain*/	_WT("设置指定属性到元素中。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	SDT_BOOL, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	2, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+3] \
	},\
	{ /*27*/ \
		/*ccname*/	_WT("取内部文本"),\
		/*egname*/	_WT("GetElementInnerText"), \
		/*explain*/	_WT("返回此元素的内部(inner)文本。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	SDT_TEXT, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	0, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+5] \
	},\
	{ /*28*/ \
		/*ccname*/	_WT("取包围框"),\
		/*egname*/	_WT("GetElementBounds"), \
		/*explain*/	_WT("返回此元素的包围框(bounding box)边界。"), \
		/*category*/	-1, \
		/*state*/	CT_RETRUN_ARY_TYPE_DATA, \
		/*ret*/	SDT_INT, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	0, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+5] \
	},\
	{ /*29*/ \
		/*ccname*/	_WT("执行方法"),\
		/*egname*/	_WT("SendEvent"), \
		/*explain*/	_WT("执行元素方法。"), \
		/*category*/	-1, \
		/*state*/	 CT_ALLOW_APPEND_NEW_ARG, \
		/*ret*/	_SDT_NULL, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	2, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+5] \
	},\
	{ /*30*/ \
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
		/*arg lp*/	&s_ArgInfo[BeginIndex+7] \
	},\
	{ /*31*/ \
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
		/*arg lp*/	&s_ArgInfo[BeginIndex+8] \
	},\
	{ /*32*/ \
		/*ccname*/	_WT("取子元素数量"),\
		/*egname*/	_WT("GetChildCount"), \
		/*explain*/	_WT("返回此文档元素拥有的子元素数量。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	SDT_INT, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	0, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+9] \
	},\
	{ /*33*/ \
		/*ccname*/	_WT("取选择器"),\
		/*egname*/	_WT("GetSelector"), \
		/*explain*/	_WT("返回此文档元素的CSS选择器字符串。"), \
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


//==========================================

#define DECL_DATA_TYPE_ProxyDOMNode_FUN_NAMES \
	EDITIONS("ProxyDOMNode_Constructor"),\
	EDITIONS("ProxyDOMNode_Destructor"),\
	EDITIONS("ProxyDOMNode_CopyConstructor"),\
	EDITIONS("ProxyDOMNode_IsValid"),\
	EDITIONS("ProxyDOMNode_GetType"),\
	EDITIONS("ProxyDOMNode_IsText"),\
	EDITIONS("ProxyDOMNode_IsElement"),\
	EDITIONS("ProxyDOMNode_IsEditable"),\
	EDITIONS("ProxyDOMNode_IsFormControlElement"),\
	EDITIONS("ProxyDOMNode_GetFormControlElementType"),\
	EDITIONS("ProxyDOMNode_GetName"),\
	EDITIONS("ProxyDOMNode_GetValue"),\
	EDITIONS("ProxyDOMNode_SetValue"),\
	EDITIONS("ProxyDOMNode_GetAsMarkup"),\
	EDITIONS("ProxyDOMNode_GetDocument"),\
	EDITIONS("ProxyDOMNode_GetParent"),\
	EDITIONS("ProxyDOMNode_GetPreviousSibling"),\
	EDITIONS("ProxyDOMNode_GetNextSibling"),\
	EDITIONS("ProxyDOMNode_HasChildren"),\
	EDITIONS("ProxyDOMNode_GetFirstChild"),\
	EDITIONS("ProxyDOMNode_GetLastChild"),\
	EDITIONS("ProxyDOMNode_GetElementTagName"),\
	EDITIONS("ProxyDOMNode_HasElementAttributes"),\
	EDITIONS("ProxyDOMNode_HasElementAttribute"),\
	EDITIONS("ProxyDOMNode_GetElementAttribute"),\
	EDITIONS("ProxyDOMNode_GetElementAttributes"),\
	EDITIONS("ProxyDOMNode_SetElementAttribute"),\
	EDITIONS("ProxyDOMNode_GetElementInnerText"),\
	EDITIONS("ProxyDOMNode_GetElementBounds"),\
	EDITIONS("ProxyDOMNode_SendEvent"),\
	EDITIONS("ProxyDOMNode_QuerySelector"),\
	EDITIONS("ProxyDOMNode_QuerySelectorAll"),\
	EDITIONS("ProxyDOMNode_GetChildCount"),\
	EDITIONS("ProxyDOMNode_GetSelector"),\


//==========================================

#define DECL_DATA_TYPE_ProxyDOMNode_FUN_CALLS \
	EDITIONF(ProxyDOMNode_Constructor),\
	EDITIONF(ProxyDOMNode_Destructor),\
	EDITIONF(ProxyDOMNode_CopyConstructor),\
	EDITIONF(ProxyDOMNode_IsValid),\
	EDITIONF(ProxyDOMNode_GetType),\
	EDITIONF(ProxyDOMNode_IsText),\
	EDITIONF(ProxyDOMNode_IsElement),\
	EDITIONF(ProxyDOMNode_IsEditable),\
	EDITIONF(ProxyDOMNode_IsFormControlElement),\
	EDITIONF(ProxyDOMNode_GetFormControlElementType),\
	EDITIONF(ProxyDOMNode_GetName),\
	EDITIONF(ProxyDOMNode_GetValue),\
	EDITIONF(ProxyDOMNode_SetValue),\
	EDITIONF(ProxyDOMNode_GetAsMarkup),\
	EDITIONF(ProxyDOMNode_GetDocument),\
	EDITIONF(ProxyDOMNode_GetParent),\
	EDITIONF(ProxyDOMNode_GetPreviousSibling),\
	EDITIONF(ProxyDOMNode_GetNextSibling),\
	EDITIONF(ProxyDOMNode_HasChildren),\
	EDITIONF(ProxyDOMNode_GetFirstChild),\
	EDITIONF(ProxyDOMNode_GetLastChild),\
	EDITIONF(ProxyDOMNode_GetElementTagName),\
	EDITIONF(ProxyDOMNode_HasElementAttributes),\
	EDITIONF(ProxyDOMNode_HasElementAttribute),\
	EDITIONF(ProxyDOMNode_GetElementAttribute),\
	EDITIONF(ProxyDOMNode_GetElementAttributes),\
	EDITIONF(ProxyDOMNode_SetElementAttribute),\
	EDITIONF(ProxyDOMNode_GetElementInnerText),\
	EDITIONF(ProxyDOMNode_GetElementBounds),\
	EDITIONF(ProxyDOMNode_SendEvent),\
	EDITIONF(ProxyDOMNode_QuerySelector),\
	EDITIONF(ProxyDOMNode_QuerySelectorAll),\
	EDITIONF(ProxyDOMNode_GetChildCount),\
	EDITIONF(ProxyDOMNode_GetSelector),\


//==========================================

extern "C"
void EDITIONF(ProxyDOMNode_Constructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyDOMNode_Destructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyDOMNode_CopyConstructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyDOMNode_IsValid) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyDOMNode_GetType) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyDOMNode_IsText) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyDOMNode_IsElement) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyDOMNode_IsEditable) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyDOMNode_IsFormControlElement) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyDOMNode_GetFormControlElementType) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyDOMNode_GetName) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyDOMNode_GetValue) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyDOMNode_SetValue) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyDOMNode_GetAsMarkup) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyDOMNode_GetDocument) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyDOMNode_GetParent) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyDOMNode_GetPreviousSibling) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyDOMNode_GetNextSibling) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyDOMNode_HasChildren) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyDOMNode_GetFirstChild) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyDOMNode_GetLastChild) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyDOMNode_GetElementTagName) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyDOMNode_HasElementAttributes) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyDOMNode_HasElementAttribute) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyDOMNode_GetElementAttribute) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyDOMNode_GetElementAttributes) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyDOMNode_SetElementAttribute) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyDOMNode_GetElementInnerText) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyDOMNode_GetElementBounds) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyDOMNode_SendEvent) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyDOMNode_QuerySelector) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyDOMNode_QuerySelectorAll) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyDOMNode_GetChildCount) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyDOMNode_GetSelector) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);


//==========================================

