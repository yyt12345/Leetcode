/*
 * @Author: your name
 * @Date: 2020-11-05 09:30:17
 * @LastEditTime: 2020-11-05 09:47:18
 * @LastEditors: Please set LastEditors
 * @Description: 输入两个链表，找出它们的第一个公共结点。（注意因为传入数据是链表，所以错误测试数据的提示是用其他方式显示的，保证传入数据是正确的）
 * @FilePath: /undefined/home/whh/programming/Leetcode/JZ36.cpp
 */
#include "dependOn.h"
#include <map>
using namespace std;
class Solution {
public:
//哈希
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        if(pHead1==nullptr || pHead2==nullptr) return nullptr;
        map<ListNode*,int> hash;
        ListNode* q=pHead1;
        while(q){
            hash[q]=1;
            q=q->next;
        }
        q=pHead2;
        while(q){
            if(hash.count(q)) return q;
            q=q->next;
        }
        return nullptr;
    }
// 对于两个有公共节点的指针，最后几位的节点一定相同 只需要将两个链表串联，只要有公共节点，必定相遇
// 12345 -> 123456745
// 6745  -> 674512345
// 双指针法
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        if(pHead1==nullptr || pHead2==nullptr) return nullptr;
        ListNode* p=pHead1,*q=pHead2;
        while(q!=p){
            q=q ? q->next : pHead1;
            p=p ? p->next : pHead2;
        }
        return q;
    }    
};