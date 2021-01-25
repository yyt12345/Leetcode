/*
 * @Author: your name
 * @Date: 2021-01-24 22:33:53
 * @LastEditTime: 2021-01-24 23:23:11
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /offer2/04.cpp
 */
/**
 *  剑指 Offer 04. 二维数组中的查找
 * 在一个 n * m 的二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按
 * 照从上到下递增的顺序排序。请完成一个高效的函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
 * 方法一：n次的二分法
 * 方法二：优化方法
 */
#include <vector>
#include <iostream>
using namespace std;
class Solution {
    bool twoRearch(vector<int>& nums,int target){
        int start=0,end=nums.size()-1;
        while(start<=end){
            int mid=(start+end)>>1;
            if(nums[mid]==target) return true;
            else if(nums[mid]<target) start=mid+1;
            else if(nums[mid]>target) end=mid-1;
        }
        return false;
    }
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        if(n==0) return false;
        int m=matrix[0].size();
        if(m==0) return false;

        for(vector<int> row:matrix){
            //判断当前行最大值最小值——减枝
            if(row[0]>target || row[m-1]<target) continue;
            if(twoRearch(row,target)) return true;
        }
        return false;
    }
    bool findNumberIn2DArray2(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        if(n==0) return false;
        int m=matrix[0].size();
        if(m==0) return false;

        int i=n-1,j=0;
        while(i>=0 && j<m){
            int flag=matrix[i][j];
            if(flag>target) i--;
            else if(flag<target) j++;
            else return true;
        }
        return false;
    }
};

int main(){
    vector<vector<int>> matrix={
        {1,   4,  7, 11, 15},
        {2,   5,  8, 12, 19},
        {3,   6,  9, 16, 22},
        {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30}
    };
    Solution s;
    cout << s.findNumberIn2DArray2(matrix,5) << endl;
}