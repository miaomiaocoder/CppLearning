#ifndef _SERIALIZER_H_
#define _SERIALIZER_H_

#include<iostream>
#include<vector>
#include<fcntl.h>
#include<unistd.h>
#include"SerClass.h"

using namespace std;

class Serializer
{
public:
	vector<SerClass*>nSerClass;

	bool Serialize(const char*pFilePath, vector<SerClass*>&v);
	bool Deserialize(const char*pFilePath, vector<SerClass*>&v);
	void Register(SerClass*ptr);
};


#endif // !_SERIALIZER_H_