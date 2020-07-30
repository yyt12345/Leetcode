/*
 * @Descripttion: 59. 螺旋矩阵 II
    给定一个正整数 n，生成一个包含 1 到 n2 所有元素，且元素按顺时针顺序螺旋排列的正方形矩阵。
 * @Author: Ye Yating
 * @Date: 2020-07-30 16:44:06
 * @LastEditors: Ye Yating
 * @LastEditTime: 2020-07-30 16:53:55
 */
#include <iostream>
#include <vector>
using namespace std;
// 执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
// 内存消耗：6.8 MB, 在所有 C++ 提交中击败了16.28% 的用户
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