#pragma once
#include "../def/def.h"

class AQUADLL ProxyContextMenuParams : public refcounted {
public:
	ProxyContextMenuParams(void* ptr);
	~ProxyContextMenuParams();

public:
    ///
    // Returns the X coordinate of the mouse where the context menu was invoked.
    // Coords are relative to the associated RenderView's origin.
    ///
    /*--cef()--*/
    int GetXCoord();

    ///
    // Returns the Y coordinate of the mouse where the context menu was invoked.
    // Coords are relative to the associated RenderView's origin.
    ///
    /*--cef()--*/
    int GetYCoord();

    ///
    // Returns flags representing the type of node that the context menu was
    // invoked on.
    ///
    /*--cef(default_retval=CM_TYPEFLAG_NONE)--*/
    int GetTypeFlags();

    ///
    // Returns the URL of the link, if any, that encloses the node that the
    // context menu was invoked on.
    ///
    /*--cef()--*/
    char* GetLinkUrl();

    ///
    // Returns the link URL, if any, to be used ONLY for "copy link address". We
    // don't validate this field in the frontend process.
    ///
    /*--cef()--*/
    char* GetUnfilteredLinkUrl();

    ///
    // Returns the source URL, if any, for the element that the context menu was
    // invoked on. Example of elements with source URLs are img, audio, and video.
    ///
    /*--cef()--*/
    char* GetSourceUrl();

    ///
    // Returns true if the context menu was invoked on an image which has
    // non-empty contents.
    ///
    /*--cef()--*/
    bool HasImageContents();

    ///
    // Returns the title text or the alt text if the context menu was invoked on
    // an image.
    ///
    /*--cef()--*/
    char* GetTitleText();

    ///
    // Returns the URL of the top level page that the context menu was invoked on.
    ///
    /*--cef()--*/
    char* GetPageUrl();

    ///
    // Returns the URL of the subframe that the context menu was invoked on.
    ///
    /*--cef()--*/
    char* GetFrameUrl();

    ///
    // Returns the character encoding of the subframe that the context menu was
    // invoked on.
    ///
    /*--cef()--*/
    char* GetFrameCharset();

    ///
    // Returns the type of context node that the context menu was invoked on.
    ///
    /*--cef(default_retval=CM_MEDIATYPE_NONE)--*/
    int GetMediaType();

    ///
    // Returns flags representing the actions supported by the media element, if
    // any, that the context menu was invoked on.
    ///
    /*--cef(default_retval=CM_MEDIAFLAG_NONE)--*/
    int GetMediaStateFlags();

    ///
    // Returns the text of the selection, if any, that the context menu was
    // invoked on.
    ///
    /*--cef()--*/
    char* GetSelectionText();

    ///
    // Returns the text of the misspelled word, if any, that the context menu was
    // invoked on.
    ///
    /*--cef()--*/
    char* GetMisspelledWord();

    ///
    // Returns true if suggestions exist, false otherwise. Fills in |suggestions|
    // from the spell check service for the misspelled word if there is one.
    ///
    /*--cef()--*/
    char** GetDictionarySuggestions();

    ///
    // Returns true if the context menu was invoked on an editable node.
    ///
    /*--cef()--*/
    bool IsEditable();

    ///
    // Returns true if the context menu was invoked on an editable node where
    // spell-check is enabled.
    ///
    /*--cef()--*/
    bool IsSpellCheckEnabled();

    ///
    // Returns flags representing the actions supported by the editable node, if
    // any, that the context menu was invoked on.
    ///
    /*--cef(default_retval=CM_EDITFLAG_NONE)--*/
    int GetEditStateFlags();

    ///
    // Returns true if the context menu contains items specified by the renderer
    // process (for example, plugin placeholder or pepper plugin menu items).
    ///
    /*--cef()--*/
    bool IsCustomMenu();

    ///
    // Returns true if the context menu was invoked from a pepper plugin.
    ///
    /*--cef()--*/
    bool IsPepperMenu();

public:
    PRIME_IMPLEMENT_REFCOUNTING(ProxyContextMenuParams);
    AQUA_DECL_PUBLIC_ORIGIN;

private:
    void* _rawptr;
};