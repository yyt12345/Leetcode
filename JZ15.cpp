/*
 * @Author: your name
 * @Date: 2020-11-03 10:28:59
 * @LastEditTime: 2020-11-03 10:44:00
 * @LastEditors: Please set LastEditors
 * @Description: 输入一个链表，反转链表后，输出新链表的表头。
 * @FilePath: /undefined/home/whh/programming/Leetcode/JZ15.cpp
 */
#include "dependOn.h"
#include <iostream>
using namespace std;
class Solution {
public:
// 递归
    ListNode* ReverseList(ListNode* pHead) {
        if(pHead==nullptr || pHead->next==nullptr) return pHead;
        ListNode* pre,* cur,* next;
        pre=pHead;
        cur=pre->next;
        next=cur->next;
        while(next!=nullptr){
            cur->next=pre;

            pre=cur;
            cur=next;
            next=cur->next;
        }
        cur->next=pre;
        pHead->next=nullptr;
        return cur;
    }
};
int main(){
    ListNode* head=new ListNode(0);
    ListNode* q=head;
    for(int i=1;i<=5;i++){
        ListNode* t=new ListNode(i);
        q->next=t;
        q=q->next;
    }

    Solution s;
    q=s.ReverseList(head->next);
    while(q!=nullptr){
        cout << q->val << " ";
        q=q->next;
    }
    
}