/*
 * @Descripttion: 74. 搜索二维矩阵
        编写一个高效的算法来判断 m x n 矩阵中，是否存在一个目标值。该矩阵具有如下特性：
            每行中的整数从左到右按升序排列。
            每行的第一个整数大于前一行的最后一个整数。
 * @version: 
 * @Author: Ye Yating
 * @Date: 2020-08-10 11:46:39
 * @LastEditors: Ye Yating
 * @LastEditTime: 2020-08-13 17:37:07
 */
#include <iostream>
#include <vector>
using std::vector;
class Solution {
public:
    // 执行用时：4 ms, 在所有 C++ 提交中击败了99.27% 的用户
    // 内存消耗：7.5 MB, 在所有 C++ 提交中击败了90.39% 的用户
    bool searchMatrix(vector<vector<int>>& matrix, int target)
    {
        if (matrix.size() == 0)
            return false;
        int m = matrix.size(), n = matrix[0].size();
        int start = 0, end = m * n - 1;
        while (start <= end) {
            int mid = (start + end) >> 1;
            if (matrix[mid / n][mid % n] == target)
                return true;
            else if (matrix[mid / n][mid % n] > target)
                end = mid - 1;
            else
                start = mid + 1;
        }
        return false;
    }
};
int main()
{
    vector<vector<int>> nums = {
        { 1, 2, 5, 6 }, { 10, 11, 16, 20 }, { 23, 30, 34, 50 }
    };
    Solution s;
    std::cout << s.searchMatrix(nums, 11) << std::endl;
}