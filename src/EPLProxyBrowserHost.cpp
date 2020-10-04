#include "stdafx.h"
#include "EPLProxyBrowserHost.h"
#include <proxy/ProxyBrowser.h>
#include <proxy/ProxyBrowserHost.h>
#include <proxy/ProxyFrame.h>
#include <proxy/ProxyRequest.h>
#include <proxy/ProxyResponse.h>
#include <proxy/proxyValue.h>
#include <proxy/proxyListValue.h>
#include <proxy/ProxyDictionaryValue.h>
#include <proxy/ProxyBrowserHost.h>



//==========================================

extern "C"
void EDITIONF(ProxyBrowserHost_Constructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	*pArgInf->m_ppCompoundData = NULL;
}

extern "C"
void EDITIONF(ProxyBrowserHost_Destructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData) { return; }
	shrewd_ptr<ProxyBrowserHost> ptr = (ProxyBrowserHost*)*pArgInf->m_ppCompoundData;
	if(ptr){ ptr->release(); *pArgInf->m_ppCompoundData = NULL; }
}

extern "C"
void EDITIONF(ProxyBrowserHost_CopyConstructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf[1].m_pCompoundData || NULL == *pArgInf[1].m_ppCompoundData) { return; }
	shrewd_ptr<ProxyBrowserHost> ptr = (ProxyBrowserHost*)*pArgInf[1].m_ppCompoundData;
	if(ptr){ ptr->retain(); *pArgInf->m_ppCompoundData = ptr.get(); }
	else { *pArgInf->m_ppCompoundData = NULL; }
}

extern "C"
void EDITIONF(ProxyBrowserHost_IsValid) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_bool = FALSE;
		return ;
	}
	shrewd_ptr<ProxyBrowserHost> self = (ProxyBrowserHost*)*pArgInf->m_ppCompoundData;
	pRetData->m_bool = self->IsValid();
}

extern "C"
void EDITIONF(ProxyBrowserHost_GetBrowser) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		*((DWORD*)pRetData->m_pCompoundData) = NULL;
		return ;
	}
	shrewd_ptr<ProxyBrowserHost> self = (ProxyBrowserHost*)*pArgInf->m_ppCompoundData;
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
void EDITIONF(ProxyBrowserHost_CloseBrowser) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyBrowserHost> self = (ProxyBrowserHost*)*pArgInf->m_ppCompoundData;
	bool argForce_Close = pArgInf[1].m_bool;
	self->CloseBrowser(argForce_Close);
}

extern "C"
void EDITIONF(ProxyBrowserHost_TryCloseBrowser) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_bool = FALSE;
		return ;
	}
	shrewd_ptr<ProxyBrowserHost> self = (ProxyBrowserHost*)*pArgInf->m_ppCompoundData;
	pRetData->m_bool = self->TryCloseBrowser();
}

extern "C"
void EDITIONF(ProxyBrowserHost_SetFocus) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyBrowserHost> self = (ProxyBrowserHost*)*pArgInf->m_ppCompoundData;
	bool argFocus = pArgInf[1].m_bool;
	self->SetFocus(argFocus);
}

extern "C"
void EDITIONF(ProxyBrowserHost_GetWindowHandle) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_uint = 0;
		return ;
	}
	shrewd_ptr<ProxyBrowserHost> self = (ProxyBrowserHost*)*pArgInf->m_ppCompoundData;
	pRetData->m_uint = (unsigned int)self->GetWindowHandle();
}

extern "C"
void EDITIONF(ProxyBrowserHost_GetOpenerWindowHandle) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_uint = 0;
		return ;
	}
	shrewd_ptr<ProxyBrowserHost> self = (ProxyBrowserHost*)*pArgInf->m_ppCompoundData;
	pRetData->m_uint = (unsigned int)self->GetOpenerWindowHandle();
}

extern "C"
void EDITIONF(ProxyBrowserHost_GetRequestContext) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		*((DWORD*)pRetData->m_pCompoundData) = NULL;
		return ;
	}
	shrewd_ptr<ProxyBrowserHost> self = (ProxyBrowserHost*)*pArgInf->m_ppCompoundData;
	shrewd_ptr<ProxyRequestContext> result = self->GetRequestContext();
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
void EDITIONF(ProxyBrowserHost_GetZoomLevel) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_double = 0.0f;
		return ;
	}
	shrewd_ptr<ProxyBrowserHost> self = (ProxyBrowserHost*)*pArgInf->m_ppCompoundData;
	pRetData->m_double = self->GetZoomLevel();
}

