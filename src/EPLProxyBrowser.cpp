#include "stdafx.h"
#include "EPLProxyBrowser.h"
#include <proxy/ProxyBrowser.h>
#include <proxy/ProxyFrame.h>
#include <proxy/ProxyRequest.h>
#include <proxy/ProxyResponse.h>
#include <proxy/proxyValue.h>
#include <proxy/proxyListValue.h>
#include <proxy/ProxyDictionaryValue.h>
#include <proxy/ProxyDOMNode.h>
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
		
		return ;
	}
	shrewd_ptr<ProxyBrowser> self = (ProxyBrowser*)*pArgInf->m_ppCompoundData;
	pRetData->m_int = self->GetFrameCount();
}

extern "C"
void EDITIONF(ProxyBrowser_GetFrameNames) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		DWORD* InternalPointer = (DWORD*)NotifySys(NRS_MALLOC, 8, 0);
		InternalPointer[0] = 1;
		InternalPointer[1] = 0;
		pRetData->m_pCompoundData = InternalPointer;
		return ;
	}
	shrewd_ptr<ProxyBrowser> self = (ProxyBrowser*)*pArgInf->m_ppCompoundData;
	pRetData->m_pCompoundData = (void*)self->GetFrameNames();
}

extern "C"
void EDITIONF(ProxyBrowser_GetFrameIdentifiers) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		DWORD* InternalPointer = (DWORD*)NotifySys(NRS_MALLOC, 8, 0);
		InternalPointer[0] = 1;
		InternalPointer[1] = 0;
		pRetData->m_pCompoundData = InternalPointer;
		return ;
	}
	shrewd_ptr<ProxyBrowser> self = (ProxyBrowser*)*pArgInf->m_ppCompoundData;
	pRetData->m_pCompoundData = (void*)self->GetFrameIdentifiers();
}

extern "C"
void EDITIONF(ProxyBrowser_GetFrames) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		DWORD* InternalPointer = (DWORD*)NotifySys(NRS_MALLOC, 8, 0);
		InternalPointer[0] = 1;
		InternalPointer[1] = 0;
		pRetData->m_pCompoundData = InternalPointer;
		return ;
	}
	shrewd_ptr<ProxyBrowser> self = (ProxyBrowser*)*pArgInf->m_ppCompoundData;
	pRetData->m_pCompoundData = (void*)self->GetFrames();
}

extern "C"
void EDITIONF(ProxyBrowser_CloseBrowser) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyBrowser> self = (ProxyBrowser*)*pArgInf->m_ppCompoundData;
	bool argForce_Close = pArgInf[1].m_bool;
	self->CloseBrowser(argForce_Close);
}

extern "C"
void EDITIONF(ProxyBrowser_SetFocus) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyBrowser> self = (ProxyBrowser*)*pArgInf->m_ppCompoundData;
	bool argFocus = pArgInf[1].m_bool;
	self->SetFocus(argFocus);
}

extern "C"
void EDITIONF(ProxyBrowser_GetOpenerWindowHandle) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_uint = 0;
		return ;
	}
	shrewd_ptr<ProxyBrowser> self = (ProxyBrowser*)*pArgInf->m_ppCompoundData;
	pRetData->m_uint = (unsigned int)self->GetOpenerWindowHandle();
}

extern "C"
void EDITIONF(ProxyBrowser_GetZoomLevel) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_double = 0.0f;
		return ;
	}
	shrewd_ptr<ProxyBrowser> self = (ProxyBrowser*)*pArgInf->m_ppCompoundData;
	pRetData->m_double = self->GetZoomLevel();
}

extern "C"
void EDITIONF(ProxyBrowser_SetZoomLevel) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyBrowser> self = (ProxyBrowser*)*pArgInf->m_ppCompoundData;
	double argZoomlevel = pArgInf[1].m_double;
	self->SetZoomLevel(argZoomlevel);
}

extern "C"
void EDITIONF(ProxyBrowser_StartDownload) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyBrowser> self = (ProxyBrowser*)*pArgInf->m_ppCompoundData;
	const char* argUrl = (NULL==pArgInf[1].m_pText || strlen(pArgInf[1].m_pText) <= 0) ? NULL : pArgInf[1].m_pText;
	self->StartDownload(argUrl);
}

