#pragma once
#include "../def/def.h"

class AQUADLL ProxyWindowInfo : public refcounted {
public:
	ProxyWindowInfo(void* ptr);
	~ProxyWindowInfo();

public:
    // is valid
    bool IsValid();

    ///
    // Create the browser as a child window.
    ///
    void SetAsChild(unsigned int parent, int x, int y, int width, int height);

    ///
    // Create the browser as a popup window.
    ///
    void SetAsPopup(unsigned int parent, const char* windowName);

public:
	PRIME_IMPLEMENT_REFCOUNTING(ProxyWindowInfo);
    AQUA_DECL_PUBLIC_ORIGIN;

public:
    void* _rawptr;
};