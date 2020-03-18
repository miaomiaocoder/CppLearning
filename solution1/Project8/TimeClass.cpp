#include<iostream>
#include "TimeClass.h"


//::叫做作用域运算符，表示initTime属于TimeClass类
void TimeClass::initTime(int tmphour, int tmpminute, int tmpsecond)
{
	Hour = tmphour; 
	Minute = tmpminute;
	Second = tmpsecond;
	initMillSecond(0);
}

void TimeClass::initMillSecond(int mls)
{
	MillSecond = mls;
}

TimeClass::TimeClass(int tmphour, int tmpminute, int tmpsecond)
{
	Hour = tmphour;
	Minute = tmpminute;
	Second = tmpsecond;
	initMillSecond(0);
	std::cout << "调用TimeClass::TimeClass(int tmphour, int tmpminute, int tmpsecond)构造函数" << std::endl;
}

TimeClass::TimeClass()
{
	Hour = 12;
	Minute = 59;
	Second = 58;
	initMillSecond(0);
	std::cout << "调用TimeClass::TimeClass()构造函数" << std::endl;
}

TimeClass::TimeClass(int tmphour)
{
	Hour = tmphour;
	Minute = 59;
	Second = 58;
	initMillSecond(0);
	std::cout << "调用TimeClass::TimeClass(int tmphour)构造函数" << std::endl;
}