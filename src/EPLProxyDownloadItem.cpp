#include "stdafx.h"
#include "EPLProxyDownloadItem.h"
#include <proxy/ProxyBrowser.h>
#include <proxy/ProxyFrame.h>
#include <proxy/ProxyRequest.h>
#include <proxy/ProxyResponse.h>
#include <proxy/proxyValue.h>
#include <proxy/proxyListValue.h>
#include <proxy/ProxyDictionaryValue.h>
#include <proxy/ProxyDOMNode.h>
#include <proxy/ProxyDownloadItem.h>



//==========================================

extern "C"
void EDITIONF(ProxyDownloadItem_Constructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	*pArgInf->m_ppCompoundData = NULL;
}

extern "C"
void EDITIONF(ProxyDownloadItem_Destructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData) { return; }
	shrewd_ptr<ProxyDownloadItem> ptr = (ProxyDownloadItem*)*pArgInf->m_ppCompoundData;
	if(ptr){ ptr->release(); *pArgInf->m_ppCompoundData = NULL; }
}

extern "C"
void EDITIONF(ProxyDownloadItem_CopyConstructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf[1].m_pCompoundData || NULL == *pArgInf[1].m_ppCompoundData) { return; }
	shrewd_ptr<ProxyDownloadItem> ptr = (ProxyDownloadItem*)*pArgInf[1].m_ppCompoundData;
	if(ptr){ ptr->retain(); *pArgInf->m_ppCompoundData = ptr.get(); }
	else { *pArgInf->m_ppCompoundData = NULL; }
}

extern "C"
void EDITIONF(ProxyDownloadItem_IsValid) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_bool = FALSE;
		return ;
	}
	shrewd_ptr<ProxyDownloadItem> self = (ProxyDownloadItem*)*pArgInf->m_ppCompoundData;
	pRetData->m_bool = self->IsValid();
}

extern "C"
void EDITIONF(ProxyDownloadItem_IsInProgress) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_bool = FALSE;
		return ;
	}
	shrewd_ptr<ProxyDownloadItem> self = (ProxyDownloadItem*)*pArgInf->m_ppCompoundData;
	pRetData->m_bool = self->IsInProgress();
}

extern "C"
void EDITIONF(ProxyDownloadItem_IsComplete) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_bool = FALSE;
		return ;
	}
	shrewd_ptr<ProxyDownloadItem> self = (ProxyDownloadItem*)*pArgInf->m_ppCompoundData;
	pRetData->m_bool = self->IsComplete();
}

extern "C"
void EDITIONF(ProxyDownloadItem_IsCanceled) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_bool = FALSE;
		return ;
	}
	shrewd_ptr<ProxyDownloadItem> self = (ProxyDownloadItem*)*pArgInf->m_ppCompoundData;
	pRetData->m_bool = self->IsCanceled();
}

extern "C"
void EDITIONF(ProxyDownloadItem_GetCurrentSpeed) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_int64 = 0;
		return ;
	}
	shrewd_ptr<ProxyDownloadItem> self = (ProxyDownloadItem*)*pArgInf->m_ppCompoundData;
	pRetData->m_int64 = self->GetCurrentSpeed();
}

extern "C"
void EDITIONF(ProxyDownloadItem_GetPercentComplete) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_int = 0;
		return ;
	}
	shrewd_ptr<ProxyDownloadItem> self = (ProxyDownloadItem*)*pArgInf->m_ppCompoundData;
	pRetData->m_int = self->GetPercentComplete();
}

extern "C"
void EDITIONF(ProxyDownloadItem_GetTotalBytes) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_int64 = 0;
		return ;
	}
	shrewd_ptr<ProxyDownloadItem> self = (ProxyDownloadItem*)*pArgInf->m_ppCompoundData;
	pRetData->m_int64 = self->GetTotalBytes();
}

extern "C"
void EDITIONF(ProxyDownloadItem_GetReceivedBytes) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_int64 = 0;
		return ;
	}
	shrewd_ptr<ProxyDownloadItem> self = (ProxyDownloadItem*)*pArgInf->m_ppCompoundData;
	pRetData->m_int64 = self->GetReceivedBytes();
}

