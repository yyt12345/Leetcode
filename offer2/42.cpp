/*
 * @Author: your name
 * @Date: 2021-01-28 23:32:44
 * @LastEditTime: 2021-01-29 00:00:44
 * @LastEditors: Please set LastEditors
 * @Description: 剑指 Offer 42. 连续子数组的最大和
 * 输入一个整型数组，数组中的一个或连续多个整数组成一个子数组。求所有子数组的和的最大值。
 * 要求时间复杂度为O(n)。
 * @FilePath: /offer2/42.cpp
 */
#include <vector>
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size()==0) return 0;
        int sum=0,maxN=-INT_MAX;
        for(int i=0;i<nums.size();i++){            
            sum+=nums[i];
            maxN=max(maxN,sum);
            if(sum<0) sum=0;
        }
        return maxN;
    }
};