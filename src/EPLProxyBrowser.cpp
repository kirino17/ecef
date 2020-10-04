#include "stdafx.h"
#include "EPLProxyBrowser.h"
#include <proxy/ProxyBrowser.h>
#include <proxy/ProxyBrowserHost.h>
#include <proxy/ProxyFrame.h>
#include <proxy/ProxyRequest.h>
#include <proxy/ProxyResponse.h>
#include <proxy/proxyValue.h>
#include <proxy/proxyListValue.h>
#include <proxy/ProxyDictionaryValue.h>
#include <proxy/ProxyBrowser.h>



//==========================================

extern "C"
void EDITIONF(ProxyBrowser_Constructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	*pArgInf->m_ppCompoundData = NULL;
}

extern "C"
void EDITIONF(ProxyBrowser_Destructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData) { return; }
	shrewd_ptr<ProxyBrowser> ptr = (ProxyBrowser*)*pArgInf->m_ppCompoundData;
	if(ptr){ ptr->release(); *pArgInf->m_ppCompoundData = NULL; }
}

extern "C"
void EDITIONF(ProxyBrowser_CopyConstructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf[1].m_pCompoundData || NULL == *pArgInf[1].m_ppCompoundData) { return; }
	shrewd_ptr<ProxyBrowser> ptr = (ProxyBrowser*)*pArgInf[1].m_ppCompoundData;
	if(ptr){ ptr->retain(); *pArgInf->m_ppCompoundData = ptr.get(); }
	else { *pArgInf->m_ppCompoundData = NULL; }
}

extern "C"
void EDITIONF(ProxyBrowser_IsValid) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_bool = FALSE;
		return ;
	}
	shrewd_ptr<ProxyBrowser> self = (ProxyBrowser*)*pArgInf->m_ppCompoundData;
	pRetData->m_bool = self->IsValid();
}

extern "C"
void EDITIONF(ProxyBrowser_GetWindowHandle) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_uint = 0;
		return ;
	}
	shrewd_ptr<ProxyBrowser> self = (ProxyBrowser*)*pArgInf->m_ppCompoundData;
	pRetData->m_uint = (unsigned int)self->GetWindowHandle();
}

extern "C"
void EDITIONF(ProxyBrowser_GetHost) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		*((DWORD*)pRetData->m_pCompoundData) = NULL;
		return ;
	}
	shrewd_ptr<ProxyBrowser> self = (ProxyBrowser*)*pArgInf->m_ppCompoundData;
	shrewd_ptr<ProxyBrowserHost> result = self->GetHost();
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
void EDITIONF(ProxyBrowser_CanGoBack) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_bool = FALSE;
		return ;
	}
	shrewd_ptr<ProxyBrowser> self = (ProxyBrowser*)*pArgInf->m_ppCompoundData;
	pRetData->m_bool = self->CanGoBack();
}

extern "C"
void EDITIONF(ProxyBrowser_GoBack) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyBrowser> self = (ProxyBrowser*)*pArgInf->m_ppCompoundData;
	self->GoBack();
}

extern "C"
void EDITIONF(ProxyBrowser_CanGoForward) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_bool = FALSE;
		return ;
	}
	shrewd_ptr<ProxyBrowser> self = (ProxyBrowser*)*pArgInf->m_ppCompoundData;
	pRetData->m_bool = self->CanGoForward();
}

extern "C"
void EDITIONF(ProxyBrowser_GoForward) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyBrowser> self = (ProxyBrowser*)*pArgInf->m_ppCompoundData;
	self->GoForward();
}

extern "C"
void EDITIONF(ProxyBrowser_IsLoading) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_bool = FALSE;
		return ;
	}
	shrewd_ptr<ProxyBrowser> self = (ProxyBrowser*)*pArgInf->m_ppCompoundData;
	pRetData->m_bool = self->IsLoading();
}

extern "C"
void EDITIONF(ProxyBrowser_Reload) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyBrowser> self = (ProxyBrowser*)*pArgInf->m_ppCompoundData;
	self->Reload();
}

extern "C"
void EDITIONF(ProxyBrowser_ReloadIgnoreCache) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyBrowser> self = (ProxyBrowser*)*pArgInf->m_ppCompoundData;
	self->ReloadIgnoreCache();
}

extern "C"
void EDITIONF(ProxyBrowser_StopLoad) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyBrowser> self = (ProxyBrowser*)*pArgInf->m_ppCompoundData;
	self->StopLoad();
}

