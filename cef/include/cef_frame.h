// Copyright (c) 2012 Marshall A. Greenblatt. All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are
// met:
//
//    * Redistributions of source code must retain the above copyright
// notice, this list of conditions and the following disclaimer.
//    * Redistributions in binary form must reproduce the above
// copyright notice, this list of conditions and the following disclaimer
// in the documentation and/or other materials provided with the
// distribution.
//    * Neither the name of Google Inc. nor the name Chromium Embedded
// Framework nor the names of its contributors may be used to endorse
// or promote products derived from this software without specific prior
// written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
// ---------------------------------------------------------------------------
//
// The contents of this file must follow a specific format in order to
// support the CEF translator tool. See the translator.README.txt file in the
// tools directory for more information.
//

#ifndef CEF_INCLUDE_CEF_FRAME_H_
#define CEF_INCLUDE_CEF_FRAME_H_
#pragma once

#include "include/cef_base.h"
#include "include/cef_dom.h"
#include "include/cef_process_message.h"
#include "include/cef_request.h"
#include "include/cef_stream.h"
#include "include/cef_string_visitor.h"

class CefBrowser;
class CefURLRequest;
class CefURLRequestClient;
class CefV8Context;

///
// Class used to represent a frame in the browser window. When used in the
// browser process the methods of this class may be called on any thread unless
// otherwise indicated in the comments. When used in the render process the
// methods of this class may only be called on the main thread.
///
/*--cef(source=library)--*/
class CefFrame : public virtual CefBaseRefCounted {
 public:
  ///
  // True if this object is currently attached to a valid frame.
  ///
  /*--cef()--*/
  virtual bool IsValid() = 0;

  ///
  // Execute undo in this frame.
  ///
  /*--cef()--*/
  virtual void Undo() = 0;

  ///
  // Execute redo in this frame.
  ///
  /*--cef()--*/
  virtual void Redo() = 0;

  ///
  // Execute cut in this frame.
  ///
  /*--cef()--*/
  virtual void Cut() = 0;

  ///
  // Execute copy in this frame.
  ///
  /*--cef()--*/
  virtual void Copy() = 0;

  ///
  // Execute paste in this frame.
  ///
  /*--cef()--*/
  virtual void Paste() = 0;

  ///
  // Execute delete in this frame.
  ///
  /*--cef(capi_name=del)--*/
  virtual void Delete() = 0;

  ///
  // Execute select all in this frame.
  ///
  /*--cef()--*/
  virtual void SelectAll() = 0;

  ///
  // Save this frame's HTML source to a temporary file and open it in the
  // default text viewing application. This method can only be called from the
  // browser process.
  ///
  /*--cef()--*/
  virtual void ViewSource() = 0;

  ///
  // Retrieve this frame's HTML source as a string sent to the specified
  // visitor.
  ///
  /*--cef()--*/
  virtual void GetSource(CefRefPtr<CefStringVisitor> visitor) = 0;

  ///
  // Retrieve this frame's display text as a string sent to the specified
  // visitor.
  ///
  /*--cef()--*/
  virtual void GetText(CefRefPtr<CefStringVisitor> visitor) = 0;

  ///
  // Load the request represented by the |request| object.
  //
  // WARNING: This method will fail with "bad IPC message" reason
  // INVALID_INITIATOR_ORIGIN (213) unless you first navigate to the
  // request origin using some other mechanism (LoadURL, link click, etc).
  ///
  /*--cef()--*/
  virtual void LoadRequest(CefRefPtr<CefRequest> request) = 0;

  ///
  // Load the specified |url|.
  ///
  /*--cef()--*/
  virtual void LoadURL(const CefString& url) = 0;

  ///
  // Execute a string of JavaScript code in this frame. The |script_url|
  // parameter is the URL where the script in question can be found, if any.
  // The renderer may request this URL to show the developer the source of the
  // error.  The |start_line| parameter is the base line number to use for error
  // reporting.
  ///
  /*--cef(optional_param=script_url)--*/
  virtual void ExecuteJavaScript(const CefString& code,
                                 const CefString& script_url,
                                 int start_line) = 0;

  ///
  // Returns true if this is the main (top-level) frame.
  ///
  /*--cef()--*/
  virtual bool IsMain() = 0;

  ///
  // Returns true if this is the focused frame.
  ///
  /*--cef()--*/
  virtual bool IsFocused() = 0;

  ///
  // Returns the name for this frame. If the frame has an assigned name (for
  // example, set via the iframe "name" attribute) then that value will be
  // returned. Otherwise a unique name will be constructed based on the frame
  // parent hierarchy. The main (top-level) frame will always have an empty name
  // value.
  ///
  /*--cef()--*/
  virtual CefString GetName() = 0;

  ///
  // Returns the globally unique identifier for this frame or < 0 if the
  // underlying frame does not yet exist.
  ///
  /*--cef()--*/
  virtual int64 GetIdentifier() = 0;

  ///
  // Returns the parent of this frame or NULL if this is the main (top-level)
  // frame.
  ///
  /*--cef()--*/
  virtual CefRefPtr<CefFrame> GetParent() = 0;

  ///
  // Returns the URL currently loaded in this frame.
  ///
  /*--cef()--*/
  virtual CefString GetURL() = 0;

  ///
  // Returns the browser that this frame belongs to.
  ///
  /*--cef()--*/
  virtual CefRefPtr<CefBrowser> GetBrowser() = 0;

  ///
  // Get the V8 context associated with the frame. This method can only be
  // called from the render process.
  ///
  /*--cef()--*/
  virtual CefRefPtr<CefV8Context> GetV8Context() = 0;

