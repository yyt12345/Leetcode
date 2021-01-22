/*
 * @Author: your name
 * @Date: 2020-10-27 13:01:05
 * @LastEditTime: 2020-10-27 13:37:18
 * @LastEditors: Please set LastEditors
 * @Description: 把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。
输入一个非递减排序的数组的一个旋转，输出旋转数组的最小元素。
例如数组[3,4,5,1,2]为[1,2,3,4,5]的一个旋转，该数组的最小值为1。
NOTE：给出的所有元素都大于0，若数组大小为0，请返回0。
 * @FilePath: /undefined/home/whh/JZ06.cpp
 */
#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
// 暴力法
    int minNumberInRotateArray(vector<int> rotateArray) {
        int n=rotateArray.size();
        if(n==0) return 0;
        if(n==1) return 1;
        for(int i=1;i<n;i++){
            if(rotateArray[i]<rotateArray[i-1]) return rotateArray[i];
        }
        return rotateArray[0];
    }
// 二分法
    int minNumberInRotateArray2(vector<int> rotateArray) {
        int n=rotateArray.size();
        if(n==0) return 0;
        if(n==1) return 1;
        int start=0,end=n-1;
        while(start<=end){
            int mid=(start+end)>>1;
            if(rotateArray[start]<rotateArray[end]) return rotateArray[start];
            else{
                if(rotateArray[mid]>=rotateArray[start]) start=mid+1;
                else if(rotateArray[mid]<rotateArray[end]) end=mid;
                else end--;
            }
        }
        return rotateArray[end];
    }
};
int main(){
    Solution s;
    vector<int> nums={3,4,5,6,7,3,3,3};
    cout << s.minNumberInRotateArray2(nums) << endl;
}