#include<iostream>
#include<vector>
#include<string>


using namespace std;
struct student {
	int num;
};
int main()
{
	//嵌套形成可变长的二维数组
	vector<vector<int> > v(3); //v有3个元素，每个元素都是vector<int> 容器
	for (int i = 0; i < v.size(); ++i)
		for (int j = 0; j < 4; ++j)
			v[i].push_back(j);
	for (int i = 0; i < v.size(); ++i) {
		for (int j = 0; j < v[i].size(); ++j)
			cout << v[i][j] << " ";
		cout << endl;
	}


	//vector 对象上的操作，往往 需要动态增加/减少
	//一般创建空vector
	//vector很多操作类似string
	//bool empty();
	vector<int> hua;
	if (hua.empty())
	{
		cout << "hua为空" << endl;
	}

	hua.push_back(1);
	hua.push_back(2);
	//void push_back(const T&val);将 val 添加到容器末尾
	for (int i = 3; i <= 100; i++)
	{
		hua.push_back(i);
	}

	//size:返回元素个数
	cout << hua.size() << endl;

	//clear:移除所有元素，清空容器
	//void clear();
	/*hua.clear();
	cout << hua.size() << endl;*/

	cout << hua[0] << endl; //打印1

	vector<int> ivec;
	ivec.push_back(111);
	ivec = hua; //ivec得到100个元素,ivec原来的元素被冲掉了
	ivec = { 12,13,14,15 };//用{}取代ivec原有的值
	cout << ivec.size() << endl;
	
	// == , !=
	//2个vector相等，元素数量相同，对应位置元素值相同
	vector<int>ivec2;
	ivec2 = ivec;
	if (ivec2 == ivec)
	{
		cout << "ivec2 == ivec" << endl;
	}
	ivec2.push_back(123);
	if (ivec2 != ivec)
	{
		cout << "ivec2 != ivec" << endl;
	}

	ivec.clear();
	ivec2.clear();
	if (ivec == ivec2)
	{
		cout << "ivec == ivec2" << endl;
	}

	//范围for应用
	vector<int> vecvalue{ 1,2,4,5,6 };
	for (auto vecitem : vecvalue)
	{
		cout << vecitem << endl;;
	}

	cout << endl;

	for (auto &vecitem : vecvalue)
	{
		vecitem *= 2;//扩大一倍
	}

	for (int vecitem: vecvalue)
	{
		cout << vecitem << endl;;
	}

	//范围for进一步
	for (auto vecitem : vecvalue)
	{
		vecvalue.push_back(123);//导致输出乱套
		cout << vecitem << endl;
	}
	//conclusion:在for语句中，尤其是遍历一个容器的类似操作中，千万不要修改vector容量，增加和删除都不可以

	return 0;
}