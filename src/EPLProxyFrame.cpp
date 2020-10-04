#include "stdafx.h"
#include "EPLProxyFrame.h"
#include <proxy/ProxyBrowser.h>
#include <proxy/ProxyBrowserHost.h>
#include <proxy/ProxyFrame.h>
#include <proxy/ProxyRequest.h>
#include <proxy/ProxyResponse.h>
#include <proxy/proxyValue.h>
#include <proxy/proxyListValue.h>
#include <proxy/ProxyDictionaryValue.h>
#include <proxy/ProxyFrame.h>



//==========================================

extern "C"
void EDITIONF(ProxyFrame_Constructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	*pArgInf->m_ppCompoundData = NULL;
}

extern "C"
void EDITIONF(ProxyFrame_Destructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData) { return; }
	shrewd_ptr<ProxyFrame> ptr = (ProxyFrame*)*pArgInf->m_ppCompoundData;
	if(ptr){ ptr->release(); *pArgInf->m_ppCompoundData = NULL; }
}

extern "C"
void EDITIONF(ProxyFrame_CopyConstructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf[1].m_pCompoundData || NULL == *pArgInf[1].m_ppCompoundData) { return; }
	shrewd_ptr<ProxyFrame> ptr = (ProxyFrame*)*pArgInf[1].m_ppCompoundData;
	if(ptr){ ptr->retain(); *pArgInf->m_ppCompoundData = ptr.get(); }
	else { *pArgInf->m_ppCompoundData = NULL; }
}

extern "C"
void EDITIONF(ProxyFrame_IsValid) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_bool = FALSE;
		return ;
	}
	shrewd_ptr<ProxyFrame> self = (ProxyFrame*)*pArgInf->m_ppCompoundData;
	pRetData->m_bool = self->IsValid();
}

extern "C"
void EDITIONF(ProxyFrame_Undo) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyFrame> self = (ProxyFrame*)*pArgInf->m_ppCompoundData;
	self->Undo();
}

extern "C"
void EDITIONF(ProxyFrame_Redo) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyFrame> self = (ProxyFrame*)*pArgInf->m_ppCompoundData;
	self->Redo();
}

extern "C"
void EDITIONF(ProxyFrame_Cut) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyFrame> self = (ProxyFrame*)*pArgInf->m_ppCompoundData;
	self->Cut();
}

extern "C"
void EDITIONF(ProxyFrame_Copy) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyFrame> self = (ProxyFrame*)*pArgInf->m_ppCompoundData;
	self->Copy();
}

extern "C"
void EDITIONF(ProxyFrame_Paste) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyFrame> self = (ProxyFrame*)*pArgInf->m_ppCompoundData;
	self->Paste();
}

extern "C"
void EDITIONF(ProxyFrame_Delete) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyFrame> self = (ProxyFrame*)*pArgInf->m_ppCompoundData;
	self->Delete();
}

extern "C"
void EDITIONF(ProxyFrame_SelectAll) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyFrame> self = (ProxyFrame*)*pArgInf->m_ppCompoundData;
	self->SelectAll();
}

extern "C"
void EDITIONF(ProxyFrame_ViewSource) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyFrame> self = (ProxyFrame*)*pArgInf->m_ppCompoundData;
	self->ViewSource();
}

extern "C"
void EDITIONF(ProxyFrame_GetSource) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_pText = NULL;
		return ;
	}
	shrewd_ptr<ProxyFrame> self = (ProxyFrame*)*pArgInf->m_ppCompoundData;
	pRetData->m_pText = self->GetSource();
}

extern "C"
void EDITIONF(ProxyFrame_GetText) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_pText = NULL;
		return ;
	}
	shrewd_ptr<ProxyFrame> self = (ProxyFrame*)*pArgInf->m_ppCompoundData;
	pRetData->m_pText = self->GetText();
}

extern "C"
void EDITIONF(ProxyFrame_LoadRequest) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyFrame> self = (ProxyFrame*)*pArgInf->m_ppCompoundData;
	shrewd_ptr<ProxyRequest> argRequest = (ProxyRequest*)*pArgInf[1].m_ppCompoundData;
	self->LoadRequest(argRequest);
}

extern "C"
void EDITIONF(ProxyFrame_LoadURL) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyFrame> self = (ProxyFrame*)*pArgInf->m_ppCompoundData;
	const char* argUrl = (NULL==pArgInf[1].m_pText || strlen(pArgInf[1].m_pText) <= 0) ? NULL : pArgInf[1].m_pText;
	self->LoadURL(argUrl);
}

