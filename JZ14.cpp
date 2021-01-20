/*** 
 * @Author: whh
 * @Date: 2020-12-14 16:01:12
 * @LastEditTime: 2020-12-14 16:14:45
 * @LastEditors: whh
 * @Description: 输入一个链表，输出该链表中倒数第k个结点。
 * @FilePath: /Leetcode/JZ14.cpp
 */
#include "dependOn.h"
using namespace std;
class Solution {
public:
    /*** 
     * @description: 快慢指针
     */
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k)
    {
        if (!pListHead || k <= 0)
            return nullptr;
        ListNode* q = pListHead;
        ListNode* p = pListHead;
        while (k--) {
            if (q)
                q = q->next;
            else
                return nullptr;
        }
        while (q) {
            q = q->next;
            p = p->next;
        }
        return p;
    }
    /*** 
     * @description: 稍微改进一下
     */
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k)
    {
        if (!pListHead || k <= 0)
            return nullptr;
        ListNode *fast = pListHead, *slow = pListHead;
        int n = 0;
        while (fast) {
            if (n >= k)
                slow = slow->next;
            fast = fast->next;
            n++;
        }
        return n >= k ? slow : nullptr;
    }
};