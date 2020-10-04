#include "stdafx.h"
#include <proxy/ProxyBase.h>
#include "EPLChromium.h"

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

void EPLClient::OnBeforeCommandLineProcessing(shrewd_ptr<ProxyCommandLine> command_line){
	if(!m_mainWindow || m_mainWindow->isDestory == TRUE){	
		m_mainWindow = NULL;
		return ; 
	}
	ProxyClient::OnBeforeCommandLineProcessing(command_line);
	EVENT_NOTIFY2 arguments(m_mainWindow->dwWinFormID, m_mainWindow->dwUnitID,0);
	arguments.m_nArgCount = 1;
	LPVOID _command_line = command_line.get();
	LPVOID _prawcommand_line = &_command_line;
	arguments.m_arg[0].m_inf.m_ppCompoundData = (void**)&_prawcommand_line;
	arguments.m_arg[0].m_dwState = EAV_IS_POINTER;
	NotifySys(NRS_EVENT_NOTIFY2, (DWORD)&arguments, 0); 
}
void EPLClient::OnContextInitialized(){
	if(!m_mainWindow || m_mainWindow->isDestory == TRUE){	
		m_mainWindow = NULL;
		return ; 
	}
	ProxyClient::OnContextInitialized();
	EVENT_NOTIFY2 arguments(m_mainWindow->dwWinFormID, m_mainWindow->dwUnitID,1);
	arguments.m_nArgCount = 0;
	NotifySys(NRS_EVENT_NOTIFY2, (DWORD)&arguments, 0); 
}
bool EPLClient::OnBeforePopup(shrewd_ptr<ProxyBrowser> browser,shrewd_ptr<ProxyFrame> frame,const char* target_uri,const char* target_frame_name,int target_disposition,bool user_gesture,shrewd_ptr<ProxyPopupFeatures> popupFeatures,shrewd_ptr<ProxyWindowInfo> window_info,shrewd_ptr<ProxyBrowserSettings> settings,shrewd_ptr<ProxyDictionaryValue> extra_info,int& no_javascript_access){
	bool result = NULL; 
	if(!m_mainWindow || m_mainWindow->isDestory == TRUE){	
		m_mainWindow = NULL;
		return result; 
	}
	ProxyClient::OnBeforePopup(browser,frame,target_uri,target_frame_name,target_disposition,user_gesture,popupFeatures,window_info,settings,extra_info,no_javascript_access);
	EVENT_NOTIFY2 arguments(m_mainWindow->dwWinFormID, m_mainWindow->dwUnitID,2);
	arguments.m_nArgCount = 11;
	LPVOID _browser = browser.get();
	LPVOID _prawbrowser = &_browser;
	arguments.m_arg[0].m_inf.m_ppCompoundData = (void**)&_prawbrowser;
	arguments.m_arg[0].m_dwState = EAV_IS_POINTER;
	LPVOID _frame = frame.get();
	LPVOID _prawframe = &_frame;
	arguments.m_arg[1].m_inf.m_ppCompoundData = (void**)&_prawframe;
	arguments.m_arg[1].m_dwState = EAV_IS_POINTER;
	arguments.m_arg[2].m_inf.m_dtDataType = SDT_TEXT;
	arguments.m_arg[2].m_inf.m_ppText = (LPTSTR*)&target_uri;
	arguments.m_arg[2].m_dwState = EAV_IS_POINTER;
	arguments.m_arg[3].m_inf.m_dtDataType = SDT_TEXT;
	arguments.m_arg[3].m_inf.m_ppText = (LPTSTR*)&target_frame_name;
	arguments.m_arg[3].m_dwState = EAV_IS_POINTER;
	arguments.m_arg[4].m_inf.m_dtDataType = SDT_INT;
	arguments.m_arg[4].m_inf.m_int = target_disposition;
	arguments.m_arg[4].m_dwState = 0;
	arguments.m_arg[5].m_inf.m_dtDataType = SDT_BOOL;
	arguments.m_arg[5].m_inf.m_bool = (BOOL)user_gesture;
	arguments.m_arg[5].m_dwState = 0;
	LPVOID _popupFeatures = popupFeatures.get();
	LPVOID _prawpopupFeatures = &_popupFeatures;
	arguments.m_arg[6].m_inf.m_ppCompoundData = (void**)&_prawpopupFeatures;
	arguments.m_arg[6].m_dwState = EAV_IS_POINTER;
	LPVOID _window_info = window_info.get();
	LPVOID _prawwindow_info = &_window_info;
	arguments.m_arg[7].m_inf.m_ppCompoundData = (void**)&_prawwindow_info;
	arguments.m_arg[7].m_dwState = EAV_IS_POINTER;
	LPVOID _settings = settings.get();
	LPVOID _prawsettings = &_settings;
	arguments.m_arg[8].m_inf.m_ppCompoundData = (void**)&_prawsettings;
	arguments.m_arg[8].m_dwState = EAV_IS_POINTER;
	LPVOID _extra_info = extra_info.get();
	LPVOID _prawextra_info = &_extra_info;
	arguments.m_arg[9].m_inf.m_ppCompoundData = (void**)&_prawextra_info;
	arguments.m_arg[9].m_dwState = EAV_IS_POINTER;
	arguments.m_arg[10].m_inf.m_dtDataType = SDT_INT;
	arguments.m_arg[10].m_inf.m_pInt = (int*)&no_javascript_access;
	arguments.m_arg[10].m_dwState = EAV_IS_POINTER;
	if(NotifySys(NRS_EVENT_NOTIFY2, (DWORD)&arguments, 0) != 0){
		if(arguments.m_blHasRetVal){
			result = arguments.m_infRetData.m_bool;
		}
	}
	return result; 
}
void EPLClient::OnAfterCreated(shrewd_ptr<ProxyBrowser> browser){
	if(!m_mainWindow || m_mainWindow->isDestory == TRUE){	
		m_mainWindow = NULL;
		return ; 
	}
	ProxyClient::OnAfterCreated(browser);
	EVENT_NOTIFY2 arguments(m_mainWindow->dwWinFormID, m_mainWindow->dwUnitID,3);
	arguments.m_nArgCount = 1;
	LPVOID _browser = browser.get();
	LPVOID _prawbrowser = &_browser;
	arguments.m_arg[0].m_inf.m_ppCompoundData = (void**)&_prawbrowser;
	arguments.m_arg[0].m_dwState = EAV_IS_POINTER;
	NotifySys(NRS_EVENT_NOTIFY2, (DWORD)&arguments, 0); 
}
void EPLClient::OnBeforeClose(shrewd_ptr<ProxyBrowser> browser){
	if(!m_mainWindow || m_mainWindow->isDestory == TRUE){	
		m_mainWindow = NULL;
		return ; 
	}
	ProxyClient::OnBeforeClose(browser);
	EVENT_NOTIFY2 arguments(m_mainWindow->dwWinFormID, m_mainWindow->dwUnitID,4);
	arguments.m_nArgCount = 1;
	LPVOID _browser = browser.get();
	LPVOID _prawbrowser = &_browser;
	arguments.m_arg[0].m_inf.m_ppCompoundData = (void**)&_prawbrowser;
	arguments.m_arg[0].m_dwState = EAV_IS_POINTER;
	NotifySys(NRS_EVENT_NOTIFY2, (DWORD)&arguments, 0); 
}
bool EPLClient::DoClose(shrewd_ptr<ProxyBrowser> browser){
	bool result = NULL; 
	if(!m_mainWindow || m_mainWindow->isDestory == TRUE){	
		m_mainWindow = NULL;
		return result; 
	}
	ProxyClient::DoClose(browser);
	EVENT_NOTIFY2 arguments(m_mainWindow->dwWinFormID, m_mainWindow->dwUnitID,5);
	arguments.m_nArgCount = 1;
	LPVOID _browser = browser.get();
	LPVOID _prawbrowser = &_browser;
	arguments.m_arg[0].m_inf.m_ppCompoundData = (void**)&_prawbrowser;
	arguments.m_arg[0].m_dwState = EAV_IS_POINTER;
	if(NotifySys(NRS_EVENT_NOTIFY2, (DWORD)&arguments, 0) != 0){
		if(arguments.m_blHasRetVal){
			result = arguments.m_infRetData.m_bool;
		}
	}
	return result; 
}
void EPLClient::OnLoadingStateChange(shrewd_ptr<ProxyBrowser> browser,bool isLoading,bool canGoBack,bool canGoForward){
	if(!m_mainWindow || m_mainWindow->isDestory == TRUE){	
		m_mainWindow = NULL;
		return ; 
	}
	ProxyClient::OnLoadingStateChange(browser,isLoading,canGoBack,canGoForward);
	EVENT_NOTIFY2 arguments(m_mainWindow->dwWinFormID, m_mainWindow->dwUnitID,6);
	arguments.m_nArgCount = 4;
	LPVOID _browser = browser.get();
	LPVOID _prawbrowser = &_browser;
	arguments.m_arg[0].m_inf.m_ppCompoundData = (void**)&_prawbrowser;
	arguments.m_arg[0].m_dwState = EAV_IS_POINTER;
	arguments.m_arg[1].m_inf.m_dtDataType = SDT_BOOL;
	arguments.m_arg[1].m_inf.m_bool = (BOOL)isLoading;
	arguments.m_arg[1].m_dwState = 0;
	arguments.m_arg[2].m_inf.m_dtDataType = SDT_BOOL;
	arguments.m_arg[2].m_inf.m_bool = (BOOL)canGoBack;
	arguments.m_arg[2].m_dwState = 0;
	arguments.m_arg[3].m_inf.m_dtDataType = SDT_BOOL;
	arguments.m_arg[3].m_inf.m_bool = (BOOL)canGoForward;
	arguments.m_arg[3].m_dwState = 0;
	NotifySys(NRS_EVENT_NOTIFY2, (DWORD)&arguments, 0); 
}
void EPLClient::OnLoadStart(shrewd_ptr<ProxyBrowser> browser,shrewd_ptr<ProxyFrame> frame,int transition_type){
	if(!m_mainWindow || m_mainWindow->isDestory == TRUE){	
		m_mainWindow = NULL;
		return ; 
	}
	ProxyClient::OnLoadStart(browser,frame,transition_type);
	EVENT_NOTIFY2 arguments(m_mainWindow->dwWinFormID, m_mainWindow->dwUnitID,7);
	arguments.m_nArgCount = 3;
	LPVOID _browser = browser.get();
	LPVOID _prawbrowser = &_browser;
	arguments.m_arg[0].m_inf.m_ppCompoundData = (void**)&_prawbrowser;
	arguments.m_arg[0].m_dwState = EAV_IS_POINTER;
	LPVOID _frame = frame.get();
	LPVOID _prawframe = &_frame;
	arguments.m_arg[1].m_inf.m_ppCompoundData = (void**)&_prawframe;
	arguments.m_arg[1].m_dwState = EAV_IS_POINTER;
	arguments.m_arg[2].m_inf.m_dtDataType = SDT_INT;
	arguments.m_arg[2].m_inf.m_int = transition_type;
	arguments.m_arg[2].m_dwState = 0;
	NotifySys(NRS_EVENT_NOTIFY2, (DWORD)&arguments, 0); 
}
void EPLClient::OnLoadEnd(shrewd_ptr<ProxyBrowser> browser,shrewd_ptr<ProxyFrame> frame,int httpStatusCode){
	if(!m_mainWindow || m_mainWindow->isDestory == TRUE){	
		m_mainWindow = NULL;
		return ; 
	}
	ProxyClient::OnLoadEnd(browser,frame,httpStatusCode);
	EVENT_NOTIFY2 arguments(m_mainWindow->dwWinFormID, m_mainWindow->dwUnitID,8);
	arguments.m_nArgCount = 3;
	LPVOID _browser = browser.get();
	LPVOID _prawbrowser = &_browser;
	arguments.m_arg[0].m_inf.m_ppCompoundData = (void**)&_prawbrowser;
	arguments.m_arg[0].m_dwState = EAV_IS_POINTER;
	LPVOID _frame = frame.get();
	LPVOID _prawframe = &_frame;
	arguments.m_arg[1].m_inf.m_ppCompoundData = (void**)&_prawframe;
	arguments.m_arg[1].m_dwState = EAV_IS_POINTER;
	arguments.m_arg[2].m_inf.m_dtDataType = SDT_INT;
	arguments.m_arg[2].m_inf.m_int = httpStatusCode;
	arguments.m_arg[2].m_dwState = 0;
	NotifySys(NRS_EVENT_NOTIFY2, (DWORD)&arguments, 0); 
}
void EPLClient::OnLoadError(shrewd_ptr<ProxyBrowser> browser,shrewd_ptr<ProxyFrame> frame,int errorCode,const char* errorText,const char* failedUrl){
	if(!m_mainWindow || m_mainWindow->isDestory == TRUE){	
		m_mainWindow = NULL;
		return ; 
	}
	ProxyClient::OnLoadError(browser,frame,errorCode,errorText,failedUrl);
	EVENT_NOTIFY2 arguments(m_mainWindow->dwWinFormID, m_mainWindow->dwUnitID,9);
	arguments.m_nArgCount = 5;
	LPVOID _browser = browser.get();
	LPVOID _prawbrowser = &_browser;
	arguments.m_arg[0].m_inf.m_ppCompoundData = (void**)&_prawbrowser;
	arguments.m_arg[0].m_dwState = EAV_IS_POINTER;
	LPVOID _frame = frame.get();
	LPVOID _prawframe = &_frame;
	arguments.m_arg[1].m_inf.m_ppCompoundData = (void**)&_prawframe;
	arguments.m_arg[1].m_dwState = EAV_IS_POINTER;
	arguments.m_arg[2].m_inf.m_dtDataType = SDT_INT;
	arguments.m_arg[2].m_inf.m_int = errorCode;
	arguments.m_arg[2].m_dwState = 0;
	arguments.m_arg[3].m_inf.m_dtDataType = SDT_TEXT;
	arguments.m_arg[3].m_inf.m_ppText = (LPTSTR*)&errorText;
	arguments.m_arg[3].m_dwState = EAV_IS_POINTER;
	arguments.m_arg[4].m_inf.m_dtDataType = SDT_TEXT;
	arguments.m_arg[4].m_inf.m_ppText = (LPTSTR*)&failedUrl;
	arguments.m_arg[4].m_dwState = EAV_IS_POINTER;
	NotifySys(NRS_EVENT_NOTIFY2, (DWORD)&arguments, 0); 
}
void EPLClient::OnAddressChange(shrewd_ptr<ProxyBrowser> browser,shrewd_ptr<ProxyFrame> frame,const char* url){
	if(!m_mainWindow || m_mainWindow->isDestory == TRUE){	
		m_mainWindow = NULL;
		return ; 
	}
	ProxyClient::OnAddressChange(browser,frame,url);
	EVENT_NOTIFY2 arguments(m_mainWindow->dwWinFormID, m_mainWindow->dwUnitID,10);
	arguments.m_nArgCount = 3;
	LPVOID _browser = browser.get();
	LPVOID _prawbrowser = &_browser;
	arguments.m_arg[0].m_inf.m_ppCompoundData = (void**)&_prawbrowser;
	arguments.m_arg[0].m_dwState = EAV_IS_POINTER;
	LPVOID _frame = frame.get();
	LPVOID _prawframe = &_frame;
	arguments.m_arg[1].m_inf.m_ppCompoundData = (void**)&_prawframe;
	arguments.m_arg[1].m_dwState = EAV_IS_POINTER;
	arguments.m_arg[2].m_inf.m_dtDataType = SDT_TEXT;
	arguments.m_arg[2].m_inf.m_ppText = (LPTSTR*)&url;
	arguments.m_arg[2].m_dwState = EAV_IS_POINTER;
	NotifySys(NRS_EVENT_NOTIFY2, (DWORD)&arguments, 0); 
}
void EPLClient::OnTitleChange(shrewd_ptr<ProxyBrowser> browser,const char* title){
	if(!m_mainWindow || m_mainWindow->isDestory == TRUE){	
		m_mainWindow = NULL;
		return ; 
	}
	ProxyClient::OnTitleChange(browser,title);
	EVENT_NOTIFY2 arguments(m_mainWindow->dwWinFormID, m_mainWindow->dwUnitID,11);
	arguments.m_nArgCount = 2;
	LPVOID _browser = browser.get();
	LPVOID _prawbrowser = &_browser;
	arguments.m_arg[0].m_inf.m_ppCompoundData = (void**)&_prawbrowser;
	arguments.m_arg[0].m_dwState = EAV_IS_POINTER;
	arguments.m_arg[1].m_inf.m_dtDataType = SDT_TEXT;
	arguments.m_arg[1].m_inf.m_ppText = (LPTSTR*)&title;
	arguments.m_arg[1].m_dwState = EAV_IS_POINTER;
	NotifySys(NRS_EVENT_NOTIFY2, (DWORD)&arguments, 0); 
}
void EPLClient::OnFaviconURLChange(shrewd_ptr<ProxyBrowser> browser,char* icon_urls){
	if(!m_mainWindow || m_mainWindow->isDestory == TRUE){	
		m_mainWindow = NULL;
		return ; 
	}
	ProxyClient::OnFaviconURLChange(browser,icon_urls);
	EVENT_NOTIFY2 arguments(m_mainWindow->dwWinFormID, m_mainWindow->dwUnitID,12);
	arguments.m_nArgCount = 2;
	LPVOID _browser = browser.get();
	LPVOID _prawbrowser = &_browser;
	arguments.m_arg[0].m_inf.m_ppCompoundData = (void**)&_prawbrowser;
	arguments.m_arg[0].m_dwState = EAV_IS_POINTER;
	arguments.m_arg[1].m_inf.m_dtDataType = SDT_TEXT;
	arguments.m_arg[1].m_inf.m_ppText = (LPTSTR*)&icon_urls;
	arguments.m_arg[1].m_dwState = EAV_IS_POINTER;
	NotifySys(NRS_EVENT_NOTIFY2, (DWORD)&arguments, 0); 
}
void EPLClient::OnFullscreenModeChange(shrewd_ptr<ProxyBrowser> browser,bool fullscreen){
	if(!m_mainWindow || m_mainWindow->isDestory == TRUE){	
		m_mainWindow = NULL;
		return ; 
	}
	ProxyClient::OnFullscreenModeChange(browser,fullscreen);
	EVENT_NOTIFY2 arguments(m_mainWindow->dwWinFormID, m_mainWindow->dwUnitID,13);
	arguments.m_nArgCount = 2;
	LPVOID _browser = browser.get();
	LPVOID _prawbrowser = &_browser;
	arguments.m_arg[0].m_inf.m_ppCompoundData = (void**)&_prawbrowser;
	arguments.m_arg[0].m_dwState = EAV_IS_POINTER;
	arguments.m_arg[1].m_inf.m_dtDataType = SDT_BOOL;
	arguments.m_arg[1].m_inf.m_bool = (BOOL)fullscreen;
	arguments.m_arg[1].m_dwState = 0;
	NotifySys(NRS_EVENT_NOTIFY2, (DWORD)&arguments, 0); 
}
bool EPLClient::OnTooltip(shrewd_ptr<ProxyBrowser> browser,const char* text){
	bool result = NULL; 
	if(!m_mainWindow || m_mainWindow->isDestory == TRUE){	
		m_mainWindow = NULL;
		return result; 
	}
	ProxyClient::OnTooltip(browser,text);
	EVENT_NOTIFY2 arguments(m_mainWindow->dwWinFormID, m_mainWindow->dwUnitID,14);
	arguments.m_nArgCount = 2;
	LPVOID _browser = browser.get();
	LPVOID _prawbrowser = &_browser;
	arguments.m_arg[0].m_inf.m_ppCompoundData = (void**)&_prawbrowser;
	arguments.m_arg[0].m_dwState = EAV_IS_POINTER;
	arguments.m_arg[1].m_inf.m_dtDataType = SDT_TEXT;
	arguments.m_arg[1].m_inf.m_ppText = (LPTSTR*)&text;
	arguments.m_arg[1].m_dwState = EAV_IS_POINTER;
	if(NotifySys(NRS_EVENT_NOTIFY2, (DWORD)&arguments, 0) != 0){
		if(arguments.m_blHasRetVal){
			result = arguments.m_infRetData.m_bool;
		}
	}
	return result; 
}
void EPLClient::OnStatusMessage(shrewd_ptr<ProxyBrowser> browser,const char* value){
	if(!m_mainWindow || m_mainWindow->isDestory == TRUE){	
		m_mainWindow = NULL;
		return ; 
	}
	ProxyClient::OnStatusMessage(browser,value);
	EVENT_NOTIFY2 arguments(m_mainWindow->dwWinFormID, m_mainWindow->dwUnitID,15);
	arguments.m_nArgCount = 2;
	LPVOID _browser = browser.get();
	LPVOID _prawbrowser = &_browser;
	arguments.m_arg[0].m_inf.m_ppCompoundData = (void**)&_prawbrowser;
	arguments.m_arg[0].m_dwState = EAV_IS_POINTER;
	arguments.m_arg[1].m_inf.m_dtDataType = SDT_TEXT;
	arguments.m_arg[1].m_inf.m_ppText = (LPTSTR*)&value;
	arguments.m_arg[1].m_dwState = EAV_IS_POINTER;
	NotifySys(NRS_EVENT_NOTIFY2, (DWORD)&arguments, 0); 
}
bool EPLClient::OnConsoleMessage(shrewd_ptr<ProxyBrowser> browser,int level,const char* message,const char* source,int line){
	bool result = NULL; 
	if(!m_mainWindow || m_mainWindow->isDestory == TRUE){	
		m_mainWindow = NULL;
		return result; 
	}
	ProxyClient::OnConsoleMessage(browser,level,message,source,line);
	EVENT_NOTIFY2 arguments(m_mainWindow->dwWinFormID, m_mainWindow->dwUnitID,16);
	arguments.m_nArgCount = 5;
	LPVOID _browser = browser.get();
	LPVOID _prawbrowser = &_browser;
	arguments.m_arg[0].m_inf.m_ppCompoundData = (void**)&_prawbrowser;
	arguments.m_arg[0].m_dwState = EAV_IS_POINTER;
	arguments.m_arg[1].m_inf.m_dtDataType = SDT_INT;
	arguments.m_arg[1].m_inf.m_int = level;
	arguments.m_arg[1].m_dwState = 0;
	arguments.m_arg[2].m_inf.m_dtDataType = SDT_TEXT;
	arguments.m_arg[2].m_inf.m_ppText = (LPTSTR*)&message;
	arguments.m_arg[2].m_dwState = EAV_IS_POINTER;
	arguments.m_arg[3].m_inf.m_dtDataType = SDT_TEXT;
	arguments.m_arg[3].m_inf.m_ppText = (LPTSTR*)&source;
	arguments.m_arg[3].m_dwState = EAV_IS_POINTER;
	arguments.m_arg[4].m_inf.m_dtDataType = SDT_INT;
	arguments.m_arg[4].m_inf.m_int = line;
	arguments.m_arg[4].m_dwState = 0;
	if(NotifySys(NRS_EVENT_NOTIFY2, (DWORD)&arguments, 0) != 0){
		if(arguments.m_blHasRetVal){
			result = arguments.m_infRetData.m_bool;
		}
	}
	return result; 
}
bool EPLClient::OnAutoResize(shrewd_ptr<ProxyBrowser> browser,int width,int height){
	bool result = NULL; 
	if(!m_mainWindow || m_mainWindow->isDestory == TRUE){	
		m_mainWindow = NULL;
		return result; 
	}
	ProxyClient::OnAutoResize(browser,width,height);
	EVENT_NOTIFY2 arguments(m_mainWindow->dwWinFormID, m_mainWindow->dwUnitID,17);
	arguments.m_nArgCount = 3;
	LPVOID _browser = browser.get();
	LPVOID _prawbrowser = &_browser;
	arguments.m_arg[0].m_inf.m_ppCompoundData = (void**)&_prawbrowser;
	arguments.m_arg[0].m_dwState = EAV_IS_POINTER;
	arguments.m_arg[1].m_inf.m_dtDataType = SDT_INT;
	arguments.m_arg[1].m_inf.m_int = width;
	arguments.m_arg[1].m_dwState = 0;
	arguments.m_arg[2].m_inf.m_dtDataType = SDT_INT;
	arguments.m_arg[2].m_inf.m_int = height;
	arguments.m_arg[2].m_dwState = 0;
	if(NotifySys(NRS_EVENT_NOTIFY2, (DWORD)&arguments, 0) != 0){
		if(arguments.m_blHasRetVal){
			result = arguments.m_infRetData.m_bool;
		}
	}
	return result; 
}
void EPLClient::OnLoadingProgressChange(shrewd_ptr<ProxyBrowser> browser,double progress){
	if(!m_mainWindow || m_mainWindow->isDestory == TRUE){	
		m_mainWindow = NULL;
		return ; 
	}
	ProxyClient::OnLoadingProgressChange(browser,progress);
	EVENT_NOTIFY2 arguments(m_mainWindow->dwWinFormID, m_mainWindow->dwUnitID,18);
	arguments.m_nArgCount = 2;
	LPVOID _browser = browser.get();
	LPVOID _prawbrowser = &_browser;
	arguments.m_arg[0].m_inf.m_ppCompoundData = (void**)&_prawbrowser;
	arguments.m_arg[0].m_dwState = EAV_IS_POINTER;
	arguments.m_arg[1].m_inf.m_dtDataType = SDT_DOUBLE;
	arguments.m_arg[1].m_inf.m_double = progress;
	arguments.m_arg[1].m_dwState = 0;
	NotifySys(NRS_EVENT_NOTIFY2, (DWORD)&arguments, 0); 
}
void EPLClient::OnTakeFocus(shrewd_ptr<ProxyBrowser> browser,bool next){
	if(!m_mainWindow || m_mainWindow->isDestory == TRUE){	
		m_mainWindow = NULL;
		return ; 
	}
	ProxyClient::OnTakeFocus(browser,next);
	EVENT_NOTIFY2 arguments(m_mainWindow->dwWinFormID, m_mainWindow->dwUnitID,19);
	arguments.m_nArgCount = 2;
	LPVOID _browser = browser.get();
	LPVOID _prawbrowser = &_browser;
	arguments.m_arg[0].m_inf.m_ppCompoundData = (void**)&_prawbrowser;
	arguments.m_arg[0].m_dwState = EAV_IS_POINTER;
	arguments.m_arg[1].m_inf.m_dtDataType = SDT_BOOL;
	arguments.m_arg[1].m_inf.m_bool = (BOOL)next;
	arguments.m_arg[1].m_dwState = 0;
	NotifySys(NRS_EVENT_NOTIFY2, (DWORD)&arguments, 0); 
}
bool EPLClient::OnSetFocus(shrewd_ptr<ProxyBrowser> browser,int source){
	bool result = NULL; 
	if(!m_mainWindow || m_mainWindow->isDestory == TRUE){	
		m_mainWindow = NULL;
		return result; 
	}
	ProxyClient::OnSetFocus(browser,source);
	EVENT_NOTIFY2 arguments(m_mainWindow->dwWinFormID, m_mainWindow->dwUnitID,20);
	arguments.m_nArgCount = 2;
	LPVOID _browser = browser.get();
	LPVOID _prawbrowser = &_browser;
	arguments.m_arg[0].m_inf.m_ppCompoundData = (void**)&_prawbrowser;
	arguments.m_arg[0].m_dwState = EAV_IS_POINTER;
	arguments.m_arg[1].m_inf.m_dtDataType = SDT_INT;
	arguments.m_arg[1].m_inf.m_int = source;
	arguments.m_arg[1].m_dwState = 0;
	if(NotifySys(NRS_EVENT_NOTIFY2, (DWORD)&arguments, 0) != 0){
		if(arguments.m_blHasRetVal){
			result = arguments.m_infRetData.m_bool;
		}
	}
	return result; 
}
void EPLClient::OnGotFocus(shrewd_ptr<ProxyBrowser> browser){
	if(!m_mainWindow || m_mainWindow->isDestory == TRUE){	
		m_mainWindow = NULL;
		return ; 
	}
	ProxyClient::OnGotFocus(browser);
	EVENT_NOTIFY2 arguments(m_mainWindow->dwWinFormID, m_mainWindow->dwUnitID,21);
	arguments.m_nArgCount = 1;
	LPVOID _browser = browser.get();
	LPVOID _prawbrowser = &_browser;
	arguments.m_arg[0].m_inf.m_ppCompoundData = (void**)&_prawbrowser;
	arguments.m_arg[0].m_dwState = EAV_IS_POINTER;
	NotifySys(NRS_EVENT_NOTIFY2, (DWORD)&arguments, 0); 
}
bool EPLClient::OnJSDialog(shrewd_ptr<ProxyBrowser> browser,const char* origin_url,int dialog_type,const char* message_text,const char* default_prompt_text,shrewd_ptr<ProxyJSDialogCallback> callback,int& suppress_message){
	bool result = NULL; 
	if(!m_mainWindow || m_mainWindow->isDestory == TRUE){	
		m_mainWindow = NULL;
		return result; 
	}
	ProxyClient::OnJSDialog(browser,origin_url,dialog_type,message_text,default_prompt_text,callback,suppress_message);
	EVENT_NOTIFY2 arguments(m_mainWindow->dwWinFormID, m_mainWindow->dwUnitID,22);
	arguments.m_nArgCount = 7;
	LPVOID _browser = browser.get();
	LPVOID _prawbrowser = &_browser;
	arguments.m_arg[0].m_inf.m_ppCompoundData = (void**)&_prawbrowser;
	arguments.m_arg[0].m_dwState = EAV_IS_POINTER;
	arguments.m_arg[1].m_inf.m_dtDataType = SDT_TEXT;
	arguments.m_arg[1].m_inf.m_ppText = (LPTSTR*)&origin_url;
	arguments.m_arg[1].m_dwState = EAV_IS_POINTER;
	arguments.m_arg[2].m_inf.m_dtDataType = SDT_INT;
	arguments.m_arg[2].m_inf.m_int = dialog_type;
	arguments.m_arg[2].m_dwState = 0;
	arguments.m_arg[3].m_inf.m_dtDataType = SDT_TEXT;
	arguments.m_arg[3].m_inf.m_ppText = (LPTSTR*)&message_text;
	arguments.m_arg[3].m_dwState = EAV_IS_POINTER;
	arguments.m_arg[4].m_inf.m_dtDataType = SDT_TEXT;
	arguments.m_arg[4].m_inf.m_ppText = (LPTSTR*)&default_prompt_text;
	arguments.m_arg[4].m_dwState = EAV_IS_POINTER;
	LPVOID _callback = callback.get();
	LPVOID _prawcallback = &_callback;
	arguments.m_arg[5].m_inf.m_ppCompoundData = (void**)&_prawcallback;
	arguments.m_arg[5].m_dwState = EAV_IS_POINTER;
	arguments.m_arg[6].m_inf.m_dtDataType = SDT_INT;
	arguments.m_arg[6].m_inf.m_pInt = (int*)&suppress_message;
	arguments.m_arg[6].m_dwState = EAV_IS_POINTER;
	if(NotifySys(NRS_EVENT_NOTIFY2, (DWORD)&arguments, 0) != 0){
		if(arguments.m_blHasRetVal){
			result = arguments.m_infRetData.m_bool;
		}
	}
	return result; 
}
bool EPLClient::OnBeforeUnloadDialog(shrewd_ptr<ProxyBrowser> browser,const char* message_text,bool is_reload,shrewd_ptr<ProxyJSDialogCallback> callback){
	bool result = NULL; 
	if(!m_mainWindow || m_mainWindow->isDestory == TRUE){	
		m_mainWindow = NULL;
		return result; 
	}
	ProxyClient::OnBeforeUnloadDialog(browser,message_text,is_reload,callback);
	EVENT_NOTIFY2 arguments(m_mainWindow->dwWinFormID, m_mainWindow->dwUnitID,23);
	arguments.m_nArgCount = 4;
	LPVOID _browser = browser.get();
	LPVOID _prawbrowser = &_browser;
	arguments.m_arg[0].m_inf.m_ppCompoundData = (void**)&_prawbrowser;
	arguments.m_arg[0].m_dwState = EAV_IS_POINTER;
	arguments.m_arg[1].m_inf.m_dtDataType = SDT_TEXT;
	arguments.m_arg[1].m_inf.m_ppText = (LPTSTR*)&message_text;
	arguments.m_arg[1].m_dwState = EAV_IS_POINTER;
	arguments.m_arg[2].m_inf.m_dtDataType = SDT_BOOL;
	arguments.m_arg[2].m_inf.m_bool = (BOOL)is_reload;
	arguments.m_arg[2].m_dwState = 0;
	LPVOID _callback = callback.get();
	LPVOID _prawcallback = &_callback;
	arguments.m_arg[3].m_inf.m_ppCompoundData = (void**)&_prawcallback;
	arguments.m_arg[3].m_dwState = EAV_IS_POINTER;
	if(NotifySys(NRS_EVENT_NOTIFY2, (DWORD)&arguments, 0) != 0){
		if(arguments.m_blHasRetVal){
			result = arguments.m_infRetData.m_bool;
		}
	}
	return result; 
}
void EPLClient::OnResetDialogState(shrewd_ptr<ProxyBrowser> browser){
	if(!m_mainWindow || m_mainWindow->isDestory == TRUE){	
		m_mainWindow = NULL;
		return ; 
	}
	ProxyClient::OnResetDialogState(browser);
	EVENT_NOTIFY2 arguments(m_mainWindow->dwWinFormID, m_mainWindow->dwUnitID,24);
	arguments.m_nArgCount = 1;
	LPVOID _browser = browser.get();
	LPVOID _prawbrowser = &_browser;
	arguments.m_arg[0].m_inf.m_ppCompoundData = (void**)&_prawbrowser;
	arguments.m_arg[0].m_dwState = EAV_IS_POINTER;
	NotifySys(NRS_EVENT_NOTIFY2, (DWORD)&arguments, 0); 
}
void EPLClient::OnDialogClosed(shrewd_ptr<ProxyBrowser> browser){
	if(!m_mainWindow || m_mainWindow->isDestory == TRUE){	
		m_mainWindow = NULL;
		return ; 
	}
	ProxyClient::OnDialogClosed(browser);
	EVENT_NOTIFY2 arguments(m_mainWindow->dwWinFormID, m_mainWindow->dwUnitID,25);
	arguments.m_nArgCount = 1;
	LPVOID _browser = browser.get();
	LPVOID _prawbrowser = &_browser;
	arguments.m_arg[0].m_inf.m_ppCompoundData = (void**)&_prawbrowser;
	arguments.m_arg[0].m_dwState = EAV_IS_POINTER;
	NotifySys(NRS_EVENT_NOTIFY2, (DWORD)&arguments, 0); 
}
bool EPLClient::OnBeforeBrowse(shrewd_ptr<ProxyBrowser> browser,shrewd_ptr<ProxyFrame> frame,shrewd_ptr<ProxyRequest> request,bool user_gesture,bool is_redirect){
	bool result = NULL; 
	if(!m_mainWindow || m_mainWindow->isDestory == TRUE){	
		m_mainWindow = NULL;
		return result; 
	}
	ProxyClient::OnBeforeBrowse(browser,frame,request,user_gesture,is_redirect);
	EVENT_NOTIFY2 arguments(m_mainWindow->dwWinFormID, m_mainWindow->dwUnitID,26);
	arguments.m_nArgCount = 5;
	LPVOID _browser = browser.get();
	LPVOID _prawbrowser = &_browser;
	arguments.m_arg[0].m_inf.m_ppCompoundData = (void**)&_prawbrowser;
	arguments.m_arg[0].m_dwState = EAV_IS_POINTER;
	LPVOID _frame = frame.get();
	LPVOID _prawframe = &_frame;
	arguments.m_arg[1].m_inf.m_ppCompoundData = (void**)&_prawframe;
	arguments.m_arg[1].m_dwState = EAV_IS_POINTER;
	LPVOID _request = request.get();
	LPVOID _prawrequest = &_request;
	arguments.m_arg[2].m_inf.m_ppCompoundData = (void**)&_prawrequest;
	arguments.m_arg[2].m_dwState = EAV_IS_POINTER;
	arguments.m_arg[3].m_inf.m_dtDataType = SDT_BOOL;
	arguments.m_arg[3].m_inf.m_bool = (BOOL)user_gesture;
	arguments.m_arg[3].m_dwState = 0;
	arguments.m_arg[4].m_inf.m_dtDataType = SDT_BOOL;
	arguments.m_arg[4].m_inf.m_bool = (BOOL)is_redirect;
	arguments.m_arg[4].m_dwState = 0;
	if(NotifySys(NRS_EVENT_NOTIFY2, (DWORD)&arguments, 0) != 0){
		if(arguments.m_blHasRetVal){
			result = arguments.m_infRetData.m_bool;
		}
	}
	return result; 
}
bool EPLClient::OnOpenURLFromTab(shrewd_ptr<ProxyBrowser> browser,shrewd_ptr<ProxyFrame> frame,const char* target_url,int target_disposition,bool user_gesture){
	bool result = NULL; 
	if(!m_mainWindow || m_mainWindow->isDestory == TRUE){	
		m_mainWindow = NULL;
		return result; 
	}
	ProxyClient::OnOpenURLFromTab(browser,frame,target_url,target_disposition,user_gesture);
	EVENT_NOTIFY2 arguments(m_mainWindow->dwWinFormID, m_mainWindow->dwUnitID,27);
	arguments.m_nArgCount = 5;
	LPVOID _browser = browser.get();
	LPVOID _prawbrowser = &_browser;
	arguments.m_arg[0].m_inf.m_ppCompoundData = (void**)&_prawbrowser;
	arguments.m_arg[0].m_dwState = EAV_IS_POINTER;
	LPVOID _frame = frame.get();
	LPVOID _prawframe = &_frame;
	arguments.m_arg[1].m_inf.m_ppCompoundData = (void**)&_prawframe;
	arguments.m_arg[1].m_dwState = EAV_IS_POINTER;
	arguments.m_arg[2].m_inf.m_dtDataType = SDT_TEXT;
	arguments.m_arg[2].m_inf.m_ppText = (LPTSTR*)&target_url;
	arguments.m_arg[2].m_dwState = EAV_IS_POINTER;
	arguments.m_arg[3].m_inf.m_dtDataType = SDT_INT;
	arguments.m_arg[3].m_inf.m_int = target_disposition;
	arguments.m_arg[3].m_dwState = 0;
	arguments.m_arg[4].m_inf.m_dtDataType = SDT_BOOL;
	arguments.m_arg[4].m_inf.m_bool = (BOOL)user_gesture;
	arguments.m_arg[4].m_dwState = 0;
	if(NotifySys(NRS_EVENT_NOTIFY2, (DWORD)&arguments, 0) != 0){
		if(arguments.m_blHasRetVal){
			result = arguments.m_infRetData.m_bool;
		}
	}
	return result; 
}
bool EPLClient::GetResourceRequestHandler(shrewd_ptr<ProxyBrowser> browser,shrewd_ptr<ProxyFrame> frame,shrewd_ptr<ProxyRequest> request,bool is_navigation,bool is_download,const char* request_initiator){
	bool result = NULL; 
	if(!m_mainWindow || m_mainWindow->isDestory == TRUE){	
		m_mainWindow = NULL;
		return result; 
	}
	ProxyClient::GetResourceRequestHandler(browser,frame,request,is_navigation,is_download,request_initiator);
	EVENT_NOTIFY2 arguments(m_mainWindow->dwWinFormID, m_mainWindow->dwUnitID,28);
	arguments.m_nArgCount = 6;
	LPVOID _browser = browser.get();
	LPVOID _prawbrowser = &_browser;
	arguments.m_arg[0].m_inf.m_ppCompoundData = (void**)&_prawbrowser;
	arguments.m_arg[0].m_dwState = EAV_IS_POINTER;
	LPVOID _frame = frame.get();
	LPVOID _prawframe = &_frame;
	arguments.m_arg[1].m_inf.m_ppCompoundData = (void**)&_prawframe;
	arguments.m_arg[1].m_dwState = EAV_IS_POINTER;
	LPVOID _request = request.get();
	LPVOID _prawrequest = &_request;
	arguments.m_arg[2].m_inf.m_ppCompoundData = (void**)&_prawrequest;
	arguments.m_arg[2].m_dwState = EAV_IS_POINTER;
	arguments.m_arg[3].m_inf.m_dtDataType = SDT_BOOL;
	arguments.m_arg[3].m_inf.m_bool = (BOOL)is_navigation;
	arguments.m_arg[3].m_dwState = 0;
	arguments.m_arg[4].m_inf.m_dtDataType = SDT_BOOL;
	arguments.m_arg[4].m_inf.m_bool = (BOOL)is_download;
	arguments.m_arg[4].m_dwState = 0;
	arguments.m_arg[5].m_inf.m_dtDataType = SDT_TEXT;
	arguments.m_arg[5].m_inf.m_ppText = (LPTSTR*)&request_initiator;
	arguments.m_arg[5].m_dwState = EAV_IS_POINTER;
	if(NotifySys(NRS_EVENT_NOTIFY2, (DWORD)&arguments, 0) != 0){
		if(arguments.m_blHasRetVal){
			result = arguments.m_infRetData.m_bool;
		}
	}
	return result; 
}
bool EPLClient::GetAuthCredentials(shrewd_ptr<ProxyBrowser> browser,const char* origin_url,bool isProxy,const char* host,int port,const char* realm,const char* scheme,shrewd_ptr<ProxyAuthCallback> callback){
	bool result = NULL; 
	if(!m_mainWindow || m_mainWindow->isDestory == TRUE){	
		m_mainWindow = NULL;
		return result; 
	}
	ProxyClient::GetAuthCredentials(browser,origin_url,isProxy,host,port,realm,scheme,callback);
	EVENT_NOTIFY2 arguments(m_mainWindow->dwWinFormID, m_mainWindow->dwUnitID,29);
	arguments.m_nArgCount = 8;
	LPVOID _browser = browser.get();
	LPVOID _prawbrowser = &_browser;
	arguments.m_arg[0].m_inf.m_ppCompoundData = (void**)&_prawbrowser;
	arguments.m_arg[0].m_dwState = EAV_IS_POINTER;
	arguments.m_arg[1].m_inf.m_dtDataType = SDT_TEXT;
	arguments.m_arg[1].m_inf.m_ppText = (LPTSTR*)&origin_url;
	arguments.m_arg[1].m_dwState = EAV_IS_POINTER;
	arguments.m_arg[2].m_inf.m_dtDataType = SDT_BOOL;
	arguments.m_arg[2].m_inf.m_bool = (BOOL)isProxy;
	arguments.m_arg[2].m_dwState = 0;
	arguments.m_arg[3].m_inf.m_dtDataType = SDT_TEXT;
	arguments.m_arg[3].m_inf.m_ppText = (LPTSTR*)&host;
	arguments.m_arg[3].m_dwState = EAV_IS_POINTER;
	arguments.m_arg[4].m_inf.m_dtDataType = SDT_INT;
	arguments.m_arg[4].m_inf.m_int = port;
	arguments.m_arg[4].m_dwState = 0;
	arguments.m_arg[5].m_inf.m_dtDataType = SDT_TEXT;
	arguments.m_arg[5].m_inf.m_ppText = (LPTSTR*)&realm;
	arguments.m_arg[5].m_dwState = EAV_IS_POINTER;
	arguments.m_arg[6].m_inf.m_dtDataType = SDT_TEXT;
	arguments.m_arg[6].m_inf.m_ppText = (LPTSTR*)&scheme;
	arguments.m_arg[6].m_dwState = EAV_IS_POINTER;
	LPVOID _callback = callback.get();
	LPVOID _prawcallback = &_callback;
	arguments.m_arg[7].m_inf.m_ppCompoundData = (void**)&_prawcallback;
	arguments.m_arg[7].m_dwState = EAV_IS_POINTER;
	if(NotifySys(NRS_EVENT_NOTIFY2, (DWORD)&arguments, 0) != 0){
		if(arguments.m_blHasRetVal){
			result = arguments.m_infRetData.m_bool;
		}
	}
	return result; 
}
bool EPLClient::OnQuotaRequest(shrewd_ptr<ProxyBrowser> browser,const char* origin_url,__int64 new_size,shrewd_ptr<ProxyRequestCallback> callback){
	bool result = NULL; 
	if(!m_mainWindow || m_mainWindow->isDestory == TRUE){	
		m_mainWindow = NULL;
		return result; 
	}
	ProxyClient::OnQuotaRequest(browser,origin_url,new_size,callback);
	EVENT_NOTIFY2 arguments(m_mainWindow->dwWinFormID, m_mainWindow->dwUnitID,30);
	arguments.m_nArgCount = 4;
	LPVOID _browser = browser.get();
	LPVOID _prawbrowser = &_browser;
	arguments.m_arg[0].m_inf.m_ppCompoundData = (void**)&_prawbrowser;
	arguments.m_arg[0].m_dwState = EAV_IS_POINTER;
	arguments.m_arg[1].m_inf.m_dtDataType = SDT_TEXT;
	arguments.m_arg[1].m_inf.m_ppText = (LPTSTR*)&origin_url;
	arguments.m_arg[1].m_dwState = EAV_IS_POINTER;
	arguments.m_arg[2].m_inf.m_dtDataType = SDT_INT64;
	arguments.m_arg[2].m_inf.m_int64 = new_size;
	arguments.m_arg[2].m_dwState = 0;
	LPVOID _callback = callback.get();
	LPVOID _prawcallback = &_callback;
	arguments.m_arg[3].m_inf.m_ppCompoundData = (void**)&_prawcallback;
	arguments.m_arg[3].m_dwState = EAV_IS_POINTER;
	if(NotifySys(NRS_EVENT_NOTIFY2, (DWORD)&arguments, 0) != 0){
		if(arguments.m_blHasRetVal){
			result = arguments.m_infRetData.m_bool;
		}
	}
	return result; 
}
void EPLClient::OnPluginCrashed(shrewd_ptr<ProxyBrowser> browser,const char* plugin_path){
	if(!m_mainWindow || m_mainWindow->isDestory == TRUE){	
		m_mainWindow = NULL;
		return ; 
	}
	ProxyClient::OnPluginCrashed(browser,plugin_path);
	EVENT_NOTIFY2 arguments(m_mainWindow->dwWinFormID, m_mainWindow->dwUnitID,31);
	arguments.m_nArgCount = 2;
	LPVOID _browser = browser.get();
	LPVOID _prawbrowser = &_browser;
	arguments.m_arg[0].m_inf.m_ppCompoundData = (void**)&_prawbrowser;
	arguments.m_arg[0].m_dwState = EAV_IS_POINTER;
	arguments.m_arg[1].m_inf.m_dtDataType = SDT_TEXT;
	arguments.m_arg[1].m_inf.m_ppText = (LPTSTR*)&plugin_path;
	arguments.m_arg[1].m_dwState = EAV_IS_POINTER;
	NotifySys(NRS_EVENT_NOTIFY2, (DWORD)&arguments, 0); 
}
void EPLClient::OnRenderViewReady(shrewd_ptr<ProxyBrowser> browser){
	if(!m_mainWindow || m_mainWindow->isDestory == TRUE){	
		m_mainWindow = NULL;
		return ; 
	}
	ProxyClient::OnRenderViewReady(browser);
	EVENT_NOTIFY2 arguments(m_mainWindow->dwWinFormID, m_mainWindow->dwUnitID,32);
	arguments.m_nArgCount = 1;
	LPVOID _browser = browser.get();
	LPVOID _prawbrowser = &_browser;
	arguments.m_arg[0].m_inf.m_ppCompoundData = (void**)&_prawbrowser;
	arguments.m_arg[0].m_dwState = EAV_IS_POINTER;
	NotifySys(NRS_EVENT_NOTIFY2, (DWORD)&arguments, 0); 
}
void EPLClient::OnRenderProcessTerminated(shrewd_ptr<ProxyBrowser> browser,int status){
	if(!m_mainWindow || m_mainWindow->isDestory == TRUE){	
		m_mainWindow = NULL;
		return ; 
	}
	ProxyClient::OnRenderProcessTerminated(browser,status);
	EVENT_NOTIFY2 arguments(m_mainWindow->dwWinFormID, m_mainWindow->dwUnitID,33);
	arguments.m_nArgCount = 2;
	LPVOID _browser = browser.get();
	LPVOID _prawbrowser = &_browser;
	arguments.m_arg[0].m_inf.m_ppCompoundData = (void**)&_prawbrowser;
	arguments.m_arg[0].m_dwState = EAV_IS_POINTER;
	arguments.m_arg[1].m_inf.m_dtDataType = SDT_INT;
	arguments.m_arg[1].m_inf.m_int = status;
	arguments.m_arg[1].m_dwState = 0;
	NotifySys(NRS_EVENT_NOTIFY2, (DWORD)&arguments, 0); 
}
int EPLClient::OnBeforeResourceLoad(shrewd_ptr<ProxyBrowser> browser,shrewd_ptr<ProxyFrame> frame,shrewd_ptr<ProxyRequest> request,shrewd_ptr<ProxyRequestCallback> callback){
	int result = NULL; 
	if(!m_mainWindow || m_mainWindow->isDestory == TRUE){	
		m_mainWindow = NULL;
		return result; 
	}
	ProxyClient::OnBeforeResourceLoad(browser,frame,request,callback);
	EVENT_NOTIFY2 arguments(m_mainWindow->dwWinFormID, m_mainWindow->dwUnitID,34);
	arguments.m_nArgCount = 4;
	LPVOID _browser = browser.get();
	LPVOID _prawbrowser = &_browser;
	arguments.m_arg[0].m_inf.m_ppCompoundData = (void**)&_prawbrowser;
	arguments.m_arg[0].m_dwState = EAV_IS_POINTER;
	LPVOID _frame = frame.get();
	LPVOID _prawframe = &_frame;
	arguments.m_arg[1].m_inf.m_ppCompoundData = (void**)&_prawframe;
	arguments.m_arg[1].m_dwState = EAV_IS_POINTER;
	LPVOID _request = request.get();
	LPVOID _prawrequest = &_request;
	arguments.m_arg[2].m_inf.m_ppCompoundData = (void**)&_prawrequest;
	arguments.m_arg[2].m_dwState = EAV_IS_POINTER;
	LPVOID _callback = callback.get();
	LPVOID _prawcallback = &_callback;
	arguments.m_arg[3].m_inf.m_ppCompoundData = (void**)&_prawcallback;
	arguments.m_arg[3].m_dwState = EAV_IS_POINTER;
	if(NotifySys(NRS_EVENT_NOTIFY2, (DWORD)&arguments, 0) != 0){
		if(arguments.m_blHasRetVal){
			result = arguments.m_infRetData.m_int;
		}
	}
	return result; 
}
void EPLClient::OnResourceRedirect(shrewd_ptr<ProxyBrowser> browser,shrewd_ptr<ProxyFrame> frame,shrewd_ptr<ProxyRequest> request,shrewd_ptr<ProxyResponse> response,char*& new_url){
	if(!m_mainWindow || m_mainWindow->isDestory == TRUE){	
		m_mainWindow = NULL;
		return ; 
	}
	ProxyClient::OnResourceRedirect(browser,frame,request,response,new_url);
	EVENT_NOTIFY2 arguments(m_mainWindow->dwWinFormID, m_mainWindow->dwUnitID,35);
	arguments.m_nArgCount = 5;
	LPVOID _browser = browser.get();
	LPVOID _prawbrowser = &_browser;
	arguments.m_arg[0].m_inf.m_ppCompoundData = (void**)&_prawbrowser;
	arguments.m_arg[0].m_dwState = EAV_IS_POINTER;
	LPVOID _frame = frame.get();
	LPVOID _prawframe = &_frame;
	arguments.m_arg[1].m_inf.m_ppCompoundData = (void**)&_prawframe;
	arguments.m_arg[1].m_dwState = EAV_IS_POINTER;
	LPVOID _request = request.get();
	LPVOID _prawrequest = &_request;
	arguments.m_arg[2].m_inf.m_ppCompoundData = (void**)&_prawrequest;
	arguments.m_arg[2].m_dwState = EAV_IS_POINTER;
	LPVOID _response = response.get();
	LPVOID _prawresponse = &_response;
	arguments.m_arg[3].m_inf.m_ppCompoundData = (void**)&_prawresponse;
	arguments.m_arg[3].m_dwState = EAV_IS_POINTER;
	arguments.m_arg[4].m_inf.m_dtDataType = SDT_TEXT;
	arguments.m_arg[4].m_inf.m_ppText = (char**)&new_url;
	arguments.m_arg[4].m_dwState = EAV_IS_POINTER;
	NotifySys(NRS_EVENT_NOTIFY2, (DWORD)&arguments, 0); 
}
bool EPLClient::OnResourceResponse(shrewd_ptr<ProxyBrowser> browser,shrewd_ptr<ProxyFrame> frame,shrewd_ptr<ProxyRequest> request,shrewd_ptr<ProxyResponse> response){
	bool result = NULL; 
	if(!m_mainWindow || m_mainWindow->isDestory == TRUE){	
		m_mainWindow = NULL;
		return result; 
	}
	ProxyClient::OnResourceResponse(browser,frame,request,response);
	EVENT_NOTIFY2 arguments(m_mainWindow->dwWinFormID, m_mainWindow->dwUnitID,36);
	arguments.m_nArgCount = 4;
	LPVOID _browser = browser.get();
	LPVOID _prawbrowser = &_browser;
	arguments.m_arg[0].m_inf.m_ppCompoundData = (void**)&_prawbrowser;
	arguments.m_arg[0].m_dwState = EAV_IS_POINTER;
	LPVOID _frame = frame.get();
	LPVOID _prawframe = &_frame;
	arguments.m_arg[1].m_inf.m_ppCompoundData = (void**)&_prawframe;
	arguments.m_arg[1].m_dwState = EAV_IS_POINTER;
	LPVOID _request = request.get();
	LPVOID _prawrequest = &_request;
	arguments.m_arg[2].m_inf.m_ppCompoundData = (void**)&_prawrequest;
	arguments.m_arg[2].m_dwState = EAV_IS_POINTER;
	LPVOID _response = response.get();
	LPVOID _prawresponse = &_response;
	arguments.m_arg[3].m_inf.m_ppCompoundData = (void**)&_prawresponse;
	arguments.m_arg[3].m_dwState = EAV_IS_POINTER;
	if(NotifySys(NRS_EVENT_NOTIFY2, (DWORD)&arguments, 0) != 0){
		if(arguments.m_blHasRetVal){
			result = arguments.m_infRetData.m_bool;
		}
	}
	return result; 
}
bool EPLClient::OnResourceResponseFilter(shrewd_ptr<ProxyBrowser> browser,shrewd_ptr<ProxyFrame> frame,shrewd_ptr<ProxyRequest> request,shrewd_ptr<ProxyResponse> response){
	bool result = NULL; 
	if(!m_mainWindow || m_mainWindow->isDestory == TRUE){	
		m_mainWindow = NULL;
		return result; 
	}
	ProxyClient::OnResourceResponseFilter(browser,frame,request,response);
	EVENT_NOTIFY2 arguments(m_mainWindow->dwWinFormID, m_mainWindow->dwUnitID,37);
	arguments.m_nArgCount = 4;
	LPVOID _browser = browser.get();
	LPVOID _prawbrowser = &_browser;
	arguments.m_arg[0].m_inf.m_ppCompoundData = (void**)&_prawbrowser;
	arguments.m_arg[0].m_dwState = EAV_IS_POINTER;
	LPVOID _frame = frame.get();
	LPVOID _prawframe = &_frame;
	arguments.m_arg[1].m_inf.m_ppCompoundData = (void**)&_prawframe;
	arguments.m_arg[1].m_dwState = EAV_IS_POINTER;
	LPVOID _request = request.get();
	LPVOID _prawrequest = &_request;
	arguments.m_arg[2].m_inf.m_ppCompoundData = (void**)&_prawrequest;
	arguments.m_arg[2].m_dwState = EAV_IS_POINTER;
	LPVOID _response = response.get();
	LPVOID _prawresponse = &_response;
	arguments.m_arg[3].m_inf.m_ppCompoundData = (void**)&_prawresponse;
	arguments.m_arg[3].m_dwState = EAV_IS_POINTER;
	if(NotifySys(NRS_EVENT_NOTIFY2, (DWORD)&arguments, 0) != 0){
		if(arguments.m_blHasRetVal){
			result = arguments.m_infRetData.m_bool;
		}
	}
	return result; 
}
void EPLClient::OnResourceLoadComplete(shrewd_ptr<ProxyBrowser> browser,shrewd_ptr<ProxyFrame> frame,shrewd_ptr<ProxyRequest> request,shrewd_ptr<ProxyResponse> response,int status,__int64 received_content_length){
	if(!m_mainWindow || m_mainWindow->isDestory == TRUE){	
		m_mainWindow = NULL;
		return ; 
	}
	ProxyClient::OnResourceLoadComplete(browser,frame,request,response,status,received_content_length);
	EVENT_NOTIFY2 arguments(m_mainWindow->dwWinFormID, m_mainWindow->dwUnitID,38);
	arguments.m_nArgCount = 6;
	LPVOID _browser = browser.get();
	LPVOID _prawbrowser = &_browser;
	arguments.m_arg[0].m_inf.m_ppCompoundData = (void**)&_prawbrowser;
	arguments.m_arg[0].m_dwState = EAV_IS_POINTER;
	LPVOID _frame = frame.get();
	LPVOID _prawframe = &_frame;
	arguments.m_arg[1].m_inf.m_ppCompoundData = (void**)&_prawframe;
	arguments.m_arg[1].m_dwState = EAV_IS_POINTER;
	LPVOID _request = request.get();
	LPVOID _prawrequest = &_request;
	arguments.m_arg[2].m_inf.m_ppCompoundData = (void**)&_prawrequest;
	arguments.m_arg[2].m_dwState = EAV_IS_POINTER;
	LPVOID _response = response.get();
	LPVOID _prawresponse = &_response;
	arguments.m_arg[3].m_inf.m_ppCompoundData = (void**)&_prawresponse;
	arguments.m_arg[3].m_dwState = EAV_IS_POINTER;
	arguments.m_arg[4].m_inf.m_dtDataType = SDT_INT;
	arguments.m_arg[4].m_inf.m_int = status;
	arguments.m_arg[4].m_dwState = 0;
	arguments.m_arg[5].m_inf.m_dtDataType = SDT_INT64;
	arguments.m_arg[5].m_inf.m_int64 = received_content_length;
	arguments.m_arg[5].m_dwState = 0;
	NotifySys(NRS_EVENT_NOTIFY2, (DWORD)&arguments, 0); 
}
void EPLClient::OnProtocolExecution(shrewd_ptr<ProxyBrowser> browser,shrewd_ptr<ProxyFrame> frame,shrewd_ptr<ProxyRequest> request,int& allow_os_execution){
	if(!m_mainWindow || m_mainWindow->isDestory == TRUE){	
		m_mainWindow = NULL;
		return ; 
	}
	ProxyClient::OnProtocolExecution(browser,frame,request,allow_os_execution);
	EVENT_NOTIFY2 arguments(m_mainWindow->dwWinFormID, m_mainWindow->dwUnitID,39);
	arguments.m_nArgCount = 4;
	LPVOID _browser = browser.get();
	LPVOID _prawbrowser = &_browser;
	arguments.m_arg[0].m_inf.m_ppCompoundData = (void**)&_prawbrowser;
	arguments.m_arg[0].m_dwState = EAV_IS_POINTER;
	LPVOID _frame = frame.get();
	LPVOID _prawframe = &_frame;
	arguments.m_arg[1].m_inf.m_ppCompoundData = (void**)&_prawframe;
	arguments.m_arg[1].m_dwState = EAV_IS_POINTER;
	LPVOID _request = request.get();
	LPVOID _prawrequest = &_request;
	arguments.m_arg[2].m_inf.m_ppCompoundData = (void**)&_prawrequest;
	arguments.m_arg[2].m_dwState = EAV_IS_POINTER;
	arguments.m_arg[3].m_inf.m_dtDataType = SDT_INT;
	arguments.m_arg[3].m_inf.m_pInt = (int*)&allow_os_execution;
	arguments.m_arg[3].m_dwState = EAV_IS_POINTER;
	NotifySys(NRS_EVENT_NOTIFY2, (DWORD)&arguments, 0); 
}
bool EPLClient::OnFileDialog(shrewd_ptr<ProxyBrowser> browser,int mode,const char* title,const char* default_file_path,const char* accept_filters,int selected_accept_filter,shrewd_ptr<ProxyFileDialogCallback> callback){
	bool result = NULL; 
	if(!m_mainWindow || m_mainWindow->isDestory == TRUE){	
		m_mainWindow = NULL;
		return result; 
	}
	ProxyClient::OnFileDialog(browser,mode,title,default_file_path,accept_filters,selected_accept_filter,callback);
	EVENT_NOTIFY2 arguments(m_mainWindow->dwWinFormID, m_mainWindow->dwUnitID,40);
	arguments.m_nArgCount = 7;
	LPVOID _browser = browser.get();
	LPVOID _prawbrowser = &_browser;
	arguments.m_arg[0].m_inf.m_ppCompoundData = (void**)&_prawbrowser;
	arguments.m_arg[0].m_dwState = EAV_IS_POINTER;
	arguments.m_arg[1].m_inf.m_dtDataType = SDT_INT;
	arguments.m_arg[1].m_inf.m_int = mode;
	arguments.m_arg[1].m_dwState = 0;
	arguments.m_arg[2].m_inf.m_dtDataType = SDT_TEXT;
	arguments.m_arg[2].m_inf.m_ppText = (LPTSTR*)&title;
	arguments.m_arg[2].m_dwState = EAV_IS_POINTER;
	arguments.m_arg[3].m_inf.m_dtDataType = SDT_TEXT;
	arguments.m_arg[3].m_inf.m_ppText = (LPTSTR*)&default_file_path;
	arguments.m_arg[3].m_dwState = EAV_IS_POINTER;
	arguments.m_arg[4].m_inf.m_dtDataType = SDT_TEXT;
	arguments.m_arg[4].m_inf.m_ppText = (LPTSTR*)&accept_filters;
	arguments.m_arg[4].m_dwState = EAV_IS_POINTER;
	arguments.m_arg[5].m_inf.m_dtDataType = SDT_INT;
	arguments.m_arg[5].m_inf.m_int = selected_accept_filter;
	arguments.m_arg[5].m_dwState = 0;
	LPVOID _callback = callback.get();
	LPVOID _prawcallback = &_callback;
	arguments.m_arg[6].m_inf.m_ppCompoundData = (void**)&_prawcallback;
	arguments.m_arg[6].m_dwState = EAV_IS_POINTER;
	if(NotifySys(NRS_EVENT_NOTIFY2, (DWORD)&arguments, 0) != 0){
		if(arguments.m_blHasRetVal){
			result = arguments.m_infRetData.m_bool;
		}
	}
	return result; 
}
void EPLClient::OnBeforeContextMenu(shrewd_ptr<ProxyBrowser> browser,shrewd_ptr<ProxyFrame> frame,shrewd_ptr<ProxyContextMenuParams> params,shrewd_ptr<ProxyMenuModel> model){
	if(!m_mainWindow || m_mainWindow->isDestory == TRUE){	
		m_mainWindow = NULL;
		return ; 
	}
	ProxyClient::OnBeforeContextMenu(browser,frame,params,model);
	EVENT_NOTIFY2 arguments(m_mainWindow->dwWinFormID, m_mainWindow->dwUnitID,41);
	arguments.m_nArgCount = 4;
	LPVOID _browser = browser.get();
	LPVOID _prawbrowser = &_browser;
	arguments.m_arg[0].m_inf.m_ppCompoundData = (void**)&_prawbrowser;
	arguments.m_arg[0].m_dwState = EAV_IS_POINTER;
	LPVOID _frame = frame.get();
	LPVOID _prawframe = &_frame;
	arguments.m_arg[1].m_inf.m_ppCompoundData = (void**)&_prawframe;
	arguments.m_arg[1].m_dwState = EAV_IS_POINTER;
	LPVOID _params = params.get();
	LPVOID _prawparams = &_params;
	arguments.m_arg[2].m_inf.m_ppCompoundData = (void**)&_prawparams;
	arguments.m_arg[2].m_dwState = EAV_IS_POINTER;
	LPVOID _model = model.get();
	LPVOID _prawmodel = &_model;
	arguments.m_arg[3].m_inf.m_ppCompoundData = (void**)&_prawmodel;
	arguments.m_arg[3].m_dwState = EAV_IS_POINTER;
	NotifySys(NRS_EVENT_NOTIFY2, (DWORD)&arguments, 0); 
}
bool EPLClient::RunContextMenu(shrewd_ptr<ProxyBrowser> browser,shrewd_ptr<ProxyFrame> frame,shrewd_ptr<ProxyContextMenuParams> params,shrewd_ptr<ProxyMenuModel> model,shrewd_ptr<ProxyRunContextMenuCallback> callback){
	bool result = NULL; 
	if(!m_mainWindow || m_mainWindow->isDestory == TRUE){	
		m_mainWindow = NULL;
		return result; 
	}
	ProxyClient::RunContextMenu(browser,frame,params,model,callback);
	EVENT_NOTIFY2 arguments(m_mainWindow->dwWinFormID, m_mainWindow->dwUnitID,42);
	arguments.m_nArgCount = 5;
	LPVOID _browser = browser.get();
	LPVOID _prawbrowser = &_browser;
	arguments.m_arg[0].m_inf.m_ppCompoundData = (void**)&_prawbrowser;
	arguments.m_arg[0].m_dwState = EAV_IS_POINTER;
	LPVOID _frame = frame.get();
	LPVOID _prawframe = &_frame;
	arguments.m_arg[1].m_inf.m_ppCompoundData = (void**)&_prawframe;
	arguments.m_arg[1].m_dwState = EAV_IS_POINTER;
	LPVOID _params = params.get();
	LPVOID _prawparams = &_params;
	arguments.m_arg[2].m_inf.m_ppCompoundData = (void**)&_prawparams;
	arguments.m_arg[2].m_dwState = EAV_IS_POINTER;
	LPVOID _model = model.get();
	LPVOID _prawmodel = &_model;
	arguments.m_arg[3].m_inf.m_ppCompoundData = (void**)&_prawmodel;
	arguments.m_arg[3].m_dwState = EAV_IS_POINTER;
	LPVOID _callback = callback.get();
	LPVOID _prawcallback = &_callback;
	arguments.m_arg[4].m_inf.m_ppCompoundData = (void**)&_prawcallback;
	arguments.m_arg[4].m_dwState = EAV_IS_POINTER;
	if(NotifySys(NRS_EVENT_NOTIFY2, (DWORD)&arguments, 0) != 0){
		if(arguments.m_blHasRetVal){
			result = arguments.m_infRetData.m_bool;
		}
	}
	return result; 
}
bool EPLClient::OnContextMenuCommand(shrewd_ptr<ProxyBrowser> browser,shrewd_ptr<ProxyFrame> frame,shrewd_ptr<ProxyContextMenuParams> params,int command_id,int event_flags){
	bool result = NULL; 
	if(!m_mainWindow || m_mainWindow->isDestory == TRUE){	
		m_mainWindow = NULL;
		return result; 
	}
	ProxyClient::OnContextMenuCommand(browser,frame,params,command_id,event_flags);
	EVENT_NOTIFY2 arguments(m_mainWindow->dwWinFormID, m_mainWindow->dwUnitID,43);
	arguments.m_nArgCount = 5;
	LPVOID _browser = browser.get();
	LPVOID _prawbrowser = &_browser;
	arguments.m_arg[0].m_inf.m_ppCompoundData = (void**)&_prawbrowser;
	arguments.m_arg[0].m_dwState = EAV_IS_POINTER;
	LPVOID _frame = frame.get();
	LPVOID _prawframe = &_frame;
	arguments.m_arg[1].m_inf.m_ppCompoundData = (void**)&_prawframe;
	arguments.m_arg[1].m_dwState = EAV_IS_POINTER;
	LPVOID _params = params.get();
	LPVOID _prawparams = &_params;
	arguments.m_arg[2].m_inf.m_ppCompoundData = (void**)&_prawparams;
	arguments.m_arg[2].m_dwState = EAV_IS_POINTER;
	arguments.m_arg[3].m_inf.m_dtDataType = SDT_INT;
	arguments.m_arg[3].m_inf.m_int = command_id;
	arguments.m_arg[3].m_dwState = 0;
	arguments.m_arg[4].m_inf.m_dtDataType = SDT_INT;
	arguments.m_arg[4].m_inf.m_int = event_flags;
	arguments.m_arg[4].m_dwState = 0;
	if(NotifySys(NRS_EVENT_NOTIFY2, (DWORD)&arguments, 0) != 0){
		if(arguments.m_blHasRetVal){
			result = arguments.m_infRetData.m_bool;
		}
	}
	return result; 
}
void EPLClient::OnContextMenuDismissed(shrewd_ptr<ProxyBrowser> browser,shrewd_ptr<ProxyFrame> frame){
	if(!m_mainWindow || m_mainWindow->isDestory == TRUE){	
		m_mainWindow = NULL;
		return ; 
	}
	ProxyClient::OnContextMenuDismissed(browser,frame);
	EVENT_NOTIFY2 arguments(m_mainWindow->dwWinFormID, m_mainWindow->dwUnitID,44);
	arguments.m_nArgCount = 2;
	LPVOID _browser = browser.get();
	LPVOID _prawbrowser = &_browser;
	arguments.m_arg[0].m_inf.m_ppCompoundData = (void**)&_prawbrowser;
	arguments.m_arg[0].m_dwState = EAV_IS_POINTER;
	LPVOID _frame = frame.get();
	LPVOID _prawframe = &_frame;
	arguments.m_arg[1].m_inf.m_ppCompoundData = (void**)&_prawframe;
	arguments.m_arg[1].m_dwState = EAV_IS_POINTER;
	NotifySys(NRS_EVENT_NOTIFY2, (DWORD)&arguments, 0); 
}
void EPLClient::OnBeforeDownload(shrewd_ptr<ProxyBrowser> browser,shrewd_ptr<ProxyDownloadItem> download_item,const char* suggested_name,shrewd_ptr<ProxyBeforeDownloadCallback> callback){
	if(!m_mainWindow || m_mainWindow->isDestory == TRUE){	
		m_mainWindow = NULL;
		return ; 
	}
	ProxyClient::OnBeforeDownload(browser,download_item,suggested_name,callback);
	EVENT_NOTIFY2 arguments(m_mainWindow->dwWinFormID, m_mainWindow->dwUnitID,45);
	arguments.m_nArgCount = 4;
	LPVOID _browser = browser.get();
	LPVOID _prawbrowser = &_browser;
	arguments.m_arg[0].m_inf.m_ppCompoundData = (void**)&_prawbrowser;
	arguments.m_arg[0].m_dwState = EAV_IS_POINTER;
	LPVOID _download_item = download_item.get();
	LPVOID _prawdownload_item = &_download_item;
	arguments.m_arg[1].m_inf.m_ppCompoundData = (void**)&_prawdownload_item;
	arguments.m_arg[1].m_dwState = EAV_IS_POINTER;
	arguments.m_arg[2].m_inf.m_dtDataType = SDT_TEXT;
	arguments.m_arg[2].m_inf.m_ppText = (LPTSTR*)&suggested_name;
	arguments.m_arg[2].m_dwState = EAV_IS_POINTER;
	LPVOID _callback = callback.get();
	LPVOID _prawcallback = &_callback;
	arguments.m_arg[3].m_inf.m_ppCompoundData = (void**)&_prawcallback;
	arguments.m_arg[3].m_dwState = EAV_IS_POINTER;
	NotifySys(NRS_EVENT_NOTIFY2, (DWORD)&arguments, 0); 
}
void EPLClient::OnDownloadUpdated(shrewd_ptr<ProxyBrowser> browser,shrewd_ptr<ProxyDownloadItem> download_item,shrewd_ptr<ProxyDownloadItemCallback> callback){
	if(!m_mainWindow || m_mainWindow->isDestory == TRUE){	
		m_mainWindow = NULL;
		return ; 
	}
	ProxyClient::OnDownloadUpdated(browser,download_item,callback);
	EVENT_NOTIFY2 arguments(m_mainWindow->dwWinFormID, m_mainWindow->dwUnitID,46);
	arguments.m_nArgCount = 3;
	LPVOID _browser = browser.get();
	LPVOID _prawbrowser = &_browser;
	arguments.m_arg[0].m_inf.m_ppCompoundData = (void**)&_prawbrowser;
	arguments.m_arg[0].m_dwState = EAV_IS_POINTER;
	LPVOID _download_item = download_item.get();
	LPVOID _prawdownload_item = &_download_item;
	arguments.m_arg[1].m_inf.m_ppCompoundData = (void**)&_prawdownload_item;
	arguments.m_arg[1].m_dwState = EAV_IS_POINTER;
	LPVOID _callback = callback.get();
	LPVOID _prawcallback = &_callback;
	arguments.m_arg[2].m_inf.m_ppCompoundData = (void**)&_prawcallback;
	arguments.m_arg[2].m_dwState = EAV_IS_POINTER;
	NotifySys(NRS_EVENT_NOTIFY2, (DWORD)&arguments, 0); 
}
bool EPLClient::OnCookieVisitor(shrewd_ptr<ProxyCookie> cookie,int count,int total){
	bool result = NULL; 
	if(!m_mainWindow || m_mainWindow->isDestory == TRUE){	
		m_mainWindow = NULL;
		return result; 
	}
	ProxyClient::OnCookieVisitor(cookie,count,total);
	EVENT_NOTIFY2 arguments(m_mainWindow->dwWinFormID, m_mainWindow->dwUnitID,47);
	arguments.m_nArgCount = 3;
	LPVOID _cookie = cookie.get();
	LPVOID _prawcookie = &_cookie;
	arguments.m_arg[0].m_inf.m_ppCompoundData = (void**)&_prawcookie;
	arguments.m_arg[0].m_dwState = EAV_IS_POINTER;
	arguments.m_arg[1].m_inf.m_dtDataType = SDT_INT;
	arguments.m_arg[1].m_inf.m_int = count;
	arguments.m_arg[1].m_dwState = 0;
	arguments.m_arg[2].m_inf.m_dtDataType = SDT_INT;
	arguments.m_arg[2].m_inf.m_int = total;
	arguments.m_arg[2].m_dwState = 0;
	if(NotifySys(NRS_EVENT_NOTIFY2, (DWORD)&arguments, 0) != 0){
		if(arguments.m_blHasRetVal){
			result = arguments.m_infRetData.m_bool;
		}
	}
	return result; 
}
void EPLClient::OnTaskVisitor(int taskid,int threadid,shrewd_ptr<ProxyValue> params){
	if(!m_mainWindow || m_mainWindow->isDestory == TRUE){	
		m_mainWindow = NULL;
		return ; 
	}
	ProxyClient::OnTaskVisitor(taskid,threadid,params);
	EVENT_NOTIFY2 arguments(m_mainWindow->dwWinFormID, m_mainWindow->dwUnitID,48);
	arguments.m_nArgCount = 3;
	arguments.m_arg[0].m_inf.m_dtDataType = SDT_INT;
	arguments.m_arg[0].m_inf.m_int = taskid;
	arguments.m_arg[0].m_dwState = 0;
	arguments.m_arg[1].m_inf.m_dtDataType = SDT_INT;
	arguments.m_arg[1].m_inf.m_int = threadid;
	arguments.m_arg[1].m_dwState = 0;
	LPVOID _params = params.get();
	LPVOID _prawparams = &_params;
	arguments.m_arg[2].m_inf.m_ppCompoundData = (void**)&_prawparams;
	arguments.m_arg[2].m_dwState = EAV_IS_POINTER;
	NotifySys(NRS_EVENT_NOTIFY2, (DWORD)&arguments, 0); 
}
void EPLClient::OnRenderProcessThreadCreated(shrewd_ptr<ProxyListValue> extra_info){
	if(!m_mainWindow || m_mainWindow->isDestory == TRUE){	
		m_mainWindow = NULL;
		return ; 
	}
	ProxyClient::OnRenderProcessThreadCreated(extra_info);
	EVENT_NOTIFY2 arguments(m_mainWindow->dwWinFormID, m_mainWindow->dwUnitID,49);
	arguments.m_nArgCount = 1;
	LPVOID _extra_info = extra_info.get();
	LPVOID _prawextra_info = &_extra_info;
	arguments.m_arg[0].m_inf.m_ppCompoundData = (void**)&_prawextra_info;
	arguments.m_arg[0].m_dwState = EAV_IS_POINTER;
	NotifySys(NRS_EVENT_NOTIFY2, (DWORD)&arguments, 0); 
}
void EPLClient::OnResourceFilter(shrewd_ptr<ProxyBrowser> browser,shrewd_ptr<ProxyResponseFilter> filter){
	if(!m_mainWindow || m_mainWindow->isDestory == TRUE){	
		m_mainWindow = NULL;
		return ; 
	}
	ProxyClient::OnResourceFilter(browser,filter);
	EVENT_NOTIFY2 arguments(m_mainWindow->dwWinFormID, m_mainWindow->dwUnitID,50);
	arguments.m_nArgCount = 2;
	LPVOID _browser = browser.get();
	LPVOID _prawbrowser = &_browser;
	arguments.m_arg[0].m_inf.m_ppCompoundData = (void**)&_prawbrowser;
	arguments.m_arg[0].m_dwState = EAV_IS_POINTER;
	LPVOID _filter = filter.get();
	LPVOID _prawfilter = &_filter;
	arguments.m_arg[1].m_inf.m_ppCompoundData = (void**)&_prawfilter;
	arguments.m_arg[1].m_dwState = EAV_IS_POINTER;
	NotifySys(NRS_EVENT_NOTIFY2, (DWORD)&arguments, 0); 
}



