#pragma once

#include "stdafx.h"
#include "lib2.h"


#define DECL_DATA_TYPE_ProxyBase \
	{ /*3*/ \
		/*m_szName*/		 _WT("静态方法"), \
		/*m_szEgName*/		 _WT("ProxyBase"), \
		/*m_szExplain*/		 _WT("适用于全局的静态函数集合。"), \
		/*m_nCmdCount*/		 34, \
		/*m_pnCmdsIndex*/		 s_nProxyBaseElementCmdIndex, \
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

#define DECL_DATA_TYPE_ProxyBase_ARGINFO \
	{ /****** ProxyBase::Initialize ** 0 **/ \
		/*name*/	 _WT("初始化设置"), \
		/*explain*/	 _WT("全局初始化配置参数。"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 MAKELONG(29,0),  /*shrewd_ptr<ProxySettings>*/ \
		/*default*/	 0,\
		/*state*/	 AS_DEFAULT_VALUE_IS_EMPTY \
	},\
	{ /****** ProxyBase::Initialize ** 1 **/ \
		/*name*/	 _WT("保留"), \
		/*explain*/	 _WT("请设置为0."), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 AS_DEFAULT_VALUE_IS_EMPTY \
	},\
	{ /****** ProxyBase::Base64Encode ** 2 **/ \
		/*name*/	 _WT("待编码的数据"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_BIN, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyBase::Base64Encode ** 3 **/ \
		/*name*/	 _WT("数据长度"), \
		/*explain*/	 _WT("待编码的数据的字节长度"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyBase::Base64Decode ** 4 **/ \
		/*name*/	 _WT("编码字符串"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_TEXT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyBase::UriEncode ** 5 **/ \
		/*name*/	 _WT("转义的字符串"), \
		/*explain*/	 _WT("执行URI转义的字符串。"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_TEXT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyBase::UriEncode ** 6 **/ \
		/*name*/	 _WT("空格转义为加号"), \
		/*explain*/	 _WT("如果设置为真, 将使用\"+\"转义空格符号"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_BOOL, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyBase::UriDecode ** 7 **/ \
		/*name*/	 _WT("待解码的字符串"), \
		/*explain*/	 _WT("将解码的URI转义字符串"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_TEXT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyBase::UriDecode ** 8 **/ \
		/*name*/	 _WT("转换到UTF8"), \
		/*explain*/	 _WT("是否将转义字符还原为UTF8字符"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_BOOL, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyBase::UriDecode ** 9 **/ \
		/*name*/	 _WT("转义规则"), \
		/*explain*/	 _WT("转义字符的解码规则, 定义见枚举常量定义值: #转义规则.* , 使用位或可叠加多个标志值。"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyBase::Utf8ToBytes ** 10 **/ \
		/*name*/	 _WT("待解码的字符串"), \
		/*explain*/	 _WT("待解码的字符串"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_BIN, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyBase::Utf8ToBytes ** 11 **/ \
		/*name*/	 _WT("字节长度"), \
		/*explain*/	 _WT("待解码字符串的字节长度"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyBase::BytesToUtf8 ** 12 **/ \
		/*name*/	 _WT("待编码的字符串"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_TEXT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyBase::CreateListValue ** 13 **/ \
		/*name*/	 _WT("初始化值"), \
		/*explain*/	 _WT("初始化值, 可以为基本数据类型值: #逻辑型、#字节型、#短整数型、整数型、小数型、#双精度小数型、#文本型、#字节集以及支持库基础值包装类型: #水星通用型、#水星列表型、#水星字典型"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 _SDT_ALL, \
		/*default*/	 0,\
		/*state*/	 AS_DEFAULT_VALUE_IS_EMPTY \
	},\
	{ /****** ProxyBase::CreatePostDataElementWithFile ** 14 **/ \
		/*name*/	 _WT("文件名"), \
		/*explain*/	 _WT("欲作提交的文件数据"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_TEXT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyBase::CreatePostDataElementWithData ** 15 **/ \
		/*name*/	 _WT("字节集数据"), \
		/*explain*/	 _WT("欲作提交的字节集数据"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_BIN, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyBase::CreateRequest ** 16 **/ \
		/*name*/	 _WT("方法"), \
		/*explain*/	 _WT("请求(Request)的方法, GET / POST / PUT ..."), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_TEXT, \
		/*default*/	 0,\
		/*state*/	 AS_DEFAULT_VALUE_IS_EMPTY \
	},\
	{ /****** ProxyBase::CreateRequest ** 17 **/ \
		/*name*/	 _WT("url"), \
		/*explain*/	 _WT("请求地址"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_TEXT, \
		/*default*/	 0,\
		/*state*/	 AS_DEFAULT_VALUE_IS_EMPTY \
	},\
	{ /****** ProxyBase::CreateRequest ** 18 **/ \
		/*name*/	 _WT("来源地址"), \
		/*explain*/	 _WT("设置来源(referrer)信息。"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_TEXT, \
		/*default*/	 0,\
		/*state*/	 AS_DEFAULT_VALUE_IS_EMPTY \
	},\
	{ /****** ProxyBase::CreateRequest ** 19 **/ \
		/*name*/	 _WT("标头字符串"), \
		/*explain*/	 _WT("设置标头信息。HTTP Header标准格式。"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_TEXT, \
		/*default*/	 0,\
		/*state*/	 AS_DEFAULT_VALUE_IS_EMPTY \
	},\
	{ /****** ProxyBase::CreateRequest ** 20 **/ \
		/*name*/	 _WT("提交数据"), \
		/*explain*/	 _WT("设置将要提交的数据"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 MAKELONG(22,0),  /*shrewd_ptr<ProxyPostDataElement>*/ \
		/*default*/	 0,\
		/*state*/	 AS_DEFAULT_VALUE_IS_EMPTY \
	},\
	{ /****** ProxyBase::CreateValue ** 21 **/ \
		/*name*/	 _WT("初始化值"), \
		/*explain*/	 _WT("初始化值, 可以为基本数据类型值: #逻辑型、#字节型、#短整数型、整数型、小数型、#双精度小数型、#文本型、#字节集以及支持库基础值包装类型: #水星通用型、#水星列表型、#水星字典型"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 _SDT_ALL, \
		/*default*/	 0,\
		/*state*/	 AS_DEFAULT_VALUE_IS_EMPTY \
	},\
	{ /****** ProxyBase::CreateAsChildWindow ** 22 **/ \
		/*name*/	 _WT("父窗口"), \
		/*explain*/	 _WT("父窗口"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyBase::CreateAsChildWindow ** 23 **/ \
		/*name*/	 _WT("x"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyBase::CreateAsChildWindow ** 24 **/ \
		/*name*/	 _WT("y"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyBase::CreateAsChildWindow ** 25 **/ \
		/*name*/	 _WT("宽度"), \
		/*explain*/	 _WT("窗口宽度"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyBase::CreateAsChildWindow ** 26 **/ \
		/*name*/	 _WT("高度"), \
		/*explain*/	 _WT("窗口高度"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyBase::CreateAsPopupWindow ** 27 **/ \
		/*name*/	 _WT("父窗口"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyBase::CreateAsPopupWindow ** 28 **/ \
		/*name*/	 _WT("标题"), \
		/*explain*/	 _WT("窗口标题"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_TEXT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyBase::SendURLRequest ** 29 **/ \
		/*name*/	 _WT("请求"), \
		/*explain*/	 _WT("发送请求"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 MAKELONG(24,0),  /*shrewd_ptr<ProxyRequest>*/ \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyBase::SendURLRequest ** 30 **/ \
		/*name*/	 _WT("隐身模式"), \
		/*explain*/	 _WT("是否使用隐身模式, 如果设置为真此请求将使用独立的会话环境, 否则使用全局的会话环境。"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_BOOL, \
		/*default*/	 0,\
		/*state*/	 AS_DEFAULT_VALUE_IS_EMPTY \
	},\
	{ /****** ProxyBase::SendURLRequest ** 31 **/ \
		/*name*/	 _WT("认证用户名"), \
		/*explain*/	 _WT("提供身份验证所需的凭据信息, 如果有的话。"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_TEXT, \
		/*default*/	 0,\
		/*state*/	 AS_DEFAULT_VALUE_IS_EMPTY \
	},\
	{ /****** ProxyBase::SendURLRequest ** 32 **/ \
		/*name*/	 _WT("认证密码"), \
		/*explain*/	 _WT("提供身份验证所需的凭据信息, 如果有的话。"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_TEXT, \
		/*default*/	 0,\
		/*state*/	 AS_DEFAULT_VALUE_IS_EMPTY \
	},\
	{ /****** ProxyBase::CreateServer ** 33 **/ \
		/*name*/	 _WT("监听地址"), \
		/*explain*/	 _WT("设置服务器监听的地址, 必须为有效的 IPv4 或 IPv6地址。"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_TEXT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyBase::CreateServer ** 34 **/ \
		/*name*/	 _WT("端口号"), \
		/*explain*/	 _WT("0-65535"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyBase::CreateServer ** 35 **/ \
		/*name*/	 _WT("连接数"), \
		/*explain*/	 _WT("最大挂起连接数。"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyBase::Awaking ** 36 **/ \
		/*name*/	 _WT("等待事件"), \
		/*explain*/	 _WT("等待的事件"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 MAKELONG(32,0),  /*shrewd_ptr<ProxyWaitableEvent>*/ \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyBase::TimedAwaking ** 37 **/ \
		/*name*/	 _WT("等待事件"), \
		/*explain*/	 _WT("等待的事件"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 MAKELONG(32,0),  /*shrewd_ptr<ProxyWaitableEvent>*/ \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyBase::TimedAwaking ** 38 **/ \
		/*name*/	 _WT("超时时间"), \
		/*explain*/	 _WT("等待的超时时间, 单位: 毫秒"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_FLOAT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyBase::CreateCollection ** 39 **/ \
		/*name*/	 _WT("使用全局缓存"), \
		/*explain*/	 _WT("是否使用全局的缓存设置以及cookies管理器。使用全局缓存将共享并持久化浏览器缓存与cookies数据。"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_BOOL, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\


//==========================================

#define DECL_DATA_TYPE_ProxyBase_CMDINFO(BeginIndex) \
	{ /*3*/ \
		/*ccname*/	_WT("进程初始化"),\
		/*egname*/	_WT("Initialize"), \
		/*explain*/	_WT("此函数应该在程序启动位置调用, 且应该于浏览器进程中执行, 执行此函数以初始化Chromium浏览器进程。初始化成功返回真, 失败返回假。"), \
		/*category*/	1, \
		/*state*/	NULL, \
		/*ret*/	SDT_BOOL, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	2, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+0] \
	},\
	{ /*4*/ \
		/*ccname*/	_WT("BASE64编码"),\
		/*egname*/	_WT("Base64Encode"), \
		/*explain*/	_WT("将字节集数据编码为Base64字符串。"), \
		/*category*/	1, \
		/*state*/	NULL, \
		/*ret*/	SDT_TEXT, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	2, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+2] \
	},\
	{ /*5*/ \
		/*ccname*/	_WT("BASE64解码"),\
		/*egname*/	_WT("Base64Decode"), \
		/*explain*/	_WT("将Base64字符串解码为字节集数据"), \
		/*category*/	1, \
		/*state*/	NULL, \
		/*ret*/	SDT_BIN, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	1, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+4] \
	},\
	{ /*6*/ \
		/*ccname*/	_WT("URI编码"),\
		/*egname*/	_WT("UriEncode"), \
		/*explain*/	_WT("对指定的字符串执行URI字符转义。"), \
		/*category*/	1, \
		/*state*/	NULL, \
		/*ret*/	SDT_TEXT, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	2, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+5] \
	},\
	{ /*7*/ \
		/*ccname*/	_WT("URI解码"),\
		/*egname*/	_WT("UriDecode"), \
		/*explain*/	_WT("还原指定字符串中的URI转义字符。"), \
		/*category*/	1, \
		/*state*/	NULL, \
		/*ret*/	SDT_TEXT, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	3, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+7] \
	},\
	{ /*8*/ \
		/*ccname*/	_WT("UTF8解码"),\
		/*egname*/	_WT("Utf8ToBytes"), \
		/*explain*/	_WT("将UTF-8编码字符串解码为多字节编码字符串。"), \
		/*category*/	1, \
		/*state*/	NULL, \
		/*ret*/	SDT_TEXT, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	2, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+10] \
	},\
	{ /*9*/ \
		/*ccname*/	_WT("UTF8编码"),\
		/*egname*/	_WT("BytesToUtf8"), \
		/*explain*/	_WT("将多字节编码字符串编码为UTF-8编码字符串。"), \
		/*category*/	1, \
		/*state*/	NULL, \
		/*ret*/	SDT_BIN, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	1, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+12] \
	},\
	{ /*10*/ \
		/*ccname*/	_WT("创建浏览器设置"),\
		/*egname*/	_WT("CreateBrowserSettings"), \
		/*explain*/	_WT("创建并返回一个新的浏览器设置类型实例对象。"), \
		/*category*/	1, \
		/*state*/	NULL, \
		/*ret*/	MAKELONG(5,0),  /*shrewd_ptr<ProxyBrowserSettings>*/ \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	0, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+13] \
	},\
	{ /*11*/ \
		/*ccname*/	_WT("创建命令行"),\
		/*egname*/	_WT("CreateCommandLine"), \
		/*explain*/	_WT("创建并返回一个新的命令行类型实例对象。"), \
		/*category*/	1, \
		/*state*/	NULL, \
		/*ret*/	MAKELONG(7,0),  /*shrewd_ptr<ProxyCommandLine>*/ \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	0, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+13] \
	},\
	{ /*12*/ \
		/*ccname*/	_WT("取全局命令行"),\
		/*egname*/	_WT("GetGlobalCommandLine"), \
		/*explain*/	_WT("从全局获取命令行类型实例对象。"), \
		/*category*/	1, \
		/*state*/	NULL, \
		/*ret*/	MAKELONG(7,0),  /*shrewd_ptr<ProxyCommandLine>*/ \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	0, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+13] \
	},\
	{ /*13*/ \
		/*ccname*/	_WT("取全局会话凭证管理器"),\
		/*egname*/	_WT("GetGlobalCookieManager"), \
		/*explain*/	_WT("从全局获取会话凭证管理器类型实例对象。"), \
		/*category*/	1, \
		/*state*/	NULL, \
		/*ret*/	MAKELONG(10,0),  /*shrewd_ptr<ProxyCookieManager>*/ \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	0, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+13] \
	},\
	{ /*14*/ \
		/*ccname*/	_WT("创建字典值"),\
		/*egname*/	_WT("CreateDictionartyValue"), \
		/*explain*/	_WT("创建并返回一个新的字典类型实例对象。"), \
		/*category*/	1, \
		/*state*/	NULL, \
		/*ret*/	MAKELONG(11,0),  /*shrewd_ptr<ProxyDictionaryValue>*/ \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	0, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+13] \
	},\
	{ /*15*/ \
		/*ccname*/	_WT("创建列表值"),\
		/*egname*/	_WT("CreateListValue"), \
		/*explain*/	_WT("创建并返回一个新的列表类型实例对象。"), \
		/*category*/	1, \
		/*state*/	 CT_ALLOW_APPEND_NEW_ARG, \
		/*ret*/	MAKELONG(20,0),  /*shrewd_ptr<ProxyListValue>*/ \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	1, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+13] \
	},\
	{ /*16*/ \
		/*ccname*/	_WT("创建提交元素"),\
		/*egname*/	_WT("CreatePostDataElement"), \
		/*explain*/	_WT("创建一个空的提交数据元素(Post Data Element)。"), \
		/*category*/	1, \
		/*state*/	NULL, \
		/*ret*/	MAKELONG(22,0),  /*shrewd_ptr<ProxyPostDataElement>*/ \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	0, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+14] \
	},\
	{ /*17*/ \
		/*ccname*/	_WT("创建文件提交元素"),\
		/*egname*/	_WT("CreatePostDataElementWithFile"), \
		/*explain*/	_WT("创建一个代表文件的提交数据元素(Post Data Element)。"), \
		/*category*/	1, \
		/*state*/	NULL, \
		/*ret*/	MAKELONG(22,0),  /*shrewd_ptr<ProxyPostDataElement>*/ \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	1, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+14] \
	},\
	{ /*18*/ \
		/*ccname*/	_WT("创建字节集提交元素"),\
		/*egname*/	_WT("CreatePostDataElementWithData"), \
		/*explain*/	_WT("创建一个代表字节集的提交数据元素(Post Data Element)。"), \
		/*category*/	1, \
		/*state*/	NULL, \
		/*ret*/	MAKELONG(22,0),  /*shrewd_ptr<ProxyPostDataElement>*/ \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	1, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+15] \
	},\
	{ /*19*/ \
		/*ccname*/	_WT("创建请求"),\
		/*egname*/	_WT("CreateRequest"), \
		/*explain*/	_WT("创建并返回一个新的请求类型实例对象。"), \
		/*category*/	1, \
		/*state*/	NULL, \
		/*ret*/	MAKELONG(24,0),  /*shrewd_ptr<ProxyRequest>*/ \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	5, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+16] \
	},\
	{ /*20*/ \
		/*ccname*/	_WT("创建响应"),\
		/*egname*/	_WT("CreateResponse"), \
		/*explain*/	_WT("创建并返回一个新的响应类型实例对象。"), \
		/*category*/	1, \
		/*state*/	NULL, \
		/*ret*/	MAKELONG(25,0),  /*shrewd_ptr<ProxyResponse>*/ \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	0, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+21] \
	},\
	{ /*21*/ \
		/*ccname*/	_WT("创建初始化设置"),\
		/*egname*/	_WT("CreateSetting"), \
		/*explain*/	_WT("创建并返回一个新的初始化设置类型实例对象。"), \
		/*category*/	1, \
		/*state*/	NULL, \
		/*ret*/	MAKELONG(29,0),  /*shrewd_ptr<ProxySettings>*/ \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	0, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+21] \
	},\
	{ /*22*/ \
		/*ccname*/	_WT("创建通用值"),\
		/*egname*/	_WT("CreateValue"), \
		/*explain*/	_WT("创建并返回一个新的通用类型实例对象。"), \
		/*category*/	1, \
		/*state*/	NULL, \
		/*ret*/	MAKELONG(31,0),  /*shrewd_ptr<ProxyValue>*/ \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	1, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+21] \
	},\
	{ /*23*/ \
		/*ccname*/	_WT("创建窗口设置"),\
		/*egname*/	_WT("CreateWindowInfo"), \
		/*explain*/	_WT("创建并返回一个新的窗口设置类型实例对象。"), \
		/*category*/	1, \
		/*state*/	NULL, \
		/*ret*/	MAKELONG(34,0),  /*shrewd_ptr<ProxyWindowInfo>*/ \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	0, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+22] \
	},\
	{ /*24*/ \
		/*ccname*/	_WT("创建子窗口设置"),\
		/*egname*/	_WT("CreateAsChildWindow"), \
		/*explain*/	_WT("创建一个窗口设置类型实例, 并将其初始化为子窗口模式。"), \
		/*category*/	1, \
		/*state*/	NULL, \
		/*ret*/	MAKELONG(34,0),  /*shrewd_ptr<ProxyWindowInfo>*/ \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	5, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+22] \
	},\
	{ /*25*/ \
		/*ccname*/	_WT("创建弹出窗口设置"),\
		/*egname*/	_WT("CreateAsPopupWindow"), \
		/*explain*/	_WT("创建一个窗口设置类型实例, 并将其初始化为弹出窗口模式。"), \
		/*category*/	1, \
		/*state*/	NULL, \
		/*ret*/	MAKELONG(34,0),  /*shrewd_ptr<ProxyWindowInfo>*/ \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	2, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+27] \
	},\
	{ /*26*/ \
		/*ccname*/	_WT("发送URL请求"),\
		/*egname*/	_WT("SendURLRequest"), \
		/*explain*/	_WT("发起HTTP请求。"), \
		/*category*/	1, \
		/*state*/	NULL, \
		/*ret*/	MAKELONG(30,0),  /*shrewd_ptr<ProxyURLRequest>*/ \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	4, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+29] \
	},\
	{ /*27*/ \
		/*ccname*/	_WT("创建服务器"),\
		/*egname*/	_WT("CreateServer"), \
		/*explain*/	_WT("创建一个新的HTTP服务器。"), \
		/*category*/	1, \
		/*state*/	NULL, \
		/*ret*/	_SDT_NULL, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	3, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+33] \
	},\
	{ /*28*/ \
		/*ccname*/	_WT("创建网页套接字"),\
		/*egname*/	_WT("CreateWebSocket"), \
		/*explain*/	_WT("创建一个新的Websocket套接字。"), \
		/*category*/	1, \
		/*state*/	NULL, \
		/*ret*/	MAKELONG(33,0),  /*shrewd_ptr<ProxyWebSocket>*/ \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	0, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+36] \
	},\
	{ /*29*/ \
		/*ccname*/	_WT("创建等待事件"),\
		/*egname*/	_WT("CreateWaitableEvent"), \
		/*explain*/	_WT("创建一个新的等待事件。 等待事件通常用于线程同步, 它允许一个线程等待另一个线程完成某些事件后在继续工作。"), \
		/*category*/	1, \
		/*state*/	NULL, \
		/*ret*/	MAKELONG(32,0),  /*shrewd_ptr<ProxyWaitableEvent>*/ \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	0, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+36] \
	},\
	{ /*30*/ \
		/*ccname*/	_WT("等待唤醒"),\
		/*egname*/	_WT("Awaking"), \
		/*explain*/	_WT("挂起一个等待事件直到被置为有信号状态。本方法加入了消息队列的处理不会阻塞UI线程。"), \
		/*category*/	1, \
		/*state*/	NULL, \
		/*ret*/	_SDT_NULL, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	1, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+36] \
	},\
	{ /*31*/ \
		/*ccname*/	_WT("等待唤醒2"),\
		/*egname*/	_WT("TimedAwaking"), \
		/*explain*/	_WT("挂起一个等待事件直到被置为有信号状态或者超过事时间。本方法加入了消息队列的处理不会阻塞UI线程。返回真表示等待事件已授信, 返回假表示已超过等待时间。"), \
		/*category*/	1, \
		/*state*/	NULL, \
		/*ret*/	SDT_BOOL, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	2, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+37] \
	},\
	{ /*32*/ \
		/*ccname*/	_WT("创建菜单"),\
		/*egname*/	_WT("CreateMenu"), \
		/*explain*/	_WT("创建一个新的菜单。"), \
		/*category*/	1, \
		/*state*/	NULL, \
		/*ret*/	MAKELONG(21,0),  /*shrewd_ptr<ProxyMenuModel>*/ \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	0, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+39] \
	},\
	{ /*33*/ \
		/*ccname*/	_WT("创建网页驱动器"),\
		/*egname*/	_WT("CreateCollection"), \
		/*explain*/	_WT("创建一个新的网页驱动器。"), \
		/*category*/	1, \
		/*state*/	NULL, \
		/*ret*/	MAKELONG(6,0),  /*shrewd_ptr<ProxyCollection>*/ \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	1, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+39] \
	},\


//==========================================

#define DECL_DATA_TYPE_ProxyBase_FUN_NAMES \
	EDITIONS("ProxyBase_Initialize"),\
	EDITIONS("ProxyBase_Base64Encode"),\
	EDITIONS("ProxyBase_Base64Decode"),\
	EDITIONS("ProxyBase_UriEncode"),\
	EDITIONS("ProxyBase_UriDecode"),\
	EDITIONS("ProxyBase_Utf8ToBytes"),\
	EDITIONS("ProxyBase_BytesToUtf8"),\
	EDITIONS("ProxyBase_CreateBrowserSettings"),\
	EDITIONS("ProxyBase_CreateCommandLine"),\
	EDITIONS("ProxyBase_GetGlobalCommandLine"),\
	EDITIONS("ProxyBase_GetGlobalCookieManager"),\
	EDITIONS("ProxyBase_CreateDictionartyValue"),\
	EDITIONS("ProxyBase_CreateListValue"),\
	EDITIONS("ProxyBase_CreatePostDataElement"),\
	EDITIONS("ProxyBase_CreatePostDataElementWithFile"),\
	EDITIONS("ProxyBase_CreatePostDataElementWithData"),\
	EDITIONS("ProxyBase_CreateRequest"),\
	EDITIONS("ProxyBase_CreateResponse"),\
	EDITIONS("ProxyBase_CreateSetting"),\
	EDITIONS("ProxyBase_CreateValue"),\
	EDITIONS("ProxyBase_CreateWindowInfo"),\
	EDITIONS("ProxyBase_CreateAsChildWindow"),\
	EDITIONS("ProxyBase_CreateAsPopupWindow"),\
	EDITIONS("ProxyBase_SendURLRequest"),\
	EDITIONS("ProxyBase_CreateServer"),\
	EDITIONS("ProxyBase_CreateWebSocket"),\
	EDITIONS("ProxyBase_CreateWaitableEvent"),\
	EDITIONS("ProxyBase_Awaking"),\
	EDITIONS("ProxyBase_TimedAwaking"),\
	EDITIONS("ProxyBase_CreateMenu"),\
	EDITIONS("ProxyBase_CreateCollection"),\


//==========================================

#define DECL_DATA_TYPE_ProxyBase_FUN_CALLS \
	EDITIONF(ProxyBase_Initialize),\
	EDITIONF(ProxyBase_Base64Encode),\
	EDITIONF(ProxyBase_Base64Decode),\
	EDITIONF(ProxyBase_UriEncode),\
	EDITIONF(ProxyBase_UriDecode),\
	EDITIONF(ProxyBase_Utf8ToBytes),\
	EDITIONF(ProxyBase_BytesToUtf8),\
	EDITIONF(ProxyBase_CreateBrowserSettings),\
	EDITIONF(ProxyBase_CreateCommandLine),\
	EDITIONF(ProxyBase_GetGlobalCommandLine),\
	EDITIONF(ProxyBase_GetGlobalCookieManager),\
	EDITIONF(ProxyBase_CreateDictionartyValue),\
	EDITIONF(ProxyBase_CreateListValue),\
	EDITIONF(ProxyBase_CreatePostDataElement),\
	EDITIONF(ProxyBase_CreatePostDataElementWithFile),\
	EDITIONF(ProxyBase_CreatePostDataElementWithData),\
	EDITIONF(ProxyBase_CreateRequest),\
	EDITIONF(ProxyBase_CreateResponse),\
	EDITIONF(ProxyBase_CreateSetting),\
	EDITIONF(ProxyBase_CreateValue),\
	EDITIONF(ProxyBase_CreateWindowInfo),\
	EDITIONF(ProxyBase_CreateAsChildWindow),\
	EDITIONF(ProxyBase_CreateAsPopupWindow),\
	EDITIONF(ProxyBase_SendURLRequest),\
	EDITIONF(ProxyBase_CreateServer),\
	EDITIONF(ProxyBase_CreateWebSocket),\
	EDITIONF(ProxyBase_CreateWaitableEvent),\
	EDITIONF(ProxyBase_Awaking),\
	EDITIONF(ProxyBase_TimedAwaking),\
	EDITIONF(ProxyBase_CreateMenu),\
	EDITIONF(ProxyBase_CreateCollection),\


//==========================================

extern "C"
void EDITIONF(ProxyBase_Initialize) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyBase_Base64Encode) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyBase_Base64Decode) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyBase_UriEncode) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyBase_UriDecode) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyBase_Utf8ToBytes) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyBase_BytesToUtf8) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyBase_CreateBrowserSettings) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyBase_CreateCommandLine) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyBase_GetGlobalCommandLine) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyBase_GetGlobalCookieManager) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyBase_CreateDictionartyValue) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyBase_CreateListValue) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyBase_CreatePostDataElement) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyBase_CreatePostDataElementWithFile) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyBase_CreatePostDataElementWithData) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyBase_CreateRequest) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyBase_CreateResponse) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyBase_CreateSetting) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyBase_CreateValue) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyBase_CreateWindowInfo) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyBase_CreateAsChildWindow) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyBase_CreateAsPopupWindow) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyBase_SendURLRequest) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyBase_CreateServer) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyBase_CreateWebSocket) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyBase_CreateWaitableEvent) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyBase_Awaking) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyBase_TimedAwaking) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyBase_CreateMenu) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyBase_CreateCollection) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);


//==========================================

