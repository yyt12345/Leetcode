/*** 
 * @Author: whh
 * @Date: 2020-12-21 20:21:41
 * @LastEditTime: 2020-12-21 21:23:14
 * @LastEditors: whh
 * @Description: 把只包含质因子2、3和5的数称作丑数（Ugly Number）。例如6、8都是丑数，但14不是，因为它包含质因子7。 习惯上我们把1当做是第一个丑数。求按从小到大的顺序的第N个丑数。
 * @FilePath: /Leetcode/JZ33.cpp
 */
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
class Solution {
public:
    /*** 
     * @description: 暴力法 算法复杂度过大
     */
    int GetUglyNumber_Solution(int index)
    {
        int num = 1;
        while (index) {
            int tmp = num;
            while (!(tmp % 5))
                tmp /= 5;
            while (!(tmp % 3))
                tmp /= 3;
            while (!(tmp % 2))
                tmp /= 2;
            if (tmp == 1)
                index--;
            num++;
        }
        return num - 1;
    }
    /*** 
     * @description: 使用小根堆
     */
    int GetUglyNumber_Solution2(int index)
    {
        if (!index)
            return 0;
        if (index == 1)
            return 1;
        std::priority_queue<long, std::vector<long>, std::greater<long>> q;
        q.push(1);
        long pre = 0;
        long num = 1;
        while (index--) {
            num = q.top();
            q.pop();
            if (pre == num) {
                index++;
                continue;
            }
            q.push(2 * num);
            q.push(3 * num);
            q.push(5 * num);
            pre = num;
        }
        return num;
    }
    /*** 
     * @description: 动态规划，三指针
     */
    int GetUglyNumber_Solution(int index)
    {
        if (!index)
            return 0;
        else if (index == 1)
            return 1;
        int two = 0, three = 0, five = 0;
        vector<int> dp(index);
        dp[0] = 1;
        for (int i = 1; i < index; i++) {
            int d1 = dp[two] * 2, d2 = dp[three] * 3, d3 = dp[five] * 5;
            dp[i] = min(d1, min(d2, d3));
            if (dp[i] == d1)
                two++;
            if (dp[i] == d2)
                three++;
            if (dp[i] == d3)
                five++;
        }
        return dp[index - 1];
    }
};
int main()
{
    Solution s;
    for (int i = 1; i <= 10; i++) {
        cout << s.GetUglyNumber_Solution2(i) << endl;
    }
    cout << s.GetUglyNumber_Solution2(7) << endl;
}