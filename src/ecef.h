// ecef.h : main header file for the ECEF DLL
//

#if !defined(AFX_ECEF_H__6114A255_D522_4DB2_95E3_359430341547__INCLUDED_)
#define AFX_ECEF_H__6114A255_D522_4DB2_95E3_359430341547__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CEcefApp
// See ecef.cpp for the implementation of this class
//

class CEcefApp : public CWinApp
{
public:
	CEcefApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEcefApp)
	//}}AFX_VIRTUAL

	//{{AFX_MSG(CEcefApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ECEF_H__6114A255_D522_4DB2_95E3_359430341547__INCLUDED_)
