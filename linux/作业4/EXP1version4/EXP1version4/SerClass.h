#ifndef _SERCLASS_H_
#define _SERCLASS_H_

//定义为抽象基类
//声明为纯虚函数，让派生类去实例化
//派生类必须实现这些函数才能实例化

class SerClass
{
public:
	SerClass() {

	};
	virtual ~SerClass() {

	};
public:
	virtual bool Serialize(int fd)const = 0 ;
	virtual bool Deserialize(int fd) = 0;     //返回bool值
	virtual SerClass* DeserializePtr(int fd) = 0;//返回对象指针而不是bool
	virtual int getType() = 0;
};


#endif // !_SERCLASS_H_


