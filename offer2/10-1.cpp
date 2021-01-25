/*
 * @Author: your name
 * @Date: 2021-01-25 23:32:27
 * @LastEditTime: 2021-01-25 23:51:28
 * @LastEditors: Please set LastEditors
 * @Description: 剑指 Offer 10- I. 斐波那契数列
 * 写一个函数，输入 n ，求斐波那契（Fibonacci）数列的第 n 项（即 F(N)）。斐波那契数列的定义如下：
 * 
 * F(0) = 0,   F(1) = 1
 * F(N) = F(N - 1) + F(N - 2), 其中 N > 1.
 * 斐波那契数列由 0 和 1 开始，之后的斐波那契数就是由之前的两数相加而得出。
 * 
 * 答案需要取模 1e9+7（1000000007），如计算初始结果为：1000000008，请返回 1。
 * 
 * 方法一：递归 (超出时间限制)
 * 方法二：动态规划的优化方法
 * @FilePath: /offer2/10-1.cpp
 */
class Solution {
public:
    int fib(int n) {
        if(n==0) return 0;
        else if(n==1) return 1;

        return fib(n-1)+fib(n-2);
    }
    int fib(int n) {
        if(n==0) return 0;
        else if(n==1) return 1;

        int a=0,b=1,i=2;
        while(i<=n){
            int tmp=(a+b)%1000000007;
            a=b;
            b=tmp;
            i++;
        }
        return b;
    }
};
