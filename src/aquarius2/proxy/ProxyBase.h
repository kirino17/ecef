#pragma once
#include "../def/def.h"
#include "ProxySettings.h"
#include "ProxyListValue.h"
#include "ProxyValue.h"

#define RENDERER_PROCESS_EXTRA_INFO_V8_INTERCEPTOR		(0x8001)
#define RENDERER_PROCESS_EXTRA_INFO_V8_OBJECT			(0x8002)

class AQUADLL ProxyBase : public refcounted {
public:
	ProxyBase();
	~ProxyBase();

public:

	///
	// This function should be called from the application entry point function to
	// execute a secondary process. It can be used to run secondary processes from
	// the browser client executable (default behavior) or from a separate
	// executable specified by the CefSettings.browser_subprocess_path value. If
	// called for the browser process (identified by no "type" command-line value)
	// it will return immediately with a value of -1. If called for a recognized
	// secondary process it will block until the process should exit and then return
	// the process exit code. The |application| parameter may be empty. The
	// |windows_sandbox_info| parameter is only used on Windows and may be NULL (see
	// cef_sandbox_win.h for details).
	///
	/*--cef(api_hash_check,optional_param=application,
			optional_param=windows_sandbox_info)--*/
	static int ExecuteProcess(unsigned int client);


	///
	// This function should be called on the main application thread to initialize
	// the CEF browser process. The |application| parameter may be empty. A return
	// value of true indicates that it succeeded and false indicates that it failed.
	// The |windows_sandbox_info| parameter is only used on Windows and may be NULL
	// (see cef_sandbox_win.h for details).
	///
	/*--cef(api_hash_check,optional_param=application,
			optional_param=windows_sandbox_info)--*/
	static bool Initialize(
		shrewd_ptr<ProxySettings> settings,
		unsigned int client
	);

	///
	// This function should be called on the main application thread to shut down
	// the CEF browser process before the application exits.
	///
	/*--cef()--*/
	static void Shutdown();

	///
	// Perform a single iteration of CEF message loop processing. This function is
	// provided for cases where the CEF message loop must be integrated into an
	// existing application message loop. Use of this function is not recommended
	// for most users; use either the CefRunMessageLoop() function or
	// CefSettings.multi_threaded_message_loop if possible. When using this function
	// care must be taken to balance performance against excessive CPU usage. It is
	// recommended to enable the CefSettings.external_message_pump option when using
	// this function so that CefBrowserProcessHandler::OnScheduleMessagePumpWork()
	// callbacks can facilitate the scheduling process. This function should only be
	// called on the main application thread and only if CefInitialize() is called
	// with a CefSettings.multi_threaded_message_loop value of false. This function
	// will not block.
	///
	/*--cef()--*/
	static void DoMessageLoopWork();

	///
	// Run the CEF message loop. Use this function instead of an application-
	// provided message loop to get the best balance between performance and CPU
	// usage. This function should only be called on the main application thread and
	// only if CefInitialize() is called with a
	// CefSettings.multi_threaded_message_loop value of false. This function will
	// block until a quit message is received by the system.
	///
	/*--cef()--*/
	static void RunMessageLoop();

	///
	// Quit the CEF message loop that was started by calling CefRunMessageLoop().
	// This function should only be called on the main application thread and only
	// if CefRunMessageLoop() was used.
	///
	/*--cef()--*/
	static void QuitMessageLoop();

	///
	// Set to true before calling Windows APIs like TrackPopupMenu that enter a
	// modal message loop. Set to false after exiting the modal message loop.
	///
	/*--cef()--*/
	static void SetOSModalLoop(bool osModalLoop);

	///
	// Call during process startup to enable High-DPI support on Windows 7 or newer.
	// Older versions of Windows should be left DPI-unaware because they do not
	// support DirectWrite and GDI fonts are kerned very badly.
	///
	/*--cef(capi_name=cef_enable_highdpi_support)--*/
	static void EnableHighDPISupport();

	///
	// SetV8Interceptor
	///
	static void SetV8Interceptor(shrewd_ptr<ProxyListValue> extra_info, const char* path, shrewd_ptr<ProxyValue> retval, int attribute);

	///
	// CreateV8Object
	///
	static void CreateV8Object(shrewd_ptr<ProxyListValue> extra_info, const char* path, int attribute);


public:
	PRIME_IMPLEMENT_REFCOUNTING(ProxyBase);
};