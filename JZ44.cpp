/*** 
 * @Author: whh
 * @Date: 2020-12-21 22:08:01
 * @LastEditTime: 2020-12-24 10:57:29
 * @LastEditors: whh
 * @Description: 牛客最近来了一个新员工Fish，每天早晨总是会拿着一本英文杂志，写些句子在本子上。同事Cat对Fish写的内容颇感兴趣，有一天他向Fish借来翻看，但却读不懂它的意思。例如，“student. a am I”。后来才意识到，这家伙原来把句子单词的顺序翻转了，正确的句子应该是“I am a student.”。Cat对一一的翻转这些单词顺序可不在行，你能帮助他么
 * @FilePath: /Leetcode/JZ44.cpp
 */
#include <string>
using namespace std;
class Solution {
public:
    string ReverseSentence(string str)
    {
        if (str.empty())
            return str;
        int i = 0, sz = str.size();
        while (i < sz && str[i] == ' ')
            ++i;
        if (i == sz)
            return str;
        string ret = "";
        string tmp = "";
        bool hasstr = false;
        for (int i = sz - 1; i >= 0; --i) {
            // 合并一个单词
            if (str[i] != ' ') {
                tmp = str[i] + tmp;
                hasstr = true;
            }
            // 找到一个单词，将单词合并到结果串中
            else if (str[i] == ' ' && hasstr) {
                ret = ret + tmp + " ";
                tmp = "";
                hasstr = false;
            }
        }
        if (tmp != "")
            ret += tmp;
        return ret;
    }
};
