#include<iostream>
#include"TimeClass.h"
using namespace std;

class student {
public:
	char name[100];
	int number;
};

void func(int a, int b = 12)
{
	return;
}

void func1(TimeClass myt)
{

}
int main()
{
	//func(6);
	//func(12, 18);


	//类是我们字节定义的数据类型（新类型）
	//设计类时要考虑角度
	//1.设计者和实现者
	//2.站在使用者
	//3.父类，子类

	//类是用户字节定义的数据类型，把类想象成一个命名空间
	//一个类构成主要：成员变量，成员函数（有许多特殊成员函数）
	//
	//student someone;
	//someone.number = 1000;
	//student *psomeone = &someone;
	//psomeone->number = 1005;

	//cout << someone.number << endl;

	//TimeClass mytime;
	//mytime.initTime(11, 14, 15);
	//cout << mytime.Hour << endl;
	//cout << mytime.Minute << endl;
	//cout << mytime.Second << endl;

	//对象拷贝
	//
	//TimeClass myTime;
	/*myTime.Hour = 12;
	myTime.Minute = 15;
	myTime.Second = 40;

	TimeClass myTime2 = myTime;
	TimeClass myTime3(myTime);
	TimeClass myTime4{ myTime };
	TimeClass myTime5 = { myTime };
	myTime5.Hour = 8;*/

	//TimeClass myTime;
	//myTime.Hour = 15;
	//cout << myTime.Hour << endl;
	//cout << myTime.Minute << endl;
	//cout << myTime.Second << endl;

	//在类中，有一种特殊的成员函数，名字和类名相同，我们在创建类的对象时候
	//这个特殊的成员函数会被系统自动调用，这个成员函数，叫做“构造函数”
	//构造函数的目的是初始化类的数据成员

	//1)构造函数没有返回值
	//2)不可以手工调用构造函数，否则编译会出错
	//3）正常情况下构造函数应该被声明为public
	//我们创建一个对象时，要替我们调用构造函数，这说明构造函数它是一个public函数，才能够被系统（外界）调用
	//因为类缺省的成员是私有成员，所以我们必须声明构造函数是一个public函数，否则无法创建该类的对象
	//4）构造函数中如果有多个参数，则我们创建对象的时候也要带上这些参数

	//TimeClass myTime = TimeClass(12, 12, 52);
	//TimeClass myTime2(12,13,52);
	//TimeClass myTime3 = TimeClass(12, 13, 52);
	//TimeClass myTime4{ 12,13,53 };
	//TimeClass myTime5 = {12,13,52};

	////TimeClass myTime6();
	////TimeClass myTime7(12,13);

	////多个构造函数
	////一个类中可以有多个构造函数，可以为类对象的创建提供多种初始化方法
	////但是多个构造函数总要有点不一样的地方

	//TimeClass myTime10 = TimeClass();
	//cout <<"1"<< endl;
	//TimeClass myTime11();
	//cout <<"1"<< endl;
	//TimeClass myTime12 = TimeClass();
	//TimeClass myTime13{};
	//TimeClass myTime14 = {};

	////对象拷贝
	////如下4个对象并没有调用传统意义上的构造函数，他们调用的是拷贝构造函数
	//TimeClass myTime15 = myTime10;
	//TimeClass myTime16 = (myTime10);
	//TimeClass myTime17{ myTime10 };
	//TimeClass myTime18 = {myTime10};

	//函数默认参数
	//规定：
	//1）默认值只能放在函数声明中，除非该函数没有声明
	//2）在具有多个参数的函数中指定默认值，默认参数必须出现在不默认参数的右边
	//一旦某个参数开始指定默认值，它右边的参数必须指定默认值
	/*TimeClass myTime19 = TimeClass(12, 12);
	TimeClass myTime20(12, 13);
	TimeClass myTime21 = TimeClass(12, 13);
	TimeClass myTime22{ 12,13 };
	TimeClass myTime23 = { 12,13};*/


	//隐式转换和explicit
	//
	//TimeClass myTime40 = 14;//编译器有个行为，把14转换成了TimeClass类类型对象 //调用了单参数的构造函数
	//TimeClass myTime41 = (12, 13, 14, 15, 16);//调用了单参数的构造函数

	//func1(16);//16被转换成了一个临时的Time对象，导致func1的调用能够成功
	//调用了单参数的构造函数

	//TimeClass myTime100 = { 16 };
	//认为此写法正常，带一个参数16，可以让系统明确的知道调用哪个构造函数

	//TimeClass myTime101 = 16;
	//含糊不清的写法，就存在临时对象隐式转换

	//func1(16);//也是糊不清的写法，就存在临时对象隐式转换

	//如果构造函数声明中带有explicit,则这个构造函数只能用于初始化和显示类型转换

	/*TimeClass myTime = TimeClass(12, 12, 52);
	TimeClass myTime2(12,13,52);
	TimeClass myTime3 = TimeClass(12, 13, 52);
	TimeClass myTime4{ 12,13,53 };*/
	//TimeClass myTime5 = {12,13,52}; //隐式类型转换//error
	//复制列表初始化不能标注为“显示”的构造函数

	TimeClass myTime100 = { 16 };
	TimeClass myTime101 = 16;
	func1(16);


	return 0;
}