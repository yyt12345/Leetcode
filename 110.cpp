/*
 * @Descripttion: 
 * @Author: Ye Yating
 * @Date: 2020-08-17 09:59:41
 * @LastEditors: Ye Yating
 * @LastEditTime: 2020-08-17 10:34:04
 */
/* 
    110. 平衡二叉树

    给定一个二叉树，判断它是否是高度平衡的二叉树。

    本题中，一棵高度平衡二叉树定义为：

        一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过1。

*/
#include <iostream>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x)
        : val(x)
        , left(NULL)
        , right(NULL)
    {
    }
};
class Solution {

public:
    // 自底而上的遍历
    // 执行用时：12 ms, 在所有 C++ 提交中击败了92.31% 的用户
    // 内存消耗：14.9 MB, 在所有 C++ 提交中击败了46.00% 的用户
    int getHight(TreeNode* root)
    {
        if (root == nullptr)
            return 0;
        int left = getHight(root->left);
        if (left == -1)
            return -1;
        int right = getHight(root->right);
        if (right == -1)
            return -1;
        return abs(right - left) > 1 ? -1 : max(right, left) + 1;
    }
    bool isBalanced(TreeNode* root)
    {
        return getHight(root) >= 0;
    }
};