/*************************************************************************
	> File Name: Events.h
	> Author: 
	> Mail: 
	> Created Time: 2016年08月17日 星期三 09时19分10秒
 ************************************************************************/

#ifndef _EVENTS_H
#define _EVENTS_H

#include<iostream>
#include<string>
#include<functional>
#include<map>

class NonCopyable
{
protected:
    NonCopyable() = default;
    ~NonCopyable() = default;
    NonCopyable(const NonCopyable&) = delete;
    NonCopyable& operator = (const NonCopyable) = delete;
};

template <typename Func>
class Events : NonCopyable
{
public:
    Events() {   }
    ~Events() {  }
    int Connect(Func && f)
    {
        return Assgin(f);
    }

    int Connect(const Func & f)
    {
        return Assgin(f);
    }

    void Disconnect(int key)
    {
        m_connections.erase(key);
    }

    template <typename ...Args>
    void Notify(Args... args)
    {
        for (auto item : m_connections)
        {
            item.second(std::forward<Args>(args)...);
        }
    }

private:
    template <typename F>
    int Assgin(F && f)
    {
        int k = m_observerId++;
        m_connections.emplace(k, std::forward<F>(f));
        return k;
    }

    int m_observerId = 0;
    std::map<int, Func> m_connections;
};

#endif
