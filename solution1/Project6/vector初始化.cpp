#include<iostream>
#include<vector>
#include<string>
using namespace std;

struct student {
	int num;
};

int func()
{
	//vector能把其他对象装进来，所以被称为容器。
	vector<int> vjihe;//vijihe里边保存int型数据（int 型对象）
	//<int>：模板，vector本身是类模板，<int>实际上类模板实例化的过程
	//
	vector<student>studentlist;

	vector<vector<string>> str;

	vector<int*> v2;
	//vector<int &> v3;//报错

	//定义和初始化vector对象
	vector<string> my_str;//创建一个string类型的空的vector对象（容器）
	my_str.push_back("abcde");
	my_str.push_back("dfs");
	//拷贝初始化
	vector<string> my_str2(my_str);//把my_str元素拷贝给了my_str2
	vector<string> my_str3 = my_str;//把my_str元素拷贝给了my_str3

	//c++11,引入列表初始化
	vector<string>my_str4 = { "adv","sdf","dsf" };

	//创建指定数量的元素，一般用()
	vector<int> jihe(15, -200);//创建15个int类型元素，每个元素值-200
	vector<string> jihe2(5, "hello");//创建5个string类型的元素，每个元素是hello

	vector<int>ijihe1(20);//20个元素，[0],[1] .. [19]每个是0
	vector<string>ijihe2(5);//5个元素，每个""

	//多种初始化方式
	vector<int> i1(10);//表示10个元素，每个元素是缺省的0
	vector<int> i2{ 10 };//表示是一个元素，该元素值为10
	vector<string> snor{ "hello" };//一个元素，内容：hello
	vector<string> str0{ 10 };//10个元素,每个元素""
	vector<string> str2{ 10, "hello" };//10个元素，每个元素内容是"hello"；
	vector<int>i3(10, 1);//10个元素，每个元素值为1;
	vector<int>i4{ 10,1 };//2个元素，第一个元素是10，第二个元素是1
	//通过{}初始化，{}里边的值类型必须跟vector后边<>类型相同

	return 0;
}