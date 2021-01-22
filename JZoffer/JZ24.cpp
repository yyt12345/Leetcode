/*** 
 * @Author: whh
 * @Date: 2020-12-16 10:24:34
 * @LastEditTime: 2020-12-16 10:40:21
 * @LastEditors: whh
 * @Description: 输入一颗二叉树的根节点和一个整数，按字典序打印出二叉树中结点值的和为输入整数的所有路径。路径定义为从树的根结点开始往下一直到叶结点所经过的结点形成一条路径
 * @FilePath: /Leetcode/ZJ24.cpp
 */
#include "dependOn.h"
#include <vector>
using namespace std;
class Solution {
    vector<int> path;
    vector<vector<int>> res;

public:
    void DFS(TreeNode* root, int expectNumber)
    {
        if (expectNumber < 0)
            return;
        else if (!root)
            return;
        path.push_back(root->val);
        if (!root->left && !root->right && root->val == expectNumber) {
            res.push_back(path);
            path.pop_back();
            return;
        }
        DFS(root->left, expectNumber - root->val);
        DFS(root->right, expectNumber - root->val);
        path.pop_back();
        return;
    }
    vector<vector<int>> FindPath(TreeNode* root, int expectNumber)
    {
        if (!root)
            return res;
        // 深度优先算法
        DFS(root, expectNumber);
        return res;
    }
};