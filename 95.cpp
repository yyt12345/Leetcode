/*
 * @Descripttion: 95. 不同的二叉搜索树 II
        给定一个整数 n，生成所有由 1 ... n 为节点所组成的 二叉搜索树 。
 * @version: 
 * @Author: Ye Yating
 * @Date: 2020-07-21 11:00:30
 * @LastEditors: Ye Yating
 * @LastEditTime: 2020-07-21 11:45:55
 */ 
#include <vector>
#include <iostream>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
// 执行用时：20 ms, 在所有 C++ 提交中击败了86.65% 的用户
// 内存消耗：14.4 MB, 在所有 C++ 提交中击败了94.74% 的用户
vector<TreeNode*> subTree(int start,int end){
    if(start>end) return {nullptr};

    vector<TreeNode*> allTrees;
    for(int i=start;i<=end;i++){
        vector<TreeNode*> leftTree=subTree(start,i-1);
        vector<TreeNode*> rightTree=subTree(i+1,end);
        for(auto& left:leftTree){
            for(auto& right:rightTree){
                TreeNode* currTree=new TreeNode(i);
                currTree->left=left;
                currTree->right=right;
                allTrees.push_back(currTree);
            }
        }
    }
    return allTrees;
}
vector<TreeNode*> generateTrees(int n) {
    if(!n) return {};
    return subTree(1,n);
}