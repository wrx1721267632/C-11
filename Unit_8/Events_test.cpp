/*************************************************************************
	> File Name: Events_test.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年08月17日 星期三 09时43分32秒
 ************************************************************************/

#include<iostream>
#include"./Events.h"
using namespace std;

struct stA 
{
    int a,b;
    void Print(int a, int b) { cout << "stA: " << a << ", " << b << endl; }
};

void Print(int a, int b) { cout << a << ", " << b << endl; }

int main()
{
    Events<std::function<void(int, int)>> my_events;

    auto key = my_events.Connect(Print);
    stA t;
    auto lambdakey = my_events.Connect([&t](int a, int b){ t.a = a; t.b = b; });
    std::function<void(int, int)> f = std::bind(&stA::Print, &t, std::placeholders::_1, std::placeholders::_2);
    my_events.Connect(f);
    int a = 1, b = 2;
    
    cout << "111" << endl;
    my_events.Notify(a, b);
    my_events.Disconnect(key);
    return 0;
}
