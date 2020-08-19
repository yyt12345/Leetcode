/*
 * @Descripttion: 81. 搜索旋转排序数组 II
        假设按照升序排序的数组在预先未知的某个点上进行了旋转。
        ( 例如，数组 [0,0,1,2,2,5,6] 可能变为 [2,5,6,0,0,1,2] )。
        编写一个函数来判断给定的目标值是否存在于数组中。若存在返回 true，否则返回 false。
 * @version: 
 * @Author: Ye Yating
 * @Date: 2020-08-19 11:57:38
 * @LastEditors: Ye Yating
 * @LastEditTime: 2020-08-19 14:03:14
 */
#include <iostream>
#include <vector>
using std::vector;
class Solution {
public:
    // 执行用时：8 ms, 在所有 C++ 提交中击败了45.10% 的用户
    // 内存消耗：6.7 MB, 在所有 C++ 提交中击败了19.59% 的用户
    bool binarySearch(const vector<int>& nums, int start, int end, const int& target)
    {
        while (start < end) {
            int mid = (start + end) >> 1;
            if (nums[mid] == target)
                return true;
            else if (nums[mid] < target)
                start = mid + 1;
            else
                end = mid - 1;
        }
        return nums[start] == target;
    }
    bool search(vector<int>& nums, int target)
    {
        int n = nums.size();
        if (n == 0)
            return false;
        int change = 0;
        for (int i = 1; i < n; i++) {
            if (nums[i] < nums[i - 1]) {
                change = i;
                break;
            }
        }
        if (change == 0)
            return binarySearch(nums, 0, n - 1, target);
        else {
            if (nums[0] == target)
                return true;
            else if (nums[0] > target)
                return binarySearch(nums, change, n - 1, target);
            else
                return binarySearch(nums, 0, change - 1, target);
        }
    }
    bool search2(vector<int>& nums, int target)
    {
        if (nums.size() == 0)
            return false;
        int start = 0, end = nums.size() - 1;
        while (start < end) {
            int mid = (start + end) >> 1;
            if (nums[mid] == target)
                return true;
            if (nums[mid] == nums[start]) {
                start++;
                continue;
            }
            //前半部分有序
            if (nums[start] < nums[mid]) {
                if (nums[mid] > target && nums[start] <= target)
                    end = mid - 1;
                else
                    start = mid + 1;
            } else {
                if (nums[mid] < target && nums[end] >= target)
                    start = mid + 1;
                else
                    end = mid - 1;
            }
        }
        return false;
    }
};
int main()
{
    Solution s;
    vector<int> nums = { 2, 5, 6 };
    std::cout << s.search(nums, 3) << std::endl;
}