#pragma once

#include "stdafx.h"
#include "lib2.h"


#define DECL_DATA_TYPE_ProxyFrame \
	{ /*17*/ \
		/*m_szName*/		 _WT("水星框架"), \
		/*m_szEgName*/		 _WT("ProxyFrame"), \
		/*m_szExplain*/		 _WT("用于在浏览器窗口中表示框架的类。在浏览器进程中使用时, 可以在任何线程上调用此类中的方法。除非注释另有说明。"), \
		/*m_nCmdCount*/		 31, \
		/*m_pnCmdsIndex*/		 s_nProxyFrameElementCmdIndex, \
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

#define DECL_DATA_TYPE_ProxyFrame_ARGINFO \
	{ /****** ProxyFrame::LoadURL ** 0 **/ \
		/*name*/	 _WT("url"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_TEXT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyFrame::LoadRequest ** 1 **/ \
		/*name*/	 _WT("请求"), \
		/*explain*/	 _WT("加载的请求"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 MAKELONG(24,0),  /*shrewd_ptr<ProxyRequest>*/ \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyFrame::ExecuteJavaScript ** 2 **/ \
		/*name*/	 _WT("脚本代码"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_TEXT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyFrame::ExecuteJavaScript ** 3 **/ \
		/*name*/	 _WT("脚本别名"), \
		/*explain*/	 _WT("用作在控制台中显示的url标识符"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_TEXT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyFrame::ExecuteJavaScript ** 4 **/ \
		/*name*/	 _WT("起始行"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyFrame::ExecuteJavaScriptEx ** 5 **/ \
		/*name*/	 _WT("脚本代码"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_TEXT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyFrame::ExecuteJavaScriptEx ** 6 **/ \
		/*name*/	 _WT("脚本别名"), \
		/*explain*/	 _WT("用作在控制台中显示的url标识符。"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_TEXT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyFrame::ExecuteJavaScriptEx ** 7 **/ \
		/*name*/	 _WT("起始行"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyFrame::ExecuteJavaScriptEx ** 8 **/ \
		/*name*/	 _WT("异常信息"), \
		/*explain*/	 _WT("执行异常时报告的错误信息。"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_TEXT, \
		/*default*/	 0,\
		/*state*/	 AS_RECEIVE_VAR,\
	},\
	{ /****** ProxyFrame::CreateURLRequest ** 9 **/ \
		/*name*/	 _WT("请求"), \
		/*explain*/	 _WT("待发送的HTTP请求"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 MAKELONG(24,0),  /*shrewd_ptr<ProxyRequest>*/ \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyFrame::CreateURLRequest ** 10 **/ \
		/*name*/	 _WT("认证用户名"), \
		/*explain*/	 _WT("提供用于身份验证的凭证信息, 如果有的话。"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_TEXT, \
		/*default*/	 0,\
		/*state*/	 AS_DEFAULT_VALUE_IS_EMPTY \
	},\
	{ /****** ProxyFrame::CreateURLRequest ** 11 **/ \
		/*name*/	 _WT("认证密码"), \
		/*explain*/	 _WT("提供用于身份验证的凭证信息, 如果有的话。"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_TEXT, \
		/*default*/	 0,\
		/*state*/	 AS_DEFAULT_VALUE_IS_EMPTY \
	},\
	{ /****** ProxyFrame::SynthesizePinchGesture ** 12 **/ \
		/*name*/	 _WT("开始位置X"), \
		/*explain*/	 _WT("手势开始的X坐标位置, 以CSS像素为单位。"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_FLOAT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyFrame::SynthesizePinchGesture ** 13 **/ \
		/*name*/	 _WT("开始位置Y"), \
		/*explain*/	 _WT("手势开始的Y坐标位置, 以CSS像素为单位。"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_FLOAT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyFrame::SynthesizePinchGesture ** 14 **/ \
		/*name*/	 _WT("缩放因子"), \
		/*explain*/	 _WT("缩放后的相对比例因子, > 1.0 放大, < 1.0 缩小。"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_FLOAT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyFrame::SynthesizePinchGesture ** 15 **/ \
		/*name*/	 _WT("相对速度"), \
		/*explain*/	 _WT("相对指针速度, 以每像素/秒为单位, 默认值为: 800。"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_FLOAT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyFrame::SynthesizePinchGesture ** 16 **/ \
		/*name*/	 _WT("输出源"), \
		/*explain*/	 _WT("生成哪种类型的输入事件, 定义值为枚举常量: #手势输出源.* "), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_FLOAT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyFrame::SynthesizeScrollGesture ** 17 **/ \
		/*name*/	 _WT("开始位置X"), \
		/*explain*/	 _WT("手势开始的X坐标位置, 以CSS像素为单位。"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_FLOAT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyFrame::SynthesizeScrollGesture ** 18 **/ \
		/*name*/	 _WT("开始位置Y"), \
		/*explain*/	 _WT("手势开始的Y坐标位置, 以CSS像素为单位。"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_FLOAT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyFrame::SynthesizeScrollGesture ** 19 **/ \
		/*name*/	 _WT("滑动距离X"), \
		/*explain*/	 _WT("沿X轴滑动的距离(向右滑动)。"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_FLOAT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyFrame::SynthesizeScrollGesture ** 20 **/ \
		/*name*/	 _WT("滑动距离Y"), \
		/*explain*/	 _WT("沿Y轴滑动的距离(向上滑动)。"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_FLOAT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyFrame::SynthesizeScrollGesture ** 21 **/ \
		/*name*/	 _WT("增量距离X"), \
		/*explain*/	 _WT("沿X轴滑动给定距离后的增程量。"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_FLOAT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyFrame::SynthesizeScrollGesture ** 22 **/ \
		/*name*/	 _WT("增量距离Y"), \
		/*explain*/	 _WT("沿Y轴滑动给定距离后的增程量。"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_FLOAT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyFrame::SynthesizeScrollGesture ** 23 **/ \
		/*name*/	 _WT("缩放因子"), \
		/*explain*/	 _WT("缩放后的相对比例因子, > 1.0 放大, < 1.0 缩小。"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_FLOAT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyFrame::SynthesizeScrollGesture ** 24 **/ \
		/*name*/	 _WT("防止逃逸"), \
		/*explain*/	 _WT("防止滑出边界。"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_BOOL, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyFrame::SynthesizeScrollGesture ** 25 **/ \
		/*name*/	 _WT("滑动速度"), \
		/*explain*/	 _WT("滑动速度(以每像素/秒为单位), 默认值: 800"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyFrame::SynthesizeScrollGesture ** 26 **/ \
		/*name*/	 _WT("输出源"), \
		/*explain*/	 _WT("生成哪种类型的输入事件, 定义值为枚举常量: #手势输出源.* "), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyFrame::SynthesizeTapGesture ** 27 **/ \
		/*name*/	 _WT("开始位置X"), \
		/*explain*/	 _WT("手势开始的X坐标位置, 以CSS像素为单位。"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_FLOAT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyFrame::SynthesizeTapGesture ** 28 **/ \
		/*name*/	 _WT("开始位置Y"), \
		/*explain*/	 _WT("手势开始的Y坐标位置, 以CSS像素为单位。"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_FLOAT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyFrame::SynthesizeTapGesture ** 29 **/ \
		/*name*/	 _WT("缩放因子"), \
		/*explain*/	 _WT("缩放后的相对比例因子, > 1.0 放大, < 1.0 缩小。"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_FLOAT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyFrame::SynthesizeTapGesture ** 30 **/ \
		/*name*/	 _WT("持续时间"), \
		/*explain*/	 _WT("从 touchdown 到 touchup 事件之间的持续时间（毫秒）。默认值: 50"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyFrame::SynthesizeTapGesture ** 31 **/ \
		/*name*/	 _WT("轻击次数"), \
		/*explain*/	 _WT("执行轻击的次数。默认值: 1"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyFrame::SynthesizeTapGesture ** 32 **/ \
		/*name*/	 _WT("输出源"), \
		/*explain*/	 _WT("生成哪种类型的输入事件, 定义值为枚举常量: #手势输出源.* "), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyFrame::SynthesizeDragGesture ** 33 **/ \
		/*name*/	 _WT("开始位置X"), \
		/*explain*/	 _WT("手势开始的X坐标位置, 以CSS像素为单位。"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_FLOAT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyFrame::SynthesizeDragGesture ** 34 **/ \
		/*name*/	 _WT("开始位置Y"), \
		/*explain*/	 _WT("手势开始的Y坐标位置, 以CSS像素为单位。"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_FLOAT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyFrame::SynthesizeDragGesture ** 35 **/ \
		/*name*/	 _WT("拖动距离X"), \
		/*explain*/	 _WT("沿X轴拖动的距离(向右拖动)。"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_FLOAT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyFrame::SynthesizeDragGesture ** 36 **/ \
		/*name*/	 _WT("拖动距离Y"), \
		/*explain*/	 _WT("沿Y轴拖动的距离(向上拖动)。"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_FLOAT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyFrame::SynthesizeDragGesture ** 37 **/ \
		/*name*/	 _WT("缩放因子"), \
		/*explain*/	 _WT("缩放后的相对比例因子, > 1.0 放大, < 1.0 缩小。"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_FLOAT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyFrame::SynthesizeDragGesture ** 38 **/ \
		/*name*/	 _WT("拖动速度"), \
		/*explain*/	 _WT("拖动速度"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyFrame::SynthesizeDragGesture ** 39 **/ \
		/*name*/	 _WT("输出源"), \
		/*explain*/	 _WT("生成哪种类型的输入事件, 定义值为枚举常量: #手势输出源.* "), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\


//==========================================

#define DECL_DATA_TYPE_ProxyFrame_CMDINFO(BeginIndex) \
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
		/*ccname*/	_WT("撤销"),\
		/*egname*/	_WT("Undo"), \
		/*explain*/	_WT(""), \
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
	{ /*5*/ \
		/*ccname*/	_WT("重做"),\
		/*egname*/	_WT("Redo"), \
		/*explain*/	_WT(""), \
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
		/*ccname*/	_WT("剪切"),\
		/*egname*/	_WT("Cut"), \
		/*explain*/	_WT(""), \
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
	{ /*7*/ \
		/*ccname*/	_WT("复制"),\
		/*egname*/	_WT("Copy"), \
		/*explain*/	_WT(""), \
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
	{ /*8*/ \
		/*ccname*/	_WT("粘贴"),\
		/*egname*/	_WT("Paste"), \
		/*explain*/	_WT(""), \
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
	{ /*9*/ \
		/*ccname*/	_WT("删除"),\
		/*egname*/	_WT("Delete"), \
		/*explain*/	_WT(""), \
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
	{ /*10*/ \
		/*ccname*/	_WT("全选"),\
		/*egname*/	_WT("SelectAll"), \
		/*explain*/	_WT(""), \
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
	{ /*11*/ \
		/*ccname*/	_WT("源码视图"),\
		/*egname*/	_WT("ViewSource"), \
		/*explain*/	_WT(""), \
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
	{ /*12*/ \
		/*ccname*/	_WT("取页面源码"),\
		/*egname*/	_WT("GetSource"), \
		/*explain*/	_WT("取此框架中的页面HTML源代码, 注意: 此函数禁止在事件中调用。"), \
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
	{ /*13*/ \
		/*ccname*/	_WT("取页面文本"),\
		/*egname*/	_WT("GetText"), \
		/*explain*/	_WT("取此框架中的页面文本, 注意: 此函数禁止在事件中调用。"), \
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
	{ /*14*/ \
		/*ccname*/	_WT("加载URL"),\
		/*egname*/	_WT("LoadURL"), \
		/*explain*/	_WT("在此框架中加载指定的URL。"), \
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
	{ /*15*/ \
		/*ccname*/	_WT("加载请求"),\
		/*egname*/	_WT("LoadRequest"), \
		/*explain*/	_WT("在此框架中加载一个新的请求。在执行此方法前需要至少执行过一次加载URL函数。"), \
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
	{ /*16*/ \
		/*ccname*/	_WT("执行脚本"),\
		/*egname*/	_WT("ExecuteJavaScript"), \
		/*explain*/	_WT("在此框架值执行指定的Javascript脚本代码。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	_SDT_NULL, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	3, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+2] \
	},\
	{ /*17*/ \
		/*ccname*/	_WT("执行脚本2"),\
		/*egname*/	_WT("ExecuteJavaScriptEx"), \
		/*explain*/	_WT("在此框架中执行指定的javacript脚本代码。执行成功返回计算结果, 执行失败返回空对象, 可调用IsValid() 函数检查对象有效性。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	MAKELONG(31,0),  /*shrewd_ptr<ProxyValue>*/ \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	4, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+5] \
	},\
	{ /*18*/ \
		/*ccname*/	_WT("是否为主框架"),\
		/*egname*/	_WT("IsMain"), \
		/*explain*/	_WT("如果此框架为首要框架(Top-Level)返回真。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	SDT_BOOL, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	0, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+9] \
	},\
	{ /*19*/ \
		/*ccname*/	_WT("是否拥有焦点"),\
		/*egname*/	_WT("IsFocused"), \
		/*explain*/	_WT("如果此框架拥有焦点返回真。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	SDT_BOOL, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	0, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+9] \
	},\
	{ /*20*/ \
		/*ccname*/	_WT("取名称"),\
		/*egname*/	_WT("GetName"), \
		/*explain*/	_WT("取此框架的名称。"), \
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
	{ /*21*/ \
		/*ccname*/	_WT("取父框架"),\
		/*egname*/	_WT("GetParent"), \
		/*explain*/	_WT("取此框架的父框架, 如果此框架没有父框架将返回空对象。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	MAKELONG(17,0),  /*shrewd_ptr<ProxyFrame>*/ \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	0, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+9] \
	},\
	{ /*22*/ \
		/*ccname*/	_WT("取URL"),\
		/*egname*/	_WT("GetURL"), \
		/*explain*/	_WT("取此框架中加载的URL。"), \
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
	{ /*23*/ \
		/*ccname*/	_WT("取浏览器"),\
		/*egname*/	_WT("GetBrowser"), \
		/*explain*/	_WT("取此框架所属的浏览器。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	MAKELONG(4,0),  /*shrewd_ptr<ProxyBrowser>*/ \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	0, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+9] \
	},\
	{ /*24*/ \
		/*ccname*/	_WT("取标识符"),\
		/*egname*/	_WT("GetIdentifier"), \
		/*explain*/	_WT("返回此框架的标识符"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	SDT_INT64, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	0, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+9] \
	},\
	{ /*25*/ \
		/*ccname*/	_WT("发送URL请求"),\
		/*egname*/	_WT("CreateURLRequest"), \
		/*explain*/	_WT("使用本框架作为会话源发送一个HTTP请求。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	MAKELONG(30,0),  /*shrewd_ptr<ProxyURLRequest>*/ \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	3, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+9] \
	},\
	{ /*26*/ \
		/*ccname*/	_WT("取文档对象"),\
		/*egname*/	_WT("VisitDOM"), \
		/*explain*/	_WT("返回此框架内的文档对象。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	MAKELONG(12,0),  /*shrewd_ptr<ProxyDOMDocument>*/ \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	0, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+12] \
	},\
	{ /*27*/ \
		/*ccname*/	_WT("合成捏合手势"),\
		/*egname*/	_WT("SynthesizePinchGesture"), \
		/*explain*/	_WT("通过发出适当的触摸事件, 以在一段时间内合成捏合手势。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	_SDT_NULL, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	5, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+12] \
	},\
	{ /*28*/ \
		/*ccname*/	_WT("合成滑动手势"),\
		/*egname*/	_WT("SynthesizeScrollGesture"), \
		/*explain*/	_WT("通过发出适当的触摸事件, 以在一段时间内合成滑动手势。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	_SDT_NULL, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	10, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+17] \
	},\
	{ /*29*/ \
		/*ccname*/	_WT("合成轻击手势"),\
		/*egname*/	_WT("SynthesizeTapGesture"), \
		/*explain*/	_WT("通过发出适当的触摸事件, 以在一段时间内合成轻击手势。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	_SDT_NULL, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	6, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+27] \
	},\
	{ /*30*/ \
		/*ccname*/	_WT("合成拖动手势"),\
		/*egname*/	_WT("SynthesizeDragGesture"), \
		/*explain*/	_WT("通过发出适当的触摸事件, 以在一段时间内合成拖动手势。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	_SDT_NULL, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	7, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+33] \
	},\


//==========================================

#define DECL_DATA_TYPE_ProxyFrame_FUN_NAMES \
	EDITIONS("ProxyFrame_Constructor"),\
	EDITIONS("ProxyFrame_Destructor"),\
	EDITIONS("ProxyFrame_CopyConstructor"),\
	EDITIONS("ProxyFrame_IsValid"),\
	EDITIONS("ProxyFrame_Undo"),\
	EDITIONS("ProxyFrame_Redo"),\
	EDITIONS("ProxyFrame_Cut"),\
	EDITIONS("ProxyFrame_Copy"),\
	EDITIONS("ProxyFrame_Paste"),\
	EDITIONS("ProxyFrame_Delete"),\
	EDITIONS("ProxyFrame_SelectAll"),\
	EDITIONS("ProxyFrame_ViewSource"),\
	EDITIONS("ProxyFrame_GetSource"),\
	EDITIONS("ProxyFrame_GetText"),\
	EDITIONS("ProxyFrame_LoadURL"),\
	EDITIONS("ProxyFrame_LoadRequest"),\
	EDITIONS("ProxyFrame_ExecuteJavaScript"),\
	EDITIONS("ProxyFrame_ExecuteJavaScriptEx"),\
	EDITIONS("ProxyFrame_IsMain"),\
	EDITIONS("ProxyFrame_IsFocused"),\
	EDITIONS("ProxyFrame_GetName"),\
	EDITIONS("ProxyFrame_GetParent"),\
	EDITIONS("ProxyFrame_GetURL"),\
	EDITIONS("ProxyFrame_GetBrowser"),\
	EDITIONS("ProxyFrame_GetIdentifier"),\
	EDITIONS("ProxyFrame_CreateURLRequest"),\
	EDITIONS("ProxyFrame_VisitDOM"),\
	EDITIONS("ProxyFrame_SynthesizePinchGesture"),\
	EDITIONS("ProxyFrame_SynthesizeScrollGesture"),\
	EDITIONS("ProxyFrame_SynthesizeTapGesture"),\
	EDITIONS("ProxyFrame_SynthesizeDragGesture"),\


//==========================================

#define DECL_DATA_TYPE_ProxyFrame_FUN_CALLS \
	EDITIONF(ProxyFrame_Constructor),\
	EDITIONF(ProxyFrame_Destructor),\
	EDITIONF(ProxyFrame_CopyConstructor),\
	EDITIONF(ProxyFrame_IsValid),\
	EDITIONF(ProxyFrame_Undo),\
	EDITIONF(ProxyFrame_Redo),\
	EDITIONF(ProxyFrame_Cut),\
	EDITIONF(ProxyFrame_Copy),\
	EDITIONF(ProxyFrame_Paste),\
	EDITIONF(ProxyFrame_Delete),\
	EDITIONF(ProxyFrame_SelectAll),\
	EDITIONF(ProxyFrame_ViewSource),\
	EDITIONF(ProxyFrame_GetSource),\
	EDITIONF(ProxyFrame_GetText),\
	EDITIONF(ProxyFrame_LoadURL),\
	EDITIONF(ProxyFrame_LoadRequest),\
	EDITIONF(ProxyFrame_ExecuteJavaScript),\
	EDITIONF(ProxyFrame_ExecuteJavaScriptEx),\
	EDITIONF(ProxyFrame_IsMain),\
	EDITIONF(ProxyFrame_IsFocused),\
	EDITIONF(ProxyFrame_GetName),\
	EDITIONF(ProxyFrame_GetParent),\
	EDITIONF(ProxyFrame_GetURL),\
	EDITIONF(ProxyFrame_GetBrowser),\
	EDITIONF(ProxyFrame_GetIdentifier),\
	EDITIONF(ProxyFrame_CreateURLRequest),\
	EDITIONF(ProxyFrame_VisitDOM),\
	EDITIONF(ProxyFrame_SynthesizePinchGesture),\
	EDITIONF(ProxyFrame_SynthesizeScrollGesture),\
	EDITIONF(ProxyFrame_SynthesizeTapGesture),\
	EDITIONF(ProxyFrame_SynthesizeDragGesture),\


//==========================================

extern "C"
void EDITIONF(ProxyFrame_Constructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyFrame_Destructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyFrame_CopyConstructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyFrame_IsValid) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyFrame_Undo) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyFrame_Redo) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyFrame_Cut) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyFrame_Copy) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyFrame_Paste) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyFrame_Delete) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyFrame_SelectAll) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyFrame_ViewSource) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyFrame_GetSource) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyFrame_GetText) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyFrame_LoadURL) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyFrame_LoadRequest) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyFrame_ExecuteJavaScript) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyFrame_ExecuteJavaScriptEx) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyFrame_IsMain) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyFrame_IsFocused) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyFrame_GetName) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyFrame_GetParent) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyFrame_GetURL) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyFrame_GetBrowser) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyFrame_GetIdentifier) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyFrame_CreateURLRequest) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyFrame_VisitDOM) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyFrame_SynthesizePinchGesture) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyFrame_SynthesizeScrollGesture) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyFrame_SynthesizeTapGesture) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyFrame_SynthesizeDragGesture) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);


//==========================================

