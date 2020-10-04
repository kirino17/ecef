#pragma once
#include "../def/def.h"


class AQUADLL ProxyBrowserSettings : public refcounted {
public:
    ProxyBrowserSettings(void* ptr);
    ~ProxyBrowserSettings();

public:
    static shrewd_ptr<ProxyBrowserSettings> Create();

public:
    // is valid
    bool IsValid();


  ///
  // The maximum rate in frames per second (fps) that CefRenderHandler::OnPaint
  // will be called for a windowless browser. The actual fps may be lower if
  // the browser cannot generate frames at the requested rate. The minimum
  // value is 1 and the maximum value is 60 (default 30). This value can also be
  // changed dynamically via CefBrowserHost::SetWindowlessFrameRate.
  ///
  void SetWindowlessFrameRate(int windowless_frame_rate);

  // The below values map to WebPreferences settings.

  ///
  // Font settings.
  ///
  void SetStandardFontFamily(const char* standard_font_family);
  /*--cef()--*/
  void SetFixedFontFamily(const char* fixed_font_family);
  /*--cef()--*/
  void SetSerifFontFamily(const char* serif_font_family);
  /*--cef()--*/
  void SetSansSerifFontFamily(const char* sans_serif_font_family);
  /*--cef()--*/
  void SetCursiveFontFamily(const char* cursive_font_family);
  /*--cef()--*/
  void SetFantasyFontFamily(const char* fantasy_font_family);
  /*--cef()--*/
  void SetDefaultFontSize(int default_font_size);
  /*--cef()--*/
  void SetDefaultFixedFontSize(int default_fixed_font_size);
  /*--cef()--*/
  void SetMinimumFontSize(int minimum_font_size);
  /*--cef()--*/
  void SetMinimumLogicalFontSize(int minimum_logical_font_size);

  ///
  // Default encoding for Web content. If empty "ISO-8859-1" will be used. Also
  // configurable using the "default-encoding" command-line switch.
  ///
  void SetDefaultEncoding(const char* default_encoding);

  ///
  // Controls the loading of fonts from remote sources. Also configurable using
  // the "disable-remote-fonts" command-line switch.
  ///
  void SetRemoteFonts(int remote_fonts);

  ///
  // Controls whether JavaScript can be executed. Also configurable using the
  // "disable-javascript" command-line switch.
  ///
  void SetJavascript(int javascript);

  ///
  // Controls whether JavaScript can be used to close windows that were not
  // opened via JavaScript. JavaScript can still be used to close windows that
  // were opened via JavaScript or that have no back/forward history. Also
  // configurable using the "disable-javascript-close-windows" command-line
  // switch.
  ///
  void SetJavascriptCloseWindows(int javascript_close_windows);

  ///
  // Controls whether JavaScript can access the clipboard. Also configurable
  // using the "disable-javascript-access-clipboard" command-line switch.
  ///
  void SetJavascriptAccessClipboard(int javascript_access_clipboard);

  ///
  // Controls whether DOM pasting is supported in the editor via
  // execCommand("paste"). The |javascript_access_clipboard| setting must also
  // be enabled. Also configurable using the "disable-javascript-dom-paste"
  // command-line switch.
  ///
  void SetJavascriptDomPaste(int javascript_dom_paste);

  ///
  // Controls whether any plugins will be loaded. Also configurable using the
  // "disable-plugins" command-line switch.
  ///
  void SetPlugins(int plugins);

  ///
  // Controls whether file URLs will have access to all URLs. Also configurable
  // using the "allow-universal-access-from-files" command-line switch.
  ///
  void SetUniversalAccessFromFileUrls(int universal_access_from_file_urls);

  ///
  // Controls whether file URLs will have access to other file URLs. Also
  // configurable using the "allow-access-from-files" command-line switch.
  ///
  void SetFileAccessFromFileUrls(int file_access_from_file_urls);

  ///
  // Controls whether web security restrictions (same-origin policy) will be
  // enforced. Disabling this setting is not recommend as it will allow risky
  // security behavior such as cross-site scripting (XSS). Also configurable
  // using the "disable-web-security" command-line switch.
  ///
  void SetWebSecurity(int web_security);

  ///
  // Controls whether image URLs will be loaded from the network. A cached image
  // will still be rendered if requested. Also configurable using the
  // "disable-image-loading" command-line switch.
  ///
  void SetImageLoading(int image_loading);

  ///
  // Controls whether standalone images will be shrunk to fit the page. Also
  // configurable using the "image-shrink-standalone-to-fit" command-line
  // switch.
  ///
  void SetImageShrinkStandaloneToFit(int image_shrink_standalone_to_fit);

  ///
  // Controls whether text areas can be resized. Also configurable using the
  // "disable-text-area-resize" command-line switch.
  ///
  void SetTextAreaResize(int text_area_resize);

  ///
  // Controls whether the tab key can advance focus to links. Also configurable
  // using the "disable-tab-to-links" command-line switch.
  ///
  void SetTabToLinks(int tab_to_links);

  ///
  // Controls whether local storage can be used. Also configurable using the
  // "disable-local-storage" command-line switch.
  ///
  void SetLocalStorage(int local_storage);

  ///
  // Controls whether databases can be used. Also configurable using the
  // "disable-databases" command-line switch.
  ///
  void SetDatabases(int databases);

  ///
  // Controls whether the application cache can be used. Also configurable using
  // the "disable-application-cache" command-line switch.
  ///
  void SetApplicationCache(int application_cache);

  ///
  // Controls whether WebGL can be used. Note that WebGL requires hardware
  // support and may not work on all systems even when enabled. Also
  // configurable using the "disable-webgl" command-line switch.
  ///
  void SetWebGL(int webgl);

  ///
  // Background color used for the browser before a document is loaded and when
  // no document color is specified. The alpha component must be either fully
  // opaque (0xFF) or fully transparent (0x00). If the alpha component is fully
  // opaque then the RGB components will be used as the background color. If the
  // alpha component is fully transparent for a windowed browser then the
  // CefSettings.background_color value will be used. If the alpha component is
  // fully transparent for a windowless (off-screen) browser then transparent
  // painting will be enabled.
  ///
  void SetBackgroundColor(int background_color);

  ///
  // Comma delimited ordered list of language codes without any whitespace that
  // will be used in the "Accept-Language" HTTP header. May be set globally
  // using the CefBrowserSettings.accept_language_list value. If both values are
  // empty then "en-US,en" will be used.
  ///
  void SetAcceptLanguageList(const char* accept_language_list);


public:
    PRIME_IMPLEMENT_REFCOUNTING(ProxyBrowserSettings);
    AQUA_DECL_PUBLIC_ORIGIN;

private:
    void* _rawptr;
};