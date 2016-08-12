/*************************************************************************
	> File Name: thread_sleep.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年08月11日 星期四 11时28分28秒
 ************************************************************************/

#include<iostream>
#include<thread>
using namespace std;

void f()
{
    this_thread::sleep_for(chrono::seconds(3));
    cout << "time out" << endl;
}

int main()
{
    thread t(f);
    t.join();
}
