/*************************************************************************
	> File Name: thread_time.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年08月11日 星期四 19时41分49秒
 ************************************************************************/

#include<iostream>
#include<thread>
#include<mutex>
#include<chrono>
using namespace std;

std::timed_mutex mutex1;

void work()
{
	std::chrono::milliseconds timeout(100);

	while (true) {
		if (mutex1.try_lock_for(timeout)) {
			cout << this_thread::get_id() << ": do work with the mutex" << endl;
			std::chrono::milliseconds sleepDuration(250);
			this_thread::sleep_for(sleepDuration);
		} else {
			cout << this_thread::get_id() << ": do work without mutex" << endl;

			chrono::milliseconds sleepDuration(100);
			std::this_thread::sleep_for(sleepDuration);
		}
	}
}

int main()
{
	std::thread t1(work);
	std::thread t2(work);

	t1.join();
	t2.join();

	return 0;
}
