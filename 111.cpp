/*
 * @Descripttion: 111. 二叉树的最小深度
        给定一个二叉树，找出其最小深度。
        最小深度是从根节点到最近叶子节点的最短路径上的节点数量。
        说明: 叶子节点是指没有子节点的节点。
 * @version: 
 * @Author: Ye Yating
 * @Date: 2020-08-21 21:42:12
 * @LastEditors: Ye Yating
 * @LastEditTime: 2020-08-21 22:06:21
 */
#include <algorithm>
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
class Solution {
public:
    // 执行用时：16 ms, 在所有 C++ 提交中击败了53.26% 的用户
    // 内存消耗：17.4 MB, 在所有 C++ 提交中击败了56.73% 的用户
    int dfs(TreeNode* root)
    {
        if (root->left == NULL && root->right == NULL)
            return 1;
        int left = __INT_MAX__, right = __INT_MAX__;
        if (root->left != NULL)
            left = dfs(root->left);
        if (root->right != NULL)
            right = dfs(root->right);
        return std::min(left, right) + 1;
    }
    int minDepth(TreeNode* root)
    {
        if (root == nullptr)
            return 0;
        return dfs(root);
    }
};
int main()
{
    TreeNode* root = new TreeNode(1, new TreeNode(2), NULL);
    Solution s;
    std::cout << s.minDepth(root) << std::endl;
}