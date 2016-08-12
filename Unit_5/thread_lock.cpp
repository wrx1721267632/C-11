/*************************************************************************
	> File Name: thread_lock.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年08月11日 星期四 11时58分59秒
 ************************************************************************/

#include<iostream>
#include<thread>
#include<mutex>
using namespace std;

std::mutex g_lock;

void func()
{
    g_lock.lock();
    cout << "in id: " << this_thread::get_id() << endl;
    this_thread::sleep_for(chrono::seconds(1));
    cout << "out id: " << this_thread::get_id() << endl;
    g_lock.unlock();
}

void f()
{
    lock_guard<std::mutex> lock(g_lock);
    cout << "in id: " << this_thread::get_id() << endl;
    this_thread::sleep_for(chrono::seconds(1));
    cout << "out id: " << this_thread::get_id() << endl;
}

int main()
{
    std::thread t1(func);
    std::thread t2(func);
    std::thread t3(func);

    t1.join();
    t2.join();
    t3.join();

    std::thread t4(f);
    std::thread t5(f);
    std::thread t6(f);

    t4.join();
    t5.join();
    t6.join();
}
