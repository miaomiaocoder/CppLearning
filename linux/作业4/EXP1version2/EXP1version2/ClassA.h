#ifndef _CLASSA_H_
#define _CLASSA_H_

#include<iostream>
#include<fcntl.h>
#include<unistd.h>

class ClassA
{
public:
	int x;
	char y;
public:
	ClassA();
	explicit ClassA(int i,char j);
	~ClassA();
public:
	bool Serialize(const char* pFilePath);
	bool Deserialize(const char* pFilePath);
	bool Serialize(int fd)const;
	bool Deserialize(int fd);
	void PrintObject();
};

#endif // !_CLASSA_H_

