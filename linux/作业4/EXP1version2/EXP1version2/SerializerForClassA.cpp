#include "SerializerForClassA.h"

bool SerializerForClassA::Serialize(const char*pFilePath, vector<ClassA>&v)
{
	int fd = open(pFilePath, O_RDWR | O_CREAT | O_TRUNC, 0666);
	//O_RDWR 读、写打开
	//O_CREAT 若此文件不存在则创建它，使用此选项时需要第3个参数mode
	//O_TRUNC 若此文件存在，而且为只写或读-写成功打开，则将其长度截断为0
	if (-1 == fd)
	{
		cout << "Serialize::open error" << endl;
		return false;
	}
	for (auto i = 0; i < v.size(); ++i)
	{
		v[i].Serialize(fd);
	}
	close(fd);
	return true;
}

bool SerializerForClassA::Deserialize(const char*pFilePath, vector<ClassA>&v)
{
	int fd = open(pFilePath, O_RDWR);
	//O_RDWR 读、写打开
	if (-1 == fd)
	{
		cout << "Serialize::open error" << endl;
		return false;
	}
	for (;;) {
		ClassA Object;
		if (true == Object.Deserialize(fd)) {
			v.push_back(Object);
		}
		else
			break;
	}
	close(fd);
	return true;
}