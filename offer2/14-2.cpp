/*
 * @Author: your name
 * @Date: 2021-01-26 10:43:39
 * @LastEditTime: 2021-01-26 18:34:19
 * @LastEditors: Please set LastEditors
 * @Description: 剑指 Offer 14- II. 剪绳子 II
 * 给你一根长度为 n 的绳子，请把绳子剪成整数长度的 m 段（m、n都是整数，n>1并且m>1），每段绳子的长度
 * 记为 k[0],k[1]...k[m-1] 。请问 k[0]*k[1]*...*k[m-1] 可能的最大乘积是多少？例如，当绳子的长度是8时，
 * 我们把它剪成长度分别为2、3、3的三段，此时得到的最大乘积是18
 * @FilePath: /offer2/14-2.cpp
 */
class Solution {
public:
    int cuttingRope(int n) {
        if(n<=2) return 1;
        int res;
        if(n%3==1) res=pow(3,n/3-1)*4;
        else res=pow(3,n/3)*(n%3);
        return res;
    }
    int cuttingRope(int n) {
        if(n <= 3) return n - 1;
        long res=1L;
        int p=(int)1e9+7;
        //贪心算法，优先切三，其次切二
        while(n>4){
            res=res*3%p;
            n-=3;
        }
        //出来循环只有三种情况，分别是n=2、3、4
        return (int)(res*n%p);
    }
};