#pragma once
#include "../def/def.h"


class AQUADLL ProxySettings : public refcounted {
public:
	ProxySettings(void* ptr);
	~ProxySettings();

public:
    static shrewd_ptr<ProxySettings> Create();

public:
    // is valid
    bool IsValid();

    ///
    // The path to a separate executable that will be launched for sub-processes.
    // If this value is empty on Windows or Linux then the main process executable
    // will be used. If this value is empty on macOS then a helper executable must
    // exist at "Contents/Frameworks/<app> Helper.app/Contents/MacOS/<app> Helper"
    // in the top-level app bundle. See the comments on CefExecuteProcess() for
    // details. Also configurable using the "browser-subprocess-path" command-line
    // switch.
    ///
    void SetBrowserSubProcessPath(const char* path);

    ///
    // Set to true (1) to have the browser process message loop run in a separate
    // thread. If false (0) than the CefDoMessageLoopWork() function must be
    // called from your application message loop. This option is only supported on
    // Windows and Linux.
    ///
    void SetMultiThreadedMessageLoop(int value);

    ///
    // Set to true (1) to control browser process main (UI) thread message pump
    // scheduling via the CefBrowserProcessHandler::OnScheduleMessagePumpWork()
    // callback. This option is recommended for use in combination with the
    // CefDoMessageLoopWork() function in cases where the CEF message loop must be
    // integrated into an existing application message loop (see additional
    // comments and warnings on CefDoMessageLoopWork). Enabling this option is not
    // recommended for most users; leave this option disabled and use either the
    // CefRunMessageLoop() function or multi_threaded_message_loop if possible.
    ///
    void SetExternalMessagePump(int value);

    ///
    // Set to true (1) to enable windowless (off-screen) rendering support. Do not
    // enable this value if the application does not use windowless rendering as
    // it may reduce rendering performance on some systems.
    ///
    void SetWindowlessRenderingEnabled(int value);

    ///
    // Set to true (1) to disable configuration of browser process features using
    // standard CEF and Chromium command-line arguments. Configuration can still
    // be specified using CEF data structures or via the
    // CefApp::OnBeforeCommandLineProcessing() method.
    ///
    void SetCommandLineArgsDisabled(int value);

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
    // The root directory that all CefSettings.cache_path and
    // CefRequestContextSettings.cache_path values must have in common. If this
    // value is empty and CefSettings.cache_path is non-empty then this value will
    // default to the CefSettings.cache_path value. Failure to set this value
    // correctly may result in the sandbox blocking read/write access to the
    // cache_path directory.
    ///
    void SetRootCachePath(const char* path);

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
    // Custom flags that will be used when initializing the V8 JavaScript engine.
    // The consequences of using custom flags may not be well tested. Also
    // configurable using the "js-flags" command-line switch.
    ///
    void SetJavascriptFlags(const char* javascript_flags);

    ///
    // Set to true (1) to disable loading of pack files for resources and locales.
    // A resource bundle handler must be provided for the browser and render
    // processes via CefApp::GetResourceBundleHandler() if loading of pack files
    // is disabled. Also configurable using the "disable-pack-loading" command-
    // line switch.
    ///
    void SetPackLoadingDisabled(int value);

    ///
    // Set to a value between 1024 and 65535 to enable remote debugging on the
    // specified port. For example, if 8080 is specified the remote debugging URL
    // will be http://localhost:8080. CEF can be remotely debugged from any CEF or
    // Chrome browser window. Also configurable using the "remote-debugging-port"
    // command-line switch.
    ///
    void SetRemoteDebuggingPort(int value);

    ///
    // The number of stack trace frames to capture for uncaught exceptions.
    // Specify a positive value to enable the CefRenderProcessHandler::
    // OnUncaughtException() callback. Specify 0 (default value) and
    // OnUncaughtException() will not be called. Also configurable using the
    // "uncaught-exception-stack-size" command-line switch.
    ///
    void SetUncaughtExceptionStackSize(int value);

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
    // Background color used for the browser before a document is loaded and when
    // no document color is specified. The alpha component must be either fully
    // opaque (0xFF) or fully transparent (0x00). If the alpha component is fully
    // opaque then the RGB components will be used as the background color. If the
    // alpha component is fully transparent for a windowed browser then the
    // default value of opaque white be used. If the alpha component is fully
    // transparent for a windowless (off-screen) browser then transparent painting
    // will be enabled.
    ///
    void SetBackgroundColor(unsigned int color);

    ///
    // Comma delimited ordered list of language codes without any whitespace that
    // will be used in the "Accept-Language" HTTP header. May be overridden on a
    // per-browser basis using the CefBrowserSettings.accept_language_list value.
    // If both values are empty then "en-US,en" will be used. Can be overridden
    // for individual CefRequestContext instances via the
    // CefRequestContextSettings.accept_language_list value.
    ///
    void SetAcceptLanguageList(const char* accept_language_list);

    ///
    // GUID string used for identifying the application. This is passed to the
    // system AV function for scanning downloaded files. By default, the GUID
    // will be an empty string and the file will be treated as an untrusted
    // file when the GUID is empty.
    ///
    void SetApplicationClientIdForFileScanning(const char* value);

public:
	PRIME_IMPLEMENT_REFCOUNTING(ProxySettings);
    AQUA_DECL_PUBLIC_ORIGIN;

public:
    void* _rawptr;
};