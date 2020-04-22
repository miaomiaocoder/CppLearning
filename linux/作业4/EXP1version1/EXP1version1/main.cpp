#include<iostream>
#include"ClassA.h"

using namespace std;

int main()
{
	{
		ClassA Object1(30);
		Object1.Serialize("result.ser");
	}
	{
		ClassA Object1;
		Object1.Deserialize("result.ser");
		Object1.PrintObject();
	}
	return 0;
}