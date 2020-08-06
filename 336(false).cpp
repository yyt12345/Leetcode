/*
 * @Descripttion: 336. 回文对
        给定一组唯一的单词， 找出所有不同 的索引对(i, j)，使得列表中的两个单词， words[i] + words[j] ，可拼接成回文串。
 * @Author: Ye Yating
 * @Date: 2020-08-06 09:33:42
 * @LastEditors: Ye Yating
 * @LastEditTime: 2020-08-06 11:02:13
 */
#include <iostream>
#include <vector>
using namespace std;
bool isPalindrome(string s)
{
    int n = s.size();
    if (n < 2)
        return true;
    int left = (n - 1) / 2, right = n / 2;
    while (left >= 0 && right < n) {
        if (s[left] == s[right]) {
            left--;
            right++;
        } else
            return false;
    }
    return true;
}
vector<vector<int>> palindromePairs(vector<string>& words)
{
    vector<vector<int>> res;
    int n = words.size();
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (i == j)
                continue;
            if (isPalindrome(words[i] + words[j]))
                res.push_back({ i, j });
            if (isPalindrome(words[j] + words[i]))
                res.push_back({ j, i });
        }
    }
    return res;
}
int main()
{
    vector<string> words = { "abcd", "dcba", "lls", "s", "sssll" };
    vector<vector<int>> res = palindromePairs(words);
    for (auto a : res) {
        cout << a[0] << " " << a[1] << endl;
    }
}