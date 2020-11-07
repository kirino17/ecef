#pragma once
#include "include/cef_cookie.h"
#include <string>
#include "include/cef_waitable_event.h"
#include <vector>
#include "../proxy/ProxyCookie.h"

//»ñÈ¡cookie
#define COOKIE_VISIT_MODE_FETCH		(0)

//É¾³ýcookie
#define COOKIE_VISIT_MODE_DELETE	(1)

class InternalCookieVisitor : public CefCookieVisitor {
public:
	InternalCookieVisitor(int mode, CefRefPtr<CefWaitableEvent> waitable);
	~InternalCookieVisitor();

public:
	virtual bool Visit(const CefCookie& cookie,
		int count,
		int total,
		bool& deleteCookie) OVERRIDE;

public:
	shrewd_ptr<ProxyCookie>** GetCookieArray(void);

public:
	IMPLEMENT_REFCOUNTING(InternalCookieVisitor);

private:
	int _visitMode;
	CefRefPtr<CefWaitableEvent> _waitable;
	std::vector<CefCookie> _cookieArray;
};