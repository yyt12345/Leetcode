/*
 * @Descripttion: 83. 删除排序链表中的重复元素
        给定一个排序链表，删除所有重复的元素，使得每个元素只出现一次。
 * @version: 
 * @Author: Ye Yating
 * @Date: 2020-08-17 13:11:40
 * @LastEditors: Ye Yating
 * @LastEditTime: 2020-08-17 13:50:29
 */
#include <iostream>
#include <map>
#include <vector>
using std::map;
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
    // 执行用时：8 ms, 在所有 C++ 提交中击败了99.64% 的用户
    // 内存消耗：7.6 MB, 在所有 C++ 提交中击败了48.48% 的用户
    ListNode* deleteDuplicates(ListNode* head)
    {
        if (head == nullptr)
            return head;
        ListNode* p = head;
        while (p->next != NULL) {
            if (p->val == p->next->val) {
                p->next = p->next->next;
            } else {
                p = p->next;
            }
        }
        return head;
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