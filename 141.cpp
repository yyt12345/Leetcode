/*
 * @Author: Ye Yating
 * @Date: 2020-10-09 20:06:08
 * @LastEditTime: 2020-10-09 21:16:35
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /undefined/home/whh/programming/Leetcode/141.cpp
 */
#include "dependOn.h"
#include <map>
using std::map;
class Solution {
public:
// 执行用时：48 ms, 在所有 C++ 提交中击败了5.82% 的用户
// 内存消耗：10.1 MB, 在所有 C++ 提交中击败了5.05% 的用户
    bool hasCycle(ListNode *head) {
        map<ListNode*,bool> hash;
        ListNode* q=head;
        while(q!=nullptr){
            if(!hash[q]) hash[q]=1;
            else return true;
            q=q->next;

        }
        return false;
    }
// 快慢指针
// 执行用时：12 ms, 在所有 C++ 提交中击败了65.52% 的用户
// 内存消耗：7.4 MB, 在所有 C++ 提交中击败了77.25% 的用户
    bool hasCycle2(ListNode *head) {
        if(head==nullptr || head->next==nullptr)    return false;
        ListNode* slow,*quick;
        slow=head;
        quick=head->next;
        while (quick!=slow)
        {
            if(fast==nullptr || fast->next==nullptr) return false;
            slow=slow->next;
            fast=fast->next->next;
        }
        return true;

    }
};