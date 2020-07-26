/*
 * @Descripttion:167. 两数之和 II - 输入有序数组
        给定一个已按照升序排列 的有序数组，找到两个数使得它们相加之和等于目标数。
        函数应该返回这两个下标值 index1 和 index2，其中 index1 必须小于 index2。 
 * @version: 
 * @Author: Ye Yating
 * @Date: 2020-07-20 14:13:56
 * @LastEditors: Ye Yating
 * @LastEditTime: 2020-07-20 14:26:45
 */ 
#include <vector>
#include <iostream>
using namespace std;
//执行用时：12 ms, 在所有 C++ 提交中击败了59.80% 的用户
// 内存消耗：9.7 MB, 在所有 C++ 提交中击败了6.90% 的用户
vector<int> twoSum(vector<int>& numbers, int target) {
    int n=numbers.size();
    if(n==0) return {};

    int i=0,j=n-1;
    while(i<j){
        if(numbers[i]+numbers[j]>target)
            j--;
        else if(numbers[i]+numbers[j]<target)
            i++;
        else    return {i+1,j+1};
    }
    return {};
}
// 执行用时：8 ms, 在所有 C++ 提交中击败了93.04% 的用户
// 内存消耗：9.6 MB, 在所有 C++ 提交中击败了6.90% 的用户
vector<int> twoSum(vector<int>& numbers, int target) {

    int i=0,j=numbers.size()-1;
    while(i<j){
        if(numbers[i]+numbers[j]>target)
            j--;
        else if(numbers[i]+numbers[j]<target)
            i++;
        else    return {i+1,j+1};
    }
    return {};
}
int main(){
    vector<int> nums={2,7,11,15};
    vector<int> res=twoSum(nums,13);
    for(auto a:res)
        cout << a << endl;
}