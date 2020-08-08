/*
 * @Descripttion: 99. 恢复二叉搜索树
        二叉搜索树中的两个节点被错误地交换。
        请在不改变其结构的情况下，恢复这棵树。
 * @version: 
 * @Author: Ye Yating
 * @Date: 2020-08-08 10:35:41
 * @LastEditors: Ye Yating
 * @LastEditTime: 2020-08-08 11:08:47
 */
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> res;
//类似位掩码的思想
// 执行用时：4 ms, 在所有 C++ 提交中击败了60.37% 的用户
// 内存消耗：15.2 MB, 在所有 C++ 提交中击败了5.00% 的用户
void permutation(const vector<int>& nums, vector<bool>& flag, int i)
{
    int n = flag.size();
    if (i == n) {
        vector<int> tmp;
        for (int j = 0; j < n; j++) {
            if (flag[j])
                tmp.push_back(nums[j]);
        }
        res.push_back(tmp);
        return;
    }

    flag[i] = false;
    permutation(nums, flag, i + 1);

    flag[i] = true;
    permutation(nums, flag, i + 1);

    return;
}
vector<vector<int>> subsets(vector<int>& nums)
{
    int n = nums.size();
    vector<bool> flag(n, false);
    permutation(nums, flag, 0);
    return res;
}
//使用二进制数生成掩码，来表示各个位上的数是否存在
// 执行用时：8 ms, 在所有 C++ 提交中击败了9.84% 的用户
// 内存消耗：7.5 MB, 在所有 C++ 提交中击败了16.88% 的用户
vector<vector<int>> subsets2(vector<int>& nums)
{
    int n = nums.size();
    int setNum = pow(2, n);
    for (int mask_set = 0; mask_set < setNum; mask_set++) {
        vector<int> tmp;
        for (int i = 0; i < n; i++) {
            if ((mask_set >> i) & 1) {
                tmp.push_back(nums[i]);
            }
        }
        res.push_back(tmp);
    }
    return res;
}
int main()
{
    vector<int> nums = { 1, 2, 3 };
    subsets(nums);
    for (auto num : res) {
        for (int a : num)
            cout << a << " ";
        cout << endl;
    }
}