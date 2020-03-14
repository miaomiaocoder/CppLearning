#include<iostream>
using namespace std;

//student.cpp
struct student {//结构具有缺省的public属性
	//成员变量
	int number;
	char name[100];
	void func()
	{
		number++;
		return;
	}
};

//void func(student temp)//形参用结构变量
//void func(student &temp)//引用
//{
//	temp.number = 2000;
//	strcpy_s(temp.name, sizeof(temp.name), "who");
//	return;
//}
void func1(student *temp)//指向结构体的指针
{
	temp->number = 2000;
	strcpy_s(temp->name, sizeof(temp->name), "who");
	return;
}

int main()
{
	student student1;//定义结构变量
	student1.number = 1001;
	strcpy_s(student1.name,sizeof(student1.name),"zhangsan");

	cout << student1.number << endl;
	cout << student1.name << endl;
	//func(student1);//效率低，因为实参传递给形参时，发生内存内容拷贝
	//func1(&student1);

	student1.func();//调用成员函数

	cout << student1.number << endl;
	cout << student1.name << endl;

	//cpp中结构和c中的结构区别
	//c++中的结构扩展，可以添加成员函数(方法)

	//类学习
	//c++定义一个属于该类的变量，我们叫对象
	//c++类内部的成员变量和函数，默认访问级别是private
	//c++结构体继承默认是public,类继承默认是private

	//类的组织，书写规范
	//类的定义代码放在一个.h文件中,头文件可以跟类名相同
	//类的具体实现代码，放在一个.cpp文件中
	return 0;
}