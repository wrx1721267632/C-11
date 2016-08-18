/*************************************************************************
	> File Name: ObjectPool_test.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年08月17日 星期三 17时11分56秒
 ************************************************************************/

#include<iostream>
#include<unistd.h>
#include"ObjectPool.h"
using namespace std;

struct BigObject
{
	BigObject() {}
	BigObject(int a) { }
	BigObject(int a, int b) { }
	void Print(const string &str)
	{
		cout << str << endl;
	}
};

void Print(shared_ptr<BigObject> p, const string & str)
{
	if (p != nullptr)
	{
		p -> Print(str);
	}
}

void TestObjPool()
{
	ObjectPool<BigObject> pool;

	pool.Init(2);

	{
		auto p = pool.Get();
		Print(p, "p");
		auto p2 = pool.Get();
		Print(p2, "p2");
	}

	auto p = pool.Get();
	auto p2 = pool.Get();

	Print(p,"p");
	Print(p2, "p2");

	// pool.Init(2,1);
	// auto p4 = pool.Get<int>();
	// Print(p4,"p4");
	// pool.Init(2, 1, 2);
	// auto p5 = pool.Get<int, int>();
	// Print(p5, "p5");
}

int main() 
{
	while(1)
	{
		TestObjPool();
		usleep(100);		
	}
	TestObjPool();
	// cout << 1 << endl;
	return 0;
}