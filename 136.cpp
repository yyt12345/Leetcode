/*
 * @Descripttion: 136. 只出现一次的数字
        给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。
        你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗？
 * @version: 
 * @Author: Ye Yating
 * @Date: 2020-08-08 11:08:47
 * @LastEditors: Ye Yating
 * @LastEditTime: 2020-08-08 11:26:26
 */
#include <iostream>
#include <vector>
using std::vector;
/*
    1、暴力法   从数组中取一个数，遍历数组进行比较   时间复杂度n^2 空间复杂度n
    2、排序     时间复杂度nlogn 空间复杂度1
    2、哈希     hash中记录每个数出现的次数，最后遍历hash表，找到出现一次的数    时间复杂度n 空间复杂度n
    3、异或运算     
*/

// 执行用时：28 ms, 在所有 C++ 提交中击败了33.33% 的用户
// 内存消耗：11.7 MB, 在所有 C++ 提交中击败了50.78%
int singleNumber2(vector<int>& nums)
{
    int res = 0;
    for (auto a : nums)
        res ^= a;
    return res;
}