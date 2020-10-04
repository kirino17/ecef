#include "ProxyRequestContextSettings.h"
#include "include/cef_request_context.h"
#include <atlconv.h>

ProxyRequestContextSettings::ProxyRequestContextSettings(void* ptr):_rawptr(ptr) {

}

ProxyRequestContextSettings::~ProxyRequestContextSettings() {
	if (_rawptr) {
		delete (CefRequestContextSettings*)_rawptr;
		_rawptr = nullptr;
	}
}

shrewd_ptr<ProxyRequestContextSettings> ProxyRequestContextSettings::Create() {
	return new ProxyRequestContextSettings( new CefRequestContextSettings );
}

bool ProxyRequestContextSettings::IsValid() {
	return _rawptr != nullptr;
}

///
// The location where cache data for this request context will be stored on
// disk. If non-empty this must be either equal to or a child directory of
// CefSettings.root_cache_path. If empty then browsers will be created in
// "incognito mode" where in-memory caches are used for storage and no data is
// persisted to disk. HTML5 databases such as localStorage will only persist
// across sessions if a cache path is specified. To share the global browser
// cache and related configuration set this value to match the
// CefSettings.cache_path value.
///
void ProxyRequestContextSettings::SetCachePath(const char* cache_path) {
	if (!_rawptr) return;
	if (cache_path) {
		USES_CONVERSION;
		CefString(&((CefRequestContextSettings*)_rawptr)->cache_path) = A2W(cache_path);
	}
}

void ProxyRequestContextSettings::SetPersistSessionCookies(int persist_session_cookies) {
	if(!_rawptr) return; ((CefRequestContextSettings*)_rawptr)->persist_session_cookies = persist_session_cookies;
}

void ProxyRequestContextSettings::SetPersistUserPreferences(int persist_user_preferences) {
	if(!_rawptr) return; ((CefRequestContextSettings*)_rawptr)->persist_user_preferences = persist_user_preferences;
}

void ProxyRequestContextSettings::SetIgnoreCertificateErrors(int ignore_certificate_errors) {
	if(!_rawptr) return; ((CefRequestContextSettings*)_rawptr)->ignore_certificate_errors = ignore_certificate_errors;
}

///
// Comma delimited ordered list of language codes without any whitespace that
// will be used in the "Accept-Language" HTTP header. Can be set globally
// using the CefSettings.accept_language_list value or overridden on a per-
// browser basis using the CefBrowserSettings.accept_language_list value. If
// all values are empty then "en-US,en" will be used. This value will be
// ignored if |cache_path| matches the CefSettings.cache_path value.
///
void ProxyRequestContextSettings::SetAcceptLanguageList(const char* accept_language_list) {
	if (!_rawptr) return;
	if (accept_language_list) {
		USES_CONVERSION;
		CefString(&((CefRequestContextSettings*)_rawptr)->accept_language_list) = A2W(accept_language_list);
	}
}