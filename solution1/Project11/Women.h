#pragma once
#include "Human.h"
#include<iostream>
class Women :public Human
{
public:
	Women();
	~Women();
	virtual void eat();
	virtual void eat2() 
	{
		std::cout << "women::eat2()" << std::endl;
	};
};

