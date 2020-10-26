/*
 * @Author: your name
 * @Date: 2020-10-22 14:46:38
 * @LastEditTime: 2020-10-26 10:06:13
 * @LastEditors: Please set LastEditors
 * @Description: 输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。要求不能创建任何新的结点，只能调整树中结点指针的指向。
 * @FilePath: /undefined/home/whh/programming/Leetcode/JZ26.cpp
 */

#include "dependOn.h"
#include <vector>
using namespace std;
class Solution {
    vector<TreeNode*> q;
public:

// 先进行中序遍历，储存在vector中。然后遍历数组，建立双向链表
    TreeNode* traverse(TreeNode* root){
        if(root==nullptr) return root;
        traverse(root->left);
        q.push_back(root);
        traverse(root->right);
        return root;
    }
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        if(pRootOfTree==nullptr) return pRootOfTree;
        traverse(pRootOfTree);
        for(int i=0;i<q.size()-1;i++){
            q[i]->right=q[i+1];
            q[i+1]->left=q[i];
        }
        return *q.begin();
    }
// 在不增加额外线性空间的情况下 通过指向上一个的指针，实现转换
    TreeNode* pre=nullptr;
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        if(pRootOfTree==nullptr) return nullptr;
        Convert(pRootOfTree->left);
        pRootOfTree->left=pre;
        if(pre!=nullptr){
            pre->right=pRootOfTree;
        }
        pre=pRootOfTree;
        Convert(pRootOfTree->right);
        TreeNode* q=pre;

        while(q->left!=nullptr) q=q->left;
        return q;
    }

};