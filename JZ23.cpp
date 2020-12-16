/*** 
 * @Author: whh
 * @Date: 2020-12-15 15:42:59
 * @LastEditTime: 2020-12-16 10:22:19
 * @LastEditors: whh
 * @Description: 输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。如果是则返回true,否则返回false。假设输入的数组的任意两个数字都互不相同。
 * @FilePath: /Leetcode/JZ23.cpp
 */
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
    bool subFun(vector<int> sequence, int start, int end)
    {
        if (end - start <= 2)
            return true;
        int root = sequence[end];
        int flag = false, rightStart = start;
        for (int i = start; i < end; i++) {
            if (!flag && sequence[i] > root) {
                flag = true;
                rightStart = i;
            } else if (flag && sequence[i] < root)
                return false;
        }
        if (rightStart != start)
            return subFun(sequence, start, rightStart - 1) && subFun(sequence, rightStart, end - 1);
        else
            return subFun(sequence, rightStart, end - 1);
    }
    bool VerifySquenceOfBST(vector<int> sequence)
    {
        if (sequence.size() == 0)
            return false;
        return subFun(sequence, 0, sequence.size() - 1);
    }
    /*** 
     * @description: 单调树方法
     */
    bool VerifySquenceOfBST(vector<int> sequence)
    {
        int n = sequence.size();
        if (n == 0)
            return false;
        stack<int> s;
        int root = INT8_MAX;
        //从右向左遍历
        for (int i = n - 1; i >= 0; i--) {
            if (sequence[i] > root)
                return false;
            while (!s.empty() && sequence[i] < s.top()) {
                root = s.top();
                s.pop();
            }
            s.push(sequence[i]);
        }
        return true;
    }
};
int main()
{
    Solution s;
    vector<int> nums = { 1, 6, 3, 2, 5 };
    cout << s.VerifySquenceOfBST(nums) << endl;
}