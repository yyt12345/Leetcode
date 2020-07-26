/*
 * @Descripttion: 剑指 Offer 11. 旋转数组的最小数字
        把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。输入一个递增排序的数组的
        一个旋转，输出旋转数组的最小元素。例如，数组 [3,4,5,1,2] 为 [1,2,3,4,5] 的一个旋转，该数组的最小值为1。  
 * @version: 
 * @Author: Ye Yating
 * @Date: 2020-07-22 10:15:26
 * @LastEditors: Ye Yating
 * @LastEditTime: 2020-07-22 15:31:51
 */ 
#include <vector>
#include <iostream>
using namespace std;
// 执行用时：12 ms, 在所有 C++ 提交中击败了67.19% 的用户
// 内存消耗：12.3 MB, 在所有 C++ 提交中击败了100.00% 的用户
int minArray2(vector<int>& numbers) {
    int len=numbers.size();
    if(len==0) return 0;
    for(int i=1;i<len;i++){
        if(numbers[i]-numbers[i-1]<0)
            return numbers[i];
    }
    return numbers[0];
}
// 执行用时：8 ms, 在所有 C++ 提交中击败了94.13% 的用户
// 内存消耗：12 MB, 在所有 C++ 提交中击败了100.00% 的用户
//二分法不一定要用递归！！

// 思考： 是否可以用 numbers[mid] 和 numbers[i] 比较做代替？
// 解析： 不可以。因为做比较的目的是判断 mmm 在哪个排序数组中。但在 numbers[m] > numbers[i]情况下，无法判断 mmm 在哪个排序数组中。本质是因为 jjj 初始值肯定在右排序数组中； iii 初始值无法确定在哪个排序数组中。
// 示例： 当 i=0,j=4,m=2i = 0, j = 4, m = 2i=0,j=4,m=2 时，有 numbers[m] > numbers[i] ，以下两示例得出不同结果。
// numbers=[1,2,3,4,5]numbers = [1, 2, 3, 4 ,5]numbers=[1,2,3,4,5] 旋转点 x=0x = 0x=0 ： mmm 在右排序数组（此示例只有右排序数组）；
// numbers=[3,4,5,1,2]numbers = [3, 4, 5, 1 ,2]numbers=[3,4,5,1,2] 旋转点 x=3x = 3x=3 ： mmm 在左排序数组。

int minArray3(vector<int>& numbers) {
    int i=0,j=numbers.size()-1;
    while(i<j){
        int mid=i+(j-i)/2;          //防止溢出
        if(numbers[mid]<numbers[j])
            j=mid;
        else if(numbers[mid]>numbers[j])
            i=mid+1;
        else
            j--;
    }
    return numbers[i];
    
}

int main(){
    vector<int> nums={3,1,3,3,3};
    cout << minArray(nums) << endl;
}