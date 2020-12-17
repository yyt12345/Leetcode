/*** 
 * @Author: whh
 * @Date: 2020-12-17 11:34:39
 * @LastEditTime: 2020-12-17 11:47:40
 * @LastEditors: whh
 * @Description: 输入n个整数，找出其中最小的K个数。例如输入4,5,1,6,2,7,3,8这8个数字，则最小的4个数字是1,2,3,4。
 * @FilePath: /Leetcode/JZ29.cpp
 */
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    /*** 
     * @description: 排序
     */
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k)
    {
        if (input.size() == 0 || input.size() < k)
            return {};
        sort(input.begin(), input.end());
        vector<int> res(input.begin(), input.begin() + k);
        return res;
    }
    /*** 
     * @description: 方法二：小顶堆
     */
};
int main()
{
    Solution s;
    vector<int> input = { 1, 4, 2, 6, 7, 3, 8, 9 };
    vector<int> res = s.GetLeastNumbers_Solution(input, 2);
    for (auto a : res)
        cout << a << " ";
    cout << endl;
}