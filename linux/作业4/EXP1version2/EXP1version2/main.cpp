#include<iostream>
#include"ClassA.h"
#include"SerializerForClassA.h"

using namespace std;

int main()
{
	{
		ClassA Object1(10,'r'), Object2(20, 'e'), Object3(30, 'n');
		vector<ClassA>v;
		v.push_back(Object1);
		v.push_back(Object2);
		v.push_back(Object3);
		SerializerForClassA ser;
		ser.Serialize("result.ser",v);
	}
	{
		SerializerForClassA ser;
		vector<ClassA>v;
		ser.Deserialize("result.ser",v);
		for (auto i = 0; i < v.size(); ++i)
		{
			v[i].PrintObject();
		}
	}
	return 0;
}