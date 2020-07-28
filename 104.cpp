/*
 * @Descripttion: 104. 二叉树的最大深度
        给定一个二叉树，找出其最大深度。
        二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。
        说明: 叶子节点是指没有子节点的节点。
 * @version: 
 * @Author: Ye Yating
 * @Date: 2020-07-28 09:48:27
 * @LastEditors: Ye Yating
 * @LastEditTime: 2020-07-28 09:48:28
 */ 
#include <iostream>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
// 执行用时：8 ms, 在所有 C++ 提交中击败了91.68% 的用户
// 内存消耗：17 MB, 在所有 C++ 提交中击败了100.00% 的用户
int maxD=0;
void func(TreeNode* root,int dep){
    if(root->left==NULL && root->right==NULL){
        maxD=max(maxD,dep);
        return;
    }
    if(root->left){
        func(root->left,dep+1);
    }
    if(root->right){
        fun(root->right,dep+1);
    }
    return;
}
int maxDepth(TreeNode* root) {
    if(root==NULL) return 0;
    func(root,1);
    return maxD;    
}
// 深入挖掘函数的含义、递归的流程
// 执行用时：12 ms, 在所有 C++ 提交中击败了65.28% 的用户
// 内存消耗：17 MB, 在所有 C++ 提交中击败了100.00% 的用户
int maxDepth(TreeNode* root){
    if(root==BULL) return 0;
    return max(maxDepth(root->left),maxDepth(root->right))+1;
}
int main(){
    
}