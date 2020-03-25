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
private:
	void funcmen() const{
		std::cout << "test" << std::endl;
	}

	//因为友元函数不属于类成员，索一友元函数声明不受public,private,protected限制
	friend void func(const Men &tempmen);//该函数是友元函数
};

