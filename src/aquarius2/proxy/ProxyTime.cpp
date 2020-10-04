#include "ProxyTime.h"
#include "include/internal/cef_types_wrappers.h"

ProxyTime::ProxyTime(void* ptr):_rawptr(ptr) {

}

ProxyTime::~ProxyTime() {
	if (_rawptr) {
		delete (CefTime*)_rawptr;
		_rawptr = NULL;
	}
}

shrewd_ptr<ProxyTime> ProxyTime::Create() {
	return new ProxyTime(new CefTime);
}

bool ProxyTime::IsValid() {
	return _rawptr != nullptr;
}

// Four or five digit year "2007" (1601 to 30827 on
// Windows, 1970 to 2038 on 32-bit POSIX)
void ProxyTime::SetYear(int year){
	ASSERTN();
	((CefTime*)_rawptr)->year = year;
}
int ProxyTime::GetYear(){
	ASSERTQ(0);
	return ((CefTime*)_rawptr)->year;
}

// 1-based month (values 1 = January, etc.)
void ProxyTime::SetMonth(int month) {
	ASSERTN();
	((CefTime*)_rawptr)->month = month;
}
int ProxyTime::GetMonth() {
	ASSERTQ(0);
	return ((CefTime*)_rawptr)->month;
}

// 0-based day of week (0 = Sunday, etc.)
void ProxyTime::SetDayOfWeek(int day_of_week) {
	ASSERTN();
	((CefTime*)_rawptr)->day_of_week = day_of_week;
}
int ProxyTime::GetDayOfWeek() {
	ASSERTQ(0);
	return ((CefTime*)_rawptr)->day_of_week;
}

// 1-based day of month (1-31)
void ProxyTime::SetDayOfMonth(int day_of_month) {
	ASSERTN();
	((CefTime*)_rawptr)->day_of_month = day_of_month;
}
int ProxyTime::GetDayOfMonth() {
	ASSERTQ(0);
	return ((CefTime*)_rawptr)->day_of_month;
}

// Hour within the current day (0-23)
void ProxyTime::SetHour(int hour) {
	ASSERTN();
	((CefTime*)_rawptr)->hour = hour;
}
int ProxyTime::GetHour() {
	ASSERTQ(0);
	return ((CefTime*)_rawptr)->hour;
}

// Minute within the current hour (0-59)
void ProxyTime::SetMinute(int minute) {
	ASSERTN();
	((CefTime*)_rawptr)->minute = minute;
}
int ProxyTime::GetMinute() {
	ASSERTQ(0);
	return ((CefTime*)_rawptr)->minute;
}

// Second within the current minute (0-59 plus leap
// seconds which may take it up to 60).
void ProxyTime::SetSecond(int second) {
	ASSERTN();
	((CefTime*)_rawptr)->second = second;
}
int ProxyTime::GetSecond() {
	ASSERTQ(0);
	return ((CefTime*)_rawptr)->second;
}

// Milliseconds within the current second (0-999)
void ProxyTime::SetMillisecond(int millisecond) {
	ASSERTN();
	((CefTime*)_rawptr)->millisecond = millisecond;
}
int ProxyTime::GetMillisecond() {
	ASSERTQ(0);
	return ((CefTime*)_rawptr)->millisecond;
}

// set time
void ProxyTime::SetTime(__int64 time) {
	ASSERTN();
	FORWARD(CefTime)->SetTimeT(time);
}

// get time
__int64 ProxyTime::GetTime() {
	ASSERTQ(0);
	return FORWARD(CefTime)->GetTimeT();
}

// set time
void ProxyTime::SetTimeDouble(double time) {
	ASSERTN();
	FORWARD(CefTime)->SetDoubleT(time);
}
// get time
double ProxyTime::GetTimeDouble() {
	ASSERTQ(0.0f);
	return FORWARD(CefTime)->GetDoubleT();
}

//set now
void ProxyTime::SetNow() {
	ASSERTN();
	FORWARD(CefTime)->Now();
}

//delta time
__int64 ProxyTime::Delta(shrewd_ptr<ProxyTime> other) {
	ASSERTQ(0);
	if (!other || !other->OriginPointer()) {
		return 0;
	}
	return FORWARD(CefTime)->Delta( *((CefTime*)other->OriginPointer()) );
}