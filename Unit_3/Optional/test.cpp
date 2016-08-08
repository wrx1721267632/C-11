/*************************************************************************
	> File Name: test.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年08月08日 星期一 08时51分01秒
 ************************************************************************/

#include<iostream>
#include"Optional.h"
#include<string>
using namespace std;

struct MyStruct
{
	MyStruct(int a, int b):m_a(a), m_b(b) { }
	int m_a;
	int m_b;
};

int main()
{
	Optional<string> a("ok");
	Optional<string> b("ok");
	Optional<string> c("aa");

	c = a;
	Optional<MyStruct> op;
	op.Emplace(1,2);
	Optional<MyStruct> t;
	if (op)
		t = *op;

	op.Emplace(3,4);
	t = *op;
}