extern "C"
void EDITIONF(ProxyBrowser_GetIdentifier) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_int = 0;
		return ;
	}
	shrewd_ptr<ProxyBrowser> self = (ProxyBrowser*)*pArgInf->m_ppCompoundData;
	pRetData->m_int = self->GetIdentifier();
}

extern "C"
void EDITIONF(ProxyBrowser_IsSame) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_bool = FALSE;
		return ;
	}
	shrewd_ptr<ProxyBrowser> self = (ProxyBrowser*)*pArgInf->m_ppCompoundData;
	shrewd_ptr<ProxyBrowser> argThat = (ProxyBrowser*)*pArgInf[1].m_ppCompoundData;
	pRetData->m_bool = self->IsSame(argThat);
}

extern "C"
void EDITIONF(ProxyBrowser_IsPopup) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_bool = FALSE;
		return ;
	}
	shrewd_ptr<ProxyBrowser> self = (ProxyBrowser*)*pArgInf->m_ppCompoundData;
	pRetData->m_bool = self->IsPopup();
}

extern "C"
void EDITIONF(ProxyBrowser_HasDocument) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_bool = FALSE;
		return ;
	}
	shrewd_ptr<ProxyBrowser> self = (ProxyBrowser*)*pArgInf->m_ppCompoundData;
	pRetData->m_bool = self->HasDocument();
}

extern "C"
void EDITIONF(ProxyBrowser_GetMainFrame) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		*((DWORD*)pRetData->m_pCompoundData) = NULL;
		return ;
	}
	shrewd_ptr<ProxyBrowser> self = (ProxyBrowser*)*pArgInf->m_ppCompoundData;
	shrewd_ptr<ProxyFrame> result = self->GetMainFrame();
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
void EDITIONF(ProxyBrowser_GetFocusedFrame) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		*((DWORD*)pRetData->m_pCompoundData) = NULL;
		return ;
	}
	shrewd_ptr<ProxyBrowser> self = (ProxyBrowser*)*pArgInf->m_ppCompoundData;
	shrewd_ptr<ProxyFrame> result = self->GetFocusedFrame();
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
void EDITIONF(ProxyBrowser_GetFrame) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		*((DWORD*)pRetData->m_pCompoundData) = NULL;
		return ;
	}
	shrewd_ptr<ProxyBrowser> self = (ProxyBrowser*)*pArgInf->m_ppCompoundData;
	const char* argName = (NULL==pArgInf[1].m_pText || strlen(pArgInf[1].m_pText) <= 0) ? NULL : pArgInf[1].m_pText;
	shrewd_ptr<ProxyFrame> result = self->GetFrame(argName);
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
void EDITIONF(ProxyBrowser_GetFrameWithIdentity) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		*((DWORD*)pRetData->m_pCompoundData) = NULL;
		return ;
	}
	shrewd_ptr<ProxyBrowser> self = (ProxyBrowser*)*pArgInf->m_ppCompoundData;
	__int64 argIdentity = pArgInf[1].m_int64;
	shrewd_ptr<ProxyFrame> result = self->GetFrameWithIdentity(argIdentity);
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
void EDITIONF(ProxyBrowser_GetFrameCount) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		*((DWORD*)pRetData->m_pCompoundData) = NULL;
		return ;
	}
	shrewd_ptr<ProxyBrowser> self = (ProxyBrowser*)*pArgInf->m_ppCompoundData;
	pRetData->m_int = self->GetFrameCount();
}

extern "C"
void EDITIONF(ProxyBrowser_GetFrameNames) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		*((DWORD*)pRetData->m_pCompoundData) = NULL;
		return ;
	}
	shrewd_ptr<ProxyBrowser> self = (ProxyBrowser*)*pArgInf->m_ppCompoundData;
	pRetData->m_pCompoundData = (void*)self->GetFrameNames();
}

extern "C"
void EDITIONF(ProxyBrowser_GetFrameIdentifiers) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		*((DWORD*)pRetData->m_pCompoundData) = NULL;
		return ;
	}
	shrewd_ptr<ProxyBrowser> self = (ProxyBrowser*)*pArgInf->m_ppCompoundData;
	pRetData->m_pCompoundData = (void*)self->GetFrameIdentifiers();
}

extern "C"
void EDITIONF(ProxyBrowser_GetFrames) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		*((DWORD*)pRetData->m_pCompoundData) = NULL;
		return ;
	}
	shrewd_ptr<ProxyBrowser> self = (ProxyBrowser*)*pArgInf->m_ppCompoundData;
	pRetData->m_pCompoundData = (void*)self->GetFrames();
}



//==========================================

