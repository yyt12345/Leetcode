/*** 
 * @Author: whh
 * @Date: 2020-12-21 14:21:29
 * @LastEditTime: 2021-01-03 14:36:20
 * @LastEditors: whh
 * @Description: 输入一个正整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。例如输入数组{3，32，321}，则打印出这三个数字能排成的最小数字为321323。
 * @FilePath: /Leetcode/JZ32.cpp
 */
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
    vector<string> res;

public:
    string PrintMinNumber(vector<int> numbers)
    {
        if (numbers.size() == 0)
            return "";
        else if (numbers.size() == 1)
            return to_string(numbers[0]);

        vector<string> nums;
        for (int i : numbers)
            nums.push_back(to_string(i));
        sort(nums.begin(), nums.end(), sort_string);
        string res;
        for (string s : nums)
            res += s;
        return res;
    }
    static bool sort_string(const string& a, const string& b)
    {
        string tmp1 = a + b;
        string tmp2 = b + a;
        return tmp1 < tmp2;
    }
};