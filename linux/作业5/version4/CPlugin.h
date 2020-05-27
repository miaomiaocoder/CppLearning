#ifndef _CPLUGIN_H_
#define _CPLUGIN_H_

class CPlugin
{
public:
	virtual void Print()
	{
	}
	virtual void Help()
	{
	}
	virtual int GetID(){
		return 0;
	}
public:
	CPlugin(){
	}
	virtual ~CPlugin(){
	}
};

#endif
