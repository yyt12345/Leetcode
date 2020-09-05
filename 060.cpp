/*
 * @Descripttion: 60. 第k个排列
        给出集合 [1,2,3,…,n]，其所有元素共有 n! 种排列。
        按大小顺序列出所有排列情况，并一一标记，当 n = 3 时, 所有排列如下：
 * @Author: Ye Yating
 * @Date: 2020-08-05 21:17:05
 * @LastEditors: Ye Yating
 * @LastEditTime: 2020-09-05 10:31:59
 */
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
private:
    int factorial(int n)
    {
        int res = 1;
        while (n > 0) {
            res *= n--;
        }
        return res;
    }

public:
    // 执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
    // 内存消耗：6 MB, 在所有 C++ 提交中击败了87.46% 的用户
    string getPermutation(int n, int k)
    {
        vector<char> nums(n);
        for (int i = 0; i < n; i++)
            nums[i] = i + 1 + '0';
        vector<bool> used(n, false);
        int l = n;
        string res = "";
        while (n > 0) {
            int cur = factorial(n - 1);
            for (int i = 0; i < l; i++) {
                if (used[i])
                    continue;
                if (cur < k) {
                    k -= cur;
                    continue;
                }
                res.push_back(nums[i]);
                used[i] = true;
                break;
            }
            n--;
        }
        return res;
    }
    // 执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
    // 内存消耗：6.2 MB, 在所有 C++ 提交中击败了33.39% 的用户
    string getPermutation2(int n, int k)
    {
        string res;
        vector<bool> ok(n);
        k--;
        int level = n;
        while (level) {
            int factorialN = factorial(--level);
            int div = k / factorialN;
            k %= factorialN;

            for (int i = 0; i < n; i++) {
                if (ok[i])
                    continue;
                if (!div) {
                    res.push_back(i + '1');
                    ok[i] = 1;
                    break;
                }
                div--;
            }
        }
        return res;
    }
};
int main()
{
    Solution s;
    cout << s.getPermutation2(3, 3) << endl;
}