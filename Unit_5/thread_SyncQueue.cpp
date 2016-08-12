/*************************************************************************
	> File Name: thread_SyncQueue.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年08月11日 星期四 21时50分26秒
 ************************************************************************/

#include<iostream>
#include"./thread_SyncQueue.h"
#include<unistd.h>
#include<vector>
using namespace std;

void func(SyncQueue<int> *sq)
{
    int ret;
    sq->Take(ret);
    std::cout << ret << std::endl;
}

int main(int argc, char *argv[])
{
    //创建线程队列，长度最大为20
    SyncQueue<int>syn(20);
    //放置数据对象
    for(int i = 0; i < 10; i++)
    {
        syn.Put(i);
    }
    std::cout << syn.Size() << std::endl;

    //线程不能拷贝，用容器和智能指针来管理线程生存
    std::vector<std::shared_ptr<std::thread>> tvec;
    //多循环一次，资源不足，阻塞最后一个线程，在后面添加一个资源，看该线程是否会被唤醒执行。
    for(int i = 0; i < 11; i++)
    {
        //创建线程并且将管理线程的智能指针保存到容器中
        tvec.push_back(std::make_shared<std::thread>(func, &syn));
        //变为后台线程
        tvec[i]->detach();
    }
    sleep(10);
    //添加一个资源
    syn.Put(10);
    sleep(10);

    return 1;
}