#pragma once
#include "../def/def.h"

class AQUADLL ProxyMenuModel : public refcounted {
public:
	ProxyMenuModel(void* ptr);
	~ProxyMenuModel();

public:

    ///
    // Returns true if this menu is a submenu.
    ///
    /*--cef()--*/
    bool IsSubMenu();

    ///
    // Clears the menu. Returns true on success.
    ///
    /*--cef()--*/
    bool Clear();

    ///
    // Returns the number of items in this menu.
    ///
    /*--cef()--*/
    int GetCount();

    ///
    // Add a separator to the menu. Returns true on success.
    ///
    /*--cef()--*/
    bool AddSeparator();

    ///
    // Add an item to the menu. Returns true on success.
    ///
    /*--cef()--*/
    bool AddItem(int command_id, const char* label);

    ///
    // Add a check item to the menu. Returns true on success.
    ///
    /*--cef()--*/
    bool AddCheckItem(int command_id, const char* label);
    ///
    // Add a radio item to the menu. Only a single item with the specified
    // |group_id| can be checked at a time. Returns true on success.
    ///
    /*--cef()--*/
    bool AddRadioItem(int command_id,
        const char* label,
        int group_id);

    ///
    // Add a sub-menu to the menu. The new sub-menu is returned.
    ///
    /*--cef()--*/
    shrewd_ptr<ProxyMenuModel> AddSubMenu(int command_id,
        const char* label);

    ///
    // Insert a separator in the menu at the specified |index|. Returns true on
    // success.
    ///
    /*--cef()--*/
    bool InsertSeparatorAt(int index);

    ///
    // Insert an item in the menu at the specified |index|. Returns true on
    // success.
    ///
    /*--cef()--*/
    bool InsertItemAt(int index,
        int command_id,
        const char* label);

    ///
    // Insert a check item in the menu at the specified |index|. Returns true on
    // success.
    ///
    /*--cef()--*/
    bool InsertCheckItemAt(int index,
        int command_id,
        const char* label);

    ///
    // Insert a radio item in the menu at the specified |index|. Only a single
    // item with the specified |group_id| can be checked at a time. Returns true
    // on success.
    ///
    /*--cef()--*/
    bool InsertRadioItemAt(int index,
        int command_id,
        const char* label,
        int group_id);

    ///
    // Insert a sub-menu in the menu at the specified |index|. The new sub-menu
    // is returned.
    ///
    /*--cef()--*/
    shrewd_ptr<ProxyMenuModel> InsertSubMenuAt(int index,
        int command_id,
        const char* label);

    ///
    // Removes the item with the specified |command_id|. Returns true on success.
    ///
    /*--cef()--*/
    bool Remove(int command_id);

    ///
    // Removes the item at the specified |index|. Returns true on success.
    ///
    /*--cef()--*/
    bool RemoveAt(int index);

    ///
    // Returns the index associated with the specified |command_id| or -1 if not
    // found due to the command id not existing in the menu.
    ///
    /*--cef()--*/
    int GetIndexOf(int command_id);

    ///
    // Returns the command id at the specified |index| or -1 if not found due to
    // invalid range or the index being a separator.
    ///
    /*--cef()--*/
    int GetCommandIdAt(int index);

    ///
    // Sets the command id at the specified |index|. Returns true on success.
    ///
    /*--cef()--*/
    bool SetCommandIdAt(int index, int command_id);

    ///
    // Returns the label for the specified |command_id| or empty if not found.
    ///
    /*--cef()--*/
    char* GetLabel(int command_id);

    ///
    // Returns the label at the specified |index| or empty if not found due to
    // invalid range or the index being a separator.
    ///
    /*--cef()--*/
    char* GetLabelAt(int index);

    ///
    // Sets the label for the specified |command_id|. Returns true on success.
    ///
    /*--cef()--*/
    bool SetLabel(int command_id, const char* label);

    ///
    // Set the label at the specified |index|. Returns true on success.
    ///
    /*--cef()--*/
    bool SetLabelAt(int index, const char* label);

    ///
    // Returns the item type for the specified |command_id|.
    ///
    /*--cef(default_retval=MENUITEMTYPE_NONE)--*/
    int GetType(int command_id);

    ///
    // Returns the item type at the specified |index|.
    ///
    /*--cef(default_retval=MENUITEMTYPE_NONE)--*/
    int GetTypeAt(int index);

    ///
    // Returns the group id for the specified |command_id| or -1 if invalid.
    ///
    /*--cef()--*/
    int GetGroupId(int command_id);

    ///
    // Returns the group id at the specified |index| or -1 if invalid.
    ///
    /*--cef()--*/
    int GetGroupIdAt(int index);

    ///
    // Sets the group id for the specified |command_id|. Returns true on success.
    ///
    /*--cef()--*/
    bool SetGroupId(int command_id, int group_id);

    ///
    // Sets the group id at the specified |index|. Returns true on success.
    ///
    /*--cef()--*/
    bool SetGroupIdAt(int index, int group_id);

    ///
    // Returns the submenu for the specified |command_id| or empty if invalid.
    ///
    /*--cef()--*/
    shrewd_ptr<ProxyMenuModel> GetSubMenu(int command_id);

    ///
    // Returns the submenu at the specified |index| or empty if invalid.
    ///
    /*--cef()--*/
    shrewd_ptr<ProxyMenuModel> GetSubMenuAt(int index);

    ///
    // Returns true if the specified |command_id| is visible.
    ///
    /*--cef()--*/
    bool IsVisible(int command_id);

