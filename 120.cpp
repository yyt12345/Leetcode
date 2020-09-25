/*
 * @Descripttion: 120. 三角形最小路径和
        给定一个三角形，找出自顶向下的最小路径和。每一步只能移动到下一行中相邻的结点上。
        相邻的结点 在这里指的是 下标 与 上一层结点下标 相同或者等于 上一层结点下标 + 1 的两个结点。
 * @version: 
 * @Author: Ye Yating
 * @Date: 2020-06-09 18:24:14
 * @LastEditors: Ye Yating
 * @LastEditTime: 2020-06-09 19:07:36
 */ 
#include <vector>
#include <iostream>
using namespace std;
//  8 ms    84.17%      8.3 MB  100.00%
int minimumTotal(vector<vector<int>>& triangle) {
    if(triangle.size()==0) return 0;
    for(int i=1;i<triangle.size();i++){
        triangle[i][0]+=triangle[i-1][0];
        int tempLen=triangle[i].size();
        for(int j=1;j<tempLen-1;j++)
            triangle[i][j]+=min(triangle[i-1][j-1],triangle[i-1][j]);
        triangle[i][tempLen-1]+=triangle[i-1][tempLen-2];
    }
    int minP=INT16_MAX;
    for(int j=0;j<triangle[triangle.size()-1].size();j++)   minP=min(minP,triangle[triangle.size()-1][j]);
    return minP;
}
int main(){
    vector<vector<int> > triangle={
        {2},
        {3,4},
        {6,5,7},
        {4,1,8,3}
    };
    cout << minimumTotal(triangle);
}
