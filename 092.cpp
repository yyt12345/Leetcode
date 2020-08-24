/*
 * @Descripttion: 92. 反转链表 II
        反转从位置 m 到 n 的链表。请使用一趟扫描完成反转。
        说明:
        1 ≤ m ≤ n ≤ 链表长度。
 * @version: 
 * @Author: Ye Yating
 * @Date: 2020-08-24 13:47:57
 * @LastEditors: Ye Yating
 * @LastEditTime: 2020-08-24 14:27:45
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
    // 执行用时：4 ms, 在所有 C++ 提交中击败了64.58% 的用户
    // 内存消耗：6.6 MB, 在所有 C++ 提交中击败了42.46% 的用户
    ListNode* reverseBetween(ListNode* head, int m, int n)
    {
        vector<ListNode*> list;
        ListNode* h = new ListNode(INT8_MAX);
        h->next = head;

        int i = 0;
        ListNode* q = h;
        ListNode* start;
        ListNode* end;
        while (q != nullptr) {
            if (i == m - 1)
                start = q;
            else if (i <= n && i >= m)
                list.push_back(q);
            if (i == n) {
                end = q->next;
                break;
            }
            q = q->next;
            i++;
        }
        start->next = list.back();
        for (int j = list.size() - 1; j > 0; j--) {
            list[j]->next = list[j - 1];
        }
        list[0]->next = end;

        return h->next;
    }
};
int main()
{
    Solution s;
    vector<int> arr = { 1, 2, 3, 4, 5 };
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

    p = s.reverseBetween(head, 2, 5);
    while (p != nullptr) {
        std::cout << p->val << " ";
        p = p->next;
    }
    std::cout << std::endl;
    return 0;
}