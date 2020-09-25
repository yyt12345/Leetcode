/*
 * @Author: your name
 * @Date: 2020-09-23 12:09:33
 * @LastEditTime: 2020-09-25 16:40:52
 * @LastEditors: Please set LastEditors
 * @Description: 105. 从前序与中序遍历序列构造二叉树
        根据一棵树的前序遍历与中序遍历构造二叉树。
 * @FilePath: /Leetcode/105.cpp
 */
#include <vector>
#include <map>
#include "dependOn.h"
using std::map;
using std::vector;
// 16 ms 96.78%
// 17.4 MB 39.13%
class Solution
{
    map<int,int> hash;
    vector<int> pre;
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        int n=inorder.size();
        for(int i=0;i<n;i++) hash[inorder[i]]=i;
        pre=preorder;
        return dfs(0,n-1,0,preorder.size()-1);
    }
    TreeNode* dfs(int is,int ie,int ps,int pe){
        if(ie<is || pe<ps) return nullptr;
        int root=pre[ps];
        int ri=hash[root];
        TreeNode* node=new TreeNode(root);
        node->left=dfs(is,ri-1,ps+1,ps+ri-is);
        node->right=dfs(ri+1,ie,ps+ri-is+1,pe);
        return node;

    }
};

int main(){
    vector<int> perorder={3,9,20,15,7};
    vector<int> inorder={9,3,15,20,7};
    Solution s;
    s.buildTree(perorder,inorder);
}