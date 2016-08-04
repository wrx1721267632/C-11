/*************************************************************************
	> File Name: range.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年08月04日 星期四 17时16分16秒
 ************************************************************************/

#include<iostream>
#include"range.h"
using namespace std;

void test_range()
{
	std::cout << "range(15):" ;
	for (int i : range(15))
	{
		std::cout << " " << i;
	}
	std::cout << std::endl;

	std::cout << "range(2, 6):" ;
	for (int i : range(2, 6))
	{
		std::cout << " " << i;
	}
	std::cout << std::endl;

	std::cout << "range(2, 6, 2):" ;
	for (int i : range(2, 6, 2))
	{
		std::cout << " " << i;
	}
	std::cout << std::endl;}

int main()
{
	test_range();

	return 0;
}