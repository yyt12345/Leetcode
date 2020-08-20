/*
 * @Descripttion: 529. 扫雷游戏
        让我们一起来玩扫雷游戏！
        给定一个代表游戏板的二维字符矩阵。 'M' 代表一个未挖出的地雷，'E' 代表一个未挖出的空方块，'B' 代表没有相邻（上，下，左，右，和所有4个对角线）地雷的已挖出的空白方块，数字（'1' 到 '8'）表示有多少地雷与这块已挖出的方块相邻，'X' 则表示一个已挖出的地雷。
        现在给出在所有未挖出的方块中（'M'或者'E'）的下一个点击位置（行和列索引），根据以下规则，返回相应位置被点击后对应的面板：
            如果一个地雷（'M'）被挖出，游戏就结束了- 把它改为 'X'。
            如果一个没有相邻地雷的空方块（'E'）被挖出，修改它为（'B'），并且所有和其相邻的未挖出方块都应该被递归地揭露。
            如果一个至少与一个地雷相邻的空方块（'E'）被挖出，修改它为数字（'1'到'8'），表示相邻地雷的数量。
            如果在此次点击中，若无更多方块可被揭露，则返回面板。
 * @version: 
 * @Author: Ye Yating
 * @Date: 2020-08-20 10:12:52
 * @LastEditors: Ye Yating
 * @LastEditTime: 2020-08-20 13:30:54
 */
#include <iostream>
#include <queue>
#include <vector>
using std::queue;
using std::vector;
class Solution {
    const int dx[8] = { 0, -1, -1, -1, 0, 1, 1, 1 };
    const int dy[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
    int m, n;

public:
    // 执行用时：64 ms, 在所有 C++ 提交中击败了91.05% 的用户
    // 内存消耗：14.2 MB, 在所有 C++ 提交中击败了35.94% 的用户
    void bfs(vector<vector<char>>& board, int y, int x)
    {
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        queue<vector<int>> q;
        q.push({ y, x });
        visited[y][x] = true;
        while (!q.empty()) {
            vector<int> tmp = q.front();
            q.pop();

            int count = 0;
            for (int i = 0; i < 8; i++) {
                int ycur = tmp[0] + dy[i], xcur = tmp[1] + dx[i];
                if (ycur < 0 || ycur >= m || xcur < 0 || xcur >= n)
                    continue;
                if (board[ycur][xcur] == 'M')
                    count++;
            }
            if (count)
                board[tmp[0]][tmp[1]] = count + '0';
            else {
                board[tmp[0]][tmp[1]] = 'B';
                for (int i = 0; i < 8; i++) {
                    int ycur = tmp[0] + dy[i], xcur = tmp[1] + dx[i];
                    if (ycur < 0 || ycur >= m || xcur < 0 || xcur >= n || visited[ycur][xcur] || board[ycur][xcur] != 'E')
                        continue;
                    q.push({ ycur, xcur });
                    visited[ycur][xcur] = true;
                }
            }
            // visited[tmp[0]][tmp[1]] = true;
        }
    }
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click)
    {
        m = board.size();
        if (m == 0)
            return board;
        n = board[0].size();

        int y = click[0], x = click[1];
        if (board[y][x] == 'M') {
            board[y][x] = 'X';
        } else if (board[y][x] == 'E') {
            bfs(board, y, x);
        }
        return board;
    }
};
int main()
{
    vector<vector<char>> map = {
        { 'E', 'E', 'E', 'E', 'E' },
        { 'E', 'E', 'M', 'E', 'E' },
        { 'E', 'E', 'E', 'E', 'E' },
        { 'E', 'E', 'E', 'E', 'E' },
        { 'E', 'E', 'E', 'E', 'E' }
    };
    vector<int> click = { 3, 1 };
    Solution s;
    s.updateBoard(map, click);
    for (auto row : map) {
        for (char a : row)
            std::cout << a << " ";
        std::cout << std::endl;
    }
}