/*
 * @Author: your name
 * @Date: 2021-01-27 16:32:53
 * @LastEditTime: 2021-01-27 16:43:25
 * @LastEditors: Please set LastEditors
 * @Description: 剑指 Offer 22. 链表中倒数第k个节点
 * 输入一个链表，输出该链表中倒数第k个节点。为了符合大多数人的习惯，本题从1开始计数，即链表的尾节点是倒数第1个节点。
 * 例如，一个链表有6个节点，从头节点开始，它们的值依次是1、2、3、4、5、6。这个链表的倒数第3个节点是值为4的节点
 * @FilePath: /offer2/22.cpp
 */
#include "../dependOn.h"
#include <vector>
using namespace std;
class Solution {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        if(!head) return nullptr;
        ListNode* p=head;
        int i=0;
        while(p && i<k){
            p=p->next;
            i++;
        }
        if(i!=k) return nullptr;//链表数小于k
        ListNode* q=head;
        while(p){
            p=p->next;
            q=q->next;
        }
        return q;
    }
};
