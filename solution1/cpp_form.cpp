//类的组织，书写规范
//类的定义代码放在一个.h文件中,头文件可以跟类名相同
//类的具体实现代码，放在一个.cpp文件中

//NULL和nullptr使用
//对于指针的初始化，用到和指针有关的场合，能用nullptr则用nullptr


//内存
//涉及cpp中内存分配和释放使用new/delete，而不是malloc/free


//std::endl和/n
//使用endl，endl包含/n,且还能刷新缓存区


//c++11中，后置返回类型。在函数声明和定义中，把返回类型写在参数列表之后
auto func123(int a, int b) -> void;
auto func123(int a, int b) -> void {}


//内联函数(函数体很小，调用很频繁时使用)
//1.inline影响编译器，编译阶段，系统尝试将调用该函数的动作替换为函数本体，来提升性能
//2.inline只是开发者对编译器建议，取决于编译器诊断功能
//3.内联函数的定义放在头文件中。这样需要用到这个内联函数的.cpp文件都能通过#inlcude把这个内联函数源代码 #include进来
//constexpr函数可看作更严格的一种内联函数
//define宏展开也类似inline


//函数形参中带const()
//1.防止无意中修改形参值，导致实参值被修改
//2.实参类型可以更灵活。
//形参中const 和 &配合很好



//conclusion:在for语句中，尤其是遍历一个容器的类似操作中，千万不要修改vector容量，增加和删除都不可以
//不要写出下面这种代码
vector<int> vecvalue{ 1,2,4,5,6 };
for (auto vecitem : vecvalue)
{
	vecvalue.push_back(123);//导致输出乱套
	cout << vecitem << endl;
}


//尽量用迭代器访问容器中的元素
