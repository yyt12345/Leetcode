/*
 * @Descripttion: 88. 合并两个有序数组
        给你两个有序整数数组 nums1 和 nums2，请你将 nums2 合并到 nums1 中，使 nums1 成为一个有序数组。
 * @version:    4 ms    70.79%      9.2 MB  6.06%
 * @Author: Ye Yating
 * @Date: 2020-05-30 12:36:46
 * @LastEditors: Ye Yating
 * @LastEditTime: 2020-06-04 17:16:53
 */ 
#include <vector>
#include <iostream>
using namespace std;
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    if(nums2.size()==0) return;
    else if(nums1.size()==0){
        nums1=nums2;
        return;
    }
    int i=0,j=0;
    while(i<m && j<n){
        if(nums1[i]<=nums2[j]) 
            i++;
        else{
            nums1.insert(nums1.begin()+i,nums2[j++]);
            i++;
            m++;
        }
    }
    if(j!=n){
        nums1.insert(nums1.begin()+i,nums2.begin()+j,nums2.end());
    }
    nums1.resize(m+n-j);
}
int main(){
    vector<int> nums1={2,0};
    vector<int> nums2={1};
    int m=1,n=1;
    merge(nums1,m,nums2,n);
    for(auto a:nums1)
        cout << a << " ";
}
