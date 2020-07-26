/*
 * @Descripttion: 42. 接雨水
        给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。
 * @version: 
 * @Author: Ye Yating
 * @Date: 2020-05-18 15:33:47
 * @LastEditors: Ye Yating
 * @LastEditTime: 2020-05-20 15:05:29
 */ 
#include <vector>
#include <iostream>
using namespace std;
//时间复杂度O(n^2) 空间复杂度O(1)  848 ms  5.05%   6.8 MB  100.00%
int trap(vector<int>& height) {
    if(height.size()==0) return 0;
    int count=0;
    for(int i=1;i<height.size()-1;i++){
        int left_max=i-1,right_max=i+1;
        for(int j=left_max;j>=0;j--){
            if(height[left_max]<height[j]) left_max=j;
        }
        for(int j=right_max;j<height.size();j++)
            if(height[right_max]<height[j]) right_max=j;
        if(height[i]<min(height[right_max],height[left_max])){
            count+=min(height[right_max],height[left_max])-height[i];
        }
    }
    return count;
}
int trap2(vector<int>& height) {
    
}
int main(){
    vector<int> height={0,1,0,2,1,0,1,3,2,1,2,1};
    int res=trap2(height);
    cout << res << endl;
}
