#include<iostream>
#include"CPlugin.h"

using namespace std;

class Plugin:
	public CPlugin
{
public:
	Plugin()
	{
	}
	virtual ~Plugin()
	{
	}
	virtual void Print()
	{
		cout << "Hello China!" << endl;
	}
	virtual void Help()
	{
		cout << "This func prints 'Hello China!'" <<endl;
	}
	virtual int GetID()
	{
		return 2;
	}
};
extern "C" CPlugin* GetInterface()
{
	static Plugin plugin;
	return &plugin;
}
