/*** 
 * @Author: whh
 * @Date: 2020-12-21 21:24:12
 * @LastEditTime: 2020-12-21 21:40:59
 * @LastEditors: whh
 * @Description: 在一个字符串(0<=字符串长度<=10000，全部由字母组成)中找到第一个只出现一次的字符,并返回它的位置, 如果没有则返回 -1（需要区分大小写）.（从0开始计数）
 * @FilePath: /Leetcode/JZ34.cpp
 */
#include <map>
#include <string>
using namespace std;
class Solution {
public:
    /*** 
     * @description: 最简单的方法 哈希
     */
    int FirstNotRepeatingChar(string str)
    {
        map<char, int> hash;
        int n = str.size();
        for (auto c : str)
            hash[c]++;
        for (int i = 0; i < n; i++) {
            if (hash[str[i]] == 1)
                return i;
        }
        return -1;
    }
    int FirstNotRepeatingChar(string str)
    {
        int n = str.size();
        for (int i = 0; i <= n - 1; i++) {
            if (str.find(str[i]) == str.rfind(str[i]))
                return i; //从左右位置同时检索，相等则表示只出现一次，返回
        }
        return -1;
    }
};