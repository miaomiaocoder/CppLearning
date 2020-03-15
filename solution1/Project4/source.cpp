//#include<iostream>
//#include<vector>
//using namespace std;
//struct student {
//	int num;
//};
//int main()
//{
//	//迭代器是一种遍历容器内的元素的数据类型
//	//理解：迭代器用来指向容器中的某个元素
//	//string,vector []很少,更常用迭代器访问（更通用）
//	//通过迭代器访问容器中的元素值或string中的每个字符，还可以修改某个迭代器所指向的元素值
//	//++， --
//	//
//	//
//	//vector<int> iv1 = { 100,200,300 };
//	//vector<int>::iterator iter;//定义迭代器
//	//这个iter变量就是个迭代器
//
//	//迭代器begin()/end()操作，反向迭代器rbegin()/rend()操作
//	//begin()/end()用来返回迭代类型
//	//iter = iv1.begin();//如果容器中有元素，则begin返回迭代器，指向的是容器中的第一个元素
//	//相当于iter 指向了iv[0]
//	//end()返回一个迭代器类型
//	//iter = iv1.end();//end返回的迭代器指向的并不是末端元素，而是末端元素的后边
//	//理解;end()指向的是一个不存在的元素
//
//	//如果一个容器为空,那么begin()/end()返回的迭代器相同
//	//vector<int> iv2;
//	//vector<int>::iterator iterbegin = iv2.begin();
//	//vector<int>::iterator iterend = iv2.end();
//	//if (iterbegin == iterend)
//	//{
//	//	cout << "容器iv2为空" << endl;
//	//}
//
//	//vector<int> iv = { 100 ,200, 300 };
//	//for (vector<int>::iterator iter = iv.begin(); iter != iv.end(); iter++)
//	//{
//	//	cout << *iter << endl;
//	//}
//	////反向迭代器,从后往前遍历,用rbegin(),rend()
//	////rbegin():返回一个反向迭代器，指向反向迭代器的第一个元素
//	////rend()：返回一个反向迭代器，指向反向迭代器最后一个元素的下一个位置
//	//for (vector<int>::reverse_iterator riter = iv.rbegin(); riter != iv.rend(); riter++)
//	//{
//	//	cout << *riter << endl;//300,200,100
//	//}
//
//	//迭代器运算符
//	//*iter：返回迭代器iter所指向的元素的引用
//	//必须要保证这个迭代器有效的容器元素，不能指向end();
//	//vector<int>::iterator iter = iv.end();
//	//cout << *iter << endl;报错
//
//
//	//vector<int> iv = { 100 ,200, 300 };
//	//++iter;iter++；让迭代器指向容器中的下一个元素
//	//已经指向end不能再++
//
//	//iter1 == iter2 , iter1 != iter2
//	//如果两个迭代器指向同一个元素，就相等
//
//
//	//引用结构中的成员
//	//vector<student> sv;
//	//student mystu;
//	//mystu.num = 100;
//	//sv.push_back(mystu);//把mystu拷贝到sv容器中
//
//	//vector<student>::iterator iter;
//	//iter = sv.begin(); //指向第一个元素
//	//cout << (*iter).num << endl;
//	//cout << iter->num << endl;
//
//	//const_iterator迭代器, const:常量
//	//const_iterator迭代器表示值不能改变，表示迭代器指向的元素值不能改变
//	//而不是表示这个迭代器本身不能改变，也就是迭代器可以不断指向下一个元素
//	//只能从容器中读元素，不能通过这个迭代器改写容器的元素，感觉起来更像常量指针
//	//vector<int> iv = { 100,200,300 };
//	//vector<int>::const_iterator iter;
//	//for (iter = iv.begin(); iter != iv.end(); ++iter)
//	//{
//	//	//*iter = 4; //error
//	//	cout << *iter << endl;
//	//}
//
//	//cbegin() ，cend()
//	//c++11引入,跟begin, end 类似, cbegin,cend返回的都素常量迭代器
//
//	//vector<int> iv = { 100,200,300 };
//	//for (auto iter = iv.cbegin(); iter != iv.cend(); ++iter)
//	//{
//	//	//*iter = 4; //error,cbegin返回的是常量迭代器
//	//	cout << *iter << endl;
//	//}
//	//
//	//return 0;
//
//	//迭代器失效
//	//vector<int> vecvalue{1,2,3,4,5};
//	//for (auto vecitem : vecvalue)
//	//{
//	//	vecvalue.push_back(13);//导致输出彻底混乱
//	//	cout << vecitem << endl;
//	//}
//
//	//for (auto beg = vecvalue.begin(), end = vecvalue.end(); beg != end; ++beg)
//	//{
//	//	vecvalue.push_back(213);
//	//	cout << *beg << endl;
//	//}
//	
//	//操作迭代器过程中，使用了迭代器这种循环体，千万不要改变vector容器的容量
//	//也就是不要增加或者删除vector容器的元素,可能会使指向容器的元素的指针，引用，迭代器失效
//	
//	/*vector<int> vecvalue{ 1,2,3,4,5 };
//	for (auto beg = vecvalue.begin(), end = vecvalue.end(); beg != end; ++beg)
//	{
//		vecvalue.push_back(213);
//		
//		break;
//	}
//	for (auto beg = vecvalue.begin(), end = vecvalue.end(); beg != end; ++beg)
//	{		
//		cout << *beg << endl;
//	}*/
//
//
//	
//
//	//vector<int> vecvalue{ 1,2,3,4,5 };
//	//auto beg = vecvalue.begin();
//	//auto end = vecvalue.end();
//	//while (beg != end)
//	//{
//	//	cout << *beg << endl;
//
//	//	//在begin这个位置插入新值，可以用insert
//	//	vecvalue.insert(beg, 80);
//	//	//第一个参数为插入位置，第二个参数为插入的元素
//	//	//这个操作肯定会导致迭代器失效
//	//	//最明智做法，只要插入，立即break
//	//	break;
//
//	//	++beg;
//	//}
//
//	//beg = vecvalue.begin();
//	//end = vecvalue.end();
//	//while (beg != end)
//	//{
//	//	cout << *beg << endl;
//
//
//	//	++beg;
//	//}
//	
//	//vector<int> vecvalue{ 1,2,3,4,5 };
//	//auto beg = vecvalue.begin();
//	//int icount = 0;
//	//
//	//while (beg != vecvalue.end())//每次更新end防止end迭代器失效
//	//{
//	//	beg = vecvalue.insert(beg, icount+80);
//	//	icount++;
//	//	if (icount > 10)
//	//		break;
//
//	//	++beg;
//	//}
// //   beg = vecvalue.begin();
//	//auto end = vecvalue.end();
//	//while (beg != end)
//	//{
//	//	cout << *beg << endl;
//
//
//	//	++beg;
//	//}
//	
//	//灾难程序
//	//vector<int> iv = { 100,200,300 };
//	//for (auto iter = iv.begin(); iter != iv.end(); ++iter)
//	//{
//	//	//iv.erase(iter);//这种方法出问题
//	//	iter = iv.erase(iter);//erase函数，移除iter位置上的元素，返回下一个元素位置
//	//						  //这种方法也出问题
//	//}
//
//	//vector<int>::iterator iter = iv.begin();
//	//while (iter != iv.end())
//	//{
//	//	iter = iv.erase(iter);
//	//}//一个一个删除
//
//	//iv.clear();//直接清空
//
//	//while (!iv.empty())
//	//{
//	//	auto iter = iv.begin();
//	//	iv.erase(iter);
//	//}//一种比较好的清空方式
//
//	
//	return 0;
//	
//}