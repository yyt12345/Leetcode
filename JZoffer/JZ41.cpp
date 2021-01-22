/***
 * @Date: 2020-11-18 09:40:23
 * @LastEditors: Ye Yating
 * @LastEditTime: 2020-11-18 09:51:09
 * @FilePath: /Leetcode/JZ41.cpp
 * @Reference:
 */
/***
 * @Date: 2020-11-18 09:40:23
 * @LastEditors: Ye Yating
 * @LastEditTime: 2020-11-18 09:49:24
 * @FilePath: /Leetcode/JZ41.cpp
 * @Reference:
 * 小明很喜欢数学,有一天他在做数学作业时,要求计算出9~16的和,他马上就写出了正确答案是100。但是他并不满足于此,他在想究竟有多少种连续的正数序列的和
 * 为100(至少包括两个数)。没多久,他就得到另一组连续正数和为100的序列:18,19,20,21,22。现在把问题交给你,你能不能也很快的找出所有和为S的连续正数序列?
 * Good Luck!
 */
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    /*** 
     * @description: 滑动窗口，双指针
     * @param : 
     * @return {*}
     */
    vector<vector<int>> FindContinuousSequence(int sum)
    {
        int start = 1, end = 1;
        int tmp = end;
        vector<vector<int>> res;
        while (end < sum) {
            if (tmp < sum) {
                tmp += ++end;
            } else if (tmp > sum) {
                tmp -= start++;
            } else {
                vector<int> t;
                for (int i = start; i <= end; i++)
                    t.push_back(i);
                res.push_back(t);
                start++;
                end = start;
                tmp = end;
            }
        }
        return res;
    }
};
int main()
{
    Solution s;
    vector<vector<int>> res = s.FindContinuousSequence(1);
    for (auto row : res) {
        for (int a : row)
            cout << a << " ";
        cout << endl;
    }
}