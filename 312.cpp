/*
 * @Descripttion: 312. 戳气球
 * 有 n 个气球，编号为0 到 n-1，每个气球上都标有一个数字，这些数字存在数组 nums 中。
    现在要求你戳破所有的气球。如果你戳破气球 i ，就可以获得 nums[left] * nums[i] * nums[right] 个硬币。 这里的
    left 和 right 代表和 i 相邻的两个气球的序号。注意当你戳破了气球 i 后，气球 left 和气球 right 就变成了相邻的气球。
    求所能获得硬币的最大数量。

 * @version: 
 * @Author: Ye Yating
 * @Date: 2020-07-19 17:06:42
 * @LastEditors: Ye Yating
 * @LastEditTime: 2020-07-19 18:45:48
 */ 
#include <vector>
#include <iostream>
using namespace std;
//暴力 深度优先 超出时间限制
int maxCoin=INT16_MIN;
void sub(vector<int> nums, int preCoin){
    int len=nums.size();
    if(len==1){
        maxCoin=max(maxCoin,preCoin+nums[0]);
        return;
    }
    for(int i=0;i<len;i++){
        int coins;
        if(i==0) coins=preCoin+nums[0]*nums[1];
        else if(i==len-1) coins=preCoin+nums[len-1]*nums[len-2];
        else coins=preCoin+nums[i-1]*nums[i]*nums[i+1];
        int temp=nums[i];
        nums.erase(nums.begin()+i);
        sub(nums,coins);

        nums.insert(nums.begin()+i,temp);
    }
}
int maxCoins2(vector<int>& nums) {
    int coins=0;
    if(nums.size()==0) return 0;
    sub(nums,coins);
    return maxCoin;
}

//自底而上的动态规划
int maxCoins(vector<int>& nums){
    int n=nums.size();
    if(n==0) return 0;
    vector<vector<int>> dp(n+2,vector<int>(n+2));
    vector<int> val(n+2);
    val[0]=val[n+1]=1;
    for(int i=0;i<n;i++)
        val[i+1]=nums[i];
    for(int i=n-1;i>=0;i--){
        for(int j=i+2;j<n+2;j++){
            for(int k=i+1;k<j;k++){
                int temp=val[i]*val[k]*val[j];
                dp[i][j]=max(temp+dp[i][k]+dp[k][j],dp[i][j]);
            }
        }
    }
    return dp[0][n+1];
}

int main(){
    vector<int> nums={3,1,5,8};
    cout << maxCoins(nums) << endl;
}
