/*
 * @Author: your name
 * @Date: 2021-01-27 19:38:24
 * @LastEditTime: 2021-01-27 19:45:32
 * @LastEditors: Please set LastEditors
 * @Description: 剑指 Offer 32 - I. 从上到下打印二叉树
 * 从上到下打印出二叉树的每个节点，同一层的节点按照从左到右的顺序打印
 * @FilePath: /offer2/32.cpp
 */
#include <vector>
#include <queue>
#include "../dependOn.h"
using namespace std;
class Solution {
public:
    vector<int> levelOrder(TreeNode* root) {
        vector<int> res;
        if(!root) return res;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* tmp=q.front();
            q.pop();
            res.push_back(tmp->val);
            if(tmp->left) q.push(tmp->left);
            if(tmp->right) q.push(tmp->right);
        }
        return res;
    }
};