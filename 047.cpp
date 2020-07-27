/*
 * @Descripttion: 47. 全排列 II
        给定一个可包含重复数字的序列，返回所有不重复的全排列。
 * @version: 
 * @Author: Ye Yating
 * @Date: 2020-07-27 19:11:15
 * @LastEditors: Ye Yating
 * @LastEditTime: 2020-07-27 19:43:36
 */ 
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
vector<vector<int> > res;
// 执行用时：8 ms, 在所有 C++ 提交中击败了90.54% 的用户
// 内存消耗：8.1 MB, 在所有 C++ 提交中击败了100.00% 的用户
void func(vector<int>& nums,int start,int end){
    if(start==end)
        res.push_back(nums);
    else{
        for(int i=start;i<=end;i++){
            // if(i>start && nums[i]==nums[i-1]) continue;
            bool flag=true;
            for(int j=start;j<i;j++){
                if(nums[j]==nums[i]) flag=false;
            }
            if(flag){
                swap(nums[i],nums[start]);
                func(nums,start+1,end);
                swap(nums[i],nums[start]);
            }
        }
    }
    return ;
}
vector<vector<int>> permuteUnique(vector<int>& nums) {
    int n=nums.size();
    if(n==0) return {};
    sort(nums.begin(),nums.end());
    func(nums,0,n-1);
    return res;
}
int main(){
    vector<int> nums={0,1,0,0,9};
    vector<vector<int> > result=permuteUnique(nums);
    for(auto num:result){
        for(int a:num){
            cout << a << " ";
        }
        cout << endl;
    }
}