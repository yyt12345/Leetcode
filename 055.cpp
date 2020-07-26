/*
 * @Descripttion: 55. 跳跃游戏
        给定一个非负整数数组，你最初位于数组的第一个位置。
        数组中的每个元素代表你在该位置可以跳跃的最大长度。
        判断你是否能够到达最后一个位置。
 * @version: 
 * @Author: Ye Yating
 * @Date: 2020-07-25 11:35:35
 * @LastEditors: Ye Yating
 * @LastEditTime: 2020-07-25 12:07:46
 */ 
#include <vector>
#include <iostream>
using namespace std;
//动态规划
// 执行用时：36 ms, 在所有 C++ 提交中击败了8.15% 的用户
// 内存消耗：13.2 MB, 在所有 C++ 提交中击败了8.70% 的用户
bool canJump(vector<int>& nums) {
    int n=nums.size();
    if(n==1) return true;
    
    vector<bool> dp(n, false);
    dp[0]=true;
    for(int i=1;i<=n;i++){
        for(int k=1;k<=i;k++){
            dp[i] = dp[i] || (dp[i-k] && nums[i-k] >= k);
            if(dp[i]) break;
        }
    }
    return dp[n-1];
}
int main(){
    vector<int> nums={2,0,0};
    cout << canJump(nums) << endl;
}