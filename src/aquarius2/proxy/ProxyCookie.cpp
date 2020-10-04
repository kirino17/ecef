#include "ProxyCookie.h"
#include "include/internal/cef_types_wrappers.h"
#include <atlconv.h>

ProxyCookie::ProxyCookie(void* ptr):_rawptr(ptr){
}

ProxyCookie::~ProxyCookie() {
	if (_rawptr) {
		delete (CefCookie*)_rawptr;
		_rawptr = NULL;
	}
}

shrewd_ptr<ProxyCookie> ProxyCookie::Create() {
	return new ProxyCookie(new CefCookie);
}

bool ProxyCookie::IsValid() {
	return _rawptr != nullptr;
}

///
// The cookie name.
///
void ProxyCookie::SetName(const char* name) {
	ASSERTN();
	if (!name) {
		return;
	}
	CefString(&((CefCookie*)_rawptr)->name) = name;
}
char* ProxyCookie::GetName() {
	ASSERTQ(NULL);
	return ToAnsi(((CefCookie*)_rawptr)->name.str, ((CefCookie*)_rawptr)->name.length);
}

///
// The cookie value.
///
void ProxyCookie::SetValue(const char* value) {
	ASSERTN();
	if (!value) {
		return;
	}
	CefString(&((CefCookie*)_rawptr)->value) = value;
}
char* ProxyCookie::GetValue() {
	ASSERTQ(NULL);
	return ToAnsi(((CefCookie*)_rawptr)->value.str, ((CefCookie*)_rawptr)->value.length);
}

///
// If |domain| is empty a host cookie will be created instead of a domain
// cookie. Domain cookies are stored with a leading "." and are visible to
// sub-domains whereas host cookies are not.
///
void ProxyCookie::SetDomain(const char* domain) {
	ASSERTN();
	if (!domain) {
		return;
	}
	CefString(&((CefCookie*)_rawptr)->domain) = domain;
}
char* ProxyCookie::GetDomain() {
	ASSERTQ(NULL);
	return ToAnsi(((CefCookie*)_rawptr)->domain.str, ((CefCookie*)_rawptr)->domain.length);
}

///
// If |path| is non-empty only URLs at or below the path will get the cookie
// value.
///
void ProxyCookie::SetPath(const char* path) {
	ASSERTN();
	if (!path) {
		return;
	}
	CefString(&((CefCookie*)_rawptr)->path) = path;
}
char* ProxyCookie::GetPath() {
	ASSERTQ(NULL);
	return ToAnsi(((CefCookie*)_rawptr)->domain.str, ((CefCookie*)_rawptr)->domain.length);
}

///
// If |secure| is true the cookie will only be sent for HTTPS requests.
///
void ProxyCookie::SetSecure(int secure) {
	ASSERTN();
	((CefCookie*)_rawptr)->secure = secure;
}

int ProxyCookie::GetSecure() {
	ASSERTQ(0);
	return ((CefCookie*)_rawptr)->secure;
}

///
// If |httponly| is true the cookie will only be sent for HTTP requests.
///
void ProxyCookie::SetHttponly(int httponly) {
	ASSERTN();
	((CefCookie*)_rawptr)->httponly = httponly;
}

int ProxyCookie::GetHttponly() {
	ASSERTQ(0);
	return ((CefCookie*)_rawptr)->httponly;
}

///
// The cookie creation date. This is automatically populated by the system on
// cookie creation.
///
void ProxyCookie::SetCreation(shrewd_ptr<ProxyTime> creation) {
	ASSERTN();
	if (!creation) {
		return;
	}
	CefTime(((CefCookie*)_rawptr)->creation) = *(CefTime*)creation->OriginPointer();
}

shrewd_ptr<ProxyTime> ProxyCookie::GetCreation() {
	ASSERTQ(NULL);
	return new ProxyTime(new CefTime(((CefCookie*)_rawptr)->creation));
}

///
// The cookie last access date. This is automatically populated by the system
// on access.
///
void ProxyCookie::SetLastAccess(shrewd_ptr<ProxyTime> last_access) {
	ASSERTN();
	if (!last_access) {
		return;
	}
	CefTime(((CefCookie*)_rawptr)->last_access) = *(CefTime*)last_access->OriginPointer();
}

shrewd_ptr<ProxyTime> ProxyCookie::GetLastAccess() {
	ASSERTQ(NULL);
	return new ProxyTime(new CefTime(((CefCookie*)_rawptr)->last_access));
}

///
// The cookie expiration date is only valid if |has_expires| is true.
///
void ProxyCookie::SetHasExpires(int has_expires) {
	ASSERTN();
	((CefCookie*)_rawptr)->has_expires = has_expires;
}
int ProxyCookie::GetHasExpires() {
	ASSERTQ(NULL);
	return ((CefCookie*)_rawptr)->has_expires;
}

void ProxyCookie::SetExpires(shrewd_ptr<ProxyTime> expires) {
	ASSERTN();
	if (!expires) {
		return;
	}
	CefTime(((CefCookie*)_rawptr)->expires) = *(CefTime*)expires->OriginPointer();
}

shrewd_ptr<ProxyTime> ProxyCookie::GetExpires() {
	ASSERTQ(NULL);
	return new ProxyTime(new CefTime(((CefCookie*)_rawptr)->expires));
}