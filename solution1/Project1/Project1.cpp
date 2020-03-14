// Project1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include<cstdio>
#include"project3.h"
#include"head1.h"
#include"head2.h"
//namespace zhangsan
//{
//	void radius() {
//		printf("hello");
//	}
//}
constexpr int func(int x)
{
	return 5;
}

//网易云课程c++学习

using namespace std;
int main()
{
	/*int i = 3;
	std::cout << i-- << i--;
    std::cout << "Hello World!\n"<<std::endl;
	lisi::radius();*/
	/*int abc{ 5 };
	std::cout << abc << std::endl;*/

	/*std::cout <<g_global1 <<std::endl;*/


	//一.范围for语句
	//int v[] = {1,22,33,444,42541};
	//for (auto x : v)
	//{
	//	cout << x << endl;
	//}
	//for (auto &x : v)//省了拷贝动作，提高效率
	//{
	//	cout << x << endl;
	//}

	/*for (auto x : {"a","y","x"})
	{
		cout << x << endl;
	}

	for (auto x : { 1,2,3,4,5 })
	{
		cout << x << endl;
	}*/

	/*constexpr int var = 1;
	int b = 5;
	constexpr int var2 = func(11);
	return 0;*/


	//二：动态内存分配 c中供程序使用的存储空间，有程序区，静态存储区，动态存储区
	//c++（1）栈 函数举报变量 ， 由编译器自动分配和释放
	//（2）堆malloc/new, free/delete
	//(3)全局/静态存储区：全局变量和静态变量static
	//（4）常量存储区
	//（5）程序代码区

	//堆和栈区别
	//1.栈空间有限的。 int a= 4分配快
	//2.堆：只要不超出实际拥有的物理内存，也在操作系统允许分配的最大内存，都可以分配，分配速度比栈慢
	
	
	//c语言中,malloc和free,malloc,free是函数
	//malloc(memory allocation)
	//一般形式：

	//void *malloc(int NumBytes);//NumBytes:要分配的字节数

	//如果分配成功返回被分配的内存的指针，分配失败则返回NULL
	
	//free
	//void free(void *FirstByte)

	//int *p = NULL;//c语言写法 等价于数字0
	//p = (int*)malloc(sizeof(int));//在堆中分配四个字节
	//if (p != NULL) {
	//	//分配成功
	//	*p = 5;
	//	cout << *p << endl;
	//	free(p);
	//}

	//char*point = NULL;
	//point = (char*)malloc(100*sizeof(char));
	//if (point != NULL)
	//{
	//	strcpy_s(point,100,"hello world!");
	//	cout << point << endl;
	//	free(point);
	//}

	int*p = (int *)malloc(sizeof(int) * 100);
	if (p != NULL)
	{
		int *q = p;
		*q++ = 1;//==>*(q++); -->*q = 1; q++;
		*q++ = 5;
		cout << *p << endl;//1
		cout << *(p+1) << endl;//5
		free(p);
	}

	return 0;
}





// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
