#include "internalDef.h"
#include <sstream>
#include <codecvt>
#include <atlconv.h>
#include <string.h>
#include <tchar.h>
#include "include/cef_waitable_event.h"
#include <Windows.h>
#include <thread>
#include "include/cef_values.h"
#include <chrono>

ByteBuffer::ByteBuffer(size_t block_size):
    _blockSize(block_size)
{

}

ByteBuffer::~ByteBuffer() {

}

//写入流
void ByteBuffer::WriteBuffer(const void* in_data, size_t length) {
    if(!in_data || length <= 0) {
        return;
    }

    if (_bufferData.empty()) {
        _bufferData.emplace_back(_blockSize);
    }

    MEMORY_DATA_BUFFER src(0);
    MEMORY_DATA_BUFFER& buffer = _bufferData.back();
    size_t notUseLength = buffer.size - buffer.offset;
    if (notUseLength >= length) {
        memcpy(&buffer.pointer[buffer.offset], in_data, length);
        buffer.offset += length;
        return;
    }
    
    memcpy(&buffer.pointer[buffer.offset], in_data, notUseLength);
    buffer.offset += notUseLength;

    src.pointer = ((unsigned char*)in_data) + notUseLength;
    src.size = length - notUseLength;

    while (src.size > 0){
        _bufferData.emplace_back(_blockSize);
        buffer = _bufferData.back();

        if (buffer.size >= src.size) {
            memcpy(buffer.pointer, src.pointer, src.size);
            buffer.offset = src.size;
            src.size = 0;
        }
        else {
            memcpy(buffer.pointer, src.pointer, buffer.size);
            buffer.offset = buffer.size;
            src.size -= buffer.size;
            src.pointer += buffer.size;
        }
    }
}

//读出流
void ByteBuffer::ReadBuffer(void* out_data, size_t length) {
    if (!out_data || length <= 0) {
        return;
    }
    int offset = 0;
    unsigned char* out = (unsigned char*)out_data;
    for (size_t i = 0; i < _bufferData.size(); i++)
    {
        if (offset >= length) {
            return;
        }

        MEMORY_DATA_BUFFER& buffer = _bufferData[i];

        size_t num = (length - offset);
        if (num >= buffer.size) {
            memcpy(&out[offset], buffer.pointer, buffer.size);
            offset += buffer.size;
        }
        else {
            memcpy(&out[offset], buffer.pointer, num);
            offset += num;
        }
    }
}

//已写入长度
size_t ByteBuffer::GetTotalBytes(void) {
    size_t length = 0;
    for (auto& v: _bufferData){
        length += v.offset;
    }
    return length;
}

void ByteBuffer::Clear() {
    _bufferData.clear();
}



/**
 *  将多个Unicode字符串合并到一个字符串输出。
 *
 *  @param stringArray 字符串数组
 *  @param spaceString 分隔字符串
 *  @return 返回合并后的ANSI字符串。
*/
char* StringArrayToBuffer(const std::vector<CefString>& stringArray, const wchar_t* spaceString) {
	std::wstringstream strbuf;
	for (size_t i = 0; i < stringArray.size(); i++)
	{
        if (!stringArray[i].empty()) {
            strbuf << stringArray[i].c_str() << spaceString;
        }
	}
	const auto& s = strbuf.str();
	if (!s.empty()) {
		return ToAnsi(s.c_str(), s.length());
	}
	return NULL;
}

/**
 *  分割一个组合字符串。
 *
 *  @param stringBuffer 待分割的字符串
 *  @param spaceString 用作分割的字符串
 *  @return 返回分割出的字符串数量
*/
int SplitString(const char* stringBuffer, const char* spaceString, std::vector<std::wstring>& stringArrays) {
    if (!stringBuffer) {
        return 0;
    }
    std::size_t length = strlen(stringBuffer);
    wchar_t* buffer = nullptr;
    bool useMemory = false;
    USES_CONVERSION;

    if (length < 0x200) {
        buffer = A2W(stringBuffer);
        length = lstrlenW(buffer);
    }
    else {
        useMemory = true;
        buffer = ToUnicode(stringBuffer, length);
        length = lstrlenW(buffer);
    }

    if (!spaceString) {
        stringArrays.push_back(buffer);
        if (useMemory) DeleteBuffer(buffer);
        return 1;
    }

    wchar_t* space = A2W(spaceString);
    std::size_t spaceLength = lstrlenW(space);
    std::size_t pointer = 0;
    while (pointer < length) {
        const wchar_t* end = wcsstr(&buffer[pointer], space);
        if (!end) {
            stringArrays.push_back(&buffer[pointer]);
            break;
        }
        stringArrays.emplace_back(&buffer[pointer], end - &buffer[pointer]);
        pointer += (end - &buffer[pointer]) + spaceLength;
    }

    if (useMemory) DeleteBuffer(buffer);
    return stringArrays.size();
}

