/*************************************************************************
	> File Name: ObjectPool.h
	> Author: 
	> Mail: 
	> Created Time: 2016年08月17日 星期三 15时24分34秒
 ************************************************************************/

#ifndef _OBJECTPOOL_H
#define _OBJECTPOOL_H

#include <string>
#include <functional>
#include <memory>
#include <map>

using namespace std;

class NonCopyable
{
protected:
	NonCopyable() = default;
	~NonCopyable() = default;
	NonCopyable(const NonCopyable&) = delete;
	NonCopyable& operator =(const NonCopyable &) = delete;
};

const int MaxObjectNum = 10;

template <typename T>
class ObjectPool : NonCopyable
{
	template <typename... Args>
	using Constructor = function<shared_ptr<T> (Args...)>;
private:
	multimap<string, shared_ptr<T>> m_object_map;

public:
	template <typename... Args>
	void Init(size_t num, Args ...args)
	{
		if (num <= 0 || num > MaxObjectNum)
		{
			throw std::logic_error("Object num out of range");
		}

		auto constructName = typeid(Constructor<Args...>).name();
		//out << "Init: " << constructName << endl;
		for (size_t i = 0; i < num; i++)
		{
			m_object_map.emplace(constructName, 
				shared_ptr<T>(new T(std::forward<Args>(args)...), [this, constructName](T *p)
			{
				cout << "dis: " << constructName << endl;
				m_object_map.emplace(std::move(constructName),shared_ptr<T>(p));
			}));
		}
	}

	template <typename... Args>
	std::shared_ptr<T> Get()
	{
		string constructName = typeid(Constructor<Args...>).name();
		cout << constructName << endl;
		auto range = m_object_map.equal_range(constructName);
		for (auto it = range.first; it != range.second; it++)
		{
			auto ptr = it -> second;
			m_object_map.erase(it);
			return ptr;
		} 

		return nullptr;
	}
};

#endif