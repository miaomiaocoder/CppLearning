//#include<iostream>
//
//using namespace std;
//
//
//template <typename T>
//class A {
//	//TODO:
//};
//
//
//int main()
//{
//	//auto可以和某些具体类型混用
//	int x = 0;
//	auto *p1 = &x; //p1为int*，auto推导为int
//	auto p2 = &x;  //p2为in*，auto推导为int*
//	auto &r1 = x;  //r1为 int&, auto推导为int
//	auto r2 = r1;  //r2为int, auto推导为int
//	//r1 本来是 int& 类型，但是 auto 却被推导为 int 类型，这表明当=右边的表达式是一个引用类型时，auto 会把引用抛弃，直接推导出它的原始类型
//
//	//auto和const结合
//	int y = 0;
//	const auto n = y;//n 为 const int ，auto 被推导为 int
//	auto f = n;//f 为 const int，auto 被推导为 int（const 属性被抛弃）
//	const auto&r1 = x; //r1 为 const int& 类型，auto 被推导为 int
//	auto &r2 = r1; //r1 为 const int& 类型，auto 被推导为 const int 类型
//
//
//	//auto的限制
//	//auto 不能在函数的参数中使用。
//	//auto 不能作用于类的非静态成员变量（也就是没有 static 关键字修饰的成员变量）中
//	//auto不能定义数组
//	char url[] = "https://github.com/renzhenhua/cpp_learning";
//	//auto  str[] = url;  //arr 为数组，所以不能使用 auto
//
//	//auto 不能作用于模板参数
//	A<int>C1;
//	//A<auto>C2 = C1;
//
//
//	return 0;
//}


//auto的应用
//定义迭代器
//#include<vector>
//using namespace std;
//
//int main()
//{
//	//vector<vector<int>> v;
//	//vector<vector<int>>::iterator i = v.begin();
//
//	//使用auto可以方便定义stl的迭代器，将上面代码简化
//	vector<vector<int>> v;
//	auto i = v.begin();
//
//
//	return 0;
//}
//


//auto用于泛型编程
#include<iostream>

using namespace std;

class A {
public:
	static int get(void) {
		return 100;
	}
};

class B {
public:
	static const char* get(void) {
		return "https://github.com/renzhenhua/cpp_learning";
	}
};

//使用auto
template<typename T>
void func(void) {
	auto val = T::get();
	cout << val << endl;
}

//不适用auto
template <typename T1, typename T2>  //额外增加一个模板参数 T2
void func(void) {
	T2 val = T1::get();
	cout << val << endl;
}

//int main(void) {
//	func<A>();
//	func<B>();
//
//	//调用时也要手动给模板参数赋值
//	func<A, int>();
//	func<B, const char*>();
//
//	return 0;
//}