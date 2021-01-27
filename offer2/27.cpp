/*
 * @Author: your name
 * @Date: 2021-01-27 18:08:33
 * @LastEditTime: 2021-01-27 18:11:48
 * @LastEditors: Please set LastEditors
 * @Description: 剑指 Offer 27. 二叉树的镜像
 * 请完成一个函数，输入一个二叉树，该函数输出它的镜像
 * @FilePath: /offer2/27.cpp
 */
#include "../dependOn.h"
#include <algorithm>
using namespace std;
class Solution {
public:
    TreeNode* mirrorTree(TreeNode* root) {
        if(!root) return nullptr;
        mirrorTree(root->left);
        mirrorTree(root->right);
        swap(root->right,root->left);
        return root;
    }
};