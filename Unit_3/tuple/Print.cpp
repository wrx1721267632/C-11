/*************************************************************************
	> File Name: Print.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年08月09日 星期二 09时02分26秒
 ************************************************************************/

#include<tuple>
#include<iostream>
#include"Print.h"
using namespace std;

int main()
{
	std::tuple<int, short, double, char> tp = std::make_tuple(1,2,3, 'a');
	PrintTuple(tp);
}