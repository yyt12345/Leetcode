/*
 * @Author: your name
 * @Date: 2020-10-28 10:22:23
 * @LastEditTime: 2020-10-28 11:03:19
 * @LastEditors: Please set LastEditors
 * @Description: 输入一棵二叉树，求该树的深度。从根结点到叶结点依次经过的结点（含根、叶结点）形成树的一条路径，最长路径的长度为树的深度。
 * @FilePath: /undefined/home/whh/programming/Leetcode/JZ38.cpp
 */
#include <iostream>
#include <vector>
#include <queue>
#include "dependOn.h"
using namespace std;
class Solution {

public:
// 递归
    int TreeDepth(TreeNode* root)
    {
        if(root==nullptr) return 0;
        if(root->left==nullptr && root->right==nullptr) return 1;
        return max(TreeDepth(root->left),TreeDepth(root->right))+1;
    }
// 层次遍历 若需要记录层数则多添加一重循环
    int TreeDepth(TreeNode* pRoot)
    {
        if(!pRoot) return 0;
        queue<TreeNode*> q;
        q.push(pRoot);
        int level=0;
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                auto node=q.front();
                q.pop();
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            level++;
        }
        return level;
    }
};
int main(){
    vector<int> nums={1,2,3,4,5,'#',6,'#','#',7};
    TreeNode* root=createTree(nums,0);
    Solution s;
    cout << s.TreeDepth(root) << endl;

}