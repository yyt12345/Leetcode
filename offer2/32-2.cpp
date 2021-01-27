/*
 * @Author: your name
 * @Date: 2021-01-27 19:45:21
 * @LastEditTime: 2021-01-27 19:49:26
 * @LastEditors: Please set LastEditors
 * @Description: 剑指 Offer 32 - II. 从上到下打印二叉树 II
 * 从上到下按层打印二叉树，同一层的节点按从左到右的顺序打印，每一层打印到一行。
 * @FilePath: /offer2/32-2.cpp
 */
#include <vector>
#include <queue>
#include "../dependOn.h"
using namespace std;
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root) return res;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            vector<int> temp;
            int n=q.size();
            for(int i=0;i<n;i++){
                TreeNode* tmp=q.front();
                q.pop();
                temp.push_back(tmp->val);
                if(tmp->left) q.push(tmp->left);
                if(tmp->right) q.push(tmp->right);
            }
            res.push_back(temp);
        }
        return res;
    }
};