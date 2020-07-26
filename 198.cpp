/*
 * @Descripttion: 198. 打家劫舍
        你是一个专业的小偷，计划偷窃沿街的房屋。每间房内都藏有一定的现金，影响你偷窃的唯一制约因素就是相邻的房屋
    装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。
        给定一个代表每个房屋存放金额的非负整数数组，计算你 不触动警报装置的情况下 ，一夜之内能够偷窃到的最高金额。
 * @version: 
 * @Author: Ye Yating
 * @Date: 2020-06-04 18:22:43
 * @LastEditors: Ye Yating
 * @LastEditTime: 2020-06-04 18:44:31
 */ 
#include <vector>
#include <iostream>
using namespace std;
//  4 ms    48.40%      8 MB    100.00%
int rob(vector<int>& nums) {
    if(nums.size()==0) return 0;
    else if(nums.size()==1) return nums[0];
    else if(nums.size()==2) return max(nums[0],nums[1]);
    vector<int> dp(nums.size());
    dp[0]=nums[0];
    dp[1]=nums[1];
    dp[2]=nums[2]+dp[0];
    for(int i=3;i<nums.size();i++)
        dp[i]=max(dp[i-2],dp[i-3])+nums[i];
    return max(dp[nums.size()-1],dp[nums.size()-2]);
}
int rob2(vector<int> & nums){
    
}
int main(){
    vector<int> nums={2,7,9,3,3,6,4};
    cout << rob(nums) << endl;
}