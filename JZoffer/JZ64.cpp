/*** 
 * @Author: whh
 * @Date: 2020-12-29 19:27:16
 * @LastEditTime: 2020-12-29 20:35:01
 * @LastEditors: whh
 * @Description: 给定一个数组和滑动窗口的大小，找出所有滑动窗口里数值的最大值。例如，如果输入数组{2,3,4,2,6,2,5,1}及滑动窗口的大小3，那么一共存在6个滑动窗口，他们的
 * 最大值分别为{4,4,6,6,6,5}； 针对数组{2,3,4,2,6,2,5,1}的滑动窗口有以下6个： {[2,3,4],2,6,2,5,1}， {2,[3,4,2],6,2,5,1}， {2,3,[4,2,6],2,5,1}， {2,3,4,[2,6,2],5,1}， 
 * {2,3,4,2,[6,2,5],1}， {2,3,4,2,6,[2,5,1]}。
 * 窗口大于数组长度的时候，返回空
 * @FilePath: /Leetcode/JZ64.cpp
 */
#include <deque>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    /*** 
     * @description: 暴力法
     */
    vector<int> maxInWindows(const vector<int>& num, unsigned int size)
    {
        if (num.size() == 0 || size <= 0 || size > num.size())
            return {};
        int n = num.size() - size + 1;
        int maxN = 0;
        vector<int> res;
        for (int i = 0; i < size; i++) {
            maxN = max(maxN, num[i]);
        }
        res.push_back(maxN);
        for (int i = 1; i < n; i++) {
            if (num[i - 1] != maxN)
                maxN = max(maxN, num[i + size - 1]);
            else {
                maxN = 0;
                for (int j = 0; j < size; j++)
                    maxN = max(maxN, num[i + j]);
            }
            res.push_back(maxN);
        }
        return res;
    }
    /*** 
     * @description: 动态规划
     */
    vector<int> maxInWindows2(const vector<int>& num, unsigned int size)
    {
        if (num.size() == 0 || size <= 0 || size > num.size())
            return {};
        int n = num.size();
        vector<vector<int>> dp(size, vector<int>(n));
        dp[0] = num;
        for (int i = 1; i < size; i++) {
            for (int j = i; j < n; j++) {
                dp[i][j] = max(dp[i - 1][j - 1], num[j]);
            }
        }
        return vector<int>(dp[size - 1].begin() + size - 1, dp[size - 1].end());
    }
    /*** 
     * @description: 双端队列
     */
    vector<int> maxInWindows3(const vector<int>& num, unsigned int size)
    {
        if (num.size() == 0 || size <= 0 || size > num.size())
            return {};
        int n = num.size();
        vector<int> res;
        deque<int> q;
        for (int i = 0; i < n; i++) {
            if (i >= size && q.front() == num[i - size])
                q.pop_front();
            while (!q.empty() && num[i] > q.back()) {
                q.pop_back();
            }
            q.push_back(num[i]);
            if (i >= size - 1)
                res.push_back(q.front());
        }
        return res;
    }
};
int main()
{
    Solution s;
    vector<int> num = { 2, 3, 4, 2, 6, 2, 5, 1 };
    vector<int> res = s.maxInWindows3(num, 3);
    for (auto a : res)
        cout << a << " ";
    cout << endl;
}