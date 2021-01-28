/*
 * @Author: your name
 * @Date: 2021-01-28 15:12:00
 * @LastEditTime: 2021-01-28 15:58:44
 * @LastEditors: Please set LastEditors
 * @Description: 剑指 Offer 35. 复杂链表的复制
 * 请实现 copyRandomList 函数，复制一个复杂链表。在复杂链表中，每个节点除了有一个 next 指针指向下一个节点，
 * 还有一个 random 指针指向链表中的任意节点或者 null。
 * @FilePath: /offer2/35.cpp
 */
#include "../dependOn.h"
#include <map>
using namespace std;
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return nullptr;
        map<Node*,Node*> hash;
        Node* h=new Node(-1);
        Node* p1=head,*p2=h;
        while(p1){
            p2->next=new Node(p1->val);
            p2=p2->next;
            hash[p1]=p2;
            p1=p1->next;
        }
        p1=head;
        p2=h->next;
        while(p2){
            p2->random=hash[p1->random];
            p1=p1->next;
            p2=p2->next;
        }
        return h->next;
    }
    Node* copyRandomList(Node* head) {
        if(!head) return nullptr;
        Node* p=head;
        while(p){
            Node* tmp=new Node(p->val);
            tmp->next=p->next;
            p->next=tmp;
            p=tmp->next;
        }
        p=head;
        while(p){
            if(p->random) p->next->random=p->random->next;
            p=p->next->next;
        }
        Node* h=head->next;
        Node* pre=head,*cur=head->next;
        while(cur->next!=nullptr){
            pre->next=pre->next->next;
            cur->next=cur->next->next;
            pre=pre->next;
            cur=cur->next;
        }
        pre->next=nullptr;
        return h;
        
    }
};