/*
 * @Author: your name
 * @Date: 2020-11-02 20:35:46
 * @LastEditTime: 2020-11-02 20:40:40
 * @LastEditors: Please set LastEditors
 * @Description: 大家都知道斐波那契数列，现在要求输入一个整数n，请你输出斐波那契数列的第n项（从0开始，第0项为0，第1项是1）。
        n<=39 
 * @FilePath: /undefined/home/whh/programming/Leetcode/JZ07.cpp
 */
#include <iostream>
class Solution {
public:
    int Fibonacci(int n) {
        if(n<=0) return 0;
        if(n<=2) return 1;
        int a=1,b=1;
        int c=0;
        n--;
        while(--n){
            c=a+b;
            a=b;
            b=c;
        }
        return c;
    }
};
int main(){
    Solution s;
    std::cout << s.Fibonacci(5) << std::endl;
}