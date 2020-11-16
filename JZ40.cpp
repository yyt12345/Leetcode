/*** 
 * @Date: 2020-11-16 10:51:30
 * @LastEditors: Ye Yating
 * @LastEditTime: 2020-11-16 11:28:26
 * @FilePath: /undefined/home/whh/c++pragramming/Leetcode/JZ40.cpp
 * @Reference: 一个整型数组里除了两个数字之外，其他的数字都出现了两次。请写程序找出这两个只出现一次的数字。
 */
#include <map>
#include <iostream>
#include <iterator>
#include <vector>
using namespace std;
class Solution
{
public:
    /*** 
     * @description: 使用hash。若匹配到hash，则删除。无，则添加
     * @param : 
     * @return {*}
     */
    void FindNumsAppearOnce(vector<int> data, int *num1, int *num2)
    {
        map<int, bool> hash;
        for (int num : data)
        {
            if (hash[num])
                hash.erase(num);
            else
                hash[num] = true;
        }
        auto it = hash.begin();
        *num1 = it++->first;
        *num2 = it->first;
        return;
    }
    /*** 
     * @description: 使用位运算：异或。相同数异或=0
     * @param : 
     * @return {*}
     */
    void FindNumsAppearOnce2(vector<int> data, int *num1, int *num2)
    {
        int tmp = 0;
        for (int a : data)
            tmp ^= a;
        int mask = 1;
        while (!(mask & tmp))
        {
            mask = mask << 1;
        }
        for (int a : data)
        {
            if (a & mask)
                *num1 ^= a;
            else
                *num2 ^= a;
        }
        return;
    }
};
int main()
{
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 1, 3, 5, 6, 7};
    int *num1 = new int;
    int *num2 = new int;
    Solution s;
    s.FindNumsAppearOnce2(nums, num1, num2);
    cout << *num1 << " " << *num2 << endl;
}