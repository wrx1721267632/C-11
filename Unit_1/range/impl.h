/*************************************************************************
	> File Name: impl.h
	> Author: 
	> Mail: 
	> Created Time: 2016年08月04日 星期四 16时41分29秒
 ************************************************************************/

#ifndef _IMPL_H
#define _IMPL_H

#include "iterator.h"
namespace detail_range{

template <typename T>
class impl
{
public:
	using value_type = T;
	using reference = const value_type&;
	using const_reference = const value_type&;
	using iterator = const detail_range::iterator<value_type>;
	using const_iterator = const detail_range::iterator<value_type>;
	using size_type = typename iterator::size_type;

private:
	const value_type begin_;        //迭代器中begin的值
	const value_type end_;          //迭代器中end的值
    const value_type step_;         //代步长
	const size_type  max_count_;    //迭代次数

	size_type get_adjusted_count(void) const
	{
		if (step_ > 0 && begin_ >= end_)
			throw std::logic_error("END value must be greater than begin value.");

		if (step_ < 0 && begin_ <= end_)
			throw std::logic_error("END value must be less than begin value");

		size_type x = static_cast<size_type>((end_ - begin_) / step_);
		if (begin_ + (step_ * x) != end_) 
		{
			++x;
		} 
		return x;
	}

public:
	impl(value_type begin_val, value_type end_val, value_type step_val)
		:begin_(begin_val), end_(end_val), step_(step_val), max_count_(get_adjusted_count())
	{ }

	size_type szie(void) const
	{
		return max_count_;
	}

	const_iterator begin(void) const 
	{
		return { 0, begin_, step_ };
	}

	const_iterator end(void) const
	{
		return { max_count_, begin_, step_ };
	}
};

}

#endif
