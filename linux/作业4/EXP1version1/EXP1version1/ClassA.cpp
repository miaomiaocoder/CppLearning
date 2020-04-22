#include "ClassA.h"
using namespace std;
ClassA::ClassA() {
	i = 0;
}
ClassA::ClassA(int i) {
	this->i = i;
}
ClassA::~ClassA() {

}

bool ClassA::Serialize(const char* pFilePath)
{
	int fd = open(pFilePath, O_RDWR | O_CREAT | O_TRUNC, 0666);
	//O_RDWR 读、写打开
	//O_CREAT 若此文件不存在则创建它，使用此选项时需要第3个参数mode
	//O_TRUNC 若此文件存在，而且为只写或读-写成功打开，则将其长度截断为0
	if (-1 == fd)
	{
		cout << "Serialize::open error" << endl;;
		return false;
	}
	if (-1 == write(fd, &i, sizeof(int)))
	{
		cout << "Serialize::write error" << endl;
		close(fd);
		return false;
	}
	if (-1 == close(fd))
	{
		cout << "Serialize::close error" << endl;
		return false;
	}
	return true;
}

bool ClassA::Deserialize(const char* pFilePath)
{
	int fd = open(pFilePath, O_RDWR);
	if (-1 == fd)
	{
		cout << "Serialize::open error" << endl;;
		return false;
	}
	if (-1 == read(fd, &i, sizeof(int))) //将读出来的数据存入ptr中
	{
		cout << "Serialize::read error" << endl;
		close(fd);
		return false;
	}
	if (-1 == close(fd))
	{
		cout << "Serialize::close error" << endl;
		return false;
	}
	return true;
}

void ClassA::PrintObject()const {
	cout << "i = " << i << endl;
}