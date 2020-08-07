/*
 * @Descripttion: 67. 二进制求和
        给你两个二进制字符串，返回它们的和（用二进制表示）。
        输入为 非空 字符串且只包含数字 1 和 0。
 * @version: 
 * @Author: Ye Yating
 * @Date: 2020-08-06 12:18:42
 * @LastEditors: Ye Yating
 * @LastEditTime: 2020-08-07 12:09:15
 */
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
// 执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
// 内存消耗：6.6 MB, 在所有 C++ 提交中击败了50.62% 的用户
string addBinary(string a, string b)
{
    if (a.size() < b.size())
        swap(a, b);
    string res;
    char c1, c2;
    int up = 0;
    while (!b.empty()) {
        c1 = a.back();
        c2 = b.back();

        int result = (c1 - '0') + (c2 - '0') + up;
        up = result / 2;
        res.push_back(result % 2 + '0');

        a.pop_back();
        b.pop_back();
    }
    reverse(res.begin(), res.end());

    if (up) {
        if (a.empty())
            a.push_back(up + '0');
        else {
            for (int i = a.size() - 1; i >= 0; i--) {
                if (a[i] == '0') {
                    a[i] += 1;
                    break;
                } else
                    a[i] = '0';
                if (i == 0 && a[i] == '0')
                    a.insert(a.begin(), '1');
            }
        }
    }
    a.insert(a.end(), res.begin(), res.end());
    return a;
}
int main()
{
    std::cout << addBinary("1111", "1111") << std::endl;
}