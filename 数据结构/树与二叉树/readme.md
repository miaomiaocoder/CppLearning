# 二叉树的链式存储结构
## 定义
```cpp
typedef struct BiTNode{
    ElemType data;
    struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;
```
## 递归遍历
```cpp
//先序遍历，中左右
void PreOrder(BiTree T){
    if(T != NULL){
        visit(T);
        PreOrder(T->lchild);
        PreOrder(T->rchild);
    }
}
//中序遍历，左中右
void InOrder(BiTree T){
    if(T != NULL){
        PreOrder(T->lchild);
        visit(T);
        PreOrder(T->rchild);
    }
}
//后序遍历，左右中
void PostOrder(BiTree T){
    if(T != NULL){
        PreOrder(T->lchild);
        PreOrder(T->rchild);
        visit(T);
    }
}
```
```html
    A
   / \
  B   C
 /  \
D    E
```
## 非递归遍历(王道)
```cpp
//先序遍历非递归实现
//思路：
//与中序类似，把访问结点操作放在入栈操作前面
void PreOrder2(BiTree T){
    InitStack(S);//初始化栈
    BiTree p = T;//p是遍历指针
    while(p || !IsEmpty(S)){
        if(p){
            visit(p);
            push(S,p);    //访问当前结点，并入栈
            p = p->lchild;//左孩子不为空，一直往左走
        }else{            //出栈，并转向出栈结点的右子树
            pop(S,p);     //栈顶元素出栈
            p = p->rchild;//向右子树走，p赋值为当前结点的右孩子
        }                 //返回while循环继续进入if-else语句
    }//while
}

//中序遍历非递归实现
//思路：
//1.沿着根的左孩子，依次入栈，直至为空，说明已经找到可以输出的结点.
//2.栈顶元素出栈并访问：若其右孩子为空，继续执行2；
                    // 若其右孩子不为空，将右子树转执行1.
//本例中 //A,B,D已经入栈
        //栈顶D出栈并访问；
        //D的右孩子为空，栈顶B出栈并访问；
        //B的右孩子不为空，将E入栈，E左孩子为空，栈顶E出栈并访问；
        //E的右孩子为空，栈顶A出栈并访问；
        //A的右孩子不为空，将C入栈
        //C的左孩子为空，栈顶C出栈并访问
//最后得到 D B E A C
void InOrder2(BiTree T){
    InitStack(S);//初始化栈
    BiTree p = T;//p是遍历指针
    while(p || !IsEmpty(S)){
        if(p){
            push(S,p);    //访问当前结点，并入栈
            p = p->lchild;//左孩子不为空，一直往左走
        }else{            //出栈，并转向出栈结点的右子树
            pop(S,p);     //栈顶元素出栈
            visit(p);     //访问出栈结点
            p = p->rchild;//向右子树走，p赋值为当前结点的右孩子
        }                 //返回while循环继续进入if-else语句
    }//while
}

//后序遍历非递归实现
//思路：
//1.沿着根的左孩子，依次入栈，直到左孩子为空。
//2.读栈顶元素：若其右孩子不空且从未被访问过，将右子树转执行1；
             //否则，栈顶元素出栈并访问
//本例中
//A B D依次入栈
//D的右孩子为空，出栈并访问
//栈顶B的右孩子不为空，且从未被访问过，将E入栈，E的左右孩子均为空，出栈并访问
//栈顶B的右孩子不为空，但已经被访问过，B出栈并访问
//栈顶A的右孩子不空且从未被访问过，C入栈，栈顶C的左右孩子均为空，出栈并访问；
//栈顶A的右孩子不空但已经被访问, A出栈并访问。
//由此得到D E B C A
void PostOrder(BiTree T){
    InitStack(S);
    BiTree p = T;
    BiTree r = NULL;
    while(p||IsEmpty(S)){
        if(p){                 //走到最左边
            push(S,p); 
            p = p->lchild;
        }else{                 //向右
            GetTop(S,p);       //读栈顶元素（不是出栈）
            if(p->rchild && p->rchild != r){ //若右子树存在，且从未被访问过
                p = p->rchild; //转向右
                push(S,p);     //压栈
                p = p->lchild; //再走到最左
            }else{             //否则，弹出结点并访问
                pop(S,p);      //将该结点弹出
                visit(p->data);//访问结点
                r = p;         //记录最近访问的结点
                p = NULL;      //结点访问完以后，重置P指针
            }
        }//else
    }//while
}
//注意：每次出栈访问完一个结点就相当于遍历完以该结点为根的子树，需要将p置为NULL
```
## 层次遍历（王道）
_思路：_
* 借助队列
```cpp
void LevelOrder(BiTree T){
    InitQueue(Q);
    BiTree p;
    EnQueue(Q,T);//将根结点入队
    while(!IsEmpty(Q)){ //队列不为空则循环
        DeQueue(Q,P);   //队头结点出队
        visit(p);       //访问出队结点
        if(p->lchild!=NULL)
            EnQueue(Q, p->lchild); //左子树不空，则左子树根节点入队
        if(p->rchild!=NULL)
            EnQueue(Q, p->rchild); //右子树不空，则右子树根节点入队
    }
}
```

