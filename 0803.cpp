/*
 * @Descripttion: 面试题 08.03. 魔术索引
        魔术索引。 在数组A[0...n-1]中，有所谓的魔术索引，满足条件A[i] = i。给定一个有序整数数组，编写一种方法找出魔术
        索引，若有的话，在数组A中找出一个魔术索引，如果没有，则返回-1。若有多个魔术索引，返回索引值最小的一个。
 * @Author: Ye Yating
 * @Date: 2020-07-31 09:46:09
 * @LastEditors: Ye Yating
 * @LastEditTime: 2020-07-31 10:13:42
 */
#include <iostream>
#include <iterator>
#include <vector>
using namespace std;
// 执行用时：32 ms, 在所有 C++ 提交中击败了86.18% 的用户
// 内存消耗：12.4 MB, 在所有 C++ 提交中击败了86.21% 的用户
int findMagicIndex(vector<int>& nums)
{
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        if (nums[i] == i)
            return i;
    }
    return -1;
}
// 执行用时：40 ms, 在所有 C++ 提交中击败了28.43% 的用户
// 内存消耗：12.7 MB, 在所有 C++ 提交中击败了20.69% 的用户
int getAnswer(const vector<int>& nums, int left, int right)
{
    if (left > right)
        return -1;
    int mid = (left + right) >> 1;
    int leftAnswer = getAnswer(nums, left, mid - 1);
    if (leftAnswer != -1)
        return leftAnswer;
    else if (nums[mid] == mid)
        return mid;
    else
        return getAnswer(nums, mid + 1, right);
}
int findMagicIndex(vector<int>& nums)
{
    return getAnswer(nums, 0, nums.size() - 1);
}