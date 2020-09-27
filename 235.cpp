/*
 * @Author: your name
 * @Date: 2020-09-27 09:48:06
 * @LastEditTime: 2020-09-27 10:30:35
 * @LastEditors: Please set LastEditors
 * @Description: 235. 二叉搜索树的最近公共祖先
        给定一个二叉搜索树, 找到该树中两个指定节点的最近公共祖先。
        百度百科中最近公共祖先的定义为：“对于有根树 T 的两个结点 p、q，最近公共祖先表示为一个结点 x，满足 x 是 p、q 的祖先且 x 的深度尽可能大（一个节点也可以是它自己的祖先）。”
        例如，给定如下二叉搜索树:  root = [6,2,8,0,4,7,9,null,null,3,5]
 * @FilePath: /undefined/home/whh/programming/Leetcode/235.cpp
 */
#include "dependOn.h"
#include <queue>
using std::queue;
class Solution {

public:
// 执行用时：48 ms, 在所有 C++ 提交中击败了45.08% 的用户
// 内存消耗：23 MB, 在所有 C++ 提交中击败了23.62% 的用户
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        queue<TreeNode*> que;
        if(root) que.push(root);
        while(!que.empty()){
            TreeNode* tmp=que.front();
            que.pop();

            if(tmp->val< max(p->val,q->val) && tmp->val>min(p->val,q->val)){
                return tmp;
            }else if(tmp->val==p->val || tmp->val==q->val){
                return tmp;
            }

            if(tmp->left) que.push(tmp->left);
            if(tmp->right) que.push(tmp->right);
        }
        return root;

    }
};