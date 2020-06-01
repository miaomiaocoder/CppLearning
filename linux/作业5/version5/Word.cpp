#include<iostream>
#include <unistd.h>
#include <fcntl.h>
#include"IPlugin.h"

using namespace std;
char FUNC_NAME[] = "cw"; //count the word cw
class Plugin:
	public IPlugin
{
public:
	Plugin()
	{
	}
	virtual ~Plugin()
	{
	}
	virtual void Print()
	{
		cout << "Count the file word! Use 'cw'" << endl;
	}
	virtual void Help()
	{
		cout <<"Func id:2 " << "This func will count file's words" <<endl;
	}
	virtual int GetID()
	{
		return 2;
	}
	virtual char *GetName()
	{
		return FUNC_NAME;
	}
	virtual void Func(char *File)
	{
		int fd;
		char temp;
		int num = 0;
		if (-1 == (fd = open(File, O_RDONLY)))
		{
			cout << "Can not open: " << File << endl;
			return;
		}
		while (read(fd, &temp, 1))
		{
			num++;
		}
		close(fd);
		if (0 == num)
		{
			cout << "Empty file: " << File << endl;
		}
		cout << File << " word is : " << num << endl;
	}
};
extern "C" void GetInterface(IPlugin **ppPlugin)
{
	static Plugin plugin;
	*ppPlugin = &plugin;
}
