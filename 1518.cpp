/*
 * @Descripttion: 1518. 换酒问题
        小区便利店正在促销，用 numExchange 个空酒瓶可以兑换一瓶新酒。你购入了 numBottles 瓶酒。
        如果喝掉了酒瓶中的酒，那么酒瓶就会变成空的。
        请你计算 最多 能喝到多少瓶酒。
 * @version: 
 * @Author: Ye Yating
 * @Date: 2020-07-25 11:09:27
 * @LastEditors: Ye Yating
 * @LastEditTime: 2020-07-25 11:19:42
 */ 
#include <vector>
#include <iostream>
using namespace std;
//暴力破解法
// 执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
// 内存消耗：5.8 MB, 在所有 C++ 提交中击败了100.00% 的用户
int numWaterBottles(int numBottles, int numExchange) {
    int res=numBottles;
    while(numBottles>=numExchange){
        res+= numBottles/numExchange;
        numBottles = numBottles/numExchange + numBottles%numExchange;
    }
    return res;
}
int main(){
    cout << numWaterBottles(15,4) << endl;
}