/*
 * @Author: your name
 * @Date: 2021-01-27 19:49:36
 * @LastEditTime: 2021-01-27 20:14:57
 * @LastEditors: Please set LastEditors
 * @Description: 剑指 Offer 32 - III. 从上到下打印二叉树 III
 * 请实现一个函数按照之字形顺序打印二叉树，即第一行按照从左到右的顺序打印，第二层按照从右到左的顺序打印，第三行再按照从左到右的顺序打印，其他行以此类推。
 * @FilePath: /offer2/32-3.cpp
 */
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include "../dependOn.h"
using namespace std;
class Solution {
public:
    //使用stack辅助
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root) return res;
        stack<TreeNode*> q;
        q.push(root);
        res.push_back({root->val});
        bool flag=true;
        while(!q.empty()){
            vector<int> temp;
            
            stack<TreeNode*> s;
            while(!q.empty()){
                TreeNode* tmp=q.top();
                q.pop();
                if(flag){
                    if(tmp->right){
                        temp.push_back(tmp->right->val);
                        s.push(tmp->right);
                    }
                    if(tmp->left){
                        temp.push_back(tmp->left->val);
                        s.push(tmp->left);
                    }
                }
                else{
                    if(tmp->left){
                        temp.push_back(tmp->left->val);
                        s.push(tmp->left);
                    }
                    if(tmp->right){
                        temp.push_back(tmp->right->val);
                        s.push(tmp->right);
                    }
                }
            }
            flag = !flag;
            q=s;

            if(!temp.empty())res.push_back(temp);
        }
        return res;
    }
    //单层结果倒序
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
            if(res.size()%2) reverse(temp.begin(),temp.end());
            res.push_back(temp);
        }
        return res;
    }
    //双端队列deque
};