extern "C"
void EDITIONF(ProxyClient_CreateBrowser) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	shrewd_ptr<EPLClient> self = EPLClient::GetInstance();
	shrewd_ptr<ProxyWindowInfo> argWininfo = (ProxyWindowInfo*)*pArgInf[1].m_ppCompoundData;
	const char* argUrl = (NULL==pArgInf[2].m_pText || strlen(pArgInf[2].m_pText) <= 0) ? NULL : pArgInf[2].m_pText;
	shrewd_ptr<ProxyBrowserSettings> argSettings = (ProxyBrowserSettings*)*pArgInf[3].m_ppCompoundData;
	shrewd_ptr<ProxyRequestContext> argRequest_Context = (ProxyRequestContext*)*pArgInf[4].m_ppCompoundData;
	pRetData->m_bool = self->CreateBrowser(argWininfo,argUrl,argSettings,argRequest_Context);
}

extern "C"
void EDITIONF(ProxyClient_CloseBrowser) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	shrewd_ptr<EPLClient> self = EPLClient::GetInstance();
	shrewd_ptr<ProxyBrowser> argBrowser = (ProxyBrowser*)*pArgInf[1].m_ppCompoundData;
	bool argForce_Close = pArgInf[2].m_bool;
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
void EDITIONF(ProxyClient_GetBrowserWithIndex) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	shrewd_ptr<EPLClient> self = EPLClient::GetInstance();
	int argIndex = pArgInf[1].m_int;
	shrewd_ptr<ProxyBrowser> result = self->GetBrowserWithIndex(argIndex);
	if(result){ 
		result->retain();
		DWORD* InternalPointer = (DWORD*)NotifySys(NRS_MALLOC,4,0);
		*InternalPointer = (DWORD)result.get();
		pRetData->m_pCompoundData = InternalPointer;
	}
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
void EDITIONF(ProxyBase_ExecuteProcess) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	shrewd_ptr<EPLClient> client = EPLClient::GetInstance();
	pRetData->m_int = ProxyBase::ExecuteProcess((DWORD)client.get());

}

