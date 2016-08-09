/*************************************************************************
	> File Name: Print.h
	> Author: 
	> Mail: 
	> Created Time: 2016年08月09日 星期二 09时01分12秒
 ************************************************************************/

#ifndef _PRINT_H
#define _PRINT_H

template<class Tuple, std::size_t N>
struct TuplePrinter {
    static void print(const Tuple& t)
    {
        TuplePrinter<Tuple, N - 1>::print(t);
        std::cout << ", " << std::get<N - 1>(t);
    }
};

template<class Tuple>
struct TuplePrinter<Tuple, 1>{
    static void print(const Tuple& t)
    {
        std::cout << std::get<0>(t);
    }
};

template<class... Args>
void PrintTuple(const std::tuple<Args...>& t)
{
    std::cout << "(";
    TuplePrinter<decltype(t), sizeof...(Args)>::print(t);
    std::cout << ")\n";
}

#endif