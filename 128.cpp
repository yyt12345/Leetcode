/*
 * @Descripttion: 128. 最长连续序列
        给定一个未排序的整数数组，找出最长连续序列的长度。
        要求算法的时间复杂度为 O(n)。
 * @version: 
 * @Author: Ye Yating
 * @Date: 2020-06-19 21:13:38
 * @LastEditors: Ye Yating
 * @LastEditTime: 2020-06-19 22:02:12
 */ 
#include<vector>
#include<iostream>
#include<map>
using namespace std;
//  20 ms   73.55%      10.8 MB     6.67%
int longestConsecutive(vector<int>& nums) {
    if(nums.size()==0) return 0;
    map<int,int> hash;
    int len=nums.size();
    for(int i=0;i<len;i++){
        hash[nums[i]]++;
    }
    int count=0,res=0,pre=hash.begin()->first;
    for(auto a:hash){
        if(a.first==pre+1) count++;
        else{
            res=max(count+1,res);
            count=0;
        }
        pre=a.first;
    }
    res=max(count+1,res);
    return res;
}
int main(){
    vector<int> nums={0,-1};
    cout << longestConsecutive(nums);
}