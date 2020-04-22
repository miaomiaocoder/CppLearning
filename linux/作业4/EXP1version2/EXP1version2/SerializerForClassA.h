#ifndef _SERIALIZERFORCLASSA_H_
#define _SERIALIZERFORCLASSA_H_
#include<iostream>
#include<vector>
#include"ClassA.h"
using namespace std;

class SerializerForClassA
{
public:
	bool Serialize(const char*pFilePath, vector<ClassA>&v);
	bool Deserialize(const char*pFilePath, vector<ClassA>&v);
};


#endif // !_SERIALIZERFORCLASSA_H_

