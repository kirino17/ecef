#pragma once
#include "../def/def.h"

class AQUADLL ProxyRequestContextSettings : public refcounted {
public:
    ProxyRequestContextSettings(void* ptr);
    ~ProxyRequestContextSettings();

public:
    static shrewd_ptr<ProxyRequestContextSettings> Create();

public:
    // is valid
    bool IsValid();

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
  void SetCachePath(const char* cache_path);

  ///
  // To persist session cookies (cookies without an expiry date or validity
  // interval) by default when using the global cookie manager set this value to
  // true (1). Session cookies are generally intended to be transient and most
  // Web browsers do not persist them. Can be set globally using the
  // CefSettings.persist_session_cookies value. This value will be ignored if
  // |cache_path| is empty or if it matches the CefSettings.cache_path value.
  ///
  void SetPersistSessionCookies(int persist_session_cookies);

  ///
  // To persist user preferences as a JSON file in the cache path directory set
  // this value to true (1). Can be set globally using the
  // CefSettings.persist_user_preferences value. This value will be ignored if
  // |cache_path| is empty or if it matches the CefSettings.cache_path value.
  ///
  void SetPersistUserPreferences(int persist_user_preferences);

  ///
  // Set to true (1) to ignore errors related to invalid SSL certificates.
  // Enabling this setting can lead to potential security vulnerabilities like
  // "man in the middle" attacks. Applications that load content from the
  // internet should not enable this setting. Can be set globally using the
  // CefSettings.ignore_certificate_errors value. This value will be ignored if
  // |cache_path| matches the CefSettings.cache_path value.
  ///
  void SetIgnoreCertificateErrors(int ignore_certificate_errors);

  ///
  // Comma delimited ordered list of language codes without any whitespace that
  // will be used in the "Accept-Language" HTTP header. Can be set globally
  // using the CefSettings.accept_language_list value or overridden on a per-
  // browser basis using the CefBrowserSettings.accept_language_list value. If
  // all values are empty then "en-US,en" will be used. This value will be
  // ignored if |cache_path| matches the CefSettings.cache_path value.
  ///
  void SetAcceptLanguageList(const char* accept_language_list);


public:
    PRIME_IMPLEMENT_REFCOUNTING(ProxyRequestContextSettings);
    AQUA_DECL_PUBLIC_ORIGIN;

private:
    void* _rawptr;
};