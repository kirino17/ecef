#include "TestThread.h"

TestThread::TestThread(std::function<void(void)> fun):
	_callback(fun)
{

}

TestThread::~TestThread() {

}

void TestThread::Execute() {
	if (_callback) {
		_callback();
	}
}