/*** 
 * @Author: whh
 * @Date: 2020-12-29 15:45:24
 * @LastEditTime: 2021-01-03 18:33:12
 * @LastEditors: whh
 * @Description: 请实现两个函数，分别用来序列化和反序列化二叉树
 * 二叉树的序列化是指：把一棵二叉树按照某种遍历方式的结果以某种格式保存为字符串，从而使得内存中建立起来的二叉树可以持久保存。
 * 序列化可以基于先序、中序、后序、层序的二叉树遍历方式来进行修改，序列化的结果是一个字符串，序列化时通过 某种符号表示空节点（#），以 ！ 表示一个结点值的结束（value!）。
 * 
 * 二叉树的反序列化是指：根据某种遍历顺序得到的序列化字符串结果str，重构二叉树。
 * 例如，我们可以把一个只有根节点为1的二叉树序列化为"1,"，然后通过自己的函数来解析回这个二叉树
 * @FilePath: /Leetcode/JZ61.cpp
 */
#include "dependOn.h"
#include <queue>
#include <string.h>
#include <string>
using namespace std;
class Solution {
public:
    char* Serialize(TreeNode* root)
    {

        if (!root)
            return nullptr;

        string s;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if (!node) {
                s += "#,";
                continue;
            }
            s += to_string(node->val);
            s.push_back(',');

            q.push(node->left);
            q.push(node->right);
        }
        char* ret = new char[s.length() + 1];
        strcpy(ret, s.c_str());

        return ret;
    }
    TreeNode* Deserialize(char* str)
    {
        if (strlen(str) == 1)
            return nullptr;

        string s(str);
        queue<TreeNode*> q;
        TreeNode* root = new TreeNode(atoi(s.c_str()));
        s = s.substr(s.find_first_not_of(',') + 1);
        q.push(root);
        while (!q.empty() && !s.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if (s[0] == '#') {
                node->left = nullptr;
                s = s.substr(2);
            } else {
                node->left = new TreeNode(atoi(s.c_str()));
                q.push(node->left);
                s = s.substr(s.find_first_of(',') + 1);
            }

            if (s[0] == '#') {
                node->right = nullptr;
                s = s.substr(2);
            } else {
                node->right = new TreeNode(atoi(s.c_str()));
                q.push(node->right);
                s = s.substr(s.find_first_of(',') + 1);
            }
        }
        return root;
    }
};