extern "C"
void EDITIONF(ProxyBrowser_Print) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyBrowser> self = (ProxyBrowser*)*pArgInf->m_ppCompoundData;
	self->Print();
}

extern "C"
void EDITIONF(ProxyBrowser_SendKeyDownEvent) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyBrowser> self = (ProxyBrowser*)*pArgInf->m_ppCompoundData;
	int argKey = pArgInf[1].m_int;
	bool argIs_System_Key = pArgInf[2].m_bool;
	int argModifiers = pArgInf[3].m_int;
	self->SendKeyDownEvent(argKey,argIs_System_Key,argModifiers);
}

extern "C"
void EDITIONF(ProxyBrowser_SendKeyUpEvent) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyBrowser> self = (ProxyBrowser*)*pArgInf->m_ppCompoundData;
	int argKey = pArgInf[1].m_int;
	bool argIs_System_Key = pArgInf[2].m_bool;
	int argModifiers = pArgInf[3].m_int;
	self->SendKeyUpEvent(argKey,argIs_System_Key,argModifiers);
}

extern "C"
void EDITIONF(ProxyBrowser_SendKeyPressEvent) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyBrowser> self = (ProxyBrowser*)*pArgInf->m_ppCompoundData;
	int argKey = pArgInf[1].m_int;
	bool argIs_System_Key = pArgInf[2].m_bool;
	int argDuration = pArgInf[3].m_int;
	int argModifiers = pArgInf[4].m_int;
	self->SendKeyPressEvent(argKey,argIs_System_Key,argDuration,argModifiers);
}

extern "C"
void EDITIONF(ProxyBrowser_SendCharEvent) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyBrowser> self = (ProxyBrowser*)*pArgInf->m_ppCompoundData;
	char argCharactor = pArgInf[1].m_byte;
	self->SendCharEvent(argCharactor);
}

extern "C"
void EDITIONF(ProxyBrowser_SendCharArrayEvent) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyBrowser> self = (ProxyBrowser*)*pArgInf->m_ppCompoundData;
	const char* argCharactor = (NULL==pArgInf[1].m_pText || strlen(pArgInf[1].m_pText) <= 0) ? NULL : pArgInf[1].m_pText;
	int argDuration = pArgInf[2].m_int;
	self->SendCharArrayEvent(argCharactor,argDuration);
}

extern "C"
void EDITIONF(ProxyBrowser_SendMouseClickEvent) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyBrowser> self = (ProxyBrowser*)*pArgInf->m_ppCompoundData;
	int argX = pArgInf[1].m_int;
	int argY = pArgInf[2].m_int;
	int argType = pArgInf[3].m_int;
	bool argMouseup = pArgInf[4].m_bool;
	int argClickcount = pArgInf[5].m_int;
	int argModifiers = pArgInf[6].m_int;
	self->SendMouseClickEvent(argX,argY,argType,argMouseup,argClickcount,argModifiers);
}

extern "C"
void EDITIONF(ProxyBrowser_SendMouseMoveEvent) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyBrowser> self = (ProxyBrowser*)*pArgInf->m_ppCompoundData;
	int argX = pArgInf[1].m_int;
	int argY = pArgInf[2].m_int;
	bool argMouseleave = pArgInf[3].m_bool;
	int argModifiers = pArgInf[4].m_int;
	self->SendMouseMoveEvent(argX,argY,argMouseleave,argModifiers);
}

extern "C"
void EDITIONF(ProxyBrowser_SendMouseWheelEvent) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyBrowser> self = (ProxyBrowser*)*pArgInf->m_ppCompoundData;
	int argX = pArgInf[1].m_int;
	int argY = pArgInf[2].m_int;
	int argDeltax = pArgInf[3].m_int;
	int argDeltay = pArgInf[4].m_int;
	int argModifiers = pArgInf[5].m_int;
	self->SendMouseWheelEvent(argX,argY,argDeltax,argDeltay,argModifiers);
}

