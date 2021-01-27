/*
 * @Author: your name
 * @Date: 2021-01-27 18:12:04
 * @LastEditTime: 2021-01-27 18:12:04
 * @LastEditors: Please set LastEditors
 * @Description: 剑指 Offer 28. 对称的二叉树
 * 请实现一个函数，用来判断一棵二叉树是不是对称的。如果一棵二叉树和它的镜像一样，那么它是对称的。
 * @FilePath: /offer2/28.cpp
 */
#include "../dependOn.h"
class Solution {
public:
    bool subFunc(TreeNode* left,TreeNode* right){
        if(!left && !right) return true;
        else if(!left || !right) return false;

        if(left->val!=right->val) return false;
        return subFunc(left->left,right->right) && subFunc(left->right,right->left);
    }
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        return subFunc(root->left,root->right);
    }
};