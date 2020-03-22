#pragma once
class Time
{
public:
	int Hour;
	int Minute;
	int Second = 10;


	char *p;
public:
	//构造函数
	Time(int tmphour, int tmpminute, int tmpsecond = 12);
	explicit Time(int tmphour);
	Time();

	//拷贝构造函数
	Time(const Time&tmptime, int a = 50);


	Time & operator =(const Time& tmpobj);//重载的赋值运算符

	~Time();
};