extern "C"
void EDITIONF(ProxyBrowser_SendTouchEvent) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyBrowser> self = (ProxyBrowser*)*pArgInf->m_ppCompoundData;
	int argId = pArgInf[1].m_int;
	float argX = pArgInf[2].m_float;
	float argY = pArgInf[3].m_float;
	float argRadius_X = pArgInf[4].m_float;
	float argRadius_Y = pArgInf[5].m_float;
	float argRotation_Angle = pArgInf[6].m_float;
	float argPressure = pArgInf[7].m_float;
	int argType = pArgInf[8].m_int;
	int argModifiers = pArgInf[9].m_int;
	int argPointer_Type = pArgInf[10].m_int;
	self->SendTouchEvent(argId,argX,argY,argRadius_X,argRadius_Y,argRotation_Angle,argPressure,argType,argModifiers,argPointer_Type);
}

extern "C"
void EDITIONF(ProxyBrowser_SendFocusEvent) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyBrowser> self = (ProxyBrowser*)*pArgInf->m_ppCompoundData;
	bool argSetfocus = pArgInf[1].m_bool;
	self->SendFocusEvent(argSetfocus);
}

extern "C"
void EDITIONF(ProxyBrowser_SendCaptureLostEvent) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyBrowser> self = (ProxyBrowser*)*pArgInf->m_ppCompoundData;
	self->SendCaptureLostEvent();
}

extern "C"
void EDITIONF(ProxyBrowser_NotifyMoveOrResizeStarted) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyBrowser> self = (ProxyBrowser*)*pArgInf->m_ppCompoundData;
	self->NotifyMoveOrResizeStarted();
}

extern "C"
void EDITIONF(ProxyBrowser_SetAudioMuted) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyBrowser> self = (ProxyBrowser*)*pArgInf->m_ppCompoundData;
	bool argMute = pArgInf[1].m_bool;
	self->SetAudioMuted(argMute);
}

extern "C"
void EDITIONF(ProxyBrowser_IsAudioMuted) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_bool = FALSE;
		return ;
	}
	shrewd_ptr<ProxyBrowser> self = (ProxyBrowser*)*pArgInf->m_ppCompoundData;
	pRetData->m_bool = self->IsAudioMuted();
}

extern "C"
void EDITIONF(ProxyBrowser_ShowDevTools) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_int = 0;
		return ;
	}
	shrewd_ptr<ProxyBrowser> self = (ProxyBrowser*)*pArgInf->m_ppCompoundData;
	int argInspect_Element_At_X = pArgInf[1].m_int;
	int argInspect_Element_At_Y = pArgInf[2].m_int;
	pRetData->m_int = self->ShowDevTools(argInspect_Element_At_X,argInspect_Element_At_Y);
}

extern "C"
void EDITIONF(ProxyBrowser_CloseDevTools) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyBrowser> self = (ProxyBrowser*)*pArgInf->m_ppCompoundData;
	self->CloseDevTools();
}

extern "C"
void EDITIONF(ProxyBrowser_HasDevTools) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_bool = FALSE;
		return ;
	}
	shrewd_ptr<ProxyBrowser> self = (ProxyBrowser*)*pArgInf->m_ppCompoundData;
	pRetData->m_bool = self->HasDevTools();
}

extern "C"
void EDITIONF(ProxyBrowser_GetCookieManager) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		
		return ;
	}
	shrewd_ptr<ProxyBrowser> self = (ProxyBrowser*)*pArgInf->m_ppCompoundData;
	shrewd_ptr<ProxyCookieManager> result = self->GetCookieManager();
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
void EDITIONF(ProxyBrowser_AddFirstScriptOnNewDocument) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyBrowser> self = (ProxyBrowser*)*pArgInf->m_ppCompoundData;
	const char* argScript_Code = (NULL==pArgInf[1].m_pText || strlen(pArgInf[1].m_pText) <= 0) ? NULL : pArgInf[1].m_pText;
	self->AddFirstScriptOnNewDocument(argScript_Code);
}

extern "C"
void EDITIONF(ProxyBrowser_SetUserAgentOverride) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyBrowser> self = (ProxyBrowser*)*pArgInf->m_ppCompoundData;
	const char* argUser_Agent = (NULL==pArgInf[1].m_pText || strlen(pArgInf[1].m_pText) <= 0) ? NULL : pArgInf[1].m_pText;
	const char* argApp_Version = (NULL==pArgInf[2].m_pText || strlen(pArgInf[2].m_pText) <= 0) ? NULL : pArgInf[2].m_pText;
	self->SetUserAgentOverride(argUser_Agent,argApp_Version);
}

