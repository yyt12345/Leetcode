/*** 
 * @Author: whh
 * @Date: 2020-12-29 21:57:01
 * @LastEditTime: 2020-12-30 15:31:29
 * @LastEditors: whh
 * @Description: 地上有一个m行和n列的方格。一个机器人从坐标0,0的格子开始移动，每一次只能向左，右，上，下四个方向移动一格，但是不能进
 * 入行坐标和列坐标的数位之和大于k的格子。 例如，当k为18时，机器人能够进入方格（35,37），因为3+5+3+7 = 18。但是，它不能进入方格（35,38），
 * 因为3+5+3+8 = 19。请问该机器人能够达到多少个格子？
 * @FilePath: /Leetcode/JZ66.cpp
 */
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int count = 0;
    int w, h;
    int th;
    vector<bool> flag;
    bool isAllowed(int i, int j)
    {
        int res = 0;
        while (j > 0) {
            res += j % 10;
            j /= 10;
        }
        while (i > 0) {
            res += i % 10;
            i /= 10;
        }
        return res <= th;
    }
    void dfs(int i, int j)
    {
        if (i >= h || j >= w)
            return;
        else if (flag[i * w + j])
            return;

        if (isAllowed(i, j)) {
            flag[i * w + j] = true;
            count++;

            dfs(i, j + 1);
            dfs(i + 1, j);
        } else
            return;
    }
    int movingCount(int threshold, int rows, int cols)
    {
        th = threshold;
        w = cols;
        h = rows;
        flag = vector<bool>(w * h, false);
        dfs(0, 0);
        return count;
    }
};
int main()
{
    Solution s;
    cout << s.movingCount(5, 10, 10) << endl;
}
