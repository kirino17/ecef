#pragma once
#include "../def/def.h"

class AQUADLL ProxyTouchEvent : public refcounted {
public:
    ProxyTouchEvent(void* ptr);
    ~ProxyTouchEvent();

public:
    static shrewd_ptr<ProxyTouchEvent> Create();

public:
    // is valid
    bool IsValid();

  ///
  // Id of a touch point. Must be unique per touch, can be any number except -1.
  // void SetTracked(int tracked); touches
  // beyond that will be ignored.
  ///
  void SetId(int id);

  ///
  // X coordinate relative to the left side of the view.
  ///
  void SetX(int x);

  ///
  // Y coordinate relative to the top side of the view.
  ///
  void SetY(int y);

  ///
  // X radius in pixels. Set to 0 if not applicable.
  ///
  void SetRadiusX(int radius_x);

  ///
  // Y radius in pixels. Set to 0 if not applicable.
  ///
  void SetRadiusY(int radius_y);

  ///
  // Rotation angle in radians. Set to 0 if not applicable.
  ///
  void SetRotationAngle(int rotation_angle);

  ///
  // The normalized pressure of the pointer input in the range of [0,1].
  // Set to 0 if not applicable.
  ///
  void SetPressure(int pressure);

  ///
  // The state of the touch point. Touches begin with one CEF_TET_PRESSED event
  // followed by zero or more CEF_TET_MOVED events and finally one
  // CEF_TET_RELEASED or CEF_TET_CANCELLED event. Events not respecting this
  // order will be ignored.
  ///
  void SetType(int type);



  ///
  // Bit flags describing any pressed modifier keys. See
  // cef_event_flags_t for values.
  ///
  void SetModifiers(int modifiers);

  ///
  // The device type that caused the event.
  ///
  void SetPointerType(int pointer_type);

public:
    PRIME_IMPLEMENT_REFCOUNTING(ProxyTouchEvent);
    AQUA_DECL_PUBLIC_ORIGIN;

private:
    void* _rawptr;
};