/*
 * @Author: your name
 * @Date: 2021-01-26 22:40:55
 * @LastEditTime: 2021-01-26 23:03:00
 * @LastEditors: Please set LastEditors
 * @Description: 剑指 Offer 21. 调整数组顺序使奇数位于偶数前面
 * 输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有奇数位于数组的前半部分，所有偶数位于数组的后半部分
 * @FilePath: /offer2/21.cpp
 */
#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        if(nums.size()==0) return {};
        int n=nums.size();
        
        int j=0;
        while(j<n && nums[j]%2) j++;

        for(int i=j+1;i<n;i++){
            if(nums[i]%2) {
                swap(nums[j],nums[i]);
                j++;
            }

        }
        return nums;
    }
};
int main(){
    Solution s;
    vector<int> nums={1,2,3,4,5,6,7,8};
    s.exchange(nums);
    for(int n:nums)
        cout << n << " ";
    cout << endl;
}