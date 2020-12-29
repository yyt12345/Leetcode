/*** 
 * @Author: whh
 * @Date: 2020-12-29 20:40:49
 * @LastEditTime: 2020-12-29 21:55:34
 * @LastEditors: whh
 * @Description: 请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有字符的路径。路径可以从矩阵中的任意一个格子开始，每一步可以
 * 在矩阵中向左，向右，向上，向下移动一个格子。如果一条路径经过了矩阵中的某一个格子，则该路径不能再进入该格子。 
 * 矩阵中包含一条字符串"bcced"的路径，但是矩阵中不包含"abcb"路径，因为字符串的第一个字符b占据了矩阵中的第一行第二个格子之后，路径不能再次进入该格子
 * @FilePath: /Leetcode/JZ65.cpp
 */
#include <iostream>
#include <string.h>
using namespace std;
class Solution {
public:
    /*** 
     * @description: 深度优先算法
     * @param {int} rows
     * @param {int} cols
     */
    char *mat = 0, *s;
    int w = 0, h = 0;
    int str_len;

    bool dfs(int i, int j, int k)
    {
        if (i < 0 || i >= h || j < 0 || j >= w)
            return false;
        else if (s[k] != mat[i * w + j])
            return false;
        else if (k == strlen(s) - 1)
            return true;

        char ch = mat[i * w + j];
        mat[i * w + j] = '#';
        if (dfs(i + 1, j, k + 1))
            return true;
        if (dfs(i - 1, j, k + 1))
            return true;
        if (dfs(i, j + 1, k + 1))
            return true;
        if (dfs(i, j - 1, k + 1))
            return true;
        //还原
        mat[i * w + j] = ch;
        return false;
    }
    bool hasPath(char* matrix, int rows, int cols, char* str)
    {
        if (rows <= 0 || cols <= 0)
            return false;
        mat = matrix;
        s = str;
        w = cols;
        h = rows;
        str_len = strlen(str);

        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (dfs(i, j, 0))
                    return true;
            }
        }
        return false;
    }
};
int main()
{
    string matrix = "ABCESFCSADEE";
    char* str = "ABCDED";
    char* str1 = new char[strlen(str)];
    strcpy(str, str1);
    Solution s;
    cout << s.hasPath(matrix, 3, 4, str) << endl;
}