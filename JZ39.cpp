/*** 
 * @Date: 2020-11-16 09:48:58
 * @LastEditors: Ye Yating
 * @LastEditTime: 2020-11-16 10:45:30
 * @FilePath: /undefined/home/whh/c++pragramming/Leetcode/JZ39.cpp
 * @Reference: 输入一棵二叉树，判断该二叉树是否是平衡二叉树。
 *        在这里，我们只需要考虑其平衡性，不需要考虑其是不是排序二叉树
 */
#include "dependOn.h"
#include <algorithm>
#include <vector>
using namespace std;
class Solution
{

public:
    /*** 
     * @description: 通过深度遍历，获取子树的最大深度并比较最大深度
     * @param : 
     * @return {*}
     */
    bool flag = true;
    int getDepthMax(TreeNode *root)
    {
        if (!root)
            return 0;
        int left = getDepthMax(root->left);
        int right = getDepthMax(root->right);
        if (abs(left - right) > 1)
            flag = false;
        return 1 + max(left, right);
    }
    bool IsBalanced_Solution(TreeNode *pRoot)
    {
        getDepthMax(pRoot);
        return flag;
    }

    /*** 
     * @description: 对方法一进行减枝操作，若发现子树不平衡则直接返回
     * @param : 
     * @return {*}
     */
    int depth(TreeNode *root)
    {
        if (!root)
            return 0;
        int left = depth(root->left);
        if (left == -1)
            return -1;
        int right = depth(root->right);
        if (right == -1)
            return -1;
        if (abs(right - left) > 1)
            return -1;
        else
            return 1 + (left > right ? left : right);
    }
    bool IsBalanced_Solution(TreeNode *pRoot)
    {
        return depth(pRoot) != -1;
    }
};
