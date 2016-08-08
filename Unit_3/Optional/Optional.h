/*************************************************************************
	> File Name: Optional.h
	> Author: 
	> Mail: 
	> Created Time: 2016年08月06日 星期六 10时29分30秒
 ************************************************************************/

#ifndef _OPTIONAL_H
#define _OPTIONAL_H

#include<type_traits>

template <typename T>
class Optional
{
	using data_t = typename std::aligned_storage<sizeof(T), std::alignment_of<T>::value>::type;
public:
	Optional() { }
	Optional(const T& v)
	{
		Create(v);
	}

	Optional(const Optional &other)
	{
		if (other.IsInit())
			Assign(other);
	}

	~Optional()
	{
		Destory();
	}

	template <class... Args>
	void Emplace(Args&&... args)
	{
		Destory();
		Create(std::forward<Args>(args)...);
	}

	bool IsInit() const { return m_hasInit; }

	explicit operator bool () const
	{
		return IsInit();
	}

	T const & operator*() const
	{
		if ( IsInit() )
		{
			return *((T*)(&m_data));
		}
		throw std::logic_error("is not init");
	}

private:
	template<class ...Args>
	void Create(Args&&... args)
	{
		new (&m_data) T(std::forward<Args>(args)...);
		m_hasInit = true;
	}

	void Destory()
	{
		if (m_hasInit)
		{
			m_hasInit = false;
			((T*)(&m_data)) -> ~T();
		}
	}

	void Assign(const Optional& other)
	{
		if (other.IsInit())
		{
			Copy(other.m_data);
			m_hasInit = true;
		}
		else 
		{
			Destory();
		}
 	}

 	void Copy(const data_t &val)
 	{
 		Destory();
 		new (&m_data) T(*((T*)(&val)));
 	}

 private:
 	bool m_hasInit = false;
 	data_t m_data;
};

#endif