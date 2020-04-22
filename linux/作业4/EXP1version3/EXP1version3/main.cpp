#include<iostream>
#include"ClassA.h"
#include"ClassB.h"
#include"Serializer.h"

using namespace std;

int main()
{
	{
		ClassA *ObjectA1 = new ClassA(10, 'r');
		ClassA *ObjectA2 = new ClassA(20, 'e');
		ClassA *ObjectA3 = new ClassA(30, 'n');
		ClassB *ObjectB1 = new ClassB('h', 'h');
		ClassB *ObjectB2 = new ClassB('e', 'e');
		vector<Serialized>v;
		Serialized a1;
		a1.nType = 1;
		a1.pObj = ObjectA1;
		Serialized a2;
		a2.nType = 1;
		a2.pObj = ObjectA2;
		Serialized a3;
		a3.nType = 1;
		a3.pObj = ObjectA3;
		Serialized b1;
		b1.nType = 2;
		b1.pObj = ObjectB1;
		Serialized b2;
		b2.nType = 2;
		b2.pObj = ObjectB2;
		Serializer ser;
		v.push_back(a1);
		v.push_back(a2);
		v.push_back(a3);
		v.push_back(b1);
		v.push_back(b2);
		ser.Serialize("result.ser", v);
		delete ObjectA1;
		delete ObjectA2;
		delete ObjectA3;
		delete ObjectB1;
		delete ObjectB2;
	}
	{
		Serializer ser;
		vector<Serialized>v;
		ser.Deserialize("result.ser", v);
		for (auto i = 0; i < v.size(); ++i)
		{
			if (1 == v[i].nType) {
				ClassA* ptr = (ClassA*)(v[i].pObj);
				ptr->PrintObject();
			}
			else if (2 == v[i].nType) {
				ClassB* ptr = (ClassB*)(v[i].pObj);
				ptr->PrintObject();
			}
		}
	}
	
	return 0;
}