extern "C"
void EDITIONF(ProxyBase_Initialize) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	shrewd_ptr<ProxySettings> argSettings = (ProxySettings*)*pArgInf[1].m_ppCompoundData;
	shrewd_ptr<EPLClient> client = EPLClient::GetInstance();
	pRetData->m_bool = ProxyBase::Initialize(argSettings, (DWORD)client.get());
}


#ifdef NOT_USED

extern "C"
void EDITIONF(ProxyClient_CreateBrowser) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_bool = FALSE;
		return ;
	}
	shrewd_ptr<ProxyClient> self = (ProxyClient*)*pArgInf->m_ppCompoundData;
	shrewd_ptr<ProxyWindowInfo> argWininfo = (ProxyWindowInfo*)*pArgInf[1].m_ppCompoundData;
	const char* argUrl = (NULL==pArgInf[2].m_pText || strlen(pArgInf[2].m_pText) <= 0) ? NULL : pArgInf[2].m_pText;
	shrewd_ptr<ProxyBrowserSettings> argSettings = (ProxyBrowserSettings*)*pArgInf[3].m_ppCompoundData;
	shrewd_ptr<ProxyRequestContext> argRequest_Context = (ProxyRequestContext*)*pArgInf[4].m_ppCompoundData;
	pRetData->m_bool = self->CreateBrowser(argWininfo,argUrl,argSettings,argRequest_Context);
}

