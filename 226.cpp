/*
 * @Author: your name
 * @Date: 2020-09-16 08:46:05
 * @LastEditTime: 2020-09-16 09:08:39
 * @LastEditors: Please set LastEditors
 * @Description: 226. 翻转二叉树
        翻转一棵二叉树。
 * @FilePath: /Leetcode/226.cpp
 */
#include <algorithm>
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
// 执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
// 内存消耗：9.1 MB, 在所有 C++ 提交中击败了37.15% 的用户
    TreeNode* invertTree(TreeNode* root) {
        if(root==nullptr) return nullptr;
        invertTree(root->left);
        invertTree(root->right);
        std::swap(root->left,root->right);
        return root;
    }
};