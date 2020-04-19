#include<iostream>
#include<string>
#include<cstring>
#include<vector>
#include<dirent.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<fcntl.h>
#include<cstdio>
#include <pwd.h>
#include <grp.h>
#include <iomanip>
#include"head.h"

using namespace std;

int main(int argc, char*argv[])
{	
	char* filepath;
	char* path;
	if (argc < 2) {
		if ((filepath = getcwd(NULL, 0)) == NULL) {
			cout << "getcwd error" << endl;
		}
	}
	if (argc == 2) {
		if ((filepath = getcwd(NULL, 0)) == NULL) {
			cout << "getcwd error" << endl;
		}
		char c[] = "/";
		strcat(filepath,c );
		strcat(filepath,argv[1]);
		chdir(filepath);//使得修改过后的filepath为工作目录
	}
	if (argc > 2) {
		cout << "too many parameters" << endl;
		exit(0);
		//暂时未能成功考虑实现
	}
	
	struct stat file_message = {};
	int ret_stat = lstat(filepath, &file_message);
	if (S_ISDIR(file_message.st_mode)) //判断是否是目录文件
	{
		vector<string> files;//存放目录下文件名
		vector<string> types;//存放目录下文件类型
		getDirFile(filepath, files);
		getDirType(filepath, types);
		for (auto i = 0; i < files.size(); ++i)  //通过for来打印信息
		{
			struct stat dirfile_message;
			int ret_opendir = open(files[i].c_str(), O_RDONLY); //open可以返回文件描述符
			fstat(ret_opendir, &dirfile_message);                  //fstat可以通过文件描述符，复制到参数struct stat file_message 结构体变量中
			if (ret_opendir == -1) // stat读取文件错误则输出提示信息
				cout << files[i] << "error!" << endl;;
			cout << types[i];
			file_power(&dirfile_message);
			file_nlink(&dirfile_message);
			file_id(&dirfile_message);
			file_size(&dirfile_message);
			file_mtime(&dirfile_message);
			cout << files[i] << endl;
		}
	}
	else {
		int ret = open(argv[1], O_RDONLY); //open可以返回文件描述符
		fstat(ret, &file_message);
		if (ret == -1) {// stat读取文件错误则输出提示信息
			cout << argv[1] << " error!" << endl;
			exit(0);
		}
		file_type(&file_message);
		file_power(&file_message);
		file_nlink(&file_message);
		file_id(&file_message);
		file_size(&file_message);
		file_mtime(&file_message);
		cout << argv[1] << endl;
	}

	return 0;
}

