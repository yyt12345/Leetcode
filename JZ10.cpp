/*
 * @Author: your name
 * @Date: 2020-10-15 09:43:37
 * @LastEditTime: 2020-10-15 09:51:35
 * @LastEditors: Please set LastEditors
 * @Description: 矩阵覆盖
 *  我们可以用2*1的小矩形横着或者竖着去覆盖更大的矩形。请问用n个2*1的小矩形无重叠地覆盖一个2*n的大矩形，总共有多少种方法？
    比如n=3时，2*3的矩形块有3种覆盖方法： 
 * @FilePath: /undefined/home/whh/programming/Leetcode/JZ10.cpp
 */
//本题和JZ08.cpp完全相同，都是使用非波那契数列求解
class Solution {
public:
    int rectCover(int number) {
        if(number==0) return 0;
        if(number==1) return 1;
        if(number==2) return 2;
        return rectCover(number-1)+rectCover(number-2);
    }
    int rectCover(int number) {
        vector<int> dp(number+1,0);
        dp[1]=1;
        dp[2]=2;
        for(int i=3;i<=number;i++){
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[number];
    }
};