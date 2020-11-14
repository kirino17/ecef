#include "stdafx.h"
#include <proxy/ProxyBase.h>
#include "def/Power.h"
#include "EPLProxyBase.h"
#include "EPLProxyDOMNode.h"
#include "EPLProxyCollection.h"
#include <proxy/ProxyDOMNode.h>
#include <proxy/ProxyCollection.h>

##{{0}}

namespace Local {
	shrewd_ptr<EPLClient> sharedInstance = NULL;
}

void AquariusProperty::init(void){
	CPropertyInfo::init();
}

BOOL AquariusProperty::Serialize(CArchive& ar){
	if(CPropertyInfo::Serialize(ar) == FALSE){
		return FALSE;
	}

	TRY
	{
		if(ar.IsLoading() == TRUE){
			DWORD dwUnitDataVer;
			ar >> dwUnitDataVer;
			if(dwUnitDataVer > AQUARIUS_UNIT_VER){
				return FALSE;
			}
			ar >> nBorderStyle;
		}
		else {
			ar << (DWORD)AQUARIUS_UNIT_VER << nBorderStyle;
		}
	}
	END_TRY;

	return TRUE;
}

BEGIN_MESSAGE_MAP(AquariusUnit, CWnd)
	ON_WM_SETFOCUS()
    ON_WM_SIZE()
    ON_WM_DESTROY()
	ON_WM_PAINT()
END_MESSAGE_MAP()


AquariusUnit::AquariusUnit():
	propertices(),
	dwWinFormID(0),
	dwUnitID(0),
	inDesignMode(FALSE),
	isDestory(FALSE)
{

}

AquariusUnit::~AquariusUnit(){

}

BOOL AquariusUnit::Create(HWND hParentWnd, DWORD dwStyle, UINT uID,
	INT x, INT y, INT cx, INT cy){
	// if(this->inDesignMode == FALSE){
	// 	dwStyle = (~WS_VISIBLE) & dwStyle;
	// }

	if (!CWnd::CreateEx (NULL, AfxRegisterWndClass (CS_DBLCLKS | CS_HREDRAW | CS_VREDRAW,
		::LoadCursor (NULL, IDC_ARROW), HBRUSH (::GetStockObject (WHITE_BRUSH))),
		_T(""), dwStyle, x, y, cx, cy, hParentWnd, (HMENU)uID, NULL)){

		return FALSE;
	}

	this->SetBorder(this->propertices.nBorderStyle);

	// if(this->inDesignMode){
	// 	hBitmap.LoadBitmap(IDB_WEBSOCKETPROVIDER_BITMAP);
	// }
	
	AfxEnableControlContainer();

	return TRUE;
}

void AquariusUnit::SetBorder(int nType){
	DWORD dwStyle = NULL, dwExStyle = NULL;
	switch (nType)
	{
	case 0:		// 无边框
		break;
	case 1:		// 凹入式
		dwExStyle = WS_EX_CLIENTEDGE;
		break;
	case 2:		// 凸出式
		dwExStyle = WS_EX_DLGMODALFRAME;
		break;
	case 3:		// 浅凹入式
		dwExStyle = WS_EX_STATICEDGE;
		break;
	case 4:		// 镜框式
		dwExStyle = WS_EX_CLIENTEDGE | WS_EX_DLGMODALFRAME;
		break;
	case 5:
		dwStyle = WS_BORDER;
		break;
	}
	this->ModifyStyleEx (WS_EX_STATICEDGE | WS_EX_CLIENTEDGE | WS_EX_DLGMODALFRAME,
		dwExStyle, SWP_NOSIZE | SWP_NOMOVE | SWP_NOZORDER | SWP_NOACTIVATE |
		SWP_FRAMECHANGED | SWP_DRAWFRAME);
	this->ModifyStyle (WS_BORDER, dwStyle,
		SWP_NOSIZE | SWP_NOMOVE | SWP_NOZORDER | SWP_NOACTIVATE |
			SWP_FRAMECHANGED | SWP_DRAWFRAME);
}

void AquariusUnit::OnSetFocus(CWnd* pOldWnd){
	CWnd::OnSetFocus(pOldWnd);
}

void AquariusUnit::OnSize(UINT nType, int cx, int cy){
	CWnd::OnSize(nType, cx, cy);
	shrewd_ptr<EPLClient> client = EPLClient::GetInstance();

	RECT rc;
	GetClientRect(&rc);
	client->OnSizeChanged((unsigned int)this->m_hWnd, rc.right,rc.bottom);
}

