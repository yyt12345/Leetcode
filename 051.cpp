/*
 * @Descripttion: 51. N 皇后
        n 皇后问题研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。
        上图为 8 皇后问题的一种解法。
        给定一个整数 n，返回所有不同的 n 皇后问题的解决方案。
        每一种解法包含一个明确的 n 皇后问题的棋子放置方案，该方案中 'Q' 和 '.' 分别代表了皇后和空位。
 * @version: 
 * @Author: Ye Yating
 * @Date: 2020-09-03 10:05:12
 * @LastEditors: Ye Yating
 * @LastEditTime: 2020-09-03 10:23:33
 */
#include <iostream>
#include <string>
#include <vector>
using std::string;
using std::vector;
class Solution {
    vector<vector<string>> res;
    vector<int> Q;
    string map;

public:
    // 执行用时：12 ms, 在所有 C++ 提交中击败了63.83% 的用户
    // 内存消耗：8.9 MB, 在所有 C++ 提交中击败了21.70% 的用户
    //一共n行，目前在走i行
    void solve(int n, int i)
    {
        if (i == n) {
            //保存当前布局
            vector<string> answer;
            for (int j = 0; j < n; j++) {
                string tmp = map;
                tmp[Q[j]] = 'Q';
                answer.push_back(tmp);
            }
            res.push_back(answer);
        }
        vector<bool> ok(n, 0);
        for (int j = 0; j < i; j++) {
            int t = Q[j];
            ok[t] = 1;
            if (i - j + t < n)
                ok[i - j + t] = 1;
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
    vector<vector<string>> solveNQueens(int n)
    {
        if (n == 0)
            return res;
        Q = vector<int>(n, -1);
        for (int i = 0; i < n; i++)
            map.push_back('.');
        solve(n, 0);
        return res;
    }
};
int main()
{
    Solution s;
    vector<vector<string>> res = s.solveNQueens(4);
    for (auto ans : res) {
        for (string a : ans)
            std::cout << a << std::endl;
        std::cout << std::endl;
    }
}