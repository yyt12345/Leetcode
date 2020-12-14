/*** 
 * @Author: whh
 * @Date: 2020-12-14 14:50:44
 * @LastEditTime: 2020-12-14 15:36:28
 * @LastEditors: whh
 * @Description: 输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有的奇数位于数组的前半部分，所有的偶数位于数组的后半部分，并保证奇数和奇数，偶数和偶数之间的相对位置不变。
 * @FilePath: /Leetcode/JZ13.cpp
 */
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    /*** 
     * @description: 
     *      方法一：使用2个辅助数组将偶数保存 时间复杂度o(n) 空间复杂度o(n)
     *      方法二：时间复杂度o(n^2) 空间复杂度o(1)
     */
    void reOrderArray(vector<int>& array)
    {
        if (array.size() == 0)
            return;
        // 双指针法
        int even;
        for (int i = 0; i < array.size(); i++) {
            if (array[i] % 2 == 0) {
                even = i;
                break;
            }
        }
        for (int i = even + 1; i < array.size() && even <= array.size() / 2; i++) {
            if (array[i] % 2) {
                array.insert(array.begin() + even, array[i]);
                array.erase(array.begin() + i + 1);
                even++;
            }
        }
        return;
    }
};
int main()
{
    Solution s;
    vector<int> nums = { 1, 2, 3, 4, 5, 6, 7 };
    s.reOrderArray(nums);
    for (auto a : nums) {
        cout << a << " ";
    }
    cout << endl;
}