void AquariusUnit::OnDestroy(){
	CWnd::OnDestroy();
}

void AquariusUnit::PostNcDestroy(void){
	CWnd::PostNcDestroy();
	NotifySys(NRS_UNIT_DESTROIED, dwWinFormID, dwUnitID);
	
	Power::GetInstance()->Shutdown();

	this->isDestory = TRUE;
	this->release();
}


//////////////////////////////////////////////////////////////////

extern "C"
PFN_INTERFACE WINAPI EDITIONF(GetInterface_Chromium)(INT nInterfaceNO){
	return nInterfaceNO == ITF_CREATE_UNIT ? (PFN_INTERFACE)EDITIONF(Create_Chromium) :
			nInterfaceNO == ITF_NOTIFY_PROPERTY_CHANGED ? (PFN_INTERFACE)EDITIONF(NotifyPropertyChanged_Chromium) :
			nInterfaceNO == ITF_GET_ALL_PROPERTY_DATA ? (PFN_INTERFACE)EDITIONF(GetAllPropertyData_Chromium) :
			nInterfaceNO == ITF_GET_PROPERTY_DATA ? (PFN_INTERFACE)EDITIONF(GetPropertyData_Chromium):
			NULL;
}

HUNIT WINAPI EDITIONF(Create_Chromium)(LPBYTE pAllData, INT nAllDataSize,
	DWORD dwStyle, HWND hParentWnd, UINT uID, HMENU hMenu, INT x, INT y, INT cx, INT cy,
	DWORD dwWinFormID, DWORD dwUnitID, HWND hDesignWnd, BOOL blInDesignMode){

	shrewd_ptr<AquariusUnit> unit = new AquariusUnit();

	if(unit->propertices.LoadData(pAllData, nAllDataSize) == FALSE){
		unit->release();
		return NULL;
	}

	unit->dwWinFormID = dwWinFormID;
	unit->dwUnitID = dwUnitID;
	unit->inDesignMode = blInDesignMode;

	if(unit->Create(hParentWnd, dwStyle | WS_CHILD | WS_CLIPSIBLINGS, uID, x,y,cx,cy)){

		unit->retain();

		EPLClient::GetInstance()->SetMainWindow(unit);

		return (HUNIT)unit.get();
	}

	return NULL;
}

BOOL WINAPI EDITIONF(NotifyPropertyChanged_Chromium) (HUNIT hUnit, INT nPropertyIndex,
	PUNIT_PROPERTY_VALUE pPropertyVaule, LPCTSTR* ppszTipText){
	ASSERT(hUnit != NULL);
	shrewd_ptr<AquariusUnit> unit = (AquariusUnit*)hUnit;

	switch(nPropertyIndex){
	case 0:
		unit->propertices.nBorderStyle = pPropertyVaule->m_int;
		unit->SetBorder(pPropertyVaule->m_int);
		break;
	default:
		break;
	}

	return FALSE;
}

BOOL WINAPI EDITIONF(GetPropertyData_Chromium) (HUNIT hUnit, INT nPropertyIndex,
	PUNIT_PROPERTY_VALUE pPropertyVaule){
	ASSERT(hUnit != NULL);
	shrewd_ptr<AquariusUnit> unit = (AquariusUnit*)hUnit;
	switch(nPropertyIndex){
	case 0:
		pPropertyVaule->m_int = unit->propertices.nBorderStyle;
		break;
	default:
		break;
	}
	return FALSE;
}



HGLOBAL WINAPI EDITIONF(GetAllPropertyData_Chromium) (HUNIT hUnit){
	ASSERT (hUnit != NULL);
	return ((AquariusUnit*)hUnit)->propertices.SaveData ();
}


////////////////////////////////////////////////////
EPLClient::EPLClient():
	m_mainWindow(NULL){

}

EPLClient::~EPLClient(){
	m_mainWindow = NULL;
}

shrewd_ptr<EPLClient> EPLClient::GetInstance(){
	if(!Local::sharedInstance){
		Local::sharedInstance = new EPLClient();
	}
	return Local::sharedInstance;
}

void EPLClient::SetMainWindow(shrewd_ptr<AquariusUnit> window){
	m_mainWindow = window;
}

##{{2}}


