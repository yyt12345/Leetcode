/*** 
 * @Date: 2020-11-19 10:23:10
 * @LastEditors: Ye Yating
 * @LastEditTime: 2020-11-19 10:59:27
 * @FilePath: /Leetcode/JZ46.cpp
 * @Reference: 每年六一儿童节,牛客都会准备一些小礼物去看望孤儿院的小朋友,今年亦是如此。HF作为牛客的资深元老,自然也准备了一些
 * 小游戏。其中,有个游戏是这样的:首先,让小朋友们围成一个大圈。然后,他随机指定一个数m,让编号为0的小朋友开始报数。每次喊到m-1的
 * 那个小朋友要出列唱首歌,然后可以在礼品箱中任意的挑选礼物,并且不再回到圈中,从他的下一个小朋友开始,继续0...m-1报数....这样下
 * 去....直到剩下最后一个小朋友,可以不用表演,并且拿到牛客名贵的“名侦探柯南”典藏版(名额有限哦!!^_^)。请你试着想下,哪个小朋友会
 * 得到这份礼品呢？(注：小朋友的编号是从0到n-1)
 */
#include "dependOn.h"
#include <iostream>
class Solution {
public:
    /*** 
     * @description: 链表
     * @param : 
     * @return {*}
     */
    int LastRemaining_Solution(int n, int m)
    {
        if (n == 0)
            return -1;
        if (n == 1)
            return 0;
        if (m == 1)
            return n - 1;

        ListNode* head = new ListNode(0);
        ListNode* q = head;
        for (int i = 1; i < n; i++) {
            q->next = new ListNode(i);
            q = q->next;
        }
        q->next = head;

        q = head;
        while (q->next != q) {
            for (int i = 1; i < m - 1; i++)
                q = q->next;
            q->next = q->next->next;
            q = q->next;
        }
        return q->val;
    }
    /*** 
     * @description: 递归 f(n,m)=(m + f(n-1,m)) % n
     *          长度为n的序列，先删除第m%n个元素。对于，留下的n-1长度序列，使用f(n-1,m)递归计算。f(n-1,m)删除的位置为x，为f（n，m）删除的位置为m%n后在数x
     * @param : 
     * @return {*}
     */
    int f(int n, int m)
    {
        if (n == 1)
            return 0;
        int x = f(n - 1, m);
        return (m + x) % n;
    }
    int LastRemaining_Solution(int n, int m)
    {
        if (n <= 0)
            return -1;
        return f(n, m);
    }
};
int main()
{
    Solution s;
    std::cout << s.LastRemaining_Solution(5, 3) << std::endl;
}