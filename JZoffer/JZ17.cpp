/*** 
 * @Author: whh
 * @Date: 2020-12-14 16:15:48
 * @LastEditTime: 2020-12-14 16:51:35
 * @LastEditors: whh
 * @Description: 输入两棵二叉树A，B，判断B是不是A的子结构。（ps：我们约定空树不是任意一个树的子结构）
 * @FilePath: /Leetcode/JZ17.cpp
 */
#include "dependOn.h"
#include <queue>
using namespace std;
class Solution {
public:
    /*** 
     * @description: 定义一个子函数，判断是否相等。然后遍历tree的每个结点，判断是否有相同树
     */
    bool isSame(TreeNode* root1, TreeNode* root2)
    {
        if (!root2)
            return true;
        else if (!root1)
            return false;

        if (root1->val != root2->val)
            return false;
        return isSame(root1->left, root2->left) && isSame(root1->right, root2->right);
    }
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        if (!pRoot1 || !pRoot2)
            return false;
        //遍历树
        queue<TreeNode*> q;
        q.push(pRoot1);
        while (!q.empty()) {
            TreeNode* tmp = q.front();
            q.pop();
            if (isSame(tmp, pRoot2))
                return true;
            if (tmp->left)
                q.push(tmp->left);
            if (tmp->right)
                q.push(tmp->right);
        }
        return false;
    }
    /*** 
     * @description: 使用morris遍历
     */

    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        if (!pRoot1 || !pRoot2)
            return false;
        TreeNode* cur = pRoot1;
        while (cur) {
            if (cur->left) {
                TreeNode* mostRight = cur->left;
                while (mostRight->right != nullptr && mostRight->right != cur)
                    mostRight = mostRight->right;
                if (mostRight->right == nullptr) {
                    mostRight->right = cur;
                    if (isSame(cur, pRoot2))
                        return true;
                    cur = cur->left;
                } else {
                    cur = cur->right;
                    mostRight->right = nullptr;
                }
            } else {
                if (isSame(cur, pRoot2))
                    return true;
                cur = cur->right;
            }
        }
        return false;
    }
};