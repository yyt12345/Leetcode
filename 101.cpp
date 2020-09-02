/*
 * @Descripttion: 101. 对称二叉树
        给定一个二叉树，检查它是否是镜像对称的。
        进阶：你可以运用递归和迭代两种方法解决这个问题吗？
 * @version: 
 * @Author: Ye Yating
 * @Date: 2020-09-02 10:29:45
 * @LastEditors: Ye Yating
 * @LastEditTime: 2020-09-02 10:56:41
 */
#include <queue>
using std::queue;
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
public:
    // 执行用时：4 ms, 在所有 C++ 提交中击败了87.54% 的用户
    // 内存消耗：12.4 MB, 在所有 C++ 提交中击败了71.48% 的用户
    bool func(TreeNode* q, TreeNode* p)
    {
        if (!q && !p)
            return true;
        if (!q || !p)
            return false;
        return p->val == q->val && func(p->left, q->right) && func(p->right, q->left);
    }
    bool isSymmetric(TreeNode* root)
    {
        return func(root, root);
    }
    // 使用迭代法进行求解 创建队列是将树的递归转换成迭代的常用方法
    // 执行用时：4 ms, 在所有 C++ 提交中击败了87.54% 的用户
    // 内存消耗：12.9 MB, 在所有 C++ 提交中击败了6.90% 的用户
    bool isSymmetric2(TreeNode* root)
    {
        queue<TreeNode*> q;
        q.push(root);
        q.push(root);
        TreeNode *u, *v;
        while (!q.empty()) {
            u = q.front();
            q.pop();
            v = q.front();
            q.pop();
            if (!u && !v)
                continue;
            if ((!u || !v) || u->val != v->val)
                return false;

            q.push(u->left);
            q.push(v->right);

            q.push(u->right);
            q.push(v->left);
        }
        return true;
    }
};