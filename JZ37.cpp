/*
 * @Author: your name
 * @Date: 2020-11-05 09:49:00
 * @LastEditTime: 2020-11-05 10:01:30
 * @LastEditors: Please set LastEditors
 * @Description: 统计一个数字在升序数组中出现的次数。
 * @FilePath: /undefined/home/whh/programming/Leetcode/JZ37.cpp
 */
#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
// 二分法，找到最左侧的k
    int GetNumberOfK(vector<int> data ,int k) {
        if(data.size()==0) return 0;
        int start=0,end=data.size()-1;
        while(start<=end){
            int mid=(end+start)>>1;
            if(data[mid]>=k) end=mid-1;
            else if(data[mid]<k) start=mid+1;
        }
        if(data[start] != k) return 0;
        int i=start;
        while(data[i]==data[start]) i++;
        return i-start;
    }
};
int main(){
    vector<int> nums={1,3,3,3,3,3,4,5};
    Solution s;
    cout << s.GetNumberOfK(nums,2) << endl;
}