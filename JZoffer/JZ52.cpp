/*** 
 * @Author: whh
 * @Date: 2020-12-26 12:39:22
 * @LastEditTime: 2020-12-29 13:50:33
 * @LastEditors: whh
 * @Description: 请实现一个函数用来匹配包括'.'和'*'的正则表达式。模式中的字符'.'表示任意一个字符，而'*'表示它前面的字符可以出现任意次（包含0次）。 
 * 在本题中，匹配是指字符串的所有字符匹配整个模式。例如，字符串"aaa"与模式"a.a"和"ab*ac*a"匹配，但是与"aa.a"和"ab*a"均不匹配
 * @FilePath: /Leetcode/JZ52.cpp
 */
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;
class Solution {
public:
    /*** 
     * @description: 动态规划
     */
    bool match(char* str, char* pattern)
    {
        int n = strlen(str), m = strlen(pattern);
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
        dp[0][0] = true;
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                if (!j)
                    dp[i][j] = (i == 0);
                else {
                    if (pattern[j - 1] == '*') {
                        if (j >= 2)
                            dp[i][j] = dp[i][j - 2] | dp[i][j];
                        if (i >= 1 && j >= 2 && (pattern[j - 2] == str[i - 1] || pattern[j - 2] == '.'))
                            dp[i][j] = dp[i - 1][j] | dp[i][j];

                    } else {
                        if (i > 0 && (str[i - 1] == pattern[j - 1] || pattern[j - 1] == '.'))
                            dp[i][j] = dp[i - 1][j - 1];
                    }
                }
            }
        }
        return dp[n][m];
    }
};