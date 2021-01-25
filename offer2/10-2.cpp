/*
 * @Author: your name
 * @Date: 2021-01-25 23:44:12
 * @LastEditTime: 2021-01-25 23:50:26
 * @LastEditors: Please set LastEditors
 * @Description: 剑指 Offer 10- II. 青蛙跳台阶问题
 * 一只青蛙一次可以跳上1级台阶，也可以跳上2级台阶。求该青蛙跳上一个 n 级的台阶总共有多少种跳法。
 * 答案需要取模 1e9+7（1000000007），如计算初始结果为：1000000008，请返回 1。
 * 方法一：动态规划
 * @FilePath: /offer2/10-2.cpp
 */
#include <vector>
using namespace std;
class Solution {
public:
    int numWays(int n) {
        if(n<2) return 1;
        vector<int> dp(n+1);
        dp[0]=1;
        dp[1]=1;
        for(int i=2;i<=n;i++){
            dp[i]=(dp[i-1]+dp[i-2])%1000000007;
        }
        return dp[n];
    }
    int numWays(int n) {
        if(n<2) return 1;
        int a=1,b=1,i=2;
        while(i<=n){
            int tmp=(a+b)%1000000007;
            a=b;
            b=tmp;
        }
        return b;
    }   
};
