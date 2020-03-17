#include<iostream>
using namespace std;
int main()
{
	//隐式类型转换
	int m = 3 + 45.6;
	double n = 3 + 45.6;

	//二、显示类型转换（强制类型转换）
	//int k0 = 5 % 3.2;//语法错
	int k1 = 5 % (int)3.2;//c语言风格强制类型转换
	int k2 = 5 % int(3.2);//函数风格强制类型转换

	//c++强制类型转换
	//这4种强制类型转换，分别用于不同的目的。
	//1.static_cast
	//2.dynamic_cast
	//3.const_cast
	//4.reinterpret_cast
	//“命名的强制类型转换”
	//通用形式
	//强制类型转换名<type>(express);
	//强制类型转换名是1，2，3，4四个名字之一
	//type：转换的目标类型
	//express：你要转换的值
	
	//（1）static_cast :静态转换，‘正常转换’，编译时候进行类型转换检查
	//代码要保证转换的安全性和正确性，和c语言中的强制类型转换相似。
	//c风格转换，编译器的隐式转换都可以用static_cast完成
	//可用于：
	//a)相关类型转换，比如整型和实型之间的转换
	//double f = 100.34f;
	//int i1 = (int)f;//c风格
	//int i2 = static_cast<int>(f);//c++风格

	//b)把子类转成父类的对象
	class A{};
	class B:public A{};
	B b;
	A a = static_cast<A>(b);//把子类转成父类的对象
	//B b = static_cast<B>(a);//error

	//c)void *与其它类型指针之间的转换
	//void*无类型指针，可以指向任何类型
	int i = 10;
	int *p = &i;
	void *q = static_cast<void*>(p);//int*转成void*
	int *db = static_cast<int*>(q);//
	//不可用于
	//a）一般不能用于指针类型之间的转换比如int*转double*，float*转double*等等
	double f = 100.0f;
	double *pf = &f;
	//int *i = static_cast<int*>(pf);//error
	//float *fd = static_cast<float*>(pf);

	//(2)dynamic_cast:主要应用于运行时类型识别和检查
	//主要用来父类型和子类型转换
	//（使父类型指针指向子类型对象，然后用dynamic_cast把父指针类型往子指针类型转）

	//(3)const_cast去除指针，或者引用的const属性
	//该转换能将const性质转换掉，编译时进行类型转换

	const int ai = 90;
	//int ai2 = const_cast<int>(ai);//ai不是指针也不是引用
	//error

	const int*pai = &ai;
	int *pai2 = const_cast<int*>(pai);
	*pai2 = 120;
	//此写值行为是未定义行为。不要这么干
	cout << ai << endl;
	cout << *pai << endl;
	////调试时都是120,打印时90,120


	//const int ai = 90;
	//int *pai = (int*)&ai;
	//*pai = 120;//未定义行为
	//cout << ai << endl;
	//cout << *pai << endl;

	return 0;
}