/*************************************************************************
	> File Name: thread_CPU.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年08月11日 星期四 11时24分15秒
 ************************************************************************/

#include<iostream>
#include<thread>
#include<unistd.h>
using namespace std;

void func()
{
    sleep(1);
}

int main()
{
    thread t(func);
    cout << t.get_id() << endl;
    t.join();

    cout << thread::hardware_concurrency() << endl;
    return 0;
}