extern "C"
void EDITIONF(ProxyClient_CreateBrowser) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	shrewd_ptr<EPLClient> self = EPLClient::GetInstance();
	shrewd_ptr<ProxyWindowInfo> argWininfo = (ProxyWindowInfo*)*pArgInf[1].m_ppCompoundData;
	const char* argUrl = (NULL==pArgInf[2].m_pText || strlen(pArgInf[2].m_pText) <= 0) ? NULL : pArgInf[2].m_pText;
	shrewd_ptr<ProxyBrowserSettings> settings = NULL;
	bool argIncognito_Mode = false;
	if(pArgInf[3].m_dtDataType != _SDT_ALL){
		if(pArgInf[3].m_ppCompoundData && *pArgInf[3].m_ppCompoundData){
			settings = (ProxyBrowserSettings*)*pArgInf[3].m_ppCompoundData;
		}
	}
	if (pArgInf[4].m_dtDataType != _SDT_ALL){
		argIncognito_Mode = pArgInf[4].m_bool;
	}

	pRetData->m_bool = self->CreateBrowser(argWininfo,argUrl,settings,argIncognito_Mode);
}

extern "C"
void EDITIONF(ProxyClient_CloseBrowser) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	shrewd_ptr<EPLClient> self = EPLClient::GetInstance();
	shrewd_ptr<ProxyBrowser> argBrowser = (ProxyBrowser*)*pArgInf[1].m_ppCompoundData;
	bool argForce_Close = false;
	if(pArgInf[2].m_dtDataType != _SDT_ALL){
		argForce_Close = pArgInf[2].m_bool;
	}
	self->CloseBrowser(argBrowser,argForce_Close);
}

extern "C"
void EDITIONF(ProxyClient_SetForeground) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	shrewd_ptr<EPLClient> self = EPLClient::GetInstance();
	unsigned int argParent_Window = pArgInf[1].m_uint;
	shrewd_ptr<ProxyBrowser> argBrowser = (ProxyBrowser*)*pArgInf[2].m_ppCompoundData;
	self->SetForeground(argParent_Window,argBrowser);
}

extern "C"
void EDITIONF(ProxyClient_GetBrowserCount) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	shrewd_ptr<EPLClient> self = EPLClient::GetInstance();
	pRetData->m_int = self->GetBrowserCount();
}

extern "C"
void EDITIONF(ProxyClient_GetBrowserWithHandle) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	shrewd_ptr<EPLClient> self = EPLClient::GetInstance();
	unsigned int argHandle = pArgInf[1].m_uint;
	shrewd_ptr<ProxyBrowser> result = self->GetBrowserWithHandle(argHandle);
	if(result){ 
		result->retain();
		DWORD* InternalPointer = (DWORD*)NotifySys(NRS_MALLOC,4,0);
		*InternalPointer = (DWORD)result.get();
		pRetData->m_pCompoundData = InternalPointer;
	}
}

extern "C"
void EDITIONF(ProxyBase_Initialize) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	shrewd_ptr<ProxySettings> settings = NULL;
	if(pArgInf[0].m_ppCompoundData && *pArgInf[0].m_ppCompoundData){
		settings = (ProxySettings*)*pArgInf[0].m_ppCompoundData;
	}
	shrewd_ptr<EPLClient> client = EPLClient::GetInstance();
	pRetData->m_bool = ProxyBase::Initialize(settings, (DWORD)client.get());
}

extern "C"
void EDITIONF(ProxyClient_GetBrowserWithIndex) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	shrewd_ptr<EPLClient> self = EPLClient::GetInstance();
	unsigned int argIndex = pArgInf[1].m_uint;
	shrewd_ptr<ProxyBrowser> result = self->GetBrowserWithIndex(argIndex);
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
void EDITIONF(ProxyClient_GetIndex) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	shrewd_ptr<EPLClient> self = EPLClient::GetInstance();
	shrewd_ptr<ProxyBrowser> argBrowser = (ProxyBrowser*)*pArgInf[1].m_ppCompoundData;
	pRetData->m_int = self->GetIndex(argBrowser);
}


extern "C"
void EDITIONF(ProxyClient_GetSameOriginBrowser) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	shrewd_ptr<EPLClient> self = EPLClient::GetInstance();
	shrewd_ptr<ProxyBrowser> argBrowser = (ProxyBrowser*)*pArgInf[1].m_ppCompoundData;
	pRetData->m_pCompoundData = (void*)self->GetSameOriginBrowser(argBrowser);
}


