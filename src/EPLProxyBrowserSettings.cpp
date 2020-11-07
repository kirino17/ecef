#include "stdafx.h"
#include "EPLProxyBrowserSettings.h"
#include <proxy/ProxyBrowser.h>
#include <proxy/ProxyFrame.h>
#include <proxy/ProxyRequest.h>
#include <proxy/ProxyResponse.h>
#include <proxy/proxyValue.h>
#include <proxy/proxyListValue.h>
#include <proxy/ProxyDictionaryValue.h>
#include <proxy/ProxyDOMNode.h>
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
void EDITIONF(ProxyBrowserSettings_IsValid) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_bool = FALSE;
		return ;
	}
	shrewd_ptr<ProxyBrowserSettings> self = (ProxyBrowserSettings*)*pArgInf->m_ppCompoundData;
	pRetData->m_bool = self->IsValid();
}

extern "C"
void EDITIONF(ProxyBrowserSettings_SetStandardFontFamily) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyBrowserSettings> self = (ProxyBrowserSettings*)*pArgInf->m_ppCompoundData;
	const char* argFont_Family = (NULL==pArgInf[1].m_pText || strlen(pArgInf[1].m_pText) <= 0) ? NULL : pArgInf[1].m_pText;
	self->SetStandardFontFamily(argFont_Family);
}

extern "C"
void EDITIONF(ProxyBrowserSettings_SetFixedFontFamily) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyBrowserSettings> self = (ProxyBrowserSettings*)*pArgInf->m_ppCompoundData;
	const char* argFont_Family = (NULL==pArgInf[1].m_pText || strlen(pArgInf[1].m_pText) <= 0) ? NULL : pArgInf[1].m_pText;
	self->SetFixedFontFamily(argFont_Family);
}

extern "C"
void EDITIONF(ProxyBrowserSettings_SetSerifFontFamily) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyBrowserSettings> self = (ProxyBrowserSettings*)*pArgInf->m_ppCompoundData;
	const char* argFont_Family = (NULL==pArgInf[1].m_pText || strlen(pArgInf[1].m_pText) <= 0) ? NULL : pArgInf[1].m_pText;
	self->SetSerifFontFamily(argFont_Family);
}

extern "C"
void EDITIONF(ProxyBrowserSettings_SetSansSerifFontFamily) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyBrowserSettings> self = (ProxyBrowserSettings*)*pArgInf->m_ppCompoundData;
	const char* argFont_Family = (NULL==pArgInf[1].m_pText || strlen(pArgInf[1].m_pText) <= 0) ? NULL : pArgInf[1].m_pText;
	self->SetSansSerifFontFamily(argFont_Family);
}

extern "C"
void EDITIONF(ProxyBrowserSettings_SetCursiveFontFamily) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyBrowserSettings> self = (ProxyBrowserSettings*)*pArgInf->m_ppCompoundData;
	const char* argFont_Family = (NULL==pArgInf[1].m_pText || strlen(pArgInf[1].m_pText) <= 0) ? NULL : pArgInf[1].m_pText;
	self->SetCursiveFontFamily(argFont_Family);
}

extern "C"
void EDITIONF(ProxyBrowserSettings_SetFantasyFontFamily) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyBrowserSettings> self = (ProxyBrowserSettings*)*pArgInf->m_ppCompoundData;
	const char* argFont_Family = (NULL==pArgInf[1].m_pText || strlen(pArgInf[1].m_pText) <= 0) ? NULL : pArgInf[1].m_pText;
	self->SetFantasyFontFamily(argFont_Family);
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
	int argValue = pArgInf[1].m_int;
	self->SetJavascript(argValue);
}

extern "C"
void EDITIONF(ProxyBrowserSettings_SetJavascriptCloseWindow) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyBrowserSettings> self = (ProxyBrowserSettings*)*pArgInf->m_ppCompoundData;
	int argValue = pArgInf[1].m_int;
	self->SetJavascriptCloseWindow(argValue);
}

extern "C"
void EDITIONF(ProxyBrowserSettings_SetJavascriptAccessClipboard) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyBrowserSettings> self = (ProxyBrowserSettings*)*pArgInf->m_ppCompoundData;
	int argValue = pArgInf[1].m_int;
	self->SetJavascriptAccessClipboard(argValue);
}

extern "C"
void EDITIONF(ProxyBrowserSettings_SetJavascriptDomPaste) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyBrowserSettings> self = (ProxyBrowserSettings*)*pArgInf->m_ppCompoundData;
	int argValue = pArgInf[1].m_int;
	self->SetJavascriptDomPaste(argValue);
}

