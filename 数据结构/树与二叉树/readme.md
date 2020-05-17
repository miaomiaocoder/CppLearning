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
### [二叉树的前序遍历](https://leetcode-cn.com/problems/binary-tree-preorder-traversal/)
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
* 

