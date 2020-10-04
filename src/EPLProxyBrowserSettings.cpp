#include "stdafx.h"
#include "EPLProxyBrowserSettings.h"
#include <proxy/ProxyBrowser.h>
#include <proxy/ProxyBrowserHost.h>
#include <proxy/ProxyFrame.h>
#include <proxy/ProxyRequest.h>
#include <proxy/ProxyResponse.h>
#include <proxy/proxyValue.h>
#include <proxy/proxyListValue.h>
#include <proxy/ProxyDictionaryValue.h>
#include <proxy/ProxyBrowserSettings.h>



//==========================================

extern "C"
void EDITIONF(ProxyBrowserSettings_Constructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	*pArgInf->m_ppCompoundData = NULL;
}

extern "C"
void EDITIONF(ProxyBrowserSettings_Destructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData) { return; }
	shrewd_ptr<ProxyBrowserSettings> ptr = (ProxyBrowserSettings*)*pArgInf->m_ppCompoundData;
	if(ptr){ ptr->release(); *pArgInf->m_ppCompoundData = NULL; }
}

extern "C"
void EDITIONF(ProxyBrowserSettings_CopyConstructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf[1].m_pCompoundData || NULL == *pArgInf[1].m_ppCompoundData) { return; }
	shrewd_ptr<ProxyBrowserSettings> ptr = (ProxyBrowserSettings*)*pArgInf[1].m_ppCompoundData;
	if(ptr){ ptr->retain(); *pArgInf->m_ppCompoundData = ptr.get(); }
	else { *pArgInf->m_ppCompoundData = NULL; }
}

extern "C"
void EDITIONF(ProxyBrowserSettings_Create) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	shrewd_ptr<ProxyBrowserSettings> result = ProxyBrowserSettings::Create();
	if(*pArgInf->m_ppCompoundData){
		((refcounted*)*pArgInf->m_ppCompoundData)->release();
	 }
	if(result){
		result->retain();
		*pArgInf->m_ppCompoundData = result.get();
	}
}

extern "C"
void EDITIONF(ProxyBrowserSettings_IsValid) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_bool = FALSE;
		return ;
	}
	shrewd_ptr<ProxyBrowserSettings> self = (ProxyBrowserSettings*)*pArgInf->m_ppCompoundData;
	pRetData->m_bool = self->IsValid();
}

extern "C"
void EDITIONF(ProxyBrowserSettings_SetWindowlessFrameRate) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyBrowserSettings> self = (ProxyBrowserSettings*)*pArgInf->m_ppCompoundData;
	int argWindowless_Frame_Rate = pArgInf[1].m_int;
	self->SetWindowlessFrameRate(argWindowless_Frame_Rate);
}

extern "C"
void EDITIONF(ProxyBrowserSettings_SetStandardFontFamily) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyBrowserSettings> self = (ProxyBrowserSettings*)*pArgInf->m_ppCompoundData;
	const char* argStandard_Font_Family = (NULL==pArgInf[1].m_pText || strlen(pArgInf[1].m_pText) <= 0) ? NULL : pArgInf[1].m_pText;
	self->SetStandardFontFamily(argStandard_Font_Family);
}

extern "C"
void EDITIONF(ProxyBrowserSettings_SetFixedFontFamily) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyBrowserSettings> self = (ProxyBrowserSettings*)*pArgInf->m_ppCompoundData;
	const char* argFixed_Font_Family = (NULL==pArgInf[1].m_pText || strlen(pArgInf[1].m_pText) <= 0) ? NULL : pArgInf[1].m_pText;
	self->SetFixedFontFamily(argFixed_Font_Family);
}

extern "C"
void EDITIONF(ProxyBrowserSettings_SetSerifFontFamily) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyBrowserSettings> self = (ProxyBrowserSettings*)*pArgInf->m_ppCompoundData;
	const char* argSerif_Font_Family = (NULL==pArgInf[1].m_pText || strlen(pArgInf[1].m_pText) <= 0) ? NULL : pArgInf[1].m_pText;
	self->SetSerifFontFamily(argSerif_Font_Family);
}

extern "C"
void EDITIONF(ProxyBrowserSettings_SetSansSerifFontFamily) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyBrowserSettings> self = (ProxyBrowserSettings*)*pArgInf->m_ppCompoundData;
	const char* argSans_Serif_Font_Family = (NULL==pArgInf[1].m_pText || strlen(pArgInf[1].m_pText) <= 0) ? NULL : pArgInf[1].m_pText;
	self->SetSansSerifFontFamily(argSans_Serif_Font_Family);
}

