/*
 * @Descripttion: 46. 全排列
        给定一个 没有重复 数字的序列，返回其所有可能的全排列。
 * @version: 
 * @Author: Ye Yating
 * @Date: 2020-07-26 23:05:05
 * @LastEditors: Ye Yating
 * @LastEditTime: 2020-07-27 18:56:51
 */ 
#include <vector>
#include <iostream>
using namespace std;
vector<vector<int> > res;
//深度优先算法
// 执行用时：8 ms, 在所有 C++ 提交中击败了42.84% 的用户
// 内存消耗：8.1 MB, 在所有 C++ 提交中击败了100.00% 的用户
void dfs(vector<int>& nums,vector<int> path){
    int n=nums.size();
    if(n==0) {
        res.push_back(path);
        return;
    }
    for(int i=0;i<n;i++){
        int temp=nums[i];
        path.push_back(nums[i]);
        nums.erase(nums.begin()+i);
        dfs(nums,path);
        nums.insert(nums.begin()+i,temp);
        path.pop_back();

    }
    return ;
}

// 执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
// 内存消耗：7.4 MB, 在所有 C++ 提交中击败了100.00% 的用户
void func(vector<int>& nums,int start,int end){
    if(start==end){
        res.push_back(nums);
    }else{
        for(int i=start;i<=end;i++){
            swap(nums[i],nums[start]);
            func(nums,start+1,end);
            swap(nums[i],nums[start]);
        }
    }
}
vector<vector<int>> permute(vector<int>& nums) {
    // dfs(nums,{});
    int n=nums.size();
    if(n==0) return {};
    func(nums,0,nums.size()-1);
    return res;
}
int main(){
    vector<int> nums={1,2,3};
    vector<vector<int> > result=permute(nums);
    for(auto num:result){
        for(int a:num){
            cout << a << " ";
        }
        cout << endl;
    }
}