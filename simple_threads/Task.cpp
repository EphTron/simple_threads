#include "Task.h"
#include <iostream>
#include <string>


Task::Task(int id):
	_id(id),
	_hThread(0),
	_terminate(false)
{
	std::cout << "Task " << std::to_string(_id) << " started" << std::endl;
}


Task::~Task()
{
}

int Task::run()
{
	for (int i = 0; i < 10; ++i) {
		Sleep(1000);
		std::cout << "Task " << std::to_string(_id) << " at:" << i << std::endl;
	}
	return 0;
}

HANDLE Task::start() {
	unsigned thread_id = 0;
	_hThread = (HANDLE)_beginthreadex(NULL, 1024 * 1024, thread_func, this, 0, &thread_id);
	return _hThread;
}

void Task::terminate()
{
	_terminate = true;
}

bool Task::is_terminated() const
{
	return _terminate;
}

void Task::wait_for_termination()
{
	WaitForSingleObject(_hThread, 1000);
	CloseHandle(_hThread);
	_hThread = 0;
}
