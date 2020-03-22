#pragma once
#include<iostream>
class Human
{
public:
	Human();
	Human(int);
public:
	int m_Age;
	char m_Name[100];

	void funcpub() {};
protected:
	int m_prol;
	void funcpro() {};
private:
	int m_priv1;
	void funcpriv();
};

