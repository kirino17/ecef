#pragma once
#include "def.h"
#include "include/cef_app.h"
#include <vector>
#include <string>
#include "include/cef_waitable_event.h"

/**
 *  将多个Unicode字符串合并到一个字符串输出。
 *
 *  @param stringArray 字符串数组
 *  @param spaceString 分隔字符串
 *  @return 返回合并后的ANSI字符串。
*/
char* StringArrayToBuffer(const std::vector<CefString>& stringArray, const wchar_t* spaceString);

/**
 *  分割一个组合字符串。
 *
 *  @param stringBuffer 待分割的字符串
 *  @param spaceString 用作分割的字符串
 *  @return 返回分割出的字符串数量
*/
int SplitString(const char* stringBuffer, const char* spaceString, std::vector<std::wstring>& stringArrays);


/**
 *  分割一个组合字符串。
 *
 *  @param stringBuffer 待分割的字符串
 *  @param spaceString 用作分割的字符串
 *  @return 返回分割出的字符串数量
*/
int SplitString(const char* stringBuffer, const char* spaceString, std::vector<CefString>& stringArrays);



/**
 *  分割一个组合字符串。
 *
 *  @param stringBuffer 待分割的字符串
 *  @param spaceString 用作分割的字符串
 *  @return 返回分割出的字符串数量
*/
int SplitString(const char* stringBuffer, const char* spaceString, std::vector<std::string>& stringArrays);

/**
 *  线程同步等待
 *
 *  @param 等待对象
*/
void WaitAwaking(CefRefPtr<CefWaitableEvent> waitable);

char** CreateEPLStringArray(const std::vector<CefString>& strings);