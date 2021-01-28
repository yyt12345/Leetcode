/*
 * @Author: your name
 * @Date: 2021-01-28 22:50:33
 * @LastEditTime: 2021-01-28 23:02:02
 * @LastEditors: Please set LastEditors
 * @Description: 剑指 Offer 39. 数组中出现次数超过一半的数字
 * 数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。
 * 你可以假设数组是非空的，并且给定的数组总是存在多数元素
 * @FilePath: /offer2/39.cpp
 */
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        return nums[nums.size()/2];
    }
    int majorityElement(vector<int>& nums) {
        int vote=0;
        int x;
        for(int i=0;i<nums.size();i++){
            if(!vote) x=nums[i];
            if(nums[i]==x) vote++;
            else vote--;
        }
        return x;
    }
};