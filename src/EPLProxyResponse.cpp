#include "stdafx.h"
#include "EPLProxyResponse.h"
#include <proxy/ProxyBrowser.h>
#include <proxy/ProxyFrame.h>
#include <proxy/ProxyRequest.h>
#include <proxy/ProxyResponse.h>
#include <proxy/proxyValue.h>
#include <proxy/proxyListValue.h>
#include <proxy/ProxyDictionaryValue.h>
#include <proxy/ProxyDOMNode.h>
#include <proxy/ProxyResponse.h>



//==========================================

extern "C"
void EDITIONF(ProxyResponse_Constructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	*pArgInf->m_ppCompoundData = NULL;
}

extern "C"
void EDITIONF(ProxyResponse_Destructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData) { return; }
	shrewd_ptr<ProxyResponse> ptr = (ProxyResponse*)*pArgInf->m_ppCompoundData;
	if(ptr){ ptr->release(); *pArgInf->m_ppCompoundData = NULL; }
}

extern "C"
void EDITIONF(ProxyResponse_CopyConstructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf[1].m_pCompoundData || NULL == *pArgInf[1].m_ppCompoundData) { return; }
	shrewd_ptr<ProxyResponse> ptr = (ProxyResponse*)*pArgInf[1].m_ppCompoundData;
	if(ptr){ ptr->retain(); *pArgInf->m_ppCompoundData = ptr.get(); }
	else { *pArgInf->m_ppCompoundData = NULL; }
}

extern "C"
void EDITIONF(ProxyResponse_IsValid) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_bool = FALSE;
		return ;
	}
	shrewd_ptr<ProxyResponse> self = (ProxyResponse*)*pArgInf->m_ppCompoundData;
	pRetData->m_bool = self->IsValid();
}

extern "C"
void EDITIONF(ProxyResponse_IsReadOnly) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_bool = FALSE;
		return ;
	}
	shrewd_ptr<ProxyResponse> self = (ProxyResponse*)*pArgInf->m_ppCompoundData;
	pRetData->m_bool = self->IsReadOnly();
}

extern "C"
void EDITIONF(ProxyResponse_GetError) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_int = 0;
		return ;
	}
	shrewd_ptr<ProxyResponse> self = (ProxyResponse*)*pArgInf->m_ppCompoundData;
	pRetData->m_int = self->GetError();
}

extern "C"
void EDITIONF(ProxyResponse_SetError) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyResponse> self = (ProxyResponse*)*pArgInf->m_ppCompoundData;
	int argError = pArgInf[1].m_int;
	self->SetError(argError);
}

extern "C"
void EDITIONF(ProxyResponse_GetStatus) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_int = 0;
		return ;
	}
	shrewd_ptr<ProxyResponse> self = (ProxyResponse*)*pArgInf->m_ppCompoundData;
	pRetData->m_int = self->GetStatus();
}

extern "C"
void EDITIONF(ProxyResponse_SetStatus) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyResponse> self = (ProxyResponse*)*pArgInf->m_ppCompoundData;
	int argStatus = pArgInf[1].m_int;
	self->SetStatus(argStatus);
}

extern "C"
void EDITIONF(ProxyResponse_GetStatusText) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_pText = NULL;
		return ;
	}
	shrewd_ptr<ProxyResponse> self = (ProxyResponse*)*pArgInf->m_ppCompoundData;
	pRetData->m_pText = self->GetStatusText();
}

extern "C"
void EDITIONF(ProxyResponse_SetStatusText) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyResponse> self = (ProxyResponse*)*pArgInf->m_ppCompoundData;
	const char* argStatustext = (NULL==pArgInf[1].m_pText || strlen(pArgInf[1].m_pText) <= 0) ? NULL : pArgInf[1].m_pText;
	self->SetStatusText(argStatustext);
}

extern "C"
void EDITIONF(ProxyResponse_GetMimeType) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_pText = NULL;
		return ;
	}
	shrewd_ptr<ProxyResponse> self = (ProxyResponse*)*pArgInf->m_ppCompoundData;
	pRetData->m_pText = self->GetMimeType();
}

