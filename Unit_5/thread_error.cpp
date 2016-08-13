/*************************************************************************
	> File Name: thread_error.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年08月11日 星期四 10时53分45秒
 ************************************************************************/

#include<iostream>
#include<thread>
#include<chrono>
using namespace std;

void func(int a, int b, int c)
{
    std::this_thread::sleep_for(std::chrono::seconds(3));
    cout << a << " " << b << " " << c << endl;
}

int main()
{
    std::thread t1(func, 1, 2, 3);
    t1.join();
    std::thread t2(func, 2, 3, 4);
    t2.detach();
    cout << "after t2 ,main is runing" << endl;
    //std::thread t3(func, 3, 4, 5);
    std::thread t4([](int a, int b, int c){std::this_thread::sleep_for(std::chrono::seconds(5)); cout << a << " " << b << " " << c << endl;}, 4,5,6);
    t4.join();

    cout << "CPU: " << thread::hardware_concurrency() << endl;
    
    return 0;
}