  ///
  // Visit the DOM document. This method can only be called from the render
  // process.
  ///
  /*--cef()--*/
  virtual void VisitDOM(CefRefPtr<CefDOMVisitor> visitor) = 0;

  ///
  // Create a new URL request that will be treated as originating from this
  // frame and the associated browser. This request may be intercepted by the
  // client via CefResourceRequestHandler or CefSchemeHandlerFactory. Use
  // CefURLRequest::Create instead if you do not want the request to have this
  // association, in which case it may be handled differently (see documentation
  // on that method). Requests may originate from both the browser process and
  // the render process.
  //
  // For requests originating from the browser process:
  //   - POST data may only contain a single element of type PDE_TYPE_FILE or
  //     PDE_TYPE_BYTES.
  // For requests originating from the render process:
  //   - POST data may only contain a single element of type PDE_TYPE_BYTES.
  //   - If the response contains Content-Disposition or Mime-Type header values
  //     that would not normally be rendered then the response may receive
  //     special handling inside the browser (for example, via the file download
  //     code path instead of the URL request code path).
  //
  // The |request| object will be marked as read-only after calling this method.
  ///
  /*--cef()--*/
  virtual CefRefPtr<CefURLRequest> CreateURLRequest(
      CefRefPtr<CefRequest> request,
      CefRefPtr<CefURLRequestClient> client) = 0;

  ///
  // Send a message to the specified |target_process|. Message delivery is not
  // guaranteed in all cases (for example, if the browser is closing,
  // navigating, or if the target process crashes). Send an ACK message back
  // from the target process if confirmation is required.
  ///
  /*--cef()--*/
  virtual void SendProcessMessage(CefProcessId target_process,
                                  CefRefPtr<CefProcessMessage> message) = 0;

  ///
  // Synthesizes a pinch gesture over a time period by issuing appropriate touch events.
  // |x| X coordinate of the start of the gesture in CSS pixels.
  // |y| Y coordinate of the start of the gesture in CSS pixels.
  // |scaleFactor| Relative scale factor after zooming (>1.0 zooms in, <1.0 zooms out).
  // |relativeSpeed| Relative pointer speed in pixels per second (default: 800).
  // |gestureSourceType| Which type of input events to be generated (default: 'default', which queries the 
  // platform for the preferred input type). Allowed Values: default, touch, mouse
  ///
  /*--cef()--*/
  virtual void SynthesizePinchGesture(
    float x, float y, 
    float scale_factor, 
    float relative_speed,
    int gesture_source_type) = 0;

  ///
  // Synthesizes a scroll gesture over a time period by issuing appropriate touch events.
  // |x| X coordinate of the start of the gesture in CSS pixels.
  // |y| Y coordinate of the start of the gesture in CSS pixels.
  // |x_distance| The distance to scroll along the X axis (positive to scroll left).
  // |y_distance| The distance to scroll along the Y axis (positive to scroll up).
  // |x_overscroll| The number of additional pixels to scroll back along the X axis, 
  // in addition to the given distance.
  // |y_overscroll| The number of additional pixels to scroll back along the Y axis, 
  // in addition to the given distance.
  // |scaleFactor| Relative scale factor after zooming (>1.0 zooms in, <1.0 zooms out).
  // |prevent_fling| Prevent fling (default: true).
  // |speed| Swipe speed in pixels per second (default: 800).
  // |gesture_source_type| Which type of input events to be generated (default: 'default', 
  // which queries the platform for the preferred input type).
  ///
  /*--cef()--*/
  virtual void SynthesizeScrollGesture(
    float x, float y,
    float x_distance, float y_distance,
    float x_overscroll, float y_overscroll,
    float scale_factor,
    bool prevent_fling,
    int speed,
    int gesture_source_type) = 0;

  ///
  // Synthesizes a tap gesture over a time period by issuing appropriate touch events.
  // |x| X coordinate of the start of the gesture in CSS pixels.
  // |y| Y coordinate of the start of the gesture in CSS pixels.
  // |scaleFactor| Relative scale factor after zooming (>1.0 zooms in, <1.0 zooms out).
  // |duration| Duration between touchdown and touchup events in ms (default: 50).
  // |tap_count| Number of times to perform the tap (e.g. 2 for double tap, default: 1).
  // |gesture_source_type| Which type of input events to be generated (default: 'default', 
  // which queries the platform for the preferred input type).
  ///
  /*--cef()--*/
  virtual void SynthesizeTapGesture(float x, float y, float scale_factor,
    int duration, int tap_count,
    int gesture_source_type) = 0;

  ///
  // Synthesizes a drag gesture over a time period by issuing appropriate touch events.
  // |x_start_position| X coordinate of the start of the gesture in CSS pixels.
  // |y_start_position| Y coordinate of the start of the gesture in CSS pixels.
  // |x_distance| The distance to scroll along the X axis (positive to scroll left).
  // |y_distance| The distance to scroll along the Y axis (positive to scroll up).
  // |scaleFactor| Relative scale factor after zooming (>1.0 zooms in, <1.0 zooms out).
  // |speed| Swipe speed in pixels per second (default: 800).
  // |gesture_source_type| Which type of input events to be generated (default: 'default', 
  // which queries the platform for the preferred input type).
  ///
  /*--cef()--*/
  virtual void SynthesizeDragGesture(float x_start_position, float y_start_position,
    float x_distance, float y_distance, float scale_factor,
    int speed, int gesture_source_type) = 0;

  ///
  // emit touch event for mouse. |enable| Whether touch emulation based on mouse input should be enabled.
  // | configuration | Touch/gesture events configuration. Default: current platform.
  ///
  /*--cef()--*/
  virtual void SetEmitTouchEventsForMouse(bool enabled, int configuration) = 0;
};

#endif  // CEF_INCLUDE_CEF_FRAME_H_
