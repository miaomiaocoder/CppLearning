#include<iostream>
#include<string>
#include <iomanip>

using namespace std;

int main()
{
	//string学习

	//定义和初始化
	//string s1; //默认初始化, s1 ="" :""空串表示这里边没有字符
	//string s2 = "I love the world";//不包括末尾的\0
	//string s3("I love the world");//和s2效果一样
	//string s4 = s2;//拷贝
	//
	//int num = 6;
	//string s5(num, 'a');//s5初始化为num个字符'a'的字符串
	//会在系统内创建临时对象

	//string构造函数和析构函数
	/*
	string str("12345678");
	char ch[] = "abcdefgh";
	string a;//定义一个空字符串
	string str_1(str);//构造函数，全部复制
	string str_2(str, 2, 5);//构造函数，从字符串str的第2个元素开始，复制5个元素，赋值给str_2
	string str_3(ch, 5);//将字符串ch的前5个元素赋值给str_3
	string str_4(5, 'X');//将 5 个 'X' 组成的字符串 "XXXXX" 赋值给 str_4
	string str_5(str.begin(),str.end());//复制字符串 str 的所有元素，并赋值给 str_5
	cout << str << endl;
	cout << a << endl;
	cout << str_1 << endl;
	cout << str_2 << endl;
	cout << str_3 << endl;
	cout << str_4 << endl;
	cout << str_5 << endl;
	return 0;
	*/


	//c++获取字符串长度
	/*
	int size = 0;
	int length = 0;
	unsigned long maxsize = 0;
	int capacity = 0;
	string str("12345678");
	string str_custom;
	str_custom = str;
	//str_custom.resize(5);
	str_custom.reserve(5);
	size = str_custom.size();
	length = str_custom.length();
	maxsize = str_custom.max_size();
	capacity = str_custom.capacity();
	cout << "size = " << size << endl;
	cout << "length = " << length << endl;
	cout << "maxsize = " << maxsize << endl;
	cout << "capacity = " << capacity << endl;
	return 0;
	*/


	//c++string.resize()
	/*
	std::string str("I like to code in C");
	std::cout << str << '\n';
	
	unsigned sz = str.size();

	str.resize(sz + 2, '+');
	std::cout << str << '\n';

	str.resize(14);
	std::cout << str << '\n';
	return 0;
	*/


	//c++获取字符串元素
	//const std::string cs("c.biancheng.net");
	//std::string s("abcde");
	//char temp = 0;
	//char temp_1 = 0;
	//char temp_2 = 0;
	//char temp_3 = 0;
	//char temp_4 = 0;
	//char temp_5 = 0;
	//
	//temp = s[2];//acquire 'c'
	//cout << temp << endl;
	//
	//temp_1 = s.at(2); //acquire 'c'
	//cout << temp_1 << endl;
	//
	//temp_2 = s[s.length()];
	//cout << temp_2 << endl;
	//
	//temp_3 = cs[cs.length()];
	//cout << temp_3 << endl;
	//
	//temp_4 = s.at(s.length()); //程序异常
	//cout << temp_4 << endl;
	//
	//temp_5 = cs.at(cs.length()); //程序异常
	//cout << temp_5 << endl;

	//return 0;
	
	/*std::string s("abcde");
	std::cout << s << std::endl;
	char&r = s[2];
	char*p = &s[3];
	r = 'X';
	*p = 'Y';
	std::cout << s << std::endl;
	s = "12345678";
	r = 'X';
	*p = 'Y';
	std::cout << s << std::endl;
	return 0;*/
	
	
	//若要对齐输出，则通过将 setw 操控器放置在流中或通过调用 宽度成员函数来指定每个项的输出宽度。
	/*double values[] = { 1.23, 35.36, 653.7, 4358.24 };
	for (int i = 0; i < 4; i++)
	{
		cout.width(10);
		cout << values[i] << '\n';
	}

	for (int i = 0; i < 4; i++)
	{
		cout.width(10);
		cout.fill('*');
		cout << values[i] << endl;
	}*/


	//string sp;
	//ostringstream myString;
	//myString << "this is a test" << ends;
	//sp = myString.str();  // Obtain string
	//cout << sp < endl;


	// setw.cpp
	// compile with: /EHsc


	/*double values1[] = { 1.23, 35.36, 653.7, 4358.24 };
	const char *names[] = { "Zoot", "Jimmy", "Al", "Stan" };
	for (int i = 0; i < 4; i++)
		cout << setw(6) << names[i]<< setw(10) << values1[i] << endl;
	for (int i = 0; i < 4; i++)
		cout << setiosflags(ios::left)
		<< setw(6) << names[i]
		<< resetiosflags(ios::left)
		<< setw(10) << values1[i] << endl;*/
	
	/*string s1;
	if (s1.empty())
	{
		cout << "s1为空" << endl;
	}*/

	//size()/length():返回字节或字符数量
	/*string s1;
	cout << s1.size() << endl;
	cout << s1.length() << endl;
	string s2 = "I love china";
	cout << s2.size() << endl;
	cout << s2.length() << endl;
	string s3 = "我爱女孩";
	cout << s3.size() << endl;
	cout << s3.length() << endl;*/

	//string s4 = "abcd";
	//string s5 = "hijk";
	//string s6 = s4 + s5;
	//cout << s6 << endl;
	//s5 = s4;
	//cout << s5 << endl;//取代
	
	//s.c_str();//返回一个字符串s中的内容指针
	//返回一个指向正规的c字符串的指针常量，以\0结尾
	//为了与c语言兼容引入
	
	//string s10 = "abC";
	//const char*p = s10.c_str();//abC	
	//char str[100];
	//strcpy_s(str,sizeof(str),p);
	//cout << str << endl;
	//string s11(str);//用c语言字符串数组初始化
	//
	
	//string s1 = "abc";
	//string s2 = "defg";
	//string s3 = s1 + " and " + s2 + 'e';
	//cout << s3 << endl;//abc and defge

	//string s5 = "abc" + "def"; //语法上不允许
	//string s5 = "abc" + s1 + "def";//中间夹一个string对象，语法允许
	//string s5 = "abc" + "def" + s2;//error

	string s1 = "i love the world";
	//for (auto c : s1)//auto类型自动推断 char
	//{
	//	cout << c << endl;
	//}
	for (auto &c : s1)
	{
		//toupper()把小写字符转成大写字符
		c = toupper(c);//因为c是一个引用，相当于改变s1中的值
	}
	cout << s1 << endl;
	return 0;
}
