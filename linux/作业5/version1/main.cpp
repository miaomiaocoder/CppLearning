#include<iostream>
#include<dlfcn.h>
#include"a.h"

using namespace std;

int main()
{
	void*handle = dlopen("./libtest.so",RTLD_LAZY);//open libtest.so
	if (0 == handle)
	{
		cout << "dlopen error" << endl;
		return 0;
	}

	typedef void(*Func)();

	Func print1 = (Func)dlsym(handle, "print");

	if (0 == print1)
	{
		cout << "print1 error" << endl;
		char*str = dlerror();
		cout << str << endl;
	}

	(*print1)();

	dlclose(handle);

	return 0;
}
