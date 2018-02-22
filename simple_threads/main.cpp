#include <iostream>
#include <thread>
#include "Task.h"

using namespace std;

void task_a(Task t){
	t.start();
}

void task_b(Task t) {
	Sleep(500);
	t.start();
}

void main(int, char**) {
	task_a(Task(0));
	task_b(Task(1));

	Sleep(10000);
	system("PAUSE");
}



/*auto thread_a = []() {
	for (int i = 0; i < 10; ++i) {
		this_thread::sleep_for(chrono::seconds(1));
		cout << "Task A at:" << i << endl;
	}
};

auto thread_b = []() {
	// this_thread::sleep_for(chrono::milliseconds(500));
	for (int i = 0; i < 10; ++i) {
		this_thread::sleep_for(chrono::seconds(1));
		cout << "Task B at:" << i << endl;
	}
};

void main(int, char**) {

thread task_a, task_b;

task_a = thread(thread_a);
task_b = thread(thread_b);

task_a.join();
task_b.join();

system("PAUSE");
}*/