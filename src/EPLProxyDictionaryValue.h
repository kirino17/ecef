#pragma once

#include "stdafx.h"
#include "lib2.h"


#define DECL_DATA_TYPE_ProxyDictionaryValue \
	{ /*11*/ \
		/*m_szName*/		 _WT("水星字典型"), \
		/*m_szEgName*/		 _WT("ProxyDictionaryValue"), \
		/*m_szExplain*/		 _WT("表示字典值(DictionaryValue)的类。"), \
		/*m_nCmdCount*/		 32, \
		/*m_pnCmdsIndex*/		 s_nProxyDictionaryValueElementCmdIndex, \
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

#define DECL_DATA_TYPE_ProxyDictionaryValue_ARGINFO \
	{ /****** ProxyDictionaryValue::IsSame ** 0 **/ \
		/*name*/	 _WT("比较对象"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 MAKELONG(11,0),  /*shrewd_ptr<ProxyDictionaryValue>*/ \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyDictionaryValue::IsEqual ** 1 **/ \
		/*name*/	 _WT("比较对象"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 MAKELONG(11,0),  /*shrewd_ptr<ProxyDictionaryValue>*/ \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyDictionaryValue::Copy ** 2 **/ \
		/*name*/	 _WT("是否清空"), \
		/*explain*/	 _WT("如果此参数为真,所有空的子字典值对象或子列表值对象都将从副本中排除。"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_BOOL, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyDictionaryValue::HasKey ** 3 **/ \
		/*name*/	 _WT("键名"), \
		/*explain*/	 _WT("键名称"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_TEXT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyDictionaryValue::Remove ** 4 **/ \
		/*name*/	 _WT("键名"), \
		/*explain*/	 _WT("键名称"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_TEXT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyDictionaryValue::GetType ** 5 **/ \
		/*name*/	 _WT("键名"), \
		/*explain*/	 _WT("键名称"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_TEXT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyDictionaryValue::GetValue ** 6 **/ \
		/*name*/	 _WT("键名"), \
		/*explain*/	 _WT("键名称"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_TEXT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyDictionaryValue::GetBool ** 7 **/ \
		/*name*/	 _WT("键名"), \
		/*explain*/	 _WT("键名称"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_TEXT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyDictionaryValue::GetInt ** 8 **/ \
		/*name*/	 _WT("键名"), \
		/*explain*/	 _WT("键名称"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_TEXT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyDictionaryValue::GetDouble ** 9 **/ \
		/*name*/	 _WT("键名"), \
		/*explain*/	 _WT("键名称"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_TEXT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyDictionaryValue::GetString ** 10 **/ \
		/*name*/	 _WT("键名"), \
		/*explain*/	 _WT("键名称"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_TEXT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyDictionaryValue::GetBinary ** 11 **/ \
		/*name*/	 _WT("键名"), \
		/*explain*/	 _WT("键名称"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_TEXT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyDictionaryValue::GetDictionary ** 12 **/ \
		/*name*/	 _WT("键名"), \
		/*explain*/	 _WT("键名称"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_TEXT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyDictionaryValue::GetList ** 13 **/ \
		/*name*/	 _WT("键名"), \
		/*explain*/	 _WT("键名称"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_TEXT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyDictionaryValue::SetValue ** 14 **/ \
		/*name*/	 _WT("键名"), \
		/*explain*/	 _WT("键名称"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_TEXT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyDictionaryValue::SetValue ** 15 **/ \
		/*name*/	 _WT("类型值"), \
		/*explain*/	 _WT("设置的类型值。"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 MAKELONG(31,0),  /*shrewd_ptr<ProxyValue>*/ \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyDictionaryValue::SetNull ** 16 **/ \
		/*name*/	 _WT("键名"), \
		/*explain*/	 _WT("键名称"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_TEXT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyDictionaryValue::SetBool ** 17 **/ \
		/*name*/	 _WT("键名"), \
		/*explain*/	 _WT("键名称"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_TEXT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyDictionaryValue::SetBool ** 18 **/ \
		/*name*/	 _WT("类型值"), \
		/*explain*/	 _WT("设置的类型值。"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_BOOL, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyDictionaryValue::SetInt ** 19 **/ \
		/*name*/	 _WT("键名"), \
		/*explain*/	 _WT("键名称"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_TEXT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyDictionaryValue::SetInt ** 20 **/ \
		/*name*/	 _WT("类型值"), \
		/*explain*/	 _WT("设置的类型值。"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyDictionaryValue::SetDouble ** 21 **/ \
		/*name*/	 _WT("键名"), \
		/*explain*/	 _WT("键名称"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_TEXT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyDictionaryValue::SetDouble ** 22 **/ \
		/*name*/	 _WT("类型值"), \
		/*explain*/	 _WT("设置的类型值。"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_DOUBLE, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyDictionaryValue::SetString ** 23 **/ \
		/*name*/	 _WT("键名"), \
		/*explain*/	 _WT("键名称"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_TEXT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyDictionaryValue::SetString ** 24 **/ \
		/*name*/	 _WT("类型值"), \
		/*explain*/	 _WT("设置的类型值。"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_TEXT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyDictionaryValue::SetBinary ** 25 **/ \
		/*name*/	 _WT("键名"), \
		/*explain*/	 _WT("键名称"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_TEXT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyDictionaryValue::SetBinary ** 26 **/ \
		/*name*/	 _WT("类型值"), \
		/*explain*/	 _WT("设置的类型值。"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_BIN, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyDictionaryValue::SetBinary ** 27 **/ \
		/*name*/	 _WT("长度"), \
		/*explain*/	 _WT("类型值长度"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyDictionaryValue::SetDictionary ** 28 **/ \
		/*name*/	 _WT("键名"), \
		/*explain*/	 _WT("键名称"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_TEXT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyDictionaryValue::SetDictionary ** 29 **/ \
		/*name*/	 _WT("类型值"), \
		/*explain*/	 _WT("设置的类型值。"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 MAKELONG(11,0),  /*shrewd_ptr<ProxyDictionaryValue>*/ \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyDictionaryValue::SetList ** 30 **/ \
		/*name*/	 _WT("键名"), \
		/*explain*/	 _WT("键名称"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_TEXT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyDictionaryValue::SetList ** 31 **/ \
		/*name*/	 _WT("类型值"), \
		/*explain*/	 _WT("设置的类型值。"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 MAKELONG(20,0),  /*shrewd_ptr<ProxyListValue>*/ \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\


//==========================================

#define DECL_DATA_TYPE_ProxyDictionaryValue_CMDINFO(BeginIndex) \
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
		/*ccname*/	_WT("是否只读"),\
		/*egname*/	_WT("IsReadOnly"), \
		/*explain*/	_WT("如果对象是只读的返回真"), \
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
		/*explain*/	_WT("比较两个对象是否相同。"), \
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
		/*explain*/	_WT("比较两个对象是否为同一个。"), \
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
		/*explain*/	_WT("为此对象创建一个新副本。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	MAKELONG(11,0),  /*shrewd_ptr<ProxyDictionaryValue>*/ \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	1, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+2] \
	},\
	{ /*9*/ \
		/*ccname*/	_WT("取大小"),\
		/*egname*/	_WT("GetSize"), \
		/*explain*/	_WT("取已存储类型大小"), \
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
	{ /*10*/ \
		/*ccname*/	_WT("清空"),\
		/*egname*/	_WT("Clear"), \
		/*explain*/	_WT("清空类型数据。"), \
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
	{ /*11*/ \
		/*ccname*/	_WT("可有键"),\
		/*egname*/	_WT("HasKey"), \
		/*explain*/	_WT("如果指定的键名存在返回真。"), \
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
	{ /*12*/ \
		/*ccname*/	_WT("取所有键"),\
		/*egname*/	_WT("GetKeys"), \
		/*explain*/	_WT("返回以Key字符串列表。"), \
		/*category*/	-1, \
		/*state*/	CT_RETRUN_ARY_TYPE_DATA, \
		/*ret*/	SDT_TEXT, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	0, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+4] \
	},\
	{ /*13*/ \
		/*ccname*/	_WT("移除键"),\
		/*egname*/	_WT("Remove"), \
		/*explain*/	_WT("删除指定的键值项"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	SDT_BOOL, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	1, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+4] \
	},\
	{ /*14*/ \
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
		/*arg lp*/	&s_ArgInfo[BeginIndex+5] \
	},\
	{ /*15*/ \
		/*ccname*/	_WT("取通用型"),\
		/*egname*/	_WT("GetValue"), \
		/*explain*/	_WT("取通用型数据。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	MAKELONG(31,0),  /*shrewd_ptr<ProxyValue>*/ \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	1, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+6] \
	},\
	{ /*16*/ \
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
		/*arg lp*/	&s_ArgInfo[BeginIndex+7] \
	},\
	{ /*17*/ \
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
		/*arg lp*/	&s_ArgInfo[BeginIndex+8] \
	},\
	{ /*18*/ \
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
		/*arg lp*/	&s_ArgInfo[BeginIndex+9] \
	},\
	{ /*19*/ \
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
		/*arg lp*/	&s_ArgInfo[BeginIndex+10] \
	},\
	{ /*20*/ \
		/*ccname*/	_WT("取字节集型"),\
		/*egname*/	_WT("GetBinary"), \
		/*explain*/	_WT("取字节集型数据。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	SDT_BIN, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	1, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+11] \
	},\
	{ /*21*/ \
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
		/*arg lp*/	&s_ArgInfo[BeginIndex+12] \
	},\
	{ /*22*/ \
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
		/*arg lp*/	&s_ArgInfo[BeginIndex+13] \
	},\
	{ /*23*/ \
		/*ccname*/	_WT("置通用型"),\
		/*egname*/	_WT("SetValue"), \
		/*explain*/	_WT("设置通用型数据"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	SDT_BOOL, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	2, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+14] \
	},\
	{ /*24*/ \
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
		/*arg lp*/	&s_ArgInfo[BeginIndex+16] \
	},\
	{ /*25*/ \
		/*ccname*/	_WT("置逻辑型"),\
		/*egname*/	_WT("SetBool"), \
		/*explain*/	_WT("设置为逻辑型数据"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	SDT_BOOL, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	2, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+17] \
	},\
	{ /*26*/ \
		/*ccname*/	_WT("置整数型"),\
		/*egname*/	_WT("SetInt"), \
		/*explain*/	_WT("设置为整数型数据"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	SDT_BOOL, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	2, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+19] \
	},\
	{ /*27*/ \
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
		/*arg lp*/	&s_ArgInfo[BeginIndex+21] \
	},\
	{ /*28*/ \
		/*ccname*/	_WT("置文本型"),\
		/*egname*/	_WT("SetString"), \
		/*explain*/	_WT("设置为文本型数据。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	SDT_BOOL, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	2, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+23] \
	},\
	{ /*29*/ \
		/*ccname*/	_WT("置字节集型"),\
		/*egname*/	_WT("SetBinary"), \
		/*explain*/	_WT("设置为字节集类型数据。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	SDT_BOOL, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	3, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+25] \
	},\
	{ /*30*/ \
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
		/*arg lp*/	&s_ArgInfo[BeginIndex+28] \
	},\
	{ /*31*/ \
		/*ccname*/	_WT("置列表型"),\
		/*egname*/	_WT("SetList"), \
		/*explain*/	_WT("设置为列表型数据"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	SDT_BOOL, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	2, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+30] \
	},\


//==========================================

#define DECL_DATA_TYPE_ProxyDictionaryValue_FUN_NAMES \
	EDITIONS("ProxyDictionaryValue_Constructor"),\
	EDITIONS("ProxyDictionaryValue_Destructor"),\
	EDITIONS("ProxyDictionaryValue_CopyConstructor"),\
	EDITIONS("ProxyDictionaryValue_IsValid"),\
	EDITIONS("ProxyDictionaryValue_IsOwned"),\
	EDITIONS("ProxyDictionaryValue_IsReadOnly"),\
	EDITIONS("ProxyDictionaryValue_IsSame"),\
	EDITIONS("ProxyDictionaryValue_IsEqual"),\
	EDITIONS("ProxyDictionaryValue_Copy"),\
	EDITIONS("ProxyDictionaryValue_GetSize"),\
	EDITIONS("ProxyDictionaryValue_Clear"),\
	EDITIONS("ProxyDictionaryValue_HasKey"),\
	EDITIONS("ProxyDictionaryValue_GetKeys"),\
	EDITIONS("ProxyDictionaryValue_Remove"),\
	EDITIONS("ProxyDictionaryValue_GetType"),\
	EDITIONS("ProxyDictionaryValue_GetValue"),\
	EDITIONS("ProxyDictionaryValue_GetBool"),\
	EDITIONS("ProxyDictionaryValue_GetInt"),\
	EDITIONS("ProxyDictionaryValue_GetDouble"),\
	EDITIONS("ProxyDictionaryValue_GetString"),\
	EDITIONS("ProxyDictionaryValue_GetBinary"),\
	EDITIONS("ProxyDictionaryValue_GetDictionary"),\
	EDITIONS("ProxyDictionaryValue_GetList"),\
	EDITIONS("ProxyDictionaryValue_SetValue"),\
	EDITIONS("ProxyDictionaryValue_SetNull"),\
	EDITIONS("ProxyDictionaryValue_SetBool"),\
	EDITIONS("ProxyDictionaryValue_SetInt"),\
	EDITIONS("ProxyDictionaryValue_SetDouble"),\
	EDITIONS("ProxyDictionaryValue_SetString"),\
	EDITIONS("ProxyDictionaryValue_SetBinary"),\
	EDITIONS("ProxyDictionaryValue_SetDictionary"),\
	EDITIONS("ProxyDictionaryValue_SetList"),\


//==========================================

#define DECL_DATA_TYPE_ProxyDictionaryValue_FUN_CALLS \
	EDITIONF(ProxyDictionaryValue_Constructor),\
	EDITIONF(ProxyDictionaryValue_Destructor),\
	EDITIONF(ProxyDictionaryValue_CopyConstructor),\
	EDITIONF(ProxyDictionaryValue_IsValid),\
	EDITIONF(ProxyDictionaryValue_IsOwned),\
	EDITIONF(ProxyDictionaryValue_IsReadOnly),\
	EDITIONF(ProxyDictionaryValue_IsSame),\
	EDITIONF(ProxyDictionaryValue_IsEqual),\
	EDITIONF(ProxyDictionaryValue_Copy),\
	EDITIONF(ProxyDictionaryValue_GetSize),\
	EDITIONF(ProxyDictionaryValue_Clear),\
	EDITIONF(ProxyDictionaryValue_HasKey),\
	EDITIONF(ProxyDictionaryValue_GetKeys),\
	EDITIONF(ProxyDictionaryValue_Remove),\
	EDITIONF(ProxyDictionaryValue_GetType),\
	EDITIONF(ProxyDictionaryValue_GetValue),\
	EDITIONF(ProxyDictionaryValue_GetBool),\
	EDITIONF(ProxyDictionaryValue_GetInt),\
	EDITIONF(ProxyDictionaryValue_GetDouble),\
	EDITIONF(ProxyDictionaryValue_GetString),\
	EDITIONF(ProxyDictionaryValue_GetBinary),\
	EDITIONF(ProxyDictionaryValue_GetDictionary),\
	EDITIONF(ProxyDictionaryValue_GetList),\
	EDITIONF(ProxyDictionaryValue_SetValue),\
	EDITIONF(ProxyDictionaryValue_SetNull),\
	EDITIONF(ProxyDictionaryValue_SetBool),\
	EDITIONF(ProxyDictionaryValue_SetInt),\
	EDITIONF(ProxyDictionaryValue_SetDouble),\
	EDITIONF(ProxyDictionaryValue_SetString),\
	EDITIONF(ProxyDictionaryValue_SetBinary),\
	EDITIONF(ProxyDictionaryValue_SetDictionary),\
	EDITIONF(ProxyDictionaryValue_SetList),\


//==========================================

extern "C"
void EDITIONF(ProxyDictionaryValue_Constructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyDictionaryValue_Destructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyDictionaryValue_CopyConstructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyDictionaryValue_IsValid) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyDictionaryValue_IsOwned) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyDictionaryValue_IsReadOnly) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyDictionaryValue_IsSame) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyDictionaryValue_IsEqual) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyDictionaryValue_Copy) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyDictionaryValue_GetSize) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyDictionaryValue_Clear) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyDictionaryValue_HasKey) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyDictionaryValue_GetKeys) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyDictionaryValue_Remove) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyDictionaryValue_GetType) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyDictionaryValue_GetValue) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyDictionaryValue_GetBool) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyDictionaryValue_GetInt) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyDictionaryValue_GetDouble) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyDictionaryValue_GetString) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyDictionaryValue_GetBinary) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyDictionaryValue_GetDictionary) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyDictionaryValue_GetList) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyDictionaryValue_SetValue) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyDictionaryValue_SetNull) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyDictionaryValue_SetBool) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyDictionaryValue_SetInt) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyDictionaryValue_SetDouble) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyDictionaryValue_SetString) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyDictionaryValue_SetBinary) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyDictionaryValue_SetDictionary) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyDictionaryValue_SetList) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);


//==========================================

