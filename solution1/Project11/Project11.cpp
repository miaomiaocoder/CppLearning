// Project11.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include"Human.h"
#include"Men.h"


int main()
{
	//类之间有层次关系
	//把车类，当成父类(也叫基类，超类)， 派生出卡车，轿车，叫做子类(派生类)
	//有父类，子类，构成层次关系，叫继承。面向对象程序设计的核心思想之一
	//父类中定义一些公用的成员变量，成员函数
	//我们通过继承父类来构建新类：子类
	//所以写代码时只需要写和子类相关的内容即可
	//子类会比父类更加庞大


	//class Men :public Human //表示Men是Human的子类
	//class 子类名 :继承方式 父类名
	//继承方式（访问权限）public, protected, private
	
	//派生类对象定义时调用构造函数的顺序
	Men men;//当定义子类对象时，是要调用父类和子类的构造函数的，而且父类的构造函数的的函数体先执行，子类的构造函数的的函数体后执行

	//public, protected, private
	//



	return 0;
}


