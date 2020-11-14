#ifndef CEF_INCLUDE_CEF_DEVICE_EMULATION_PARAMS_H_
#define CEF_INCLUDE_CEF_DEVICE_EMULATION_PARAMS_H_
#pragma once

#include "include/cef_base.h"

///
// All sizes are measured in device independent pixels.
///
/*--cef(source=library)--*/
class CefDeviceEmulationParams : public virtual CefBaseRefCounted {
public:
  ///
  // create the renderer process.
  ///
  /*--cef()--*/
  static CefRefPtr<CefDeviceEmulationParams> Create();

  ///
  // set the screen type.
  ///
  /*--cef()--*/
  virtual void SetScreenType(int type) = 0;

  ///
  // Emulated screen size. Typically full / physical size of the device screen
  // in DIP. Empty size means using default value: original one for kDesktop
  // screen position, equal to |view_size| for kMobile.
  ///
  /*--cef()--*/
  virtual void SetScreenSize(int width, int height) = 0;

  ///
  // Position of view on the screen. Missing position means using default value:
  // original one for kDesktop screen position, (0, 0) for kMobile.
  ///
  /*--cef()--*/
  virtual void SetViewPosition(int x, int y) = 0;

  ///
  // Emulated view size. A width or height of 0 means no override in that
  // dimension, but the other can still be applied. When both are 0, then the
  // |scale| will be applied to the view instead.
  ///
  /*--cef()--*/
  virtual void SetViewSize(int width, int height) = 0;

  ///
  // If zero, the original device scale factor is preserved.
  ///
  /*--cef()--*/
  virtual void SetDeviceScaleFactor(float value) = 0;

  ///
  // Scale the contents of the main frame. The view's size will be scaled by
  // this number when they are not specified in |view_size|.
  ///
  /*--cef()--*/
  virtual void SetScale(float value) = 0;

  ///
  // Forced viewport offset for screenshots during emulation, (-1, -1) for
  // disabled.
  ///
  /*--cef()--*/
  virtual void SetViewportOffset(float x, float y) = 0;

  ///
  // Viewport scale for screenshots during emulation, 0 for current.
  ///
  /*--cef()--*/
  virtual void SetViewportScale(float value) = 0;

  ///
  // Optional screen orientation type, with mojom::ScreenOrientation::kUndefined
  // value meaning no emulation necessary.
  ///
  /*--cef()--*/
  virtual void SetScreenOrientationType(int type) = 0;

  ///
  // Screen orientation angle, used together with screenOrientationType.
  ///
  /*--cef()--*/
  virtual void SetScreenOrientationAngle(int angle) = 0;

};

#endif