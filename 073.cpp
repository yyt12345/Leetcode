/*
 * @Descripttion: 73. 矩阵置零
        给定一个 m x n 的矩阵，如果一个元素为 0，则将其所在行和列的所有元素都设为 0。请使用原地算法。
 * @version: 
 * @Author: Ye Yating
 * @Date: 2020-08-10 11:46:39
 * @LastEditors: Ye Yating
 * @LastEditTime: 2020-08-13 11:21:05
 */
#include <iostream>
#include <vector>
using std::vector;
// 执行用时：56 ms, 在所有 C++ 提交中击败了6.26% 的用户
// 内存消耗：13.3 MB, 在所有 C++ 提交中击败了49.37% 的用户
void setZeroes(vector<vector<int>>& matrix)
{
    if (matrix.size() == 0)
        return;
    const int m = matrix.size();
    const int n = matrix[0].size();
    bool firstRow = false;
    bool firstCol = false;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            const int item = matrix[i][j];
            if (item == 0) {
                if (i == 0) {
                    firstRow = true;
                }
                if (j == 0) {
                    firstCol = true;
                }
                matrix[0][j] = 0;
                matrix[i][0] = 0;
            }
        }
    }

    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            const int item = matrix[i][j];
            if (matrix[0][j] == 0 || matrix[i][0] == 0) {
                matrix[i][j] = 0;
            }
        }
    }
    // 修改第一行和第一列
    if (firstRow) {
        for (int i = 0; i < n; i++) {
            matrix[0][i] = 0;
        }
    }

    if (firstCol) {
        for (int i = 0; i < m; i++) {
            matrix[i][0] = 0;
        }
    }
}

int main()
{
    vector<vector<int>> nums = {
        { 1, 1, 1 },
        { 0, 1, 2 }
    };
    setZeroes(nums);
    for (auto row : nums) {
        for (int a : row)
            std::cout << a << " ";
        std::cout << std::endl;
    }
}