/*
 * @Author: your name
 * @Date: 2021-01-24 23:25:28
 * @LastEditTime: 2021-01-25 00:05:00
 * @LastEditors: Please set LastEditors
 * @Description: 剑指 Offer 05. 替换空格
 * 请实现一个函数，把字符串 s 中的每个空格替换成"%20"。
 * 方法一：遍历，字符串拼接
 * 方法二：原地算法+双指针(倒序遍历)
 * @FilePath: /offer2/05.cpp
 */
#include <string>
using namespace std;
class Solution {
public:
    string replaceSpace(string s) {
        if(s.size()<0) return nullptr;
        string res;
        for(char ch:s){
            if(ch==' ') res+="%20";
            else res.push_back(ch);
        }
        return res;
    }
    string replaceSpace(string s) {
        if(s.size()<0) return nullptr;
        int count=0;
        for(char ch:s)
            if(ch==' ') count++;
        int i=s.size();
        s.resize(s.size()+count*2);
        int j=s.size()-1;
        for(;i>=0;i--){
            if(s[i]==' '){
                s[j--]='0';
                s[j--]='2';
                s[j--]='%';
            }else s[j--]=s[i];
        }
        return s;
    }
};
