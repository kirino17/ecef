#include "stdafx.h"
#include "EPLProxyTouchEvent.h"
#include <proxy/ProxyBrowser.h>
#include <proxy/ProxyBrowserHost.h>
#include <proxy/ProxyFrame.h>
#include <proxy/ProxyRequest.h>
#include <proxy/ProxyResponse.h>
#include <proxy/proxyValue.h>
#include <proxy/proxyListValue.h>
#include <proxy/ProxyDictionaryValue.h>
#include <proxy/ProxyTouchEvent.h>



//==========================================

extern "C"
void EDITIONF(ProxyTouchEvent_Constructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	*pArgInf->m_ppCompoundData = NULL;
}

extern "C"
void EDITIONF(ProxyTouchEvent_Destructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData) { return; }
	shrewd_ptr<ProxyTouchEvent> ptr = (ProxyTouchEvent*)*pArgInf->m_ppCompoundData;
	if(ptr){ ptr->release(); *pArgInf->m_ppCompoundData = NULL; }
}

extern "C"
void EDITIONF(ProxyTouchEvent_CopyConstructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf[1].m_pCompoundData || NULL == *pArgInf[1].m_ppCompoundData) { return; }
	shrewd_ptr<ProxyTouchEvent> ptr = (ProxyTouchEvent*)*pArgInf[1].m_ppCompoundData;
	if(ptr){ ptr->retain(); *pArgInf->m_ppCompoundData = ptr.get(); }
	else { *pArgInf->m_ppCompoundData = NULL; }
}

extern "C"
void EDITIONF(ProxyTouchEvent_Create) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	shrewd_ptr<ProxyTouchEvent> result = ProxyTouchEvent::Create();
	if(*pArgInf->m_ppCompoundData){
		((refcounted*)*pArgInf->m_ppCompoundData)->release();
	 }
	if(result){
		result->retain();
		*pArgInf->m_ppCompoundData = result.get();
	}
}

extern "C"
void EDITIONF(ProxyTouchEvent_IsValid) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_bool = FALSE;
		return ;
	}
	shrewd_ptr<ProxyTouchEvent> self = (ProxyTouchEvent*)*pArgInf->m_ppCompoundData;
	pRetData->m_bool = self->IsValid();
}

extern "C"
void EDITIONF(ProxyTouchEvent_SetId) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyTouchEvent> self = (ProxyTouchEvent*)*pArgInf->m_ppCompoundData;
	int argId = pArgInf[1].m_int;
	self->SetId(argId);
}

extern "C"
void EDITIONF(ProxyTouchEvent_SetX) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyTouchEvent> self = (ProxyTouchEvent*)*pArgInf->m_ppCompoundData;
	int argX = pArgInf[1].m_int;
	self->SetX(argX);
}

extern "C"
void EDITIONF(ProxyTouchEvent_SetY) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyTouchEvent> self = (ProxyTouchEvent*)*pArgInf->m_ppCompoundData;
	int argY = pArgInf[1].m_int;
	self->SetY(argY);
}

extern "C"
void EDITIONF(ProxyTouchEvent_SetRadiusX) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyTouchEvent> self = (ProxyTouchEvent*)*pArgInf->m_ppCompoundData;
	int argRadius_X = pArgInf[1].m_int;
	self->SetRadiusX(argRadius_X);
}

extern "C"
void EDITIONF(ProxyTouchEvent_SetRadiusY) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyTouchEvent> self = (ProxyTouchEvent*)*pArgInf->m_ppCompoundData;
	int argRadius_Y = pArgInf[1].m_int;
	self->SetRadiusY(argRadius_Y);
}

extern "C"
void EDITIONF(ProxyTouchEvent_SetRotationAngle) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyTouchEvent> self = (ProxyTouchEvent*)*pArgInf->m_ppCompoundData;
	int argRotation_Angle = pArgInf[1].m_int;
	self->SetRotationAngle(argRotation_Angle);
}

extern "C"
void EDITIONF(ProxyTouchEvent_SetPressure) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyTouchEvent> self = (ProxyTouchEvent*)*pArgInf->m_ppCompoundData;
	int argPressure = pArgInf[1].m_int;
	self->SetPressure(argPressure);
}

extern "C"
void EDITIONF(ProxyTouchEvent_SetType) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyTouchEvent> self = (ProxyTouchEvent*)*pArgInf->m_ppCompoundData;
	int argType = pArgInf[1].m_int;
	self->SetType(argType);
}

extern "C"
void EDITIONF(ProxyTouchEvent_SetModifiers) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyTouchEvent> self = (ProxyTouchEvent*)*pArgInf->m_ppCompoundData;
	int argModifiers = pArgInf[1].m_int;
	self->SetModifiers(argModifiers);
}

extern "C"
void EDITIONF(ProxyTouchEvent_SetPointerType) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyTouchEvent> self = (ProxyTouchEvent*)*pArgInf->m_ppCompoundData;
	int argPointer_Type = pArgInf[1].m_int;
	self->SetPointerType(argPointer_Type);
}



//==========================================

