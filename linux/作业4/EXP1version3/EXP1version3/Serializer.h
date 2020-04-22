#ifndef _SERIALIZER_H_
#define _SERIALIZER_H_

#include<iostream>
#include<vector>
#include<fcntl.h>
#include<unistd.h>
#include"ClassA.h"
#include"ClassB.h"

using namespace std;
struct Serialized
{
	int  nType; //1 for A; 2 for B
	void * pObj;
};

class Serializer
{
public:
	bool Serialize(const char*pFilePath, vector<Serialized>&v);
	bool Deserialize(const char*pFilePath, vector<Serialized>&v);
};


#endif // !_SERIALIZER_H_



