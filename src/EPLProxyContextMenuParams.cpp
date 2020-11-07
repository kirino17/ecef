#include "stdafx.h"
#include "EPLProxyContextMenuParams.h"
#include <proxy/ProxyBrowser.h>
#include <proxy/ProxyFrame.h>
#include <proxy/ProxyRequest.h>
#include <proxy/ProxyResponse.h>
#include <proxy/proxyValue.h>
#include <proxy/proxyListValue.h>
#include <proxy/ProxyDictionaryValue.h>
#include <proxy/ProxyDOMNode.h>
#include <proxy/ProxyContextMenuParams.h>



//==========================================

extern "C"
void EDITIONF(ProxyContextMenuParams_Constructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	*pArgInf->m_ppCompoundData = NULL;
}

extern "C"
void EDITIONF(ProxyContextMenuParams_Destructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData) { return; }
	shrewd_ptr<ProxyContextMenuParams> ptr = (ProxyContextMenuParams*)*pArgInf->m_ppCompoundData;
	if(ptr){ ptr->release(); *pArgInf->m_ppCompoundData = NULL; }
}

extern "C"
void EDITIONF(ProxyContextMenuParams_CopyConstructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf[1].m_pCompoundData || NULL == *pArgInf[1].m_ppCompoundData) { return; }
	shrewd_ptr<ProxyContextMenuParams> ptr = (ProxyContextMenuParams*)*pArgInf[1].m_ppCompoundData;
	if(ptr){ ptr->retain(); *pArgInf->m_ppCompoundData = ptr.get(); }
	else { *pArgInf->m_ppCompoundData = NULL; }
}

extern "C"
void EDITIONF(ProxyContextMenuParams_GetXCoord) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_int = 0;
		return ;
	}
	shrewd_ptr<ProxyContextMenuParams> self = (ProxyContextMenuParams*)*pArgInf->m_ppCompoundData;
	pRetData->m_int = self->GetXCoord();
}

extern "C"
void EDITIONF(ProxyContextMenuParams_GetYCoord) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_int = 0;
		return ;
	}
	shrewd_ptr<ProxyContextMenuParams> self = (ProxyContextMenuParams*)*pArgInf->m_ppCompoundData;
	pRetData->m_int = self->GetYCoord();
}

extern "C"
void EDITIONF(ProxyContextMenuParams_GetTypeFlags) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_int = 0;
		return ;
	}
	shrewd_ptr<ProxyContextMenuParams> self = (ProxyContextMenuParams*)*pArgInf->m_ppCompoundData;
	pRetData->m_int = self->GetTypeFlags();
}

extern "C"
void EDITIONF(ProxyContextMenuParams_GetLinkUrl) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_pText = NULL;
		return ;
	}
	shrewd_ptr<ProxyContextMenuParams> self = (ProxyContextMenuParams*)*pArgInf->m_ppCompoundData;
	pRetData->m_pText = self->GetLinkUrl();
}

extern "C"
void EDITIONF(ProxyContextMenuParams_GetUnfilteredLinkUrl) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_pText = NULL;
		return ;
	}
	shrewd_ptr<ProxyContextMenuParams> self = (ProxyContextMenuParams*)*pArgInf->m_ppCompoundData;
	pRetData->m_pText = self->GetUnfilteredLinkUrl();
}

extern "C"
void EDITIONF(ProxyContextMenuParams_GetSourceUrl) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_pText = NULL;
		return ;
	}
	shrewd_ptr<ProxyContextMenuParams> self = (ProxyContextMenuParams*)*pArgInf->m_ppCompoundData;
	pRetData->m_pText = self->GetSourceUrl();
}

extern "C"
void EDITIONF(ProxyContextMenuParams_HasImageContents) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_bool = FALSE;
		return ;
	}
	shrewd_ptr<ProxyContextMenuParams> self = (ProxyContextMenuParams*)*pArgInf->m_ppCompoundData;
	pRetData->m_bool = self->HasImageContents();
}

extern "C"
void EDITIONF(ProxyContextMenuParams_GetTitleText) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_pText = NULL;
		return ;
	}
	shrewd_ptr<ProxyContextMenuParams> self = (ProxyContextMenuParams*)*pArgInf->m_ppCompoundData;
	pRetData->m_pText = self->GetTitleText();
}

extern "C"
void EDITIONF(ProxyContextMenuParams_GetPageUrl) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_pText = NULL;
		return ;
	}
	shrewd_ptr<ProxyContextMenuParams> self = (ProxyContextMenuParams*)*pArgInf->m_ppCompoundData;
	pRetData->m_pText = self->GetPageUrl();
}

