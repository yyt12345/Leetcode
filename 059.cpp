/*
 * @Descripttion: 
 * @Author: Ye Yating
 * @Date: 2020-07-30 16:44:06
 * @LastEditors: Ye Yating
 * @LastEditTime: 2020-07-30 16:50:48
 */
#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> generateMatrix(int n)
{
    vector<vector<int>> res(n, vector<int>(n));
    if (n == 1)
        return { vector<int>(1, 1) };
    int u = 0, d = n - 1, l = 0, r = n - 1;
    int count = 1;
    while (true) {
        for (int i = l; i <= r; ++i)
            res[u][i] = count++; //向右移动直到最右
        if (++u > d)
            break; //重新设定上边界，若上边界大于下边界，则遍历遍历完成，下同
        for (int i = u; i <= d; ++i)
            res[i][r] = count++; //向下
        if (--r < l)
            break; //重新设定有边界
        for (int i = r; i >= l; --i)
            res[d][i] = count++; //向左
        if (--d < u)
            break; //重新设定下边界
        for (int i = d; i >= u; --i)
            res[i][l] = count++; //向上
        if (++l > r)
            break; //重新设定左边界
    }
    return res;
}
int main()
{
    vector<vector<int>> res = generateMatrix(4);
    for (auto num : res) {
        for (int a : num)
            cout << a << " ";
        cout << endl;
    }
}