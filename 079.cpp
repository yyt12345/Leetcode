/*
 * @Descripttion: 79. 单词搜索
        给定一个二维网格和一个单词，找出该单词是否存在于网格中。
        单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。
 * @version: 
 * @Author: Ye Yating
 * @Date: 2020-08-08 10:35:41
 * @LastEditors: Ye Yating
 * @LastEditTime: 2020-08-17 13:11:40
 */
#include <iostream>
#include <string>
#include <vector>
using std::string;
using std::vector;
// 执行用时：28 ms, 在所有 C++ 提交中击败了79.69% 的用户
// 内存消耗：8.3 MB, 在所有 C++ 提交中击败了62.38% 的用户
class Solution {
    const int dx[4] = { 0, -1, 0, 1 };
    const int dy[4] = { -1, 0, 1, 0 };
    bool isfound = false;
    vector<vector<char>> visited;
    int m, n, l;

public:
    bool dfs(int i, int j, const string& word, int z)
    {
        if (visited[i][j] != word[z])
            return false;
        if (z == l - 1)
            return true;
        visited[i][j] = ' ';
        for (int k = 0; k < 4; k++) {
            int x = j + dx[k];
            int y = i + dy[k];
            if (x < 0 || x >= n || y < 0 || y >= m)
                continue;
            if (dfs(y, x, word, z + 1))
                return true;
        }
        visited[i][j] = word[z];
        return false;
    }
    bool exist(vector<vector<char>>& board, string word)
    {
        m = board.size(), n = board[0].size();
        l = word.size();
        if (l > m * n)
            return false;
        visited = board;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (dfs(i, j, word, 0))
                    return true;
            }
        }
        return false;
    }
};
int main()
{
    vector<vector<char>> board = {
        { 'A', 'B', 'C', 'E' },
        { 'S', 'F', 'C', 'S' },
        { 'A', 'D', 'E', 'E' }
    };
    Solution s;
    std::cout << s.exist(board, "FCE") << std::endl;
}