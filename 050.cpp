/*
 * @Descripttion: 50. Pow(x, n)
        实现 pow(x, n) ，即计算 x 的 n 次幂函数。
 * @version: 
 * @Author: Ye Yating
 * @Date: 2020-07-27 22:57:50
 * @LastEditors: Ye Yating
 * @LastEditTime: 2020-07-31 09:42:18
 */
#include <iostream>
using namespace std;
// 执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
// 内存消耗：6 MB, 在所有 C++ 提交中击败了100.00% 的用户
double myPow(double x, int n)
{
    if (x == 0)
        return 0;
    if (n == 0)
        return 1;
    bool flag1 = false, flag2 = false;
    long t = n;
    if (x < 0) {
        flag1 = true;
        x = -x;
    }
    if (n < 0) {
        flag2 = true;
        t = abs(n);
    }
    double res = 1;
    while (t > 0) {

        long i = 1;
        double tmp = x;
        while (i <= t / 2) {
            tmp = tmp * tmp;
            i *= 2;
        }
        res *= tmp;
        t -= i;
    }
    if (flag1 && n % 2)
        res *= -1;
    if (flag2)
        res = 1 / res;
    return res;
}
int main()
{
    cout << myPow(2.1, 3) << endl;
}