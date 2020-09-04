/*
 * @Descripttion: 52. N皇后 II
        n 皇后问题研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。
 * @version: 
 * @Author: Ye Yating
 * @Date: 2020-09-04 08:48:42
 * @LastEditors: Ye Yating
 * @LastEditTime: 2020-09-04 09:31:02
 */
#include <iostream>
#include <vector>
using std::vector;
class Solution {
    vector<int> Q;
    int count = 0;

public:
    // 执行用时：12 ms, 在所有 C++ 提交中击败了25.62% 的用户
    // 内存消耗：6.5 MB, 在所有 C++ 提交中击败了25.02% 的用户
    void solve(int n, int i)
    {
        if (i == n) {
            count++;
            return;
        }
        vector<bool> ok(n, 0);
        for (int j = 0; j < i; j++) {
            int t = Q[j];
            ok[t] = 1;
            if (t + i - j < n)
                ok[t + i - j] = 1;
            if (t - i + j >= 0)
                ok[t - i + j] = 1;
        }
        for (int j = 0; j < n; j++) {
            if (ok[j])
                continue;
            Q[i] = j;
            solve(n, i + 1);
        }
    }
    int totalNQueens(int n)
    {
        Q = vector<int>(n);
        solve(n, 0);
        return count;
    }
};
int main()
{
    Solution s;
    std::cout << s.totalNQueens(4) << std::endl;
}