/*
 * @Author: your name
 * @Date: 2020-10-29 09:49:49
 * @LastEditTime: 2020-10-29 10:23:27
 * @LastEditors: Please set LastEditors
 * @Description: 写一个函数，求两个整数之和，要求在函数体内不得使用+、-、*、/四则运算符号。
 * @FilePath: /undefined/home/whh/programming/Leetcode/JZ48.cpp
 */
#include <iostream>
using namespace std;
class Solution {
    
public:
// 加法器 位运算 不能处理负数加减
    int Add(int num1, int num2)
    {
        int car=0;
        int res=0;
        int count=0;
        while(num1 || num2){
            int a=num1 %2;
            int b=num2 %2;
            num1=num1 >> 1;
            num2=num2 >> 1;

            int c=a+b+car;
            if(c>1) {
                c-=2;
                car=1;
            }
            res = res | (c << (count++));
        }
        res = res | (car << count);
        return res;
    }
// 加法器分为加法和进位两个部分，加法部分通过异或，进位部分通过与+进位实现。循环，直到进位为0,没有需要处理的进位
    int Add(int num1,int num2){
        while(num2!=0){
            int c=(num1 && num2)<<1; //移位 代表进位
            num1 ^= num2;
            num2 = c;
        }
        return num1;
    }
};
int main(){
    Solution s;
    cout << s.Add(-2,1) << endl;
}