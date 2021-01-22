/*
 * @Author: your name
 * @Date: 2020-10-18 09:52:42
 * @LastEditTime: 2020-10-18 11:00:37
 * @LastEditors: Please set LastEditors
 * @Description: 连续子数组的最大和
 * @FilePath: /undefined/home/whh/JZ30.cpp
 */
// 对于本题，结果的头尾一定皆为正数
#include <vector>
using namespace std;
class Solution {
public:
// 暴力破解法
    int FindGreatestSumOfSubArray(vector<int> array) {
        int n=array.size();
        if(n==0) return 0;
        int maxN=-__INT_MAX__;
        for(int i=0;i<n;i++){
            int temp=array[i];
            int max2=array[i];
            for(int j=i+1;j<n;j++){
                temp+=array[j];
                max2=max(max2,temp);
            }
            maxN=max(max2,maxN);
        }
        return maxN;
    }
// 动态规划
// 状态定义：dp[i]表示以i结尾的连续子数组的最大和。所以最终要求dp[n-1]
    int FindGreatestSumOfSubArray(vector<int> array) {
        int n=array.size();
        if(n==0) return 0;
        vector<int> dp(n,0);
        dp[0]=array[0];
        int res=array[0];
        for(int i=1;i<n;i++){
            dp[i]=max(dp[i-1]+array[i],array[i]);
            res=max(dp[i],res);
        }
        return res;
    }
// 空间复杂度O(1)
    int FindGreatestSumOfSubArray(vector<int> array) {
        int n=array.size();
        if(n==0) return 0;
        int res=array[0];
        int temp=0;
        for(int k:array){
            if(temp+k<0)    temp=0;
            else temp+=k;

            res=max(res,temp);
        }   
        if(temp!=0) return res;
        return *max_element(array.begin(),array.end());
    }
};