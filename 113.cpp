/*
 * @Author: your name
 * @Date: 2020-09-26 09:10:19
 * @LastEditTime: 2020-09-26 09:31:23
 * @LastEditors: Please set LastEditors
 * @Description: 113. 路径总和 II
        给定一个二叉树和一个目标和，找到所有从根节点到叶子节点路径总和等于给定目标和的路径。
        说明: 叶子节点是指没有子节点的节点。
 * @FilePath: /undefined/home/whh/programming/Leetcode/113.cpp
 */
#include "dependOn.h"
#include <vector>
using std::vector;
class Solution {
    vector<vector<int>> res;
    vector<int> path;
public:
// 执行用时：616 ms, 在所有 C++ 提交中击败了8.17% 的用户
// 内存消耗：173.8 MB, 在所有 C++ 提交中击败了5.06% 的用户
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if(root==nullptr) return res;
        path.push_back(root->val);
        sum-=root->val;
        if(root->left==nullptr && root->right==nullptr && sum==0){
            res.push_back(path);
        }
        pathSum(root->left,sum);
        pathSum(root->right,sum);
        path.pop_back();

        return res;
    }
};