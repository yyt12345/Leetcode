/*
 * @Author: your name
 * @Date: 2020-10-29 11:02:46
 * @LastEditTime: 2020-11-02 16:18:44
 * @LastEditors: Please set LastEditors
 * @Description: 树的几种遍历方法
 * @FilePath: /undefined/home/whh/programming/Leetcode/treeTraverse.cpp
 */
#include "dependOn.h"
#include <vector>
#include <queue>
#include <stack>
#include <iostream>
using namespace std;
class TreeAl{
public:
//中序遍历 递归算法
    static void midRecur(TreeNode* root){
        if(!root) return;

        midRecur(root->left);
        cout << root->val << " ";
        midRecur(root->right);

    }
//中序遍历 迭代算法
    static void midIteration(TreeNode* root){
        if(!root) return;

        stack<TreeNode*> s;
        TreeNode* cur=root;
        while(true){
            while(cur){
                s.push(cur);
                cur=cur->left;
            }
            if(s.empty()) break;
            cur=s.top();
            cout << cur->val << " ";

            cur=cur->right;
            s.pop();

        }
        return;
    }

//前序遍历 递归算法
    static void preRecur(TreeNode* root){
        if(!root) return;

        cout << root->val << " ";
        preRecur(root->left);
        preRecur(root->right);
        return;
    }
//前序遍历 迭代算法
    static void preIteration(TreeNode* root){
        if(!root) return;

        stack<TreeNode*> s;
        TreeNode* cur=root;
        while(true){
            while(cur){
                s.push(cur);
                cout << cur->val << " ";
                cur=cur->left;
            }
            if(s.empty()) break;
            cur=s.top()->right;
            s.pop();
        }
    }

//后序遍历 递归算法
    static void backRecur(TreeNode* root){
        if(!root) return;

        backRecur(root->left);
        backRecur(root->right);
        cout << root->val << " ";
        return ;
    }


//层次遍历
    static void levelIteration_1(TreeNode* root){
        if(!root) return;

        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* cur=q.front();
            q.pop();

            cout << cur->val << " ";
            if(cur->left) q.push(cur->left);
            if(cur->right) q.push(cur->right);
        }
        return;
    }

    static void levelIteration_2(TreeNode* root){
        if(!root) return;

        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            for(int i=0;i<n;i++){
                TreeNode* cur=q.front();
                q.pop();

                cout << cur->val << " ";
                if(cur->left) q.push(cur->left);
                if(cur->right) q.push(cur->right);
            }
            cout << endl;
        }
        return;
    }

//morris遍历
    static void morrisMid(TreeNode* root){
        if(!root) return;

        TreeNode* cur=root;
        TreeNode* mostRight;
        while(cur!=nullptr){
            mostRight=cur->left;
            if(mostRight){
                while(mostRight->right!=nullptr && mostRight->right!=cur) mostRight=mostRight->right;
                if(mostRight->right==nullptr){ //最右边的节点指向空 第一次到达节点
                    mostRight->right=cur;
                    cout << cur->val << " ";// 前序遍历
                    cur=cur->left;
                    continue;
                }else{  //最右边节点指向cur 第二次到达节点
                    mostRight->right=nullptr;
                    // 后序遍历
                }
            }
            else{ //前序遍历
                cout << cur->val << " ";
            }
            // cout << cur->val << " "; //中序遍历
            cur=cur->right;
        }
        // 后序遍历
    }
};

int main(){
    vector<int> nums={1,2,3,4,5,6,7};
    TreeNode* root=createTree(nums,0);

    
    cout << "中序遍历（递归）： ";
    TreeAl::midRecur(root);
    cout << endl;

    cout << "中序遍历（迭代）： ";
    TreeAl::midIteration(root);
    cout << endl;

    cout << "前序遍历（递归）： ";
    TreeAl::preRecur(root);
    cout << endl;

    cout << "前序遍历（迭代）： ";
    TreeAl::preIteration(root);
    cout << endl;

    cout << "后序遍历（递归）： ";
    TreeAl::backRecur(root);
    cout << endl;

    cout << "层次遍历（迭代）： ";
    TreeAl::levelIteration_1(root);
    cout << endl;

    cout << "层次遍历（迭代）： "<< endl;
    TreeAl::levelIteration_2(root);

    cout << "morris中序： ";
    TreeAl::morrisMid(root);
    cout << endl;

}