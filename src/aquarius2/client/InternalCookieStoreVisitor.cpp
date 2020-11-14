#include "InternalCookieStoreVisitor.h"
#include "../def/def.h"
#include "include/capi/cef_parser_capi.h"

InternalCookieStoreVisitor::InternalCookieStoreVisitor(CefRefPtr<CefWaitableEvent> waitable,
	int mode):
	_waitable(waitable),
	_fetchMode(mode)
{
	
}

InternalCookieStoreVisitor::~InternalCookieStoreVisitor() {
	if(_waitable) _waitable->Signal();
	_waitable = nullptr;
}

bool InternalCookieStoreVisitor::Visit(const CefCookie& cookie,
	int count,
	int total,
	bool& deleteCookie) {

	if ((count + 1) >= total) {
		_waitable->Signal();
	}

	if (CefString(&cookie.domain) == L"www.internal.aquarius2") {
		deleteCookie = true;
		return true;
	}

	if (!cookie.name.str || cookie.name.length <= 0) {
		return true;
	}

	if (_fetchMode == 0) {
		_sstr << L"Set-Cookie:";
		if (cookie.name.length > 0 && cookie.value.length > 0) {
			_sstr << cookie.name.str << L"=" << cookie.value.str << ";";
		}
		if (cookie.domain.length > 0) {
			_sstr << L"Domain=" << cookie.domain.str << ";";
		}
		if (cookie.path.str && cookie.path.length > 0) {
			_sstr << L"Path=" << cookie.path.str << ";";
		}
		if (cookie.secure) {
			_sstr << L"Secure;";
		}
		if (cookie.httponly) {
			_sstr << L"HttpOnly;";
		}
		if (cookie.has_expires) {
			_sstr << L"Expires=" << CefTime(cookie.expires).GetTimeT() << ";";
		}
		_sstr << L"\r\n";
	}
	else {
		_sstr << cookie.name.str << L"=" << cookie.value.str << ";";
	}

	return true;
}

char* InternalCookieStoreVisitor::GetString(void) {
	const auto& s = _sstr.str();
	char* outStr = nullptr;
	if (s.empty()) {
		return outStr;
	}
	return ToAnsi(s.c_str(), s.length());
}