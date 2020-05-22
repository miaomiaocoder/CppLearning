## c++对象序列化
使用vs2017远程连接ubuntu

## 版本一
* 将一个类的一个对象序列化到文件
```cpp
class CA_LL
{
int i;
public:
  bool Serialize(const char* pFilePath);
  bool Deserialize(const char* pFilePath);
};

```

## 版本二
* 将一个类的多个对象序列化到文件
```cpp
class SerializerForClassA
{
public:
	bool Serialize(const char*pFilePath, vector<ClassA>&v);
	bool Deserialize(const char*pFilePath, vector<ClassA>&v);
};
```
## 版本三
* 将两个不同类的多个对象序列化到文件
* 采用结构体的方法解决
```cpp
struct Serialized
{
   int  nType; //0 for A; 1 for B
   void *pObj;
};
 
```

## 版本四
* 将三个不同类的多个对象序列化到文件
* 采用面向对象的方法，使用一个抽象基类
```cpp
class SerClass
{
public:
	SerClass() {

	};
	virtual ~SerClass() {

	};
public:
	virtual bool Serialize(int fd)const = 0 ;
	virtual bool Deserialize(int fd) = 0;     
	virtual SerClass* DeserializePtr(int fd) = 0;
	virtual int getType() = 0;
};
```
