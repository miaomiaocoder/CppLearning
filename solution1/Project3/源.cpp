// basic_string_compare.cpp
// compile with: /EHsc
#include <string>
#include <iostream>
using namespace std;


int main()
{
	//string学习


	//// The first member function compares
	//// an operand string to a parameter string
	//int comp1;
	//string s1o("CAB");
	//string s1p("CAB");
	//cout << "The operand string is: " << s1o << endl;
	//cout << "The parameter string is: " << s1p << endl;
	//comp1 = s1o.compare(s1p);
	//if (comp1 < 0)
	//	cout << "The operand string is less than "
	//	<< "the parameter string." << endl;
	//else if (comp1 == 0)
	//	cout << "The operand string is equal to "
	//	<< "the parameter string." << endl;
	//else
	//	cout << "The operand string is greater than "
	//	<< "the parameter string." << endl;
	//cout << endl;

	//// The second member function compares part of
	//// an operand string to a parameter string
	//int comp2a, comp2b;
	//string s2o("AACAB");
	//string s2p("CAB");
	//cout << "The operand string is: " << s2o << endl;
	//cout << "The parameter string is: " << s2p << endl;
	//comp2a = s2o.compare(2, 3, s2p);
	//if (comp2a < 0)
	//	cout << "The last three characters of "
	//	<< "the operand string\n are less than "
	//	<< "the parameter string." << endl;
	//else if (comp2a == 0)
	//	cout << "The last three characters of "
	//	<< "the operand string\n are equal to "
	//	<< "the parameter string." << endl;
	//else
	//	cout << "The last three characters of "
	//	<< "the operand string\n is greater than "
	//	<< "the parameter string." << endl;

	//comp2b = s2o.compare(0, 3, s2p);
	//if (comp2b < 0)
	//	cout << "The first three characters of "
	//	<< "the operand string\n are less than "
	//	<< "the parameter string." << endl;
	//else if (comp2b == 0)
	//	cout << "The first three characters of "
	//	<< "the operand string\n are equal to "
	//	<< "the parameter string." << endl;
	//else
	//	cout << "The first three characters of "
	//	<< "the operand string\n is greater than "
	//	<< "the parameter string." << endl;
	//cout << endl;

	//// The third member function compares part of
	//// an operand string to part of a parameter string
	//int comp3a;
	//string s3o("AACAB");
	//string s3p("DCABD");
	//cout << "The operand string is: " << s3o << endl;
	//cout << "The parameter string is: " << s3p << endl;
	//comp3a = s3o.compare(2, 3, s3p, 1, 3);
	//if (comp3a < 0)
	//	cout << "The three characters from position 2 of "
	//	<< "the operand string are less than\n "
	//	<< "the 3 characters parameter string "
	//	<< "from position 1." << endl;
	//else if (comp3a == 0)
	//	cout << "The three characters from position 2 of "
	//	<< "the operand string are equal to\n "
	//	<< "the 3 characters parameter string "
	//	<< "from position 1." << endl;
	//else
	//	cout << "The three characters from position 2 of "
	//	<< "the operand string is greater than\n "
	//	<< "the 3 characters parameter string "
	//	<< "from position 1." << endl;
	//cout << endl;

	//// The fourth member function compares
	//// an operand string to a parameter C-string
	//int comp4a;
	//string s4o("ABC");
	//const char* cs4p = "DEF";
	//cout << "The operand string is: " << s4o << endl;
	//cout << "The parameter C-string is: " << cs4p << endl;
	//comp4a = s4o.compare(cs4p);
	//if (comp4a < 0)
	//	cout << "The operand string is less than "
	//	<< "the parameter C-string." << endl;
	//else if (comp4a == 0)
	//	cout << "The operand string is equal to "
	//	<< "the parameter C-string." << endl;
	//else
	//	cout << "The operand string is greater than "
	//	<< "the parameter C-string." << endl;
	//cout << endl;

	//// The fifth member function compares part of
	//// an operand string to a parameter C-string
	//int comp5a;
	//string s5o("AACAB");
	//const char* cs5p = "CAB";
	//cout << "The operand string is: " << s5o << endl;
	//cout << "The parameter string is: " << cs5p << endl;
	//comp5a = s5o.compare(2, 3, s2p);
	//if (comp5a < 0)
	//	cout << "The last three characters of "
	//	<< "the operand string\n are less than "
	//	<< "the parameter C-string." << endl;
	//else if (comp5a == 0)
	//	cout << "The last three characters of "
	//	<< "the operand string\n are equal to "
	//	<< "the parameter C-string." << endl;
	//else
	//	cout << "The last three characters of "
	//	<< "the operand string\n is greater than "
	//	<< "the parameter C-string." << endl;
	//cout << endl;

	//// The sixth member function compares part of
	//// an operand string to part of an equal length of
	//// a parameter C-string
	//int comp6a;
	//string s6o("AACAB");
	//const char* cs6p = "ACAB";
	//cout << "The operand string is: " << s6o << endl;
	//cout << "The parameter C-string is: " << cs6p << endl;
	//comp6a = s6o.compare(1, 3, cs6p, 3);
	//if (comp6a < 0)
	//	cout << "The 3 characters from position 1 of "
	//	<< "the operand string are less than\n "
	//	<< "the first 3 characters of the parameter C-string."
	//	<< endl;
	//else if (comp6a == 0)
	//	cout << "The 3 characters from position 2 of "
	//	<< "the operand string are equal to\n "
	//	<< "the first 3 characters of the parameter C-string."
	//	<< endl;
	//else
	//	cout << "The 3 characters from position 2 of "
	//	<< "the operand string is greater than\n "
	//	<< "the first 3 characters of the parameter C-string."
	//	<< endl;
	//cout << endl;

	//若参与比较的两个串值相同，则函数返回 0；若字符串 S 按字典顺序要先于 S2，则返回负值；反之，则返回正值。
	/*string A("aBcedf");
	string B("AbcdEf");
	string C("123456");
	string D("123dfg");
	int m = A.compare(B);
	int n = A.compare(1, 5, B);
	int p = A.compare(1, 5, B, 4, 2);
	int q = C.compare(0, 3, D, 0, 3);
	cout << "m = " << m << ", n = " << n << ", p = " << p << ", q = " << q << endl;
	cin.get();*/
	
	
	
	/*string A("a");
	string B("A");*/
	/*int m = A.compare(B);
	cout << m << endl;*/
	
	/*string s(2, 'xa');
	string s2(1, 'x');
	string s3(3, '123');
	string s4("x");
	cout << s << " " << s2 << " " << s3 << endl;
	cout << s4 << endl;*/

	string str1("123456");
	string str;
	str.assign(str1);
	cout <<"str:"<<str<<" "<<"str1:"<< str1 << endl;
	str.assign(str1,3,3);
	cout << "str:" << str << endl;
	str.assign(str1,2,str1.npos);//赋值给从位置 2 至末尾的子串
	cout << "str:" << str << endl;
	str.assign(5,'X');
	cout << str << endl;
	string::iterator itB;
	string::iterator itE;
	itB = str1.begin();
	itE = str1.end();
	str.assign(itB,(--itE));
	cout << str << endl;
	return 0;

	
}
