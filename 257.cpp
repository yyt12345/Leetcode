/*
 * @Descripttion: 257. 二叉树的所有路径
        给定一个二叉树，返回所有从根节点到叶子节点的路径。
        说明: 叶子节点是指没有子节点的节点。
 * @version: 
 * @Author: Ye Yating
 * @Date: 2020-09-04 08:48:42
 * @LastEditors: Ye Yating
 * @LastEditTime: 2020-09-04 09:15:58
 */
#include <iostream>
#include <string>
#include <vector>
using std::string;
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
    vector<TreeNode*> path;
    vector<string> res;

public:
    // 执行用时：8 ms, 在所有 C++ 提交中击败了56.59% 的用户
    // 内存消耗：13.4 MB, 在所有 C++ 提交中击败了81.31% 的用户
    void func(TreeNode* root)
    {
        if (root->left == NULL && root->right == NULL) {
            if (path.size() == 0)
                return;
            string tmp;
            for (auto a : path) {
                tmp += std::to_string(a->val);
                tmp += "->";
            }
            if (tmp.size() > 2)
                tmp.erase(tmp.end() - 2, tmp.end());
            res.push_back(tmp);
            return;
        }

        if (root->left) {
            path.push_back(root->left);
            func(root->left);
            path.pop_back();
        }
        if (root->right) {
            path.push_back(root->right);
            func(root->right);
            path.pop_back();
        }
        return;
    }
    vector<string> binaryTreePaths(TreeNode* root)
    {
        if (root == nullptr)
            return res;
        path.push_back(root);
        func(root);
        return res;
    }
};
int main()
{
    TreeNode* root = new TreeNode(1);
    TreeNode* q = root;
    TreeNode* t1 = new TreeNode(2);
    q->left = t1;
    t1 = new TreeNode(3);
    q->right = t1;
    t1 = new TreeNode(5);
    q = root->left;
    q->right = t1;

    Solution s;
    vector<string> res = s.binaryTreePaths(root);
    for (auto a : res)
        std::cout << a << std::endl;
}