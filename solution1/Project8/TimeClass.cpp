#include<iostream>
#include "TimeClass.h"

int TimeClass::mystatic = 15;

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
	:Hour(tmphour), Minute(tmpminute), Second(tmpsecond), MillSecond(0), ctestvalue(80)//构造函数初始化列表
{
	/*Hour = tmphour;
	Minute = tmpminute;
	Second = tmpsecond;
	initMillSecond(0);*/

	std::cout << "调用TimeClass::TimeClass(int tmphour, int tmpminute, int tmpsecond)构造函数" << std::endl;
}

//TimeClass::TimeClass():ctestvalue(80)
//{
//	Hour = 12;
//	Minute = 59;
//	Second = 58;
//	initMillSecond(0);
//	std::cout << "调用TimeClass::TimeClass()构造函数" << std::endl;
//}

TimeClass::TimeClass(int tmphour):ctestvalue(80)
{
	Hour = tmphour;
	this->Hour = 12;
	Minute = 59;
	Second = 58;
	initMillSecond(0);
	std::cout << "调用TimeClass::TimeClass(int tmphour)构造函数" << std::endl;
}

void TimeClass::addhour(int tmphour)const 
{
	//Minute = tmphour;//error
}

TimeClass& TimeClass::add_hour(int tmphour)
{
	Hour += tmphour;

	this->Hour;
	return *this;//把对象自己返回去
}

TimeClass& TimeClass:: add_minute(int Minute)
{
	this->Minute += Minute;
	return*this;
}

void TimeClass::mstafunc(int testvalue)
{
	//Minute = 12; //error
	mystatic = testvalue;//ok
}

//普通函数，不是成员函数
void WriteTimeClass(TimeClass &mytime)
{
	std::cout << mytime.Hour << std::endl;
}


TimeClass::TimeClass(const TimeClass&tmptime, int a):ctestvalue(80),Hour(50),Minute(40)
{
	std::cout << "调用TimeClass::TimeClass(TimeClass&tmptime, int a)拷贝构造函数" << std::endl;
}