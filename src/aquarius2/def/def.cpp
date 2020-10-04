#include "def.h"
#include <malloc.h>
#include <assert.h>

/**
 *  分配一个新的内存缓冲区，该分配函数由调用者提供。
 *
 *  @param size 分配长度
 *  @return 返回分配到的内存缓冲区指针。
*/
AQUADLL LPFN_MEMORY_ALLOCATE NewBuffer = nullptr;

/**
 *  释放由NewBuffer函数申请的内存缓冲区指针, 该释放函数由调用者提供。
 *
 *  @param ptr 缓冲区指针, 调用此函数后, 该指针不再可用。
*/
AQUADLL LPFN_MEMORY_RELEASE	DeleteBuffer = nullptr;

/**
 *  分配一个新的内存缓冲区, 该缓冲区是数组，该分配函数由调用者提供。
 *
 *  @param size 分配长度
 *  @return 返回分配到的内存缓冲区指针。
*/
AQUADLL LPFN_MEMORY_ALLOCATE NewBufferInArray = nullptr;

/**
 *  释放由NewBufferInArray函数申请的内存缓冲区指针, 该释放函数由调用者提供。
 *
 *  @param ptr 缓冲区指针, 调用此函数后, 该指针不再可用。
*/
AQUADLL LPFN_MEMORY_RELEASE	DeleteBufferInArray = nullptr;


/**
 *  转换多字节(MBCS/ANSI)字符串流到宽字节(Unicode)字符串流。
 *
 *  @param str 字符流缓冲区
 *  @param length 字符流长度
 *  @return 返回转换后的宽字节(Unicode)字符串流。
*/
AQUADLL wchar_t* WEBAPI ToUnicode(const char* str, size_t length) {
	assert(NewBuffer);
	if (!str || length <= 0) return NULL;
	size_t bLength = MultiByteToWideChar(CP_ACP, NULL, str, length, NULL, NULL);
	wchar_t* buf = (wchar_t*)NewBuffer(bLength* sizeof(wchar_t) + sizeof(wchar_t));
	MultiByteToWideChar(CP_ACP, NULL, str, length, buf, bLength);
	buf[bLength] = 0;
	return buf;
}

/**
 *  转换宽字节(Unicode)字符串流到多字节(MBCS/ANSI)字符串流。
 *
 *  @param str 字符流缓冲区
 *  @param length 字符流长度
 *  @return 返回转换后的多字节(MBCS/ANSI)字符串流。
*/
AQUADLL char* WEBAPI ToAnsi(const wchar_t* str, size_t length) {
	assert(NewBuffer);
	if (!str || length <= 0) return NULL;
	size_t bLength = WideCharToMultiByte(CP_ACP, NULL, str, length, NULL, NULL,NULL,NULL);
	char* buf = (char*)NewBuffer(bLength * sizeof(char*) + sizeof(char));
	WideCharToMultiByte(CP_ACP, NULL, str, length, buf, bLength, NULL, NULL);
	buf[bLength] = 0;
	return buf;
}