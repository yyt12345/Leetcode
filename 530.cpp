/*
 * @Author: your name
 * @Date: 2020-10-12 14:14:57
 * @LastEditTime: 2020-10-13 10:04:01
 * @LastEditors: Please set LastEditors
 * @Description: 530. 二叉搜索树的最小绝对差
        给你一棵所有节点为非负值的二叉搜索树，请你计算树中任意两节点的差的绝对值的最小值。
 * @FilePath: /undefined/home/whh/programming/Leetcode/530.cpp
 */
#include "dependOn.h"
#include <queue>
#include <iostream>
#include <algorithm>
using std::queue;
// 执行用时：24 ms, 在所有 C++ 提交中击败了93.02% 的用户
// 内存消耗：24.6 MB, 在所有 C++ 提交中击败了51.62% 的用户
class Solution {
public:
    int getMinimumDifference(TreeNode* root) {
        TreeNode* cur=root;
        int pre=root->val;
        int minN=__INT_MAX__;
        while(cur!=nullptr){
            if(cur->left){
                TreeNode* mostRight=cur->left;
                while(mostRight->right!=nullptr && mostRight->right!=cur) {
                    mostRight=mostRight->right;
                }
                if(mostRight->right==nullptr) {    
                    mostRight->right=cur;
                    cur=cur->left;
                }else if(mostRight->right==cur){
                    minN=cur->val-pre>0?std::min(cur->val-pre,minN):minN;
                    pre=cur->val;
                    mostRight->right=nullptr;
                    cur=cur->right;
                }
            }else{
                minN=cur->val-pre>0?std::min(cur->val-pre,minN):minN;
                pre=cur->val;
                cur=cur->right;
            }
        }
        return minN;
        
    }
};
int main(){
    TreeNode* root=new TreeNode(1);
    root->left=new TreeNode(2);
    root->right=new TreeNode(3);
    TreeNode* cur=root->left;
    cur->left=new TreeNode(4);
    cur->right=new TreeNode(5);
    cur=root->right;
    cur->left=new TreeNode(6);
    cur->right=new TreeNode(7);

    Solution s;
    std::cout << s.getMinimumDifference(root) << std::endl;
}