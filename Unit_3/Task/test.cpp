/*************************************************************************
	> File Name: test.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年08月08日 星期一 15时44分46秒
 ************************************************************************/

#include<iostream>
#include"Task.h"
using namespace std;

int main()
{
	Task<int(int)> task([](int i) {return i;} );
	auto result = task.Then([](int i){return i+1;}).Then([](int i){return i+2;}).Then([](int i){return i+3;}).Run(1);
	cout << result << endl;
	Task<int(int)> task1([](int i) {return i;} );
	auto result1 = task1.Then([](int i){return i+1;}).Then([](int i){return i+2;}).Then([](int i){return i+3;}).Run(2);
 	cout << result1 << endl;
 	Task<int(int)> task2([](int i) {return i;} );
 	auto result2 = task2.Then([](int i){return i+1;}).Then([](int i){return i+2;}).Run(1);
 	cout << result2 << endl;
 	Task<int(int)> task3([](int i) {return i;} );
 	auto result3 = task3.Run(1);
 	cout << result3 << endl;
}