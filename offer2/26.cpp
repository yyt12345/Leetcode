/*
 * @Author: your name
 * @Date: 2021-01-27 17:16:53
 * @LastEditTime: 2021-01-27 17:59:36
 * @LastEditors: Please set LastEditors
 * @Description: 剑指 Offer 26. 树的子结构
 * 输入两棵二叉树A和B，判断B是不是A的子结构。(约定空树不是任意一个树的子结构)
 * B是A的子结构， 即 A中有出现和B相同的结构和节点值。
 * @FilePath: /offer2/24.cpp
 */
#include "../dependOn.h"
class Solution {
public:
    bool isSubTree(TreeNode* A,TreeNode* B){
        if(!B) return true;
        else if(!A) return false;
        else if(A->val!=B->val) return false;

        return isSubTree(A->left,B->left) && isSubTree(A->right,B->right);
    }
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if(!A || !B) return false;
        if(isSubTree(A,B)) return true;
        return isSubStructure(A->left,B) || isSubStructure(A->right,B);
    }
};