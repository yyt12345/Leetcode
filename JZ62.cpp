/*
 * @Author: your name
 * @Date: 2020-10-29 10:45:38
 * @LastEditTime: 2020-11-02 20:15:59
 * @LastEditors: Please set LastEditors
 * @Description: 给定一棵二叉搜索树，请找出其中的第k小的结点。
 * @FilePath: /undefined/home/whh/programming/Leetcode/JZ62.cpp
 */
#include "dependOn.h"
#include <stack>
using namespace std;
class Solution {
    int count=0;
public:
// 中序遍历 count=k
    TreeNode* KthNode(TreeNode* pRoot, int k)
    {
        if(!pRoot) return pRoot;

        stack<TreeNode*> s;
        TreeNode* cur=pRoot;
        while(true){
            while(cur){
                s.push(cur);
                cur=cur->left;
            }
            if(s.empty()) break;
            cur=s.top();
            if(--k==0) return cur;

            cur=cur->right;
            s.pop();
        }
        return nullptr;
    }

// 递归
    int index=0;
    TreeNode* getKthNode(TreeNode* pRoot,int k){
        TreeNode* node=nullptr;
        if(pRoot->left!=nullptr)
            node=getKthNode(pRoot->left,k);
        if(++index==k) node=pRoot;
        if(node==nullptr && pRoot->right!=nullptr) node=getKthNode(pRoot->right,k);
        return node;
    }
    TreeNode* KthNode(TreeNode* pRoot,int k){
        if(pRoot==nullptr || k<=0) return nullptr;
        return getKthNode(pRoot,k);
    }
};