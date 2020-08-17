/*
 * @Descripttion: 77. 组合
        给定两个整数 n 和 k，返回 1 ... n 中所有可能的 k 个数的组合。
 * @version: 
 * @Author: Ye Yating
 * @Date: 2020-08-13 16:50:34
 * @LastEditors: Ye Yating
 * @LastEditTime: 2020-08-13 19:00:27
 */
#include <iostream>
#include <map>
#include <vector>
using std::map;
using std::vector;
class Solution {

    vector<vector<int>> res;

    void func(vector<int> path, int n, int k)
    {
        if (k == 0) {
            res.push_back(path);
            return;
        }
        int start = path.empty() ? 1 : path.back() + 1;
        for (int i = start; i <= n; i++) {
            path.push_back(i);
            func(path, n, k - 1);
            path.pop_back();
        }
        return;
    }

public:
    // 执行用时：952 ms, 在所有 C++ 提交中击败了5.14% 的用户
    // 内存消耗：165.4 MB, 在所有 C++ 提交中击败了5.03% 的用户
    vector<vector<int>> combine(int n, int k)
    {
        if (n == 0 || k == 0)
            return res;
        func({}, n, k);
        return res;
    }
};
int main()
{
    Solution s;
    vector<vector<int>> res = s.combine(4, 2);
    for (auto row : res) {
        for (int a : row)
            std::cout << a << " ";
        std::cout << std::endl;
    }
}