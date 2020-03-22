#include<iostream>
#include"Time2.h"
#include"TimeClass.h"

using namespace std;


int main()
{
	//拷贝构造函数
	//默认情况下，类对象的拷贝是每个成员变量逐个拷贝
	//如果一个类的构造函数的第一个参数是所属的类类型引用。如果有其它额外参数，那么这些额外参数都有默认值，则这个函数叫做拷贝构造函数
	//函数默认参数必须放在函数声明中，除非该函数没有函数声明
	//拷贝函数的作用:会在一定的时机，被系统调用
	TimeClass myTime;//调用默认构造函数
	cout << endl;
	TimeClass myTime2 = myTime;
	TimeClass myTime3(myTime);
	TimeClass myTime4{ myTime };
	TimeClass myTime5 = { myTime };
	
	//TimeClass myTime6;
	//myTime6 = myTime5;
	


	return 0;
}