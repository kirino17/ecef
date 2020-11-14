#pragma once
#include "include/cef_cookie.h"
#include "include/cef_waitable_event.h"
#include <sstream>

class InternalCookieStoreVisitor : public CefCookieVisitor {
public:
	InternalCookieStoreVisitor(CefRefPtr<CefWaitableEvent> waitable, int mode = 0);
	~InternalCookieStoreVisitor();

public:
	virtual bool Visit(const CefCookie& cookie,
		int count,
		int total,
		bool& deleteCookie) OVERRIDE;

public:
	char* GetString(void);

public:
	IMPLEMENT_REFCOUNTING(InternalCookieStoreVisitor);

private:
	CefRefPtr<CefWaitableEvent> _waitable;
	std::wstringstream _sstr;
	int _fetchMode;
};