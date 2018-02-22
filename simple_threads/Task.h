#pragma once
#include <Windows.h>
#include <process.h>

class Task
{
public:
	Task(int);
	~Task();
	
	// functions
	int run();

	HANDLE start();

	void terminate();
	bool is_terminated() const;

	void wait_for_termination();

private:
	HANDLE _hThread;
	int _id;
	bool _terminate;

	static unsigned __stdcall thread_func(void *param) {
		if (param) {
			return ((Task*)param)->run();
		}
		else {
			return 1;  // return error
		}
	}
};

