/*
 * @Descripttion: 102. 二叉树的层序遍历
        给你一个二叉树，请你返回其按 层序遍历 得到的节点值。 （即逐层地，从左到右访问所有节点）。
 * @version: 
 * @Author: Ye Yating
 * @Date: 2020-09-03 10:23:33
 * @LastEditors: Ye Yating
 * @LastEditTime: 2020-09-03 10:56:03
 */
#include <queue>
#include <vector>
using std::queue;
using std::vector;
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
    // 执行用时：8 ms, 在所有 C++ 提交中击败了47.38% 的用户
    // 内存消耗：11.9 MB, 在所有 C++ 提交中击败了20.09% 的用户
    vector<vector<int>> levelOrder(TreeNode* root)
    {
        vector<vector<int>> res;
        if (root == nullptr)
            return res;
        vector<TreeNode*> q;
        q.push_back(root);
        while (!q.empty()) {
            vector<int> tmp;
            for (auto a : q)
                tmp.push_back(a->val);
            res.push_back(tmp);

            vector<TreeNode*> nextLevel;
            for (auto a : q) {
                if (a->left)
                    nextLevel.push_back(a->left);
                if (a->right)
                    nextLevel.push_back(a->right);
            }
            q = nextLevel;
        }
        return res;
    }
    // 执行用时：4 ms, 在所有 C++ 提交中击败了89.10% 的用户
    // 内存消耗：11.9 MB, 在所有 C++ 提交中击败了18.77% 的用户
    vector<vector<int>> levelOrder(TreeNode* root)
    {
        vector<vector<int>> res;
        if (root == nullptr)
            return res;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int n = q.size();
            vector<int> tmp;
            for (int i = 1; i <= n; i++) {
                TreeNode* t = q.front();
                q.pop();
                tmp.push_back(t->val);
                if (t->left)
                    q.push(t->left);
                if (t->right)
                    q.push(t->right);
            }
            res.push_back(tmp);
        }
        return res;
    }
};