/*
 * @Descripttion: 152. 乘积最大子数组
        给你一个整数数组 nums ，请你找出数组中乘积最大的连续子数组（该子数组中至少包含一个数字），并返回该子数组所对应的乘积。
 * @version: 
 * @Author: Ye Yating
 * @Date: 2020-06-09 21:51:38
 * @LastEditors: Ye Yating
 * @LastEditTime: 2020-06-18 22:54:02
 */ 
#include <vector>
#include <iostream>
#include <string.h>
using namespace std;
//哦，又超出时间限制
int maxProduct(vector<int>& nums) {
    int len=nums.size();
    vector<vector<int> > dp(len);
    for(int i=0;i<dp.size();i++)
        dp[i].resize(len);
    for(int i=0;i<len;i++){
        dp[i][i]=nums[i];
        for(int j=i+1;j<len;j++){
            dp[j][i]=dp[j-1][i]*nums[j];
        }
    }
    int res=nums[0];
    for(auto rows:dp){
        for(int a:rows)
            res=max(res,a);
    }
    return res;
}
//  12 ms   37.05%  11.9 MB 6.25%
int maxProduct2(vector<int>& nums) {
    int len=nums.size();
    if(len==0) return 0;
    vector<int> imax(len),imin(len);
    imax[0]=nums[0];
    imin[0]=nums[0];
    for(int i=1;i<len;i++){
        if(nums[i]>=0) {
            imax[i]=max(imax[i-1]*nums[i],nums[i]);
            imin[i]=min(imin[i-1]*nums[i],nums[i]);
        }else{
            imax[i]=max(imin[i-1]*nums[i],nums[i]);
            imin[i]=min(imax[i-1]*nums[i],nums[i]);
        }
    }
    int maxN=INT16_MIN;
    for(int a:imax){
        maxN=max(a,maxN);
    }
    return maxN;
}
//  8 ms    75.32%      11.6 MB 6.25%
int maxProduct3(vector<int>& nums){
    int len=nums.size();
    if(len==0) return 0;
    int pMax=nums[0],pMin=nums[0];
    int res=nums[0];
    for(int i=1;i<len;i++){
        if(nums[i]<0) swap(pMax,pMin);
        pMax=max(pMax*nums[i],nums[i]);
        pMin=min(pMin*nums[i],nums[i]);
        res=max(res,pMax);
    }
    return res;
}
int main(){
    vector<int> nums={1,2,-1,-2,2,1,-2,1};
    cout << maxProduct3(nums) << endl;
}