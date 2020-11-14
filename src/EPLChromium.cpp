#include "stdafx.h"
#include <proxy/ProxyBase.h>
#include "def/Power.h"
#include "EPLProxyBase.h"
#include "EPLProxyDOMNode.h"
#include "EPLProxyCollection.h"
#include <proxy/ProxyDOMNode.h>
#include <proxy/ProxyCollection.h>

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

void EPLClient::OnBeforeCommandLineProcessing(const char* process_type,shrewd_ptr<ProxyCommandLine> command_line){
	if(!m_mainWindow || m_mainWindow->isDestory == TRUE){	
		m_mainWindow = NULL;
		return ; 
	}
	ProxyClient::OnBeforeCommandLineProcessing(process_type,command_line);
	EVENT_NOTIFY2 arguments(m_mainWindow->dwWinFormID, m_mainWindow->dwUnitID,0);
	arguments.m_nArgCount = 2;
	arguments.m_arg[0].m_inf.m_dtDataType = SDT_TEXT;
	arguments.m_arg[0].m_inf.m_ppText = (LPTSTR*)&process_type;
	arguments.m_arg[0].m_dwState = EAV_IS_POINTER;
	LPVOID _command_line = command_line.get();
	LPVOID _prawcommand_line = &_command_line;
	arguments.m_arg[1].m_inf.m_ppCompoundData = (void**)&_prawcommand_line;
	arguments.m_arg[1].m_dwState = EAV_IS_POINTER;
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
void EPLClient::OnBeforeChildProcessLaunch(shrewd_ptr<ProxyCommandLine> command_line){
	if(!m_mainWindow || m_mainWindow->isDestory == TRUE){	
		m_mainWindow = NULL;
		return ; 
	}
	ProxyClient::OnBeforeChildProcessLaunch(command_line);
	EVENT_NOTIFY2 arguments(m_mainWindow->dwWinFormID, m_mainWindow->dwUnitID,2);
	arguments.m_nArgCount = 1;
	LPVOID _command_line = command_line.get();
	LPVOID _prawcommand_line = &_command_line;
	arguments.m_arg[0].m_inf.m_ppCompoundData = (void**)&_prawcommand_line;
	arguments.m_arg[0].m_dwState = EAV_IS_POINTER;
	NotifySys(NRS_EVENT_NOTIFY2, (DWORD)&arguments, 0); 
}
void EPLClient::OnRenderProcessThreadCreated(shrewd_ptr<ProxyListValue> extra_info){
	if(!m_mainWindow || m_mainWindow->isDestory == TRUE){	
		m_mainWindow = NULL;
		return ; 
	}
	ProxyClient::OnRenderProcessThreadCreated(extra_info);
	EVENT_NOTIFY2 arguments(m_mainWindow->dwWinFormID, m_mainWindow->dwUnitID,3);
	arguments.m_nArgCount = 1;
	LPVOID _extra_info = extra_info.get();
	LPVOID _prawextra_info = &_extra_info;
	arguments.m_arg[0].m_inf.m_ppCompoundData = (void**)&_prawextra_info;
	arguments.m_arg[0].m_dwState = EAV_IS_POINTER;
	NotifySys(NRS_EVENT_NOTIFY2, (DWORD)&arguments, 0); 
}
bool EPLClient::OnBeforePopup(shrewd_ptr<ProxyBrowser> browser,shrewd_ptr<ProxyFrame> frame,const char* target_uri,const char* target_frame_name,int target_disposition,bool user_gesture,shrewd_ptr<ProxyWindowInfo> window_info,shrewd_ptr<ProxyBrowserSettings> settings,int& no_javascript_access){
	bool result = NULL; 
	if(!m_mainWindow || m_mainWindow->isDestory == TRUE){	
		m_mainWindow = NULL;
		return result; 
	}
	ProxyClient::OnBeforePopup(browser,frame,target_uri,target_frame_name,target_disposition,user_gesture,window_info,settings,no_javascript_access);
	EVENT_NOTIFY2 arguments(m_mainWindow->dwWinFormID, m_mainWindow->dwUnitID,4);
	arguments.m_nArgCount = 9;
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
	LPVOID _window_info = window_info.get();
	LPVOID _prawwindow_info = &_window_info;
	arguments.m_arg[6].m_inf.m_ppCompoundData = (void**)&_prawwindow_info;
	arguments.m_arg[6].m_dwState = EAV_IS_POINTER;
	LPVOID _settings = settings.get();
	LPVOID _prawsettings = &_settings;
	arguments.m_arg[7].m_inf.m_ppCompoundData = (void**)&_prawsettings;
	arguments.m_arg[7].m_dwState = EAV_IS_POINTER;
	arguments.m_arg[8].m_inf.m_dtDataType = SDT_INT;
	arguments.m_arg[8].m_inf.m_pInt = (int*)&no_javascript_access;
	arguments.m_arg[8].m_dwState = EAV_IS_POINTER;
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
	EVENT_NOTIFY2 arguments(m_mainWindow->dwWinFormID, m_mainWindow->dwUnitID,5);
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
	EVENT_NOTIFY2 arguments(m_mainWindow->dwWinFormID, m_mainWindow->dwUnitID,6);
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
	EVENT_NOTIFY2 arguments(m_mainWindow->dwWinFormID, m_mainWindow->dwUnitID,7);
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
	EVENT_NOTIFY2 arguments(m_mainWindow->dwWinFormID, m_mainWindow->dwUnitID,8);
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
	EVENT_NOTIFY2 arguments(m_mainWindow->dwWinFormID, m_mainWindow->dwUnitID,9);
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
	EVENT_NOTIFY2 arguments(m_mainWindow->dwWinFormID, m_mainWindow->dwUnitID,11);
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
void EPLClient::OnBeforeContextMenu(shrewd_ptr<ProxyBrowser> browser,shrewd_ptr<ProxyFrame> frame,shrewd_ptr<ProxyContextMenuParams> params,shrewd_ptr<ProxyMenuModel> model){
	if(!m_mainWindow || m_mainWindow->isDestory == TRUE){	
		m_mainWindow = NULL;
		return ; 
	}
	ProxyClient::OnBeforeContextMenu(browser,frame,params,model);
	EVENT_NOTIFY2 arguments(m_mainWindow->dwWinFormID, m_mainWindow->dwUnitID,12);
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
	EVENT_NOTIFY2 arguments(m_mainWindow->dwWinFormID, m_mainWindow->dwUnitID,13);
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
	EVENT_NOTIFY2 arguments(m_mainWindow->dwWinFormID, m_mainWindow->dwUnitID,14);
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
	EVENT_NOTIFY2 arguments(m_mainWindow->dwWinFormID, m_mainWindow->dwUnitID,15);
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
void EPLClient::OnAddressChange(shrewd_ptr<ProxyBrowser> browser,shrewd_ptr<ProxyFrame> frame,const char* url){
	if(!m_mainWindow || m_mainWindow->isDestory == TRUE){	
		m_mainWindow = NULL;
		return ; 
	}
	ProxyClient::OnAddressChange(browser,frame,url);
	EVENT_NOTIFY2 arguments(m_mainWindow->dwWinFormID, m_mainWindow->dwUnitID,16);
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
	EVENT_NOTIFY2 arguments(m_mainWindow->dwWinFormID, m_mainWindow->dwUnitID,17);
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
bool EPLClient::OnTooltip(shrewd_ptr<ProxyBrowser> browser,const char* text){
	bool result = NULL; 
	if(!m_mainWindow || m_mainWindow->isDestory == TRUE){	
		m_mainWindow = NULL;
		return result; 
	}
	ProxyClient::OnTooltip(browser,text);
	EVENT_NOTIFY2 arguments(m_mainWindow->dwWinFormID, m_mainWindow->dwUnitID,18);
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
	EVENT_NOTIFY2 arguments(m_mainWindow->dwWinFormID, m_mainWindow->dwUnitID,19);
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
	EVENT_NOTIFY2 arguments(m_mainWindow->dwWinFormID, m_mainWindow->dwUnitID,20);
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
void EPLClient::OnLoadingProgressChange(shrewd_ptr<ProxyBrowser> browser,double progress){
	if(!m_mainWindow || m_mainWindow->isDestory == TRUE){	
		m_mainWindow = NULL;
		return ; 
	}
	ProxyClient::OnLoadingProgressChange(browser,progress);
	EVENT_NOTIFY2 arguments(m_mainWindow->dwWinFormID, m_mainWindow->dwUnitID,21);
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
void EPLClient::OnFullscreenModeChange(shrewd_ptr<ProxyBrowser> browser,bool fullscreen){
	if(!m_mainWindow || m_mainWindow->isDestory == TRUE){	
		m_mainWindow = NULL;
		return ; 
	}
	ProxyClient::OnFullscreenModeChange(browser,fullscreen);
	EVENT_NOTIFY2 arguments(m_mainWindow->dwWinFormID, m_mainWindow->dwUnitID,22);
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
bool EPLClient::OnJSDialog(shrewd_ptr<ProxyBrowser> browser,const char* origin_url,int dialog_type,const char* message_text,const char* default_prompt_text,shrewd_ptr<ProxyJSDialogCallback> callback,int& suppress_message){
	bool result = NULL; 
	if(!m_mainWindow || m_mainWindow->isDestory == TRUE){	
		m_mainWindow = NULL;
		return result; 
	}
	ProxyClient::OnJSDialog(browser,origin_url,dialog_type,message_text,default_prompt_text,callback,suppress_message);
	EVENT_NOTIFY2 arguments(m_mainWindow->dwWinFormID, m_mainWindow->dwUnitID,23);
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
	EVENT_NOTIFY2 arguments(m_mainWindow->dwWinFormID, m_mainWindow->dwUnitID,24);
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
	EVENT_NOTIFY2 arguments(m_mainWindow->dwWinFormID, m_mainWindow->dwUnitID,25);
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
	EVENT_NOTIFY2 arguments(m_mainWindow->dwWinFormID, m_mainWindow->dwUnitID,26);
	arguments.m_nArgCount = 1;
	LPVOID _browser = browser.get();
	LPVOID _prawbrowser = &_browser;
	arguments.m_arg[0].m_inf.m_ppCompoundData = (void**)&_prawbrowser;
	arguments.m_arg[0].m_dwState = EAV_IS_POINTER;
	NotifySys(NRS_EVENT_NOTIFY2, (DWORD)&arguments, 0); 
}
bool EPLClient::GetAuthCredentials(shrewd_ptr<ProxyBrowser> browser,const char* origin_url,bool isProxy,const char* host,int port,const char* realm,const char* scheme,shrewd_ptr<ProxyAuthCallback> callback){
	bool result = NULL; 
	if(!m_mainWindow || m_mainWindow->isDestory == TRUE){	
		m_mainWindow = NULL;
		return result; 
	}
	ProxyClient::GetAuthCredentials(browser,origin_url,isProxy,host,port,realm,scheme,callback);
	EVENT_NOTIFY2 arguments(m_mainWindow->dwWinFormID, m_mainWindow->dwUnitID,27);
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
bool EPLClient::OnBeforeBrowse(shrewd_ptr<ProxyBrowser> browser,shrewd_ptr<ProxyFrame> frame,shrewd_ptr<ProxyRequest> request,bool user_gesture,bool is_redirect){
	bool result = NULL; 
	if(!m_mainWindow || m_mainWindow->isDestory == TRUE){	
		m_mainWindow = NULL;
		return result; 
	}
	ProxyClient::OnBeforeBrowse(browser,frame,request,user_gesture,is_redirect);
	EVENT_NOTIFY2 arguments(m_mainWindow->dwWinFormID, m_mainWindow->dwUnitID,28);
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
int EPLClient::OnBeforeResourceLoad(shrewd_ptr<ProxyBrowser> browser,shrewd_ptr<ProxyFrame> frame,shrewd_ptr<ProxyRequest> request){
	int result = NULL; 
	if(!m_mainWindow || m_mainWindow->isDestory == TRUE){	
		m_mainWindow = NULL;
		return result; 
	}
	ProxyClient::OnBeforeResourceLoad(browser,frame,request);
	EVENT_NOTIFY2 arguments(m_mainWindow->dwWinFormID, m_mainWindow->dwUnitID,29);
	arguments.m_nArgCount = 3;
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
	EVENT_NOTIFY2 arguments(m_mainWindow->dwWinFormID, m_mainWindow->dwUnitID,30);
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
	EVENT_NOTIFY2 arguments(m_mainWindow->dwWinFormID, m_mainWindow->dwUnitID,31);
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
	EVENT_NOTIFY2 arguments(m_mainWindow->dwWinFormID, m_mainWindow->dwUnitID,32);
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
	EVENT_NOTIFY2 arguments(m_mainWindow->dwWinFormID, m_mainWindow->dwUnitID,33);
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
bool EPLClient::OnFileDialog(shrewd_ptr<ProxyBrowser> browser,int mode,const char* title,const char* default_file_path,const char* accept_filters,int selected_accept_filter,shrewd_ptr<ProxyFileDialogCallback> callback){
	bool result = NULL; 
	if(!m_mainWindow || m_mainWindow->isDestory == TRUE){	
		m_mainWindow = NULL;
		return result; 
	}
	ProxyClient::OnFileDialog(browser,mode,title,default_file_path,accept_filters,selected_accept_filter,callback);
	EVENT_NOTIFY2 arguments(m_mainWindow->dwWinFormID, m_mainWindow->dwUnitID,34);
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
void EPLClient::OnBeforeDownload(shrewd_ptr<ProxyBrowser> browser,shrewd_ptr<ProxyDownloadItem> download_item,const char* suggested_name){
	if(!m_mainWindow || m_mainWindow->isDestory == TRUE){	
		m_mainWindow = NULL;
		return ; 
	}
	ProxyClient::OnBeforeDownload(browser,download_item,suggested_name);
	EVENT_NOTIFY2 arguments(m_mainWindow->dwWinFormID, m_mainWindow->dwUnitID,35);
	arguments.m_nArgCount = 3;
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
	NotifySys(NRS_EVENT_NOTIFY2, (DWORD)&arguments, 0); 
}
void EPLClient::OnDownloadUpdated(shrewd_ptr<ProxyBrowser> browser,shrewd_ptr<ProxyDownloadItem> download_item){
	if(!m_mainWindow || m_mainWindow->isDestory == TRUE){	
		m_mainWindow = NULL;
		return ; 
	}
	ProxyClient::OnDownloadUpdated(browser,download_item);
	EVENT_NOTIFY2 arguments(m_mainWindow->dwWinFormID, m_mainWindow->dwUnitID,36);
	arguments.m_nArgCount = 2;
	LPVOID _browser = browser.get();
	LPVOID _prawbrowser = &_browser;
	arguments.m_arg[0].m_inf.m_ppCompoundData = (void**)&_prawbrowser;
	arguments.m_arg[0].m_dwState = EAV_IS_POINTER;
	LPVOID _download_item = download_item.get();
	LPVOID _prawdownload_item = &_download_item;
	arguments.m_arg[1].m_inf.m_ppCompoundData = (void**)&_prawdownload_item;
	arguments.m_arg[1].m_dwState = EAV_IS_POINTER;
	NotifySys(NRS_EVENT_NOTIFY2, (DWORD)&arguments, 0); 
}
void EPLClient::OnResourceFilter(shrewd_ptr<ProxyBrowser> browser,shrewd_ptr<ProxyResponseFilter> filter){
	if(!m_mainWindow || m_mainWindow->isDestory == TRUE){	
		m_mainWindow = NULL;
		return ; 
	}
	ProxyClient::OnResourceFilter(browser,filter);
	EVENT_NOTIFY2 arguments(m_mainWindow->dwWinFormID, m_mainWindow->dwUnitID,37);
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
void EPLClient::OnServerCreated(shrewd_ptr<ProxyServer> server){
	if(!m_mainWindow || m_mainWindow->isDestory == TRUE){	
		m_mainWindow = NULL;
		return ; 
	}
	ProxyClient::OnServerCreated(server);
	EVENT_NOTIFY2 arguments(m_mainWindow->dwWinFormID, m_mainWindow->dwUnitID,38);
	arguments.m_nArgCount = 1;
	LPVOID _server = server.get();
	LPVOID _prawserver = &_server;
	arguments.m_arg[0].m_inf.m_ppCompoundData = (void**)&_prawserver;
	arguments.m_arg[0].m_dwState = EAV_IS_POINTER;
	NotifySys(NRS_EVENT_NOTIFY2, (DWORD)&arguments, 0); 
}
void EPLClient::OnServerDestroyed(shrewd_ptr<ProxyServer> server){
	if(!m_mainWindow || m_mainWindow->isDestory == TRUE){	
		m_mainWindow = NULL;
		return ; 
	}
	ProxyClient::OnServerDestroyed(server);
	EVENT_NOTIFY2 arguments(m_mainWindow->dwWinFormID, m_mainWindow->dwUnitID,39);
	arguments.m_nArgCount = 1;
	LPVOID _server = server.get();
	LPVOID _prawserver = &_server;
	arguments.m_arg[0].m_inf.m_ppCompoundData = (void**)&_prawserver;
	arguments.m_arg[0].m_dwState = EAV_IS_POINTER;
	NotifySys(NRS_EVENT_NOTIFY2, (DWORD)&arguments, 0); 
}
void EPLClient::OnClientConnected(shrewd_ptr<ProxyServer> server,int connection_id){
	if(!m_mainWindow || m_mainWindow->isDestory == TRUE){	
		m_mainWindow = NULL;
		return ; 
	}
	ProxyClient::OnClientConnected(server,connection_id);
	EVENT_NOTIFY2 arguments(m_mainWindow->dwWinFormID, m_mainWindow->dwUnitID,40);
	arguments.m_nArgCount = 2;
	LPVOID _server = server.get();
	LPVOID _prawserver = &_server;
	arguments.m_arg[0].m_inf.m_ppCompoundData = (void**)&_prawserver;
	arguments.m_arg[0].m_dwState = EAV_IS_POINTER;
	arguments.m_arg[1].m_inf.m_dtDataType = SDT_INT;
	arguments.m_arg[1].m_inf.m_int = connection_id;
	arguments.m_arg[1].m_dwState = 0;
	NotifySys(NRS_EVENT_NOTIFY2, (DWORD)&arguments, 0); 
}
void EPLClient::OnClientDisconnected(shrewd_ptr<ProxyServer> server,int connection_id){
	if(!m_mainWindow || m_mainWindow->isDestory == TRUE){	
		m_mainWindow = NULL;
		return ; 
	}
	ProxyClient::OnClientDisconnected(server,connection_id);
	EVENT_NOTIFY2 arguments(m_mainWindow->dwWinFormID, m_mainWindow->dwUnitID,41);
	arguments.m_nArgCount = 2;
	LPVOID _server = server.get();
	LPVOID _prawserver = &_server;
	arguments.m_arg[0].m_inf.m_ppCompoundData = (void**)&_prawserver;
	arguments.m_arg[0].m_dwState = EAV_IS_POINTER;
	arguments.m_arg[1].m_inf.m_dtDataType = SDT_INT;
	arguments.m_arg[1].m_inf.m_int = connection_id;
	arguments.m_arg[1].m_dwState = 0;
	NotifySys(NRS_EVENT_NOTIFY2, (DWORD)&arguments, 0); 
}
void EPLClient::OnHttpRequest(shrewd_ptr<ProxyServer> server,int connection_id,const char* client_address,shrewd_ptr<ProxyRequest> request){
	if(!m_mainWindow || m_mainWindow->isDestory == TRUE){	
		m_mainWindow = NULL;
		return ; 
	}
	ProxyClient::OnHttpRequest(server,connection_id,client_address,request);
	EVENT_NOTIFY2 arguments(m_mainWindow->dwWinFormID, m_mainWindow->dwUnitID,42);
	arguments.m_nArgCount = 4;
	LPVOID _server = server.get();
	LPVOID _prawserver = &_server;
	arguments.m_arg[0].m_inf.m_ppCompoundData = (void**)&_prawserver;
	arguments.m_arg[0].m_dwState = EAV_IS_POINTER;
	arguments.m_arg[1].m_inf.m_dtDataType = SDT_INT;
	arguments.m_arg[1].m_inf.m_int = connection_id;
	arguments.m_arg[1].m_dwState = 0;
	arguments.m_arg[2].m_inf.m_dtDataType = SDT_TEXT;
	arguments.m_arg[2].m_inf.m_ppText = (LPTSTR*)&client_address;
	arguments.m_arg[2].m_dwState = EAV_IS_POINTER;
	LPVOID _request = request.get();
	LPVOID _prawrequest = &_request;
	arguments.m_arg[3].m_inf.m_ppCompoundData = (void**)&_prawrequest;
	arguments.m_arg[3].m_dwState = EAV_IS_POINTER;
	NotifySys(NRS_EVENT_NOTIFY2, (DWORD)&arguments, 0); 
}
bool EPLClient::OnWebSocketRequest(shrewd_ptr<ProxyServer> server,int connection_id,const char* client_address,shrewd_ptr<ProxyRequest> request){
	bool result = NULL; 
	if(!m_mainWindow || m_mainWindow->isDestory == TRUE){	
		m_mainWindow = NULL;
		return result; 
	}
	ProxyClient::OnWebSocketRequest(server,connection_id,client_address,request);
	EVENT_NOTIFY2 arguments(m_mainWindow->dwWinFormID, m_mainWindow->dwUnitID,43);
	arguments.m_nArgCount = 4;
	LPVOID _server = server.get();
	LPVOID _prawserver = &_server;
	arguments.m_arg[0].m_inf.m_ppCompoundData = (void**)&_prawserver;
	arguments.m_arg[0].m_dwState = EAV_IS_POINTER;
	arguments.m_arg[1].m_inf.m_dtDataType = SDT_INT;
	arguments.m_arg[1].m_inf.m_int = connection_id;
	arguments.m_arg[1].m_dwState = 0;
	arguments.m_arg[2].m_inf.m_dtDataType = SDT_TEXT;
	arguments.m_arg[2].m_inf.m_ppText = (LPTSTR*)&client_address;
	arguments.m_arg[2].m_dwState = EAV_IS_POINTER;
	LPVOID _request = request.get();
	LPVOID _prawrequest = &_request;
	arguments.m_arg[3].m_inf.m_ppCompoundData = (void**)&_prawrequest;
	arguments.m_arg[3].m_dwState = EAV_IS_POINTER;
	if(NotifySys(NRS_EVENT_NOTIFY2, (DWORD)&arguments, 0) != 0){
		if(arguments.m_blHasRetVal){
			result = arguments.m_infRetData.m_bool;
		}
	}
	return result; 
}
void EPLClient::OnWebSocketConnected(shrewd_ptr<ProxyServer> server,int connection_id){
	if(!m_mainWindow || m_mainWindow->isDestory == TRUE){	
		m_mainWindow = NULL;
		return ; 
	}
	ProxyClient::OnWebSocketConnected(server,connection_id);
	EVENT_NOTIFY2 arguments(m_mainWindow->dwWinFormID, m_mainWindow->dwUnitID,44);
	arguments.m_nArgCount = 2;
	LPVOID _server = server.get();
	LPVOID _prawserver = &_server;
	arguments.m_arg[0].m_inf.m_ppCompoundData = (void**)&_prawserver;
	arguments.m_arg[0].m_dwState = EAV_IS_POINTER;
	arguments.m_arg[1].m_inf.m_dtDataType = SDT_INT;
	arguments.m_arg[1].m_inf.m_int = connection_id;
	arguments.m_arg[1].m_dwState = 0;
	NotifySys(NRS_EVENT_NOTIFY2, (DWORD)&arguments, 0); 
}
void EPLClient::OnWebSocketMessage(shrewd_ptr<ProxyServer> server,int connection_id,const unsigned char* data,int data_size){
	if(!m_mainWindow || m_mainWindow->isDestory == TRUE){	
		m_mainWindow = NULL;
		return ; 
	}
	ProxyClient::OnWebSocketMessage(server,connection_id,data,data_size);
	EVENT_NOTIFY2 arguments(m_mainWindow->dwWinFormID, m_mainWindow->dwUnitID,45);
	arguments.m_nArgCount = 4;
	LPVOID _server = server.get();
	LPVOID _prawserver = &_server;
	arguments.m_arg[0].m_inf.m_ppCompoundData = (void**)&_prawserver;
	arguments.m_arg[0].m_dwState = EAV_IS_POINTER;
	arguments.m_arg[1].m_inf.m_dtDataType = SDT_INT;
	arguments.m_arg[1].m_inf.m_int = connection_id;
	arguments.m_arg[1].m_dwState = 0;
	arguments.m_arg[2].m_inf.m_dtDataType = SDT_BIN;
	arguments.m_arg[2].m_inf.m_ppBin = (unsigned char**)&data;
	arguments.m_arg[2].m_dwState = EAV_IS_POINTER;
	arguments.m_arg[3].m_inf.m_dtDataType = SDT_INT;
	arguments.m_arg[3].m_inf.m_int = data_size;
	arguments.m_arg[3].m_dwState = 0;
	NotifySys(NRS_EVENT_NOTIFY2, (DWORD)&arguments, 0); 
}
void EPLClient::OnWebSocketClientConnected(shrewd_ptr<ProxyWebSocket> websocket){
	if(!m_mainWindow || m_mainWindow->isDestory == TRUE){	
		m_mainWindow = NULL;
		return ; 
	}
	ProxyClient::OnWebSocketClientConnected(websocket);
	EVENT_NOTIFY2 arguments(m_mainWindow->dwWinFormID, m_mainWindow->dwUnitID,46);
	arguments.m_nArgCount = 1;
	LPVOID _websocket = websocket.get();
	LPVOID _prawwebsocket = &_websocket;
	arguments.m_arg[0].m_inf.m_ppCompoundData = (void**)&_prawwebsocket;
	arguments.m_arg[0].m_dwState = EAV_IS_POINTER;
	NotifySys(NRS_EVENT_NOTIFY2, (DWORD)&arguments, 0); 
}
void EPLClient::OnWebSocketClientClosed(shrewd_ptr<ProxyWebSocket> websocket){
	if(!m_mainWindow || m_mainWindow->isDestory == TRUE){	
		m_mainWindow = NULL;
		return ; 
	}
	ProxyClient::OnWebSocketClientClosed(websocket);
	EVENT_NOTIFY2 arguments(m_mainWindow->dwWinFormID, m_mainWindow->dwUnitID,47);
	arguments.m_nArgCount = 1;
	LPVOID _websocket = websocket.get();
	LPVOID _prawwebsocket = &_websocket;
	arguments.m_arg[0].m_inf.m_ppCompoundData = (void**)&_prawwebsocket;
	arguments.m_arg[0].m_dwState = EAV_IS_POINTER;
	NotifySys(NRS_EVENT_NOTIFY2, (DWORD)&arguments, 0); 
}
void EPLClient::OnWebSocketClientMessage(shrewd_ptr<ProxyWebSocket> websocket,int type,const unsigned char* message){
	if(!m_mainWindow || m_mainWindow->isDestory == TRUE){	
		m_mainWindow = NULL;
		return ; 
	}
	ProxyClient::OnWebSocketClientMessage(websocket,type,message);
	EVENT_NOTIFY2 arguments(m_mainWindow->dwWinFormID, m_mainWindow->dwUnitID,48);
	arguments.m_nArgCount = 3;
	LPVOID _websocket = websocket.get();
	LPVOID _prawwebsocket = &_websocket;
	arguments.m_arg[0].m_inf.m_ppCompoundData = (void**)&_prawwebsocket;
	arguments.m_arg[0].m_dwState = EAV_IS_POINTER;
	arguments.m_arg[1].m_inf.m_dtDataType = SDT_INT;
	arguments.m_arg[1].m_inf.m_int = type;
	arguments.m_arg[1].m_dwState = 0;
	arguments.m_arg[2].m_inf.m_dtDataType = SDT_BIN;
	arguments.m_arg[2].m_inf.m_ppBin = (unsigned char**)&message;
	arguments.m_arg[2].m_dwState = EAV_IS_POINTER;
	NotifySys(NRS_EVENT_NOTIFY2, (DWORD)&arguments, 0); 
}
void EPLClient::OnWebSocketClientError(shrewd_ptr<ProxyWebSocket> websocket,const char* error){
	if(!m_mainWindow || m_mainWindow->isDestory == TRUE){	
		m_mainWindow = NULL;
		return ; 
	}
	ProxyClient::OnWebSocketClientError(websocket,error);
	EVENT_NOTIFY2 arguments(m_mainWindow->dwWinFormID, m_mainWindow->dwUnitID,49);
	arguments.m_nArgCount = 2;
	LPVOID _websocket = websocket.get();
	LPVOID _prawwebsocket = &_websocket;
	arguments.m_arg[0].m_inf.m_ppCompoundData = (void**)&_prawwebsocket;
	arguments.m_arg[0].m_dwState = EAV_IS_POINTER;
	arguments.m_arg[1].m_inf.m_dtDataType = SDT_TEXT;
	arguments.m_arg[1].m_inf.m_ppText = (LPTSTR*)&error;
	arguments.m_arg[1].m_dwState = EAV_IS_POINTER;
	NotifySys(NRS_EVENT_NOTIFY2, (DWORD)&arguments, 0); 
}
void EPLClient::OnExtensionLoadFailed(int result){
	if(!m_mainWindow || m_mainWindow->isDestory == TRUE){	
		m_mainWindow = NULL;
		return ; 
	}
	ProxyClient::OnExtensionLoadFailed(result);
	EVENT_NOTIFY2 arguments(m_mainWindow->dwWinFormID, m_mainWindow->dwUnitID,50);
	arguments.m_nArgCount = 1;
	arguments.m_arg[0].m_inf.m_dtDataType = SDT_INT;
	arguments.m_arg[0].m_inf.m_int = result;
	arguments.m_arg[0].m_dwState = 0;
	NotifySys(NRS_EVENT_NOTIFY2, (DWORD)&arguments, 0); 
}
void EPLClient::OnExtensionLoaded(shrewd_ptr<ProxyExtension> extension){
	if(!m_mainWindow || m_mainWindow->isDestory == TRUE){	
		m_mainWindow = NULL;
		return ; 
	}
	ProxyClient::OnExtensionLoaded(extension);
	EVENT_NOTIFY2 arguments(m_mainWindow->dwWinFormID, m_mainWindow->dwUnitID,51);
	arguments.m_nArgCount = 1;
	LPVOID _extension = extension.get();
	LPVOID _prawextension = &_extension;
	arguments.m_arg[0].m_inf.m_ppCompoundData = (void**)&_prawextension;
	arguments.m_arg[0].m_dwState = EAV_IS_POINTER;
	NotifySys(NRS_EVENT_NOTIFY2, (DWORD)&arguments, 0); 
}
void EPLClient::OnExtensionUnloaded(shrewd_ptr<ProxyExtension> extension){
	if(!m_mainWindow || m_mainWindow->isDestory == TRUE){	
		m_mainWindow = NULL;
		return ; 
	}
	ProxyClient::OnExtensionUnloaded(extension);
	EVENT_NOTIFY2 arguments(m_mainWindow->dwWinFormID, m_mainWindow->dwUnitID,52);
	arguments.m_nArgCount = 1;
	LPVOID _extension = extension.get();
	LPVOID _prawextension = &_extension;
	arguments.m_arg[0].m_inf.m_ppCompoundData = (void**)&_prawextension;
	arguments.m_arg[0].m_dwState = EAV_IS_POINTER;
	NotifySys(NRS_EVENT_NOTIFY2, (DWORD)&arguments, 0); 
}
bool EPLClient::OnBeforeBackgroundBrowser(shrewd_ptr<ProxyExtension> extension,const char* url){
	bool result = NULL; 
	if(!m_mainWindow || m_mainWindow->isDestory == TRUE){	
		m_mainWindow = NULL;
		return result; 
	}
	ProxyClient::OnBeforeBackgroundBrowser(extension,url);
	EVENT_NOTIFY2 arguments(m_mainWindow->dwWinFormID, m_mainWindow->dwUnitID,53);
	arguments.m_nArgCount = 2;
	LPVOID _extension = extension.get();
	LPVOID _prawextension = &_extension;
	arguments.m_arg[0].m_inf.m_ppCompoundData = (void**)&_prawextension;
	arguments.m_arg[0].m_dwState = EAV_IS_POINTER;
	arguments.m_arg[1].m_inf.m_dtDataType = SDT_TEXT;
	arguments.m_arg[1].m_inf.m_ppText = (LPTSTR*)&url;
	arguments.m_arg[1].m_dwState = EAV_IS_POINTER;
	if(NotifySys(NRS_EVENT_NOTIFY2, (DWORD)&arguments, 0) != 0){
		if(arguments.m_blHasRetVal){
			result = arguments.m_infRetData.m_bool;
		}
	}
	return result; 
}
bool EPLClient::OnBeforeBrowser(shrewd_ptr<ProxyExtension> extension,shrewd_ptr<ProxyBrowser> browser,shrewd_ptr<ProxyBrowser> active_browser,int index,const char* url,bool active,shrewd_ptr<ProxyWindowInfo>& windowInfo){
	bool result = NULL; 
	if(!m_mainWindow || m_mainWindow->isDestory == TRUE){	
		m_mainWindow = NULL;
		return result; 
	}
	ProxyClient::OnBeforeBrowser(extension,browser,active_browser,index,url,active,windowInfo);
	EVENT_NOTIFY2 arguments(m_mainWindow->dwWinFormID, m_mainWindow->dwUnitID,54);
	arguments.m_nArgCount = 7;
	LPVOID _extension = extension.get();
	LPVOID _prawextension = &_extension;
	arguments.m_arg[0].m_inf.m_ppCompoundData = (void**)&_prawextension;
	arguments.m_arg[0].m_dwState = EAV_IS_POINTER;
	LPVOID _browser = browser.get();
	LPVOID _prawbrowser = &_browser;
	arguments.m_arg[1].m_inf.m_ppCompoundData = (void**)&_prawbrowser;
	arguments.m_arg[1].m_dwState = EAV_IS_POINTER;
	LPVOID _active_browser = active_browser.get();
	LPVOID _prawactive_browser = &_active_browser;
	arguments.m_arg[2].m_inf.m_ppCompoundData = (void**)&_prawactive_browser;
	arguments.m_arg[2].m_dwState = EAV_IS_POINTER;
	arguments.m_arg[3].m_inf.m_dtDataType = SDT_INT;
	arguments.m_arg[3].m_inf.m_int = index;
	arguments.m_arg[3].m_dwState = 0;
	arguments.m_arg[4].m_inf.m_dtDataType = SDT_TEXT;
	arguments.m_arg[4].m_inf.m_ppText = (LPTSTR*)&url;
	arguments.m_arg[4].m_dwState = EAV_IS_POINTER;
	arguments.m_arg[5].m_inf.m_dtDataType = SDT_BOOL;
	arguments.m_arg[5].m_inf.m_bool = (BOOL)active;
	arguments.m_arg[5].m_dwState = 0;
	LPVOID _windowInfo = windowInfo.get();
	LPVOID _prawwindowInfo = &_windowInfo;
	arguments.m_arg[6].m_inf.m_ppCompoundData = (void**)&_prawwindowInfo;
	arguments.m_arg[6].m_dwState = EAV_IS_POINTER;
	if(NotifySys(NRS_EVENT_NOTIFY2, (DWORD)&arguments, 0) != 0){
		if(arguments.m_blHasRetVal){
			result = arguments.m_infRetData.m_bool;
		}
	}
	return result; 
}
bool EPLClient::CanAccessBrowser(shrewd_ptr<ProxyExtension> extension,shrewd_ptr<ProxyBrowser> browser,bool include_incognito,shrewd_ptr<ProxyBrowser> target_browser){
	bool result = NULL; 
	if(!m_mainWindow || m_mainWindow->isDestory == TRUE){	
		m_mainWindow = NULL;
		return result; 
	}
	ProxyClient::CanAccessBrowser(extension,browser,include_incognito,target_browser);
	EVENT_NOTIFY2 arguments(m_mainWindow->dwWinFormID, m_mainWindow->dwUnitID,55);
	arguments.m_nArgCount = 4;
	LPVOID _extension = extension.get();
	LPVOID _prawextension = &_extension;
	arguments.m_arg[0].m_inf.m_ppCompoundData = (void**)&_prawextension;
	arguments.m_arg[0].m_dwState = EAV_IS_POINTER;
	LPVOID _browser = browser.get();
	LPVOID _prawbrowser = &_browser;
	arguments.m_arg[1].m_inf.m_ppCompoundData = (void**)&_prawbrowser;
	arguments.m_arg[1].m_dwState = EAV_IS_POINTER;
	arguments.m_arg[2].m_inf.m_dtDataType = SDT_BOOL;
	arguments.m_arg[2].m_inf.m_bool = (BOOL)include_incognito;
	arguments.m_arg[2].m_dwState = 0;
	LPVOID _target_browser = target_browser.get();
	LPVOID _prawtarget_browser = &_target_browser;
	arguments.m_arg[3].m_inf.m_ppCompoundData = (void**)&_prawtarget_browser;
	arguments.m_arg[3].m_dwState = EAV_IS_POINTER;
	if(NotifySys(NRS_EVENT_NOTIFY2, (DWORD)&arguments, 0) != 0){
		if(arguments.m_blHasRetVal){
			result = arguments.m_infRetData.m_bool;
		}
	}
	return result; 
}
void EPLClient::GetActiveBrowser(shrewd_ptr<ProxyExtension> extension,shrewd_ptr<ProxyBrowser> browser,bool include_incognito,shrewd_ptr<ProxyActiveBrowserCallback> callback){
	if(!m_mainWindow || m_mainWindow->isDestory == TRUE){	
		m_mainWindow = NULL;
		return ; 
	}
	ProxyClient::GetActiveBrowser(extension,browser,include_incognito,callback);
	EVENT_NOTIFY2 arguments(m_mainWindow->dwWinFormID, m_mainWindow->dwUnitID,56);
	arguments.m_nArgCount = 4;
	LPVOID _extension = extension.get();
	LPVOID _prawextension = &_extension;
	arguments.m_arg[0].m_inf.m_ppCompoundData = (void**)&_prawextension;
	arguments.m_arg[0].m_dwState = EAV_IS_POINTER;
	LPVOID _browser = browser.get();
	LPVOID _prawbrowser = &_browser;
	arguments.m_arg[1].m_inf.m_ppCompoundData = (void**)&_prawbrowser;
	arguments.m_arg[1].m_dwState = EAV_IS_POINTER;
	arguments.m_arg[2].m_inf.m_dtDataType = SDT_BOOL;
	arguments.m_arg[2].m_inf.m_bool = (BOOL)include_incognito;
	arguments.m_arg[2].m_dwState = 0;
	LPVOID _callback = callback.get();
	LPVOID _prawcallback = &_callback;
	arguments.m_arg[3].m_inf.m_ppCompoundData = (void**)&_prawcallback;
	arguments.m_arg[3].m_dwState = EAV_IS_POINTER;
	NotifySys(NRS_EVENT_NOTIFY2, (DWORD)&arguments, 0); 
}
bool EPLClient::GetExtensionResource(shrewd_ptr<ProxyExtension> extension,shrewd_ptr<ProxyBrowser> browser,const char* file,shrewd_ptr<ProxyGetExtensionResourceCallback> callback){
	bool result = NULL; 
	if(!m_mainWindow || m_mainWindow->isDestory == TRUE){	
		m_mainWindow = NULL;
		return result; 
	}
	ProxyClient::GetExtensionResource(extension,browser,file,callback);
	EVENT_NOTIFY2 arguments(m_mainWindow->dwWinFormID, m_mainWindow->dwUnitID,57);
	arguments.m_nArgCount = 4;
	LPVOID _extension = extension.get();
	LPVOID _prawextension = &_extension;
	arguments.m_arg[0].m_inf.m_ppCompoundData = (void**)&_prawextension;
	arguments.m_arg[0].m_dwState = EAV_IS_POINTER;
	LPVOID _browser = browser.get();
	LPVOID _prawbrowser = &_browser;
	arguments.m_arg[1].m_inf.m_ppCompoundData = (void**)&_prawbrowser;
	arguments.m_arg[1].m_dwState = EAV_IS_POINTER;
	arguments.m_arg[2].m_inf.m_dtDataType = SDT_TEXT;
	arguments.m_arg[2].m_inf.m_ppText = (LPTSTR*)&file;
	arguments.m_arg[2].m_dwState = EAV_IS_POINTER;
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
bool EPLClient::OnQuery(shrewd_ptr<ProxyBrowser> browser,shrewd_ptr<ProxyFrame> frame,__int64 query_id,const char* request,bool persistent,shrewd_ptr<ProxyQueryCallback> callback){
	bool result = NULL; 
	if(!m_mainWindow || m_mainWindow->isDestory == TRUE){	
		m_mainWindow = NULL;
		return result; 
	}
	ProxyClient::OnQuery(browser,frame,query_id,request,persistent,callback);
	EVENT_NOTIFY2 arguments(m_mainWindow->dwWinFormID, m_mainWindow->dwUnitID,58);
	arguments.m_nArgCount = 6;
	LPVOID _browser = browser.get();
	LPVOID _prawbrowser = &_browser;
	arguments.m_arg[0].m_inf.m_ppCompoundData = (void**)&_prawbrowser;
	arguments.m_arg[0].m_dwState = EAV_IS_POINTER;
	LPVOID _frame = frame.get();
	LPVOID _prawframe = &_frame;
	arguments.m_arg[1].m_inf.m_ppCompoundData = (void**)&_prawframe;
	arguments.m_arg[1].m_dwState = EAV_IS_POINTER;
	arguments.m_arg[2].m_inf.m_dtDataType = SDT_INT64;
	arguments.m_arg[2].m_inf.m_int64 = query_id;
	arguments.m_arg[2].m_dwState = 0;
	arguments.m_arg[3].m_inf.m_dtDataType = SDT_TEXT;
	arguments.m_arg[3].m_inf.m_ppText = (LPTSTR*)&request;
	arguments.m_arg[3].m_dwState = EAV_IS_POINTER;
	arguments.m_arg[4].m_inf.m_dtDataType = SDT_BOOL;
	arguments.m_arg[4].m_inf.m_bool = (BOOL)persistent;
	arguments.m_arg[4].m_dwState = 0;
	LPVOID _callback = callback.get();
	LPVOID _prawcallback = &_callback;
	arguments.m_arg[5].m_inf.m_ppCompoundData = (void**)&_prawcallback;
	arguments.m_arg[5].m_dwState = EAV_IS_POINTER;
	if(NotifySys(NRS_EVENT_NOTIFY2, (DWORD)&arguments, 0) != 0){
		if(arguments.m_blHasRetVal){
			result = arguments.m_infRetData.m_bool;
		}
	}
	return result; 
}
void EPLClient::OnQueryCanceled(shrewd_ptr<ProxyBrowser> browser,shrewd_ptr<ProxyFrame> frame,__int64 query_id){
	if(!m_mainWindow || m_mainWindow->isDestory == TRUE){	
		m_mainWindow = NULL;
		return ; 
	}
	ProxyClient::OnQueryCanceled(browser,frame,query_id);
	EVENT_NOTIFY2 arguments(m_mainWindow->dwWinFormID, m_mainWindow->dwUnitID,59);
	arguments.m_nArgCount = 3;
	LPVOID _browser = browser.get();
	LPVOID _prawbrowser = &_browser;
	arguments.m_arg[0].m_inf.m_ppCompoundData = (void**)&_prawbrowser;
	arguments.m_arg[0].m_dwState = EAV_IS_POINTER;
	LPVOID _frame = frame.get();
	LPVOID _prawframe = &_frame;
	arguments.m_arg[1].m_inf.m_ppCompoundData = (void**)&_prawframe;
	arguments.m_arg[1].m_dwState = EAV_IS_POINTER;
	arguments.m_arg[2].m_inf.m_dtDataType = SDT_INT64;
	arguments.m_arg[2].m_inf.m_int64 = query_id;
	arguments.m_arg[2].m_dwState = 0;
	NotifySys(NRS_EVENT_NOTIFY2, (DWORD)&arguments, 0); 
}



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
		else if(pArgInf->m_dtDataType == MAKELONG(11,0)){
			if(pArgInf->m_ppCompoundData && *pArgInf->m_ppCompoundData){
				shrewd_ptr<ProxyDictionaryValue> argValue = (ProxyDictionaryValue*)*pArgInf->m_ppCompoundData;
				object->SetDictionary(argValue);
			}
		}
		else if(pArgInf->m_dtDataType == MAKELONG(20,0)){
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
			else if(pArgInf[i].m_dtDataType == MAKELONG(11,0)){
				if(pArgInf[i].m_ppCompoundData && *pArgInf[i].m_ppCompoundData){
					shrewd_ptr<ProxyDictionaryValue> argValue = (ProxyDictionaryValue*)*pArgInf[i].m_ppCompoundData;
					object->SetDictionary(i,argValue);
				}
			}
			else if(pArgInf[i].m_dtDataType == MAKELONG(31,0)){
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
	bool argIncognito_Mode = pArgInf[4].m_bool;
	pRetData->m_bool = self->CreateBrowser(argWininfo,argUrl,argSettings,argIncognito_Mode);
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
void EDITIONF(ProxyClient_GetBrowserWithHandle) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		
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

extern "C"
void EDITIONF(ProxyClient_GetBrowserWithIndex) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		
		return ;
	}
	shrewd_ptr<ProxyClient> self = (ProxyClient*)*pArgInf->m_ppCompoundData;
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
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_int = 0;
		return ;
	}
	shrewd_ptr<ProxyClient> self = (ProxyClient*)*pArgInf->m_ppCompoundData;
	shrewd_ptr<ProxyBrowser> argBrowser = (ProxyBrowser*)*pArgInf[1].m_ppCompoundData;
	pRetData->m_int = self->GetIndex(argBrowser);
}

extern "C"
void EDITIONF(ProxyClient_GetSameOriginBrowser) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		DWORD* InternalPointer = (DWORD*)NotifySys(NRS_MALLOC, 8, 0);
		InternalPointer[0] = 1;
		InternalPointer[1] = 0;
		pRetData->m_pCompoundData = InternalPointer;
		return ;
	}
	shrewd_ptr<ProxyClient> self = (ProxyClient*)*pArgInf->m_ppCompoundData;
	shrewd_ptr<ProxyBrowser> argBrowser = (ProxyBrowser*)*pArgInf[1].m_ppCompoundData;
	pRetData->m_pCompoundData = (void*)self->GetSameOriginBrowser(argBrowser);
}





#endif
