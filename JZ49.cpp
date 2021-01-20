/*** 
 * @Author: whh
 * @Date: 2020-12-24 10:58:49
 * @LastEditTime: 2020-12-26 12:38:40
 * @LastEditors: whh
 * @Description: 将一个字符串转换成一个整数，要求不能使用字符串转换整数的库函数。 数值为0或者字符串不是一个合法的数值则返回0
 * @FilePath: /Leetcode/JZ49.cpp
 */
#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    int StrToInt(string str)
    {
        if (str.empty() || str.size() <= 0)
            return 0;
        int ans = 0;
        int i = 0, flag = 1;
        if (str[i] == '-') {
            flag = -1;
            i++;
        } else if (str[i] == '+')
            i++;

        for (; i < str.size(); i++) {
            int a = str[i] - '0';
            if (a < 0 || a > 9)
                return 0;
            ans = ans * 10 + a;
        }
        return ans * flag;
    }
};
int main()
{
    Solution s;
    cout << s.StrToInt("123456") << endl;
}