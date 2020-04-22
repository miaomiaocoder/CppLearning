#include "ClassA.h"
using namespace std;
ClassA::ClassA() {
	x = 0;
	y = 'r';
}
ClassA::ClassA(int i, char j) {
	x = i;
	y = j;
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
	if (false == Serialize(fd))
	{
		cout << "Serialize(fd) = false" << endl;
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
	if (false == Deserialize(fd))
	{
		cout << "Deserialize(fd) = false" << endl;
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


bool ClassA::Serialize(int fd) const {
	if (-1 == fd) {
		return false;
	}
	if (write(fd, &x, sizeof(int)) == -1) {
		return false;
	}
	if (write(fd, &y, sizeof(char)) == -1) {
		return false;
	}
	return true;
}

bool ClassA::Deserialize(int fd){
	if (-1 == fd) {
		return false;
	}
	int rd;
	rd = read(fd, &x, sizeof(int));
	if (-1 == rd || 0 == rd) {
		return false;
	}
	rd = read(fd, &y, sizeof(char));
	if (-1 == rd || 0 == rd) {
		return false;
	}
	return true;
}

void ClassA::PrintObject() {
	cout << "x = " <<x<< endl;
	cout << "y = " <<y<< endl;
}