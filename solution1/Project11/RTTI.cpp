#include"Human.h"
#include"Men.h"
#include"Women.h"
#include<iostream>
using namespace std;
int main()
{
	//RTTI "Run-Time Type Identification" 运行时类型识别
	//通过运行时类型识别，程序能够使用基类的指针或者引用来检查这些指针或者引用所指的对象的实际派生类别
	
	//Human *phuman = new Men;
	//Human &p = *phuman; //*phuman表示指针phuman所指向的对象
	
	//RTTI看作功能，这种功能通过2个运算符来体现
	//1）dynamic_cast运算符：能够把基类的指针或者引用安全的转换为派生类的指针或引用
	//2）typeid运算符：返回指针或者引用所指对象的实际类型
	//要写让RTTI的两个运算符能正常工作，那么基类中必须至少要有一个虚函数，否则可能会跟预测结果不一样
	//因为只有虚函数存在，这两个运算符才会使用指针或者引用所绑定的对象的动态内容（你new的类型）
	

	//phuman->eat();
	//phuman->testfunc();

	//dynamic_cast运算符，如果该运算符能够转换成功，说明这个指针实际上是要转换到的那个类型。这个运算符能够帮我们做安全检查
	//Human *phuman = new Men;
	//Men *p = (Men*)(phuman);//用c语言风格的强制类型转换
	//p->testfunc();//能够正常调用Men类的成员函数testfunc();

	//Women *p1 = (Women*)(phuman);
	//容易出问题
	
	//Human *phuman = new Men;
	//Men *pmen = dynamic_cast<Men*>(phuman);
	//if (pmen != nullptr)
	//{
	//	std::cout << "phuman实际上是一个Men类型" << std::endl;
	//	//在这里操作类Men里边的成员函数，成员变量都能够操作并且安全的操作
	//	pmen->testfunc();
	//}else
	//{
	//	//转换失败
	//	std::cout << "phuman不是一个Men类型" << std::endl;
	//}

	//对于引用，如果用dynamic_cast转换失败，则系统会抛出一个std::bad_cast异常try()..catch(){}
	//Human *phuman = new Men;
	//Human &q = *phuman;
	//try
	//{
	//	Men menbm = dynamic_cast<Men&>(q);//转换不成功，则流程直接进入到catch里边去，如果转换成功，流程继续往下走
	//	//success
	//	std::cout << "phuman实际上是一个Men类型" << std::endl;
	//	menbm.testfunc();
	//}
	//catch (std::bad_cast)
	//{
	//	std::cout << "phuman实际不是一个Men类型" << std::endl;
	//}


	//typeid运算符
	//typeid(类型)；也可能typeid(表达式)
	//拿到对象类型信息；typeid就会返回一个常量对象的引用，这个常量对象是一个标准库类型type_info
	/*Human *phuman = new Men;
	Human &q = *phuman;
	std::cout << typeid(*phuman).name() << std::endl;
	std::cout << typeid(q).name() << std::endl;
	char a[10] = { 5,1 };
	int b = 120;
	std::cout << typeid(a).name() << std::endl;
	std::cout << typeid(b).name() << std::endl;
	std::cout << typeid(19.6).name() << std::endl;
	std::cout << typeid("adfs").name() << std::endl;*/

	//typeid主要是比较2个指针是否指向同一个类型
	//1）两个指针定义的类型相同（Human）,不管他们new的是啥，typeid都相等
	//该例子不符合我们要求
	/*Human *phuman = new Men;
	Human *phuman2 = new Women;
	if (typeid(phuman) == typeid(phuman2))
	{
		std::cout << "phuman和phuman2是同一种类型[看指针定义]" << std::endl;
	}*/

	//比较对象时，看的是new出来的是哪个对象，或者该指针指向的是哪个对象，和定义该指针时的类型没啥关系

	/*Human *phuman = new Men;
	Men *phuman2 = new Men;
	Human *phuman3 = phuman2;
	if (typeid(*phuman) == typeid(*phuman2))
	{
		std::cout << "phuman 和phuman2指向的对象类型相同" << std::endl;
	}
	if (typeid(*phuman3) == typeid(*phuman2)) 
	{
		std::cout << "phuman2 和phuman3指向的对象类型相同" << std::endl;
	}*/

	/*Human *phuman = new Men;
	if (typeid(*phuman) == typeid(Men))
	{
		std::cout << "phuman指向Men" << endl;
	}
	else if (typeid(*phuman) == typeid(Human))
	{
		cout << "phuman指向Human" << endl;
	}*/
	//基类必须要有虚函数，否则上边条件不成立
	//切记，只有基类有虚函数时，编译器才会对typeid()中的表达式求值，否则如果某个类型不含有虚函数
	//则typeid（）返回的是表达式的静态类型（定义时的类型）既然是定义的类型，编译器就不需要对表达式求值，也能知道表达式的静态类型

	//type_info类
	//标准库类型

	//a)  .name:名字：返回一个c风格字符串
	//Human *phuman = new Men;
	//const type_info &tp = typeid(*phuman);
	////cout << tp.name() << endl; //打印 class Men

	////b) ==, !=,
	//Human *phuman2 = new Men;
	//const type_info &tp2 = typeid(*phuman2);
	//if (tp == tp2)
	//{
	//	cout << "tp和tp2类型相同" << endl;
	//}
	//Human *phuman3 = new Women;
	//const type_info &tp3 = typeid(*phuman3);
	//if (tp == tp3)
	//{
	//	cout << "tp和tp3类型相同" << endl;
	//}


	//RTTI与虚函数表
	//c++如果类含有虚函数。编译器就会对该类产生一个虚函数表
	//虚函数表有很多项，每一项都是一个指针，每个指针指向的是这个类里各个虚函数的入口地址
	//虚函数表项里，第一个表项很特殊，它指向的不是虚函数的入口地址，它指向实际上是这个类所关联的type_info对象
	Human *phuman = new Men;
	const type_info &ty = typeid(*phuman);
	//phuman对象里有一个我们看不见的指针，这个指针指向的是这个对象所在的类Men里的虚函数表
	return 0;
}