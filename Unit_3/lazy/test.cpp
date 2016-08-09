/*************************************************************************
	> File Name: test.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年08月08日 星期一 09时51分45秒
 ************************************************************************/

#include<iostream>
#include<memory>
#include"Lazy.h"
using namespace std;

struct BigObj
{
	BigObj()
	{
		cout << "lazy load big object" << endl;
	}
};

struct MyStruct
{
	MyStruct()
	{
		m_obj = lazy([] { return std::make_shared<BigObj>(); });
	}

	void load()
	{
		//cout << 11 << endl;
		m_obj.Value();
	}

	Lazy<std::shared_ptr<BigObj>> m_obj;
};

int Foo(int x)
{
	return x * 2;
}

int main()
{
	int y = 4;
	auto lazyer1 = lazy(Foo, y);
	cout << lazyer1.Value() << endl;

	Lazy<int> lazyer2 = lazy([]{return 12;});
	cout << lazyer2.Value() << endl;

	std::function <int(int)> f = [](int x){return x + 3;};
	auto lazyer3 = lazy(f, 3);
	cout << lazyer3.Value() << endl;

	MyStruct t;
	t.load();

	return 0;
}