extern "C"
void EDITIONF(ProxyBrowser_SetTouchEventEmulationEnabled) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyBrowser> self = (ProxyBrowser*)*pArgInf->m_ppCompoundData;
	bool argEnabled = pArgInf[1].m_bool;
	int argMaxtouchpoints = pArgInf[2].m_int;
	self->SetTouchEventEmulationEnabled(argEnabled,argMaxtouchpoints);
}

extern "C"
void EDITIONF(ProxyBrowser_SetGeolocationOverride) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyBrowser> self = (ProxyBrowser*)*pArgInf->m_ppCompoundData;
	float argLatitude = pArgInf[1].m_float;
	float argLongitude = pArgInf[2].m_float;
	float argAccuracy = pArgInf[3].m_float;
	self->SetGeolocationOverride(argLatitude,argLongitude,argAccuracy);
}

extern "C"
void EDITIONF(ProxyBrowser_SetEmulatedMedia) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyBrowser> self = (ProxyBrowser*)*pArgInf->m_ppCompoundData;
	const char* argMedia = (NULL==pArgInf[1].m_pText || strlen(pArgInf[1].m_pText) <= 0) ? NULL : pArgInf[1].m_pText;
	shrewd_ptr<ProxyDictionaryValue> argFeatures = (ProxyDictionaryValue*)*pArgInf[2].m_ppCompoundData;
	self->SetEmulatedMedia(argMedia,argFeatures);
}

extern "C"
void EDITIONF(ProxyBrowser_ClearMediaFeatureOverrides) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyBrowser> self = (ProxyBrowser*)*pArgInf->m_ppCompoundData;
	self->ClearMediaFeatureOverrides();
}

extern "C"
void EDITIONF(ProxyBrowser_EnableDeviceEmulation) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyBrowser> self = (ProxyBrowser*)*pArgInf->m_ppCompoundData;
	shrewd_ptr<ProxyDictionaryValue> argData = (ProxyDictionaryValue*)*pArgInf[1].m_ppCompoundData;
	self->EnableDeviceEmulation(argData);
}

extern "C"
void EDITIONF(ProxyBrowser_DisableDeviceEmulation) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyBrowser> self = (ProxyBrowser*)*pArgInf->m_ppCompoundData;
	self->DisableDeviceEmulation();
}

extern "C"
void EDITIONF(ProxyBrowser_SetEmitTouchEventsForMouse) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyBrowser> self = (ProxyBrowser*)*pArgInf->m_ppCompoundData;
	bool argEnabled = pArgInf[1].m_bool;
	int argConfiguration = pArgInf[2].m_int;
	self->SetEmitTouchEventsForMouse(argEnabled,argConfiguration);
}

extern "C"
void EDITIONF(ProxyBrowser_LoadExtension) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyBrowser> self = (ProxyBrowser*)*pArgInf->m_ppCompoundData;
	const char* argRoot_Directory = (NULL==pArgInf[1].m_pText || strlen(pArgInf[1].m_pText) <= 0) ? NULL : pArgInf[1].m_pText;
	shrewd_ptr<ProxyDictionaryValue> argManifest = (ProxyDictionaryValue*)*pArgInf[2].m_ppCompoundData;
	self->LoadExtension(argRoot_Directory,argManifest);
}

extern "C"
void EDITIONF(ProxyBrowser_DidLoadExtension) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_bool = FALSE;
		return ;
	}
	shrewd_ptr<ProxyBrowser> self = (ProxyBrowser*)*pArgInf->m_ppCompoundData;
	const char* argExtension_Id = (NULL==pArgInf[1].m_pText || strlen(pArgInf[1].m_pText) <= 0) ? NULL : pArgInf[1].m_pText;
	pRetData->m_bool = self->DidLoadExtension(argExtension_Id);
}

extern "C"
void EDITIONF(ProxyBrowser_HasExtension) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_bool = FALSE;
		return ;
	}
	shrewd_ptr<ProxyBrowser> self = (ProxyBrowser*)*pArgInf->m_ppCompoundData;
	const char* argExtension_Id = (NULL==pArgInf[1].m_pText || strlen(pArgInf[1].m_pText) <= 0) ? NULL : pArgInf[1].m_pText;
	pRetData->m_bool = self->HasExtension(argExtension_Id);
}

