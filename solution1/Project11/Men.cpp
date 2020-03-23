#include "Men.h"
#include<iostream>

Men::Men()
{
	//funcpro();
	//std::cout << "执行了men::men()" << std::endl;
}



void Men::samenamefunc(int)
{
	Human::samenamefunc(12);//调用父类带参的
	Human::samenamefunc();//调用父类不带参
	std::cout << "执行了 Men::samenamefunc(int)" << std::endl;
}