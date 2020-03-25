#include "C.h"
#include "A.h"
#include<iostream>

void C::callCAF(int x, A &a)
{
	a.data = x;
	std::cout << a.data << std::endl;
}

void C::callCAF2(int x, A &a)
{
	//a.data = x;//error
	//....
}