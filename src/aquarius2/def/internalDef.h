#pragma once
#include "def.h"
#include "include/cef_app.h"
#include <vector>
#include <string>
#include "include/cef_waitable_event.h"
#include <windows.h>

//  使用页分配的内存数据块
struct MEMORY_DATA_BUFFER {
	unsigned char* pointer;
	size_t	size;
	size_t	offset;

	MEMORY_DATA_BUFFER(size_t length) :
		pointer(nullptr),
		size(0),
		offset(0) {
		if (length > 0) {
			Initialized(length);
		}
	}

	~MEMORY_DATA_BUFFER() {
		Clear();
	}

	void Initialized(size_t length) {
		this->Clear();
		pointer = (unsigned char*)VirtualAlloc(nullptr, length, MEM_COMMIT, PAGE_READWRITE);
		this->size = length;
		this->offset = 0;
	}

	void Clear() {
		if (pointer) {
			VirtualFree(pointer, 0, MEM_RELEASE);
			this->size = 0;
			this->offset = 0;
		}
	}
};

///
//	字节流
///
class ByteBuffer {
public:
	ByteBuffer(size_t block_size);
	~ByteBuffer();

public:
	//写入流
	void WriteBuffer(const void* in_data, size_t length);

	//读出流
	void ReadBuffer(void* out_data, size_t length);

	//已写入长度
	size_t GetTotalBytes(void);

	void Clear();
private:
	std::vector<MEMORY_DATA_BUFFER> _bufferData;
	int _blockSize;
};

////////////////////////////////////////////////////

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

void WaitTimeout(float timeout);

/**
 *  线程同步等待
 *
 *  @param waitable 等待对象
*/
void WaitAwaking(CefRefPtr<CefWaitableEvent> waitable);

/**
 *  线程同步等待
 *
 *  @param waitable 等待对象
*/
void DomWaitAwaking(CefRefPtr<CefFrame> frame, CefRefPtr<CefWaitableEvent> waitable);


/**
 *  线程同步等待, 超时限制
 *
 *  @param waitable 等待对象
 *	@param timeout 等待时间
 *	@return 返回true表示收到信号, false则已超过时间
*/
bool WaitAwakingTimeout(CefRefPtr<CefWaitableEvent> waitable, float timeout);

/**
 *	创建易字符串数组
*/
char** CreateEPLStringArray(const std::vector<CefString>& strings);