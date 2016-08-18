/*************************************************************************
	> File Name: thread_pool_test.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年08月17日 星期三 23时10分51秒
 ************************************************************************/

#include<iostream>
#include"thread_pool.h"
using namespace std;

int main()
{
	ThreadPool pool(2);

	//pool.Start(2);
	std::thread thd1([&pool]
	{
		for (int i = 0; i < 10; i++)
		{
			auto thdId = this_thread::get_id();
			pool.AddTask([thdId]
			{
				cout << "1.thread id: " << thdId << endl;
			});
		}
	});
	std::thread thd2([&pool]
	{
		for (int i = 0; i < 10; i++)
		{
			auto thdId = this_thread::get_id();
			pool.AddTask([thdId]
			{
				cout << "2.thread id: " << thdId << endl;
			});
		}
	});

	this_thread::sleep_for(std::chrono::seconds(2));
	getchar();
	pool.Stop();
	thd1.join();
	thd2.join();
}