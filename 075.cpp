/*
 * @Descripttion: 75. 颜色分类
        给定一个包含红色、白色和蓝色，一共 n 个元素的数组，原地对它们进行排序，使得相同颜色的元素相邻，并按照红色、白色、蓝色顺序排列。
        此题中，我们使用整数 0、 1 和 2 分别表示红色、白色和蓝色。
        注意:
        不能使用代码库中的排序函数来解决这道题。
        进阶：
            一个直观的解决方案是使用计数排序的两趟扫描算法。
            首先，迭代计算出0、1 和 2 元素的个数，然后按照0、1、2的排序，重写当前数组。
            你能想出一个仅使用常数空间的一趟扫描算法吗？
 * @version: 
 * @Author: Ye Yating
 * @Date: 2020-08-13 16:50:34
 * @LastEditors: Ye Yating
 * @LastEditTime: 2020-08-13 17:36:01
 */
#include <iostream>
#include <map>
#include <vector>
using std::map;
using std::vector;
class Solution {
public:
    // 使用了常数空间，但扫描两次
    // 执行用时：4 ms, 在所有 C++ 提交中击败了57.51% 的用户
    // 内存消耗：8.8 MB, 在所有 C++ 提交中击败了5.36% 的用户
    void sortColors(vector<int>& nums)
    {
        map<int, int> hash;
        for (int a : nums)
            hash[a]++;
        int i = 0;
        for (auto a : hash) {
            while (a.second--) {
                nums[i++] = a.first;
            }
        }
    }
    //  常数工作空间，一次扫描，时间复杂度n^2
    // 执行用时：8 ms, 在所有 C++ 提交中击败了5.36% 的用户
    // 内存消耗：8.4 MB, 在所有 C++ 提交中击败了42.27% 的用户
    void sortColors2(vector<int>& nums)
    {
        int n = nums.size();
        int i = 0;
        for (int k = 0; k < n; k++) {
            if (nums[k] == 0) {
                nums.erase(nums.begin() + k);
                nums.insert(nums.begin(), 0);
                i++;
            } else if (nums[k] == 1) {
                nums.erase(nums.begin() + k);
                nums.insert(nums.begin() + i, 1);
            }
        }
        return;
    }
    //双指针 交换
    // 执行用时：4 ms, 在所有 C++ 提交中击败了57.51% 的用户
    // 内存消耗：8.5 MB, 在所有 C++ 提交中击败了33.33% 的用户
    void sortColors3(vector<int>& nums)
    {
        int n = nums.size();
        if (n == 0)
            return;
        int i = 0, j = n - 1, k = 0;
        while (k <= j) {
            if (nums[k] == 2) {
                std::swap(nums[k], nums[j--]);
            } else if (nums[k] == 0) {
                std::swap(nums[k++], nums[i++]);
            } else
                k++;
        }
        return;
    }
};
int main()
{
    Solution s;
    vector<int> nums = { 2, 0, 2, 1, 1, 0 };
    s.sortColors2(nums);
    for (auto a : nums)
        std::cout << a << " ";
    std::cout << std::endl;
    return 0;
}