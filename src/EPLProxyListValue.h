#pragma once

#include "stdafx.h"
#include "lib2.h"


#define DECL_DATA_TYPE_ProxyListValue \
	{ /*20*/ \
		/*m_szName*/		 _WT("水星列表型"), \
		/*m_szEgName*/		 _WT("ProxyListValue"), \
		/*m_szExplain*/		 _WT("表示列表值(ListValue)的类。"), \
		/*m_nCmdCount*/		 31, \
		/*m_pnCmdsIndex*/		 s_nProxyListValueElementCmdIndex, \
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

#define DECL_DATA_TYPE_ProxyListValue_ARGINFO \
	{ /****** ProxyListValue::IsSame ** 0 **/ \
		/*name*/	 _WT("比较类型"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 MAKELONG(20,0),  /*shrewd_ptr<ProxyListValue>*/ \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyListValue::IsEqual ** 1 **/ \
		/*name*/	 _WT("是否相等"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 MAKELONG(20,0),  /*shrewd_ptr<ProxyListValue>*/ \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyListValue::SetSize ** 2 **/ \
		/*name*/	 _WT("大小"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyListValue::Remove ** 3 **/ \
		/*name*/	 _WT("索引"), \
		/*explain*/	 _WT("类型索引, 从0开始"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyListValue::GetType ** 4 **/ \
		/*name*/	 _WT("索引"), \
		/*explain*/	 _WT("类型索引, 从0开始"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyListValue::GetValue ** 5 **/ \
		/*name*/	 _WT("索引"), \
		/*explain*/	 _WT("类型索引, 从0开始"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyListValue::GetBool ** 6 **/ \
		/*name*/	 _WT("索引"), \
		/*explain*/	 _WT("类型索引, 从0开始"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyListValue::GetInt ** 7 **/ \
		/*name*/	 _WT("索引"), \
		/*explain*/	 _WT("索引, 从0开始。"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyListValue::GetDouble ** 8 **/ \
		/*name*/	 _WT("索引"), \
		/*explain*/	 _WT("类型索引, 从0开始"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyListValue::GetString ** 9 **/ \
		/*name*/	 _WT("索引"), \
		/*explain*/	 _WT("类型索引, 从0开始。"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyListValue::GetBinary ** 10 **/ \
		/*name*/	 _WT("索引"), \
		/*explain*/	 _WT("类型索引, 从0开始。"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyListValue::GetDictionary ** 11 **/ \
		/*name*/	 _WT("索引"), \
		/*explain*/	 _WT("类型索引, 从0开始"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyListValue::GetList ** 12 **/ \
		/*name*/	 _WT("索引"), \
		/*explain*/	 _WT("类型索引, 从0开始。"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyListValue::SetValue ** 13 **/ \
		/*name*/	 _WT("索引"), \
		/*explain*/	 _WT("类型索引, 从0开始。"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyListValue::SetValue ** 14 **/ \
		/*name*/	 _WT("类型值"), \
		/*explain*/	 _WT("预设值的类型值"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 MAKELONG(31,0),  /*shrewd_ptr<ProxyValue>*/ \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyListValue::SetNull ** 15 **/ \
		/*name*/	 _WT("索引"), \
		/*explain*/	 _WT("类型索引, 从0开始"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyListValue::SetBool ** 16 **/ \
		/*name*/	 _WT("索引"), \
		/*explain*/	 _WT("类型索引, 从0开始。"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyListValue::SetBool ** 17 **/ \
		/*name*/	 _WT("类型值"), \
		/*explain*/	 _WT("设置的类型值"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_BOOL, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyListValue::SetInt ** 18 **/ \
		/*name*/	 _WT("索引"), \
		/*explain*/	 _WT("类型索引, 从0开始"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyListValue::SetInt ** 19 **/ \
		/*name*/	 _WT("类型值"), \
		/*explain*/	 _WT("设置的类型值"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyListValue::SetDouble ** 20 **/ \
		/*name*/	 _WT("索引"), \
		/*explain*/	 _WT("类型索引, 从0开始"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyListValue::SetDouble ** 21 **/ \
		/*name*/	 _WT("类型值"), \
		/*explain*/	 _WT("设置的类型值"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_DOUBLE, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyListValue::SetString ** 22 **/ \
		/*name*/	 _WT("索引"), \
		/*explain*/	 _WT("类型索引, 从0开始"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyListValue::SetString ** 23 **/ \
		/*name*/	 _WT("类型值"), \
		/*explain*/	 _WT("设置的类型值"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_TEXT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyListValue::SetBinary ** 24 **/ \
		/*name*/	 _WT("索引"), \
		/*explain*/	 _WT("类型索引, 从0开始"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyListValue::SetBinary ** 25 **/ \
		/*name*/	 _WT("类型值"), \
		/*explain*/	 _WT("设置的类型值"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_BIN, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyListValue::SetBinary ** 26 **/ \
		/*name*/	 _WT("长度"), \
		/*explain*/	 _WT("数据长度"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyListValue::SetDictionary ** 27 **/ \
		/*name*/	 _WT("索引"), \
		/*explain*/	 _WT("类型索引, 从0开始"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyListValue::SetDictionary ** 28 **/ \
		/*name*/	 _WT("类型值"), \
		/*explain*/	 _WT("设置的类型值"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 MAKELONG(11,0),  /*shrewd_ptr<ProxyDictionaryValue>*/ \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyListValue::SetList ** 29 **/ \
		/*name*/	 _WT("索引"), \
		/*explain*/	 _WT("类型索引, 从0开始"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyListValue::SetList ** 30 **/ \
		/*name*/	 _WT("类型值"), \
		/*explain*/	 _WT("设置的类型值"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 MAKELONG(20,0),  /*shrewd_ptr<ProxyListValue>*/ \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\


//==========================================

#define DECL_DATA_TYPE_ProxyListValue_CMDINFO(BeginIndex) \
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
		/*ccname*/	_WT("是否拥有"),\
		/*egname*/	_WT("IsOwned"), \
		/*explain*/	_WT("如果基础数据由另一个对象拥有，则返回true。"), \
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
		/*ccname*/	_WT("是否相同"),\
		/*egname*/	_WT("IsSame"), \
		/*explain*/	_WT("比较两个对象是否相同"), \
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
	{ /*7*/ \
		/*ccname*/	_WT("是否相等"),\
		/*egname*/	_WT("IsEqual"), \
		/*explain*/	_WT("比较两个对象是否为同一个"), \
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
	{ /*8*/ \
		/*ccname*/	_WT("创建副本"),\
		/*egname*/	_WT("Copy"), \
		/*explain*/	_WT("为此对象创建一个新的副本"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	MAKELONG(20,0),  /*shrewd_ptr<ProxyListValue>*/ \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	0, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+2] \
	},\
	{ /*9*/ \
		/*ccname*/	_WT("置大小"),\
		/*egname*/	_WT("SetSize"), \
		/*explain*/	_WT("设置列表类型大小"), \
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
	{ /*10*/ \
		/*ccname*/	_WT("取大小"),\
		/*egname*/	_WT("GetSize"), \
		/*explain*/	_WT("返回列表大小"), \
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
		/*ccname*/	_WT("清空"),\
		/*egname*/	_WT("Clear"), \
		/*explain*/	_WT("清空类型"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	SDT_BOOL, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	0, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+3] \
	},\
	{ /*12*/ \
		/*ccname*/	_WT("移除"),\
		/*egname*/	_WT("Remove"), \
		/*explain*/	_WT("移除类型"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	SDT_BOOL, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	1, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+3] \
	},\
	{ /*13*/ \
		/*ccname*/	_WT("取类型"),\
		/*egname*/	_WT("GetType"), \
		/*explain*/	_WT("取该对象中存储的基础数据值类型, 有关定义在枚举常量: #值类型.* 中。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	SDT_INT, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	1, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+4] \
	},\
	{ /*14*/ \
		/*ccname*/	_WT("取通用型"),\
		/*egname*/	_WT("GetValue"), \
		/*explain*/	_WT("返回通用型类型数据。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	MAKELONG(31,0),  /*shrewd_ptr<ProxyValue>*/ \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	1, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+5] \
	},\
	{ /*15*/ \
		/*ccname*/	_WT("取逻辑型"),\
		/*egname*/	_WT("GetBool"), \
		/*explain*/	_WT("取逻辑型数据。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	SDT_BOOL, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	1, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+6] \
	},\
	{ /*16*/ \
		/*ccname*/	_WT("取整数型"),\
		/*egname*/	_WT("GetInt"), \
		/*explain*/	_WT("取整数型数据。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	SDT_INT, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	1, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+7] \
	},\
	{ /*17*/ \
		/*ccname*/	_WT("取双精度小数型"),\
		/*egname*/	_WT("GetDouble"), \
		/*explain*/	_WT("取双精度小数型数据。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	SDT_DOUBLE, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	1, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+8] \
	},\
	{ /*18*/ \
		/*ccname*/	_WT("取文本型"),\
		/*egname*/	_WT("GetString"), \
		/*explain*/	_WT("取文本型数据。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	SDT_TEXT, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	1, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+9] \
	},\
	{ /*19*/ \
		/*ccname*/	_WT("取字节集型"),\
		/*egname*/	_WT("GetBinary"), \
		/*explain*/	_WT("取字节集类型数据。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	SDT_BIN, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	1, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+10] \
	},\
	{ /*20*/ \
		/*ccname*/	_WT("取字典型"),\
		/*egname*/	_WT("GetDictionary"), \
		/*explain*/	_WT("取字典型数据。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	MAKELONG(11,0),  /*shrewd_ptr<ProxyDictionaryValue>*/ \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	1, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+11] \
	},\
	{ /*21*/ \
		/*ccname*/	_WT("取列表型"),\
		/*egname*/	_WT("GetList"), \
		/*explain*/	_WT("取列表型数据。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	MAKELONG(20,0),  /*shrewd_ptr<ProxyListValue>*/ \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	1, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+12] \
	},\
	{ /*22*/ \
		/*ccname*/	_WT("置通用型"),\
		/*egname*/	_WT("SetValue"), \
		/*explain*/	_WT("设置通用型数据。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	SDT_BOOL, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	2, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+13] \
	},\
	{ /*23*/ \
		/*ccname*/	_WT("置为空"),\
		/*egname*/	_WT("SetNull"), \
		/*explain*/	_WT("设置为空类型数据。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	SDT_BOOL, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	1, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+15] \
	},\
	{ /*24*/ \
		/*ccname*/	_WT("置逻辑型"),\
		/*egname*/	_WT("SetBool"), \
		/*explain*/	_WT("设置逻辑型数据。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	SDT_BOOL, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	2, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+16] \
	},\
	{ /*25*/ \
		/*ccname*/	_WT("置整数型"),\
		/*egname*/	_WT("SetInt"), \
		/*explain*/	_WT("设置整数型数据。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	SDT_BOOL, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	2, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+18] \
	},\
	{ /*26*/ \
		/*ccname*/	_WT("置双精度小数型"),\
		/*egname*/	_WT("SetDouble"), \
		/*explain*/	_WT("设置双精度小数型数据。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	SDT_BOOL, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	2, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+20] \
	},\
	{ /*27*/ \
		/*ccname*/	_WT("置文本型"),\
		/*egname*/	_WT("SetString"), \
		/*explain*/	_WT("设置文本型数据。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	SDT_BOOL, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	2, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+22] \
	},\
	{ /*28*/ \
		/*ccname*/	_WT("类型值"),\
		/*egname*/	_WT("SetBinary"), \
		/*explain*/	_WT("设置的类型值"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	SDT_BOOL, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	3, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+24] \
	},\
	{ /*29*/ \
		/*ccname*/	_WT("置字典型"),\
		/*egname*/	_WT("SetDictionary"), \
		/*explain*/	_WT("设置字典型数据。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	SDT_BOOL, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	2, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+27] \
	},\
	{ /*30*/ \
		/*ccname*/	_WT("置列表型"),\
		/*egname*/	_WT("SetList"), \
		/*explain*/	_WT("设置列表型数据。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	SDT_BOOL, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	2, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+29] \
	},\


//==========================================

#define DECL_DATA_TYPE_ProxyListValue_FUN_NAMES \
	EDITIONS("ProxyListValue_Constructor"),\
	EDITIONS("ProxyListValue_Destructor"),\
	EDITIONS("ProxyListValue_CopyConstructor"),\
	EDITIONS("ProxyListValue_IsValid"),\
	EDITIONS("ProxyListValue_IsOwned"),\
	EDITIONS("ProxyListValue_IsReadOnly"),\
	EDITIONS("ProxyListValue_IsSame"),\
	EDITIONS("ProxyListValue_IsEqual"),\
	EDITIONS("ProxyListValue_Copy"),\
	EDITIONS("ProxyListValue_SetSize"),\
	EDITIONS("ProxyListValue_GetSize"),\
	EDITIONS("ProxyListValue_Clear"),\
	EDITIONS("ProxyListValue_Remove"),\
	EDITIONS("ProxyListValue_GetType"),\
	EDITIONS("ProxyListValue_GetValue"),\
	EDITIONS("ProxyListValue_GetBool"),\
	EDITIONS("ProxyListValue_GetInt"),\
	EDITIONS("ProxyListValue_GetDouble"),\
	EDITIONS("ProxyListValue_GetString"),\
	EDITIONS("ProxyListValue_GetBinary"),\
	EDITIONS("ProxyListValue_GetDictionary"),\
	EDITIONS("ProxyListValue_GetList"),\
	EDITIONS("ProxyListValue_SetValue"),\
	EDITIONS("ProxyListValue_SetNull"),\
	EDITIONS("ProxyListValue_SetBool"),\
	EDITIONS("ProxyListValue_SetInt"),\
	EDITIONS("ProxyListValue_SetDouble"),\
	EDITIONS("ProxyListValue_SetString"),\
	EDITIONS("ProxyListValue_SetBinary"),\
	EDITIONS("ProxyListValue_SetDictionary"),\
	EDITIONS("ProxyListValue_SetList"),\


//==========================================

#define DECL_DATA_TYPE_ProxyListValue_FUN_CALLS \
	EDITIONF(ProxyListValue_Constructor),\
	EDITIONF(ProxyListValue_Destructor),\
	EDITIONF(ProxyListValue_CopyConstructor),\
	EDITIONF(ProxyListValue_IsValid),\
	EDITIONF(ProxyListValue_IsOwned),\
	EDITIONF(ProxyListValue_IsReadOnly),\
	EDITIONF(ProxyListValue_IsSame),\
	EDITIONF(ProxyListValue_IsEqual),\
	EDITIONF(ProxyListValue_Copy),\
	EDITIONF(ProxyListValue_SetSize),\
	EDITIONF(ProxyListValue_GetSize),\
	EDITIONF(ProxyListValue_Clear),\
	EDITIONF(ProxyListValue_Remove),\
	EDITIONF(ProxyListValue_GetType),\
	EDITIONF(ProxyListValue_GetValue),\
	EDITIONF(ProxyListValue_GetBool),\
	EDITIONF(ProxyListValue_GetInt),\
	EDITIONF(ProxyListValue_GetDouble),\
	EDITIONF(ProxyListValue_GetString),\
	EDITIONF(ProxyListValue_GetBinary),\
	EDITIONF(ProxyListValue_GetDictionary),\
	EDITIONF(ProxyListValue_GetList),\
	EDITIONF(ProxyListValue_SetValue),\
	EDITIONF(ProxyListValue_SetNull),\
	EDITIONF(ProxyListValue_SetBool),\
	EDITIONF(ProxyListValue_SetInt),\
	EDITIONF(ProxyListValue_SetDouble),\
	EDITIONF(ProxyListValue_SetString),\
	EDITIONF(ProxyListValue_SetBinary),\
	EDITIONF(ProxyListValue_SetDictionary),\
	EDITIONF(ProxyListValue_SetList),\


//==========================================

extern "C"
void EDITIONF(ProxyListValue_Constructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyListValue_Destructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyListValue_CopyConstructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyListValue_IsValid) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyListValue_IsOwned) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyListValue_IsReadOnly) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyListValue_IsSame) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyListValue_IsEqual) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyListValue_Copy) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyListValue_SetSize) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyListValue_GetSize) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyListValue_Clear) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyListValue_Remove) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyListValue_GetType) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyListValue_GetValue) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyListValue_GetBool) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyListValue_GetInt) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyListValue_GetDouble) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyListValue_GetString) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyListValue_GetBinary) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyListValue_GetDictionary) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyListValue_GetList) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyListValue_SetValue) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyListValue_SetNull) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyListValue_SetBool) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyListValue_SetInt) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyListValue_SetDouble) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyListValue_SetString) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyListValue_SetBinary) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyListValue_SetDictionary) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyListValue_SetList) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);


//==========================================

