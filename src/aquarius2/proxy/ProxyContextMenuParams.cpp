#include "ProxyContextMenuParams.h"
#include "include/cef_context_menu_handler.h"
#include "../def/internalDef.h"

AQUA_PROXY_AUTO_CONSTRUCTOR(ProxyContextMenuParams,CefContextMenuParams);

///
// Returns the X coordinate of the mouse where the context menu was invoked.
// Coords are relative to the associated RenderView's origin.
///
/*--cef()--*/
int ProxyContextMenuParams::GetXCoord(){
	ASSERTQ(0);
	return FORWARD(CefContextMenuParams)->GetXCoord();
}

///
// Returns the Y coordinate of the mouse where the context menu was invoked.
// Coords are relative to the associated RenderView's origin.
///
/*--cef()--*/
int ProxyContextMenuParams::GetYCoord(){
	ASSERTQ(0);
	return FORWARD(CefContextMenuParams)->GetYCoord();
}

///
// Returns flags representing the type of node that the context menu was
// invoked on.
///
/*--cef(default_retval=CM_TYPEFLAG_NONE)--*/
int ProxyContextMenuParams::GetTypeFlags(){
	ASSERTQ(0);
	return FORWARD(CefContextMenuParams)->GetTypeFlags();
}

///
// Returns the URL of the link, if any, that encloses the node that the
// context menu was invoked on.
///
/*--cef()--*/
char* ProxyContextMenuParams::GetLinkUrl(){
	ASSERTQ(NULL);
	assert(NewBuffer);
	CefString string = FORWARD(CefContextMenuParams)->GetLinkUrl();
	return ToAnsi(string.c_str(),string.length());
}

///
// Returns the link URL, if any, to be used ONLY for "copy link address". We
// don't validate this field in the frontend process.
///
/*--cef()--*/
char* ProxyContextMenuParams::GetUnfilteredLinkUrl(){
	ASSERTQ(NULL);
	assert(NewBuffer);
	CefString string = FORWARD(CefContextMenuParams)->GetUnfilteredLinkUrl();
	return ToAnsi(string.c_str(), string.length());
}

///
// Returns the source URL, if any, for the element that the context menu was
// invoked on. Example of elements with source URLs are img, audio, and video.
///
/*--cef()--*/
char* ProxyContextMenuParams::GetSourceUrl(){
	ASSERTQ(NULL);
	assert(NewBuffer);
	CefString string = FORWARD(CefContextMenuParams)->GetSourceUrl();
	return ToAnsi(string.c_str(), string.length());
}

///
// Returns true if the context menu was invoked on an image which has
// non-empty contents.
///
/*--cef()--*/
bool ProxyContextMenuParams::HasImageContents(){
	ASSERTQ(false);
	return FORWARD(CefContextMenuParams)->HasImageContents();
}

///
// Returns the title text or the alt text if the context menu was invoked on
// an image.
///
/*--cef()--*/
char* ProxyContextMenuParams::GetTitleText(){
	ASSERTQ(NULL);
	assert(NewBuffer);
	CefString string = FORWARD(CefContextMenuParams)->GetTitleText();
	if (string.empty()) {
		return NULL;
	}
	return ToAnsi(string.c_str(), string.length());
}

///
// Returns the URL of the top level page that the context menu was invoked on.
///
/*--cef()--*/
char* ProxyContextMenuParams::GetPageUrl(){
	ASSERTQ(NULL);
	assert(NewBuffer);
	CefString string = FORWARD(CefContextMenuParams)->GetPageUrl();
	if (string.empty()) {
		return NULL;
	}
	return ToAnsi(string.c_str(), string.length());
}

///
// Returns the URL of the subframe that the context menu was invoked on.
///
/*--cef()--*/
char* ProxyContextMenuParams::GetFrameUrl(){
	ASSERTQ(NULL);
	assert(NewBuffer);
	CefString string = FORWARD(CefContextMenuParams)->GetFrameUrl();
	if (string.empty()) {
		return NULL;
	}
	return ToAnsi(string.c_str(), string.length());
}

