/*** 
 * @Author: whh
 * @Date: 2020-12-29 14:46:42
 * @LastEditTime: 2020-12-29 14:53:53
 * @LastEditors: whh
 * @Description: 实现一个函数，用来判断一棵二叉树是不是对称的。注意，如果一个二叉树同此二叉树的镜像是同样的，定义其为对称的。
 * @FilePath: /Leetcode/JZ58.cpp
 */
#include "dependOn.h"
using namespace std;
class Solution {
public:
    bool dfs(TreeNode* pLeft, TreeNode* pRight)
    {
        if (!pLeft && !pRight)
            return true;
        else if (!pLeft || !pRight)
            return false;

        return (pLeft->val == pRight->val) && dfs(pLeft->right, pRight->left) && dfs(pLeft->left, pRight->right);
    }
    bool isSymmetrical(TreeNode* pRoot)
    {
        if (pRoot == nullptr)
            return true;
        return dfs(pRoot->left, pRoot->right);
    }
};