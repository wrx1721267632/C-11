/*************************************************************************
	> File Name: Lazy.h
	> Author: 
	> Mail: 
	> Created Time: 2016年08月08日 星期一 09时37分12秒
 ************************************************************************/

#ifndef _LAZY_H
#define _LAZY_H

#include<functional>
#include"../Optional/Optional.h"
#include<iostream>
#include<utility>

template <typename T>
struct Lazy
{
	Lazy() { }
	template <typename Func, typename... Args>
	Lazy(Func&& f, Args && ...args)
	{
		m_func = [&f, &args...] {return f(args...);};
	}

	const T Value()
	{
		if (!m_value.IsInit())
		{
			m_value = m_func();
		}
	
		return *m_value;
	}

	bool IsValueCreated() const
	{
		return m_value.IsInit();
	}

private:
	std::function<T()> m_func;
	Optional<T> m_value;
};

template <class Func, typename... Args>
Lazy<typename std::result_of<Func(Args...)>::type> lazy(Func && fun, Args && ...args)
{
	return Lazy<typename std::result_of<Func(Args...)>::type>(std::forward<Func>(fun), std::forward<Args>(args)...);
}

#endif