///
// Returns the character encoding of the subframe that the context menu was
// invoked on.
///
/*--cef()--*/
char* ProxyContextMenuParams::GetFrameCharset(){
	ASSERTQ(NULL);
	assert(NewBuffer);
	CefString string = FORWARD(CefContextMenuParams)->GetFrameCharset();
	if (string.empty()) {
		return NULL;
	}
	return ToAnsi(string.c_str(), string.length());
}

///
// Returns the type of context node that the context menu was invoked on.
///
/*--cef(default_retval=CM_MEDIATYPE_NONE)--*/
int ProxyContextMenuParams::GetMediaType(){
	ASSERTQ(false);
	return FORWARD(CefContextMenuParams)->GetMediaType();
}

///
// Returns flags representing the actions supported by the media element, if
// any, that the context menu was invoked on.
///
/*--cef(default_retval=CM_MEDIAFLAG_NONE)--*/
int ProxyContextMenuParams::GetMediaStateFlags(){
	ASSERTQ(false);
	return FORWARD(CefContextMenuParams)->GetMediaStateFlags();
}

///
// Returns the text of the selection, if any, that the context menu was
// invoked on.
///
/*--cef()--*/
char* ProxyContextMenuParams::GetSelectionText(){
	ASSERTQ(NULL);
	assert(NewBuffer);
	CefString string = FORWARD(CefContextMenuParams)->GetSelectionText();
	if (string.empty()) {
		return NULL;
	}
	return ToAnsi(string.c_str(), string.length());
}

///
// Returns the text of the misspelled word, if any, that the context menu was
// invoked on.
///
/*--cef()--*/
char* ProxyContextMenuParams::GetMisspelledWord(){
	ASSERTQ(NULL);
	assert(NewBuffer);
	CefString string = FORWARD(CefContextMenuParams)->GetMisspelledWord();
	if (string.empty()) {
		return NULL;
	}
	return ToAnsi(string.c_str(), string.length());
}

///
// Returns true if suggestions exist, false otherwise. Fills in |suggestions|
// from the spell check service for the misspelled word if there is one.
///
/*--cef()--*/
char** ProxyContextMenuParams::GetDictionarySuggestions(){
	ASSERTQ(NULL);
	std::vector<CefString> strings;
	FORWARD(CefContextMenuParams)->GetDictionarySuggestions(strings);
	return CreateEPLStringArray(strings);
}

///
// Returns true if the context menu was invoked on an editable node.
///
/*--cef()--*/
bool ProxyContextMenuParams::IsEditable(){
	ASSERTQ(false);
	return FORWARD(CefContextMenuParams)->IsEditable();
}

///
// Returns true if the context menu was invoked on an editable node where
// spell-check is enabled.
///
/*--cef()--*/
bool ProxyContextMenuParams::IsSpellCheckEnabled(){
	ASSERTQ(false);
	return FORWARD(CefContextMenuParams)->IsSpellCheckEnabled();
}

///
// Returns flags representing the actions supported by the editable node, if
// any, that the context menu was invoked on.
///
/*--cef(default_retval=CM_EDITFLAG_NONE)--*/
int ProxyContextMenuParams::GetEditStateFlags(){
	ASSERTQ(0);
	return FORWARD(CefContextMenuParams)->GetEditStateFlags();
}

///
// Returns true if the context menu contains items specified by the renderer
// process (for example, plugin placeholder or pepper plugin menu items).
///
/*--cef()--*/
bool ProxyContextMenuParams::IsCustomMenu(){
	ASSERTQ(false);
	return FORWARD(CefContextMenuParams)->IsCustomMenu();
}

///
// Returns true if the context menu was invoked from a pepper plugin.
///
/*--cef()--*/
bool ProxyContextMenuParams::IsPepperMenu(){
	ASSERTQ(false);
	return FORWARD(CefContextMenuParams)->IsPepperMenu();
}
