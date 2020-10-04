#include "ProxyMenuModel.h"
#include "include/cef_menu_model.h"
#include <atlconv.h>

AQUA_PROXY_AUTO_CONSTRUCTOR(ProxyMenuModel,CefMenuModel);


///
 // Create a new MenuModel with the specified |delegate|.
 ///
 /*--cef()--*/
shrewd_ptr<ProxyMenuModel> ProxyMenuModel::CreateMenuModel(){
    return new ProxyMenuModel(CefMenuModel::CreateMenuModel(nullptr));
}

///
// Returns true if this menu is a submenu.
///
/*--cef()--*/
bool ProxyMenuModel::IsSubMenu(){
    ASSERTQ(false);
    return FORWARD(CefMenuModel)->IsSubMenu();
}

///
// Clears the menu. Returns true on success.
///
/*--cef()--*/
bool ProxyMenuModel::Clear(){
    ASSERTQ(false);
    return FORWARD(CefMenuModel)->Clear();
}

///
// Returns the number of items in this menu.
///
/*--cef()--*/
int ProxyMenuModel::GetCount(){
    ASSERTQ(0);
    return FORWARD(CefMenuModel)->GetCount();
}

///
// Add a separator to the menu. Returns true on success.
///
/*--cef()--*/
bool ProxyMenuModel::AddSeparator(){
    ASSERTQ(false);
    return FORWARD(CefMenuModel)->AddSeparator();
}

///
// Add an item to the menu. Returns true on success.
///
/*--cef()--*/
bool ProxyMenuModel::AddItem(int command_id, const char* label){
    ASSERTQ(false);
    CefString string;
    USES_CONVERSION;
    if (label) {
        string = A2W(label);
    }
    return FORWARD(CefMenuModel)->AddItem(command_id, string);
}

///
// Add a check item to the menu. Returns true on success.
///
/*--cef()--*/
bool ProxyMenuModel::AddCheckItem(int command_id, const char* label){
    ASSERTQ(false);
    CefString string;
    USES_CONVERSION;
    if (label) {
        string = A2W(label);
    }
    return FORWARD(CefMenuModel)->AddCheckItem(command_id, string);
}
///
// Add a radio item to the menu. Only a single item with the specified
// |group_id| can be checked at a time. Returns true on success.
///
/*--cef()--*/
bool ProxyMenuModel::AddRadioItem(int command_id,
    const char* label,
    int group_id){
    ASSERTQ(false);
    CefString string;
    USES_CONVERSION;
    if (label) {
        string = A2W(label);
    }
    return FORWARD(CefMenuModel)->AddRadioItem(command_id, string, group_id);
}

///
// Add a sub-menu to the menu. The new sub-menu is returned.
///
/*--cef()--*/
shrewd_ptr<ProxyMenuModel> ProxyMenuModel::AddSubMenu(int command_id,
    const char* label){
    ASSERTQ(NULL);
    CefString string;
    USES_CONVERSION;
    if (label) {
        string = A2W(label);
    }
    return new ProxyMenuModel(FORWARD(CefMenuModel)->AddSubMenu(command_id, string));
}

///
// Insert a separator in the menu at the specified |index|. Returns true on
// success.
///
/*--cef()--*/
bool ProxyMenuModel::InsertSeparatorAt(int index){
    ASSERTQ(false);
    return FORWARD(CefMenuModel)->InsertSeparatorAt(index);
}

///
// Insert an item in the menu at the specified |index|. Returns true on
// success.
///
/*--cef()--*/
bool ProxyMenuModel::InsertItemAt(int index,
    int command_id,
    const char* label){
    ASSERTQ(false);
    CefString string;
    USES_CONVERSION;
    if (label) {
        string = A2W(label);
    }
    return FORWARD(CefMenuModel)->InsertItemAt(index, command_id, string);
}

///
// Insert a check item in the menu at the specified |index|. Returns true on
// success.
///
/*--cef()--*/
bool ProxyMenuModel::InsertCheckItemAt(int index,
    int command_id,
    const char* label){
    ASSERTQ(false);
    CefString string;
    USES_CONVERSION;
    if (label) {
        string = A2W(label);
    }
    return FORWARD(CefMenuModel)->InsertCheckItemAt(index, command_id, string);
}

