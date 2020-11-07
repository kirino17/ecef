// Copyright (c) 2020 The Chromium Embedded Framework Authors. All rights
// reserved. Use of this source code is governed by a BSD-style license that
// can be found in the LICENSE file.
//
// ---------------------------------------------------------------------------
//
// This file was generated by the CEF translator tool. If making changes by
// hand only do so within the body of existing method and function
// implementations. See the translator.README.txt file in the tools directory
// for more information.
//
// $hash=46b9c5f03daba032a504af228f12fe1c8891243a$
//

#ifndef CEF_LIBCEF_DLL_CTOCPP_FRAME_CTOCPP_H_
#define CEF_LIBCEF_DLL_CTOCPP_FRAME_CTOCPP_H_
#pragma once

#if !defined(WRAPPING_CEF_SHARED)
#error This file can be included wrapper-side only
#endif

#include "include/capi/cef_browser_capi.h"
#include "include/capi/cef_frame_capi.h"
#include "include/capi/cef_urlrequest_capi.h"
#include "include/capi/cef_v8_capi.h"
#include "include/cef_browser.h"
#include "include/cef_frame.h"
#include "include/cef_urlrequest.h"
#include "include/cef_v8.h"
#include "libcef_dll/ctocpp/ctocpp_ref_counted.h"

// Wrap a C structure with a C++ class.
// This class may be instantiated and accessed wrapper-side only.
class CefFrameCToCpp
    : public CefCToCppRefCounted<CefFrameCToCpp, CefFrame, cef_frame_t> {
 public:
  CefFrameCToCpp();
  virtual ~CefFrameCToCpp();

  // CefFrame methods.
  bool IsValid() OVERRIDE;
  void Undo() OVERRIDE;
  void Redo() OVERRIDE;
  void Cut() OVERRIDE;
  void Copy() OVERRIDE;
  void Paste() OVERRIDE;
  void Delete() OVERRIDE;
  void SelectAll() OVERRIDE;
  void ViewSource() OVERRIDE;
  void GetSource(CefRefPtr<CefStringVisitor> visitor) OVERRIDE;
  void GetText(CefRefPtr<CefStringVisitor> visitor) OVERRIDE;
  void LoadRequest(CefRefPtr<CefRequest> request) OVERRIDE;
  void LoadURL(const CefString& url) OVERRIDE;
  void ExecuteJavaScript(const CefString& code,
                         const CefString& script_url,
                         int start_line) OVERRIDE;
  bool IsMain() OVERRIDE;
  bool IsFocused() OVERRIDE;
  CefString GetName() OVERRIDE;
  int64 GetIdentifier() OVERRIDE;
  CefRefPtr<CefFrame> GetParent() OVERRIDE;
  CefString GetURL() OVERRIDE;
  CefRefPtr<CefBrowser> GetBrowser() OVERRIDE;
  CefRefPtr<CefV8Context> GetV8Context() OVERRIDE;
  void VisitDOM(CefRefPtr<CefDOMVisitor> visitor) OVERRIDE;
  CefRefPtr<CefURLRequest> CreateURLRequest(
      CefRefPtr<CefRequest> request,
      CefRefPtr<CefURLRequestClient> client) OVERRIDE;
  void SendProcessMessage(CefProcessId target_process,
                          CefRefPtr<CefProcessMessage> message) OVERRIDE;
  void SynthesizePinchGesture(float x,
                              float y,
                              float scale_factor,
                              float relative_speed,
                              int gesture_source_type) OVERRIDE;
  void SynthesizeScrollGesture(float x,
                               float y,
                               float x_distance,
                               float y_distance,
                               float x_overscroll,
                               float y_overscroll,
                               float scale_factor,
                               bool prevent_fling,
                               int speed,
                               int gesture_source_type) OVERRIDE;
  void SynthesizeTapGesture(float x,
                            float y,
                            float scale_factor,
                            int duration,
                            int tap_count,
                            int gesture_source_type) OVERRIDE;
  void SynthesizeDragGesture(float x_start_position,
                             float y_start_position,
                             float x_distance,
                             float y_distance,
                             float scale_factor,
                             int speed,
                             int gesture_source_type) OVERRIDE;
  void SetEmitTouchEventsForMouse(bool enabled, int configuration) OVERRIDE;
};

#endif  // CEF_LIBCEF_DLL_CTOCPP_FRAME_CTOCPP_H_