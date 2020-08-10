/*
 * @Descripttion: 73. 矩阵置零
        给定一个 m x n 的矩阵，如果一个元素为 0，则将其所在行和列的所有元素都设为 0。请使用原地算法。
 * @version: 
 * @Author: Ye Yating
 * @Date: 2020-08-10 11:46:39
 * @LastEditors: Ye Yating
 * @LastEditTime: 2020-08-10 16:24:30
 */
#include <vector>
using std::vector;
void setZeroes(vector<vector<int>>& matrix)
{
    int m = matrix.size(), n = matrix[0].size();
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == 0) {
                for (int k = 0; k < m; k++)
                    matrix[k][j] = matrix[k][j] == 0 ? 0 : __INT_MAX__;
                for (int k = 0; k < n; k++)
                    matrix[i][k] = matrix[i][k] == 0 ? 0 : __INT_MAX__;
            }
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == __INT_MAX__)
                matrix[i][j] = 0;
        }
    }
    return;
}