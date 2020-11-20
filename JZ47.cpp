/*** 
 * @Date: 2020-11-20 10:11:11
 * @LastEditors: Ye Yating
 * @LastEditTime: 2020-11-20 10:25:20
 * @FilePath: /Leetcode/JZ47.cpp
 * @Reference: 求1+2+3+...+n，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）。
 */
class Solution {
public:
    /*** 
     * @description: 递归  用到了if，不符合要求
     * @param : 
     * @return {*}
     */
    int Sum_Solution(int n)
    {
        if (n == 1)
            return 1;
        return n + Sum_Solution(n - 1);
    }
    /*** 
     * @description: 将终止条件替换掉
     * @param : 
     * @return {*}
     */
    int Sum_Solution(int n)
    {
        int sum = n;
        n > 1 && (sum += Sum_Solution(n - 1));
        return sum;
    }
};