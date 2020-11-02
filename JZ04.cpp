/*
 * @Author: your name
 * @Date: 2020-11-02 20:18:20
 * @LastEditTime: 2020-11-02 20:32:20
 * @LastEditors: Please set LastEditors
 * @Description: 输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。假设输入的前序遍历和中序遍历的结果中都不含重复的数字。例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，则重建二叉树并返回。
 * @FilePath: /undefined/home/whh/programming/Leetcode/JZ04.cpp
 */
#include "dependOn.h"
#include <vector>
using namespace std;
class Solution {
public:
    TreeNode* subFunc(vector<int> pre,vector<int> vin,int ps,int pe,int vs,int ve){
        if(ps>pe || vs>ve) return nullptr;
        TreeNode* root=new TreeNode(pre[ps]);
        int index=0;
        while(vin[index+vs]!=pre[ps]) index++;
        root->left=subFunc(pre,vin,ps+1,ps+index,vs,vs+index);
        root->right=subFunc(pre,vin,ps+index+1,pe,vs+index+1,ve);
        return root;


    }
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        return subFunc(pre,vin,0,pre.size()-1,0,vin.size()-1);

    }
};