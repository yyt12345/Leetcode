/*
 * @Author: your name
 * @Date: 2021-01-27 21:59:09
 * @LastEditTime: 2021-01-27 22:15:29
 * @LastEditors: Please set LastEditors
 * @Description: 剑指 Offer 34. 二叉树中和为某一值的路径
 * 输入一棵二叉树和一个整数，打印出二叉树中节点值的和为输入整数的所有路径。从树的根节点开始往下一直到叶节点所经过的
 * 节点形成一条路径。
 * @FilePath: /offer2/34.cpp
 */
#include <vector>
#include "../dependOn.h"
using namespace std;
class Solution {
    vector<int> path;
    vector<vector<int>> res;
public:
    void dfs(TreeNode* root,int sum){
        if(!root) return;
        if(!root->right && !root->left && sum==root->val) {
            path.push_back(root->val);
            res.push_back(path);
            path.pop_back();
            return;
        }

        path.push_back(root->val);
        dfs(root->left,sum-root->val);
        dfs(root->right,sum-root->val);
        path.pop_back();  
        return;      
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        dfs(root,sum);
        return res;
    }
};
