/*************************************************************************
	> File Name: thread_move.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年08月11日 星期四 10时59分26秒
 ************************************************************************/

#include<iostream>
#include<thread>
#include<unistd.h>
using namespace std;

void func()
{
    sleep(3);
    cout << " this is func" << endl;
}

int main()
{
    std::thread t(func);
    std::thread t1(std::move(t));
    // t.join();
    t1.join();

    return 0;
}
