/*
 * @Descripttion: 486. 预测赢家
        给定一个表示分数的非负整数数组。 玩家 1 从数组任意一端拿取一个分数，随后玩家 2 继续从剩余数组任意一端拿取分数，然后玩家 1 拿，…… 。每次一个玩家只能拿取一个分数，分数被拿取之后不再可取。直到没有剩余分数可取时游戏结束。最终获得分数总和最多的玩家获胜。
        给定一个表示分数的数组，预测玩家1是否会成为赢家。你可以假设每个玩家的玩法都会使他的分数最大化。
 * @version: 
 * @Author: Ye Yating
 * @Date: 2020-09-01 09:24:02
 * @LastEditors: Ye Yating
 * @LastEditTime: 2020-09-01 09:58:01
 */
#include <algorithm>
#include <iostream>
#include <vector>
using std::vector;
class Solution {
public:
    // 执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
    // 内存消耗：8.1 MB, 在所有 C++ 提交中击败了19.80% 的用户
    bool PredictTheWinner(vector<int>& nums)
    {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
            dp[i][i] = nums[i];
        for (int i = n - 2; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                dp[i][j] = std::max(nums[i] - dp[i + 1][j], nums[j] - dp[i][j - 1]);
            }
        }
        return dp[0][n - 1] >= 0;
    }
};
int main()
{
    vector<int> nums = { 1, 5, 2 };
    Solution s;
    std::cout << s.PredictTheWinner(nums) << std::endl;
}