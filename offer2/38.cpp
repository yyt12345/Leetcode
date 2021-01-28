/*
 * @Author: your name
 * @Date: 2021-01-28 22:11:11
 * @LastEditTime: 2021-01-28 22:46:14
 * @LastEditors: Please set LastEditors
 * @Description: 剑指 Offer 38. 字符串的排列
 * 输入一个字符串，打印出该字符串中字符的所有排列。
 * 你可以以任意顺序返回这个字符串数组，但里面不能有重复元素
 * @FilePath: /offer2/38.cpp
 */
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
class Solution {
    vector<string> res;
public:
    void dfs(int i,string s){
        if(i==s.size()) {
            res.push_back(s);
            return;
        }
        for(int j=i;j<s.size();j++){
            if(j>i && s[i]==s[j]) continue;
            swap(s[i],s[j]);
            dfs(i+1,s);
            swap(s[i],s[j]);
        }
        return;
    }
    vector<string> permutation(string s) {
        if(s.size()==0) return res;
        // sort(s.begin(),s.end());
        dfs(0,s);
        return res;
    }
};