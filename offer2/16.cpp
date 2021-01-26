/*
 * @Author: your name
 * @Date: 2021-01-26 18:44:12
 * @LastEditTime: 2021-01-26 19:25:53
 * @LastEditors: Please set LastEditors
 * @Description: 剑指 Offer 16. 数值的整数次方
 * 实现函数double Power(double base, int exponent)，求base的exponent次方。不得使用库函数，同时不需要考虑大数问题。
 * @FilePath: /offer2/16.cpp
 */
#include <iostream>
using namespace std;
class Solution {
public:
    double myPow(double x, int n) {
        if(x==0) return 0;
        else if(n==0) return 1;

        int xFlag=1;
        bool nFlag=true;
        long num=n;
        if(num<0) {
            num *= -1;
            x=(double)1/x;
        }

        double res=1;
        while(num>0){
            if(num%2) res *= x;
            x*=x;
            num /= 2;
        }
        return res;
    }
};
int main(){
    Solution s;
    cout << s.myPow(-2,-3) << endl;
}