extern "C"
void EDITIONF(ProxyFrame_ExecuteJavaScript) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyFrame> self = (ProxyFrame*)*pArgInf->m_ppCompoundData;
	const char* argCode = (NULL==pArgInf[1].m_pText || strlen(pArgInf[1].m_pText) <= 0) ? NULL : pArgInf[1].m_pText;
	const char* argScript_Url = (NULL==pArgInf[2].m_pText || strlen(pArgInf[2].m_pText) <= 0) ? NULL : pArgInf[2].m_pText;
	int argStart_Line = pArgInf[3].m_int;
	self->ExecuteJavaScript(argCode,argScript_Url,argStart_Line);
}

extern "C"
void EDITIONF(ProxyFrame_ExecuteJavaScriptEx) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		*((DWORD*)pRetData->m_pCompoundData) = NULL;
		return ;
	}
	shrewd_ptr<ProxyFrame> self = (ProxyFrame*)*pArgInf->m_ppCompoundData;
	const char* argCode = (NULL==pArgInf[1].m_pText || strlen(pArgInf[1].m_pText) <= 0) ? NULL : pArgInf[1].m_pText;
	const char* argScript_Url = (NULL==pArgInf[2].m_pText || strlen(pArgInf[2].m_pText) <= 0) ? NULL : pArgInf[2].m_pText;
	int argStart_Line = pArgInf[3].m_int;
	char* argException = NULL;
	shrewd_ptr<ProxyValue> result = self->ExecuteJavaScriptEx(argCode,argScript_Url,argStart_Line,&argException);
	if(result){
	result->retain();
	DWORD* InternalPointer = (DWORD*)NotifySys(NRS_MALLOC,4,0);
	*InternalPointer = (DWORD)result.get();
	pRetData->m_pCompoundData = InternalPointer;
}
	else{
	pRetData->m_pCompoundData=NULL;
}
	if(*pArgInf[4].m_ppText){ NotifySys(NRS_MFREE, (DWORD)*pArgInf[4].m_ppText ,0); *pArgInf[4].m_ppText = NULL;  }
	*pArgInf[4].m_ppText = argException;
}

extern "C"
void EDITIONF(ProxyFrame_IsMain) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_bool = FALSE;
		return ;
	}
	shrewd_ptr<ProxyFrame> self = (ProxyFrame*)*pArgInf->m_ppCompoundData;
	pRetData->m_bool = self->IsMain();
}

extern "C"
void EDITIONF(ProxyFrame_IsFocused) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_bool = FALSE;
		return ;
	}
	shrewd_ptr<ProxyFrame> self = (ProxyFrame*)*pArgInf->m_ppCompoundData;
	pRetData->m_bool = self->IsFocused();
}

extern "C"
void EDITIONF(ProxyFrame_GetName) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_pText = NULL;
		return ;
	}
	shrewd_ptr<ProxyFrame> self = (ProxyFrame*)*pArgInf->m_ppCompoundData;
	pRetData->m_pText = self->GetName();
}

extern "C"
void EDITIONF(ProxyFrame_GetParent) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		*((DWORD*)pRetData->m_pCompoundData) = NULL;
		return ;
	}
	shrewd_ptr<ProxyFrame> self = (ProxyFrame*)*pArgInf->m_ppCompoundData;
	shrewd_ptr<ProxyFrame> result = self->GetParent();
	if(result){
	result->retain();
	DWORD* InternalPointer = (DWORD*)NotifySys(NRS_MALLOC,4,0);
	*InternalPointer = (DWORD)result.get();
	pRetData->m_pCompoundData = InternalPointer;
}
	else{
	pRetData->m_pCompoundData=NULL;
}
}

extern "C"
void EDITIONF(ProxyFrame_GetURL) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_pText = NULL;
		return ;
	}
	shrewd_ptr<ProxyFrame> self = (ProxyFrame*)*pArgInf->m_ppCompoundData;
	pRetData->m_pText = self->GetURL();
}

extern "C"
void EDITIONF(ProxyFrame_GetBrowser) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		*((DWORD*)pRetData->m_pCompoundData) = NULL;
		return ;
	}
	shrewd_ptr<ProxyFrame> self = (ProxyFrame*)*pArgInf->m_ppCompoundData;
	shrewd_ptr<ProxyBrowser> result = self->GetBrowser();
	if(result){
	result->retain();
	DWORD* InternalPointer = (DWORD*)NotifySys(NRS_MALLOC,4,0);
	*InternalPointer = (DWORD)result.get();
	pRetData->m_pCompoundData = InternalPointer;
}
	else{
	pRetData->m_pCompoundData=NULL;
}
}

extern "C"
void EDITIONF(ProxyFrame_GetIdentifier) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_int64 = 0;
		return ;
	}
	shrewd_ptr<ProxyFrame> self = (ProxyFrame*)*pArgInf->m_ppCompoundData;
	pRetData->m_int64 = self->GetIdentifier();
}



//==========================================

