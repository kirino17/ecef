#include "stdafx.h"
#include "EPLProxyWindowInfo.h"
#include <proxy/ProxyBrowser.h>
#include <proxy/ProxyBrowserHost.h>
#include <proxy/ProxyFrame.h>
#include <proxy/ProxyRequest.h>
#include <proxy/ProxyResponse.h>
#include <proxy/proxyValue.h>
#include <proxy/proxyListValue.h>
#include <proxy/ProxyDictionaryValue.h>
#include <proxy/ProxyWindowInfo.h>



//==========================================

extern "C"
void EDITIONF(ProxyWindowInfo_Constructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	*pArgInf->m_ppCompoundData = NULL;
}

extern "C"
void EDITIONF(ProxyWindowInfo_Destructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData) { return; }
	shrewd_ptr<ProxyWindowInfo> ptr = (ProxyWindowInfo*)*pArgInf->m_ppCompoundData;
	if(ptr){ ptr->release(); *pArgInf->m_ppCompoundData = NULL; }
}

extern "C"
void EDITIONF(ProxyWindowInfo_CopyConstructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf[1].m_pCompoundData || NULL == *pArgInf[1].m_ppCompoundData) { return; }
	shrewd_ptr<ProxyWindowInfo> ptr = (ProxyWindowInfo*)*pArgInf[1].m_ppCompoundData;
	if(ptr){ ptr->retain(); *pArgInf->m_ppCompoundData = ptr.get(); }
	else { *pArgInf->m_ppCompoundData = NULL; }
}

extern "C"
void EDITIONF(ProxyWindowInfo_Create) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	shrewd_ptr<ProxyWindowInfo> result = ProxyWindowInfo::Create();
	if(*pArgInf->m_ppCompoundData){
		((refcounted*)*pArgInf->m_ppCompoundData)->release();
	 }
	if(result){
		result->retain();
		*pArgInf->m_ppCompoundData = result.get();
	}
}

extern "C"
void EDITIONF(ProxyWindowInfo_IsValid) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_bool = FALSE;
		return ;
	}
	shrewd_ptr<ProxyWindowInfo> self = (ProxyWindowInfo*)*pArgInf->m_ppCompoundData;
	pRetData->m_bool = self->IsValid();
}

extern "C"
void EDITIONF(ProxyWindowInfo_SetExStyle) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyWindowInfo> self = (ProxyWindowInfo*)*pArgInf->m_ppCompoundData;
	unsigned int argEx_Style = pArgInf[1].m_uint;
	self->SetExStyle(argEx_Style);
}

extern "C"
void EDITIONF(ProxyWindowInfo_SetWindowName) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyWindowInfo> self = (ProxyWindowInfo*)*pArgInf->m_ppCompoundData;
	const char* argWindow_Name = (NULL==pArgInf[1].m_pText || strlen(pArgInf[1].m_pText) <= 0) ? NULL : pArgInf[1].m_pText;
	self->SetWindowName(argWindow_Name);
}

extern "C"
void EDITIONF(ProxyWindowInfo_SetStyle) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyWindowInfo> self = (ProxyWindowInfo*)*pArgInf->m_ppCompoundData;
	unsigned int argStyle = pArgInf[1].m_uint;
	self->SetStyle(argStyle);
}

extern "C"
void EDITIONF(ProxyWindowInfo_SetX) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyWindowInfo> self = (ProxyWindowInfo*)*pArgInf->m_ppCompoundData;
	int argX = pArgInf[1].m_int;
	self->SetX(argX);
}

extern "C"
void EDITIONF(ProxyWindowInfo_SetY) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyWindowInfo> self = (ProxyWindowInfo*)*pArgInf->m_ppCompoundData;
	int argY = pArgInf[1].m_int;
	self->SetY(argY);
}

extern "C"
void EDITIONF(ProxyWindowInfo_SetWidth) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyWindowInfo> self = (ProxyWindowInfo*)*pArgInf->m_ppCompoundData;
	int argWidth = pArgInf[1].m_int;
	self->SetWidth(argWidth);
}

extern "C"
void EDITIONF(ProxyWindowInfo_SetHeight) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyWindowInfo> self = (ProxyWindowInfo*)*pArgInf->m_ppCompoundData;
	int argHeight = pArgInf[1].m_int;
	self->SetHeight(argHeight);
}

extern "C"
void EDITIONF(ProxyWindowInfo_SetParentWindow) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyWindowInfo> self = (ProxyWindowInfo*)*pArgInf->m_ppCompoundData;
	unsigned int argParent_Window = pArgInf[1].m_uint;
	self->SetParentWindow(argParent_Window);
}

extern "C"
void EDITIONF(ProxyWindowInfo_SetMenu) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyWindowInfo> self = (ProxyWindowInfo*)*pArgInf->m_ppCompoundData;
	unsigned int argMenu = pArgInf[1].m_uint;
	self->SetMenu(argMenu);
}

extern "C"
void EDITIONF(ProxyWindowInfo_SetWindowlessRenderingEnabled) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyWindowInfo> self = (ProxyWindowInfo*)*pArgInf->m_ppCompoundData;
	int argValue = pArgInf[1].m_int;
	self->SetWindowlessRenderingEnabled(argValue);
}

extern "C"
void EDITIONF(ProxyWindowInfo_SetSharedtextureEnabled) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyWindowInfo> self = (ProxyWindowInfo*)*pArgInf->m_ppCompoundData;
	int argValue = pArgInf[1].m_int;
	self->SetSharedtextureEnabled(argValue);
}

extern "C"
void EDITIONF(ProxyWindowInfo_SetExternalBeginFrameEnabled) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyWindowInfo> self = (ProxyWindowInfo*)*pArgInf->m_ppCompoundData;
	int argValue = pArgInf[1].m_int;
	self->SetExternalBeginFrameEnabled(argValue);
}

extern "C"
void EDITIONF(ProxyWindowInfo_SetWindow) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyWindowInfo> self = (ProxyWindowInfo*)*pArgInf->m_ppCompoundData;
	unsigned int argWindow = pArgInf[1].m_uint;
	self->SetWindow(argWindow);
}

extern "C"
void EDITIONF(ProxyWindowInfo_SetAsChild) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyWindowInfo> self = (ProxyWindowInfo*)*pArgInf->m_ppCompoundData;
	unsigned int argParent = pArgInf[1].m_uint;
	int argX = pArgInf[2].m_int;
	int argY = pArgInf[3].m_int;
	int argWidth = pArgInf[4].m_int;
	int argHeight = pArgInf[5].m_int;
	self->SetAsChild(argParent,argX,argY,argWidth,argHeight);
}

extern "C"
void EDITIONF(ProxyWindowInfo_SetAsPopup) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyWindowInfo> self = (ProxyWindowInfo*)*pArgInf->m_ppCompoundData;
	unsigned int argParent = pArgInf[1].m_uint;
	const char* argWindowname = (NULL==pArgInf[2].m_pText || strlen(pArgInf[2].m_pText) <= 0) ? NULL : pArgInf[2].m_pText;
	self->SetAsPopup(argParent,argWindowname);
}

extern "C"
void EDITIONF(ProxyWindowInfo_SetAsWindowless) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyWindowInfo> self = (ProxyWindowInfo*)*pArgInf->m_ppCompoundData;
	unsigned int argParent = pArgInf[1].m_uint;
	self->SetAsWindowless(argParent);
}



//==========================================

