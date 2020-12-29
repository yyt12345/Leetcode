/*** 
 * @Author: whh
 * @Date: 2020-12-29 17:01:31
 * @LastEditTime: 2020-12-29 17:03:06
 * @LastEditors: whh
 * @Description: 从上往下打印出二叉树的每个节点，同层节点从左至右打印。
 * @FilePath: /Leetcode/JZ22.cpp
 */
#include "dependOn.h"
#include <queue>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> PrintFromTopToBottom(TreeNode* root)
    {
        if (!root)
            return {};
        vector<int> res;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            res.push_back(node->val);
            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }
        return res;
    }
};