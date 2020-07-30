/*
 * @Descripttion: 343. 整数拆分
        给定一个正整数 n，将其拆分为至少两个正整数的和，并使这些整数的乘积最大化。 返回你可以获得的最大乘积。
 * @Author: Ye Yating
 * @Date: 2020-07-30 15:17:27
 * @LastEditors: Ye Yating
 * @LastEditTime: 2020-07-30 15:50:49
 */
#include <iostream>
#include <math.h>
#include <vector>
using namespace std;
//独立完成的动态规划解法
// 执行用时：4 ms, 在所有 C++ 提交中击败了31.28% 的用户
// 内存消耗：6.2 MB, 在所有 C++ 提交中击败了39.47% 的用户
int integerBreak(int n)
{

    vector<int> dp(n + 1, 0);
    dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        for (int k = 1; k < i; k++) {
            dp[i] = max(dp[i], max(dp[k] * (i - k), k * (i - k)));
            //将max(max(dp[i],dp[k]*(i-k)),k*(i-k))换成当前命令后内存消耗减小  为什么？？
        }
    }
    return dp[n];
}
//将问题建模，通过数学方法求出目标函数的极小值。求出当因子取3或者2时，乘积最大。且3优先级大于2
// 执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
// 内存消耗：6.1 MB, 在所有 C++ 提交中击败了76.32% 的用户
int integerBreak(int n)
{
    if (n <= 3)
        return n - 1;
    int a = n / 3, b = n % 3;
    if (b == 0)
        return pow(3, a);
    else if (b == 1)
        return pow(3, a - 1) * 4;
    return pow(3, a) * 2;
}
int main()
{
    cout << integerBreak(10) << endl;
}