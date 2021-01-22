/*** 
 * @Author: whh
 * @Date: 2020-12-29 13:53:02
 * @LastEditTime: 2020-12-29 14:44:54
 * @LastEditors: whh
 * @Description: 在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，重复的结点不保留，返回链表头指针。 例如，链表1->2->3->3->4->4->5 处理后为 1->2->5
 * @FilePath: /Leetcode/JZ56.cpp
 */
#include "dependOn.h"
class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead)
    {
        if (!pHead)
            return nullptr;
        ListNode* Head = new ListNode(-1);
        Head->next = pHead;
        ListNode* q = Head;
        while (q->next && q->next->next) {
            ListNode* tmp = q->next;
            if (q->next->val == tmp->next->val) {
                while (tmp->next != nullptr && q->next->val == tmp->next->val)
                    tmp = tmp->next;
                q->next = tmp->next;
            } else
                q = q->next;
        }
        return Head->next;
    }
};