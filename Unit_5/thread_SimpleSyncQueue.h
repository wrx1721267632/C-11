/*************************************************************************
	> File Name: thread_SimpleSyncQueue.h
	> Author: 
	> Mail: 
	> Created Time: 2016年08月11日 星期四 22时05分24秒
 ************************************************************************/

#ifndef _THREAD_SIMPLESYNCQUEUE_H
#define _THREAD_SIMPLESYNCQUEUE_H

#include<thread>
#include<condition_variable>
#include<mutex>
#include<list>
#include<iostream>

template<typename T>
class SimpleSyncQueue
{
private:
	std::list<T> m_queue;
	std::mutex m_mutex;
	std::condition_variable m_notEmpty;
public:
	SimpleSyncQueue() { }

	void Put(const T &x)
	{
		std::lock_guard<std::mutex> locker(m_mutex);
		m.queue.push_back(x);
		m_notEmpty.notify_one();
	}

	void Take(T &x)
	{
		std::unique_lock<std::mutex> locker(m_mutex);
		m_notEmpty.wait(locker, [this] {return !m_queue.empty();});
		x = m_queue.front();
		m_queue.pop_front();
	}

	bool Empty()
	{
		std::lock_guard<std::mutex> locker(m_mutex);
		return m_queue.empty();
	}

	size_t Size()
	{
		std::lock_guard<std::mutex> locker(m_mutex);
		return m_queue.size();
	}
};

#endif
