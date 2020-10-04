#include "ProxyCommandLine.h"
#include "include/cef_command_line.h"
#include <atlconv.h>
#include "../def/internalDef.h"

AQUA_PROXY_AUTO_CONSTRUCTOR(ProxyCommandLine,CefCommandLine);

///
// Create a new CefCommandLine instance.
///
/*--cef(api_hash_check)--*/
shrewd_ptr<ProxyCommandLine> ProxyCommandLine::CreateCommandLine() {
	return new ProxyCommandLine(CefCommandLine::CreateCommandLine());
}

///
// Returns the singleton global CefCommandLine object. The returned object
// will be read-only.
///
/*--cef(api_hash_check)--*/
shrewd_ptr<ProxyCommandLine> ProxyCommandLine::GetGlobalCommandLine() {
	return new ProxyCommandLine(CefCommandLine::GetGlobalCommandLine());
}

///
// Returns true if this object is valid. Do not call any other methods if this
// function returns false.
///
/*--cef()--*/
bool ProxyCommandLine::IsValid() {
	ASSERTQ(false);
	return FORWARD(CefCommandLine)->IsValid();
}

///
// Returns true if the values of this object are read-only. Some APIs may
// expose read-only objects.
///
/*--cef()--*/
bool ProxyCommandLine::IsReadOnly() {
	ASSERTQ(false);
	return FORWARD(CefCommandLine)->IsReadOnly();
}

///
// Returns a writable copy of this object.
///
/*--cef()--*/
shrewd_ptr<ProxyCommandLine> ProxyCommandLine::Copy() {
	ASSERTQ(NULL);
	return new ProxyCommandLine(FORWARD(CefCommandLine)->Copy());
}

///
// Initialize the command line with the string returned by calling
// GetCommandLineW(). This method is only supported on Windows.
///
/*--cef()--*/
void ProxyCommandLine::InitFromString(const char* command_line) {
	ASSERTN();
	USES_CONVERSION;
	FORWARD(CefCommandLine)->InitFromString(A2W(command_line));
}

///
// Reset the command-line switches and arguments but leave the program
// component unchanged.
///
/*--cef()--*/
void ProxyCommandLine::Reset() {
	ASSERTN();
	FORWARD(CefCommandLine)->Reset();
}

///
// Retrieve the original command line string as a vector of strings.
// The argv array: { program, [(--|-|/)switch[=value]]*, [--], [argument]* }
///
/*--cef()--*/
char** ProxyCommandLine::GetArgv() {
	ASSERTQ(0);
	assert(NewBuffer);
	std::vector<CefString> stringArrays;
	FORWARD(CefCommandLine)->GetArgv(stringArrays);
	size_t count = stringArrays.size();
	DWORD* pointer = (DWORD*)NewBuffer( sizeof(INT) * (2 + count) );
	*(pointer + 0) = 1;
	*(pointer + 1) = count;
	for (size_t i = 0; i < stringArrays.size(); i++){
		*(pointer + i + 2) = (DWORD)ToAnsi(stringArrays[i].c_str(), stringArrays[i].length());
	}
	return (char**)pointer;
}

///
// Constructs and returns the represented command line string. Use this method
// cautiously because quoting behavior is unclear.
///
/*--cef()--*/
char* ProxyCommandLine::GetCommandLineString() {
	ASSERTQ(NULL);
	assert(NewBuffer);
	CefString string = FORWARD(CefCommandLine)->GetCommandLineString();
	return ToAnsi(string.c_str(), string.length());
}

///
// Get the program part of the command line string (the first item).
///
/*--cef()--*/
char* ProxyCommandLine::GetProgram() {
	ASSERTQ(NULL);
	assert(NewBuffer);
	CefString string = FORWARD(CefCommandLine)->GetProgram();
	return ToAnsi(string.c_str(), string.length());
}

///
// Set the program part of the command line string (the first item).
///
/*--cef()--*/
void ProxyCommandLine::SetProgram(const char* program) {
	ASSERTN();
	if (!program) {
		return;
	}
	USES_CONVERSION;
	FORWARD(CefCommandLine)->SetProgram(A2W(program));
}

///
// Returns true if the command line has switches.
///
/*--cef()--*/
bool ProxyCommandLine::HasSwitches() {
	ASSERTQ(false);
	USES_CONVERSION;
	return FORWARD(CefCommandLine)->HasSwitches();
}

///
// Returns true if the command line contains the given switch.
///
/*--cef()--*/
bool ProxyCommandLine::HasSwitch(const char* name) {
	ASSERTQ(false);
	if (!name) {
		return false;
	}
	USES_CONVERSION;
	return FORWARD(CefCommandLine)->HasSwitch(name);
}

///
// Returns the value associated with the given switch. If the switch has no
// value or isn't present this method returns the empty string.
///
/*--cef()--*/
char* ProxyCommandLine::GetSwitchValue(const char* name) {
	ASSERTQ(NULL);
	assert(NewBuffer);
	if (!name) {
		return NULL;
	}
	CefString string = FORWARD(CefCommandLine)->GetSwitchValue(name);
	return ToAnsi(string.c_str(), string.length());
}


///
// Add a switch to the end of the command line. If the switch has no value
// pass an empty value string.
///
/*--cef()--*/
void ProxyCommandLine::AppendSwitch(const char* name) {
	ASSERTN();
	if (!name) {
		return;
	}
	FORWARD(CefCommandLine)->AppendSwitch(name);
}

///
// Add a switch with the specified value to the end of the command line.
///
/*--cef()--*/
void ProxyCommandLine::AppendSwitchWithValue(const char* name,
	const char* value) {
	ASSERTN();
	if (!name) {
		return;
	}
	if (!value) {
		FORWARD(CefCommandLine)->AppendSwitch(name);
	}
	else {
		USES_CONVERSION;
		FORWARD(CefCommandLine)->AppendSwitchWithValue(name, A2W(value) );
	}
}