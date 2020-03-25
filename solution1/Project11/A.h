#pragma once
#include"C.h"

//class C;//仅仅表示类C声明

class A
{
	friend void C::callCAF(int x, A &a);//该函数是友元成员函数的声明
private:
	int data;
	
};