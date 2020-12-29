/*** 
 * @Author: whh
 * @Date: 2020-12-29 14:56:13
 * @LastEditTime: 2020-12-29 15:43:35
 * @LastEditors: whh
 * @Description: 请实现一个函数按照之字形打印二叉树，即第一行按照从左到右的顺序打印，第二层按照从右至左的顺序打印，第三行按照从左到右的顺序打印，其他行以此类推。
 * @FilePath: /Leetcode/JZ59.cpp
 */
#include "dependOn.h"
#include <deque>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> Print(TreeNode* pRoot)
    {
        if (!pRoot)
            return {};
        queue<TreeNode*> q;
        q.push(pRoot);
        bool flag = true;
        vector<vector<int>> res;
        while (!q.empty()) {
            vector<int> tmp;
            int n = q.size();
            for (int i = 0; i < n; i++) {
                TreeNode* front = q.front();
                q.pop();
                if (!flag)
                    tmp.insert(tmp.begin(), front->val);
                else
                    tmp.push_back(front->val);

                if (front->left)
                    q.push(front->left);
                if (front->right)
                    q.push(front->right);
            }
            flag = !flag;
            res.push_back(tmp);
        }
        return res;
    }
    /*** 
     * @description: 使用双端队列
     */
    vector<vector<int>> Print(TreeNode* pRoot)
    {
        if (!pRoot)
            return {};
        deque<TreeNode*> q;
        q.push_back(pRoot);
        bool flag = true;
        vector<vector<int>> res;
        while (!q.empty()) {
            int n = q.size();
            //奇数层
            vector<int> tmp;
            for (int i = 0; i < n; i++) {
                TreeNode* front = q.front();
                q.pop_front();
                tmp.push_back(front->val);
                if (front->left)
                    q.push_back(front->left);
                if (front->right)
                    q.push_back(front->right);
            }
            res.push_back(tmp);
            if (q.empty())
                break;
            //偶数层
            tmp = {};
            int n = q.size();
            for (int i = 0; i < n; i++) {
                TreeNode* back = q.back();
                q.pop_back();
                tmp.push_back(back->val);
                if (back->right)
                    q.push_front(back->right);
                if (back->left)
                    q.push_front(back->left);
            }
            res.push_back(tmp);
        }
        return res;
    }
};
int main()
{
    bool flag = false;
    flag = !flag;
    cout << flag << endl;
}