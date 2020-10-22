/*
 * @Author: your name
 * @Date: 2020-10-22 14:06:18
 * @LastEditTime: 2020-10-22 14:42:29
 * @LastEditors: Please set LastEditors
 * @Description: 输入两个单调递增的链表，输出两个链表合成后的链表，当然我们需要合成后的链表满足单调不减规则。
 * @FilePath: /undefined/home/whh/programming/Leetcode/ZJ16.cpp
 */
#include "dependOn.h"
#include <iostream>
using namespace std;
class Solution {
public:
//迭代
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        if(!pHead1) return pHead2;
        else if(!pHead2) return pHead1;

        ListNode* resHead=new ListNode(0);
        ListNode* t=resHead;
        ListNode* p=pHead1,*q=pHead2;
        while(p!=nullptr && q!=nullptr){
            if(p->val <= q->val){
                t->next=p;
                p=p->next;
                t=t->next;
            }else{
                t->next=q;
                q=q->next;
                t=t->next;
            }
        }
        if(p==nullptr) t->next=q;
        else{
            t->next=p;
        }
        return resHead->next;
    }
    //递归
    ListNode* Merge2(ListNode* pHead1, ListNode* pHead2)
    {
        if(pHead1==nullptr) return pHead2;
        else if(pHead2==nullptr) return pHead1;

        if(pHead1->val <= pHead2->val){
            pHead1->next=Merge(pHead1->next,pHead2);
            return pHead1;
        }else{
            pHead2->next=Merge(pHead1,pHead2->next);
            return pHead2;
        }
    }
};
int main(){
    ListNode* pHead1=new ListNode(1);
    pHead1->next=new ListNode(3);
    pHead1->next->next=new ListNode(5);

    ListNode* pHead2=new ListNode(2);
    pHead2->next=new ListNode(4);
    pHead2->next->next=new ListNode(6);

    Solution s;
    ListNode* res=s.Merge2(pHead1,pHead2);
    ListNode* q=res;
    while(q!=nullptr){
        cout << q->val << " ";
        q=q->next;
    }

}