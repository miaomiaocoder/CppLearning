#include "Time.h"
#include<iostream>


Time::Time(int tmphour, int tmpminute, int tmpsecond):Hour(tmphour),Minute(tmpminute), Second(tmpsecond)
{
	std::cout << "调用Time::Time(int tmphour, int tmpminute, int tmpsecond)构造函数" << std::endl;
}

Time::Time(int tmphour)
{
	std::cout << "调用Time::Time(int tmphour)构造函数" << std::endl;
}

Time::Time()
{
	std::cout << "调用Time::Time()构造函数" << std::endl;

	p = new char[100];
}

Time::Time(const Time&tmptime, int a):Hour(50),Minute(40)
{
	std::cout << "调用Time::Time(const Time&tmptime, int a)拷贝构造函数" << std::endl;
}

//赋值运算符重载
Time& Time:: operator =(const Time& tmpobj)
{
	Hour = tmpobj.Hour;
	Minute = tmpobj.Minute;
	Second = tmpobj.Second;
	//...

	std::cout << "调用Time& Time:: operator =(const Time& tmpobj)赋值运算符重载" << std::endl;
	return *this;//把对象自身返回去
}

Time::~Time()
{
	delete[] p;
	std::cout << "调用了Time::~Time()析构函数" << std::endl;
}