/*
 * @Author: your name
 * @Date: 2020-10-10 08:57:22
 * @LastEditTime: 2020-10-10 09:07:04
 * @LastEditors: Please set LastEditors
 * @Description: 142. 环形链表 II
        给定一个链表，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。
        为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。 如果 pos 是 -1，则在该链表中没有环。
        说明：不允许修改给定的链表。
 * @FilePath: /undefined/home/whh/programming/Leetcode/142.cpp
 */
#include "dependOn.h"
#include <map>
using std::map;
class Solution {
public:
// 执行用时：44 ms, 在所有 C++ 提交中击败了7.05% 的用户
// 内存消耗：9.7 MB, 在所有 C++ 提交中击败了12.99% 的用户
    ListNode *detectCycle(ListNode *head) {
        map<ListNode*,bool> hash;
        ListNode* q=head;
        while(q!=nullptr){
            if(!hash[q]) hash[q]=1;
            else return q;
            q=q->next;

        }
        return null;
    }
    
};