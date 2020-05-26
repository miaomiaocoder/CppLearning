#ifndef _ILMEDIUMFORSERIALIZATION_H_
#define _ILMEDIUMFORSERIALIZATION_H_

#include"Status.h"

class ILMediumForSerialization
{
public:
	ILMediumForSerialization() {

	}
	virtual ~ILMediumForSerialization() {

	}
public:
	virtual Status WriteToMedium(const char* pBuff, unsigned int iSize) = 0;
	virtual Status GetSizeOfObjectInMedium(unsigned int & objssize) = 0;
	virtual Status ReadFromMedium(char* pBuff) = 0;
};

#endif 
