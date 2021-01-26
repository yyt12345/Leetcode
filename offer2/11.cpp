/*
 * @Author: your name
 * @Date: 2021-01-25 23:51:45
 * @LastEditTime: 2021-01-26 00:35:09
 * @LastEditors: Please set LastEditors
 * @Description: 剑指 Offer 11. 旋转数组的最小数字
 * 把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。输入一个递增排序的数组的一个旋转，输出旋转数组的最小元素。
 * 例如，数组 [3,4,5,1,2] 为 [1,2,3,4,5] 的一个旋转，该数组的最小值为1。  
 * 方法一：遍历数组，下降沿
 * 方法二：
 * @FilePath: /offer2/11.cpp
 */
#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    //该方法思路是找一个下降沿
    int minArray(vector<int>& numbers) {
        int n=numbers.size();
        if(n==0) return -1;
        else if(n==1) return numbers[0];

        int start=0,end=n-1;
        while(end-start>1){
            int mid=(start+end)>>1;
            if(numbers[mid]>numbers[end]) start=mid;
            else if(numbers[mid]<numbers[end]) end=mid;
            else end--;
        }
        return (numbers[end]<numbers[0])?numbers[end]:numbers[0];
    }
    //找最小值 
    int minArray(vector<int>& numbers) {
        int n=numbers.size();
        if(n==0) return -1;
        else if(n==1) return numbers[0];

        int start=0,end=n-1;
        while(start<=end){
            int mid=(start+end)>>1;
            if(numbers[mid]>numbers[end]) start=mid+1;
            else if(numbers[mid]<numbers[end]) end=mid;
            else end--;
        }
        return numbers[end];
    }
};
int main(){
    vector<int> nums={2,2,2,0,1};
    Solution s;
    cout << s.minArray(nums) << endl;
}
