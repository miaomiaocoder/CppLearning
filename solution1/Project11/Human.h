#pragma once
#include<iostream>
class Human
{
public:
	Human();
	Human(int);
	virtual~Human();
public:
	int m_Age;
	char m_Name[100];
	void funchuman() {};
	void funcpub() 
	{
		std::cout << "执行了Human::funcpub() " << std::endl;
	};

	//声明成虚函数
	virtual void eat();

	virtual void eat2() = 0;//纯虚函数，没有函数体，只有一个函数声明

	


public:
	void samenamefunc();
	void samenamefunc(int);
protected:
	int m_prol;
	void funcpro() 
	{
		std::cout << "执行了Human::funcpro()" << std::endl;
	};
private:
	int m_priv1;
	void funcpriv();
};

