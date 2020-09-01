/*
 * @Descripttion: 93. 复原IP地址
    给定一个只包含数字的字符串，复原它并返回所有可能的 IP 地址格式。
    有效的 IP 地址 正好由四个整数（每个整数位于 0 到 255 之间组成，且不能含有前导 0），整数之间用 '.' 分隔。
    例如："0.1.2.201" 和 "192.168.1.1" 是 有效的 IP 地址，但是 "0.011.255.245"、"192.168.1.312" 和 "192.168@1.1" 是 无效的 IP 地址。
 * @version: 
 * @Author: Ye Yating
 * @Date: 2020-09-01 09:24:02
 * @LastEditors: Ye Yating
 * @LastEditTime: 2020-09-01 10:47:07
 */
#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution {
    vector<string> res;
    vector<int> path;

public:
    // 执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
    // 内存消耗：6.8 MB, 在所有 C++ 提交中击败了56.80% 的用户
    void dfs(const string& s, int start, int level)
    {
        int n = s.size();
        if (level == 4 && start == n) {
            string t;
            for (int num : path) {
                t += std::to_string(num);
                t.push_back('.');
            }
            t.pop_back();
            res.push_back(t);
            return;
        } else if (n - start > (4 - level) * 3)
            return;
        for (int i = 1; i < 4 && start + i - 1 < n; i++) {
            string tmp = s.substr(start, i);
            if (i != 1 && s[start] == '0')
                continue;
            int num = atoi(tmp.c_str());
            if (num > 255)
                continue;
            path.push_back(num);
            dfs(s, start + i, level + 1);
            path.pop_back();
        }
        return;
    }
    vector<string> restoreIpAddresses(string s)
    {
        dfs(s, 0, 0);
        return res;
    }
};
int main()
{
    Solution s;
    string str = "101023";
    vector<string> res = s.restoreIpAddresses(str);
    for (auto a : res)
        std::cout << a << std::endl;
}