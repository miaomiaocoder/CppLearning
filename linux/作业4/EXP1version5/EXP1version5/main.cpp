#include<iostream>
#include<vector>
#include"CLSerializer.h"
#include"CLFileMediumForSerialization.h"
#include"ClassA.h"

using namespace std;

int main()
{
	{
		CLSerializer s(new CLFileMediumForSerialization("result.ser"));
		s.Register(new ClassA());

		ClassA a1(3);
		ClassA a2(4);

		vector<ILSerClass *>v;
		v.push_back(&a1);
		v.push_back(&a2);
		s.Serialize(v);
	}
	{
		CLSerializer s(new CLFileMediumForSerialization("result.ser"));
		s.Register(new ClassA());

		vector<ILSerClass *> v;

		s.Deserialize(v);
		for (int i = 0; i < v.size(); i++)
		{
			v[i]->Dispatch();
		}
	}

	return 0;
}