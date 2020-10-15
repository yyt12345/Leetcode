/*
 * @Author: your name
 * @Date: 2020-10-15 09:15:58
 * @LastEditTime: 2020-10-15 09:41:41
 * @LastEditors: Please set LastEditors
 * @Description: 一只青蛙一次可以跳上1级台阶，也可以跳上2级。求该青蛙跳上一个n级的台阶总共有多少种跳法（先后次序不同算不同的结果）。
 * @FilePath: /undefined/home/whh/programming/Leetcode/JZ08.cpp
 */
//初步思考有：动态规划、递归两种方法
//跳n级台阶相当与n-1级台阶再跳一级和n-2级再跳2级
#include <vector>
using std::vector;
class Solution {
public:
//动态规划
    int jumpFloor(int number) {
        vector<int> dp(number+1,0);
        dp[0]=1;
        dp[1]=1;
        for(int i=2;i<=number;i++){
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[number];
    }
// 优化动态规划，只需要前两个数
    int jumpFloor(int number){
        if(number==1 || number==0) return 1;
        int pre1=1,pre2=1;
        for(int i=2;i<=number;i++){
            c=pre1+pre2;
            pre1=pre2;
            pre2=c;
        }
        return c;
    }

// 递归方法
    int jumpFloor(int number) {
        if(number==1 || number==0) return 1;
        return jumpFloor(number-1)+jumpFloor(number-2);
    }

};