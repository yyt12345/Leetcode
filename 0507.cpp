/*
 * @Descripttion: 面试题 05.07. 配对交换
        配对交换。编写程序，交换某个整数的奇数位和偶数位，
        尽量使用较少的指令（也就是说，位0与位1交换，位2与位3交换，以此类推）。
 * @version: 
 * @Author: Ye Yating
 * @Date: 2020-06-19 21:00:49
 * @LastEditors: Ye Yating
 * @LastEditTime: 2020-06-19 21:13:12
 */ 
//  0 ms    100.00%     6 MB    100.00%
#include <iostream>
int exchangeBits(int num) {
    return ( (num&0x55555555) << 1) | ((num&0xaaaaaaaa) >> 1);
}
int main(){
    std::cout << exchangeBits(1);
}