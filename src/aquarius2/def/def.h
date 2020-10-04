#pragma once

//导出定义
#ifdef AQUARIUS_SRC
#define AQUADLL __declspec(dllexport)
#else
#define AQUADLL __declspec(dllimport)
#endif

//多线程生命周期管理工具
#define PRIME_DLL	AQUADLL
#include "refcounted.h"
using namespace prime;

//导出API约定
#define WEBAPI			__cdecl
#define WEBCALLBACK		__stdcall

///////////////////////////////////////////////////////
///////////////////////////////////////////////////////

//适用于Proxy类的自动构造函数
#define AQUA_PROXY_AUTO_CONSTRUCTOR(ClassName,OriginClass) \
	ClassName::ClassName(void* ptr):_rawptr(ptr){ \
		if(_rawptr) reinterpret_cast<OriginClass*>(_rawptr)->AddRef(); \
	} \
	ClassName::~##ClassName(){ \
		if(_rawptr){ \
			reinterpret_cast<OriginClass*>(_rawptr)->Release(); \
			_rawptr = NULL; \
		} \
	}

#define AQUA_DECL_PUBLIC_ORIGIN \
	public: \
		void* OriginPointer(void) { return _rawptr; }

//辅助编写宏
#define ASSERTQ(ret) if(!_rawptr) return ret
#define ASSERTN() if(!_rawptr) return 
#define FORWARD(ClassName) reinterpret_cast<ClassName*>(_rawptr)
#define ORIGIN(ClassName, wrap) reinterpret_cast<ClassName*>(wrap->OriginPointer())

//约定内存的申请以及释放接口定义
typedef void*(WEBCALLBACK* LPFN_MEMORY_ALLOCATE)(size_t size);
typedef void(WEBCALLBACK* LPFN_MEMORY_RELEASE)(void* ptr);

//////////////////////////////////////////////////////////

/**
 *  分配一个新的内存缓冲区，该分配函数由调用者提供。
 *  
 *  @param size 分配长度
 *  @return 返回分配到的内存缓冲区指针。
*/
extern AQUADLL LPFN_MEMORY_ALLOCATE NewBuffer;

/**
 *  释放由NewBuffer函数申请的内存缓冲区指针, 该释放函数由调用者提供。
 *
 *  @param ptr 缓冲区指针, 调用此函数后, 该指针不再可用。
*/
extern AQUADLL LPFN_MEMORY_RELEASE	DeleteBuffer;


/**
 *  分配一个新的内存缓冲区, 该缓冲区是数组，该分配函数由调用者提供。
 *
 *  @param size 分配长度
 *  @return 返回分配到的内存缓冲区指针。
*/
extern AQUADLL LPFN_MEMORY_ALLOCATE NewBufferInArray;

/**
 *  释放由NewBufferInArray函数申请的内存缓冲区指针, 该释放函数由调用者提供。
 *
 *  @param ptr 缓冲区指针, 调用此函数后, 该指针不再可用。
*/
extern AQUADLL LPFN_MEMORY_RELEASE	DeleteBufferInArray;

///////////////////////////////////////////////
///////////////////////////////////////////////

/**
 *  转换多字节(MBCS/ANSI)字符串流到宽字节(Unicode)字符串流。
 *  
 *  @param str 字符流缓冲区
 *  @param length 字符流长度
 *  @return 返回转换后的宽字节(Unicode)字符串流。
*/
AQUADLL wchar_t* WEBAPI ToUnicode(const char* str, size_t length);

/**
 *  转换宽字节(Unicode)字符串流到多字节(MBCS/ANSI)字符串流。
 *
 *  @param str 字符流缓冲区
 *  @param length 字符流长度
 *  @return 返回转换后的多字节(MBCS/ANSI)字符串流。
*/
AQUADLL char* WEBAPI ToAnsi(const wchar_t* str, size_t length);

//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////

