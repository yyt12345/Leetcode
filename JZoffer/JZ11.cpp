/*
 * @Author: your name
 * @Date: 2020-11-03 09:26:17
 * @LastEditTime: 2020-11-03 09:52:21
 * @LastEditors: Please set LastEditors
 * @Description: 输入一个整数，输出该数32位二进制表示中1的个数。其中负数用补码表示。
 * @FilePath: /undefined/home/whh/programming/Leetcode/JZ11.cpp
 */
#include <iostream>
using namespace std;
class Solution {
public:
// 复杂度太高
    int  NumberOf1(int n) {
        int count=0;
        if(n<0) {
            count=1;
            n *= -1;
        }
        while(n){
            count += n & 1;
            n=n>>1;
        }
        return count;
    }

    int  NumberOf1(int n) {
        int ans=0;
        while(n){
            ans++;
            n=n & (n-1);
        }
        return ans;
    }
};
int main(){
    Solution s;
    cout << s.NumberOf1(-3) << endl;
}