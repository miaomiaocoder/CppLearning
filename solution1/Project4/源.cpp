//c++迭代器学习
#include<iostream>
#include<vector>
using namespace std;
int main()
{
	vector<int> v;//v是存放int类型变量的可变长数组，开始是没有元素
	for (int n = 0; n < 5; ++n)
	{
		v.push_back(n);//push_back成员函数在vector容器尾部添加一个元素
	}
	vector<int>::iterator i;//定义正向迭代器
	for (i = v.begin(); i != v.end(); ++i)
	{

	}
}



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
