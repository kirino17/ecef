#pragma once
#include "def.h"

class AQUADLL Power : public refcounted {
public:
	Power(void* ptr);
	~Power();

public:
	static shrewd_ptr<Power> GetInstance();

public:
	void Initialize(int mode);

	void Shutdown(void);

	void* GetCmdNames(HWND hWnd);
public:
	PRIME_IMPLEMENT_REFCOUNTING(Power);
	AQUA_DECL_PUBLIC_ORIGIN;

private:
	void* _rawptr;
};