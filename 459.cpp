/*
 * @Descripttion: 459. 重复的子字符串
        给定一个非空的字符串，判断它是否可以由它的一个子串重复多次构成。给定的字符串只含有小写英文字母，并且长度不超过10000。
 * @version: 
 * @Author: Ye Yating
 * @Date: 2020-06-08 14:17:27
 * @LastEditors: Ye Yating
 * @LastEditTime: 2020-08-24 13:28:27
 */
#include <string>
using std::string;
class Solution {
public:
    // 执行用时：36 ms, 在所有 C++ 提交中击败了35.96% 的用户
    // 内存消耗：9.6 MB, 在所有 C++ 提交中击败了88.39% 的用户
    bool repeatedSubstringPattern(string s)
    {
        int n = s.size();
        for (int i = 1; i * 2 <= n; i++) {
            if (n % i == 0) {
                bool match = true;
                for (int j = i; j < n; j++) {
                    if (s[j] != s[j - i]) {
                        match = false;
                        break;
                    }
                }
                if (match)
                    return true;
            }
        }
        return false;
    }
};