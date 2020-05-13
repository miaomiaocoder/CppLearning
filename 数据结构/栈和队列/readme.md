## 栈的顺序存储结构
### 定义
```cpp
#define MAXSIZE 50
typedef struct{
    ElemType data[MAXSIZE];  //存放栈中元素
    int top;   //栈顶指针
}SqStack;
```
初始设置: ```S.top = -1 ```;

栈顶元素：```S.data[top]```

进栈操作：```S.data[++S.top] = x```  指针先加1，再入栈

出栈操作：```x = S.data[S.top--]```  先出栈，指针再减1

栈空条件：```S.top == -1```

栈满条件：```S.top = MAXSIZE + 1```

栈长：```S.top + 1```

## 两个栈共享空间
### 定义
```cpp
#define MAXSIZE 200
typedef struct{
    ElemType elem[MAXSIZE];
    int top[2];
}DuSqStack;
```
判空与判满
* 满：```ds.top[0] + 1 == ds.top[1]```
* 左栈空：```ds.top[0] == -1```
* 右栈空：```ds.top[1] == MAXSIZE```

入栈
* 左入```s.top[0]++```;
* 右入```s.top[1]--```;

出栈
* 左出```s.top[0]--```;
* 右出```s.top[1]++```;

## 栈的链式存储结构

### 定义
```cpp
typedef struct Linknode{
    ElemType data;
    struct Linknode *next;
}*LiStack;
```

## 队列的顺序存储
### 定义
```cpp
#define MAXSIZE 50
typedef struct{
    ElemType data[MAXSIZE];  //存放队列元素
    int front, rear;  //front 队头（队首）指针， rear 队尾指针
}SqQueue;
```

## 队列的链式存储
### 定义
```cpp
typedef struct{      //链式队列结点
    ElemType data;
    struct LinkNode *next;
}LinkNode;
typedef struct{     //链式队列
    LinkNode *front, *rear;   //队列的队头和队尾指针
}LinkQueue;
```
