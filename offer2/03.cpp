/*
 * @Author: your name
 * @Date: 2021-01-22 10:57:21
 * @LastEditTime: 2021-01-24 22:33:11
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /offer2/03.cpp
 */
/*
 * 剑指 Offer 03. 数组中重复的数字
 * 找出数组中重复的数字。
 * 在一个长度为 n 的数组 nums 里的所有数字都在 0～n-1 的范围内。数组中某些数字是重复的，但不知道有几个数字重复了，也不知道每个数字重复了几次。请找出数组中任意一个重复的数字
 * 方法一 ： hash
 * 方法二：排序
 * 方法三：原地置换算法
 */

#include <vector>
#include <map>
#include <iostream>
using namespace std;

class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        if(nums.size()==0) return -1;
        if(nums.size()==1) return nums[0];
        map<int,bool> hash;
        for(auto n:nums){
            if(hash.count(n)) return n;
            else hash[n]=true;
        }
        return -1;
    }
    //排序算法
    int findRepeatNumber(vector<int>& nums) {
        if(nums.size()==0) return -1;
        if(nums.size()==1) return nums[0];
        sort(nums.begin(),nums.end());
        for(int i=1;i<nums.size();i++)
            if(nums[i]==nums[i-1]) return nums[i];
        return -1;
    }
    //原地置换
    int findRepeatNumber(vector<int>& nums) {
        if(nums.size()==0) return -1;
        else if(nums.size()==1) return nums[0];
        for(int i=0;i<nums.size();i++){
            while(nums[i]!=i){
                if(nums[i]==nums[nums[i]]) return nums[i];
                swap(nums[i],nums[nums[i]]);
            }
        }
        return -1;
    }
};

int main(){
    vector<int> nums={2, 3, 1, 0, 2, 5, 3};
    Solution s;
    cout << s.findRepeatNumber(nums) << endl;
}

