/*** 
 * @Date: 2020-11-25 10:43:54
 * @LastEditors: Ye Yating
 * @LastEditTime: 2020-11-25 10:55:52
 * @FilePath: /Leetcode/JZ54.cpp
 * @Reference: 请实现一个函数用来找出字符流中第一个只出现一次的字符。例如，当从字符流中只读出前两个字符"go"时，第一个只出现一次的字符是"g"。当从该字符流中读出前六个字符“google"时，第一个只出现一次的字符是"l"。
 */
#include <map>
#include <queue>
using namespace std;
class Solution {
    map<char, int> hash;
    queue<char> q;

public:
    //Insert one char from stringstream
    void Insert(char ch)
    {
        hash[ch]++;
        if (hash[ch] == 1)
            q.push(ch);
    }
    //return the first appearence once char in current stringstream
    char FirstAppearingOnce()
    {
        while (!q.empty()) {
            if (hash[q.front()] == 1)
                return q.front();
            else
                q.pop();
        }
        return '#';
    }
};
// input:google output:ggg#ll
int main()
{
}