/*
 * @Descripttion: 69. x 的平方根
        实现 int sqrt(int x) 函数。
        计算并返回 x 的平方根，其中 x 是非负整数。
        由于返回类型是整数，结果只保留整数的部分，小数部分将被舍去。
 * @version: 
 * @Author: Ye Yating
 * @Date: 2020-08-10 11:46:39
 * @LastEditors: Ye Yating
 * @LastEditTime: 2020-08-10 14:47:44
 */
#include <iostream>
using namespace std;
// 执行用时：20 ms, 在所有 C++ 提交中击败了12.90% 的用户
// 内存消耗：5.9 MB, 在所有 C++ 提交中击败了62.61% 的用户
int mySqrt(int x)
{
    if (x == 0)
        return 0;
    long long res = 0;
    while (res * res <= x) {
        res++;
    }
    return res - 1;
}
// 二分法
// 执行用时：4 ms, 在所有 C++ 提交中击败了59.23% 的用户
// 内存消耗：5.9 MB, 在所有 C++ 提交中击败了50.98% 的用户
int mySqrt2(int x)
{
    if (x == 0)
        return 0;
    int start = 0, end = x;
    int mid;
    int res;
    while (start <= end) {
        mid = (end - start) / 2 + start;
        if ((long long)mid * mid <= x) {
            res = mid;
            start = mid + 1;
        } else
            end = mid - 1;
    }
    return res;
}
int main()
{
    cout << mySqrt2(8) << endl;
}