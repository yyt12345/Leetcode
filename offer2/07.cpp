/*
 * @Author: your name
 * @Date: 2021-01-25 09:30:14
 * @LastEditTime: 2021-01-25 23:00:06
 * @LastEditors: Please set LastEditors
 * @Description: 剑指 Offer 07. 重建二叉树
 * 输入某二叉树的前序遍历和中序遍历的结果，请重建该二叉树。假设输入的前序遍历和中序遍历的结果中都不含重复的数字
 * 方法一：
 * @FilePath: /offer2/07.cpp
 */
#include "../dependOn.h"
#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    TreeNode* buildSubTree(vector<int>& pre,vector<int>& in,int ps,int pe,int is,int ie){
        if(ps>pe || is>ie) return nullptr;

        int rootN=pre[ps];
        TreeNode* root=new TreeNode(rootN);

        int i=is;
        while(i<=ie && in[i]!=rootN) i++;
        if(i>ie) return nullptr;
        root->left=buildSubTree(pre,in,ps+1,ps+i-is,is,i-1);
        root->right=buildSubTree(pre,in,ps+i-is+1,pe,i+1,ie);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int m=preorder.size(),n=inorder.size();
        if(m!=n || m==0) return nullptr;
        else if(m==1) return new TreeNode(preorder[0]); 

        return buildSubTree(preorder,inorder,0,m-1,0,n-1);
    }
};
int main(){
    vector<int> preorder={3,9,20,15,7};
    vector<int> inorder={9,3,15,20,7};

    Solution s;
    s.buildTree(preorder,inorder);
}
