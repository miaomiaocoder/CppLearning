#ifndef _CLASSA_H_
#define _ClASSA_H_

#include<iostream>
#include"ILSerClass.h"
#include"CLUUID.h"

class ClassA :
	public ILSerClass
{
public:
	ClassA()
	{
		i = 0;
	}
	explicit ClassA(int j)
	{
		i = j;
	}
	virtual Status GetObjSize(unsigned int * pObjSize)
	{
		*pObjSize = 4;
		return LSUCCESS;
	}
	virtual Status Serialize(char *pBuffer)
	{
		int *p = (int *)pBuffer;
		*p = i;
		return LSUCCESS;
	}
	virtual Status Deserialize(const char *pBuffer, ILSerClass **ppSerialized)
	{
		const int *p = (const int *)pBuffer;
		ClassA *pA = new ClassA();
		pA->i = *p;
		*ppSerialized = pA;
		return LSUCCESS;
	}
	virtual Status GetType(CLUUID &type)
	{
		type.SetValue(0x1, 0x2, 0x3, 0x4);

		return LSUCCESS;
	}
	virtual Status Dispatch()
	{
		std::cout << "ClassA.i = "<<i << std::endl;
	}
private:
	int i;
};

#endif // !_CLASSA_H_
