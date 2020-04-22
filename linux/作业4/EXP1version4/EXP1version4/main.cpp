#include<iostream>
#include"ClassA.h"
#include"ClassB.h"
#include"ClassC.h"
#include"Serializer.h"

using namespace std;

int main() {
	{
		ClassA *ObjectA1 = new ClassA(10, 'r');
		ClassA *ObjectA2 = new ClassA(20, 'e');
		ClassA *ObjectA3 = new ClassA(30, 'n');
		ClassB *ObjectB1 = new ClassB('h', 'h');
		ClassB *ObjectB2 = new ClassB('e', 'e');
		ClassC *ObjectC1 = new ClassC(40, 50);
		ClassC *ObjectC2 = new ClassC(60, 70);
		vector<SerClass*>v;
		v.push_back(ObjectA1);
		v.push_back(ObjectA2);
		v.push_back(ObjectA3);
		v.push_back(ObjectB1);
		v.push_back(ObjectB2);
		v.push_back(ObjectC1);
		v.push_back(ObjectC2);
		Serializer ser;
		ser.Serialize("result.ser",v);
		delete ObjectA1;
		delete ObjectA2;
		delete ObjectA3;
		delete ObjectB1;
		delete ObjectB2;
		delete ObjectC1;
		delete ObjectC2;
	}
	{
		Serializer s;
		vector<SerClass*>v;

		ClassA a;
		ClassB b;
		ClassC c;
		s.Register(&a);
		s.Register(&b);
		s.Register(&c);
		
		s.Deserialize("result.ser", v);
		for (auto i = 0; i < v.size(); ++i) {
			SerClass * p;
			if (v[i]->getType() == 1) {
				p = dynamic_cast<ClassA*>(v[i]);  //dynamic_cast:主要应用于运行时类型识别和检查
				if (p != nullptr) {
					((ClassA*)p)->PrintObject();
				}
			}
			else if (v[i]->getType() == 2) {
				p = dynamic_cast<ClassB*>(v[i]);
				if (p != nullptr) {
					((ClassB*)p)->PrintObject();
				}
			}
			else if (v[i]->getType() == 3) {
				p = dynamic_cast<ClassC*>(v[i]);
				if (p != nullptr) {
					((ClassC*)p)->PrintObject();
				}
			}
		}
	}
	return 0;
}