#pragma once
#include "include/cef_cookie.h"
#include <string>

class InternalCookieVisitor : public CefCookieVisitor {
public:
	InternalCookieVisitor(bool is_delete = false);
	~InternalCookieVisitor();

public:
	virtual bool Visit(const CefCookie& cookie,
		int count,
		int total,
		bool& deleteCookie) OVERRIDE;

public:
	IMPLEMENT_REFCOUNTING(InternalCookieVisitor);

private:
	bool _isDelete;
};