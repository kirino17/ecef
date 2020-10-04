#include "stdafx.h"
#include "EPLProxyPopupFeatures.h"
#include <proxy/ProxyBrowser.h>
#include <proxy/ProxyBrowserHost.h>
#include <proxy/ProxyFrame.h>
#include <proxy/ProxyRequest.h>
#include <proxy/ProxyResponse.h>
#include <proxy/proxyValue.h>
#include <proxy/proxyListValue.h>
#include <proxy/ProxyDictionaryValue.h>
#include <proxy/ProxyPopupFeatures.h>



//==========================================

extern "C"
void EDITIONF(ProxyPopupFeatures_Constructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	*pArgInf->m_ppCompoundData = NULL;
}

extern "C"
void EDITIONF(ProxyPopupFeatures_Destructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData) { return; }
	shrewd_ptr<ProxyPopupFeatures> ptr = (ProxyPopupFeatures*)*pArgInf->m_ppCompoundData;
	if(ptr){ ptr->release(); *pArgInf->m_ppCompoundData = NULL; }
}

extern "C"
void EDITIONF(ProxyPopupFeatures_CopyConstructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf[1].m_pCompoundData || NULL == *pArgInf[1].m_ppCompoundData) { return; }
	shrewd_ptr<ProxyPopupFeatures> ptr = (ProxyPopupFeatures*)*pArgInf[1].m_ppCompoundData;
	if(ptr){ ptr->retain(); *pArgInf->m_ppCompoundData = ptr.get(); }
	else { *pArgInf->m_ppCompoundData = NULL; }
}

extern "C"
void EDITIONF(ProxyPopupFeatures_Create) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	shrewd_ptr<ProxyPopupFeatures> result = ProxyPopupFeatures::Create();
	if(*pArgInf->m_ppCompoundData){
		((refcounted*)*pArgInf->m_ppCompoundData)->release();
	 }
	if(result){
		result->retain();
		*pArgInf->m_ppCompoundData = result.get();
	}
}

extern "C"
void EDITIONF(ProxyPopupFeatures_IsValid) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_bool = FALSE;
		return ;
	}
	shrewd_ptr<ProxyPopupFeatures> self = (ProxyPopupFeatures*)*pArgInf->m_ppCompoundData;
	pRetData->m_bool = self->IsValid();
}

extern "C"
void EDITIONF(ProxyPopupFeatures_GetX) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_int = 0;
		return ;
	}
	shrewd_ptr<ProxyPopupFeatures> self = (ProxyPopupFeatures*)*pArgInf->m_ppCompoundData;
	pRetData->m_int = self->GetX();
}

extern "C"
void EDITIONF(ProxyPopupFeatures_GetXSet) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_int = 0;
		return ;
	}
	shrewd_ptr<ProxyPopupFeatures> self = (ProxyPopupFeatures*)*pArgInf->m_ppCompoundData;
	pRetData->m_int = self->GetXSet();
}

extern "C"
void EDITIONF(ProxyPopupFeatures_GetY) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_int = 0;
		return ;
	}
	shrewd_ptr<ProxyPopupFeatures> self = (ProxyPopupFeatures*)*pArgInf->m_ppCompoundData;
	pRetData->m_int = self->GetY();
}

extern "C"
void EDITIONF(ProxyPopupFeatures_GetYSet) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_int = 0;
		return ;
	}
	shrewd_ptr<ProxyPopupFeatures> self = (ProxyPopupFeatures*)*pArgInf->m_ppCompoundData;
	pRetData->m_int = self->GetYSet();
}

extern "C"
void EDITIONF(ProxyPopupFeatures_GetWidth) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_int = 0;
		return ;
	}
	shrewd_ptr<ProxyPopupFeatures> self = (ProxyPopupFeatures*)*pArgInf->m_ppCompoundData;
	pRetData->m_int = self->GetWidth();
}

extern "C"
void EDITIONF(ProxyPopupFeatures_GetWidthSet) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_int = 0;
		return ;
	}
	shrewd_ptr<ProxyPopupFeatures> self = (ProxyPopupFeatures*)*pArgInf->m_ppCompoundData;
	pRetData->m_int = self->GetWidthSet();
}

extern "C"
void EDITIONF(ProxyPopupFeatures_GetHeight) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_int = 0;
		return ;
	}
	shrewd_ptr<ProxyPopupFeatures> self = (ProxyPopupFeatures*)*pArgInf->m_ppCompoundData;
	pRetData->m_int = self->GetHeight();
}

extern "C"
void EDITIONF(ProxyPopupFeatures_GetHeightSet) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_int = 0;
		return ;
	}
	shrewd_ptr<ProxyPopupFeatures> self = (ProxyPopupFeatures*)*pArgInf->m_ppCompoundData;
	pRetData->m_int = self->GetHeightSet();
}

extern "C"
void EDITIONF(ProxyPopupFeatures_GetMenuBarVisible) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_int = 0;
		return ;
	}
	shrewd_ptr<ProxyPopupFeatures> self = (ProxyPopupFeatures*)*pArgInf->m_ppCompoundData;
	pRetData->m_int = self->GetMenuBarVisible();
}

extern "C"
void EDITIONF(ProxyPopupFeatures_GetStatusBarVisible) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_int = 0;
		return ;
	}
	shrewd_ptr<ProxyPopupFeatures> self = (ProxyPopupFeatures*)*pArgInf->m_ppCompoundData;
	pRetData->m_int = self->GetStatusBarVisible();
}

extern "C"
void EDITIONF(ProxyPopupFeatures_GetToolBarVisible) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_int = 0;
		return ;
	}
	shrewd_ptr<ProxyPopupFeatures> self = (ProxyPopupFeatures*)*pArgInf->m_ppCompoundData;
	pRetData->m_int = self->GetToolBarVisible();
}

extern "C"
void EDITIONF(ProxyPopupFeatures_GetScrollbarsVisible) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_int = 0;
		return ;
	}
	shrewd_ptr<ProxyPopupFeatures> self = (ProxyPopupFeatures*)*pArgInf->m_ppCompoundData;
	pRetData->m_int = self->GetScrollbarsVisible();
}



//==========================================

