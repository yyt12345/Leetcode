/*
 * @Author: your name
 * @Date: 2020-09-22 08:45:29
 * @LastEditTime: 2020-09-22 09:48:13
 * @LastEditors: Please set LastEditors
 * @Description: 968. 监控二叉树
        给定一个二叉树，我们在树的节点上安装摄像头。
        节点上的每个摄影头都可以监视其父对象、自身及其直接子对象。
        计算监控树的所有节点所需的最小摄像头数量。
 * @FilePath: /Leetcode/968.cpp
 */
#include "dependOn.h"
class Solution
{
    int res;

public:
    int lrd(TreeNode *node)
    {

        if (node == nullptr)
        {
            return 1;
        }
        int left = lrd(node->left);
        int right = lrd(node->right);
        if (left == 0 || right == 0)
        {
            res++;
            return 2;
        }
        if (left == 1 && right == 1)
        {
            return 0;
        }
        if (left + right >= 3)
        {
            return 1;
        }

        return -1;
    }

    int minCameraCover(TreeNode *root)
    {
        if (lrd(root) == 0)
            res++;
        return res;
    }
};