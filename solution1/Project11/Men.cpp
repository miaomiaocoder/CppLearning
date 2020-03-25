#include "Men.h"
#include<iostream>

Men::Men()
{
	//funcpro();
	std::cout << "执行了Men::Men()" << std::endl;
}



void Men::samenamefunc(int)
{
	Human::samenamefunc(12);//调用父类带参的
	Human::samenamefunc();//调用父类不带参
	std::cout << "执行了 Men::samenamefunc(int)" << std::endl;
}

void Men::eat()
{
	std::cout << "男人喜欢吃米饭" << std::endl;
};

Men::~Men()
{
	std::cout << "执行了Men::~Men()" << std::endl;
}


