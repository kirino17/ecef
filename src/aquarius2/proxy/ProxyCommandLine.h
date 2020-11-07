#pragma once
#include "../def/def.h"

class AQUADLL ProxyCommandLine : public refcounted {
public:
	ProxyCommandLine(void* ptr = NULL);
	~ProxyCommandLine();

public:
  ///
  // Returns true if this object is valid. Do not call any other methods if this
  // function returns false.
  ///
  /*--cef()--*/
     bool IsValid();

    ///
    // Returns true if the values of this object are read-only. Some APIs may
    // expose read-only objects.
    ///
    /*--cef()--*/
     bool IsReadOnly();

    ///
    // Returns a writable copy of this object.
    ///
    /*--cef()--*/
     shrewd_ptr<ProxyCommandLine> Copy();

    ///
    // Initialize the command line with the string returned by calling
    // GetCommandLineW(). This method is only supported on Windows.
    ///
    /*--cef()--*/
     void InitFromString(const char* command_line);

    ///
    // Reset the command-line switches and arguments but leave the program
    // component unchanged.
    ///
    /*--cef()--*/
     void Reset();

    ///
    // Retrieve the original command line string as a vector of strings.
    // The argv array: { program, [(--|-|/)switch[=value]]*, [--], [argument]* }
    // 返回一个组合字符串, 写入到 |argvArrays|, 使用\r\n进行分隔, 返回值为组合字符串中的子串数。
    ///
    /*--cef()--*/
     char** GetArgv();

    ///
    // Constructs and returns the represented command line string. Use this method
    // cautiously because quoting behavior is unclear.
    ///
    /*--cef()--*/
     char* GetCommandLineString();

    ///
    // Get the program part of the command line string (the first item).
    ///
    /*--cef()--*/
     char* GetProgram();

    ///
    // Set the program part of the command line string (the first item).
    ///
    /*--cef()--*/
     void SetProgram(const char* program);

    ///
    // Returns true if the command line has switches.
    ///
    /*--cef()--*/
     bool HasSwitches();

    ///
    // Returns true if the command line contains the given switch.
    ///
    /*--cef()--*/
     bool HasSwitch(const char* name);

    ///
    // Returns the value associated with the given switch. If the switch has no
    // value or isn't present this method returns the empty string.
    ///
    /*--cef()--*/
     char* GetSwitchValue(const char* name);


    ///
    // Add a switch to the end of the command line. If the switch has no value
    // pass an empty value string.
    ///
    /*--cef()--*/
     void AppendSwitch(const char* name);

    ///
    // Add a switch with the specified value to the end of the command line.
    ///
    /*--cef()--*/
     void AppendSwitchWithValue(const char* name,
        const char* value);

     
public:
	PRIME_IMPLEMENT_REFCOUNTING(ProxyCommandLine);
	AQUA_DECL_PUBLIC_ORIGIN;

private:
	void* _rawptr;
};