#include<iostream>
#include<unistd.h>
#include<fcntl.h>
using namespace std;

int main()
{
	int fd = open("a.txt", O_RDWR | O_APPEND);
	if(-1 == fd)
	{
		cout << "open error" << endl;
		return 0;
	}

	off_t CurrentPosition = lseek(fd, 0, SEEK_CUR);
	cout << "CurrentPosition:  " <<CurrentPosition<< endl;


	char write_buf = 'm';
	if (write(fd, &write_buf, 1) == -1)
	{
		cout << "write error" << endl;
		close(fd);
		return 0;
	}

	CurrentPosition = lseek(fd, 0, SEEK_CUR);
	cout << "After writing m, CurrentPosition:  " << CurrentPosition << endl;
	
	if (lseek(fd, 0, SEEK_SET) == -1)
	{
		cout << "lseek error" << endl;
		close(fd);
		return 0;
	}

	char buf[100];
	if ((read(fd, &buf, 5) == -1))
	{
		cout<<"Read failed"<<endl;
		close(fd);
		return 0;
	}

	off_t newCurrentPosition = lseek(fd, 0, SEEK_CUR);
	cout << "After read, CurrentPosition:  " << CurrentPosition << endl;
	cout << "what I read:  " << buf<<endl;


	char write_buf2 = 'P';
	if (write(fd, &write_buf2, 1) == -1)
	{
		cout << "write error" << endl;
		close(fd);
		return 0;
	}

	//lseek 可以在任一位置读，但由追加标志打开的文件只能在尾端写入。
	return 0;
}