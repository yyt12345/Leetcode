/*
 * @Descripttion: 100. 相同的树
        给定两个二叉树，编写一个函数来检验它们是否相同。
        如果两个树在结构上相同，并且节点具有相同的值，则认为它们是相同的。
 * @version: 
 * @Author: Ye Yating
 * @Date: 2020-07-19 18:51:15
 * @LastEditors: Ye Yating
 * @LastEditTime: 2020-08-07 11:16:04
 */
#include <iostream>
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode()
        : val(0)
        , left(nullptr)
        , right(nullptr)
    {
    }
    TreeNode(int x)
        : val(x)
        , left(nullptr)
        , right(nullptr)
    {
    }
    TreeNode(int x, TreeNode* left, TreeNode* right)
        : val(x)
        , left(left)
        , right(right)
    {
    }
};
// 执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
// 内存消耗：9.8 MB, 在所有 C++ 提交中击败了88.54% 的用户
bool isSameTree(TreeNode* p, TreeNode* q)
{
    if (p == nullptr && q == nullptr)
        return true;
    else if (p == nullptr || q == nullptr)
        return false;

    if (p->val != q->val)
        return false;
    else {
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
}