extern "C"
void EDITIONF(ProxyContextMenuParams_GetFrameUrl) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_pText = NULL;
		return ;
	}
	shrewd_ptr<ProxyContextMenuParams> self = (ProxyContextMenuParams*)*pArgInf->m_ppCompoundData;
	pRetData->m_pText = self->GetFrameUrl();
}

extern "C"
void EDITIONF(ProxyContextMenuParams_GetFrameCharset) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_pText = NULL;
		return ;
	}
	shrewd_ptr<ProxyContextMenuParams> self = (ProxyContextMenuParams*)*pArgInf->m_ppCompoundData;
	pRetData->m_pText = self->GetFrameCharset();
}

extern "C"
void EDITIONF(ProxyContextMenuParams_GetMediaType) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_int = 0;
		return ;
	}
	shrewd_ptr<ProxyContextMenuParams> self = (ProxyContextMenuParams*)*pArgInf->m_ppCompoundData;
	pRetData->m_int = self->GetMediaType();
}

extern "C"
void EDITIONF(ProxyContextMenuParams_GetMediaStateFlags) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_int = 0;
		return ;
	}
	shrewd_ptr<ProxyContextMenuParams> self = (ProxyContextMenuParams*)*pArgInf->m_ppCompoundData;
	pRetData->m_int = self->GetMediaStateFlags();
}

extern "C"
void EDITIONF(ProxyContextMenuParams_GetSelectionText) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_pText = NULL;
		return ;
	}
	shrewd_ptr<ProxyContextMenuParams> self = (ProxyContextMenuParams*)*pArgInf->m_ppCompoundData;
	pRetData->m_pText = self->GetSelectionText();
}

extern "C"
void EDITIONF(ProxyContextMenuParams_GetMisspelledWord) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_pText = NULL;
		return ;
	}
	shrewd_ptr<ProxyContextMenuParams> self = (ProxyContextMenuParams*)*pArgInf->m_ppCompoundData;
	pRetData->m_pText = self->GetMisspelledWord();
}

extern "C"
void EDITIONF(ProxyContextMenuParams_GetDictionarySuggestions) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		DWORD* InternalPointer = (DWORD*)NotifySys(NRS_MALLOC, 8, 0);
		InternalPointer[0] = 1;
		InternalPointer[1] = 0;
		pRetData->m_pCompoundData = InternalPointer;
		return ;
	}
	shrewd_ptr<ProxyContextMenuParams> self = (ProxyContextMenuParams*)*pArgInf->m_ppCompoundData;
	pRetData->m_pCompoundData = (void*)self->GetDictionarySuggestions();
}

extern "C"
void EDITIONF(ProxyContextMenuParams_IsEditable) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_bool = FALSE;
		return ;
	}
	shrewd_ptr<ProxyContextMenuParams> self = (ProxyContextMenuParams*)*pArgInf->m_ppCompoundData;
	pRetData->m_bool = self->IsEditable();
}

extern "C"
void EDITIONF(ProxyContextMenuParams_IsSpellCheckEnabled) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_bool = FALSE;
		return ;
	}
	shrewd_ptr<ProxyContextMenuParams> self = (ProxyContextMenuParams*)*pArgInf->m_ppCompoundData;
	pRetData->m_bool = self->IsSpellCheckEnabled();
}

extern "C"
void EDITIONF(ProxyContextMenuParams_GetEditStateFlags) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_int = 0;
		return ;
	}
	shrewd_ptr<ProxyContextMenuParams> self = (ProxyContextMenuParams*)*pArgInf->m_ppCompoundData;
	pRetData->m_int = self->GetEditStateFlags();
}

extern "C"
void EDITIONF(ProxyContextMenuParams_IsCustomMenu) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_bool = FALSE;
		return ;
	}
	shrewd_ptr<ProxyContextMenuParams> self = (ProxyContextMenuParams*)*pArgInf->m_ppCompoundData;
	pRetData->m_bool = self->IsCustomMenu();
}

extern "C"
void EDITIONF(ProxyContextMenuParams_IsPepperMenu) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_bool = FALSE;
		return ;
	}
	shrewd_ptr<ProxyContextMenuParams> self = (ProxyContextMenuParams*)*pArgInf->m_ppCompoundData;
	pRetData->m_bool = self->IsPepperMenu();
}



//==========================================

