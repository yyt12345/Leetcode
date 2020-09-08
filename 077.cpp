/*
 * @Descripttion: 77. 组合
        给定两个整数 n 和 k，返回 1 ... n 中所有可能的 k 个数的组合。
 * @version: 
 * @Author: Ye Yating
 * @Date: 2020-08-13 16:50:34
 * @LastEditors: Ye Yating
 * @LastEditTime: 2020-09-08 15:23:56
 */
#include <iostream>
#include <map>
#include <vector>
using std::map;
using std::vector;
class Solution {

    vector<vector<int>> res;
    vector<int> path;
    // 递归+剪枝 可以自己画树，判断剪枝条件
    // 执行用时：16 ms, 在所有 C++ 提交中击败了92.51% 的用户
    // 内存消耗：10.3 MB, 在所有 C++ 提交中击败了30.46% 的用户
    void func(int n, int k, int start)
    {
        if (path.size() == k) {
            res.push_back(path);
            return;
        }

        for (int i = start; i <= n - (k - path.size()) + 1; i++) {
            path.push_back(i);
            func(n, k, i + 1);
            path.pop_back();
        }
        return;
    }

public:
    vector<vector<int>> combine(int n, int k)
    {
        if (k == 0)
            return res;
        func(n, k, 1);
        return res;
    }
};
int main()
{
    Solution s;
    vector<vector<int>> res = s.combine(3, 3);
    for (auto row : res) {
        for (int a : row)
            std::cout << a << " ";
        std::cout << std::endl;
    }
}