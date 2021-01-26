/*
 * @Author: your name
 * @Date: 2021-01-26 18:35:47
 * @LastEditTime: 2021-01-26 18:59:02
 * @LastEditors: Please set LastEditors
 * @Description:剑指 Offer 15. 二进制中1的个数
 * 请实现一个函数，输入一个整数（以二进制串形式），输出该数二进制表示中 1 的个数。
 * 例如，把 9 表示成二进制是 1001，有 2 位是 1。因此，如果输入 9，则该函数输出 2。
 * @FilePath: /offer2/15.cpp
 */
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count=0;
        while(n>0){
            if(n%2) count++;
            n/=2;
        }
        return count;
    }
    int hammingWeight(uint32_t n) {
        int count=0;
        while(n>0){
            count += n&1;
            n >>= 1;
        }
        return count;
    }
};