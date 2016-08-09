/*************************************************************************
	> File Name: a.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年08月08日 星期一 14时50分45秒
 ************************************************************************/

#include<iostream>
using namespace std;

int main()
{
	auto t = create_task([]()->int{ return 0; });

	auto incrememt = [](int n) { return n + 1; };

	int result = t.then(incrememt).then(incrememt).then(incrememt).get();

	return 0;
}