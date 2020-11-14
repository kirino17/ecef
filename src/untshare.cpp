#include "stdafx.h"
#include "def/def.h"
#include "untshare.h"
#include <afxadv.h>

extern INT WINAPI NotifySys (INT nMsg, DWORD dwParam1, DWORD dwParam2);

/*
    版权声明：
    本文件版权为易语言作者吴涛所有，仅授权给第三方用作开发易语言支持库，禁止用于其他任何场合。
*/

HGLOBAL CPropertyInfo::SaveData ()
{
	CSharedFile file;
	CArchive ar (&file, CArchive::store);

	if (Serialize (ar) == TRUE)
	{
		ar.Close ();

		DWORD dwLength = file.GetLength ();
		HGLOBAL hGlobal = file.Detach ();
		::GlobalUnlock (hGlobal);
		::GlobalReAlloc (hGlobal, dwLength, GMEM_DDESHARE | GMEM_MOVEABLE);
		//     注意由于Windows系统内存管理按字对齐的原因，最后hGlobal的大小（GloalSize返回）
		// 可能会大于dwLength值0-3个字节。

		return hGlobal;
	}
	else
		return NULL;
}

BOOL CPropertyInfo::LoadData (LPBYTE pData, INT nDataSize)
{
	init ();

	if (pData != NULL && nDataSize > 0)
	{
		CMemFile file;
		file.Attach (pData, nDataSize);

		CArchive ar (&file, CArchive::load);
		return Serialize (ar);
	}
	else
		return TRUE;
}

void ChangeBorder (CWnd* pUnit, INT nBorderType)
{
	DWORD dwStyle = NULL, dwExStyle = NULL;
	switch (nBorderType)
	{
//	case 0:		// 无边框
//		break;
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
	pUnit->ModifyStyleEx (WS_EX_STATICEDGE | WS_EX_CLIENTEDGE | WS_EX_DLGMODALFRAME,
			dwExStyle, SWP_NOSIZE | SWP_NOMOVE | SWP_NOZORDER | SWP_NOACTIVATE |
			SWP_FRAMECHANGED | SWP_DRAWFRAME);
	pUnit->ModifyStyle (WS_BORDER, dwStyle,
			SWP_NOSIZE | SWP_NOMOVE | SWP_NOZORDER | SWP_NOACTIVATE |
			SWP_FRAMECHANGED | SWP_DRAWFRAME);
}

BOOL CreateImageList (CImageList* pimgList, LPBYTE p, INT nSize)
{
	pimgList->DeleteImageList ();

	if (nSize > sizeof (DWORD) + sizeof (COLORREF) &&
			*(LPDWORD)p == IMAGE_LIST_DATA_MARK)
	{
		CMemFile file;
		file.Attach (p + sizeof (DWORD) + sizeof (COLORREF),
				nSize - sizeof (DWORD) - sizeof (COLORREF));
		CArchive ar (&file, CArchive::load);
		return pimgList->Read (&ar);
	}
	else
		return FALSE;
}

COLORREF ProcessSysBackColor (COLORREF clr)
{
	if (clr == CLR_DEFAULT)
		return ::GetSysColor (COLOR_BTNFACE);
	else
		return clr;
}

// 绝对不会返回NULL或者窗口句柄无效的CWnd*指针。
CWnd* GetWndPtr (PMDATA_INF pInf)
{
	return (CWnd*)NotifySys (NRS_GET_AND_CHECK_UNIT_PTR, pInf->m_unit.m_dwFormID,
			pInf->m_unit.m_dwUnitID);
}

BOOL MyCreateFont (CFont& font, LOGFONT* pLogFont)
{
	LOGFONT lgfont;
	::CopyMemory ((LPBYTE)&lgfont, (LPBYTE)pLogFont, sizeof (LOGFONT));

	lgfont.lfCharSet = DEFAULT_CHARSET;
	lgfont.lfOutPrecision = OUT_DEFAULT_PRECIS;
	lgfont.lfClipPrecision = CLIP_DEFAULT_PRECIS;
	lgfont.lfQuality = PROOF_QUALITY;
	lgfont.lfPitchAndFamily = DEFAULT_PITCH;

	return font.CreateFontIndirect (&lgfont);
}

void ModiUnitStyle (CWnd* pUnit, DWORD dwAddStyle, DWORD dwRemoveStyle)
{
	DWORD dwOldStyle = GetWindowLong (pUnit->m_hWnd, GWL_STYLE);
	DWORD dwNewStyle = (dwOldStyle & ~dwRemoveStyle) | dwAddStyle;
	if (dwNewStyle != dwOldStyle)
		SetWindowLong (pUnit->m_hWnd, GWL_STYLE, dwNewStyle);
}

void SetUnitStyle (CWnd* pUnit, BOOL blSet, DWORD dwStyle)
{
	ModiUnitStyle (pUnit, (blSet ? dwStyle : 0), (blSet ? 0 : dwStyle));
}

void SerializeCString (CString& str, CArchive& ar)
{
	INT nSize;
	if (ar.IsStoring() == TRUE)
	{
		nSize = str.GetLength () * sizeof (TCHAR);
		ar << nSize;
		if (nSize > 0)
			ar.Write ((LPTSTR)(LPCTSTR)str, nSize);
	}
	else
	{
		str.Empty ();

		ar >> nSize;
		ASSERT (nSize >= 0);
		if (nSize > 0)
		{
			LPTSTR p = str.GetBuffer (nSize);
			ar.Read (p, nSize);
			str.ReleaseBuffer();
		}
	}
}

void SetStr (CString& str, LPTSTR szText)
{
	if (szText != NULL)
		str = szText;
	else
		str.Empty ();
}

