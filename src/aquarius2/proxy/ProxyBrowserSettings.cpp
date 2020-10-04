#include "ProxyBrowserSettings.h"
#include "include/cef_browser.h"
#include <atlconv.h>

ProxyBrowserSettings::ProxyBrowserSettings(void* ptr):_rawptr(ptr) {

}

ProxyBrowserSettings::~ProxyBrowserSettings() {
	if (_rawptr) {
		delete (CefBrowserSettings*)_rawptr;
		_rawptr = nullptr;
	}
}

shrewd_ptr<ProxyBrowserSettings> ProxyBrowserSettings::Create() {
	return new ProxyBrowserSettings( new CefBrowserSettings );
}

bool ProxyBrowserSettings::IsValid() {
	return _rawptr != nullptr;
}

void ProxyBrowserSettings::SetStandardFontFamily(const char* standard_font_family) {
	if (!_rawptr) return;
	if (standard_font_family) {
		USES_CONVERSION;
		CefString(&((CefBrowserSettings*)_rawptr)->standard_font_family) = A2W(standard_font_family);
	}
}
void ProxyBrowserSettings::SetFixedFontFamily(const char* fixed_font_family) {
	if (!_rawptr) return;
	if (fixed_font_family) {
		USES_CONVERSION;
		CefString(&((CefBrowserSettings*)_rawptr)->fixed_font_family) = A2W(fixed_font_family);
	}
}
void ProxyBrowserSettings::SetSerifFontFamily(const char* serif_font_family) {
	if (!_rawptr) return;
	if (serif_font_family) {
		USES_CONVERSION;
		CefString(&((CefBrowserSettings*)_rawptr)->serif_font_family) = A2W(serif_font_family);
	}
}
void ProxyBrowserSettings::SetSansSerifFontFamily(const char* sans_serif_font_family) {
	if (!_rawptr) return;
	if (sans_serif_font_family) {
		USES_CONVERSION;
		CefString(&((CefBrowserSettings*)_rawptr)->sans_serif_font_family) = A2W(sans_serif_font_family);
	}
}
void ProxyBrowserSettings::SetCursiveFontFamily(const char* cursive_font_family) {
	if (!_rawptr) return;
	if (cursive_font_family) {
		USES_CONVERSION;
		CefString(&((CefBrowserSettings*)_rawptr)->cursive_font_family) = A2W(cursive_font_family);
	}
}
void ProxyBrowserSettings::SetFantasyFontFamily(const char* fantasy_font_family) {
	if (!_rawptr) return;
	if (fantasy_font_family) {
		USES_CONVERSION;
		CefString(&((CefBrowserSettings*)_rawptr)->fantasy_font_family) = A2W(fantasy_font_family);
	}
}

void ProxyBrowserSettings::SetWindowlessFrameRate(int windowless_frame_rate) {
	if(!_rawptr) return; ((CefBrowserSettings*)_rawptr)->windowless_frame_rate = windowless_frame_rate;
}
///
 // Default encoding for Web content. If empty "ISO-8859-1" will be used. Also
 // configurable using the "default-encoding" command-line switch.
 ///
void ProxyBrowserSettings::SetDefaultEncoding(const char* default_encoding) {
	if (!_rawptr) return;
	if (default_encoding) {
		USES_CONVERSION;
		CefString(&((CefBrowserSettings*)_rawptr)->default_encoding) = A2W(default_encoding);
	}
}
void ProxyBrowserSettings::SetDefaultFontSize(int default_font_size) {
	if(!_rawptr) return; ((CefBrowserSettings*)_rawptr)->default_font_size = default_font_size;
}

void ProxyBrowserSettings::SetDefaultFixedFontSize(int default_fixed_font_size) {
	if(!_rawptr) return; ((CefBrowserSettings*)_rawptr)->default_fixed_font_size = default_fixed_font_size;
}

void ProxyBrowserSettings::SetMinimumFontSize(int minimum_font_size) {
	if(!_rawptr) return; ((CefBrowserSettings*)_rawptr)->minimum_font_size = minimum_font_size;
}

void ProxyBrowserSettings::SetMinimumLogicalFontSize(int minimum_logical_font_size) {
	if(!_rawptr) return; ((CefBrowserSettings*)_rawptr)->minimum_logical_font_size = minimum_logical_font_size;
}

void ProxyBrowserSettings::SetRemoteFonts(int remote_fonts) {
	if(!_rawptr) return; ((CefBrowserSettings*)_rawptr)->remote_fonts = (cef_state_t)remote_fonts;
}

