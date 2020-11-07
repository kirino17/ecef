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

//易语言类型导出约定
typedef char	        EPL_BYTE;
typedef short	        EPL_SHORT;
typedef int		        EPL_INT;
typedef __int64	        EPL_INT64;
typedef float	        EPL_FLOAT;
typedef double	        EPL_DOUBLE;
typedef int		        EPL_BOOL;
typedef char*           EPL_TEXT;
typedef unsigned char*  EPL_BIN;
typedef void*           EPL_SUBPTR;
typedef void*           EPL_STATMENT;
typedef void*           EPL_ALL;

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

//内部方法标志, 使用此标志的类, 枚举, 以及方法都将在易语言中隐藏
#define INTERNAL_CALL

//可空标志, 使用此标志的参数表示为接受易语言空值调用, 标志必须于类型名称前, 如: void foo(EPL_EMPTY int value);
#define EPL_EMPTY

//事件标志, 使用此标志的方法为一个易语言事件。
#define EPL_EVENT

#define ASSERTARRAY(type) if(!_rawptr){ \
    DWORD* pointer = (DWORD*)NewBuffer(sizeof(INT) * (2)); \
    *(pointer + 0) = 1; \
    *(pointer + 1) = 0; \
    return (type**)pointer; \
}

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

