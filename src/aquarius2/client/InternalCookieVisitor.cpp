#include "InternalCookieVisitor.h"
#include "InternalClient.h"

InternalCookieVisitor::InternalCookieVisitor(int mode, CefRefPtr<CefWaitableEvent> waitable):
	_visitMode(mode),
	_waitable(waitable)
{

}

InternalCookieVisitor::~InternalCookieVisitor() {
	_cookieArray.clear();
	_waitable = nullptr;
}

bool InternalCookieVisitor::Visit(const CefCookie& cookie,
	int count,
	int total,
	bool& deleteCookie) {
	wchar_t buffer[MAX_PATH];

	if (_visitMode == COOKIE_VISIT_MODE_FETCH) {
		
		if (CefString(&cookie.domain) != L"www.internal.aquarius2") {
			_cookieArray.push_back(cookie);
		}

		if ((count+1) >= total) {
			if (_waitable) {
				_waitable->Signal();
			}
		}
	}
	else if (_visitMode == COOKIE_VISIT_MODE_DELETE) {
		deleteCookie = true;
	}
	return true;
}

shrewd_ptr<ProxyCookie>** InternalCookieVisitor::GetCookieArray(void) {
	if (_cookieArray.empty()) {
		DWORD* pointer = (DWORD*)NewBuffer(2 * sizeof(DWORD));
		*(pointer + 0) = 1;
		*(pointer + 1) = 0;
		return (shrewd_ptr<ProxyCookie>**)pointer;
	}

	DWORD* pointer = (DWORD*)NewBuffer((2 + _cookieArray.size()) * sizeof(DWORD));
	*(pointer + 0) = 1;
	*(pointer + 1) = _cookieArray.size();

	shrewd_ptr<ProxyCookie> cookie = nullptr;

	for (size_t i = 0; i < _cookieArray.size(); i++){
		cookie = new ProxyCookie(new CefCookie(_cookieArray[i]));
		DWORD* item = (DWORD*)NewBuffer(sizeof(DWORD));
		cookie->retain();
		*item = (DWORD)(cookie.get());
		*(pointer +i+ 2) = (DWORD)item;
	}

	return (shrewd_ptr<ProxyCookie>**)pointer;
}