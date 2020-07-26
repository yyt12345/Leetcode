/*
 * @Descripttion: 392. 判断子序列
        给定字符串 s 和 t ，判断 s 是否为 t 的子序列。
        你可以认为 s 和 t 中仅包含英文小写字母。字符串 t 可能会很长（长度 ~= 500,000），而 s 是个短字符串（长度 <=100）。
        字符串的一个子序列是原始字符串删除一些（也可以不删除）字符而不改变剩余字符相对位置形成的新字符串。（例如，"ace"是"abcde"的一个子序列，而"aec"不是）。
    后续挑战 :
        如果有大量输入的 S，称作S1, S2, ... , Sk 其中 k >= 10亿，你需要依次检查它们是否为 T 的子序列。在这种情况下，你会怎样改变代码？
 * @version: 
 * @Author: Ye Yating
 * @Date: 2020-06-05 11:42:15
 * @LastEditors: Ye Yating
 * @LastEditTime: 2020-06-08 14:16:17
 */ 
#include <string>
#include <iostream>
#include <string.h>
using namespace std;
//暴力法 双百
bool isSubsequence(string s, string t) {
    int i=0,j=0;
    while(i<s.size() && j<t.size()){
        if(s[i]==t[j]){
            i++;j++;
        }else
            j++;
    }
    if(i==s.size()) return true;
    else return false;
}
//动态规划  8 ms    83.46%  6.6 MB  100.00%
bool isSubsequence2(string s, string t) {
    int sLen=s.size(),tLen=t.size();
    if(sLen==0) return true;
    else if(tLen==0) return false;
    bool dp[sLen][tLen];
    memset(dp,0,sizeof(bool)*sLen*tLen);

    dp[0][0]= (s[0]==t[0]);
    for(int i=1;i<tLen;i++){
        if(s[0]==t[i]) dp[0][i]=true;
        else 
            dp[0][i]=dp[0][i-1];
    }
    for(int j=1;j<sLen;j++){
        for(int i=j;i<tLen;i++){
            if(s[j]==t[i]) dp[j][i]=dp[j-1][i-1];
            else 
                dp[j][i]=dp[j][i-1];
        }
    }
    return dp[sLen-1][tLen-1];
}
int main(){
    cout << isSubsequence2("aaaaaaa","bbaaaaa") << endl;
}