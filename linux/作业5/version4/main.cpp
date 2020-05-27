#include <dlfcn.h>
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include "SearchPlugin.h"
#include "CPlugin.h"
using namespace std;

//导出函数的指针类型
typedef CPlugin*  (*FUNC_GETINTERFACE)();

//主程序，测试代码
int main (int argc, char *argv[])
{
    //存放所有插件的文件名
    vector<string> PluginName;

    //定义插件搜索类对象
    SearchPlugin ptr;
    //获取所有的插件文件名
    if(!ptr.GetPlugin(PluginName))
    {
        cout << "GetPlugin error" << endl;
        return 0;
    }

    int pluginCount = 0;
    vector<CPlugin*> vPlugin;

    //遍历文件名数组，依次打开并获取导出的接口对象
    for(int i = 0; i< PluginName.size(); i++)
    {
        //打开动态链接库文件
        void *handle = dlopen(PluginName[i].c_str(), RTLD_LAZY);
        if(handle == 0)
        {
            cout << "dlopen error" << endl;
            return 0;
        }

        //获取导出的接口对象指针
        FUNC_GETINTERFACE func = (FUNC_GETINTERFACE)dlsym(handle, "GetInterface");
        //获取接口对象指针
        CPlugin* pInterface = func();
        //指针存到数组
        vPlugin.push_back(pInterface);

        ++pluginCount;
    }

    //获取用户输入的参数
    if (argc > 1) {
        char* param = argv[1];
        if ( !strcmp(param, "help") ) //用户输入的是help
        {
            //循环，显示所有插件的功能ID和帮助信息
            for (auto i = 0; i < pluginCount; i++)
            {
                cout << vPlugin[i]->GetID() << ": "; //调用输出ID
                vPlugin[i]->Help(); //调用帮助信息函数
            }
        }
        else //用户可能输入的是功能ID
        {
            int id = atoi(param);
            //循环，找出该功能
            for (auto i = 0; i < pluginCount; i++)
                if (vPlugin[i]->GetID() == id) //找到了
                    vPlugin[i]->Print(); //调用其打印函数
        }
    }

    return 0;
}

