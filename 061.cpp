/*
 * @Descripttion: 61. 旋转链表
        给定一个链表，旋转链表，将链表每个节点向右移动 k 个位置，其中 k 是非负数。
 * @Author: Ye Yating
 * @Date: 2020-08-05 22:55:01
 * @LastEditors: Ye Yating
 * @LastEditTime: 2020-08-06 12:06:32
 */
#include <iostream>
#include <vector>
using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x)
        : val(x)
        , next(NULL)
    {
    }
};
//双指针
// 执行用时：16 ms, 在所有 C++ 提交中击败了15.22% 的用户
// 内存消耗：7 MB, 在所有 C++ 提交中击败了91.49% 的用户
ListNode* rotateRight(ListNode* head, int k)
{
    if (head == nullptr)
        return nullptr;
    if (head->next == NULL)
        return head;

    ListNode* p = head;
    int count = 0;
    while (p) {
        count++;
        p = p->next;
    }
    k = k % count;

    p = head;
    while ((k--) > 0) {
        p = p->next;
    }
    if (p == head)
        return head;
    ListNode* q = head;
    while (p->next) {
        p = p->next;
        q = q->next;
    }
    p->next = head;
    p = q->next;
    q->next = NULL;

    return p;
}
// 执行用时：16 ms, 在所有 C++ 提交中击败了15.22% 的用户
// 内存消耗：7.1 MB, 在所有 C++ 提交中击败了51.04% 的用户
ListNode* rotateRight2(ListNode* head, int k)
{
    if (head == nullptr)
        return nullptr;
    if (head->next == NULL)
        return head;

    ListNode* p = head;
    int count = 1;
    while (p->next) {
        count++;
        p = p->next;
    }
    k = k % count;

    p->next = head;
    p = p->next;
    for (int i = 0; i < count - k - 1; i++) {
        p = p->next;
    }
    head = p->next;
    p->next = NULL;

    return head;
}
int main()
{
    ListNode* head = new ListNode(1);
    ListNode* p = head;
    int count = 2;
    while (count <= 5) {
        ListNode* tmp = new ListNode(count++);
        p->next = tmp;
        p = p->next;
    }
    p->next = NULL;

    p = head;
    cout << p->val << " ";
    while (p->next) {
        p = p->next;
        cout << p->val << " ";
    }
    cout << endl;

    p = rotateRight2(head, 7);
    cout << p->val << " ";
    while (p->next) {
        p = p->next;
        cout << p->val << " ";
    }
    cout << endl;
}