extern "C"
void EDITIONF(ProxyBrowserHost_SetZoomLevel) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyBrowserHost> self = (ProxyBrowserHost*)*pArgInf->m_ppCompoundData;
	double argZoomlevel = pArgInf[1].m_double;
	self->SetZoomLevel(argZoomlevel);
}

extern "C"
void EDITIONF(ProxyBrowserHost_StartDownload) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyBrowserHost> self = (ProxyBrowserHost*)*pArgInf->m_ppCompoundData;
	const char* argUrl = (NULL==pArgInf[1].m_pText || strlen(pArgInf[1].m_pText) <= 0) ? NULL : pArgInf[1].m_pText;
	self->StartDownload(argUrl);
}

extern "C"
void EDITIONF(ProxyBrowserHost_Print) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyBrowserHost> self = (ProxyBrowserHost*)*pArgInf->m_ppCompoundData;
	self->Print();
}

extern "C"
void EDITIONF(ProxyBrowserHost_SetMouseCursorChangeDisabled) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyBrowserHost> self = (ProxyBrowserHost*)*pArgInf->m_ppCompoundData;
	bool argDisabled = pArgInf[1].m_bool;
	self->SetMouseCursorChangeDisabled(argDisabled);
}

extern "C"
void EDITIONF(ProxyBrowserHost_IsMouseCursorChangeDisabled) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_bool = FALSE;
		return ;
	}
	shrewd_ptr<ProxyBrowserHost> self = (ProxyBrowserHost*)*pArgInf->m_ppCompoundData;
	pRetData->m_bool = self->IsMouseCursorChangeDisabled();
}

extern "C"
void EDITIONF(ProxyBrowserHost_ReplaceMisspelling) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyBrowserHost> self = (ProxyBrowserHost*)*pArgInf->m_ppCompoundData;
	const char* argWord = (NULL==pArgInf[1].m_pText || strlen(pArgInf[1].m_pText) <= 0) ? NULL : pArgInf[1].m_pText;
	self->ReplaceMisspelling(argWord);
}

extern "C"
void EDITIONF(ProxyBrowserHost_AddWordToDictionary) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyBrowserHost> self = (ProxyBrowserHost*)*pArgInf->m_ppCompoundData;
	const char* argWord = (NULL==pArgInf[1].m_pText || strlen(pArgInf[1].m_pText) <= 0) ? NULL : pArgInf[1].m_pText;
	self->AddWordToDictionary(argWord);
}

extern "C"
void EDITIONF(ProxyBrowserHost_IsWindowRenderingDisabled) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_bool = FALSE;
		return ;
	}
	shrewd_ptr<ProxyBrowserHost> self = (ProxyBrowserHost*)*pArgInf->m_ppCompoundData;
	pRetData->m_bool = self->IsWindowRenderingDisabled();
}

extern "C"
void EDITIONF(ProxyBrowserHost_WasResized) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyBrowserHost> self = (ProxyBrowserHost*)*pArgInf->m_ppCompoundData;
	self->WasResized();
}

extern "C"
void EDITIONF(ProxyBrowserHost_WasHidden) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyBrowserHost> self = (ProxyBrowserHost*)*pArgInf->m_ppCompoundData;
	bool argHidden = pArgInf[1].m_bool;
	self->WasHidden(argHidden);
}

extern "C"
void EDITIONF(ProxyBrowserHost_NotifyScreenInfoChanged) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyBrowserHost> self = (ProxyBrowserHost*)*pArgInf->m_ppCompoundData;
	self->NotifyScreenInfoChanged();
}

extern "C"
void EDITIONF(ProxyBrowserHost_SendKeyEvent) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyBrowserHost> self = (ProxyBrowserHost*)*pArgInf->m_ppCompoundData;
	shrewd_ptr<ProxyKeyEvent> argEvent = (ProxyKeyEvent*)*pArgInf[1].m_ppCompoundData;
	self->SendKeyEvent(argEvent);
}

extern "C"
void EDITIONF(ProxyBrowserHost_SendMouseClickEvent) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyBrowserHost> self = (ProxyBrowserHost*)*pArgInf->m_ppCompoundData;
	shrewd_ptr<ProxyMouseEvent> argEvent = (ProxyMouseEvent*)*pArgInf[1].m_ppCompoundData;
	int argType = pArgInf[2].m_int;
	bool argMouseup = pArgInf[3].m_bool;
	int argClickcount = pArgInf[4].m_int;
	self->SendMouseClickEvent(argEvent,argType,argMouseup,argClickcount);
}

