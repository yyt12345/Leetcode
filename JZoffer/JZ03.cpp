/*** 
 * @Author: whh
 * @Date: 2020-12-14 14:35:25
 * @LastEditTime: 2020-12-14 14:49:14
 * @LastEditors: whh
 * @Description: 输入一个链表，按链表从尾到头的顺序返回一个ArrayList。
 * @FilePath: /Leetcode/JZ03.cpp
 */
#include "dependOn.h"
#include <stack>
#include <vector>
using namespace std;
class Solution {
public:
    /*** 
     * @description: 用堆栈
     */
    vector<int> printListFromTailToHead(ListNode* head)
    {
        stack<int> s;
        ListNode* q = head;
        while (q) {
            s.push(q->val);
            q = q->next;
        }
        vector<int> res;
        while (!s.empty()) {
            res.push_back(s.top());
            s.pop();
        }
        return res;
    }
    /*** 
     * @description: 直接反转数组
     */
    vector<int> printListFromTailToHead(ListNode* head)
    {
        vector<int> res;
        ListNode* q = head;
        while (q) {
            res.push_back(q->val);
            q = q->next;
        }
        // reverse(res.begin(),res.end());
        int n = res.size();
        for (int i = 0; i < n - 1 - i; i++) {
            swap(res[i], res[n - 1 - i]);
        }
        return res;
    }
    /*** 
     * @description: 递归法  mask! mask!
     */
    vector<int> printListFromTailToHead(ListNode* head)
    {
        if (head == nullptr)
            return {};
        vector<int> res = printListFromTailToHead(head->next);
        res.push_back(head->val);
        return res;
    }
};