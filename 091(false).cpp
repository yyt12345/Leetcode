/*
 * @Descripttion: 91. 解码方法
        一条包含字母 A-Z 的消息通过以下方式进行了编码：
        'A' -> 1
        'B' -> 2
        ...
        'Z' -> 26
        给定一个只包含数字的非空字符串，请计算解码方法的总数。
 * @version: 
 * @Author: Ye Yating
 * @Date: 2020-06-08 14:17:27
 * @LastEditors: Ye Yating
 * @LastEditTime: 2020-06-08 15:03:31
 */ 
#include <string>
#include <vector>
#include <iostream>
using namespace std;
int numDecodings(string s) {
    int sLen=s.size();
    int dp[sLen];
    if(s[0]=='0') return 0;
    dp[0]=1;
    for(int i=1;i<sLen;i++){
        if(s[i]=='0'){
            if(s[i-1]>'0' && s[i-1]<='2') dp[i]=dp[i-1];
            else return 0;
        }
        else if(s[i]<='6'&& s[i-1]>'0' && s[i-1]<='2') dp[i]=dp[i-2]+2;
        else    dp[i]=dp[i-1];
    }
    return dp[sLen-1];
}
int main(){
    cout << numDecodings("100");
}