extern "C"
void EDITIONF(ProxyResponse_SetMimeType) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyResponse> self = (ProxyResponse*)*pArgInf->m_ppCompoundData;
	const char* argMimetype = (NULL==pArgInf[1].m_pText || strlen(pArgInf[1].m_pText) <= 0) ? NULL : pArgInf[1].m_pText;
	self->SetMimeType(argMimetype);
}

extern "C"
void EDITIONF(ProxyResponse_GetCharset) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_pText = NULL;
		return ;
	}
	shrewd_ptr<ProxyResponse> self = (ProxyResponse*)*pArgInf->m_ppCompoundData;
	pRetData->m_pText = self->GetCharset();
}

extern "C"
void EDITIONF(ProxyResponse_SetCharset) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyResponse> self = (ProxyResponse*)*pArgInf->m_ppCompoundData;
	const char* argCharset = (NULL==pArgInf[1].m_pText || strlen(pArgInf[1].m_pText) <= 0) ? NULL : pArgInf[1].m_pText;
	self->SetCharset(argCharset);
}

extern "C"
void EDITIONF(ProxyResponse_GetHeaderByName) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_pText = NULL;
		return ;
	}
	shrewd_ptr<ProxyResponse> self = (ProxyResponse*)*pArgInf->m_ppCompoundData;
	const char* argName = (NULL==pArgInf[1].m_pText || strlen(pArgInf[1].m_pText) <= 0) ? NULL : pArgInf[1].m_pText;
	pRetData->m_pText = self->GetHeaderByName(argName);
}

extern "C"
void EDITIONF(ProxyResponse_SetHeaderByName) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyResponse> self = (ProxyResponse*)*pArgInf->m_ppCompoundData;
	const char* argName = (NULL==pArgInf[1].m_pText || strlen(pArgInf[1].m_pText) <= 0) ? NULL : pArgInf[1].m_pText;
	const char* argValue = (NULL==pArgInf[2].m_pText || strlen(pArgInf[2].m_pText) <= 0) ? NULL : pArgInf[2].m_pText;
	bool argOverwrite = pArgInf[3].m_bool;
	self->SetHeaderByName(argName,argValue,argOverwrite);
}

extern "C"
void EDITIONF(ProxyResponse_GetHeaderMap) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		DWORD* InternalPointer = (DWORD*)NotifySys(NRS_MALLOC, 8, 0);
		InternalPointer[0] = 1;
		InternalPointer[1] = 0;
		pRetData->m_pCompoundData = InternalPointer;
		return ;
	}
	shrewd_ptr<ProxyResponse> self = (ProxyResponse*)*pArgInf->m_ppCompoundData;
	pRetData->m_pCompoundData = (void*)self->GetHeaderMap();
}

extern "C"
void EDITIONF(ProxyResponse_SetHeaderMap) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyResponse> self = (ProxyResponse*)*pArgInf->m_ppCompoundData;
	const char* argHeadermap = (NULL==pArgInf[1].m_pText || strlen(pArgInf[1].m_pText) <= 0) ? NULL : pArgInf[1].m_pText;
	self->SetHeaderMap(argHeadermap);
}

extern "C"
void EDITIONF(ProxyResponse_GetURL) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_pText = NULL;
		return ;
	}
	shrewd_ptr<ProxyResponse> self = (ProxyResponse*)*pArgInf->m_ppCompoundData;
	pRetData->m_pText = self->GetURL();
}

extern "C"
void EDITIONF(ProxyResponse_SetURL) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyResponse> self = (ProxyResponse*)*pArgInf->m_ppCompoundData;
	const char* argUrl = (NULL==pArgInf[1].m_pText || strlen(pArgInf[1].m_pText) <= 0) ? NULL : pArgInf[1].m_pText;
	self->SetURL(argUrl);
}



//==========================================

