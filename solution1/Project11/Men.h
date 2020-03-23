#pragma once
#include"Human.h"
class Men:public Human //表示Men是Human的子类
//class Men:protected Human
//class Men:private Human
{
public:
	Men();

public:
	void samenamefunc(int);

public:
	using Human::samenamefunc;
};

