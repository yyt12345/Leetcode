/*** 
 * @Author: whh
 * @Date: 2020-12-14 16:01:12
 * @LastEditTime: 2020-12-14 16:03:24
 * @LastEditors: whh
 * @Description: 输入一个链表，输出该链表中倒数第k个结点。
 * @FilePath: /Leetcode/ZJ14.cpp
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
};