///
// Insert a radio item in the menu at the specified |index|. Only a single
// item with the specified |group_id| can be checked at a time. Returns true
// on success.
///
/*--cef()--*/
bool ProxyMenuModel::InsertRadioItemAt(int index,
    int command_id,
    const char* label,
    int group_id){
    ASSERTQ(false);
    CefString string;
    USES_CONVERSION;
    if (label) {
        string = A2W(label);
    }
    return FORWARD(CefMenuModel)->InsertRadioItemAt(index, command_id, string, group_id);
}

///
// Insert a sub-menu in the menu at the specified |index|. The new sub-menu
// is returned.
///
/*--cef()--*/
shrewd_ptr<ProxyMenuModel> ProxyMenuModel::InsertSubMenuAt(int index,
    int command_id,
    const char* label){
    ASSERTQ(NULL);
    CefString string;
    USES_CONVERSION;
    if (label) {
        string = A2W(label);
    }
    return new ProxyMenuModel(FORWARD(CefMenuModel)->InsertSubMenuAt(index, command_id, string));
}

///
// Removes the item with the specified |command_id|. Returns true on success.
///
/*--cef()--*/
bool ProxyMenuModel::Remove(int command_id){
    ASSERTQ(false);
    return FORWARD(CefMenuModel)->Remove(command_id);
}

///
// Removes the item at the specified |index|. Returns true on success.
///
/*--cef()--*/
bool ProxyMenuModel::RemoveAt(int index){
    ASSERTQ(false);
    return FORWARD(CefMenuModel)->RemoveAt(index);
}

///
// Returns the index associated with the specified |command_id| or -1 if not
// found due to the command id not existing in the menu.
///
/*--cef()--*/
int ProxyMenuModel::GetIndexOf(int command_id){
    ASSERTQ(-1);
    return FORWARD(CefMenuModel)->GetIndexOf(command_id);
}

///
// Returns the command id at the specified |index| or -1 if not found due to
// invalid range or the index being a separator.
///
/*--cef()--*/
int ProxyMenuModel::GetCommandIdAt(int index){
    ASSERTQ(-1);
    return FORWARD(CefMenuModel)->GetCommandIdAt(index);
}

///
// Sets the command id at the specified |index|. Returns true on success.
///
/*--cef()--*/
bool ProxyMenuModel::SetCommandIdAt(int index, int command_id){
    ASSERTQ(false);
    return FORWARD(CefMenuModel)->SetCommandIdAt(index,command_id);
}

///
// Returns the label for the specified |command_id| or empty if not found.
///
/*--cef()--*/
char* ProxyMenuModel::GetLabel(int command_id){
    ASSERTQ(NULL);
    CefString string = FORWARD(CefMenuModel)->GetLabel(command_id);
    if (string.empty()) {
        return NULL;
    }
    return ToAnsi(string.c_str(),string.length());
}

///
// Returns the label at the specified |index| or empty if not found due to
// invalid range or the index being a separator.
///
/*--cef()--*/
char* ProxyMenuModel::GetLabelAt(int index){
    ASSERTQ(NULL);
    CefString string = FORWARD(CefMenuModel)->GetLabelAt(index);
    if (string.empty()) {
        return NULL;
    }
    return ToAnsi(string.c_str(), string.length());
}

///
// Sets the label for the specified |command_id|. Returns true on success.
///
/*--cef()--*/
bool ProxyMenuModel::SetLabel(int command_id, const char* label){
    ASSERTQ(false);
    USES_CONVERSION;
    CefString string;
    if (label) {
        string = A2W(label);
    }
    return FORWARD(CefMenuModel)->SetLabel(command_id, string);
}

///
// Set the label at the specified |index|. Returns true on success.
///
/*--cef()--*/
bool ProxyMenuModel::SetLabelAt(int index, const char* label){
    ASSERTQ(false);
    USES_CONVERSION;
    CefString string;
    if (label) {
        string = A2W(label);
    }
    return FORWARD(CefMenuModel)->SetLabel(index, string);
}

///
// Returns the item type for the specified |command_id|.
///
/*--cef(default_retval=MENUITEMTYPE_NONE)--*/
int ProxyMenuModel::GetType(int command_id){
    ASSERTQ(0);
    return FORWARD(CefMenuModel)->GetType(command_id);
}

///
// Returns the item type at the specified |index|.
///
/*--cef(default_retval=MENUITEMTYPE_NONE)--*/
int ProxyMenuModel::GetTypeAt(int index){
    ASSERTQ(0);
    return FORWARD(CefMenuModel)->GetType(index);
}

