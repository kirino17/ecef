#pragma once
#include "../def/def.h"

class AQUADLL ProxyTime : public refcounted {
public:
	ProxyTime(void* ptr);
	~ProxyTime();

public:
    static shrewd_ptr<ProxyTime> Create();

public:
    // is valid
    bool IsValid();

    // Four or five digit year "2007" (1601 to 30827 on
    // Windows, 1970 to 2038 on 32-bit POSIX)
    void SetYear(int year);
    /*--cef()--*/
    int GetYear();
            
    // 1-based month (values 1 = January, etc.)
    void SetMonth(int month);
    /*--cef()--*/
    int GetMonth();

    // 0-based day of week (0 = Sunday, etc.)
    void SetDayOfWeek(int day_of_week);
    /*--cef()--*/
    int GetDayOfWeek();

    // 1-based day of month (1-31)
    void SetDayOfMonth(int day_of_month);
    /*--cef()--*/
    int GetDayOfMonth();

    // Hour within the current day (0-23)
    void SetHour(int hour);
    /*--cef()--*/
    int GetHour();

    // Minute within the current hour (0-59)
    void SetMinute(int minute);
    /*--cef()--*/
    int GetMinute();

    // Second within the current minute (0-59 plus leap
    // seconds which may take it up to 60).
    void SetSecond(int second); 
    /*--cef()--*/
    int GetSecond();
                       
    // Milliseconds within the current second (0-999)
    void SetMillisecond(int millisecond);
    /*--cef()--*/
    int GetMillisecond();

    // set time
    void SetTime(__int64 time);
    // get time
    __int64 GetTime();

    // set time
    void SetTimeDouble(double time);
    // get time
    double GetTimeDouble();

    //set now
    void SetNow(); 

    //delta time
    __int64 Delta(shrewd_ptr<ProxyTime> other);

public:
	PRIME_IMPLEMENT_REFCOUNTING(ProxyTime);
	AQUA_DECL_PUBLIC_ORIGIN;

private:
	void* _rawptr;
};