/*** 
 * @Author: whh
 * @Date: 2020-12-14 16:53:03
 * @LastEditTime: 2020-12-15 15:18:31
 * @LastEditors: whh
 * @Description: 输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字，
 * 例如，如果输入如下4 X 4矩阵： 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 则依次打印出数字1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10.
 * @FilePath: /Leetcode/JZ19.cpp
 */
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    /*** 
     * @description: 可以将矩阵看成若干层，首先打印最外层的元素，其次打印次外层的元素，直到打印最内层的元素。
     * 定义矩阵的第 kk 层是到最近边界距离为 kk 的所有顶点。例如，下图矩阵最外层元素都是第 11 层，次外层元素都是第 22 层，剩下的元素都是第 33 层。
     * 
     * [[1, 1, 1, 1, 1, 1, 1],
     * [1, 2, 2, 2, 2, 2, 1],
     * [1, 2, 3, 3, 3, 2, 1],
     * [1, 2, 2, 2, 2, 2, 1],
     * [1, 1, 1, 1, 1, 1, 1]]
     * 对于每层，从左上方开始以顺时针的顺序遍历所有元素。假设当前层的左上角位于 (top,left)，右下角位于 (bottom,right)，按照如下顺序遍历当前层的元素。
     * 从左到右遍历上侧元素，依次为 (top,left) 到 (top,right)。
     * 到下遍历右侧元素，依次为 (top+1,right) 到 (bottom,right)。
     * 如果left<right 且 top<bottom，则从右到左遍历下侧元素，依次为 (bottom,right−1) 到 (bottom,left+1)，以及从下到上遍历左侧元素，依次为(bottom,left) 到 (top+1,left)。
     * 遍历完当前层的元素之后，将 left 和 top 分别增加 11，将 right 和 bottom 分别减少 11，进入下一层继续遍历，直到遍历完所有元素为止。
     */
    vector<int> printMatrix(vector<vector<int>> matrix)
    {
        if (matrix.size() == 0 || matrix[0].size() == 0) {
            return {};
        }

        int rows = matrix.size(), columns = matrix[0].size();
        vector<int> order;
        int left = 0, right = columns - 1, top = 0, bottom = rows - 1;
        while (left <= right && top <= bottom) {
            for (int column = left; column <= right; column++) {
                order.push_back(matrix[top][column]);
            }
            for (int row = top + 1; row <= bottom; row++) {
                order.push_back(matrix[row][right]);
            }
            if (left < right && top < bottom) {
                for (int column = right - 1; column > left; column--) {
                    order.push_back(matrix[bottom][column]);
                }
                for (int row = bottom; row > top; row--) {
                    order.push_back(matrix[row][left]);
                }
            }
            left++;
            right--;
            top++;
            bottom--;
        }
        return order;
    }
};
int main()
{
    vector<vector<int>> matrix = {
        // { 1, 2, 3, 4, 17 },
        // { 5, 6, 7, 8, 18 },
        // { 9, 10, 11, 12, 19 },
        // { 13, 14, 15, 16, 10 },
        // { 21, 22, 23, 24, 25 }
        { 1, 2, 3, 4 },
        { 5, 6, 7, 8 },
        { 9, 10, 11, 12 },
        { 13, 14, 15, 16 }
    };
    Solution s;
    vector<int> res = s.printMatrix(matrix);
    for (auto a : res)
        cout << a << " ";
    cout << endl;
}