/*
 * @Descripttion: 410. 分割数组的最大值
        给定一个非负整数数组和一个整数 m，你需要将这个数组分
        成 m 个非空的连续子数组。设计一个算法使得这 m 个子数组各自和的最大值最小。
        注意:
        数组长度 n 满足以下条件:
            1 ≤ n ≤ 1000
            1 ≤ m ≤ min(50, n)
 * @version: 
 * @Author: Ye Yating
 * @Date: 2020-07-25 09:53:05
 * @LastEditors: Ye Yating
 * @LastEditTime: 2020-07-25 11:06:02
 */ 
#include <vector>
#include <iostream>
using namespace std;
// 执行用时：460 ms, 在所有 C++ 提交中击败了5.16% 的用户
// 内存消耗：8.1 MB, 在所有 C++ 提交中击败了80.00% 的用户
int splitArray(vector<int>& nums,int m){
    int n=nums.size();
    vector<long long> sub(n+1,0);
    for(int i=1;i<=n;i++){
        sub[i]=sub[i-1]+nums[i-1];
    }
    vector<vector<long long> > dp(n+1,vector<long long>(m+1,__LONG_LONG_MAX__));
    dp[0][0]=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=min(i,m);j++){  
            for(int k=0;k<i;k++){
                dp[i][j]=min(dp[i][j], max(dp[k][j-1],sub[i]-sub[k]));
            }
        }
    }
    return dp[n][m];    
}
//二分查找法+贪心
// 执行用时：4 ms, 在所有 C++ 提交中击败了66.04% 的用户
// 内存消耗：7.2 MB, 在所有 C++ 提交中击败了100.00% 的用户
bool check(vector<int>& nums,int x,int m){
    long long sum=0;
    int cnt=1;
    int n=nums.size();
    for(int i=0;i<n;i++){
        sum+=nums[i];
        if(sum>x){
            cnt++;
            sum=nums[i];
        }
    }
    return cnt <= m;
}
int splitArray2(vector<int>& nums, int m) {
    int n=nums.size();
    long long l=0,h=0;
    for(int i=0;i<n;i++){
        l=max(l,(long long)nums[i]);
        h+=nums[i];
    }
    while(l<h){
        long long mid=(l+h) >>1;
        if(check(nums,mid,m))
            h=mid;
        else l=mid+1;
    }
    return l;
}
int main(){
    vector<int> nums={7,2,5,10,8};
    cout << splitArray2(nums,2) << endl;
}