## leetcode习题
### [1.二叉树的前序遍历](https://leetcode-cn.com/problems/binary-tree-preorder-traversal/)
_思路1：_
* 套用递归实现即可
```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> v;
    vector<int> preorderTraversal(TreeNode* root) {
        if(root != NULL){
            v.push_back(root->val);
            preorderTraversal(root->left);
            preorderTraversal(root->right);
        }
        return v;
    }
};
```
_思路2:_
* 非递归实现
* 思路见上面
```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> stk;
        vector<int> ans;
        TreeNode* p = root;
        while(p != NULL||!stk.empty()){
            if(p){
                ans.push_back(p->val);
                stk.push(p);
                p = p->left;
            }else{
                p = stk.top();
                stk.pop();
                p = p->right;
            }
        }
        return ans;
    }
};
```
### [2.二叉树的中序遍历](https://leetcode-cn.com/problems/binary-tree-inorder-traversal/)
给定一个二叉树，返回它的中序遍历。
_思路1:_
* 递归实现
```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> v;
    vector<int> inorderTraversal(TreeNode* root) {
        if(root != NULL){
            inorderTraversal(root->left);
            v.push_back(root->val);
            inorderTraversal(root->right);
        }
        return v;        
    }
};
```
_思路2：_
* 非递归实现
* 思路见上面
```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) { 
        stack<TreeNode*> stk;
        vector<int> result;
        TreeNode* p = root;
        while(p != NULL || !stk.empty()){
            if(p){
                stk.push(p);
                p = p->left;
            }else{
                p = stk.top();
                stk.pop();
                result.push_back(p->val);
                p = p->right;
            }
        }
        return result;   
    }
};
```
### [3.二叉树的后序遍历](https://leetcode-cn.com/problems/binary-tree-postorder-traversal/)
_思路1:_
* 递归
```cpp
class Solution {
public:
    vector<int> v;
    vector<int> postorderTraversal(TreeNode* root) {
        if(root != NULL){
            postorderTraversal(root->left);
            postorderTraversal(root->right);
            v.push_back(root->val);
        }
        return v;
    }
};
```
_思路2：_
* 非递归实现
* 思路见上面
```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> stk;
        vector<int> ans;
        TreeNode* p = root;
        TreeNode* r = nullptr;
        while(p != nullptr || !stk.empty()){
            if(p){
                stk.push(p);
                p = p->left;
            }else{
                p = stk.top();
                if(p->right && p->right != r){
                    p = p->right;
                    stk.push(p);
                    p = p->left;
                }else{
                    stk.pop();
                    ans.push_back(p->val);
                    r = p;
                    p = nullptr;
                }
            }
        }
        return ans;
    }
};
```
### [4.二叉树的层平均值](https://leetcode-cn.com/problems/average-of-levels-in-binary-tree/)
给定一个非空二叉树, 返回一个由每层节点平均值组成的数组.
示例 1:
```
输入:
    3
   / \
  9  20
    /  \
   15   7
输出: [3, 14.5, 11]
解释:
第0层的平均值是 3,  第1层是 14.5, 第2层是 11. 因此返回 [3, 14.5, 11].
```
注意：
* 节点值的范围在32位有符号整数范围内。

