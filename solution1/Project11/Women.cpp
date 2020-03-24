#include "Women.h"
#include<iostream>

Women::Women()
{
	std::cout << "执行了Women::Women()" << std::endl;
}

Women::~Women()
{
	std::cout << "执行了Women::~Women()" << std::endl;
}


void Women::eat()
{
	std::cout << "女人喜欢吃面食" << std::endl;
};

