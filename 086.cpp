/*
 * @Descripttion: 86. 分隔链表
        给定一个链表和一个特定值 x，对链表进行分隔，使得所有小于 x 的节点都在大于或等于 x 的节点之前。
        你应当保留两个分区中每个节点的初始相对位置。
 * @version: 
 * @Author: Ye Yating
 * @Date: 2020-08-20 13:50:29
 * @LastEditors: Ye Yating
 * @LastEditTime: 2020-08-20 14:20:35
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
    // 执行用时：8 ms, 在所有 C++ 提交中击败了78.80% 的用户
    // 内存消耗：6.8 MB, 在所有 C++ 提交中击败了83.70% 的用户
    ListNode* partition(ListNode* head, int x)
    {
        ListNode* small = new ListNode(INT8_MAX);
        ListNode* big = new ListNode(INT8_MAX);
        ListNode *s = small, *b = big;

        ListNode* p = head;
        while (p != nullptr) {
            if (p->val < x) {
                s->next = p;
                s = s->next;
            } else {
                b->next = p;
                b = b->next;
            }
            p = p->next;
        }
        s->next = big->next;
        b->next = NULL;
        return small->next;
    }
};
int main()
{
    Solution s;
    vector<int> arr = { 1, 4, 3, 2, 5, 2 };
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

    p = s.partition(head, 3);
    while (p != nullptr) {
        std::cout << p->val << " ";
        p = p->next;
    }
    std::cout << std::endl;
    return 0;
}