void EDITIONF(ProxyBase_CreateValue) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	shrewd_ptr<ProxyValue> object = ProxyBase::CreateValue(0);

	if(object){
		if(pArgInf->m_dtDataType == SDT_BOOL){
			object->SetBool(pArgInf->m_bool);
		}
		else if(pArgInf->m_dtDataType == SDT_INT){
			object->SetInt(pArgInf->m_int);
		}
		else if(pArgInf->m_dtDataType == SDT_BYTE){
			object->SetInt(pArgInf->m_byte);
		}
		else if(pArgInf->m_dtDataType == SDT_SHORT){
			object->SetInt(pArgInf->m_short);
		}
		else if(pArgInf->m_dtDataType == SDT_FLOAT){
			object->SetDouble(pArgInf->m_float);
		}
		else if(pArgInf->m_dtDataType == SDT_DOUBLE){
			object->SetDouble(pArgInf->m_double);
		}
		else if(pArgInf->m_dtDataType == SDT_TEXT){
			object->SetString(pArgInf->m_pText);
		}
		else if(pArgInf->m_dtDataType == SDT_BIN){
			object->SetBinary(pArgInf->m_pBin, *(INT*)&pArgInf->m_pBin[4]);
		}
		else if(pArgInf->m_dtDataType == MAKELONG(shrewd_ptr<ProxyDictionaryValue>)){
			if(pArgInf->m_ppCompoundData && *pArgInf->m_ppCompoundData){
				shrewd_ptr<ProxyDictionaryValue> argValue = (ProxyDictionaryValue*)*pArgInf->m_ppCompoundData;
				object->SetDictionary(argValue);
			}
		}
		else if(pArgInf->m_dtDataType == MAKELONG(shrewd_ptr<ProxyListValue>)){
			if(pArgInf->m_ppCompoundData && *pArgInf->m_ppCompoundData){
				shrewd_ptr<ProxyListValue> argValue = (ProxyListValue*)*pArgInf->m_ppCompoundData;
				object->SetList(argValue);
			}
		}
		object->retain();
		DWORD* InternalPointer = (DWORD*)NotifySys(NRS_MALLOC,4,0);
		*InternalPointer = (DWORD)object.get();
		pRetData->m_pCompoundData = InternalPointer;
	}
	else {
		pRetData->m_pCompoundData = NULL;
	}
}

void EDITIONF(ProxyBase_CreateListValue) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	shrewd_ptr<ProxyListValue> object = ProxyBase::CreateListValue(0);

	if(object){

		for(size_t i = 0; i < nArgCount; i++){
			if (pArgInf[i].m_dtDataType == SDT_BOOL)
			{
				object->SetBool(i,pArgInf[i].m_bool);
			}
			else if (pArgInf[i].m_dtDataType == SDT_INT)
			{
				object->SetInt(i,pArgInf[i].m_int);
			}
			else if (pArgInf[i].m_dtDataType == SDT_BYTE)
			{
				object->SetInt(i,pArgInf[i].m_byte);
			}
			else if (pArgInf[i].m_dtDataType == SDT_SHORT)
			{
				object->SetInt(i,pArgInf[i].m_short);
			}
			else if (pArgInf[i].m_dtDataType == SDT_FLOAT)
			{
				object->SetDouble(i,pArgInf[i].m_float);
			}
			else if (pArgInf[i].m_dtDataType == SDT_DOUBLE)
			{
				object->SetDouble(i,pArgInf[i].m_double);
			}
			else if (pArgInf[i].m_dtDataType == SDT_TEXT)
			{
				object->SetString(i,pArgInf[i].m_pText);
			}
			else if (pArgInf[i].m_dtDataType == SDT_BIN)
			{
				object->SetBinary(i,pArgInf[i].m_pBin, *(INT *)&pArgInf[i].m_pBin[4]);
			}
			else if(pArgInf[i].m_dtDataType == MAKELONG(shrewd_ptr<ProxyDictionaryValue>)){
				if(pArgInf[i].m_ppCompoundData && *pArgInf[i].m_ppCompoundData){
					shrewd_ptr<ProxyDictionaryValue> argValue = (ProxyDictionaryValue*)*pArgInf[i].m_ppCompoundData;
					object->SetDictionary(i,argValue);
				}
			}
			else if(pArgInf[i].m_dtDataType == MAKELONG(shrewd_ptr<ProxyValue>)){
				if(pArgInf[i].m_ppCompoundData && *pArgInf[i].m_ppCompoundData){
					shrewd_ptr<ProxyValue> argValue = (ProxyValue*)*pArgInf[i].m_ppCompoundData;
					object->SetValue(i,argValue);
				}
			}
		}

		object->retain();
		DWORD* InternalPointer = (DWORD*)NotifySys(NRS_MALLOC,4,0);
		*InternalPointer = (DWORD)object.get();
		pRetData->m_pCompoundData = InternalPointer;
	}
	else {
		pRetData->m_pCompoundData = NULL;
	}
}

