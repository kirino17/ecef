
/*
    版权声明：
    本文件版权为易语言作者吴涛所有，仅授权给第三方用作开发易语言支持库，禁止用于其他任何场合。
*/

#ifndef __UNTSHARE_H
#define	__UNTSHARE_H
#include "lib2.h"

class CPropertyInfo
{
public:
	CPropertyInfo ()
	{
		init ();
	}

	virtual void init ()  { }
	virtual BOOL Serialize (CArchive& ar)
	{
		if (ar.IsLoading () == TRUE)
			init ();
		return TRUE;
	}

	HGLOBAL SaveData ();
	BOOL LoadData (LPBYTE pData, INT nDataSize);
};

COLORREF ProcessSysBackColor (COLORREF clr);
BOOL CreateImageList (CImageList* pimgList, LPBYTE p, INT nSize);
void ChangeBorder (CWnd* pUnit, INT nBorderType);

CWnd* GetWndPtr (PMDATA_INF parg);
BOOL MyCreateFont (CFont& font, LOGFONT* pLogFont);
void ModiUnitStyle (CWnd* pUnit, DWORD dwAddStyle, DWORD dwRemoveStyle);
void SetUnitStyle (CWnd* pUnit, BOOL blSet, DWORD dwStyle);
void SerializeCString (CString& str, CArchive& ar);
void SetStr (CString& str, LPTSTR szText);

#endif

