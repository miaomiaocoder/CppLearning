#include<iostream>
#include"head.h"
using namespace std;


//类和结构体初步学习

//student.cpp
//struct student {//结构具有缺省的public属性
//	//成员变量
//	int number;
//	char name[100];
//	void func()
//	{
//		number++;
//		return;
//	}
//};

//void func(student temp)//形参用结构变量
//void func(student &temp)//引用
//{
//	temp.number = 2000;
//	strcpy_s(temp.name, sizeof(temp.name), "who");
//	return;
//}
//void func1(student *temp)//指向结构体的指针
//{
//	temp->number = 2000;
//	strcpy_s(temp->name, sizeof(temp->name), "who");
//	return;
//}



//内联函数

//inline int myfunc(int testv) //函数定义前加inline，内联函数
//{
//	return 1;
//}
//
//constexpr int a()
//{
//	//尽量特别简单
//}


//函数奇怪用法

//void func1()
//{
//
//}
//
//void func2()
//{
//	//return;
//	return func1();//this is ok
//}



//函数指针和引用

//int *myfunc()
//{
//	int tempvalue = 9;
//	return &tempvalue; //this is 错误
//	//函数执行完一hi，tempvalue这段内存已经被系统回收
//}

//int &myfunc()
//{
//	int tempvalue = 9;
//	cout << &tempvalue << endl;
//	return tempvalue;//巨大隐患
//}

//
//int myfunc(void)
//{
//	return 1;
//}


int main()
{
	//student student1;//定义结构变量
	//student1.number = 1001;
	//strcpy_s(student1.name,sizeof(student1.name),"zhangsan");

	//cout << student1.number << endl;
	//cout << student1.name << endl;
	////func(student1);//效率低，因为实参传递给形参时，发生内存内容拷贝
	////func1(&student1);

	//student1.func();//调用成员函数

	//cout << student1.number << endl;
	//cout << student1.name << endl;

	//cpp中结构和c中的结构区别
	//c++中的结构扩展，可以添加成员函数(方法)

	//类学习
	//c++定义一个属于该类的变量，我们叫对象
	//c++类内部的成员变量和函数，默认访问级别是private
	//c++结构体继承默认是public,类继承默认是private

	//类的组织，书写规范
	//类的定义代码放在一个.h文件中,头文件可以跟类名相同
	//类的具体实现代码，放在一个.cpp文件中



	//内联函数
	//在函数定义前inline
	//函数体很小，调用很频繁
	//1.inline影响编译器，编译阶段，系统尝试将调用该函数的动作替换为函数本体，来提升性能
	//int a = myfunc(5); //int a = 1;
	//cout << a << endl;
	//2.inline只是开发者对编译器建议，取决于编译器诊断功能
	//3.内联函数的定义放在头文件中。这样需要用到这个内联函数的.cpp文件都能通过#inlcude把这个内联函数源代码 #include""进来
	//以便找到这个函数本体源代码并替换
	
	//优缺点
	//代码膨胀，所以内联函数函数体尽量小


	//函数奇怪用法
	//1.函数返回类型为void,表示函数不返回任何类型。
	//但是我们可以调用一个返回类型是void的函数，让它作为另一个返回类型是void的函数
	
	//2.函数返回指针和引用
	//int *p = myfunc();
	//*p = 6;//往一个不属于自己的内存赋值，极大错误

	//int&k = myfunc();
	//cout << &k << endl;
	//k = 10;//往一个不属于自己的内存赋值，极大错误

	//int k = myfunc();
	//cout << &k << endl;
	//k = 10; //安全

	//3.没有形参可以保持形参列表为空(),或者int myfunc(void)

	//4.如果一个函数不调用，可以只有声明部分

	//5.普通函数只能定义一次（放在.cpp文件），声明可以多次
	//一般函数定义所在的.cpp文件会#include声明所在的.h文件
	
	//6.void func(int &a ,int &b)在c++更习惯使用引用类型的形参取代指针类型的的形参


	//7.c++，函数允许同名，但是形参列表的参数类型和数量应该有明显不同


	//const char* 、 char const * 、char * const区别
	
	//const char *p;
	
	//char str[] = "i hello world!" ;  //char str[]{ "hello world!" };
	//const char *p;//p指向的目标不能通过p来修改
	//p = str;
	////*p = 'y';//语法错误
	//p++;
	//str[0] = 'y';


	//char const *p 等价于 const char *p

	////char * const
	//char str[] = "i helle world";
	//char * const p = str;    //定义时候必须初始化
	//    //p指向一个东西以后，就不可以指向其它东西
	////p++;//报错
	//*p = 'Y';    //但是可以修改p指向的目标中的内容
	//
	//const char * const p = str;   //等价于下一行的那种写法
	//char const * const p = str;
	//     //p指向不能变。p指向的内容也不能改变。
	//
	//int i = 100;
	//const int &a = i;    //代表a的内容不能通过a自己修改
	//i = 100;
	////a = 500;//error

	////int &b = 31;//error
	//const int &b = 31;//分配了内存
	//cout << b << endl;


	//函数形参中带const
	
	return 0;
}