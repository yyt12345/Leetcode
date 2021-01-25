/*
 * @Author: your name
 * @Date: 2021-01-24 23:40:02
 * @LastEditTime: 2021-01-25 00:03:21
 * @LastEditors: Please set LastEditors
 * @Description: 剑指 Offer 06. 从尾到头打印链表
 * 输入一个链表的头节点，从尾到头反过来返回每个节点的值（用数组返回）。
 * 方法一：存入堆栈
 * 方法二：反转数组
 * 方法三：递归
 * @FilePath: /offer2/06.cpp
 */
#include "../dependOn.h"
#include <stack>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
class Solution {
    vector<int> res;
public:
    //递归
    void func(ListNode* head){
        if(!head) return;

        func(head->next);
        res.push_back(head->val);
        return;
    }
    vector<int> reversePrint(ListNode* head) {
        func(head);
        return res;
    }
    //堆栈
    vector<int> reversePrint2(ListNode* head) {
        stack<int> s;
        ListNode* p=head;
        while(p){
            s.push(p->val);
            p=p->next;
        }
        vector<int> res;
        while(!s.empty()){
            res.push_back(s.top());
            s.pop();
        }
        return res;
    }
    //反转数组
    vector<int> reversePrint3(ListNode* head) {
        vector<int> s;
        ListNode* p=head;
        while(p){
            s.push_back(p->val);
            p=p->next;
        }
        reverse(s.begin(),s.end());
        return s;
    }
};
int main(){
    Solution s;
    ListNode* h1=new ListNode(0);
    ListNode* q=h1;
    for(int i=1;i<5;i++){
        q->next=new ListNode(i);
        q=q->next;
    }
    vector<int> res=s.reversePrint2(h1);
    for(auto n:res)
        cout << n << " ";
    cout << endl;
}