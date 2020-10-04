#pragma once

#include "stdafx.h"
#include "lib2.h"


#define DECL_DATA_TYPE_ProxyBrowserSettings \
	{ /*6*/ \
		/*m_szName*/		 _WT("Chromium浏览器设置"), \
		/*m_szEgName*/		 _WT("ProxyBrowserSettings"), \
		/*m_szExplain*/		 _WT("提供浏览器初始化设置。"), \
		/*m_nCmdCount*/		 36, \
		/*m_pnCmdsIndex*/		 s_nProxyBrowserSettingsElementCmdIndex, \
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

#define DECL_DATA_TYPE_ProxyBrowserSettings_ARGINFO \
	{ /****** ProxyBrowserSettings::SetWindowlessFrameRate ** 0 **/ \
		/*name*/	 _WT("windowless_frame_rate"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxyBrowserSettings::SetStandardFontFamily ** 1 **/ \
		/*name*/	 _WT("字体名称"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_TEXT, \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxyBrowserSettings::SetFixedFontFamily ** 2 **/ \
		/*name*/	 _WT("字体名称"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_TEXT, \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxyBrowserSettings::SetSerifFontFamily ** 3 **/ \
		/*name*/	 _WT("字体名称"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_TEXT, \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxyBrowserSettings::SetSansSerifFontFamily ** 4 **/ \
		/*name*/	 _WT("字体名称"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_TEXT, \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxyBrowserSettings::SetCursiveFontFamily ** 5 **/ \
		/*name*/	 _WT("字体名称"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_TEXT, \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxyBrowserSettings::SetFantasyFontFamily ** 6 **/ \
		/*name*/	 _WT("字体名称"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_TEXT, \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxyBrowserSettings::SetDefaultFontSize ** 7 **/ \
		/*name*/	 _WT("字体大小"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxyBrowserSettings::SetDefaultFixedFontSize ** 8 **/ \
		/*name*/	 _WT("字体大小"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxyBrowserSettings::SetMinimumFontSize ** 9 **/ \
		/*name*/	 _WT("最小大小"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxyBrowserSettings::SetMinimumLogicalFontSize ** 10 **/ \
		/*name*/	 _WT("最小合理大小"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxyBrowserSettings::SetDefaultEncoding ** 11 **/ \
		/*name*/	 _WT("默认编码"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_TEXT, \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxyBrowserSettings::SetRemoteFonts ** 12 **/ \
		/*name*/	 _WT("开关"), \
		/*explain*/	 _WT("配置状态开关定义值为枚举常量: #状态开关.*"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxyBrowserSettings::SetJavascript ** 13 **/ \
		/*name*/	 _WT("开关"), \
		/*explain*/	 _WT("配置状态开关定义值为枚举常量: #状态开关.*"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxyBrowserSettings::SetJavascriptCloseWindows ** 14 **/ \
		/*name*/	 _WT("开关"), \
		/*explain*/	 _WT("配置状态开关定义值为枚举常量: #状态开关.*"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxyBrowserSettings::SetJavascriptAccessClipboard ** 15 **/ \
		/*name*/	 _WT("开关"), \
		/*explain*/	 _WT("配置状态开关定义值为枚举常量: #状态开关.*"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxyBrowserSettings::SetJavascriptDomPaste ** 16 **/ \
		/*name*/	 _WT("开关"), \
		/*explain*/	 _WT("配置状态开关定义值为枚举常量: #状态开关.*"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxyBrowserSettings::SetPlugins ** 17 **/ \
		/*name*/	 _WT("开关"), \
		/*explain*/	 _WT("配置状态开关定义值为枚举常量: #状态开关.*"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxyBrowserSettings::SetUniversalAccessFromFileUrls ** 18 **/ \
		/*name*/	 _WT("开关"), \
		/*explain*/	 _WT("配置状态开关定义值为枚举常量: #状态开关.*"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxyBrowserSettings::SetFileAccessFromFileUrls ** 19 **/ \
		/*name*/	 _WT("开关"), \
		/*explain*/	 _WT("配置状态开关定义值为枚举常量: #状态开关.*"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxyBrowserSettings::SetWebSecurity ** 20 **/ \
		/*name*/	 _WT("开关"), \
		/*explain*/	 _WT("配置状态开关定义值为枚举常量: #状态开关.*"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxyBrowserSettings::SetImageLoading ** 21 **/ \
		/*name*/	 _WT("开关"), \
		/*explain*/	 _WT("配置状态开关定义值为枚举常量: #状态开关.*"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxyBrowserSettings::SetImageShrinkStandaloneToFit ** 22 **/ \
		/*name*/	 _WT("开关"), \
		/*explain*/	 _WT("配置状态开关定义值为枚举常量: #状态开关.*"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxyBrowserSettings::SetTextAreaResize ** 23 **/ \
		/*name*/	 _WT("开关"), \
		/*explain*/	 _WT("配置状态开关定义值为枚举常量: #状态开关.*"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxyBrowserSettings::SetTabToLinks ** 24 **/ \
		/*name*/	 _WT("开关"), \
		/*explain*/	 _WT("配置状态开关定义值为枚举常量: #状态开关.*"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxyBrowserSettings::SetLocalStorage ** 25 **/ \
		/*name*/	 _WT("开关"), \
		/*explain*/	 _WT("配置状态开关定义值为枚举常量: #状态开关.*"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxyBrowserSettings::SetDatabases ** 26 **/ \
		/*name*/	 _WT("开关"), \
		/*explain*/	 _WT("配置状态开关定义值为枚举常量: #状态开关.*"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxyBrowserSettings::SetApplicationCache ** 27 **/ \
		/*name*/	 _WT("开关"), \
		/*explain*/	 _WT("配置状态开关定义值为枚举常量: #状态开关.*"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxyBrowserSettings::SetWebGL ** 28 **/ \
		/*name*/	 _WT("开关"), \
		/*explain*/	 _WT("配置状态开关定义值为枚举常量: #状态开关.*"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxyBrowserSettings::SetBackgroundColor ** 29 **/ \
		/*name*/	 _WT("背景颜色"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxyBrowserSettings::SetAcceptLanguageList ** 30 **/ \
		/*name*/	 _WT("值"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_TEXT, \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\


//==========================================

#define DECL_DATA_TYPE_ProxyBrowserSettings_CMDINFO(BeginIndex) \
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
		/*ret*/	MAKELONG(7,0),  /*shrewd_ptr<ProxyBrowserSettings>*/ \
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
		/*ccname*/	_WT("SetWindowlessFrameRate"),\
		/*egname*/	_WT("SetWindowlessFrameRate"), \
		/*explain*/	_WT(""), \
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
	{ /*6*/ \
		/*ccname*/	_WT("设置标准字体"),\
		/*egname*/	_WT("SetStandardFontFamily"), \
		/*explain*/	_WT(""), \
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
	{ /*7*/ \
		/*ccname*/	_WT("设置等宽字体"),\
		/*egname*/	_WT("SetFixedFontFamily"), \
		/*explain*/	_WT(""), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	_SDT_NULL, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	1, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+2] \
	},\
	{ /*8*/ \
		/*ccname*/	_WT("设置衬线字体"),\
		/*egname*/	_WT("SetSerifFontFamily"), \
		/*explain*/	_WT(""), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	_SDT_NULL, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	1, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+3] \
	},\
	{ /*9*/ \
		/*ccname*/	_WT("设置无衬线字体"),\
		/*egname*/	_WT("SetSansSerifFontFamily"), \
		/*explain*/	_WT(""), \
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
	{ /*10*/ \
		/*ccname*/	_WT("设置手写字体"),\
		/*egname*/	_WT("SetCursiveFontFamily"), \
		/*explain*/	_WT(""), \
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
	{ /*11*/ \
		/*ccname*/	_WT("设置艺术字体"),\
		/*egname*/	_WT("SetFantasyFontFamily"), \
		/*explain*/	_WT(""), \
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
	{ /*12*/ \
		/*ccname*/	_WT("设置默认字体大小"),\
		/*egname*/	_WT("SetDefaultFontSize"), \
		/*explain*/	_WT(""), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	_SDT_NULL, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	1, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+7] \
	},\
	{ /*13*/ \
		/*ccname*/	_WT("设置默认等宽字体大小"),\
		/*egname*/	_WT("SetDefaultFixedFontSize"), \
		/*explain*/	_WT(""), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	_SDT_NULL, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	1, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+8] \
	},\
	{ /*14*/ \
		/*ccname*/	_WT("设置字体最小大小"),\
		/*egname*/	_WT("SetMinimumFontSize"), \
		/*explain*/	_WT(""), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	_SDT_NULL, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	1, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+9] \
	},\
	{ /*15*/ \
		/*ccname*/	_WT("设置字体最小合理大小"),\
		/*egname*/	_WT("SetMinimumLogicalFontSize"), \
		/*explain*/	_WT(""), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	_SDT_NULL, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	1, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+10] \
	},\
	{ /*16*/ \
		/*ccname*/	_WT("设置页面缺省编码"),\
		/*egname*/	_WT("SetDefaultEncoding"), \
		/*explain*/	_WT("默认设置为: \"ISO-8859-1\", 也可以使用\"default-encoding\"命令行开关进行配置。"), \
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
	{ /*17*/ \
		/*ccname*/	_WT("设置是否允许加载远程字体源"),\
		/*egname*/	_WT("SetRemoteFonts"), \
		/*explain*/	_WT(""), \
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
	{ /*18*/ \
		/*ccname*/	_WT("设置是否允许执行脚本"),\
		/*egname*/	_WT("SetJavascript"), \
		/*explain*/	_WT("设置是否允许执行Javascript。也可以使用命令行开关\"disable-javascript\"进行配置。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	_SDT_NULL, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	1, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+13] \
	},\
	{ /*19*/ \
		/*ccname*/	_WT("设置是否允许脚本关闭窗口"),\
		/*egname*/	_WT("SetJavascriptCloseWindows"), \
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
	{ /*20*/ \
		/*ccname*/	_WT("设置是否允许脚本访问剪辑版"),\
		/*egname*/	_WT("SetJavascriptAccessClipboard"), \
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
	{ /*21*/ \
		/*ccname*/	_WT("设置是否允许脚本粘贴DOM"),\
		/*egname*/	_WT("SetJavascriptDomPaste"), \
		/*explain*/	_WT(""), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	_SDT_NULL, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	1, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+16] \
	},\
	{ /*22*/ \
		/*ccname*/	_WT("设置是否允许加载插件"),\
		/*egname*/	_WT("SetPlugins"), \
		/*explain*/	_WT(""), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	_SDT_NULL, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	1, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+17] \
	},\
	{ /*23*/ \
		/*ccname*/	_WT("SetUniversalAccessFromFileUrls"),\
		/*egname*/	_WT("SetUniversalAccessFromFileUrls"), \
		/*explain*/	_WT(""), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	_SDT_NULL, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	1, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+18] \
	},\
	{ /*24*/ \
		/*ccname*/	_WT("SetFileAccessFromFileUrls"),\
		/*egname*/	_WT("SetFileAccessFromFileUrls"), \
		/*explain*/	_WT(""), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	_SDT_NULL, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	1, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+19] \
	},\
	{ /*25*/ \
		/*ccname*/	_WT("SetWebSecurity"),\
		/*egname*/	_WT("SetWebSecurity"), \
		/*explain*/	_WT(""), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	_SDT_NULL, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	1, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+20] \
	},\
	{ /*26*/ \
		/*ccname*/	_WT("SetImageLoading"),\
		/*egname*/	_WT("SetImageLoading"), \
		/*explain*/	_WT(""), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	_SDT_NULL, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	1, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+21] \
	},\
	{ /*27*/ \
		/*ccname*/	_WT("SetImageShrinkStandaloneToFit"),\
		/*egname*/	_WT("SetImageShrinkStandaloneToFit"), \
		/*explain*/	_WT(""), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	_SDT_NULL, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	1, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+22] \
	},\
	{ /*28*/ \
		/*ccname*/	_WT("SetTextAreaResize"),\
		/*egname*/	_WT("SetTextAreaResize"), \
		/*explain*/	_WT(""), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	_SDT_NULL, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	1, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+23] \
	},\
	{ /*29*/ \
		/*ccname*/	_WT("SetTabToLinks"),\
		/*egname*/	_WT("SetTabToLinks"), \
		/*explain*/	_WT(""), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	_SDT_NULL, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	1, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+24] \
	},\
	{ /*30*/ \
		/*ccname*/	_WT("设置是否允许使用LocalStorage"),\
		/*egname*/	_WT("SetLocalStorage"), \
		/*explain*/	_WT(""), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	_SDT_NULL, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	1, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+25] \
	},\
	{ /*31*/ \
		/*ccname*/	_WT("设置是否允许使用IndexedDB"),\
		/*egname*/	_WT("SetDatabases"), \
		/*explain*/	_WT(""), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	_SDT_NULL, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	1, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+26] \
	},\
	{ /*32*/ \
		/*ccname*/	_WT("设置是否允许ApplicationCache"),\
		/*egname*/	_WT("SetApplicationCache"), \
		/*explain*/	_WT(""), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	_SDT_NULL, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	1, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+27] \
	},\
	{ /*33*/ \
		/*ccname*/	_WT("设置是否允许使用WebGL"),\
		/*egname*/	_WT("SetWebGL"), \
		/*explain*/	_WT(""), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	_SDT_NULL, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	1, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+28] \
	},\
	{ /*34*/ \
		/*ccname*/	_WT("设置背景颜色"),\
		/*egname*/	_WT("SetBackgroundColor"), \
		/*explain*/	_WT("设置在加载文档之前或加载没有背景色的文档时浏览器使用的背景色。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	_SDT_NULL, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	1, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+29] \
	},\
	{ /*35*/ \
		/*ccname*/	_WT("设置HTTP接收语言字符串"),\
		/*egname*/	_WT("SetAcceptLanguageList"), \
		/*explain*/	_WT("设置全局的HTTP接收语言字符串,以逗号分隔的语言代码字符串数组,不可以使用空格, 这些字符串值将在\"Accept-Language\" HTTP标头中使用。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	_SDT_NULL, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	1, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+30] \
	},\


//==========================================

#define DECL_DATA_TYPE_ProxyBrowserSettings_FUN_NAMES \
	EDITIONS("ProxyBrowserSettings_Constructor"),\
	EDITIONS("ProxyBrowserSettings_Destructor"),\
	EDITIONS("ProxyBrowserSettings_CopyConstructor"),\
	EDITIONS("ProxyBrowserSettings_Create"),\
	EDITIONS("ProxyBrowserSettings_IsValid"),\
	EDITIONS("ProxyBrowserSettings_SetWindowlessFrameRate"),\
	EDITIONS("ProxyBrowserSettings_SetStandardFontFamily"),\
	EDITIONS("ProxyBrowserSettings_SetFixedFontFamily"),\
	EDITIONS("ProxyBrowserSettings_SetSerifFontFamily"),\
	EDITIONS("ProxyBrowserSettings_SetSansSerifFontFamily"),\
	EDITIONS("ProxyBrowserSettings_SetCursiveFontFamily"),\
	EDITIONS("ProxyBrowserSettings_SetFantasyFontFamily"),\
	EDITIONS("ProxyBrowserSettings_SetDefaultFontSize"),\
	EDITIONS("ProxyBrowserSettings_SetDefaultFixedFontSize"),\
	EDITIONS("ProxyBrowserSettings_SetMinimumFontSize"),\
	EDITIONS("ProxyBrowserSettings_SetMinimumLogicalFontSize"),\
	EDITIONS("ProxyBrowserSettings_SetDefaultEncoding"),\
	EDITIONS("ProxyBrowserSettings_SetRemoteFonts"),\
	EDITIONS("ProxyBrowserSettings_SetJavascript"),\
	EDITIONS("ProxyBrowserSettings_SetJavascriptCloseWindows"),\
	EDITIONS("ProxyBrowserSettings_SetJavascriptAccessClipboard"),\
	EDITIONS("ProxyBrowserSettings_SetJavascriptDomPaste"),\
	EDITIONS("ProxyBrowserSettings_SetPlugins"),\
	EDITIONS("ProxyBrowserSettings_SetUniversalAccessFromFileUrls"),\
	EDITIONS("ProxyBrowserSettings_SetFileAccessFromFileUrls"),\
	EDITIONS("ProxyBrowserSettings_SetWebSecurity"),\
	EDITIONS("ProxyBrowserSettings_SetImageLoading"),\
	EDITIONS("ProxyBrowserSettings_SetImageShrinkStandaloneToFit"),\
	EDITIONS("ProxyBrowserSettings_SetTextAreaResize"),\
	EDITIONS("ProxyBrowserSettings_SetTabToLinks"),\
	EDITIONS("ProxyBrowserSettings_SetLocalStorage"),\
	EDITIONS("ProxyBrowserSettings_SetDatabases"),\
	EDITIONS("ProxyBrowserSettings_SetApplicationCache"),\
	EDITIONS("ProxyBrowserSettings_SetWebGL"),\
	EDITIONS("ProxyBrowserSettings_SetBackgroundColor"),\
	EDITIONS("ProxyBrowserSettings_SetAcceptLanguageList"),\


//==========================================

#define DECL_DATA_TYPE_ProxyBrowserSettings_FUN_CALLS \
	EDITIONF(ProxyBrowserSettings_Constructor),\
	EDITIONF(ProxyBrowserSettings_Destructor),\
	EDITIONF(ProxyBrowserSettings_CopyConstructor),\
	EDITIONF(ProxyBrowserSettings_Create),\
	EDITIONF(ProxyBrowserSettings_IsValid),\
	EDITIONF(ProxyBrowserSettings_SetWindowlessFrameRate),\
	EDITIONF(ProxyBrowserSettings_SetStandardFontFamily),\
	EDITIONF(ProxyBrowserSettings_SetFixedFontFamily),\
	EDITIONF(ProxyBrowserSettings_SetSerifFontFamily),\
	EDITIONF(ProxyBrowserSettings_SetSansSerifFontFamily),\
	EDITIONF(ProxyBrowserSettings_SetCursiveFontFamily),\
	EDITIONF(ProxyBrowserSettings_SetFantasyFontFamily),\
	EDITIONF(ProxyBrowserSettings_SetDefaultFontSize),\
	EDITIONF(ProxyBrowserSettings_SetDefaultFixedFontSize),\
	EDITIONF(ProxyBrowserSettings_SetMinimumFontSize),\
	EDITIONF(ProxyBrowserSettings_SetMinimumLogicalFontSize),\
	EDITIONF(ProxyBrowserSettings_SetDefaultEncoding),\
	EDITIONF(ProxyBrowserSettings_SetRemoteFonts),\
	EDITIONF(ProxyBrowserSettings_SetJavascript),\
	EDITIONF(ProxyBrowserSettings_SetJavascriptCloseWindows),\
	EDITIONF(ProxyBrowserSettings_SetJavascriptAccessClipboard),\
	EDITIONF(ProxyBrowserSettings_SetJavascriptDomPaste),\
	EDITIONF(ProxyBrowserSettings_SetPlugins),\
	EDITIONF(ProxyBrowserSettings_SetUniversalAccessFromFileUrls),\
	EDITIONF(ProxyBrowserSettings_SetFileAccessFromFileUrls),\
	EDITIONF(ProxyBrowserSettings_SetWebSecurity),\
	EDITIONF(ProxyBrowserSettings_SetImageLoading),\
	EDITIONF(ProxyBrowserSettings_SetImageShrinkStandaloneToFit),\
	EDITIONF(ProxyBrowserSettings_SetTextAreaResize),\
	EDITIONF(ProxyBrowserSettings_SetTabToLinks),\
	EDITIONF(ProxyBrowserSettings_SetLocalStorage),\
	EDITIONF(ProxyBrowserSettings_SetDatabases),\
	EDITIONF(ProxyBrowserSettings_SetApplicationCache),\
	EDITIONF(ProxyBrowserSettings_SetWebGL),\
	EDITIONF(ProxyBrowserSettings_SetBackgroundColor),\
	EDITIONF(ProxyBrowserSettings_SetAcceptLanguageList),\


//==========================================

extern "C"
void EDITIONF(ProxyBrowserSettings_Constructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyBrowserSettings_Destructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyBrowserSettings_CopyConstructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyBrowserSettings_Create) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyBrowserSettings_IsValid) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyBrowserSettings_SetWindowlessFrameRate) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyBrowserSettings_SetStandardFontFamily) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyBrowserSettings_SetFixedFontFamily) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyBrowserSettings_SetSerifFontFamily) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyBrowserSettings_SetSansSerifFontFamily) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyBrowserSettings_SetCursiveFontFamily) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyBrowserSettings_SetFantasyFontFamily) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyBrowserSettings_SetDefaultFontSize) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyBrowserSettings_SetDefaultFixedFontSize) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyBrowserSettings_SetMinimumFontSize) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyBrowserSettings_SetMinimumLogicalFontSize) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyBrowserSettings_SetDefaultEncoding) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyBrowserSettings_SetRemoteFonts) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyBrowserSettings_SetJavascript) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyBrowserSettings_SetJavascriptCloseWindows) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyBrowserSettings_SetJavascriptAccessClipboard) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyBrowserSettings_SetJavascriptDomPaste) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyBrowserSettings_SetPlugins) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyBrowserSettings_SetUniversalAccessFromFileUrls) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyBrowserSettings_SetFileAccessFromFileUrls) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyBrowserSettings_SetWebSecurity) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyBrowserSettings_SetImageLoading) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyBrowserSettings_SetImageShrinkStandaloneToFit) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyBrowserSettings_SetTextAreaResize) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyBrowserSettings_SetTabToLinks) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyBrowserSettings_SetLocalStorage) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyBrowserSettings_SetDatabases) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyBrowserSettings_SetApplicationCache) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyBrowserSettings_SetWebGL) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyBrowserSettings_SetBackgroundColor) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyBrowserSettings_SetAcceptLanguageList) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);


//==========================================

