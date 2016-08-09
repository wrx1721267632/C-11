/*************************************************************************
	> File Name: Find.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年08月09日 星期二 09时11分26秒
 ************************************************************************/

#include<iostream>
#include<tuple>
#include"Find.h"
using namespace std;

int main()
{
	std::tuple<int, double, string> tp = std::make_tuple(1,2,"ok");
	//cout << tp.get<0>() << endl;
	string a = "ok";
	int index = find_index(tp, a);
	cout << index << endl;
	return 0;
}