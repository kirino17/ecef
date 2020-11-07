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

void ProxyBrowserSettings::SetJavascript(int value) {
	if (!_rawptr) return; ((CefBrowserSettings*)_rawptr)->javascript = (cef_state_t)value;
}

void ProxyBrowserSettings::SetJavascriptCloseWindow(int value) {
	if (!_rawptr) return; ((CefBrowserSettings*)_rawptr)->javascript_close_windows = (cef_state_t)value;
}

void ProxyBrowserSettings::SetJavascriptAccessClipboard(int value) {
	if (!_rawptr) return; ((CefBrowserSettings*)_rawptr)->javascript_access_clipboard = (cef_state_t)value;
}

void ProxyBrowserSettings::SetJavascriptDomPaste(int value) {
	if (!_rawptr) return; ((CefBrowserSettings*)_rawptr)->javascript_dom_paste = (cef_state_t)value;
}

void ProxyBrowserSettings::SetPlugins(int value) {
	if (!_rawptr) return; ((CefBrowserSettings*)_rawptr)->plugins = (cef_state_t)value;
}

void ProxyBrowserSettings::SetUniversalAccessFromFileUrls(int value) {
	if (!_rawptr) return; ((CefBrowserSettings*)_rawptr)->universal_access_from_file_urls = (cef_state_t)value;
}

void ProxyBrowserSettings::SetFileAccessFromFileUrls(int value) {
	if (!_rawptr) return; ((CefBrowserSettings*)_rawptr)->file_access_from_file_urls = (cef_state_t)value;
}

void ProxyBrowserSettings::SetWebSecurity(int value) {
	if (!_rawptr) return; ((CefBrowserSettings*)_rawptr)->web_security = (cef_state_t)value;
}
void ProxyBrowserSettings::SetImageLoading(int value) {
	if (!_rawptr) return; ((CefBrowserSettings*)_rawptr)->image_loading = (cef_state_t)value;
}
void ProxyBrowserSettings::SetImageShrinkStandaloneToFit(int value) {
	if (!_rawptr) return; ((CefBrowserSettings*)_rawptr)->image_shrink_standalone_to_fit = (cef_state_t)value;
}
void ProxyBrowserSettings::SetTextAreaResize(int value) {
	if (!_rawptr) return; ((CefBrowserSettings*)_rawptr)->text_area_resize = (cef_state_t)value;
}
void ProxyBrowserSettings::SetTabToLinks(int value) {
	if (!_rawptr) return; ((CefBrowserSettings*)_rawptr)->tab_to_links = (cef_state_t)value;
}
void ProxyBrowserSettings::SetLocalStorage(int value) {
	if (!_rawptr) return; ((CefBrowserSettings*)_rawptr)->local_storage = (cef_state_t)value;
}

void ProxyBrowserSettings::SetDataBase(int value) {
	if (!_rawptr) return; ((CefBrowserSettings*)_rawptr)->databases = (cef_state_t)value;
}

void ProxyBrowserSettings::SetApplicationCache(int value) {
	if (!_rawptr) return; ((CefBrowserSettings*)_rawptr)->application_cache = (cef_state_t)value;
}

void ProxyBrowserSettings::SetWebGL(int value) {
	if (!_rawptr) return; ((CefBrowserSettings*)_rawptr)->webgl = (cef_state_t)value;
}

void ProxyBrowserSettings::SetBackgroundColor(int color) {
	if (!_rawptr) return; ((CefBrowserSettings*)_rawptr)->background_color = (cef_color_t)color;
}

void ProxyBrowserSettings::SetAcceptLanguageList(const char* values) {
	if (!_rawptr || !values) return; 
	USES_CONVERSION;
	CefString(&((CefBrowserSettings*)_rawptr)->accept_language_list) = A2W(values);
}