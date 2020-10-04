#pragma once

#include "stdafx.h"
#include "lib2.h"


#define DECL_DATA_TYPE_ProxyContextMenuParams \
	{ /*8*/ \
		/*m_szName*/		 _WT("Chromium菜单上下文信息"), \
		/*m_szEgName*/		 _WT("ProxyContextMenuParams"), \
		/*m_szExplain*/		 _WT("提供有关上下文菜单状态的信息。"), \
		/*m_nCmdCount*/		 24, \
		/*m_pnCmdsIndex*/		 s_nProxyContextMenuParamsElementCmdIndex, \
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

#define DECL_DATA_TYPE_ProxyContextMenuParams_ARGINFO \


//==========================================

#define DECL_DATA_TYPE_ProxyContextMenuParams_CMDINFO(BeginIndex) \
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
		/*ccname*/	_WT("GetXCoord"),\
		/*egname*/	_WT("GetXCoord"), \
		/*explain*/	_WT(""), \
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
	{ /*4*/ \
		/*ccname*/	_WT("GetYCoord"),\
		/*egname*/	_WT("GetYCoord"), \
		/*explain*/	_WT(""), \
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
		/*ccname*/	_WT("GetTypeFlags"),\
		/*egname*/	_WT("GetTypeFlags"), \
		/*explain*/	_WT(""), \
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
	{ /*6*/ \
		/*ccname*/	_WT("GetLinkUrl"),\
		/*egname*/	_WT("GetLinkUrl"), \
		/*explain*/	_WT(""), \
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
	{ /*7*/ \
		/*ccname*/	_WT("GetUnfilteredLinkUrl"),\
		/*egname*/	_WT("GetUnfilteredLinkUrl"), \
		/*explain*/	_WT(""), \
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
	{ /*8*/ \
		/*ccname*/	_WT("GetSourceUrl"),\
		/*egname*/	_WT("GetSourceUrl"), \
		/*explain*/	_WT(""), \
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
		/*ccname*/	_WT("HasImageContents"),\
		/*egname*/	_WT("HasImageContents"), \
		/*explain*/	_WT(""), \
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
	{ /*10*/ \
		/*ccname*/	_WT("GetTitleText"),\
		/*egname*/	_WT("GetTitleText"), \
		/*explain*/	_WT(""), \
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
		/*ccname*/	_WT("GetPageUrl"),\
		/*egname*/	_WT("GetPageUrl"), \
		/*explain*/	_WT(""), \
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
		/*ccname*/	_WT("GetFrameUrl"),\
		/*egname*/	_WT("GetFrameUrl"), \
		/*explain*/	_WT(""), \
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
		/*ccname*/	_WT("GetFrameCharset"),\
		/*egname*/	_WT("GetFrameCharset"), \
		/*explain*/	_WT(""), \
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
		/*ccname*/	_WT("GetMediaType"),\
		/*egname*/	_WT("GetMediaType"), \
		/*explain*/	_WT(""), \
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
	{ /*15*/ \
		/*ccname*/	_WT("GetMediaStateFlags"),\
		/*egname*/	_WT("GetMediaStateFlags"), \
		/*explain*/	_WT(""), \
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
	{ /*16*/ \
		/*ccname*/	_WT("GetSelectionText"),\
		/*egname*/	_WT("GetSelectionText"), \
		/*explain*/	_WT(""), \
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
	{ /*17*/ \
		/*ccname*/	_WT("GetMisspelledWord"),\
		/*egname*/	_WT("GetMisspelledWord"), \
		/*explain*/	_WT(""), \
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
	{ /*18*/ \
		/*ccname*/	_WT("GetDictionarySuggestions"),\
		/*egname*/	_WT("GetDictionarySuggestions"), \
		/*explain*/	_WT(""), \
		/*category*/	-1, \
		/*state*/	CT_RETRUN_ARY_TYPE_DATA, \
		/*ret*/	SDT_TEXT, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	0, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+0] \
	},\
	{ /*19*/ \
		/*ccname*/	_WT("IsEditable"),\
		/*egname*/	_WT("IsEditable"), \
		/*explain*/	_WT(""), \
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
	{ /*20*/ \
		/*ccname*/	_WT("IsSpellCheckEnabled"),\
		/*egname*/	_WT("IsSpellCheckEnabled"), \
		/*explain*/	_WT(""), \
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
	{ /*21*/ \
		/*ccname*/	_WT("GetEditStateFlags"),\
		/*egname*/	_WT("GetEditStateFlags"), \
		/*explain*/	_WT(""), \
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
	{ /*22*/ \
		/*ccname*/	_WT("IsCustomMenu"),\
		/*egname*/	_WT("IsCustomMenu"), \
		/*explain*/	_WT(""), \
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
	{ /*23*/ \
		/*ccname*/	_WT("IsPepperMenu"),\
		/*egname*/	_WT("IsPepperMenu"), \
		/*explain*/	_WT(""), \
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


//==========================================

#define DECL_DATA_TYPE_ProxyContextMenuParams_FUN_NAMES \
	EDITIONS("ProxyContextMenuParams_Constructor"),\
	EDITIONS("ProxyContextMenuParams_Destructor"),\
	EDITIONS("ProxyContextMenuParams_CopyConstructor"),\
	EDITIONS("ProxyContextMenuParams_GetXCoord"),\
	EDITIONS("ProxyContextMenuParams_GetYCoord"),\
	EDITIONS("ProxyContextMenuParams_GetTypeFlags"),\
	EDITIONS("ProxyContextMenuParams_GetLinkUrl"),\
	EDITIONS("ProxyContextMenuParams_GetUnfilteredLinkUrl"),\
	EDITIONS("ProxyContextMenuParams_GetSourceUrl"),\
	EDITIONS("ProxyContextMenuParams_HasImageContents"),\
	EDITIONS("ProxyContextMenuParams_GetTitleText"),\
	EDITIONS("ProxyContextMenuParams_GetPageUrl"),\
	EDITIONS("ProxyContextMenuParams_GetFrameUrl"),\
	EDITIONS("ProxyContextMenuParams_GetFrameCharset"),\
	EDITIONS("ProxyContextMenuParams_GetMediaType"),\
	EDITIONS("ProxyContextMenuParams_GetMediaStateFlags"),\
	EDITIONS("ProxyContextMenuParams_GetSelectionText"),\
	EDITIONS("ProxyContextMenuParams_GetMisspelledWord"),\
	EDITIONS("ProxyContextMenuParams_GetDictionarySuggestions"),\
	EDITIONS("ProxyContextMenuParams_IsEditable"),\
	EDITIONS("ProxyContextMenuParams_IsSpellCheckEnabled"),\
	EDITIONS("ProxyContextMenuParams_GetEditStateFlags"),\
	EDITIONS("ProxyContextMenuParams_IsCustomMenu"),\
	EDITIONS("ProxyContextMenuParams_IsPepperMenu"),\


//==========================================

#define DECL_DATA_TYPE_ProxyContextMenuParams_FUN_CALLS \
	EDITIONF(ProxyContextMenuParams_Constructor),\
	EDITIONF(ProxyContextMenuParams_Destructor),\
	EDITIONF(ProxyContextMenuParams_CopyConstructor),\
	EDITIONF(ProxyContextMenuParams_GetXCoord),\
	EDITIONF(ProxyContextMenuParams_GetYCoord),\
	EDITIONF(ProxyContextMenuParams_GetTypeFlags),\
	EDITIONF(ProxyContextMenuParams_GetLinkUrl),\
	EDITIONF(ProxyContextMenuParams_GetUnfilteredLinkUrl),\
	EDITIONF(ProxyContextMenuParams_GetSourceUrl),\
	EDITIONF(ProxyContextMenuParams_HasImageContents),\
	EDITIONF(ProxyContextMenuParams_GetTitleText),\
	EDITIONF(ProxyContextMenuParams_GetPageUrl),\
	EDITIONF(ProxyContextMenuParams_GetFrameUrl),\
	EDITIONF(ProxyContextMenuParams_GetFrameCharset),\
	EDITIONF(ProxyContextMenuParams_GetMediaType),\
	EDITIONF(ProxyContextMenuParams_GetMediaStateFlags),\
	EDITIONF(ProxyContextMenuParams_GetSelectionText),\
	EDITIONF(ProxyContextMenuParams_GetMisspelledWord),\
	EDITIONF(ProxyContextMenuParams_GetDictionarySuggestions),\
	EDITIONF(ProxyContextMenuParams_IsEditable),\
	EDITIONF(ProxyContextMenuParams_IsSpellCheckEnabled),\
	EDITIONF(ProxyContextMenuParams_GetEditStateFlags),\
	EDITIONF(ProxyContextMenuParams_IsCustomMenu),\
	EDITIONF(ProxyContextMenuParams_IsPepperMenu),\


//==========================================

extern "C"
void EDITIONF(ProxyContextMenuParams_Constructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyContextMenuParams_Destructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyContextMenuParams_CopyConstructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyContextMenuParams_GetXCoord) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyContextMenuParams_GetYCoord) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyContextMenuParams_GetTypeFlags) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyContextMenuParams_GetLinkUrl) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyContextMenuParams_GetUnfilteredLinkUrl) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyContextMenuParams_GetSourceUrl) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyContextMenuParams_HasImageContents) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyContextMenuParams_GetTitleText) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyContextMenuParams_GetPageUrl) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyContextMenuParams_GetFrameUrl) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyContextMenuParams_GetFrameCharset) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyContextMenuParams_GetMediaType) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyContextMenuParams_GetMediaStateFlags) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyContextMenuParams_GetSelectionText) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyContextMenuParams_GetMisspelledWord) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyContextMenuParams_GetDictionarySuggestions) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyContextMenuParams_IsEditable) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyContextMenuParams_IsSpellCheckEnabled) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyContextMenuParams_GetEditStateFlags) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyContextMenuParams_IsCustomMenu) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyContextMenuParams_IsPepperMenu) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);


//==========================================