extern "C"
void EDITIONF(ProxyBrowser_GetExtensions) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		DWORD* InternalPointer = (DWORD*)NotifySys(NRS_MALLOC, 8, 0);
		InternalPointer[0] = 1;
		InternalPointer[1] = 0;
		pRetData->m_pCompoundData = InternalPointer;
		return ;
	}
	shrewd_ptr<ProxyBrowser> self = (ProxyBrowser*)*pArgInf->m_ppCompoundData;
	pRetData->m_pCompoundData = (void*)self->GetExtensions();
}

extern "C"
void EDITIONF(ProxyBrowser_GetExtension) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		
		return ;
	}
	shrewd_ptr<ProxyBrowser> self = (ProxyBrowser*)*pArgInf->m_ppCompoundData;
	const char* argExtension_Id = (NULL==pArgInf[1].m_pText || strlen(pArgInf[1].m_pText) <= 0) ? NULL : pArgInf[1].m_pText;
	shrewd_ptr<ProxyExtension> result = self->GetExtension(argExtension_Id);
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
void EDITIONF(ProxyBrowser_IsBackgroundHost) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_bool = FALSE;
		return ;
	}
	shrewd_ptr<ProxyBrowser> self = (ProxyBrowser*)*pArgInf->m_ppCompoundData;
	pRetData->m_bool = self->IsBackgroundHost();
}

extern "C"
void EDITIONF(ProxyBrowser_GetUserData) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		
		return ;
	}
	shrewd_ptr<ProxyBrowser> self = (ProxyBrowser*)*pArgInf->m_ppCompoundData;
	shrewd_ptr<ProxyListValue> result = self->GetUserData();
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
void EDITIONF(ProxyBrowser_HasPreference) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_bool = FALSE;
		return ;
	}
	shrewd_ptr<ProxyBrowser> self = (ProxyBrowser*)*pArgInf->m_ppCompoundData;
	const char* argName = (NULL==pArgInf[1].m_pText || strlen(pArgInf[1].m_pText) <= 0) ? NULL : pArgInf[1].m_pText;
	pRetData->m_bool = self->HasPreference(argName);
}

extern "C"
void EDITIONF(ProxyBrowser_GetPreference) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		
		return ;
	}
	shrewd_ptr<ProxyBrowser> self = (ProxyBrowser*)*pArgInf->m_ppCompoundData;
	const char* argName = (NULL==pArgInf[1].m_pText || strlen(pArgInf[1].m_pText) <= 0) ? NULL : pArgInf[1].m_pText;
	shrewd_ptr<ProxyValue> result = self->GetPreference(argName);
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
void EDITIONF(ProxyBrowser_GetAllPreferences) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		
		return ;
	}
	shrewd_ptr<ProxyBrowser> self = (ProxyBrowser*)*pArgInf->m_ppCompoundData;
	bool argInclude_Defaults = pArgInf[1].m_bool;
	shrewd_ptr<ProxyDictionaryValue> result = self->GetAllPreferences(argInclude_Defaults);
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
void EDITIONF(ProxyBrowser_CanSetPreference) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_bool = FALSE;
		return ;
	}
	shrewd_ptr<ProxyBrowser> self = (ProxyBrowser*)*pArgInf->m_ppCompoundData;
	const char* argName = (NULL==pArgInf[1].m_pText || strlen(pArgInf[1].m_pText) <= 0) ? NULL : pArgInf[1].m_pText;
	pRetData->m_bool = self->CanSetPreference(argName);
}

extern "C"
void EDITIONF(ProxyBrowser_SetPreference) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_bool = FALSE;
		return ;
	}
	shrewd_ptr<ProxyBrowser> self = (ProxyBrowser*)*pArgInf->m_ppCompoundData;
	const char* argName = (NULL==pArgInf[1].m_pText || strlen(pArgInf[1].m_pText) <= 0) ? NULL : pArgInf[1].m_pText;
	shrewd_ptr<ProxyValue> argValue = (ProxyValue*)*pArgInf[2].m_ppCompoundData;
	pRetData->m_bool = self->SetPreference(argName,argValue);
}



//==========================================

