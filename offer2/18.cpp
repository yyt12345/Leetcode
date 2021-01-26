/*
 * @Author: your name
 * @Date: 2021-01-26 19:55:37
 * @LastEditTime: 2021-01-26 20:00:01
 * @LastEditors: Please set LastEditors
 * @Description: 剑指 Offer 18. 删除链表的节点
 * 给定单向链表的头指针和一个要删除的节点的值，定义一个函数删除该节点。
 * 返回删除后的链表的头节点。
 * @FilePath: /offer2/18.cpp
 */
#include "../dependOn.h"

class Solution {
public:
    ListNode* deleteNode(ListNode* head, int val) {
        ListNode* h=new ListNode(-1);
        h->next=head;
        ListNode* p=h;
        while(p->next){
            if(p->next->val==val) {
                p->next=p->next->next;
                break;
            }
            p=p->next;
        }
        return h->next;
    }
};