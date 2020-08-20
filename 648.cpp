/*
 * @Descripttion: 647. 回文子串
        给定一个字符串，你的任务是计算这个字符串中有多少个回文子串。
        具有不同开始位置或结束位置的子串，即使是由相同的字符组成，也会被视作不同的子串
 * @version: 
 * @Author: Ye Yating
 * @Date: 2020-08-19 11:57:38
 * @LastEditors: Ye Yating
 * @LastEditTime: 2020-08-19 12:58:32
 */
#include <iostream>
#include <string>
#include <vector>
using std::string;
using std::vector;
class Solution {
public:
    // 执行用时：60 ms, 在所有 C++ 提交中击败了28.79% 的用户
    // 内存消耗：7.5 MB, 在所有 C++ 提交中击败了58.24% 的用户
    int countSubstrings(string s)
    {
        int n = s.size();
        if (n == 0)
            return 0;
        int count;
        vector<vector<bool>> dp(n, vector<bool>(n));
        for (int j = 0; j < n; j++) {
            for (int i = 0; i <= j; i++) {
                if (i == j) {
                    dp[i][j] = true;
                    count++;
                } else if (j == i + 1 && s[i] == s[j]) {
                    dp[i][j] = true;
                    count++;
                } else if (j > i + 1 && s[i] == s[j] && dp[i + 1][j - 1] == true) {
                    dp[i][j] = true;
                    count++;
                }
            }
        }
        return count;
    }
};
int main()
{
    string s1 = "abc";
    Solution s;
    std::cout << s.countSubstrings(s1) << std::endl;
}