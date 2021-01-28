/*
 * @Author: your name
 * @Date: 2021-01-28 15:58:52
 * @LastEditTime: 2021-01-28 20:49:13
 * @LastEditors: Please set LastEditors
 * @Description: 剑指 Offer 36. 二叉搜索树与双向链表
 * 输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的循环双向链表。要求不能创建任何新的节点，只能调整树中节点指针的指向。
 * @FilePath: /offer2/36.cpp
 */
#include "../dependOn.h"
#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        if(!root) return nullptr;
        Node* cur=root;
        while(cur->left) cur=cur->left;
        Node* head=new Node(-1);

        cur=root;
        Node* pre=head;
        while(cur){
            if(cur->left){
                Node* mostRight=cur->left;
                while(mostRight->right!=nullptr && mostRight->right!=cur) mostRight=mostRight->right;
                if(mostRight->right==nullptr) {
                    mostRight->right=cur;
                    cur=cur->left;
                    continue;
                }else{
                    mostRight->right=nullptr;
                }
            }
            pre->right=cur;
            cur->left=pre;
            pre=cur;
            cur=cur->right;
        }
        pre->right=head->right;
        head->right->left=pre;
        return head->right;
    }
};
int main(){
    vector<Node*> t;
    for(int i=1;i<8;i++){
        t.push_back(new Node(i));
    }
    t[0]->left=t[1];
    t[0]->right=t[2];
    t[1]->left=t[3];
    t[1]->right=t[4];
    t[2]->left=t[5];
    t[2]->right=t[6];
    Node* root=t[0];

    Solution s;
    Node* p=s.treeToDoublyList(root);
    while(p){
        cout << p->val << endl;
        p=p->right;
    }
    return 0;


}