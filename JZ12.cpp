/*
 * @Author: your name
 * @Date: 2020-11-03 09:53:54
 * @LastEditTime: 2020-11-03 10:26:44
 * @LastEditors: Please set LastEditors
 * @Description: 给定一个double类型的浮点数base和int类型的整数exponent。求base的exponent次方。 
 * @FilePath: /undefined/home/whh/programming/Leetcode/JZ12.cpp
 */
#include <iostream>
using namespace std;
class Solution {
public:
// 递归 内存超出限制
    double sub(double base, int exponent){
        if(exponent==1) return base;
        return base*sub(base,exponent-1);
    }
    double Power1(double base, int exponent) {
        if(base==0) return 0;
        else if(exponent==0) return 1;
        else if(base==1) return 1;

        return sub(base,exponent);
    }

// 迭代法 超出时间限制
    double Power2(double base, int exponent) {
        if(base==0) return 0;
        else if(exponent==0) return 1;
        else if(base==1) return 1;

        double res=1;
        while(exponent--)
            res *= base;
        return res;
    }    

    double Power(double base, int exponent) {
        if(base==0) return 0;
        else if(exponent==0) return 1;
        else if(base==1) return 1;
        if(exponent<0){
            base = 1/base;
            exponent = -exponent;
        }

        double baseMul=base;
        double res=1;
        while(exponent){
            if(exponent & 1) res*=baseMul;
            exponent >>= 1;
            baseMul *= baseMul;
        }
        return res;
    }    
};
int main(){
    Solution s;
    cout << s.Power(2.1,10) << endl;
}