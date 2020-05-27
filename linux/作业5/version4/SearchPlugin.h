#ifndef _SEARCHPLUGIN_H_
#define _SEARCHPLUGIN_H_

#include<iostream>
#include<vector>
#include<string>
#include<dirent.h>
#include<cstring>

using namespace std;
class SearchPlugin
{
public:
	SearchPlugin() {
	}
	~SearchPlugin() {
	}
	bool GetPlugin(vector<string>& PluginName);
};


#endif // !_SEARCHPLUGIN_H_