extern "C"
void EDITIONF(ProxyClient_CloseBrowser) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyClient> self = (ProxyClient*)*pArgInf->m_ppCompoundData;
	shrewd_ptr<ProxyBrowser> argBrowser = (ProxyBrowser*)*pArgInf[1].m_ppCompoundData;
	bool argForce_Close = pArgInf[2].m_bool;
	self->CloseBrowser(argBrowser,argForce_Close);
}

extern "C"
void EDITIONF(ProxyClient_SetForeground) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyClient> self = (ProxyClient*)*pArgInf->m_ppCompoundData;
	unsigned int argParent_Window = pArgInf[1].m_uint;
	shrewd_ptr<ProxyBrowser> argBrowser = (ProxyBrowser*)*pArgInf[2].m_ppCompoundData;
	self->SetForeground(argParent_Window,argBrowser);
}

extern "C"
void EDITIONF(ProxyClient_GetBrowserCount) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_int = 0;
		return ;
	}
	shrewd_ptr<ProxyClient> self = (ProxyClient*)*pArgInf->m_ppCompoundData;
	pRetData->m_int = self->GetBrowserCount();
}

extern "C"
void EDITIONF(ProxyClient_GetBrowserWithIndex) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		*((DWORD*)pRetData->m_pCompoundData) = NULL;
		return ;
	}
	shrewd_ptr<ProxyClient> self = (ProxyClient*)*pArgInf->m_ppCompoundData;
	int argIndex = pArgInf[1].m_int;
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
void EDITIONF(ProxyClient_GetBrowserWithHandle) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		*((DWORD*)pRetData->m_pCompoundData) = NULL;
		return ;
	}
	shrewd_ptr<ProxyClient> self = (ProxyClient*)*pArgInf->m_ppCompoundData;
	unsigned int argHandle = pArgInf[1].m_uint;
	shrewd_ptr<ProxyBrowser> result = self->GetBrowserWithHandle(argHandle);
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





#endif
