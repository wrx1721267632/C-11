/*************************************************************************
	> File Name: thread_atmoic.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年08月13日 星期六 11时16分08秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <atomic>
#include <thread>
#include <vector>
#include <iostream>

//创建int类型的原子变量
std::atomic<int>atc(0);

void func()
{
    std::cout << atc << std::endl;
    //原子变量自增
    atc++;
}

int main(int argc, char *argv[])
{
    std::vector<std::thread>tvec;
    for(int i = 0; i < 10; i++)
    {
        std::thread t(func);
        //线程对象移动语义
        tvec.push_back(std::move(t));
        tvec[i].join();
    }

    return EXIT_SUCCESS;
}
