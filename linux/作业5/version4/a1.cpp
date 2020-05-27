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
		cout << "Hello World!" << endl;
	}
	virtual void Help()
	{
		cout << "This func prints 'Hello World!'" <<endl;
	}
	virtual int GetID()
	{
		return 1;
	}
};
extern "C" CPlugin* GetInterface()
{
	static Plugin plugin;
	return &plugin;
}
