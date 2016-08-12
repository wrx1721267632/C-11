/*************************************************************************
	> File Name: thread_SyncQueue.h
	> Author: 
	> Mail: 
	> Created Time: 2016年08月11日 星期四 21时46分13秒
 ************************************************************************/

#ifndef _THREAD_SYNCQUEUE_H
#define _THREAD_SYNCQUEUE_H

#include<iostream>
#include<thread>
#include<mutex>
#include<condition_variable>
#include<list>
using namespace std;

template <typename T>
class SyncQueue
{
private:
    std::list<T> m_queue;
    std::mutex m_mutex;
    std::condition_variable_any m_notFull;
    std::condition_variable_any m_notEmpty;
    int m_maxsize;

    bool IsFull()
    {
        return m_queue.size() == m_maxsize;
    }

    bool IsEmpty()
    {
        return m_queue.empty();
    }
public:
    SyncQueue(int max):m_maxsize(max) {  }
    void Put(const T& x)
    {
        std::lock_guard<std::mutex> locker(m_mutex);

        while (IsFull())
        {
            std::cout << "data Full" << std::endl;
            m_notFull.wait(m_mutex);
        }
        m_queue.push_back(x);
        m_notEmpty.notify_one();
    }

    void Take(T& x)
    {
        std:lock_guard<std::mutex> locker(m_mutex);

        while(IsEmpty())
        {
            std::cout << "data Empty" << std::endl;
            m_notEmpty.wait(m_mutex);
        }
        x = m_queue.front();
        m_queue.pop_front();
        m_notFull.notify_one();
    }

    bool Empty()
    {
        std::lock_guard<std::mutex> locker(m_mutex);
        return m_queue.empty();
    }

    bool Full()
    {
        std::lock_guard<std::mutex> locker(m_mutex);
        return m_queue.size() == m_maxsize;
    }

    size_t Size()
    {
        std::lock_guard<std::mutex> locker(m_mutex);
        return m_queue.size();
    }
};

#endif