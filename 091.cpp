/*
 * @Descripttion: 91. 解码方法
        一条包含字母 A-Z 的消息通过以下方式进行了编码：
        'A' -> 1
        'B' -> 2
        ...
        'Z' -> 26
        给定一个只包含数字的非空字符串，请计算解码方法的总数。
 * @version: 
 * @Author: Ye Yating
 * @Date: 2020-06-08 14:17:27
 * @LastEditors: Ye Yating
 * @LastEditTime: 2020-08-24 13:47:57
 */
#include <iostream>
#include <string>
#include <vector>
using namespace std;
// 改进的动态规划
// 执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
// 内存消耗：6.4 MB, 在所有 C++ 提交中击败了53.20% 的用户
int numDecodings(string s)
{
    if (s[0] == '0')
        return 0;
    int pre = 1, curr = 1; //dp[-1] = dp[0] = 1
    for (int i = 1; i < s.size(); i++) {
        int tmp = curr;
        if (s[i] == '0')
            if (s[i - 1] == '1' || s[i - 1] == '2')
                curr = pre;
            else
                return 0;
        else if (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] >= '1' && s[i] <= '6'))
            curr = curr + pre;
        pre = tmp;
    }
    return curr;
}
int main()
{
    cout << numDecodings("226");
}
