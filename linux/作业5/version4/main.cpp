#include <iostream>
#include "CPluginController.h"
#include <string.h>
#include <stdlib.h>

using namespace std;

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		cout << "Parameters error" << endl;
		return 0;
	}
	if (strcmp(argv[1], "help") == 0)
	{
		CPluginController ptr;
		ptr.ProcessHelp();
		return 0;
	}
	int FunctionID = atoi(argv[1]);
	CPluginController pointer;
	pointer.InitializeController();
	pointer.ProcessRequest(FunctionID);
	pointer.UninitializeController();
	return 0;
}
