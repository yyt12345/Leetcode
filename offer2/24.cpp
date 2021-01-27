/*
 * @Author: your name
 * @Date: 2021-01-27 16:43:59
 * @LastEditTime: 2021-01-27 17:14:33
 * @LastEditors: Please set LastEditors
 * @Description: 剑指 Offer 24. 反转链表
 * 定义一个函数，输入一个链表的头节点，反转该链表并输出反转后链表的头节点
 * @FilePath: /offer2/23.cpp
 */
#include "../dependOn.h"
#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head) return nullptr;
        else if(!head->next) return head;

        ListNode* nextHead=reverseList(head->next);
        head->next->next=head;
        head->next=nullptr;
        return nextHead;
    }
};
int main(){
    vector<int> nums={1,2,3,4,5};
    ListNode* head=new ListNode(0);
    ListNode* p=head;
    for(int i=0;i<5;i++){
        p->next=new ListNode(nums[i]);
        p=p->next;
    }
    
    Solution s;
    p=s.reverseList(head->next);
    while(p){
        cout << p->val << " ";
        p=p->next;
    }
    cout << endl;
}