extern "C"
void EDITIONF(ProxyDownloadItem_GetStartTime) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_double = 0.0f;
		return ;
	}
	shrewd_ptr<ProxyDownloadItem> self = (ProxyDownloadItem*)*pArgInf->m_ppCompoundData;
	pRetData->m_double = self->GetStartTime();
}

extern "C"
void EDITIONF(ProxyDownloadItem_GetEndTime) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_double = 0.0f;
		return ;
	}
	shrewd_ptr<ProxyDownloadItem> self = (ProxyDownloadItem*)*pArgInf->m_ppCompoundData;
	pRetData->m_double = self->GetEndTime();
}

extern "C"
void EDITIONF(ProxyDownloadItem_GetFullPath) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_pText = NULL;
		return ;
	}
	shrewd_ptr<ProxyDownloadItem> self = (ProxyDownloadItem*)*pArgInf->m_ppCompoundData;
	pRetData->m_pText = self->GetFullPath();
}

extern "C"
void EDITIONF(ProxyDownloadItem_GetId) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_int = 0;
		return ;
	}
	shrewd_ptr<ProxyDownloadItem> self = (ProxyDownloadItem*)*pArgInf->m_ppCompoundData;
	pRetData->m_int = self->GetId();
}

extern "C"
void EDITIONF(ProxyDownloadItem_GetURL) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_pText = NULL;
		return ;
	}
	shrewd_ptr<ProxyDownloadItem> self = (ProxyDownloadItem*)*pArgInf->m_ppCompoundData;
	pRetData->m_pText = self->GetURL();
}

extern "C"
void EDITIONF(ProxyDownloadItem_GetOriginalUrl) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_pText = NULL;
		return ;
	}
	shrewd_ptr<ProxyDownloadItem> self = (ProxyDownloadItem*)*pArgInf->m_ppCompoundData;
	pRetData->m_pText = self->GetOriginalUrl();
}

extern "C"
void EDITIONF(ProxyDownloadItem_GetSuggestedFileName) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_pText = NULL;
		return ;
	}
	shrewd_ptr<ProxyDownloadItem> self = (ProxyDownloadItem*)*pArgInf->m_ppCompoundData;
	pRetData->m_pText = self->GetSuggestedFileName();
}

extern "C"
void EDITIONF(ProxyDownloadItem_GetContentDisposition) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_pText = NULL;
		return ;
	}
	shrewd_ptr<ProxyDownloadItem> self = (ProxyDownloadItem*)*pArgInf->m_ppCompoundData;
	pRetData->m_pText = self->GetContentDisposition();
}

extern "C"
void EDITIONF(ProxyDownloadItem_GetMimeType) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_pText = NULL;
		return ;
	}
	shrewd_ptr<ProxyDownloadItem> self = (ProxyDownloadItem*)*pArgInf->m_ppCompoundData;
	pRetData->m_pText = self->GetMimeType();
}

extern "C"
void EDITIONF(ProxyDownloadItem_SaveTo) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyDownloadItem> self = (ProxyDownloadItem*)*pArgInf->m_ppCompoundData;
	const char* argDownload_Path = (NULL==pArgInf[1].m_pText || strlen(pArgInf[1].m_pText) <= 0) ? NULL : pArgInf[1].m_pText;
	bool argShow_Dialog = pArgInf[2].m_bool;
	self->SaveTo(argDownload_Path,argShow_Dialog);
}

extern "C"
void EDITIONF(ProxyDownloadItem_CancelDownload) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyDownloadItem> self = (ProxyDownloadItem*)*pArgInf->m_ppCompoundData;
	self->CancelDownload();
}

extern "C"
void EDITIONF(ProxyDownloadItem_PauseDownload) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyDownloadItem> self = (ProxyDownloadItem*)*pArgInf->m_ppCompoundData;
	self->PauseDownload();
}

extern "C"
void EDITIONF(ProxyDownloadItem_ResumeDownload) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyDownloadItem> self = (ProxyDownloadItem*)*pArgInf->m_ppCompoundData;
	self->ResumeDownload();
}



//==========================================

