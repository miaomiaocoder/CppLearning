#include<iostream>
#include<string>
#include <iomanip>

using namespace std;

int main()
{
	//string学习


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

	
}