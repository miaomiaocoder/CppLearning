#pragma once


class A;//类声明，表示有A这样一个类型
class C
{
public:
	void callCAF(int x, A &a);//只有public函数才有机会成为其它类的友元函数
	void callCAF2(int x, A &a);
};

