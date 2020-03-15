////c++迭代器学习
//#include<iostream>
//#include<vector>
//using namespace std;
//int main()
//{
//	vector<int> v;//v是存放int类型变量的可变长数组，开始是没有元素
//	for (int n = 0; n < 5; ++n)
//	{
//		v.push_back(n);//push_back成员函数在vector容器尾部添加一个元素
//	}
//	vector<int>::iterator i;//定义正向迭代器
//	for (i = v.begin(); i != v.end(); ++i)//用迭代器遍历容器
//	{
//		cout << *i << " ";//*i 就是迭代器i指向的元素 
//		*i *= 2;//每个元素变为原来的2倍
//	}
//	cout << endl;
//	
//	//用反向迭代器遍历容器
//	for (vector<int>::reverse_iterator j = v.rbegin(); j != v.rend(); ++j)
//		cout << *j << " ";
//	return 0;
//}
//迭代器是一个对象，可以循环访问 STL 容器中的元素，并提供对各个元素的访问。 STL 容器全都提供迭代器，以便算法可以采用标准方式访问其元素，
//而不必考虑用于存储元素的容器类型。
//
//可以通过使用成员和全局函数（如 begin() 和 end()）以及运算符（如 ++ 和 -- ）向前或向后移动，来显式使用迭代器。 
//还可以通过范围 for 循环或（对于某些迭代器类型）下标运算符[]，来隐式使用迭代器。
//
//在 STL 中，序列或范围的开头是第一个元素。 序列或范围的末尾始终定义为最后一个元素的下一个位置。 
//全局函数的开始和结束会将迭代器返回到指定容器。





// compile with: /EHsc /W4
//push_back详解
//#include <vector>
//#include <iostream>
//
//using namespace std;
//
//template <typename T> void print_elem(const T& t) {
//	cout << "(" << t << ") ";
//}
//
//template <typename T> void print_collection(const T& t) {
//	cout << "  " << t.size() << " elements: ";
//
//	for (const auto& p : t) {
//		print_elem(p);
//	}
//	cout << endl;
//}
//
//int main()
//{
//	vector<int> v;
//	for (int i = 0; i < 10; ++i) {
//		v.push_back(10 + i);
//	}
//
//	cout << "vector data: " << endl;
//	print_collection(v);
//
//	// pop_back() until it's empty, printing the last element as we go
//	while (v.begin() != v.end()) {
//		cout << "v.back(): "; print_elem(v.back()); cout << endl;
//		v.pop_back();
//	}
//}
//




#include<iostream>
#include<string>
#include<vector>

using namespace std;

struct conf {
	char itemname[40];
	char itemcontent[100];
};

char *getInfo(vector<conf*> &conflist, const char*pitem)
{
	for (auto pos = conflist.begin(); pos != conflist.end(); ++pos)
	{
		if (_stricmp((*pos)->itemname,pitem) == 0)
		{
			return(*pos)->itemcontent;
		}
	}
	return nullptr;
}
int main()
{
	//用迭代器遍历string类型数据
	//string str("I love China!");
	//for (auto iter = str.begin(); iter != str.end(); ++iter)
	//{
	//	*iter = toupper(*iter);
	//}
	//cout << str << endl;


	//vector容器常用操作与内存释放
	//SeverName = 1区 //表示服务器名称
	//SeverID = 10000 //表示服务器ID

	conf *pconf1 = new conf;
	strcpy_s(pconf1->itemname,sizeof(pconf1->itemname), "SeverName");
	strcpy_s(pconf1->itemcontent,sizeof(pconf1->itemcontent),"1区");

	conf *pconf2 = new conf;
	strcpy_s(pconf2->itemname, sizeof(pconf2->itemname), "SeverID");
	strcpy_s(pconf2->itemcontent, sizeof(pconf2->itemcontent), "100000");

	vector<conf*>conflist;
	conflist.push_back(pconf1);
	conflist.push_back(pconf2);

	char *p_tmp = getInfo(conflist, "SeverName");
	if (p_tmp != nullptr)
	{
		cout << p_tmp << endl;
	}

	//释放内存
	std::vector<conf*>::iterator pos;
	for (pos = conflist.begin(); pos != conflist.end(); ++pos)
	{
		delete(*pos);//*pos是那个指针
	}

	conflist.clear();

	return 0;
}
