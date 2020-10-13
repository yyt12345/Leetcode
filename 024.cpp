/*
 * @Author: your name
 * @Date: 2020-10-13 08:47:11
 * @LastEditTime: 2020-10-13 09:19:09
 * @LastEditors: Please set LastEditors
 * @Description: 24. 两两交换链表中的节点
        给定一个链表，两两交换其中相邻的节点，并返回交换后的链表。
        你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。
 * @FilePath: /undefined/home/whh/programming/Leetcode/024.cpp
 */
#include "dependOn.h"
#include <vector>
#include <iostream>
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head==nullptr || head->next==nullptr) return head;
        ListNode *headNode=new ListNode(0);
        headNode->next=head;
        ListNode* pre=headNode;
        ListNode *q=headNode->next;
        while(q!=nullptr && q->next!=nullptr){
            ListNode* first=q;
            ListNode* second=q->next;
            q=q->next->next;
            first->next=second->next;
            second->next=first;
            pre->next=second;

            pre=first;
        }
        return headNode->next;
    }
};
int main(){
    std::vector<int> nums={1,2,3,4,5};
    ListNode* head=new ListNode(nums[0]);
    ListNode* q=head;
    for(int i=1;i<nums.size();i++){
        q->next=new ListNode(nums[i]);
        q=q->next;
    }
     
    Solution s;
    q=s.swapPairs(head);

    while(q!=nullptr){
        std::cout << q->val << " ";
        q=q->next;
    }
    
}