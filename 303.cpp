/*
 * @Descripttion: 303. 区域和检索 - 数组不可变
        给定一个整数数组  nums，求出数组从索引 i 到 j  (i ≤ j) 范围内元素的总和，包含 i,  j 两点。
 * @version: 
 * @Author: Ye Yating
 * @Date: 2020-06-05 11:13:14
 * @LastEditors: Ye Yating
 * @LastEditTime: 2020-06-05 11:41:55
 */ 
#include <vector>
#include <iostream>
using namespace std;
//递归  916 ms      5.06%       17.2 MB     52.94%
class NumArray {
private:
    vector<int> vec;
public:
    NumArray(vector<int>& nums) {
        vec=nums;
    }
    
    int sumRange(int i, int j) {
        if(i==j) return vec[i];
        return vec[i]+sumRange(i+1,j);
    }
};
//动态规划  40 ms   83.65%      16.5 MB     100.00%
class NumArray {
private:
    int* dp;
public:
    NumArray(vector<int>& nums) {
        dp=new int[nums.size()+1];
        dp[0]=0;
        for(int i=0;i<nums.size();i++)
            dp[i+1]=dp[i]+nums[i];
    }
    
    int sumRange(int i, int j) {
        return dp[j+1]-dp[i];
    }
};
int main(){
    vector<int> nums={-2, 0, 3, -5, 2, -1};
    NumArray a(nums);
    int res=a.sumRange(0,2);
    cout << res;
}