extern "C"
void EDITIONF(ProxyBrowserHost_SendMouseMoveEvent) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyBrowserHost> self = (ProxyBrowserHost*)*pArgInf->m_ppCompoundData;
	shrewd_ptr<ProxyMouseEvent> argEvent = (ProxyMouseEvent*)*pArgInf[1].m_ppCompoundData;
	bool argMouseleave = pArgInf[2].m_bool;
	self->SendMouseMoveEvent(argEvent,argMouseleave);
}

extern "C"
void EDITIONF(ProxyBrowserHost_SendMouseWheelEvent) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyBrowserHost> self = (ProxyBrowserHost*)*pArgInf->m_ppCompoundData;
	shrewd_ptr<ProxyMouseEvent> argEvent = (ProxyMouseEvent*)*pArgInf[1].m_ppCompoundData;
	int argDeltax = pArgInf[2].m_int;
	int argDeltay = pArgInf[3].m_int;
	self->SendMouseWheelEvent(argEvent,argDeltax,argDeltay);
}

extern "C"
void EDITIONF(ProxyBrowserHost_SendTouchEvent) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyBrowserHost> self = (ProxyBrowserHost*)*pArgInf->m_ppCompoundData;
	shrewd_ptr<ProxyTouchEvent> argEvent = (ProxyTouchEvent*)*pArgInf[1].m_ppCompoundData;
	self->SendTouchEvent(argEvent);
}

extern "C"
void EDITIONF(ProxyBrowserHost_SendFocusEvent) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyBrowserHost> self = (ProxyBrowserHost*)*pArgInf->m_ppCompoundData;
	bool argSetfocus = pArgInf[1].m_bool;
	self->SendFocusEvent(argSetfocus);
}

extern "C"
void EDITIONF(ProxyBrowserHost_SendCaptureLostEvent) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyBrowserHost> self = (ProxyBrowserHost*)*pArgInf->m_ppCompoundData;
	self->SendCaptureLostEvent();
}

extern "C"
void EDITIONF(ProxyBrowserHost_NotifyMoveOrResizeStarted) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyBrowserHost> self = (ProxyBrowserHost*)*pArgInf->m_ppCompoundData;
	self->NotifyMoveOrResizeStarted();
}

extern "C"
void EDITIONF(ProxyBrowserHost_GetWindowlessFrameRate) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_int = 0;
		return ;
	}
	shrewd_ptr<ProxyBrowserHost> self = (ProxyBrowserHost*)*pArgInf->m_ppCompoundData;
	pRetData->m_int = self->GetWindowlessFrameRate();
}

extern "C"
void EDITIONF(ProxyBrowserHost_SetWindowlessFrameRate) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyBrowserHost> self = (ProxyBrowserHost*)*pArgInf->m_ppCompoundData;
	int argFrame_Rate = pArgInf[1].m_int;
	self->SetWindowlessFrameRate(argFrame_Rate);
}

extern "C"
void EDITIONF(ProxyBrowserHost_SetAudioMuted) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyBrowserHost> self = (ProxyBrowserHost*)*pArgInf->m_ppCompoundData;
	bool argMute = pArgInf[1].m_bool;
	self->SetAudioMuted(argMute);
}

extern "C"
void EDITIONF(ProxyBrowserHost_IsAudioMuted) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_bool = FALSE;
		return ;
	}
	shrewd_ptr<ProxyBrowserHost> self = (ProxyBrowserHost*)*pArgInf->m_ppCompoundData;
	pRetData->m_bool = self->IsAudioMuted();
}

extern "C"
void EDITIONF(ProxyBrowserHost_ShowDevTools) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyBrowserHost> self = (ProxyBrowserHost*)*pArgInf->m_ppCompoundData;
	shrewd_ptr<ProxyWindowInfo> argWindowinfo = (ProxyWindowInfo*)*pArgInf[1].m_ppCompoundData;
	shrewd_ptr<ProxyBrowserSettings> argSettings = (ProxyBrowserSettings*)*pArgInf[2].m_ppCompoundData;
	int argInspect_Element_At_X = pArgInf[3].m_int;
	int argInspect_Element_At_Y = pArgInf[4].m_int;
	self->ShowDevTools(argWindowinfo,argSettings,argInspect_Element_At_X,argInspect_Element_At_Y);
}

extern "C"
void EDITIONF(ProxyBrowserHost_CloseDevTools) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyBrowserHost> self = (ProxyBrowserHost*)*pArgInf->m_ppCompoundData;
	self->CloseDevTools();
}

extern "C"
void EDITIONF(ProxyBrowserHost_HasDevTools) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_bool = FALSE;
		return ;
	}
	shrewd_ptr<ProxyBrowserHost> self = (ProxyBrowserHost*)*pArgInf->m_ppCompoundData;
	pRetData->m_bool = self->HasDevTools();
}



//==========================================