///
// Returns the group id for the specified |command_id| or -1 if invalid.
///
/*--cef()--*/
int ProxyMenuModel::GetGroupId(int command_id){
    ASSERTQ(-1);
    return FORWARD(CefMenuModel)->GetGroupId(command_id);
}

///
// Returns the group id at the specified |index| or -1 if invalid.
///
/*--cef()--*/
int ProxyMenuModel::GetGroupIdAt(int index){
    ASSERTQ(-1);
    return FORWARD(CefMenuModel)->GetGroupIdAt(index);
}

///
// Sets the group id for the specified |command_id|. Returns true on success.
///
/*--cef()--*/
bool ProxyMenuModel::SetGroupId(int command_id, int group_id){
    ASSERTQ(false);
    return FORWARD(CefMenuModel)->SetGroupId(command_id, group_id);
}

///
// Sets the group id at the specified |index|. Returns true on success.
///
/*--cef()--*/
bool ProxyMenuModel::SetGroupIdAt(int index, int group_id){
    ASSERTQ(false);
    return FORWARD(CefMenuModel)->SetGroupIdAt(index, group_id);
}

///
// Returns the submenu for the specified |command_id| or empty if invalid.
///
/*--cef()--*/
shrewd_ptr<ProxyMenuModel> ProxyMenuModel::GetSubMenu(int command_id){
    ASSERTQ(NULL);
    return new ProxyMenuModel(FORWARD(CefMenuModel)->GetSubMenu(command_id));
}

///
// Returns the submenu at the specified |index| or empty if invalid.
///
/*--cef()--*/
shrewd_ptr<ProxyMenuModel> ProxyMenuModel::GetSubMenuAt(int index){
    ASSERTQ(NULL);
    return new ProxyMenuModel(FORWARD(CefMenuModel)->GetSubMenuAt(index));
}

///
// Returns true if the specified |command_id| is visible.
///
/*--cef()--*/
bool ProxyMenuModel::IsVisible(int command_id){
    ASSERTQ(false);
    return FORWARD(CefMenuModel)->IsVisible(command_id);
}

///
// Returns true if the specified |index| is visible.
///
/*--cef()--*/
bool ProxyMenuModel::IsVisibleAt(int index){
    ASSERTQ(false);
    return FORWARD(CefMenuModel)->IsVisibleAt(index);
}

///
// Change the visibility of the specified |command_id|. Returns true on
// success.
///
/*--cef()--*/
bool ProxyMenuModel::SetVisible(int command_id, bool visible){
    ASSERTQ(false);
    return FORWARD(CefMenuModel)->SetVisible(command_id,visible);
}

///
// Change the visibility at the specified |index|. Returns true on success.
///
/*--cef()--*/
bool ProxyMenuModel::SetVisibleAt(int index, bool visible){
    ASSERTQ(false);
    return FORWARD(CefMenuModel)->SetVisibleAt(index,visible);
}

///
// Returns true if the specified |command_id| is enabled.
///
/*--cef()--*/
bool ProxyMenuModel::IsEnabled(int command_id){
    ASSERTQ(false);
    return FORWARD(CefMenuModel)->IsEnabled(command_id);
}

///
// Returns true if the specified |index| is enabled.
///
/*--cef()--*/
bool ProxyMenuModel::IsEnabledAt(int index){
    ASSERTQ(false);
    return FORWARD(CefMenuModel)->IsEnabledAt(index);
}

///
// Change the enabled status of the specified |command_id|. Returns true on
// success.
///
/*--cef()--*/
bool ProxyMenuModel::SetEnabled(int command_id, bool enabled){
    ASSERTQ(false);
    return FORWARD(CefMenuModel)->SetEnabled(command_id, enabled);
}

///
// Change the enabled status at the specified |index|. Returns true on
// success.
///
/*--cef()--*/
bool ProxyMenuModel::SetEnabledAt(int index, bool enabled){
    ASSERTQ(false);
    return FORWARD(CefMenuModel)->SetEnabledAt(index,enabled);
}

///
// Returns true if the specified |command_id| is checked. Only applies to
// check and radio items.
///
/*--cef()--*/
bool ProxyMenuModel::IsChecked(int command_id){
    ASSERTQ(false);
    return FORWARD(CefMenuModel)->IsChecked(command_id);
}

///
// Returns true if the specified |index| is checked. Only applies to check
// and radio items.
///
/*--cef()--*/
bool ProxyMenuModel::IsCheckedAt(int index){
    ASSERTQ(false);
    return FORWARD(CefMenuModel)->IsCheckedAt(index);
}

