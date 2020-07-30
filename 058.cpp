/*
 * @Descripttion: 58. 最后一个单词的长度
        给定一个仅包含大小写字母和空格 ' ' 的字符串 s，返回其最后一个单词的长度。如果字符串从左向右滚动显示，那么最后一个单词就是最后出现的单词。
        如果不存在最后一个单词，请返回 0 。
        说明：一个单词是指仅由字母组成、不包含任何空格字符的 最大子字符串。
 * @Author: Ye Yating
 * @Date: 2020-07-30 16:08:28
 * @LastEditors: Ye Yating
 * @LastEditTime: 2020-07-30 16:42:30
 */
#include <string>
using namespace std;
//看似简单，实则有许多情况需要考虑  如“ ” “a  ” “ world"
// 执行用时：4 ms, 在所有 C++ 提交中击败了49.92% 的用户
// 内存消耗：6.5 MB, 在所有 C++ 提交中击败了72.12% 的用户
int lengthOfLastWord(string s)
{
    int n = s.size();
    if (n == 0)
        return 0;
    int start = -1, end = -1;
    if (isalpha(s[0]))
        start = 0;
    for (int i = 0; i < n - 1; i++) {
        if (s[i] == ' ' && isalpha(s[i + 1]))
            start = i;
        else if (isalpha(s[i]) && s[i + 1] == ' ')
            end = i;
    }
    if (isalpha(s[n - 1]))
        end = n - 1;
    return start == -1 ? 0 : end - start + 1;
}
//从后往前遍历
// 执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
// 内存消耗：6.6 MB, 在所有 C++ 提交中击败了57.69% 的用户
int lengthOfLastWord(string s)
{
    int count = 0;
    for (int i = s.size() - 1; i >= 0; i--) {
        if (s[i] == ' ') {
            if (count == 0)
                continue;
            break;
        }
        count++;
    }
    return count;
}