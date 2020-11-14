#pragma once
#include "../def/def.h"


class AQUADLL ProxySettings : public refcounted {
public:
	ProxySettings(void* ptr);
	~ProxySettings();

public:
    // is valid
    bool IsValid();

    ///
    // The location where data for the global browser cache will be stored on
    // disk. If non-empty this must be either equal to or a child directory of
    // CefSettings.root_cache_path. If empty then browsers will be created in
    // "incognito mode" where in-memory caches are used for storage and no data is
    // persisted to disk. HTML5 databases such as localStorage will only persist
    // across sessions if a cache path is specified. Can be overridden for
    // individual CefRequestContext instances via the
    // CefRequestContextSettings.cache_path value.
    ///
    void SetCachePath(const char* path);

    ///
    // The location where user data such as spell checking dictionary files will
    // be stored on disk. If empty then the default platform-specific user data
    // directory will be used ("~/.cef_user_data" directory on Linux,
    // "~/Library/Application Support/CEF/User Data" directory on Mac OS X,
    // "Local Settings\Application Data\CEF\User Data" directory under the user
    // profile directory on Windows).
    ///
    void SetUserDataPath(const char* path);

    ///
    // To persist session cookies (cookies without an expiry date or validity
    // interval) by default when using the global cookie manager set this value to
    // true (1). Session cookies are generally intended to be transient and most
    // Web browsers do not persist them. A |cache_path| value must also be
    // specified to enable this feature. Also configurable using the
    // "persist-session-cookies" command-line switch. Can be overridden for
    // individual CefRequestContext instances via the
    // CefRequestContextSettings.persist_session_cookies value.
    ///
    void SetPersistSessionCookies(int value);

    ///
    // To persist user preferences as a JSON file in the cache path directory set
    // this value to true (1). A |cache_path| value must also be specified
    // to enable this feature. Also configurable using the
    // "persist-user-preferences" command-line switch. Can be overridden for
    // individual CefRequestContext instances via the
    // CefRequestContextSettings.persist_user_preferences value.
    ///
    void SetPersistUserPreferences(int value);

    ///
    // Value that will be returned as the User-Agent HTTP header. If empty the
    // default User-Agent string will be used. Also configurable using the
    // "user-agent" command-line switch.
    ///
    void SetUserAgent(const char* user_agent);

    ///
    // Value that will be inserted as the product portion of the default
    // User-Agent string. If empty the Chromium product version will be used. If
    // |userAgent| is specified this value will be ignored. Also configurable
    // using the "product-version" command-line switch.
    ///
    void SetProductVersion(const char* product_version);

    ///
    // The locale string that will be passed to WebKit. If empty the default
    // locale of "en-US" will be used. This value is ignored on Linux where locale
    // is determined using environment variable parsing with the precedence order:
    // LANGUAGE, LC_ALL, LC_MESSAGES and LANG. Also configurable using the "lang"
    // command-line switch.
    ///
    void SetLocale(const char* locale);

    ///
    // Set to true (1) to ignore errors related to invalid SSL certificates.
    // Enabling this setting can lead to potential security vulnerabilities like
    // "man in the middle" attacks. Applications that load content from the
    // internet should not enable this setting. Also configurable using the
    // "ignore-certificate-errors" command-line switch. Can be overridden for
    // individual CefRequestContext instances via the
    // CefRequestContextSettings.ignore_certificate_errors value.
    ///
    void SetIgnoreCertificateErrors(int value);

    ///
    // Comma delimited ordered list of language codes without any whitespace that
    // will be used in the "Accept-Language" HTTP header. May be overridden on a
    // per-browser basis using the CefBrowserSettings.accept_language_list value.
    // If both values are empty then "en-US,en" will be used. Can be overridden
    // for individual CefRequestContext instances via the
    // CefRequestContextSettings.accept_language_list value.
    ///
    void SetAcceptLanguageList(const char* accept_language_list);

public:
	PRIME_IMPLEMENT_REFCOUNTING(ProxySettings);
    AQUA_DECL_PUBLIC_ORIGIN;

public:
    void* _rawptr;
};