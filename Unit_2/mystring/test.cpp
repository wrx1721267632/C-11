/*************************************************************************
	> File Name: test.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年08月05日 星期五 11时11分37秒
 ************************************************************************/

#include<iostream>
#include<vector>
#include"MyString.h"
using namespace std;

int main()
{
	MyString a;
	a = MyString("hello");
	std::vector<MyString> vec;
	vec.push_back(MyString("World"));
}