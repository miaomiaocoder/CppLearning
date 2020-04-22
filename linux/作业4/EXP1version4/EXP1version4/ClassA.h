#ifndef _CLASSA_H_
#define _CLASSA_H_

#include"SerClass.h"
#include<fcntl.h>
#include<unistd.h>
#include<iostream>

class ClassA :
	public SerClass
{
public:
	int x;
	char y;
public:
	ClassA();
	explicit ClassA(int i, char j);
	~ClassA();
public:
	bool Serialize(int fd)const;
	bool Deserialize(int fd);
	SerClass* DeserializePtr(int fd);
	void PrintObject();
	int getType() {
		return 1;
	}
};


#endif // !_CLASSA_H_