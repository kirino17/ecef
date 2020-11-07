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
	return ToAnsi(((CefCookie*)_rawptr)->path.str, ((CefCookie*)_rawptr)->path.length);
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
void ProxyCookie::SetCreation(double creation) {
	ASSERTN();
	if (!creation) {
		return;
	}
	CefTime time;
	time.AttachTo(((CefCookie*)_rawptr)->creation);
	time.SetDoubleT(creation);
}

double ProxyCookie::GetCreation() {
	ASSERTQ(NULL);
	CefTime time;
	time.AttachTo(((CefCookie*)_rawptr)->creation);
	return time.GetDoubleT();
}

///
// The cookie last access date. This is automatically populated by the system
// on access.
///
void ProxyCookie::SetLastAccess(double last_access) {
	ASSERTN();
	if (!last_access) {
		return;
	}
	CefTime time;
	time.AttachTo(((CefCookie*)_rawptr)->last_access);

}

double ProxyCookie::GetLastAccess() {
	ASSERTQ(NULL);
	CefTime time;
	time.AttachTo(((CefCookie*)_rawptr)->last_access);
	return time.GetDoubleT();
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

void ProxyCookie::SetExpires(double expires) {
	ASSERTN();
	if (!expires) {
		return;
	}
	CefTime time;
	time.AttachTo(((CefCookie*)_rawptr)->expires);
	time.SetDoubleT(expires);
}

double ProxyCookie::GetExpires() {
	ASSERTQ(NULL);
	CefTime time;
	time.AttachTo(((CefCookie*)_rawptr)->expires);
	return time.GetDoubleT();
}