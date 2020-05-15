- [线性表顺序存储](#-------)
  * [定义](#--)
  * [习题](#--)
    + [1.两个增序的顺序表合并，使新的顺序表也是增序](#1---------------------)
    + [[2.整数反转](https://leetcode-cn.com/problems/reverse-integer/)](#-2------https---leetcode-cncom-problems-reverse-integer--)
- [线性表链式存储](#-------)
  * [定义](#---1)
    + [1.头插法创建单链表](#1--------)
    + [2.尾插法创建单链表](#2--------)
  * [习题](#---1)
    + [[3.两数相加](https://leetcode-cn.com/problems/add-two-numbers/)](#-3------https---leetcode-cncom-problems-add-two-numbers--)
    + [[4.合并两个有序链表](https://leetcode-cn.com/problems/merge-two-sorted-lists/)](#-4----------https---leetcode-cncom-problems-merge-two-sorted-lists--)
    + [[5.删除链表的倒数第N个节点](https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list/)](#-5--------n-----https---leetcode-cncom-problems-remove-nth-node-from-end-of-list--)
    + [[6.两数之和](https://leetcode-cn.com/problems/two-sum/)](#-6------https---leetcode-cncom-problems-two-sum--)
    + [[7.反转链表](https://leetcode-cn.com/problems/reverse-linked-list/)](#-7------https---leetcode-cncom-problems-reverse-linked-list--)

<small><i><a href='http://ecotrust-canada.github.io/markdown-toc/'>Table of contents generated with markdown-toc</a></i></small>

# 线性表顺序存储
## 定义
```cpp
#define MAXSIZE 50
typedef struct{
    ElemType data[MAXSIZE];
    int length;
}SList;
```
## 习题
### 1.两个增序的顺序表合并，使新的顺序表也是增序
_思路：_
* 迭代
* 按顺序不断取下两个顺序表表头较小的节点存入新的顺序表中
* 讲剩余的表直接接上
```cpp
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
### [2.整数反转](https://leetcode-cn.com/problems/reverse-integer/)
给出一个 32 位的有符号整数，你需要将这个整数中每位上的数字进行反转。
示例1：
```
输入: 123
输出: 321
```
示例2：
```
输入: -123
输出: -321
```
示例3:
```
输入: 120
输出: 21
```
注意：
假设我们的环境只能存储得下 32 位的有符号整数，则其数值范围为 [−2^31,  2^31 − 1]。请根据这个假设，如果反转后整数溢出那么就返回 0。

_思路:_
* 注意根据范围判定是否溢出
* 2^31 − 1最后一位为7，2^31最后一位为8
```cpp
class Solution {
public:
    int reverse(int x) {
        int min=INT_MIN;
        int max=INT_MAX;
        int result = 0;
        while(x != 0)
        {
            int a = x%10;  
            x = x/10;
            if(result > max/10 || (result == max/10 && a>7)){
                return 0;
            }
            if(result < min/10 || (result == min/10 && a<-8)){
                return 0;
            }
            result = result * 10 + a;
        }
        return result;
    }
};
```

# 线性表链式存储
## 定义
```cpp
typedef struct LNode{
    ElemType data;
    struct LNode *next;
}LNode, *LinkList;
```

### 1.头插法创建单链表
注意：使用头插法建立单链表时，读入数据的顺序与生成的链表中的元素顺序相反
```cpp
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
### 2.尾插法创建单链表
```cpp
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
## 习题
### [3.两数相加](https://leetcode-cn.com/problems/add-two-numbers/)
给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。

如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。

您可以假设除了数字 0 之外，这两个数都不会以 0 开头。

示例：
```
输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
输出：7 -> 0 -> 8
原因：342 + 465 = 807
```
_思路：_
* 设置一个carry 考虑进位
* 相加时NULL 处理为按照0相加
* 注意考虑最后一位carry
```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* p = l1;
        ListNode* q = l2;
        ListNode* l3 = new ListNode(0);
        ListNode* r = l3;
        int carry = 0;
        int sum = 0;
        while((p != NULL) || (q != NULL))
        {
            int x = 0;
            int y = 0;
            if(p != NULL){
                x = p->val;
            }
            if(q != NULL){
                y = q->val;
            }
            sum = x + y + carry;
            carry = sum/10;
            r->next = new ListNode(sum%10);
            r = r->next;
            if(p != NULL)
                p=p->next;
            if(q != NULL)
                q=q->next;
        }
        if(carry > 0)
        {
            r->next = new ListNode(1);
            r = r->next;
        }
        r->next = NULL;
        return l3->next;
    }
};
```
### [4.合并两个有序链表](https://leetcode-cn.com/problems/merge-two-sorted-lists/)
将两个升序链表合并为一个新的升序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。

示例：
```
输入：1->2->4, 1->3->4
输出：1->1->2->3->4->4
```
_思路：_
* 迭代
* 当 l1 和 l2 都不是空链表时，判断 l1 和 l2 哪一个链表的头节点的值更小，将较小值的节点添加到结果里，当一个节点被添加到结果里之后，将对应链表中的节点向后移一位。
* 合并后 l1 和 l2 最多只有一个还未被合并完，我们直接将链表末尾指向未合并完的链表即可
```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *p = l1;
        ListNode *q = l2;
        ListNode *l3 = new ListNode(0);
        ListNode *r = l3; 
        while((p!= NULL) && (q != NULL))
        {
            if(p->val >= q->val){
                r->next = new ListNode(q->val);
                r = r->next;
                q=q->next;
            }else{
                r->next = new ListNode(p->val);
                r = r->next;
                p=p->next;
            }
        }
        r->next = p?p:q;
        return l3->next; 
    }
};
```
### [5.删除链表的倒数第N个节点](https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list/)
给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。

示例：
```
给定一个链表: 1->2->3->4->5, 和 n = 2.

当删除了倒数第二个节点后，链表变为 1->2->3->5.
```
说明：

给定的 n 保证是有效的。

进阶：

你能尝试使用一趟扫描实现吗？

_思路_
* 使用双指针法
* 第一个指针先走n步（下面我添加了自己的头节点，走n+1步）
* 完成上面以后，2个指针同时移动，直到first pointer = nullptr
```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* newhead = new ListNode(0);
        newhead->next = head;
        ListNode* first = newhead;
        ListNode* second = newhead;
        for(auto i = 0; i <= n ; i++)
        {
            first = first->next;
        }
        while(first != nullptr)
        {
            first = first->next;
            second = second->next;
        }
        second->next = second->next->next;//跳过要删除的节点
        return newhead->next;
    }
};
```
### [6.两数之和](https://leetcode-cn.com/problems/two-sum/)
给定一个整数数组 ```nums``` 和一个目标值 ```target```，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。

你可以假设每种输入只会对应一个答案。但是，数组中同一个元素不能使用两遍。

示例:
```
给定 nums = [2, 7, 11, 15], target = 9

因为 nums[0] + nums[1] = 2 + 7 = 9
所以返回 [0, 1]
```

_思路：_
* 直接遍历即可
* O（n^2）
```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for(auto i = 0; i < nums.size() - 1; ++i)
        {
            for(auto j = i+1; j < nums.size(); ++j)
            {
                if((nums[i] + nums[j]) == target)
                {
                    return {i,j};
                }
            }
        }
        return{};
    }
};
```

### [7.反转链表](https://leetcode-cn.com/problems/reverse-linked-list/)

反转一个单链表。

示例：
```
输入: 1->2->3->4->5->NULL
输出: 5->4->3->2->1->NULL
```
进阶:
你可以迭代或递归地反转链表。你能否用两种方法解决这道题？

_思路：_

* 定义两个指针： pre 和 cur ；pre 在前 cur 在后
* 实现局部反转以后移动
* 参考[huwt的思路](https://leetcode-cn.com/problems/reverse-linked-list/solution/fan-zhuan-lian-biao-shuang-zhi-zhen-di-gui-yao-mo-/)
```cpp
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* cur = NULL,*pre = head;
        while(pre!=NULL){
            ListNode* temp = pre->next; 
            pre->next = cur;
            cur = pre;
            pre = temp;
        }
        return cur;
    }
};
```


