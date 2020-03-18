#include<iostream>

//decltype 类型说明符生成指定表达式的类型。 decltype 类型说明符与 auto 关键字一起主要对编写模板库的开发人员有用。
//使用 auto 和 decltype 声明其返回类型取决于其模板参数类型的模板函数。 
//或者，使用 auto 和 decltype 声明包装对其他函数的调用，然后返回包装函数的返回类型的模板函数。
//decltype(expression) expression是一个表达式
int main()
{/*
	int var;
	const int && fx();
	struct A { double x; };
	const A*a = new A();

	decltype(fx());  //const int&&对 左值引用 的const int。
	decltype(var);   //int 变量 var 的类型。
	decltype(a->x);  //double成员访问的类型。
	decltype((a->x));*/   //const 
						  //double&
	//内部括号导致语句作为表达式而不是成员访问计算。 由于 a 声明为 const 指针，因此类型是对 const double 的引用。
	



}