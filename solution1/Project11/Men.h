#pragma once
#include"Human.h"
class Men:public Human //表示Men是Human的子类
//class Men:protected Human
//class Men:private Human
{
public:
	Men();
	~Men();

public:
	void samenamefunc(int);

	void funcmen() {};

	virtual void eat() override;

	virtual void eat2() 
	{
		std::cout << "men::eat2()" << std::endl;
	};

public:
	using Human::samenamefunc;
};

