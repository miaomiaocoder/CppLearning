#pragma once
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

using namespace std;

void getDirFile(char* path, vector<string>& files);//得到目录下的文件
void getDirType(char* path, vector<string>&types);//得到目录下文件的类型
void file_type(const struct stat* file_message); //得到文件的类型
void file_nlink(const struct stat *file_message);//得到文件的硬连接数
void file_power(const struct stat *file_message); //获得文件权限
void file_id(const struct stat*file_message);//得到文件所有者，组名称
void file_size(const struct stat*file_message); //获取文件大小
void file_mtime(const struct stat*file_message); //获取文件最近一次修改时间