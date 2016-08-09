/*************************************************************************
	> File Name: Task.h
	> Author: 
	> Mail: 
	> Created Time: 2016年08月08日 星期一 15时22分09秒
 ************************************************************************/

#ifndef _TASK_H
#define _TASK_H

#include<iostream>
#include<functional>
#include<type_traits>

template<typename T>
class Task;

template<typename R, typename ...Args>
class Task<R(Args...)>
{
public:
	Task(std::function<R(Args...)>&& f):m_fn(std::move(f)){ }
	Task(std::function<R(Args...)>& f):m_fn(f) { }

	R Run(Args&&...args)
	{
		return m_fn(std::forward<Args>(args)...);
	}

	template<typename F>
	auto Then(F&&f)->Task<typename std::result_of<F(R)>::type(Args...)>
	{
		using return_type = typename std::result_of<F(R)>::type;

		auto func = std::move(m_fn);
		return Task<return_type(Args...)>([func, &f](Args&&...args){ return f(func(std::forward<Args>(args)...)); });
	}

private:
	std::function<R(Args...)> m_fn;
};

#endif