extern "C"
void EDITIONF(ProxyBrowserSettings_SetCursiveFontFamily) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyBrowserSettings> self = (ProxyBrowserSettings*)*pArgInf->m_ppCompoundData;
	const char* argCursive_Font_Family = (NULL==pArgInf[1].m_pText || strlen(pArgInf[1].m_pText) <= 0) ? NULL : pArgInf[1].m_pText;
	self->SetCursiveFontFamily(argCursive_Font_Family);
}

extern "C"
void EDITIONF(ProxyBrowserSettings_SetFantasyFontFamily) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyBrowserSettings> self = (ProxyBrowserSettings*)*pArgInf->m_ppCompoundData;
	const char* argFantasy_Font_Family = (NULL==pArgInf[1].m_pText || strlen(pArgInf[1].m_pText) <= 0) ? NULL : pArgInf[1].m_pText;
	self->SetFantasyFontFamily(argFantasy_Font_Family);
}

extern "C"
void EDITIONF(ProxyBrowserSettings_SetDefaultFontSize) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyBrowserSettings> self = (ProxyBrowserSettings*)*pArgInf->m_ppCompoundData;
	int argDefault_Font_Size = pArgInf[1].m_int;
	self->SetDefaultFontSize(argDefault_Font_Size);
}

extern "C"
void EDITIONF(ProxyBrowserSettings_SetDefaultFixedFontSize) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyBrowserSettings> self = (ProxyBrowserSettings*)*pArgInf->m_ppCompoundData;
	int argDefault_Fixed_Font_Size = pArgInf[1].m_int;
	self->SetDefaultFixedFontSize(argDefault_Fixed_Font_Size);
}

extern "C"
void EDITIONF(ProxyBrowserSettings_SetMinimumFontSize) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyBrowserSettings> self = (ProxyBrowserSettings*)*pArgInf->m_ppCompoundData;
	int argMinimum_Font_Size = pArgInf[1].m_int;
	self->SetMinimumFontSize(argMinimum_Font_Size);
}

extern "C"
void EDITIONF(ProxyBrowserSettings_SetMinimumLogicalFontSize) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyBrowserSettings> self = (ProxyBrowserSettings*)*pArgInf->m_ppCompoundData;
	int argMinimum_Logical_Font_Size = pArgInf[1].m_int;
	self->SetMinimumLogicalFontSize(argMinimum_Logical_Font_Size);
}

extern "C"
void EDITIONF(ProxyBrowserSettings_SetDefaultEncoding) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyBrowserSettings> self = (ProxyBrowserSettings*)*pArgInf->m_ppCompoundData;
	const char* argDefault_Encoding = (NULL==pArgInf[1].m_pText || strlen(pArgInf[1].m_pText) <= 0) ? NULL : pArgInf[1].m_pText;
	self->SetDefaultEncoding(argDefault_Encoding);
}

extern "C"
void EDITIONF(ProxyBrowserSettings_SetRemoteFonts) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyBrowserSettings> self = (ProxyBrowserSettings*)*pArgInf->m_ppCompoundData;
	int argRemote_Fonts = pArgInf[1].m_int;
	self->SetRemoteFonts(argRemote_Fonts);
}

extern "C"
void EDITIONF(ProxyBrowserSettings_SetJavascript) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyBrowserSettings> self = (ProxyBrowserSettings*)*pArgInf->m_ppCompoundData;
	int argJavascript = pArgInf[1].m_int;
	self->SetJavascript(argJavascript);
}

extern "C"
void EDITIONF(ProxyBrowserSettings_SetJavascriptCloseWindows) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyBrowserSettings> self = (ProxyBrowserSettings*)*pArgInf->m_ppCompoundData;
	int argJavascript_Close_Windows = pArgInf[1].m_int;
	self->SetJavascriptCloseWindows(argJavascript_Close_Windows);
}

extern "C"
void EDITIONF(ProxyBrowserSettings_SetJavascriptAccessClipboard) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyBrowserSettings> self = (ProxyBrowserSettings*)*pArgInf->m_ppCompoundData;
	int argJavascript_Access_Clipboard = pArgInf[1].m_int;
	self->SetJavascriptAccessClipboard(argJavascript_Access_Clipboard);
}

extern "C"
void EDITIONF(ProxyBrowserSettings_SetJavascriptDomPaste) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyBrowserSettings> self = (ProxyBrowserSettings*)*pArgInf->m_ppCompoundData;
	int argJavascript_Dom_Paste = pArgInf[1].m_int;
	self->SetJavascriptDomPaste(argJavascript_Dom_Paste);
}

