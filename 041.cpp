/*
 * @Descripttion: 41. 缺失的第一个正数
        给你一个未排序的整数数组，请你找出其中没有出现的最小的正整数。
        你的算法的时间复杂度应为O(n)，并且只能使用常数级别的额外空间。
 * @version: 
 * @Author: Ye Yating
 * @Date: 2020-05-18 14:23:12
 * @LastEditors: Ye Yating
 * @LastEditTime: 2020-05-18 15:32:36
 */ 
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
//时间复杂度NlogN，不符合要求      4 ms    64.32%      6.7 MB  100.00%
int firstMissingPositive(vector<int>& nums) {
    if(nums.size()==0) return 1;
    sort(nums.begin(),nums.end());
    for(int i=0;i<nums.size();i++){
        if(nums[i]<=0) continue;
        else if(nums[i]>1) return 1;
        int j;
        for(j=i+1;j<nums.size();j++){
            if(nums[j]!=nums[j-1]+1) return nums[j-1]+1;
        }
        return nums[j-1]+1;
    }
}
//常数级的额外空间，原地操作  0 ms    100.00%     6.4 MB  100.00%
int firstMissingPositive2(vector<int>& nums) {
    for(int i=0;i<nums.size();i++){
        while(nums[i]!=i+1){
            if(nums[i]<=0||nums[i]>nums.size() || nums[i]==nums[nums[i]-1]) break;
            swap(nums[i],nums[nums[i]-1]);
        }        
    }
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] != (i + 1)) {
            return (i + 1);
        }
    }
    return nums.size()+1;
}
int main(){
    vector<int> nums={-1,1};
    int res=firstMissingPositive2(nums);
    cout << res << endl;
}
