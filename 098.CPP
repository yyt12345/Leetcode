/*
 * @Descripttion: 98. 验证二叉搜索树
        给定一个二叉树，判断其是否是一个有效的二叉搜索树。
        假设一个二叉搜索树具有如下特征：
            节点的左子树只包含小于当前节点的数。
            节点的右子树只包含大于当前节点的数。
            所有左子树和右子树自身必须也是二叉搜索树。

 * @version: 
 * @Author: Ye Yating
 * @Date: 2020-09-02 08:47:53
 * @LastEditors: Ye Yating
 * @LastEditTime: 2020-09-02 10:29:45
 */

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x)
        : val(x)
        , left(NULL)
        , right(NULL) {};
};
class Solution {
    long cur = -__LONG_MAX__;
    bool flag = true;

public:
    // 使用中序遍历，序列单调递增
    // 执行用时：28 ms, 在所有 C++ 提交中击败了5.08% 的用户
    // 内存消耗：18.4 MB, 在所有 C++ 提交中击败了31.70% 的用户
    void func(TreeNode* root)
    {
        if (root == nullptr)
            return;
        func(root->left);
        if (root->val <= cur)
            flag = false;
        else
            cur = root->val;
        func(root->right);
        return;
    }
    bool isValidBST(TreeNode* root)
    {
        func(root);
        return flag;
    }
    // 执行用时：16 ms, 在所有 C++ 提交中击败了69.77% 的用户
    // 内存消耗：18.2 MB, 在所有 C++ 提交中击败了74.19% 的用户
    bool helper(TreeNode* root, int lower, int upper)
    {
        if (root == nullptr)
            return true;
        if (root->val <= lower || root->val >= upper)
            return false;
        return helper(root->left, lower, root->val) && helper(root->right, root->val, upper);
    }
    bool isValidBST2(TreeNode* root)
    {
        return helper(root, -__INT_MAX__, __INT_MAX__);
    }
}