_思路：_
* 用层次遍历的方法去实现即可
```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode*> que;
        vector<double> res;
        if(root == nullptr){
            return res;
        }
        que.push(root);
        while(!que.empty()){
            int len = que.size();
            double sum = 0;
            for(int i=0;i<len; i++){
                TreeNode* p=que.front();
                que.pop();
                sum = sum + p->val;
                if(p->left != NULL)
                    que.push(p->left);
                if(p->right != NULL)
                    que.push(p->right);  
            }
            res.push_back(sum/len);
        }
        return res;
    }
};
```
### [5.二叉树的层序遍历](https://leetcode-cn.com/problems/binary-tree-level-order-traversal/)
给你一个二叉树，请你返回其按 层序遍历 得到的节点值。 （即逐层地，从左到右访问所有节点）。

示例：```[3,9,20,null,null,15,7]```,
```html
    3
   / \
  9  20
    /  \
   15   7
```
返回其层次遍历结果：
```
[
  [3],
  [9,20],
  [15,7]
]
```
_思路:_
* 使用队列
* 每一层结点入队马上出队即可
```cpp
//cpp实现
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> dq;
        vector<vector<int>> result;
        if (!root) 
            return result;
        dq.push(root);
        while(!dq.empty()){
            int len = dq.size();
            result.push_back(vector<int>());
            for(int i=0;i<len; i++){
                TreeNode* p=dq.front();
                dq.pop();
                result.back().push_back(p->val);
                if(p->left != NULL)
                    dq.push(p->left);
                if(p->right != NULL)
                    dq.push(p->right);  
            }
        }
        return result;
    }
};
```
### [6.二叉树的最大深度](https://leetcode-cn.com/problems/maximum-depth-of-binary-tree/)
给定一个二叉树，找出其最大深度。

二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。

说明: 叶子节点是指没有子节点的节点。

示例：
给定二叉树 ```[3,9,20,null,null,15,7]```，
```html
    3
   / \
  9  20
    /  \
   15   7
```
返回它的最大深度 3 。

_思路1：_
* 递归的思路做
```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == nullptr){
            return 0;
        }
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;   
    }
};
```
_思路2：_
* 层次遍历，计算层数
```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int maxDepth(TreeNode* root) {
        queue<TreeNode*> que;
        TreeNode* ptr = root;
        if(!root)
            return 0;
        int res = 0; 
        que.push(root);
        while(!que.empty()){
            int len = que.size();
            res = res + 1;
            for(auto i = 0; i < len; i++){
                ptr = que.front();
                que.pop();
                if(ptr->left != nullptr){
                    que.push(ptr->left);
                }
                if(ptr->right != nullptr){
                    que.push(ptr->right);
                }
            }
        }
        return res;  
    }
};
```
### [7.二叉树的最小深度](https://leetcode-cn.com/problems/minimum-depth-of-binary-tree/)
给定一个二叉树，找出其最小深度。

最小深度是从根节点到最近叶子节点的最短路径上的节点数量。

说明: 叶子节点是指没有子节点的节点。

示例:

给定二叉树 ```[3,9,20,null,null,15,7]```,

```html
    3
   / \
  9  20
    /  \
   15   7
```
_思路1：_
* 采用层次遍历的方法，当遍历到一个结点是叶结点时候，跳出循环
```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int minDepth(TreeNode* root) {
        queue<TreeNode*> que;
        TreeNode* ptr = root;
        if(!root)
            return 0;
        int res = 0; 
        que.push(root);
        while(!que.empty()){
            int len = que.size();
            res = res + 1;
            for(auto i = 0; i < len; i++){
                ptr = que.front();
                que.pop();
                if(ptr -> left == nullptr && ptr -> right == nullptr)
                    return res;
                if(ptr->left != nullptr){
                    que.push(ptr->left);
                }
                if(ptr->right != nullptr){
                    que.push(ptr->right);
                }
            }
        }
        return res;
    }
};
```