extern "C"
void EDITIONF(ProxyBrowserSettings_SetPlugins) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyBrowserSettings> self = (ProxyBrowserSettings*)*pArgInf->m_ppCompoundData;
	int argPlugins = pArgInf[1].m_int;
	self->SetPlugins(argPlugins);
}

extern "C"
void EDITIONF(ProxyBrowserSettings_SetUniversalAccessFromFileUrls) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyBrowserSettings> self = (ProxyBrowserSettings*)*pArgInf->m_ppCompoundData;
	int argUniversal_Access_From_File_Urls = pArgInf[1].m_int;
	self->SetUniversalAccessFromFileUrls(argUniversal_Access_From_File_Urls);
}

extern "C"
void EDITIONF(ProxyBrowserSettings_SetFileAccessFromFileUrls) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyBrowserSettings> self = (ProxyBrowserSettings*)*pArgInf->m_ppCompoundData;
	int argFile_Access_From_File_Urls = pArgInf[1].m_int;
	self->SetFileAccessFromFileUrls(argFile_Access_From_File_Urls);
}

extern "C"
void EDITIONF(ProxyBrowserSettings_SetWebSecurity) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyBrowserSettings> self = (ProxyBrowserSettings*)*pArgInf->m_ppCompoundData;
	int argWeb_Security = pArgInf[1].m_int;
	self->SetWebSecurity(argWeb_Security);
}

extern "C"
void EDITIONF(ProxyBrowserSettings_SetImageLoading) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyBrowserSettings> self = (ProxyBrowserSettings*)*pArgInf->m_ppCompoundData;
	int argImage_Loading = pArgInf[1].m_int;
	self->SetImageLoading(argImage_Loading);
}

extern "C"
void EDITIONF(ProxyBrowserSettings_SetImageShrinkStandaloneToFit) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyBrowserSettings> self = (ProxyBrowserSettings*)*pArgInf->m_ppCompoundData;
	int argImage_Shrink_Standalone_To_Fit = pArgInf[1].m_int;
	self->SetImageShrinkStandaloneToFit(argImage_Shrink_Standalone_To_Fit);
}

extern "C"
void EDITIONF(ProxyBrowserSettings_SetTextAreaResize) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyBrowserSettings> self = (ProxyBrowserSettings*)*pArgInf->m_ppCompoundData;
	int argText_Area_Resize = pArgInf[1].m_int;
	self->SetTextAreaResize(argText_Area_Resize);
}

extern "C"
void EDITIONF(ProxyBrowserSettings_SetTabToLinks) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyBrowserSettings> self = (ProxyBrowserSettings*)*pArgInf->m_ppCompoundData;
	int argTab_To_Links = pArgInf[1].m_int;
	self->SetTabToLinks(argTab_To_Links);
}

extern "C"
void EDITIONF(ProxyBrowserSettings_SetLocalStorage) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyBrowserSettings> self = (ProxyBrowserSettings*)*pArgInf->m_ppCompoundData;
	int argLocal_Storage = pArgInf[1].m_int;
	self->SetLocalStorage(argLocal_Storage);
}

extern "C"
void EDITIONF(ProxyBrowserSettings_SetDatabases) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyBrowserSettings> self = (ProxyBrowserSettings*)*pArgInf->m_ppCompoundData;
	int argDatabases = pArgInf[1].m_int;
	self->SetDatabases(argDatabases);
}

extern "C"
void EDITIONF(ProxyBrowserSettings_SetApplicationCache) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyBrowserSettings> self = (ProxyBrowserSettings*)*pArgInf->m_ppCompoundData;
	int argApplication_Cache = pArgInf[1].m_int;
	self->SetApplicationCache(argApplication_Cache);
}

extern "C"
void EDITIONF(ProxyBrowserSettings_SetWebGL) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyBrowserSettings> self = (ProxyBrowserSettings*)*pArgInf->m_ppCompoundData;
	int argWebgl = pArgInf[1].m_int;
	self->SetWebGL(argWebgl);
}

extern "C"
void EDITIONF(ProxyBrowserSettings_SetBackgroundColor) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyBrowserSettings> self = (ProxyBrowserSettings*)*pArgInf->m_ppCompoundData;
	int argBackground_Color = pArgInf[1].m_int;
	self->SetBackgroundColor(argBackground_Color);
}

extern "C"
void EDITIONF(ProxyBrowserSettings_SetAcceptLanguageList) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyBrowserSettings> self = (ProxyBrowserSettings*)*pArgInf->m_ppCompoundData;
	const char* argAccept_Language_List = (NULL==pArgInf[1].m_pText || strlen(pArgInf[1].m_pText) <= 0) ? NULL : pArgInf[1].m_pText;
	self->SetAcceptLanguageList(argAccept_Language_List);
}



//==========================================

