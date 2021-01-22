/*** 
 * @Date: 2020-11-18 10:15:19
 * @LastEditors: Ye Yating
 * @LastEditTime: 2020-11-18 10:32:41
 * @FilePath: /Leetcode/JZ42.cpp
 * @Reference: 输入一个递增排序的数组和一个数字S，在数组中查找两个数，使得他们的和正好是S，如果有多对数字的和等于S，输出两个数的乘积最小的。
 */
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    /*** 
     * @description:双指针 
     * @param : 
     * @return {*}
     */
    vector<int> FindNumbersWithSum(vector<int> array, int sum)
    {
        int i = 0, j = array.size() - 1;
        if (j == i)
            return {};
        int minMul = INT8_MAX;
        vector<int> res;
        while (i < j) {
            int tmp = array[i] + array[j];
            if (tmp < sum)
                i++;
            else if (tmp > sum)
                j--;
            else {
                res.push_back(array[i]);
                res.push_back(array[j]);
                break;
            }
        }
        return res;
    }
};
int main()
{
    Solution s;
    vector<int> nums = { 1, 2, 3, 4, 5, 6, 7 };
    vector<int> res = s.FindNumbersWithSum(nums, 7);
    for (auto a : res)
        cout << a << " ";
    cout << endl;
}