void EDITIONF(ProxyBase_CreateRequest) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	const char* argMethod = (NULL==pArgInf[0].m_pText || strlen(pArgInf[0].m_pText) <= 0) ? NULL : pArgInf[0].m_pText;
	const char* argUrl = (NULL==pArgInf[1].m_pText || strlen(pArgInf[1].m_pText) <= 0) ? NULL : pArgInf[1].m_pText;
	const char* argReferrer = (NULL==pArgInf[2].m_pText || strlen(pArgInf[2].m_pText) <= 0) ? NULL : pArgInf[2].m_pText;
	const char* argHeadermaps = (NULL==pArgInf[3].m_pText || strlen(pArgInf[3].m_pText) <= 0) ? NULL : pArgInf[3].m_pText;
	shrewd_ptr<ProxyPostDataElement> argPostdata = NULL;
	shrewd_ptr<ProxyRequest> result = ProxyBase::CreateRequest(NULL,NULL,NULL,NULL,NULL);
	if(result){
		result->retain();

		if(argMethod){
			result->SetMethod(argMethod);
		}

		if(argUrl){
			result->SetURL(argUrl);
		}

		if(argReferrer){
			result->SetReferrer(argReferrer, 0);
		}

		if(argHeadermaps){
			result->SetHeaderMap(argHeadermaps);
		}

		if(pArgInf[4].m_dtDataType != _SDT_ALL){
			if(pArgInf[4].m_ppCompoundData && *pArgInf[4].m_ppCompoundData){
				argPostdata = (ProxyPostDataElement*)*pArgInf[4].m_ppCompoundData;
				result->AddPostDataElement(argPostdata);
			}
		}
		DWORD* InternalPointer = (DWORD*)NotifySys(NRS_MALLOC,4,0);
		*InternalPointer = (DWORD)result.get();
		pRetData->m_pCompoundData = InternalPointer;
	}
	else{
		pRetData->m_pCompoundData=NULL;
	}
}

extern "C"
void EDITIONF(ProxyDOMNode_SendEvent) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyDOMNode> self = (ProxyDOMNode*)*pArgInf->m_ppCompoundData;
	const char* argEvt_Name = (NULL==pArgInf[1].m_pText || strlen(pArgInf[1].m_pText) <= 0) ? NULL : pArgInf[1].m_pText;
	shrewd_ptr<ProxyListValue> arguments = NULL;
	if(nArgCount > 1){
		arguments = ProxyBase::CreateListValue(0);
		for(int i=1; i< nArgCount;i++){
			if (pArgInf[i].m_dtDataType == SDT_BOOL)
			{
				arguments->SetBool(i,pArgInf[i].m_bool);
			}
			else if (pArgInf[i].m_dtDataType == SDT_INT)
			{
				arguments->SetInt(i,pArgInf[i].m_int);
			}
			else if (pArgInf[i].m_dtDataType == SDT_BYTE)
			{
				arguments->SetInt(i,pArgInf[i].m_byte);
			}
			else if (pArgInf[i].m_dtDataType == SDT_SHORT)
			{
				arguments->SetInt(i,pArgInf[i].m_short);
			}
			else if (pArgInf[i].m_dtDataType == SDT_FLOAT)
			{
				arguments->SetDouble(i,pArgInf[i].m_float);
			}
			else if (pArgInf[i].m_dtDataType == SDT_DOUBLE)
			{
				arguments->SetDouble(i,pArgInf[i].m_double);
			}
			else if (pArgInf[i].m_dtDataType == SDT_TEXT)
			{
				arguments->SetString(i,pArgInf[i].m_pText);
			}
		}
	}
	self->SendEvent(argEvt_Name,arguments.get());
}

extern "C"
void EDITIONF(ProxyCollection_CreateBrowser) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		
		return ;
	}
	shrewd_ptr<ProxyCollection> self = (ProxyCollection*)*pArgInf->m_ppCompoundData;
	const char* argUrl = (NULL==pArgInf[1].m_pText || strlen(pArgInf[1].m_pText) <= 0) ? NULL : pArgInf[1].m_pText;
	shrewd_ptr<ProxyBrowserSettings> settings = NULL;
	if(pArgInf[2].m_dtDataType != _SDT_ALL){
		if(pArgInf[2].m_ppCompoundData && *pArgInf[2].m_ppCompoundData){
			settings = (ProxyBrowserSettings*)*pArgInf[2].m_ppCompoundData;
		}
	}

	shrewd_ptr<ProxyBrowser> result = self->CreateBrowser(argUrl,settings);
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


#ifdef NOT_USED

##{{3}}

#endif
