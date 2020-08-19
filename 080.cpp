/*
 * @Descripttion: 80. 删除排序数组中的重复项 II
        给定一个排序数组，你需要在原地删除重复出现的元素，使得每个元素最多出现两次，返回移除后数组的新长度。
        不要使用额外的数组空间，你必须在原地修改输入数组并在使用 O(1) 额外空间的条件下完成。
 * @version: 
 * @Author: Ye Yating
 * @Date: 2020-08-18 10:34:10
 * @LastEditors: Ye Yating
 * @LastEditTime: 2020-08-18 11:16:51
 */
#include <iostream>
#include <vector>
using std::vector;
class Solution {
public:
    // 执行用时：8 ms, 在所有 C++ 提交中击败了95.92% 的用户
    // 内存消耗：6.6 MB, 在所有 C++ 提交中击败了36.44%
    int removeDuplicates(vector<int>& nums)
    {
        int l = nums.size();
        if (l < 2)
            return l;
        auto it1 = nums.begin();
        while ((it1 + 2) != nums.end()) {
            if (*it1 == *(it1 + 2))
                nums.erase(it1 + 2);
            else {
                it1++;
            }
        }
        return nums.size();
    }
    //     执行用时：8 ms, 在所有 C++ 提交中击败了95.92% 的用户
    // 内存消耗：6.5 MB, 在所有 C++ 提交中击败了58.00% 的用户
    int removeDuplicates2(vector<int>& nums)
    {
        int n = nums.size();
        if (n <= 2)
            return n;
        int i = 1;
        for (int j = 2; j < n; j++) {
            if (nums[j] != nums[i - 1]) {
                nums[++i] = nums[j];
            }
        }
        return i + 1;
    }
};
int main()
{
    Solution s;
    vector<int> nums = { 1, 1, 1, 2, 2, 3, 3, 3, 3, 5 };
    s.removeDuplicates(nums);
    for (int a : nums) {
        std::cout << a << " ";
    }
    std::cout << std::endl;
}