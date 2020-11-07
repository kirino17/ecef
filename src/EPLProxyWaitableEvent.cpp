#include "stdafx.h"
#include "EPLProxyWaitableEvent.h"
#include <proxy/ProxyBrowser.h>
#include <proxy/ProxyFrame.h>
#include <proxy/ProxyRequest.h>
#include <proxy/ProxyResponse.h>
#include <proxy/proxyValue.h>
#include <proxy/proxyListValue.h>
#include <proxy/ProxyDictionaryValue.h>
#include <proxy/ProxyDOMNode.h>
#include <proxy/ProxyWaitableEvent.h>



//==========================================

extern "C"
void EDITIONF(ProxyWaitableEvent_Constructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	*pArgInf->m_ppCompoundData = NULL;
}

extern "C"
void EDITIONF(ProxyWaitableEvent_Destructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData) { return; }
	shrewd_ptr<ProxyWaitableEvent> ptr = (ProxyWaitableEvent*)*pArgInf->m_ppCompoundData;
	if(ptr){ ptr->release(); *pArgInf->m_ppCompoundData = NULL; }
}

extern "C"
void EDITIONF(ProxyWaitableEvent_CopyConstructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf[1].m_pCompoundData || NULL == *pArgInf[1].m_ppCompoundData) { return; }
	shrewd_ptr<ProxyWaitableEvent> ptr = (ProxyWaitableEvent*)*pArgInf[1].m_ppCompoundData;
	if(ptr){ ptr->retain(); *pArgInf->m_ppCompoundData = ptr.get(); }
	else { *pArgInf->m_ppCompoundData = NULL; }
}

extern "C"
void EDITIONF(ProxyWaitableEvent_IsValid) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_bool = FALSE;
		return ;
	}
	shrewd_ptr<ProxyWaitableEvent> self = (ProxyWaitableEvent*)*pArgInf->m_ppCompoundData;
	pRetData->m_bool = self->IsValid();
}

extern "C"
void EDITIONF(ProxyWaitableEvent_Reset) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyWaitableEvent> self = (ProxyWaitableEvent*)*pArgInf->m_ppCompoundData;
	self->Reset();
}

extern "C"
void EDITIONF(ProxyWaitableEvent_Signal) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyWaitableEvent> self = (ProxyWaitableEvent*)*pArgInf->m_ppCompoundData;
	self->Signal();
}

extern "C"
void EDITIONF(ProxyWaitableEvent_IsSignaled) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_bool = FALSE;
		return ;
	}
	shrewd_ptr<ProxyWaitableEvent> self = (ProxyWaitableEvent*)*pArgInf->m_ppCompoundData;
	pRetData->m_bool = self->IsSignaled();
}

extern "C"
void EDITIONF(ProxyWaitableEvent_Wait) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyWaitableEvent> self = (ProxyWaitableEvent*)*pArgInf->m_ppCompoundData;
	self->Wait();
}

extern "C"
void EDITIONF(ProxyWaitableEvent_TimedWait) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_bool = FALSE;
		return ;
	}
	shrewd_ptr<ProxyWaitableEvent> self = (ProxyWaitableEvent*)*pArgInf->m_ppCompoundData;
	__int64 argMax_Ms = pArgInf[1].m_int64;
	pRetData->m_bool = self->TimedWait(argMax_Ms);
}

extern "C"
void EDITIONF(ProxyWaitableEvent_SetUserData) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyWaitableEvent> self = (ProxyWaitableEvent*)*pArgInf->m_ppCompoundData;
	shrewd_ptr<ProxyValue> argValue = (ProxyValue*)*pArgInf[1].m_ppCompoundData;
	self->SetUserData(argValue);
}

extern "C"
void EDITIONF(ProxyWaitableEvent_GetUserData) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		
		return ;
	}
	shrewd_ptr<ProxyWaitableEvent> self = (ProxyWaitableEvent*)*pArgInf->m_ppCompoundData;
	shrewd_ptr<ProxyValue> result = self->GetUserData();
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



//==========================================

