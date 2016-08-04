/*************************************************************************
	> File Name: range.h
	> Author: 
	> Mail: 
	> Created Time: 2016年08月04日 星期四 17时11分35秒
 ************************************************************************/

#ifndef _RANGE_H
#define _RANGE_H

#include "impl.h"

template <typename T>
detail_range::impl<T> range(T end)
{
	return { { }, end, 1 };
}

template <typename T>
detail_range::impl<T> range(T begin, T end)
{
	return { begin, end, 1 };
}

template <typename T, typename U>
detail_range::impl<T> range(T begin, T end, U step)
{
	using r_t = detail_range::impl<decltype(begin + step)>;
	return r_t{ { }, end, 1 };
}

#endif