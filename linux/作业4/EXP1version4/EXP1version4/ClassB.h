#ifndef _CLASSB_H_
#define _CLASSB_H_

#include"SerClass.h"
#include<iostream>
#include<fcntl.h>
#include<unistd.h>
class ClassB:
	public SerClass
{
public:
	char x;
	char y;
public:
	ClassB();
	explicit ClassB(char i, char j);
	~ClassB();
public:
	bool Serialize(int fd)const;
	bool Deserialize(int fd);
	SerClass* DeserializePtr(int fd);
	void PrintObject();
	int getType() {
		return 2;
	}
};

#endif // !_CLASSB_H_