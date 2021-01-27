/*
 * @Author: your name
 * @Date: 2021-01-27 17:59:19
 * @LastEditTime: 2021-01-27 18:08:42
 * @LastEditors: Please set LastEditors
 * @Description: 剑指 Offer 25. 合并两个排序的链表
 * 输入两个递增排序的链表，合并这两个链表并使新链表中的节点仍然是递增排序的
 * @FilePath: /offer2/25.cpp
 */
#include "../dependOn.h"
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* head=new ListNode(0);
        ListNode* q=head,*p1=l1,*p2=l2;
        while(p1 && p2){
            if(p1->val<=p2->val) {
                q->next=p1;
                q=q->next;
                p1=p1->next;
            }else{
                q->next=p2;
                q=q->next;
                p2=p2->next;
            }
        }
        q->next= p1?p1:p2;
        return head->next;
    }
};