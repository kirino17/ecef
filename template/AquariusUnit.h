#pragma once
#include "stdafx.h"
#include <windows.h>
##{{0}}
#include "lib2.h"
#include "resource.h"


#define DATA_TYPE_AQUARIUS_UNIT \
	{ \
		/*m_szName*/			_WT("水星铬浏览框"), \
		/*m_szEgName*/			_WT("Chromium"), \
		/*m_szExplain*/			_WT("提供浏览器对象的生命周期管理以及事件派发支持。"), \
		/*m_nCmdCount*/			sizeof(s_nChromiumElementCmdIndex) / sizeof(s_nChromiumElementCmdIndex[0]), \
		/*m_pnCmdsIndex*/ 		s_nChromiumElementCmdIndex, \
		/*m_dwState*/			_DT_OS (__OS_WIN) | LDT_WIN_UNIT, \
		/*m_dwUnitBmpID*/		IDB_AQUARIUS_CHROMIUM_BITMAP, \
		/*m_nEventCount*/		sizeof(s_ChromiumEvent) / sizeof(s_ChromiumEvent[0]), \
		/*m_pEventBegin*/		s_ChromiumEvent, \
		/*m_nPropertyCount*/	sizeof(s_ChromiumProperty) / sizeof(s_ChromiumProperty[0]), \
		/*m_pPropertyBegin*/	s_ChromiumProperty, \
		/*m_pfnGetInterface*/	EDITIONF(GetInterface_Chromium), \
		/*m_nElementCount*/		0, \
		/*m_pElementBegin*/		NULL \
	}, \


///////////////////////////////////////////////////////////////////////////

#include "untshare.h"
class AquariusProperty : public CPropertyInfo{

public:
	AquariusProperty():nBorderStyle(0){}
	~AquariusProperty(){}

public:
	int nBorderStyle;

public:
	virtual void init(void);
	virtual BOOL Serialize(CArchive& ar);
};


#define AQUARIUS_UNIT_VER (1)


extern"C"
PFN_INTERFACE WINAPI EDITIONF(GetInterface_Chromium)(INT nInterfaceNO);
HUNIT WINAPI EDITIONF(Create_Chromium)(LPBYTE pAllData, INT nAllDataSize,
	DWORD dwStyle, HWND hParentWnd, UINT uID, HMENU hMenu, INT x, INT y, INT cx, INT cy,
	DWORD dwWinFormID, DWORD dwUnitID, HWND hDesignWnd = 0, BOOL blInDesignMode = FALSE);
BOOL WINAPI EDITIONF(NotifyPropertyChanged_Chromium) (HUNIT hUnit, INT nPropertyIndex,
	PUNIT_PROPERTY_VALUE pPropertyVaule, LPCTSTR* ppszTipText);
BOOL WINAPI EDITIONF(GetPropertyData_Chromium) (HUNIT hUnit, INT nPropertyIndex,
PUNIT_PROPERTY_VALUE pPropertyVaule_Chromium);
HGLOBAL WINAPI EDITIONF(GetAllPropertyData_Chromium) (HUNIT hUnit);


class AquariusUnit : public CWnd, public ##{{1}} {
public:
	AquariusUnit();
	~AquariusUnit();

public:
	AquariusProperty propertices;
	DWORD dwWinFormID;
	DWORD dwUnitID;
	BOOL inDesignMode;
	BOOL isDestory;

public:
	BOOL Create(HWND hParentWnd, DWORD dwStyle, UINT uID, INT x, INT y, INT cx, INT cy);

public:
	void SetBorder(int nType);

public:
	PRIME_IMPLEMENT_REFCOUNTING(AquariusUnit);

protected:
	virtual void PostNcDestroy(void);
public:
	afx_msg void OnSetFocus(CWnd* pOldWnd);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnDestroy();
	DECLARE_MESSAGE_MAP();
};


class EPLClient : public ##{{1}} {
public:
	EPLClient();
	~EPLClient();

public:
	static shrewd_ptr<EPLClient> GetInstance();

public:
	##{{2}}

public:
	void SetMainWindow(shrewd_ptr<AquariusUnit> window);

public:
	PRIME_IMPLEMENT_REFCOUNTING(EPLClient);

private:
	shrewd_ptr<AquariusUnit> m_mainWindow;
};

##{{3}}
