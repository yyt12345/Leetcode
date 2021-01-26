/*
 * @Author: your name
 * @Date: 2021-01-26 10:08:12
 * @LastEditTime: 2021-01-26 23:09:29
 * @LastEditors: Please set LastEditors
 * @Description: 剑指 Offer 14- I. 剪绳子
 * 给你一根长度为 n 的绳子，请把绳子剪成整数长度的 m 段（m、n都是整数，n>1并且m>1），每段绳子的长度
 * 记为 k[0],k[1]...k[m-1] 。请问 k[0]*k[1]*...*k[m-1] 可能的最大乘积是多少？例如，当绳子的长度是8时，
 * 我们把它剪成长度分别为2、3、3的三段，此时得到的最大乘积是18
 * @FilePath: /offer2/14.cpp
 */
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int cuttingRope(int n) {
        if(n<=1) return -1;
        vector<int> dp(n+1);
        dp[2]=1;
        dp[1]=1;
        for(int i=2;i<=n;i++){
            for(int j=1;j<=i/2;j++){
                dp[i]=max(dp[i],max((i-j)*j,j*dp[i-1]));
            }
        }
        return dp[n];
    }
    int cuttingRope(int n) {
        if(n<=3) return n-1;
        int res=1;
        if(n%3==1) res=pow(3,n/3-1)*4;
        else if(n%3)res=pow(3,n/3)*(n%3);
        else res=pow(3,n/3);
        return res;
    }
};
