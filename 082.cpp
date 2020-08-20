/*
 * @Descripttion: 82. 删除排序链表中的重复元素 II
        给定一个排序链表，删除所有含有重复数字的节点，只保留原始链表中 没有重复出现 的数字。
 * @version: 
 * @Author: Ye Yating
 * @Date: 2020-08-20 10:12:52
 * @LastEditors: Ye Yating
 * @LastEditTime: 2020-08-20 14:04:49
 */
#include <iostream>
#include <vector>
using std::vector;
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x)
        : val(x)
        , next(NULL)
    {
    }
};
class Solution {
public:
    // 执行用时：12 ms, 在所有 C++ 提交中击败了56.77% 的用户
    // 内存消耗：7.3 MB, 在所有 C++ 提交中击败了25.18% 的用户
    ListNode* deleteDuplicates(ListNode* head)
    {
        if (head == nullptr)
            return head;
        ListNode* h = new ListNode(INT8_MAX);
        h->next = head;
        ListNode* pre = h;
        ListNode* cur = pre->next;
        while (cur->next) {
            int preN = pre->next->val;
            if (preN == cur->next->val)
                cur = cur->next;
            else if (preN != cur->next->val) {
                if (cur == pre->next) {
                    pre = cur;
                    cur = cur->next;
                } else {
                    cur = cur->next;
                    pre->next = cur;
                }
            }
        }
        if (cur != pre->next)
            pre->next = NULL;
        return h->next;
    }
};
int main()
{
    Solution s;
    vector<int> arr = { 1, 1, 2, 2, 3, 4, 5, 7, 7, 7 };
    ListNode *head, *p;
    ListNode* tmp = new ListNode(arr[0]);
    head = tmp;
    p = head;
    for (int i = 1; i < arr.size(); i++) {
        ListNode* t = new ListNode(arr[i]);
        p->next = t;
        p = p->next;
    }
    p->next = NULL;

    p = s.deleteDuplicates(head);
    while (p != nullptr) {
        std::cout << p->val << " ";
        p = p->next;
    }
    std::cout << std::endl;
    return 0;
}