void ProxyBrowserSettings::SetJavascript(int javascript) {
	if(!_rawptr) return; ((CefBrowserSettings*)_rawptr)->javascript = (cef_state_t)javascript;
}

void ProxyBrowserSettings::SetJavascriptCloseWindows(int javascript_close_windows) {
	if(!_rawptr) return; ((CefBrowserSettings*)_rawptr)->javascript_close_windows = (cef_state_t)javascript_close_windows;
}

void ProxyBrowserSettings::SetJavascriptAccessClipboard(int javascript_access_clipboard) {
	if(!_rawptr) return; ((CefBrowserSettings*)_rawptr)->javascript_access_clipboard = (cef_state_t)javascript_access_clipboard;
}

void ProxyBrowserSettings::SetJavascriptDomPaste(int javascript_dom_paste) {
	if(!_rawptr) return; ((CefBrowserSettings*)_rawptr)->javascript_dom_paste = (cef_state_t)javascript_dom_paste;
}

void ProxyBrowserSettings::SetPlugins(int plugins) {
	if(!_rawptr) return; ((CefBrowserSettings*)_rawptr)->plugins = (cef_state_t)plugins;
}

void ProxyBrowserSettings::SetUniversalAccessFromFileUrls(int universal_access_from_file_urls) {
	if(!_rawptr) return; ((CefBrowserSettings*)_rawptr)->universal_access_from_file_urls = (cef_state_t)universal_access_from_file_urls;
}

void ProxyBrowserSettings::SetFileAccessFromFileUrls(int file_access_from_file_urls) {
	if(!_rawptr) return; ((CefBrowserSettings*)_rawptr)->file_access_from_file_urls = (cef_state_t)file_access_from_file_urls;
}

void ProxyBrowserSettings::SetWebSecurity(int web_security) {
	if(!_rawptr) return; ((CefBrowserSettings*)_rawptr)->web_security = (cef_state_t)web_security;
}

void ProxyBrowserSettings::SetImageLoading(int image_loading) {
	if(!_rawptr) return; ((CefBrowserSettings*)_rawptr)->image_loading = (cef_state_t)image_loading;
}

void ProxyBrowserSettings::SetImageShrinkStandaloneToFit(int image_shrink_standalone_to_fit) {
	if(!_rawptr) return; ((CefBrowserSettings*)_rawptr)->image_shrink_standalone_to_fit = (cef_state_t)image_shrink_standalone_to_fit;
}

void ProxyBrowserSettings::SetTextAreaResize(int text_area_resize) {
	if(!_rawptr) return; ((CefBrowserSettings*)_rawptr)->text_area_resize = (cef_state_t)text_area_resize;
}

void ProxyBrowserSettings::SetTabToLinks(int tab_to_links) {
	if(!_rawptr) return; ((CefBrowserSettings*)_rawptr)->tab_to_links = (cef_state_t)tab_to_links;
}

void ProxyBrowserSettings::SetLocalStorage(int local_storage) {
	if(!_rawptr) return; ((CefBrowserSettings*)_rawptr)->local_storage = (cef_state_t)local_storage;
}

void ProxyBrowserSettings::SetDatabases(int databases) {
	if(!_rawptr) return; ((CefBrowserSettings*)_rawptr)->databases = (cef_state_t)databases;
}

void ProxyBrowserSettings::SetApplicationCache(int application_cache) {
	if(!_rawptr) return; ((CefBrowserSettings*)_rawptr)->application_cache = (cef_state_t)application_cache;
}

void ProxyBrowserSettings::SetWebGL(int webgl) {
	if(!_rawptr) return; ((CefBrowserSettings*)_rawptr)->webgl = (cef_state_t)webgl;
}

void ProxyBrowserSettings::SetBackgroundColor(int background_color) {
	if(!_rawptr) return; ((CefBrowserSettings*)_rawptr)->background_color = (cef_color_t)background_color;
}

///
// Comma delimited ordered list of language codes without any whitespace that
// will be used in the "Accept-Language" HTTP header. May be set globally
// using the CefBrowserSettings.accept_language_list value. If both values are
// empty then "en-US,en" will be used.
///
void ProxyBrowserSettings::SetAcceptLanguageList(const char* accept_language_list) {
	if (!_rawptr) return;
	if (accept_language_list) {
		USES_CONVERSION;
		CefString(&((CefBrowserSettings*)_rawptr)->accept_language_list) = A2W(accept_language_list);
	}
}