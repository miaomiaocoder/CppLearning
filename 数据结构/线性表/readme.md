## 线性表顺序存储
### 定义
```
#define MAXSIZE 50
typedef struct{
    ElemType data[MAXSIZE];
    int length;
}SList;
```
### 习题
### 两个增序的顺序表合并，使新的顺序表也是增序
```
bool Merge(SList A, SList B, SList &C)
{
    if(A.length+B.length > C.Maxsize)
        return false;
    int i = 0, j = 0, k = 0;
    while(i<A.length && j<B.length)
    {
        if(A.data[i] <= B.data[j]){
            C.data[k] = A.data[i];
            i++;
        }else{
            C.data[k] = B.data[j];
            j++;
        }
    }
    while(i < A.length)
        C.data[k++] = A.data[i++];
    while(i < B.length)
        C.data[k++] = B.data[j++];
    C.length = k;
    return true;
}
```
## 线性表链式存储
### 定义
```
typedef struct LNode{
    ElemType data;
    struct LNode *next;
}LNode, *LinkList;
```

### 头插法创建单链表
注意：使用头插法建立单链表时，读入数据的顺序与生成的链表中的元素顺序相反
```
struct node
{
    int data;
    struct node *next;
};

typedef struct node node;

node*Creat(int Count)
{
    node*p, *head;
    int n;
    srand(time(NULL));
    head = (node*)malloc(sizeof(node));
    head->data = Count;
    head->next = NULL;
    for(n = 0; n < Count; n++)
    {
        p = (node*)malloc(sizeof(node));
        p->data = rand()%10000;
        //2行关键代码
        p->next = head->next;  
        head->next = p;
    }
    return(head);
}
```
### 尾插法创建单链表
```
struct node
{
    int data;
    struct node *next;
};

typedef struct node node;

node*Creat(int Count)
{
    node*p1, *p2, *head;
    int n;
    srand(time(NULL));
    head = p1 = (node*)malloc(sizeof(node));//p1为指向表尾结点的指针
    head->data = rand()%10000;
    head->next = NULL;
    for(n = 1; n < Count; n++)
    {
        p2 = (node*)malloc(sizeof(node));//p2为新申请的节点
        p2->data = rand()%10000;
        //3行关键代码
        p1->next = p2;//将表尾指针的指向新节点
        p1 = p2;//将当前的新节点定义为表尾终端节点
    }
    p1->next = NULL; //循环结束尾节点指针赋值为NULL
    return(head);
}
```
