/*
 * @Author: your name
 * @Date: 2020-09-25 10:43:05
 * @LastEditTime: 2020-09-25 15:58:04
 * @LastEditors: Please set LastEditors
 * @Description: 106. 从中序与后序遍历序列构造二叉树
		根据一棵树的中序遍历与后序遍历构造二叉树。
 * @FilePath: /undefined/home/whh/programming/Leetcode/106.cpp
 */
#include "dependOn.h"
#include <map>
using std::map;

class Solution {
    map<int,int> hash;
    vector<int> post;
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for(int i=0;i<inorder.size();i++) hash[inorder[i]]=i;
        post=postorder;
        TreeNode* root=dfs(0,inorder.size()-1,0,postorder.size()-1);
        return root;
    }
    TreeNode* dfs(int is,int ie,int ps,int pe){
        if(ie<is || pe<ps) return nullptr;

        int root=post[pe];
        int ri=hash[root];

        TreeNode* node=new TreeNode(root);
        node->left=dfs(is,ri-1,ps,ps+ri-is-1);
        node->right=dfs(ri+1,ie,ps+ri-is,pe-1);
        return node;
    }
};
