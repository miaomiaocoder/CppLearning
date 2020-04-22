#ifndef _CLASSC_H_
#define _CLASSC_H_

#include"SerClass.h"
#include<iostream>
#include<fcntl.h>
#include<unistd.h>
class ClassC :
	public SerClass
{
public:
	int x;
	int y;
public:
	ClassC();
	explicit ClassC(int i, int j);
	~ClassC();
public:
	bool Serialize(int fd)const;
	bool Deserialize(int fd);
	SerClass* DeserializePtr(int fd);
	void PrintObject();
	int getType() {
		return 3;
	}
};


#endif // !_CLASSC_H_
