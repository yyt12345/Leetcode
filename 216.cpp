/*
 * @Descripttion: 216. 组合总和 III
        找出所有相加之和为 n 的 k 个数的组合。组合中只允许含有 1 - 9 的正整数，并且每种组合中不存在重复的数字。
        说明：
            所有数字都是正整数。
            解集不能包含重复的组合。 
 * @Author: Ye Yating
 * @Date: 2020-09-11 08:25:00
 * @LastEditors: Ye Yating
 * @LastditTime: 2020-09-11 08:25:17
 */
#include <iostream>
#include <vector>
using std::vector;
class Solution {
    vector<vector<int>> res;
    vector<int> path;
    // 执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
    // 内存消耗：6.5 MB, 在所有 C++ 提交中击败了63.45% 的用户
    void DFS(int k, int n, int start)
    {
        if (k == 0) {
            if (n == 0)
                res.push_back(path);
            return;
        }
        if (n < 0)
            return;
        //剪枝
        int min = 0, max = 0;
        for (int i = k; i > 0; i--) {
            min += i;
            max += start - i + 1;
        }
        if (n > max && n < min)
            return;

        for (int i = start; i > 0; i--) {
            path.push_back(i);
            DFS(k - 1, n - i, i - 1);
            path.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum3(int k, int n)
    {
        if (k <= 0 || k > 9)
            return res;
        DFS(k, n, 9);
        return res;
    }
};
int main()
{
    Solution s;
    vector<vector<int>> res = s.combinationSum3(3, 9);
    for (auto arr : res) {
        for (int a : arr)
            std::cout << a << " ";
        std::cout << std::endl;
    }
}