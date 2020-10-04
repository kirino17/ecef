#pragma once
#include "../def/def.h"

class AQUADLL ProxyMouseEvent : public refcounted {
public:
    ProxyMouseEvent(void* ptr);
    ~ProxyMouseEvent();

public:
    static shrewd_ptr<ProxyMouseEvent> Create();


public:
    // is valid
    bool IsValid();

  ///
  // X coordinate relative to the left side of the view.
  ///
  void SetX(int x);

  ///
  // Y coordinate relative to the top side of the view.
  ///
  void SetY(int y);

  ///
  // Bit flags describing any pressed modifier keys. See
  // cef_event_flags_t for values.
  ///
  void SetModifiers(int modifiers);

public:
    PRIME_IMPLEMENT_REFCOUNTING(ProxyMouseEvent);
    AQUA_DECL_PUBLIC_ORIGIN;

private:
    void* _rawptr;
};