///
// Check the specified |command_id|. Only applies to check and radio items.
// Returns true on success.
///
/*--cef()--*/
bool ProxyMenuModel::SetChecked(int command_id, bool checked){
    ASSERTQ(false);
    return FORWARD(CefMenuModel)->SetChecked(command_id, checked);
}

///
// Check the specified |index|. Only applies to check and radio items. Returns
// true on success.
///
/*--cef()--*/
bool ProxyMenuModel::SetCheckedAt(int index, bool checked){
    ASSERTQ(false);
    return FORWARD(CefMenuModel)->SetCheckedAt(index, checked);
}

///
// Returns true if the specified |command_id| has a keyboard accelerator
// assigned.
///
/*--cef()--*/
bool ProxyMenuModel::HasAccelerator(int command_id){
    ASSERTQ(false);
    return FORWARD(CefMenuModel)->HasAccelerator(command_id);
}

///
// Returns true if the specified |index| has a keyboard accelerator assigned.
///
/*--cef()--*/
bool ProxyMenuModel::HasAcceleratorAt(int index){
    ASSERTQ(false);
    return FORWARD(CefMenuModel)->HasAcceleratorAt(index);
}

///
// Set the keyboard accelerator for the specified |command_id|. |key_code| can
// be any key or character value. Returns true on success.
///
/*--cef()--*/
bool ProxyMenuModel::SetAccelerator(int command_id,
    int key_code,
    bool shift_pressed,
    bool ctrl_pressed,
    bool alt_pressed){
    ASSERTQ(false);
    return FORWARD(CefMenuModel)->SetAccelerator(command_id, key_code, shift_pressed, ctrl_pressed, alt_pressed);
}

///
// Set the keyboard accelerator at the specified |index|. |key_code| can be
// any key or character value. Returns true on success.
///
/*--cef()--*/
bool ProxyMenuModel::SetAcceleratorAt(int index,
    int key_code,
    bool shift_pressed,
    bool ctrl_pressed,
    bool alt_pressed){
    ASSERTQ(false);
    return FORWARD(CefMenuModel)->SetAcceleratorAt(index, key_code, shift_pressed,ctrl_pressed,alt_pressed);
}

///
// Remove the keyboard accelerator for the specified |command_id|. Returns
// true on success.
///
/*--cef()--*/
bool ProxyMenuModel::RemoveAccelerator(int command_id){
    ASSERTQ(false);
    return FORWARD(CefMenuModel)->RemoveAccelerator(command_id);
}

///
// Remove the keyboard accelerator at the specified |index|. Returns true on
// success.
///
/*--cef()--*/
bool ProxyMenuModel::RemoveAcceleratorAt(int index){
    ASSERTQ(false);
    return FORWARD(CefMenuModel)->RemoveAcceleratorAt(index);
}

///
// Set the explicit color for |command_id| and |color_type| to |color|.
// Specify a |color| value of 0 to remove the explicit color. If no explicit
// color or default color is set for |color_type| then the system color will
// be used. Returns true on success.
///
/*--cef()--*/
bool ProxyMenuModel::SetColor(int command_id,
    int color_type,
    unsigned int color){
    ASSERTQ(false);
    return FORWARD(CefMenuModel)->SetColor(command_id, (cef_menu_color_type_t)color_type, color);
}

///
// Set the explicit color for |command_id| and |index| to |color|. Specify a
// |color| value of 0 to remove the explicit color. Specify an |index| value
// of -1 to set the default color for items that do not have an explicit
// color set. If no explicit color or default color is set for |color_type|
// then the system color will be used. Returns true on success.
///
/*--cef()--*/
bool ProxyMenuModel::SetColorAt(int index,
    int color_type,
    unsigned int color){
    ASSERTQ(false);
    return FORWARD(CefMenuModel)->SetColorAt(index,(cef_menu_color_type_t)color_type, color);
}

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
bool ProxyMenuModel::SetFontList(int command_id, const char* font_list){
    ASSERTQ(false);
    CefString string;
    USES_CONVERSION;
    if (font_list) {
        string = A2W(font_list);
    }
    return FORWARD(CefMenuModel)->SetFontList(command_id, string);
}

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
bool ProxyMenuModel::SetFontListAt(int index, const char* font_list){
    ASSERTQ(false);
    CefString string;
    USES_CONVERSION;
    if (font_list) {
        string = A2W(font_list);
    }
    return FORWARD(CefMenuModel)->SetFontList(index, string);
}
