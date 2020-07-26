/*
 * @Descripttion: 53. 最大子序和
        给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
 * @version: 
 * @Author: Ye Yating
 * @Date: 2020-05-20 16:46:31
 * @LastEditors: Ye Yating
 * @LastEditTime: 2020-05-30 12:10:58
 */ 
#include <vector>
#include <iostream>
using namespace std;
int maxSubArray(vector<int>& nums) {

    int pre=0, maxans=nums[0];
    for(int i=0;i<nums.size();i++){
        pre=max(pre+nums[i],nums[i]);
        maxans=max(maxans,pre);
    }
    return maxans;
}
int main(){
    vector<int> nums={1,2};
    int res=maxSubArray(nums);
    cout << res << endl;
}
