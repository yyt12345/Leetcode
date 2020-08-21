/*
 * @Descripttion: 89. 格雷编码
        格雷编码是一个二进制数字系统，在该系统中，两个连续的数值仅有一个位数的差异。
        给定一个代表编码总位数的非负整数 n，打印其格雷编码序列。即使有多个不同答案，你也只需要返回其中一种。
        格雷编码序列必须以 0 开头。
 * @version: 
 * @Author: Ye Yating
 * @Date: 2020-08-21 22:06:21
 * @LastEditors: Ye Yating
 * @LastEditTime: 2020-08-21 22:41:11
 */
#include <algorithm>
#include <iostream>
#include <vector>
using std::vector;
class Solution {
    vector<int> result;

public:
    // 执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
    // 内存消耗：6.8 MB, 在所有 C++ 提交中击败了27.78% 的用户
    vector<int> grayCode(int n)
    {
        if (n == 0)
            return { 0 };
        if (n == 1) {
            return { 0, 1 };
        }
        vector<int> res = grayCode(n - 1);
        for (int i = res.size() - 1; i >= 0; i--) {
            res.push_back(res[i] + std::pow(2, n - 1));
        }
        return res;
    }
    // 方法二将结果数组存储在Solution中，减少了数据传输，以空间换时间
    // 执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
    // 内存消耗：7.1 MB, 在所有 C++ 提交中击败了11.27% 的用户
    void func(int n)
    {
        if (n == 1) {
            result.insert(result.begin(), { 0, 1 });
            return;
        }
        func(n - 1);
        for (int i = result.size() - 1; i >= 0; i--) {
            result.push_back(result[i] + std::pow(2, n - 1));
        }
        return;
    }
    vector<int> grayCode2(int n)
    {
        if (n == 0)
            return { 0 };
        func(n);
        return result;
    }
};
int main()
{
    Solution s;
    vector<int> res = s.grayCode2(2);
    for (int a : res)
        std::cout << a << " ";
    std::cout << std::endl;
}