#pragma once

#include "stdafx.h"
#include "lib2.h"


#define DECL_DATA_TYPE_ProxyBrowserSettings \
	{ /*5*/ \
		/*m_szName*/		 _WT("水星浏览器设置"), \
		/*m_szEgName*/		 _WT("ProxyBrowserSettings"), \
		/*m_szExplain*/		 _WT("提供浏览器初始化设置。"), \
		/*m_nCmdCount*/		 34, \
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
	{ /****** ProxyBrowserSettings::SetStandardFontFamily ** 0 **/ \
		/*name*/	 _WT("字体名称"), \
		/*explain*/	 _WT("设置字体名称"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_TEXT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyBrowserSettings::SetFixedFontFamily ** 1 **/ \
		/*name*/	 _WT("字体名称"), \
		/*explain*/	 _WT("设置字体名称"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_TEXT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyBrowserSettings::SetSerifFontFamily ** 2 **/ \
		/*name*/	 _WT("字体名称"), \
		/*explain*/	 _WT("设置字体名称"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_TEXT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyBrowserSettings::SetSansSerifFontFamily ** 3 **/ \
		/*name*/	 _WT("字体名称"), \
		/*explain*/	 _WT("设置字体名称"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_TEXT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyBrowserSettings::SetCursiveFontFamily ** 4 **/ \
		/*name*/	 _WT("字体名称"), \
		/*explain*/	 _WT("设置字体名称"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_TEXT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyBrowserSettings::SetFantasyFontFamily ** 5 **/ \
		/*name*/	 _WT("字体名称"), \
		/*explain*/	 _WT("设置字体名称"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_TEXT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyBrowserSettings::SetDefaultFontSize ** 6 **/ \
		/*name*/	 _WT("字体大小"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyBrowserSettings::SetDefaultFixedFontSize ** 7 **/ \
		/*name*/	 _WT("字体大小"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyBrowserSettings::SetMinimumFontSize ** 8 **/ \
		/*name*/	 _WT("最小大小"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyBrowserSettings::SetMinimumLogicalFontSize ** 9 **/ \
		/*name*/	 _WT("最小合理大小"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyBrowserSettings::SetDefaultEncoding ** 10 **/ \
		/*name*/	 _WT("默认编码"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_TEXT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyBrowserSettings::SetRemoteFonts ** 11 **/ \
		/*name*/	 _WT("状态开关"), \
		/*explain*/	 _WT("配置状态开关定义值为枚举常量: #状态开关.*"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyBrowserSettings::SetJavascript ** 12 **/ \
		/*name*/	 _WT("状态开关"), \
		/*explain*/	 _WT("设置启用状态, 定义值为枚举常量: #状态开关.* 。"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyBrowserSettings::SetJavascriptCloseWindow ** 13 **/ \
		/*name*/	 _WT("状态开关"), \
		/*explain*/	 _WT("设置启用状态, 定义值为枚举常量: #状态开关.* 。"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyBrowserSettings::SetJavascriptAccessClipboard ** 14 **/ \
		/*name*/	 _WT("状态开关"), \
		/*explain*/	 _WT("设置启用状态, 定义值为枚举常量: #状态开关.* 。"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyBrowserSettings::SetJavascriptDomPaste ** 15 **/ \
		/*name*/	 _WT("状态开关"), \
		/*explain*/	 _WT("设置启用状态, 定义值为枚举常量: #状态开关.* 。"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyBrowserSettings::SetPlugins ** 16 **/ \
		/*name*/	 _WT("状态开关"), \
		/*explain*/	 _WT("设置启用状态, 定义值为枚举常量: #状态开关.* 。"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyBrowserSettings::SetUniversalAccessFromFileUrls ** 17 **/ \
		/*name*/	 _WT("状态开关"), \
		/*explain*/	 _WT("设置启用状态, 定义值为枚举常量: #状态开关.* 。"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyBrowserSettings::SetFileAccessFromFileUrls ** 18 **/ \
		/*name*/	 _WT("状态开关"), \
		/*explain*/	 _WT("设置启用状态, 定义值为枚举常量: #状态开关.* 。"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyBrowserSettings::SetWebSecurity ** 19 **/ \
		/*name*/	 _WT("状态开关"), \
		/*explain*/	 _WT("设置启用状态, 定义值为枚举常量: #状态开关.* 。"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyBrowserSettings::SetImageLoading ** 20 **/ \
		/*name*/	 _WT("状态开关"), \
		/*explain*/	 _WT("设置启用状态, 定义值为枚举常量: #状态开关.* 。"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyBrowserSettings::SetImageShrinkStandaloneToFit ** 21 **/ \
		/*name*/	 _WT("状态开关"), \
		/*explain*/	 _WT("设置启用状态, 定义值为枚举常量: #状态开关.* 。"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyBrowserSettings::SetTextAreaResize ** 22 **/ \
		/*name*/	 _WT("状态开关"), \
		/*explain*/	 _WT("设置启用状态, 定义值为枚举常量: #状态开关.* 。"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyBrowserSettings::SetTabToLinks ** 23 **/ \
		/*name*/	 _WT("状态开关"), \
		/*explain*/	 _WT("设置启用状态, 定义值为枚举常量: #状态开关.* 。"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyBrowserSettings::SetLocalStorage ** 24 **/ \
		/*name*/	 _WT("状态开关"), \
		/*explain*/	 _WT("设置启用状态, 定义值为枚举常量: #状态开关.* 。"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyBrowserSettings::SetDataBase ** 25 **/ \
		/*name*/	 _WT("启用状态"), \
		/*explain*/	 _WT("设置启用状态, 定义值为枚举常量: #状态开关.* 。"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyBrowserSettings::SetApplicationCache ** 26 **/ \
		/*name*/	 _WT("状态开关"), \
		/*explain*/	 _WT("设置启用状态, 定义值为枚举常量: #状态开关.* 。"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyBrowserSettings::SetWebGL ** 27 **/ \
		/*name*/	 _WT("状态开关"), \
		/*explain*/	 _WT("设置启用状态, 定义值为枚举常量: #状态开关.* 。"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyBrowserSettings::SetBackgroundColor ** 28 **/ \
		/*name*/	 _WT("颜色"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyBrowserSettings::SetAcceptLanguageList ** 29 **/ \
		/*name*/	 _WT("语言字符串"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_TEXT, \
		/*default*/	 0,\
		/*state*/	 NULL \
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
		/*ccname*/	_WT("标准字体"),\
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
		/*arg lp*/	&s_ArgInfo[BeginIndex+0] \
	},\
	{ /*5*/ \
		/*ccname*/	_WT("等宽字体"),\
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
		/*arg lp*/	&s_ArgInfo[BeginIndex+1] \
	},\
	{ /*6*/ \
		/*ccname*/	_WT("衬线字体"),\
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
		/*arg lp*/	&s_ArgInfo[BeginIndex+2] \
	},\
	{ /*7*/ \
		/*ccname*/	_WT("无衬线字体"),\
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
		/*arg lp*/	&s_ArgInfo[BeginIndex+3] \
	},\
	{ /*8*/ \
		/*ccname*/	_WT("手写字体"),\
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
		/*arg lp*/	&s_ArgInfo[BeginIndex+4] \
	},\
	{ /*9*/ \
		/*ccname*/	_WT("艺术字体"),\
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
		/*arg lp*/	&s_ArgInfo[BeginIndex+5] \
	},\
	{ /*10*/ \
		/*ccname*/	_WT("默认字体大小"),\
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
		/*arg lp*/	&s_ArgInfo[BeginIndex+6] \
	},\
	{ /*11*/ \
		/*ccname*/	_WT("默认等宽字体大小"),\
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
		/*arg lp*/	&s_ArgInfo[BeginIndex+7] \
	},\
	{ /*12*/ \
		/*ccname*/	_WT("字体最小大小"),\
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
		/*arg lp*/	&s_ArgInfo[BeginIndex+8] \
	},\
	{ /*13*/ \
		/*ccname*/	_WT("字体最小合理大小"),\
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
		/*arg lp*/	&s_ArgInfo[BeginIndex+9] \
	},\
	{ /*14*/ \
		/*ccname*/	_WT("页面缺省编码"),\
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
		/*arg lp*/	&s_ArgInfo[BeginIndex+10] \
	},\
	{ /*15*/ \
		/*ccname*/	_WT("加载远程字体源"),\
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
		/*arg lp*/	&s_ArgInfo[BeginIndex+11] \
	},\
	{ /*16*/ \
		/*ccname*/	_WT("脚本可否执行"),\
		/*egname*/	_WT("SetJavascript"), \
		/*explain*/	_WT("控制是否可以执行Javascript脚本。"), \
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
	{ /*17*/ \
		/*ccname*/	_WT("脚本可否关闭窗口"),\
		/*egname*/	_WT("SetJavascriptCloseWindow"), \
		/*explain*/	_WT("控制是否可以使用JavaScript关闭未通过JavaScript打开的窗口。Javascript仍可用于关闭通过Javascript打开的窗口或没有后退/前进历史记录的窗口。"), \
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
	{ /*18*/ \
		/*ccname*/	_WT("脚本可否访问剪贴板"),\
		/*egname*/	_WT("SetJavascriptAccessClipboard"), \
		/*explain*/	_WT("控制JavaScript是否可用访问剪贴板。"), \
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
	{ /*19*/ \
		/*ccname*/	_WT("脚本可否粘贴DOM"),\
		/*egname*/	_WT("SetJavascriptDomPaste"), \
		/*explain*/	_WT("控制是否通过 execCommand(\"paste\") 在编辑器中支持DOM粘贴。 要使用该设置需要连同 脚本可否访问剪贴板 设置一起启用。"), \
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
	{ /*20*/ \
		/*ccname*/	_WT("加载插件"),\
		/*egname*/	_WT("SetPlugins"), \
		/*explain*/	_WT("控制是否允许加载插件"), \
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
	{ /*21*/ \
		/*ccname*/	_WT("文件URL所有访问"),\
		/*egname*/	_WT("SetUniversalAccessFromFileUrls"), \
		/*explain*/	_WT("控制文件URL是否可以访问所有URL。"), \
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
	{ /*22*/ \
		/*ccname*/	_WT("文件URL本地访问"),\
		/*egname*/	_WT("SetFileAccessFromFileUrls"), \
		/*explain*/	_WT("控制文件URL是否可用访问其它文件URL"), \
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
	{ /*23*/ \
		/*ccname*/	_WT("WEB安全限制"),\
		/*egname*/	_WT("SetWebSecurity"), \
		/*explain*/	_WT("控制是否将Web安全限制(同源策略)设置为强制执行。不建议禁用此设置, 因为它会带来风险安全行为, 例如跨站点脚本(XSS)。"), \
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
	{ /*24*/ \
		/*ccname*/	_WT("加载图像"),\
		/*egname*/	_WT("SetImageLoading"), \
		/*explain*/	_WT("控制是否从网络加载图像URL。如果需要, 仍将渲染缓存的图像。"), \
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
	{ /*25*/ \
		/*ccname*/	_WT("图像自适应缩放"),\
		/*egname*/	_WT("SetImageShrinkStandaloneToFit"), \
		/*explain*/	_WT("控制是否将独立图像缩小以适合页面。"), \
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
	{ /*26*/ \
		/*ccname*/	_WT("调整文本区域尺寸"),\
		/*egname*/	_WT("SetTextAreaResize"), \
		/*explain*/	_WT("控制是否可用调整文本区域(Text Area)的大小。"), \
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
	{ /*27*/ \
		/*ccname*/	_WT("转移焦点到连接"),\
		/*egname*/	_WT("SetTabToLinks"), \
		/*explain*/	_WT("控制TAB键是否可用将焦点转移到链接。"), \
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
	{ /*28*/ \
		/*ccname*/	_WT("LocalStorage"),\
		/*egname*/	_WT("SetLocalStorage"), \
		/*explain*/	_WT("控制是否可用使用本地存储(Local Storage)。"), \
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
	{ /*29*/ \
		/*ccname*/	_WT("Database"),\
		/*egname*/	_WT("SetDataBase"), \
		/*explain*/	_WT("控制是否可用使用数据库(Database)。"), \
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
	{ /*30*/ \
		/*ccname*/	_WT("ApplicationCache"),\
		/*egname*/	_WT("SetApplicationCache"), \
		/*explain*/	_WT("控制可否使用应用缓存(Application Cache)。"), \
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
	{ /*31*/ \
		/*ccname*/	_WT("WebGL"),\
		/*egname*/	_WT("SetWebGL"), \
		/*explain*/	_WT("控制是否可用使用WebGL, 请注意, WebGL 需要硬件支持, 即使启用, 也可能无法在所有系统上运行。"), \
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
	{ /*32*/ \
		/*ccname*/	_WT("背景颜色"),\
		/*egname*/	_WT("SetBackgroundColor"), \
		/*explain*/	_WT("在加载稳定之前和未指定文档颜色时浏览器使用的背景颜色。alpha分量必须完全不透明(0xFF)或完全透明(0x00).如果Alpha分量完全不透明, 则RGB分量将作用于背景色。"), \
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
	{ /*33*/ \
		/*ccname*/	_WT("接收语言字符串"),\
		/*egname*/	_WT("SetAcceptLanguageList"), \
		/*explain*/	_WT("设置以逗号分隔的语言代码的有序列表, 不能出现空格, 这些字符串将在HTTP Accept-Language 标头中使用。"), \
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


//==========================================

#define DECL_DATA_TYPE_ProxyBrowserSettings_FUN_NAMES \
	EDITIONS("ProxyBrowserSettings_Constructor"),\
	EDITIONS("ProxyBrowserSettings_Destructor"),\
	EDITIONS("ProxyBrowserSettings_CopyConstructor"),\
	EDITIONS("ProxyBrowserSettings_IsValid"),\
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
	EDITIONS("ProxyBrowserSettings_SetJavascriptCloseWindow"),\
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
	EDITIONS("ProxyBrowserSettings_SetDataBase"),\
	EDITIONS("ProxyBrowserSettings_SetApplicationCache"),\
	EDITIONS("ProxyBrowserSettings_SetWebGL"),\
	EDITIONS("ProxyBrowserSettings_SetBackgroundColor"),\
	EDITIONS("ProxyBrowserSettings_SetAcceptLanguageList"),\


//==========================================

#define DECL_DATA_TYPE_ProxyBrowserSettings_FUN_CALLS \
	EDITIONF(ProxyBrowserSettings_Constructor),\
	EDITIONF(ProxyBrowserSettings_Destructor),\
	EDITIONF(ProxyBrowserSettings_CopyConstructor),\
	EDITIONF(ProxyBrowserSettings_IsValid),\
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
	EDITIONF(ProxyBrowserSettings_SetJavascriptCloseWindow),\
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
	EDITIONF(ProxyBrowserSettings_SetDataBase),\
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
void EDITIONF(ProxyBrowserSettings_IsValid) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
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
void EDITIONF(ProxyBrowserSettings_SetJavascriptCloseWindow) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
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
void EDITIONF(ProxyBrowserSettings_SetDataBase) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyBrowserSettings_SetApplicationCache) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyBrowserSettings_SetWebGL) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyBrowserSettings_SetBackgroundColor) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyBrowserSettings_SetAcceptLanguageList) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);


//==========================================

