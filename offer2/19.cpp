/*
 * @Author: your name
 * @Date: 2021-01-26 20:00:10
 * @LastEditTime: 2021-01-26 21:03:50
 * @LastEditors: Please set LastEditors
 * @Description: 剑指 Offer 19. 正则表达式匹配
 * 请实现一个函数用来匹配包含'. '和'*'的正则表达式。模式中的字符'.'表示任意一个字符，而'*'表示它前面的字符可以出现
 * 任意次（含0次）。在本题中，匹配是指字符串的所有字符匹配整个模式。例如，字符串"aaa"与模式"a.a"和"ab*ac*a"匹配，
 * 但与"aa.a"和"ab*a"均不匹配。
 * @FilePath: /offer2/19.cpp
 */
#include <vector>
#include <string>
#include <iostream>
using namespace std;
class Solution {
public:
    bool isMatch(string s, string p) {
        int m=s.size(),n=p.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,false));
        dp[0][0]=true;
        for(int j=2;j<=n;j++)
            dp[0][j]=dp[0][j-2] && p[j-1]=='*';
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if((s[i-1]==p[j-1] || p[j-1]=='.') && dp[i-1][j-1]) dp[i][j]=true;
                else if(p[j-1]=='*') dp[i][j]=dp[i][j-2] ||dp[i][j-1] || (dp[i-1][j] && (s[i-1]==p[j-2] || p[j-2]=='.'));
            }
        }
        return dp[m][n];
    }
};
int main(){
    Solution s;
    cout << s.isMatch("mississippi","mis*is*p*.") << endl;
}