extern "C"
void EDITIONF(ProxyBrowserSettings_SetPlugins) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyBrowserSettings> self = (ProxyBrowserSettings*)*pArgInf->m_ppCompoundData;
	int argValue = pArgInf[1].m_int;
	self->SetPlugins(argValue);
}

extern "C"
void EDITIONF(ProxyBrowserSettings_SetUniversalAccessFromFileUrls) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyBrowserSettings> self = (ProxyBrowserSettings*)*pArgInf->m_ppCompoundData;
	int argValue = pArgInf[1].m_int;
	self->SetUniversalAccessFromFileUrls(argValue);
}

extern "C"
void EDITIONF(ProxyBrowserSettings_SetFileAccessFromFileUrls) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyBrowserSettings> self = (ProxyBrowserSettings*)*pArgInf->m_ppCompoundData;
	int argValue = pArgInf[1].m_int;
	self->SetFileAccessFromFileUrls(argValue);
}

extern "C"
void EDITIONF(ProxyBrowserSettings_SetWebSecurity) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyBrowserSettings> self = (ProxyBrowserSettings*)*pArgInf->m_ppCompoundData;
	int argValue = pArgInf[1].m_int;
	self->SetWebSecurity(argValue);
}

extern "C"
void EDITIONF(ProxyBrowserSettings_SetImageLoading) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyBrowserSettings> self = (ProxyBrowserSettings*)*pArgInf->m_ppCompoundData;
	int argValue = pArgInf[1].m_int;
	self->SetImageLoading(argValue);
}

extern "C"
void EDITIONF(ProxyBrowserSettings_SetImageShrinkStandaloneToFit) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyBrowserSettings> self = (ProxyBrowserSettings*)*pArgInf->m_ppCompoundData;
	int argValue = pArgInf[1].m_int;
	self->SetImageShrinkStandaloneToFit(argValue);
}

extern "C"
void EDITIONF(ProxyBrowserSettings_SetTextAreaResize) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyBrowserSettings> self = (ProxyBrowserSettings*)*pArgInf->m_ppCompoundData;
	int argValue = pArgInf[1].m_int;
	self->SetTextAreaResize(argValue);
}

extern "C"
void EDITIONF(ProxyBrowserSettings_SetTabToLinks) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyBrowserSettings> self = (ProxyBrowserSettings*)*pArgInf->m_ppCompoundData;
	int argValue = pArgInf[1].m_int;
	self->SetTabToLinks(argValue);
}

extern "C"
void EDITIONF(ProxyBrowserSettings_SetLocalStorage) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyBrowserSettings> self = (ProxyBrowserSettings*)*pArgInf->m_ppCompoundData;
	int argValue = pArgInf[1].m_int;
	self->SetLocalStorage(argValue);
}

extern "C"
void EDITIONF(ProxyBrowserSettings_SetDataBase) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyBrowserSettings> self = (ProxyBrowserSettings*)*pArgInf->m_ppCompoundData;
	int argValue = pArgInf[1].m_int;
	self->SetDataBase(argValue);
}

extern "C"
void EDITIONF(ProxyBrowserSettings_SetApplicationCache) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyBrowserSettings> self = (ProxyBrowserSettings*)*pArgInf->m_ppCompoundData;
	int argValue = pArgInf[1].m_int;
	self->SetApplicationCache(argValue);
}

extern "C"
void EDITIONF(ProxyBrowserSettings_SetWebGL) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyBrowserSettings> self = (ProxyBrowserSettings*)*pArgInf->m_ppCompoundData;
	int argValue = pArgInf[1].m_int;
	self->SetWebGL(argValue);
}

extern "C"
void EDITIONF(ProxyBrowserSettings_SetBackgroundColor) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyBrowserSettings> self = (ProxyBrowserSettings*)*pArgInf->m_ppCompoundData;
	int argColor = pArgInf[1].m_int;
	self->SetBackgroundColor(argColor);
}

extern "C"
void EDITIONF(ProxyBrowserSettings_SetAcceptLanguageList) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyBrowserSettings> self = (ProxyBrowserSettings*)*pArgInf->m_ppCompoundData;
	const char* argValues = (NULL==pArgInf[1].m_pText || strlen(pArgInf[1].m_pText) <= 0) ? NULL : pArgInf[1].m_pText;
	self->SetAcceptLanguageList(argValues);
}



//==========================================

