/*
 * @Author: Ye Yating
 * @Date: 2020-09-21 09:47:56
 * @LastEditTime: 2020-09-21 11:10:39
 * @LastEditors: Please set LastEditors
 * @Description: 538. 把二叉搜索树转换为累加树
        给定一个二叉搜索树（Binary Search Tree），把它转换成为累加树（Greater Tree)，使得每个节点的值是原来的节点值加上所有大于它的节点值之和。
 * @FilePath: /Leetcode/538.cpp
 */
#include "dependOn.h"
#include <vector>
using std::vector;
class Solution
{
    int pre;

public:
    // 执行用时：64 ms, 在所有 C++ 提交中击败了82.84% 的用户
    // 内存消耗：32.8 MB, 在所有 C++ 提交中击败了17.03% 的用户
    void dfs(TreeNode *root)
    {
        if (root == nullptr)
            return;
        dfs(root->right);
        root->val += pre;
        pre = root->val;
        dfs(root->left);
    }
    TreeNode *convertBST(TreeNode *root)
    {
        dfs(root);
        return root;
    }
    // 执行用时：68 ms, 在所有 C++ 提交中击败了69.49% 的用户
    // 内存消耗：32.6 MB, 在所有 C++ 提交中击败了50.93% 的用户
    TreeNode *convertBST(TreeNode *root)
    {
        if (root == nullptr)
            return root;
        convertBST(root->right);
        root->val += pre;
        pre = root->val;
        convertBST(root->left);
        return root;
    }
    // 使用morris的二叉树遍历算法，空间复杂度O(1)
    // 执行用时：72 ms, 在所有 C++ 提交中击败了53.17% 的用户
    // 内存消耗：32.5 MB, 在所有 C++ 提交中击败了79.10% 的用户
    TreeNode *convertBST(TreeNode *root)
    {
        int sum = 0;
        TreeNode *cur = root;
        while (cur != nullptr)
        {
            if (cur->right == nullptr)
            {
                root->val += sum;
                sum = root->val;
                cur = cur->right;
            }
            else
            {
                TreeNode *tmp = cur->right;
                while (tmp->left != nullptr && tmp->left != cur)
                    tmp = tmp->left;
                if (tmp->left == nullptr)
                {
                    tmp->left = cur;
                    cur = cur->right;
                }
                else
                {
                    tmp->left = nullptr;
                    tmp->val += sum;
                    sum = tmp->val;
                    cur = cur->left;
                }
            }
        }
        return root;
    }
    vector<int> morrisMider(TreeNode *root)
    {
        vector<int> res;
        if (root == nullptr)
            return res;
        TreeNode *cur = root;
        while (cur != nullptr)
        {
            if (cur->left == nullptr)
            {
                res.push_back(cur->val);
                cur = cur->right;
            }
            else
            {
                TreeNode *q = cur->left;
                while (q->right != nullptr && q->right != cur)
                    q = q->right;
                if (q->right == nullptr)
                {
                    q->right = cur;
                    cur = cur->left;
                }
                else
                {
                    res.push_back(cur->val);
                    q->right = nullptr;
                    cur = cur->right;
                }
            }
        }
        return res;
    }
};