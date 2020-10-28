/*
 * @Author: your name
 * @Date: 2020-10-28 10:12:51
 * @LastEditTime: 2020-10-28 10:18:10
 * @LastEditors: Please set LastEditors
 * @Description: 操作给定的二叉树，将其变换为源二叉树的镜像。
 * @FilePath: /undefined/home/whh/programming/Leetcode/JZ18.cpp
 */
#include "dependOn.h"
class Solution {
public:
// 递归 转换指针
    void Mirror(TreeNode *pRoot) {  
        if(!pRoot) return;
        swap(pRoot->left,pRoot->right);
        Mirror(pRoot->left);
        Mirror(pRoot->right);
    }
};