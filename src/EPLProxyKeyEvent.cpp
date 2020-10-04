#include "stdafx.h"
#include "EPLProxyKeyEvent.h"
#include <proxy/ProxyBrowser.h>
#include <proxy/ProxyBrowserHost.h>
#include <proxy/ProxyFrame.h>
#include <proxy/ProxyRequest.h>
#include <proxy/ProxyResponse.h>
#include <proxy/proxyValue.h>
#include <proxy/proxyListValue.h>
#include <proxy/ProxyDictionaryValue.h>
#include <proxy/ProxyKeyEvent.h>



//==========================================

extern "C"
void EDITIONF(ProxyKeyEvent_Constructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	*pArgInf->m_ppCompoundData = NULL;
}

extern "C"
void EDITIONF(ProxyKeyEvent_Destructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData) { return; }
	shrewd_ptr<ProxyKeyEvent> ptr = (ProxyKeyEvent*)*pArgInf->m_ppCompoundData;
	if(ptr){ ptr->release(); *pArgInf->m_ppCompoundData = NULL; }
}

extern "C"
void EDITIONF(ProxyKeyEvent_CopyConstructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf[1].m_pCompoundData || NULL == *pArgInf[1].m_ppCompoundData) { return; }
	shrewd_ptr<ProxyKeyEvent> ptr = (ProxyKeyEvent*)*pArgInf[1].m_ppCompoundData;
	if(ptr){ ptr->retain(); *pArgInf->m_ppCompoundData = ptr.get(); }
	else { *pArgInf->m_ppCompoundData = NULL; }
}

extern "C"
void EDITIONF(ProxyKeyEvent_Create) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	shrewd_ptr<ProxyKeyEvent> result = ProxyKeyEvent::Create();
	if(*pArgInf->m_ppCompoundData){
		((refcounted*)*pArgInf->m_ppCompoundData)->release();
	 }
	if(result){
		result->retain();
		*pArgInf->m_ppCompoundData = result.get();
	}
}

extern "C"
void EDITIONF(ProxyKeyEvent_IsValid) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_bool = FALSE;
		return ;
	}
	shrewd_ptr<ProxyKeyEvent> self = (ProxyKeyEvent*)*pArgInf->m_ppCompoundData;
	pRetData->m_bool = self->IsValid();
}

extern "C"
void EDITIONF(ProxyKeyEvent_SetType) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyKeyEvent> self = (ProxyKeyEvent*)*pArgInf->m_ppCompoundData;
	int argType = pArgInf[1].m_int;
	self->SetType(argType);
}

extern "C"
void EDITIONF(ProxyKeyEvent_SetModifiers) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyKeyEvent> self = (ProxyKeyEvent*)*pArgInf->m_ppCompoundData;
	int argModifiers = pArgInf[1].m_int;
	self->SetModifiers(argModifiers);
}

extern "C"
void EDITIONF(ProxyKeyEvent_SetWindowsKeyCode) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyKeyEvent> self = (ProxyKeyEvent*)*pArgInf->m_ppCompoundData;
	int argWindows_Key_Code = pArgInf[1].m_int;
	self->SetWindowsKeyCode(argWindows_Key_Code);
}

extern "C"
void EDITIONF(ProxyKeyEvent_SetNativeKeyCode) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyKeyEvent> self = (ProxyKeyEvent*)*pArgInf->m_ppCompoundData;
	int argNative_Key_Code = pArgInf[1].m_int;
	self->SetNativeKeyCode(argNative_Key_Code);
}

extern "C"
void EDITIONF(ProxyKeyEvent_SetIsSystemKey) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyKeyEvent> self = (ProxyKeyEvent*)*pArgInf->m_ppCompoundData;
	int argIs_System_Key = pArgInf[1].m_int;
	self->SetIsSystemKey(argIs_System_Key);
}

extern "C"
void EDITIONF(ProxyKeyEvent_SetCharacter) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyKeyEvent> self = (ProxyKeyEvent*)*pArgInf->m_ppCompoundData;
	int argCharacter = pArgInf[1].m_int;
	self->SetCharacter(argCharacter);
}

extern "C"
void EDITIONF(ProxyKeyEvent_SetUnmodifiedCharacter) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyKeyEvent> self = (ProxyKeyEvent*)*pArgInf->m_ppCompoundData;
	int argUnmodified_Character = pArgInf[1].m_int;
	self->SetUnmodifiedCharacter(argUnmodified_Character);
}

extern "C"
void EDITIONF(ProxyKeyEvent_SetFocusOnEditableField) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyKeyEvent> self = (ProxyKeyEvent*)*pArgInf->m_ppCompoundData;
	int argFocus_On_Editable_Field = pArgInf[1].m_int;
	self->SetFocusOnEditableField(argFocus_On_Editable_Field);
}



//==========================================

