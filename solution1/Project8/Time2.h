
#ifndef _MYTIME2_
#define _MYTIME2_
class Otherclass
{
public:
	Otherclass(int) {};
};

class Time2
{
public:
	//explicit Time2();
	
	//Tim2(int) {};


	//Time2() {};
	//Time2() = default;//编译能够为这种 =default的函数自动生成函数体

	//int pfunc() = default; //非特殊函数，不可使用 = default

	//Time2() = delete;//让程序元显示的禁用某个函数
public:
	int Hour;
	int Minute;
	int Second{0};

	//Otherclass oc1;
};
#endif // !_MYTIME2_

