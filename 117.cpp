/*
 * @Author: your name
 * @Date: 2020-09-28 10:40:15
 * @LastEditTime: 2020-09-28 10:53:41
 * @LastEditors: Please set LastEditors
 * @Description: 117. 填充每个节点的下一个右侧节点指针 II
        给定一个二叉树
        struct Node {
        int val;
        Node *left;
        Node *right;
        Node *next;
        }
        填充它的每个 next 指针，让这个指针指向其下一个右侧节点。如果找不到下一个右侧节点，则将 next 指针设置为 NULL。
        初始状态下，所有 next 指针都被设置为 NULL。
 * @FilePath: /undefined/home/whh/programming/Leetcode/117.cpp
 */
#include "dependOn.h"
#include <queue>
using std::queue;
// 执行用时：24 ms, 在所有 C++ 提交中击败了47.82% 的用户
// 内存消耗：17.3 MB, 在所有 C++ 提交中击败了25.42% 的用户
class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*> q;
        q.push(root);
        q.push(nullptr);

        int count;
        while(!q.empty()){
            Node* tmp=q.front();
            q.pop();
            if(tmp!=nullptr){
                count=0;
                tmp->next=q.front();
                if(tmp->left) q.push(tmp->left);
                if(tmp->right) q.push(tmp->right);
            }else{
                q.push(nullptr);
                if(++count==2) break;
            }
        }
        return root;
    }
};