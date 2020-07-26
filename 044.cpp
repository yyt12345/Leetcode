/*
 * @Descripttion: 44. 通配符匹配
        给定一个字符串 (s) 和一个字符模式 (p) ，实现一个支持 '?' 和 '*' 的通配符匹配。
        '?' 可以匹配任何单个字符。
        '*' 可以匹配任意字符串（包括空字符串）。
        两个字符串完全匹配才算匹配成功。
 * @version: 
 * @Author: Ye Yating
 * @Date: 2020-07-24 11:20:02
 * @LastEditors: Ye Yating
 * @LastEditTime: 2020-07-24 11:37:04
 */ 
#include <vector>
#include <iostream>
using namespace std;
// 执行用时：240 ms, 在所有 C++ 提交中击败了44.10% 的用户
// 内存消耗：9.6 MB, 在所有 C++ 提交中击败了100.00% 的用户
bool isMatch(string s, string p) {
    int n1=s.size(),n2=p.size();
    
    vector<vector<bool> > dp(n2+1,vector<bool>(n1+1,false));
    dp[0][0]=true;
    for(int i=1;i<=n2;i++){
        if(p[i-1]=='*') dp[i][0]=dp[i-1][0];
        for(int j=1;j<=n1;j++){
            if(p[i-1]=='?') dp[i][j]=dp[i-1][j-1];
            else if(p[i-1]=='*') dp[i][j]=dp[i-1][j] || dp[i][j-1];
            else dp[i][j]= p[i-1]==s[j-1] && dp[i-1][j-1]==true;
        }
    }
    return dp[n2][n1];
}
int main(){
    string s="aab";
    string p="c*a*b";
    cout << isMatch(s,p) << endl;
}