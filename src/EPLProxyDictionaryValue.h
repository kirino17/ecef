#pragma once

#include "stdafx.h"
#include "lib2.h"


#define DECL_DATA_TYPE_ProxyDictionaryValue \
	{ /*11*/ \
		/*m_szName*/		 _WT("Chromium字典值"), \
		/*m_szEgName*/		 _WT("ProxyDictionaryValue"), \
		/*m_szExplain*/		 _WT("表示字典值(DictionaryValue)的类。"), \
		/*m_nCmdCount*/		 33, \
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
		/*name*/	 _WT("that"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 MAKELONG(12,0),  /*shrewd_ptr<ProxyDictionaryValue>*/ \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxyDictionaryValue::IsEqual ** 1 **/ \
		/*name*/	 _WT("that"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 MAKELONG(12,0),  /*shrewd_ptr<ProxyDictionaryValue>*/ \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxyDictionaryValue::Copy ** 2 **/ \
		/*name*/	 _WT("exclude_empty_children"), \
		/*explain*/	 _WT("如果此参数为真,所有空的子字典值对象或子列表值对象都将从副本中排除。"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_BOOL, \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxyDictionaryValue::HasKey ** 3 **/ \
		/*name*/	 _WT("key"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_TEXT, \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxyDictionaryValue::Remove ** 4 **/ \
		/*name*/	 _WT("key"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_TEXT, \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxyDictionaryValue::GetType ** 5 **/ \
		/*name*/	 _WT("key"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_TEXT, \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxyDictionaryValue::GetValue ** 6 **/ \
		/*name*/	 _WT("key"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_TEXT, \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxyDictionaryValue::GetBool ** 7 **/ \
		/*name*/	 _WT("key"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_TEXT, \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxyDictionaryValue::GetInt ** 8 **/ \
		/*name*/	 _WT("key"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_TEXT, \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxyDictionaryValue::GetDouble ** 9 **/ \
		/*name*/	 _WT("key"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_TEXT, \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxyDictionaryValue::GetString ** 10 **/ \
		/*name*/	 _WT("key"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_TEXT, \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxyDictionaryValue::GetBinary ** 11 **/ \
		/*name*/	 _WT("key"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_TEXT, \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxyDictionaryValue::GetDictionary ** 12 **/ \
		/*name*/	 _WT("key"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_TEXT, \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxyDictionaryValue::GetList ** 13 **/ \
		/*name*/	 _WT("key"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_TEXT, \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxyDictionaryValue::SetValue ** 14 **/ \
		/*name*/	 _WT("key"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_TEXT, \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxyDictionaryValue::SetValue ** 15 **/ \
		/*name*/	 _WT("value"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 MAKELONG(36,0),  /*shrewd_ptr<ProxyValue>*/ \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxyDictionaryValue::SetNull ** 16 **/ \
		/*name*/	 _WT("key"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_TEXT, \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxyDictionaryValue::SetBool ** 17 **/ \
		/*name*/	 _WT("key"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_TEXT, \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxyDictionaryValue::SetBool ** 18 **/ \
		/*name*/	 _WT("value"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_BOOL, \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxyDictionaryValue::SetInt ** 19 **/ \
		/*name*/	 _WT("key"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_TEXT, \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxyDictionaryValue::SetInt ** 20 **/ \
		/*name*/	 _WT("value"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxyDictionaryValue::SetDouble ** 21 **/ \
		/*name*/	 _WT("key"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_TEXT, \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxyDictionaryValue::SetDouble ** 22 **/ \
		/*name*/	 _WT("value"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_DOUBLE, \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxyDictionaryValue::SetString ** 23 **/ \
		/*name*/	 _WT("key"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_TEXT, \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxyDictionaryValue::SetString ** 24 **/ \
		/*name*/	 _WT("value"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_TEXT, \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxyDictionaryValue::SetBinary ** 25 **/ \
		/*name*/	 _WT("key"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_TEXT, \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxyDictionaryValue::SetBinary ** 26 **/ \
		/*name*/	 _WT("value"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_BIN, \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxyDictionaryValue::SetBinary ** 27 **/ \
		/*name*/	 _WT("length"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxyDictionaryValue::SetDictionary ** 28 **/ \
		/*name*/	 _WT("key"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_TEXT, \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxyDictionaryValue::SetDictionary ** 29 **/ \
		/*name*/	 _WT("value"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 MAKELONG(12,0),  /*shrewd_ptr<ProxyDictionaryValue>*/ \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxyDictionaryValue::SetList ** 30 **/ \
		/*name*/	 _WT("key"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_TEXT, \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxyDictionaryValue::SetList ** 31 **/ \
		/*name*/	 _WT("value"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 MAKELONG(19,0),  /*shrewd_ptr<ProxyListValue>*/ \
		/*default*/	 0,\
		/*state*/	 NULL\
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
		/*ccname*/	_WT("创建对象"),\
		/*egname*/	_WT("Create"), \
		/*explain*/	_WT("创建对象实例, 非静态对象, 需要调用此函数后才能够有效访问。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	MAKELONG(12,0),  /*shrewd_ptr<ProxyDictionaryValue>*/ \
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
		/*ccname*/	_WT("IsOwned"),\
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
	{ /*6*/ \
		/*ccname*/	_WT("IsReadOnly"),\
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
	{ /*7*/ \
		/*ccname*/	_WT("IsSame"),\
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
	{ /*8*/ \
		/*ccname*/	_WT("IsEqual"),\
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
	{ /*9*/ \
		/*ccname*/	_WT("Copy"),\
		/*egname*/	_WT("Copy"), \
		/*explain*/	_WT("为此对象创建一个新副本。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	MAKELONG(12,0),  /*shrewd_ptr<ProxyDictionaryValue>*/ \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	1, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+2] \
	},\
	{ /*10*/ \
		/*ccname*/	_WT("GetSize"),\
		/*egname*/	_WT("GetSize"), \
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
		/*ccname*/	_WT("Clear"),\
		/*egname*/	_WT("Clear"), \
		/*explain*/	_WT(""), \
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
		/*ccname*/	_WT("HasKey"),\
		/*egname*/	_WT("HasKey"), \
		/*explain*/	_WT(""), \
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
		/*ccname*/	_WT("GetKeys"),\
		/*egname*/	_WT("GetKeys"), \
		/*explain*/	_WT("返回以 #换行符 分隔的Key字符串列表。"), \
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
	{ /*14*/ \
		/*ccname*/	_WT("Remove"),\
		/*egname*/	_WT("Remove"), \
		/*explain*/	_WT(""), \
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
	{ /*15*/ \
		/*ccname*/	_WT("GetType"),\
		/*egname*/	_WT("GetType"), \
		/*explain*/	_WT("获取该对象中存储的基础数据值类型, 有关定义在枚举常量: #值类型.* 中。"), \
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
	{ /*16*/ \
		/*ccname*/	_WT("GetValue"),\
		/*egname*/	_WT("GetValue"), \
		/*explain*/	_WT(""), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	MAKELONG(36,0),  /*shrewd_ptr<ProxyValue>*/ \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	1, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+6] \
	},\
	{ /*17*/ \
		/*ccname*/	_WT("GetBool"),\
		/*egname*/	_WT("GetBool"), \
		/*explain*/	_WT(""), \
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
	{ /*18*/ \
		/*ccname*/	_WT("GetInt"),\
		/*egname*/	_WT("GetInt"), \
		/*explain*/	_WT(""), \
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
	{ /*19*/ \
		/*ccname*/	_WT("GetDouble"),\
		/*egname*/	_WT("GetDouble"), \
		/*explain*/	_WT(""), \
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
	{ /*20*/ \
		/*ccname*/	_WT("GetString"),\
		/*egname*/	_WT("GetString"), \
		/*explain*/	_WT(""), \
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
	{ /*21*/ \
		/*ccname*/	_WT("GetBinary"),\
		/*egname*/	_WT("GetBinary"), \
		/*explain*/	_WT(""), \
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
	{ /*22*/ \
		/*ccname*/	_WT("GetDictionary"),\
		/*egname*/	_WT("GetDictionary"), \
		/*explain*/	_WT(""), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	MAKELONG(12,0),  /*shrewd_ptr<ProxyDictionaryValue>*/ \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	1, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+12] \
	},\
	{ /*23*/ \
		/*ccname*/	_WT("GetList"),\
		/*egname*/	_WT("GetList"), \
		/*explain*/	_WT(""), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	MAKELONG(19,0),  /*shrewd_ptr<ProxyListValue>*/ \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	1, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+13] \
	},\
	{ /*24*/ \
		/*ccname*/	_WT("SetValue"),\
		/*egname*/	_WT("SetValue"), \
		/*explain*/	_WT(""), \
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
	{ /*25*/ \
		/*ccname*/	_WT("SetNull"),\
		/*egname*/	_WT("SetNull"), \
		/*explain*/	_WT(""), \
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
	{ /*26*/ \
		/*ccname*/	_WT("SetBool"),\
		/*egname*/	_WT("SetBool"), \
		/*explain*/	_WT(""), \
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
	{ /*27*/ \
		/*ccname*/	_WT("SetInt"),\
		/*egname*/	_WT("SetInt"), \
		/*explain*/	_WT(""), \
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
	{ /*28*/ \
		/*ccname*/	_WT("SetDouble"),\
		/*egname*/	_WT("SetDouble"), \
		/*explain*/	_WT(""), \
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
	{ /*29*/ \
		/*ccname*/	_WT("SetString"),\
		/*egname*/	_WT("SetString"), \
		/*explain*/	_WT(""), \
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
	{ /*30*/ \
		/*ccname*/	_WT("SetBinary"),\
		/*egname*/	_WT("SetBinary"), \
		/*explain*/	_WT(""), \
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
	{ /*31*/ \
		/*ccname*/	_WT("SetDictionary"),\
		/*egname*/	_WT("SetDictionary"), \
		/*explain*/	_WT(""), \
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
	{ /*32*/ \
		/*ccname*/	_WT("SetList"),\
		/*egname*/	_WT("SetList"), \
		/*explain*/	_WT(""), \
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
	EDITIONS("ProxyDictionaryValue_Create"),\
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
	EDITIONF(ProxyDictionaryValue_Create),\
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
void EDITIONF(ProxyDictionaryValue_Create) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
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

