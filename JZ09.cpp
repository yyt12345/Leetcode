/*
 * @Author: your name
 * @Date: 2020-10-21 19:18:39
 * @LastEditTime: 2020-10-21 19:37:25
 * @LastEditors: Please set LastEditors
 * @Description: 一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。求该青蛙跳上一个n级的台阶总共有多少种跳法。
 * @FilePath: /undefined/home/whh/programming/Leetcode/JZ09.cpp
 */
#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    int jumpFloorII(int number) {
        if(number==0)   return 0;
        vector<int> dp(number+1,0);
        dp[0]=1;
        dp[1]=1;
        for(int i=2;i<=number;i++){
            for(int j=0;j<i;j++){
                dp[i]+=dp[j];
            }
        }
        return dp[number];
        
    }
// f(n)=2f(n-1)
    int jumpFloorII(int number) {
        if(number==0 || number==1) return 1;
        int a=1;
        for(int i=2;i<=number;i++){
            a=a<<1;
        }
        return a;
        
    }
    int jumpFloorII(int number) {
        if(number==0 || number==1) return 1;
        return pow(2,number-1);
    }
};
int main(){
    Solution s;
    cout << s.jumpFloorII(3) << endl;
}