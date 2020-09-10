/*
 * @Descripttion: 40. 组合总和 II
        给定一个数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。
        candidates 中的每个数字在每个组合中只能使用一次。
 * @version: 
 * @Author: Ye Yating
 * @Date: 2020-09-10 08:40:13
 * @LastEditors: Ye Yating
 * @LastEditTime: 2020-09-10 09:18:33
 */
#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

class Solution {
    vector<vector<int>> res;
    vector<int> candidates;
    vector<int> path;

public:
    // 执行用时：8 ms, 在所有 C++ 提交中击败了78.09% 的用户
    // 内存消耗：7.1 MB, 在所有 C++ 提交中击败了92.97% 的用户
    void func(int start, int target)
    {
        if (!target) {
            res.push_back(path);
            return;
        } else if (target < 0)
            return;
        int n = candidates.size();
        for (int i = start; i < n && candidates[i] <= target; i++) {
            if (i != start && candidates[i] == candidates[i - 1])
                continue;
            path.push_back(candidates[i]);
            func(i + 1, target - candidates[i]);
            path.pop_back();
        }
        return;
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        this->candidates = candidates;
        func(0, target);
        return res;
    }
};
int main()
{
    vector<int> nums = { 10, 1, 2, 7, 6, 1, 5 };
    Solution s;
    vector<vector<int>> res = s.combinationSum2(nums, 8);
    for (auto arr : res) {
        for (int a : arr)
            std::cout << a << " ";
        std::cout << std::endl;
    }
}