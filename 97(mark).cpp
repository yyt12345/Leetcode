/*
 * @Descripttion: 97. 交错字符串
 *      给定三个字符串 s1, s2, s3, 验证 s3 是否是由 s1 和 s2 交错组成的。
 * @version: 
 * @Author: Ye Yating
 * @Date: 2020-07-19 18:51:15
 * @LastEditors: Ye Yating
 * @LastEditTime: 2020-07-20 14:09:11
 */ 
#include <string>
#include <vector>
#include <iostream>
using namespace std;
bool isInterleave(string s1, string s2, string s3) {
    int n1=s1.size();
    int n2=s2.size();
    int n3=s3.size();
    if(n1+n2 != n3) return false;


    vector<vector<bool> > dp(n1+1, vector<bool>(n2+1,false));
    dp[0][0]=true;
    for(int i=0;i<=n1;i++){
        for(int j=0;j<=n2;j++){
            bool flag1=false,flag2=false;
            if(i>0)
                dp[i][j] = dp[i][j] || (dp[i-1][j] && s1[i-1]==s3[i+j-1]);
            if(j>0)
                dp[i][j] = dp[i][j] || (dp[i][j-1] && s2[j-1]==s3[j+i-1]);
        }
    }
    return dp[n1][n2];

}
int main(){
    string s1="aabcc",s2="dbbca",s3="aadbbcbcac";
    cout << isInterleave(s1,s2,s3)<< endl;
}