    ///
    // Returns true if the specified |index| is visible.
    ///
    /*--cef()--*/
    bool IsVisibleAt(int index);

    ///
    // Change the visibility of the specified |command_id|. Returns true on
    // success.
    ///
    /*--cef()--*/
    bool SetVisible(int command_id, bool visible);

    ///
    // Change the visibility at the specified |index|. Returns true on success.
    ///
    /*--cef()--*/
    bool SetVisibleAt(int index, bool visible);

    ///
    // Returns true if the specified |command_id| is enabled.
    ///
    /*--cef()--*/
    bool IsEnabled(int command_id);

    ///
    // Returns true if the specified |index| is enabled.
    ///
    /*--cef()--*/
    bool IsEnabledAt(int index);

    ///
    // Change the enabled status of the specified |command_id|. Returns true on
    // success.
    ///
    /*--cef()--*/
    bool SetEnabled(int command_id, bool enabled);

    ///
    // Change the enabled status at the specified |index|. Returns true on
    // success.
    ///
    /*--cef()--*/
    bool SetEnabledAt(int index, bool enabled);

    ///
    // Returns true if the specified |command_id| is checked. Only applies to
    // check and radio items.
    ///
    /*--cef()--*/
    bool IsChecked(int command_id);

    ///
    // Returns true if the specified |index| is checked. Only applies to check
    // and radio items.
    ///
    /*--cef()--*/
    bool IsCheckedAt(int index);

    ///
    // Check the specified |command_id|. Only applies to check and radio items.
    // Returns true on success.
    ///
    /*--cef()--*/
    bool SetChecked(int command_id, bool checked);

    ///
    // Check the specified |index|. Only applies to check and radio items. Returns
    // true on success.
    ///
    /*--cef()--*/
    bool SetCheckedAt(int index, bool checked);

    ///
    // Returns true if the specified |command_id| has a keyboard accelerator
    // assigned.
    ///
    /*--cef()--*/
    bool HasAccelerator(int command_id);

    ///
    // Returns true if the specified |index| has a keyboard accelerator assigned.
    ///
    /*--cef()--*/
    bool HasAcceleratorAt(int index);

    ///
    // Set the keyboard accelerator for the specified |command_id|. |key_code| can
    // be any key or character value. Returns true on success.
    ///
    /*--cef()--*/
    bool SetAccelerator(int command_id,
        int key_code,
        bool shift_pressed,
        bool ctrl_pressed,
        bool alt_pressed);

    ///
    // Set the keyboard accelerator at the specified |index|. |key_code| can be
    // any key or character value. Returns true on success.
    ///
    /*--cef()--*/
    bool SetAcceleratorAt(int index,
        int key_code,
        bool shift_pressed,
        bool ctrl_pressed,
        bool alt_pressed);

    ///
    // Remove the keyboard accelerator for the specified |command_id|. Returns
    // true on success.
    ///
    /*--cef()--*/
    bool RemoveAccelerator(int command_id);

    ///
    // Remove the keyboard accelerator at the specified |index|. Returns true on
    // success.
    ///
    /*--cef()--*/
    bool RemoveAcceleratorAt(int index);

    ///
    // Set the explicit color for |command_id| and |color_type| to |color|.
    // Specify a |color| value of 0 to remove the explicit color. If no explicit
    // color or default color is set for |color_type| then the system color will
    // be used. Returns true on success.
    ///
    /*--cef()--*/
    bool SetColor(int command_id,
        int color_type,
        unsigned int color);

    ///
    // Set the explicit color for |command_id| and |index| to |color|. Specify a
    // |color| value of 0 to remove the explicit color. Specify an |index| value
    // of -1 to set the default color for items that do not have an explicit
    // color set. If no explicit color or default color is set for |color_type|
    // then the system color will be used. Returns true on success.
    ///
    /*--cef()--*/
    bool SetColorAt(int index,
        int color_type,
        unsigned int color);

    ///
    // Sets the font list for the specified |command_id|. If |font_list| is empty
    // the system font will be used. Returns true on success. The format is
    // "<FONT_FAMILY_LIST>,[STYLES] <SIZE>", where:
    // - FONT_FAMILY_LIST is a comma-separated list of font family names,
    // - STYLES is an optional space-separated list of style names (case-sensitive
    //   "Bold" and "Italic" are supported), and
    // - SIZE is an integer font size in pixels with the suffix "px".
    //
    // Here are examples of valid font description strings:
    // - "Arial, Helvetica, Bold Italic 14px"
    // - "Arial, 14px"
    ///
    /*--cef(optional_param=font_list)--*/
    bool SetFontList(int command_id, const char* font_list);

    ///
    // Sets the font list for the specified |index|. Specify an |index| value of
    // -1 to set the default font. If |font_list| is empty the system font will
    // be used. Returns true on success. The format is
    // "<FONT_FAMILY_LIST>,[STYLES] <SIZE>", where:
    // - FONT_FAMILY_LIST is a comma-separated list of font family names,
    // - STYLES is an optional space-separated list of style names (case-sensitive
    //   "Bold" and "Italic" are supported), and
    // - SIZE is an integer font size in pixels with the suffix "px".
    //
    // Here are examples of valid font description strings:
    // - "Arial, Helvetica, Bold Italic 14px"
    // - "Arial, 14px"
    ///
    /*--cef(optional_param=font_list)--*/
    bool SetFontListAt(int index, const char* font_list);

public:
	PRIME_IMPLEMENT_REFCOUNTING(ProxyMenuModel);
	AQUA_DECL_PUBLIC_ORIGIN;

private:
	void* _rawptr;
};