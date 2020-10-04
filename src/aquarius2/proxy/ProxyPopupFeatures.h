#include "../def/def.h"

class AQUADLL ProxyPopupFeatures : public refcounted {
public:
    ProxyPopupFeatures(void* ptr);
    ~ProxyPopupFeatures();

public:
    static shrewd_ptr<ProxyPopupFeatures> Create();

public:
    // is valid
    bool IsValid();

    /*--cef()--*/
    int GetX();
    /*--cef()--*/
    int GetXSet();
    /*--cef()--*/
    int GetY();
    /*--cef()--*/
    int GetYSet();
    /*--cef()--*/
    int GetWidth();
    /*--cef()--*/
    int GetWidthSet();
    /*--cef()--*/
    int GetHeight();
    /*--cef()--*/
    int GetHeightSet();

    /*--cef()--*/
    int GetMenuBarVisible();
    /*--cef()--*/
    int GetStatusBarVisible();
    /*--cef()--*/
    int GetToolBarVisible();
    /*--cef()--*/
    int GetScrollbarsVisible();

public:
    PRIME_IMPLEMENT_REFCOUNTING(ProxyPopupFeatures);
    AQUA_DECL_PUBLIC_ORIGIN;

private:
    void* _rawptr;
};