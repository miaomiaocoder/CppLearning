#include<iostream>

#include"TimeClass.h"

using namespace std;

//void pfunc()const
//{
//	return;
//}
// 非成员函数上不允许修饰符	
//error

int main()
{
	//类定义中实现成员函数inline
	//这种直接在类的定义中实现的成员函数，会被当作inline内联函数处理

	//成员函数末尾的const
	//const：常量,在成员函数后边增加一个const
	//不但要在成员函数声明中增加const,也要在成员函数定义中增加const
	//作用：告诉系统，这个成员函数 不会修改该对象里任何成员变量的值
	//也就是说，这个成员函数不会修改类Time的任何状态
	//后边加一个const后缀的成员函数“常量成员函数”

	const TimeClass abc;//定义const对象。这种对象有限制
	//abc.initTime(15,34,60);//error
	//这个initTime只能被非const对象调用
	TimeClass der;
	der.initTime(123,32,32);
	//abc.noone();//errpe，不可以调用，因为noone()没有声明成const
	abc.noone2();

	//const成员函数，不管是const对象还是非const，都可以调用const成员函数
	//而非const成员函数，不能被const对象调用，只能被非const对象调用

	//mutable(不稳定)
	//mutable的引入为了突破const的限制
	//用mutable修饰一个成员变量，则表示这个成员变量永远处于可以被修改的状态
	//即便是const的结尾的成员函数中，也可以被修改
	
	//返回自身对象的引用,this
	//调用成员函数时，编译器负责把这个对象的地址(&mytime)传递给这个成员函数中隐藏的this形参
	//在系统看来，任何对类成员的直接访问都被看做是通过this做隐式调用
	//TimeClass mytime;
	//mytime.add_hour(3);
	//a. this指针只能在成员函数中使用，全局函数，静态函数中都不能使用this指针
	
	//b. 在普通成员函数中，this是一个指向非const对象的const指针
	//(类型为TimeClass, 那么this为TimeClass*const this)表示this只能当前TimeClass对象
	
	//c. 在const成员函数中，this指针是一个指向const对象的const指针
	//（类型为TimeClass, this 是const TimeClass *const this 类型的指针）
	//



	//TimeClass(15);
	TimeClass mytime;
	mytime.add_hour(3).add_minute(12);
	
	return 0;
}