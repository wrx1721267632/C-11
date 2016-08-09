/*************************************************************************
	> File Name: Find.h
	> Author: 
	> Mail: 
	> Created Time: 2016年08月09日 星期二 09时06分52秒
 ************************************************************************/

#ifndef _FIND_H
#define _FIND_H

namespace detail
{
	template<typename T, typename U>
	typename std::enable_if<std::is_convertible<T, U>::value || std::is_convertible<U,T>::value, bool>::type
			compare(T t, U u)
			{
				return t == u;
			}

	bool compare(...)
	{
		return false;
	}

    template<int I, typename T, typename... Args>
    struct find_index
    {
        static int call(std::tuple<Args...> const& t, T&& val)
        {
            return (compare(std::get<I - 1>(t), val) ? I - 1 :
                find_index<I - 1, T, Args...>::call(t, std::forward<T>(val)));
        }
    };

    template<typename T, typename... Args>
    struct find_index<0, T, Args...>
    {
        static int call(std::tuple<Args...> const& t, T&& val)
        {
            return (compare(std::get<0>(t), val) ? 0 : -1);
        }
    };
}

template<typename T, typename... Args>
int find_index(std::tuple<Args...> const& t, T&& val)
{
    return detail::find_index<sizeof...(Args), T, Args...>::call(t, std::forward<T>(val));
}

#endif