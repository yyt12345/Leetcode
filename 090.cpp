/*
 * @Descripttion: 90. 子集 II
        给定一个可能包含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。
        说明：解集不能包含重复的子集。
 * @version: 
 * @Author: Ye Yating
 * @Date: 2020-08-21 22:41:11
 * @LastEditors: Ye Yating
 * @LastEditTime: 2020-08-21 23:32:49
 */
#include <algorithm>
#include <iostream>
#include <vector>
using std::vector;
class Solution {
    vector<vector<int>> res;
    vector<int> path;
    int l;

public:
    // 执行用时：4 ms, 在所有 C++ 提交中击败了79.45% 的用户
    // 内存消耗：7.5 MB, 在所有 C++ 提交中击败了41.69%
    bool func(const vector<int>& num, int start)
    {
        if (start == l)
            return true;
        for (int i = start; i < l; i++) {
            if (i != start && num[i] == num[i - 1])
                continue;
            path.push_back(num[i]);
            res.push_back(path);
            func(num, i + 1);
            path.pop_back();
        }
        return true;
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums)
    {
        l = nums.size();
        if (l == 0)
            return res;
        res.push_back({});
        std::sort(nums.begin(), nums.end());
        func(nums, 0);
        return res;
    }
};
int main()
{
    vector<int> nums = { 1, 2, 2 };
    Solution s;
    vector<vector<int>> res = s.subsetsWithDup(nums);
    for (auto row : res) {
        for (int a : row)
            std::cout << a << " ";
        std::cout << std::endl;
    }
}