/**
 *  分割一个组合字符串。
 *
 *  @param stringBuffer 待分割的字符串
 *  @param spaceString 用作分割的字符串
 *  @return 返回分割出的字符串数量
*/
int SplitString(const char* stringBuffer, const char* spaceString, std::vector<CefString>& stringArrays) {
    if (!stringBuffer) {
        return 0;
    }
    std::size_t length = strlen(stringBuffer);
    wchar_t* buffer = nullptr;
    bool useMemory = false;
    USES_CONVERSION;

    if (length < 0x200) {
        buffer = A2W(stringBuffer);
        length = lstrlenW(buffer);
    }
    else {
        useMemory = true;
        buffer = ToUnicode(stringBuffer, length);
        length = lstrlenW(buffer);
    }

    if (!spaceString) {
        stringArrays.push_back(buffer);
        if (useMemory) DeleteBuffer(buffer);
        return 1;
    }

    wchar_t* space = A2W(spaceString);
    std::size_t spaceLength = lstrlenW(space);
    std::size_t pointer = 0;
    std::wstring temp;
    while (pointer < length) {
        const wchar_t* end = wcsstr(&buffer[pointer], space);
        if (!end) {
            stringArrays.push_back(buffer);
            break;
        }
        temp.assign(&buffer[pointer], end - &buffer[pointer]);
        stringArrays.emplace_back(temp);
        pointer += (end - &buffer[pointer]) + spaceLength;
    }

    if (useMemory) DeleteBuffer(buffer);
    return stringArrays.size();
}


/**
 *  分割一个组合字符串。
 *
 *  @param stringBuffer 待分割的字符串
 *  @param spaceString 用作分割的字符串
 *  @return 返回分割出的字符串数量
*/
int SplitString(const char* stringBuffer, const char* spaceString, std::vector<std::string>& stringArrays) {
    if (!stringBuffer) {
        return 0;
    }
    if (!spaceString) {
        stringArrays.push_back(stringBuffer);
        return 1;
    }
    std::size_t length = strlen(stringBuffer);
    std::size_t spaceLength = strlen(spaceString);
    std::size_t pointer = 0;
    while (pointer < length) {
        const char* end = strstr(&stringBuffer[pointer], spaceString);
        if (!end) {
            stringArrays.push_back(stringBuffer);
            break;
        }
        stringArrays.emplace_back(&stringBuffer[pointer], end - &stringBuffer[pointer]);
        pointer += (end - &stringBuffer[pointer]) + spaceLength;
    }
    return stringArrays.size();
}

void WaitTimeout(float timeout) {
    MSG uiMsg;
    if (timeout <= 0) {
        return ;
    }
    auto timepoint = std::chrono::steady_clock::now();
    while (true) {
        if (PeekMessage(&uiMsg, NULL, 0, 0, PM_REMOVE)) {
            TranslateMessage(&uiMsg);
            DispatchMessage(&uiMsg);
            if (uiMsg.message == WM_QUIT) {
                return ;
            }
        }

        auto time = std::chrono::steady_clock::now();
        auto delta = static_cast<float>(static_cast<double>(std::chrono::duration_cast<std::chrono::microseconds>((time - timepoint)).count()) * 1e-3);
        if (delta >= timeout) {
            return ;
        }

        Sleep(1);
    }
}

/**
 *  线程同步等待
 *
 *  @param 等待对象
*/
void WaitAwaking(CefRefPtr<CefWaitableEvent> waitable) {
    MSG uiMsg;
    if (!waitable) {
        return;
    }
    while (!waitable->IsSignaled()) {
        if (PeekMessage(&uiMsg, NULL, 0, 0, PM_REMOVE)) {
            TranslateMessage(&uiMsg);
            DispatchMessage(&uiMsg);
            if (uiMsg.message == WM_QUIT) {
                break;
            }
        }
        Sleep(1);
    }
}

/**
 *  线程同步等待
 *
 *  @param waitable 等待对象
*/
void DomWaitAwaking(CefRefPtr<CefFrame> frame, CefRefPtr<CefWaitableEvent> waitable) {
    MSG uiMsg;
    if (!waitable) {
        return;
    }
    while (!waitable->IsSignaled() && frame->IsValid()) {
        if (PeekMessage(&uiMsg, NULL, 0, 0, PM_REMOVE)) {
            TranslateMessage(&uiMsg);
            DispatchMessage(&uiMsg);
            if (uiMsg.message == WM_QUIT) {
                break;
            }
        }
        Sleep(1);
    }
}


bool WaitAwakingTimeout(CefRefPtr<CefWaitableEvent> waitable, float timeout) {
    MSG uiMsg;
    if (!waitable) {
        return false;
    }
    if (timeout <= 0) {
        return false;
    }
    auto timepoint = std::chrono::steady_clock::now();

    while (!waitable->IsSignaled()) {
        if (PeekMessage(&uiMsg, NULL, 0, 0, PM_REMOVE)) {
            TranslateMessage(&uiMsg);
            DispatchMessage(&uiMsg);
            if (uiMsg.message == WM_QUIT) {
                return false;
            }
        }

        auto time = std::chrono::steady_clock::now();
        auto delta = static_cast<float>(static_cast<double>(std::chrono::duration_cast<std::chrono::microseconds>((time - timepoint)).count()) * 1e-3);
        if (delta >= timeout) {
            return false;
        }

        Sleep(1);
    }

    return true;
}

char** CreateEPLStringArray(const std::vector<CefString>& strings) {
    if (strings.empty()) {
        return NULL;
    }
    int count = strings.size();
    
    DWORD* pointer = (DWORD*)NewBuffer(sizeof(INT) * (2 + count));
    *(pointer + 0) = 1;
    *(pointer + 1) = count;
    for (size_t i = 0; i < count; i++) {
        if (strings[i].length() > 0) {
            char* buffer = ToAnsi(strings[i].c_str(), strings[i].length());
            *(pointer + i + 2) = (DWORD)buffer;
        }
        else {
            *(pointer + i + 2) = (DWORD)NULL;
        }
    }
    return (char**)pointer;
}