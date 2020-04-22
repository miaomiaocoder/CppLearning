#pragma once
#include<iostream>
#include<fcntl.h>
#include<unistd.h>

class ClassA
{
private:
	int i;
public:
	ClassA();
	explicit ClassA(int i);
	~ClassA();
public:
	bool Serialize(const char* pFilePath);
	bool Deserialize(const char* pFilePath);
	void PrintObject()const;
};
