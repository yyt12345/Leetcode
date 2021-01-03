/*** 
 * @Author: whh
 * @Date: 2020-12-21 21:42:07
 * @LastEditTime: 2021-01-03 17:16:13
 * @LastEditors: whh
 * @Description: 在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。输入一个数组,求出这个数组中的逆序对的总数P。并将P对1000000007取模的结果输出。 即输出P%1000000007
 * @FilePath: /Leetcode/JZ35.cpp
 */
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    /*** 
     * @description: 暴力法 n^2 超时
     */
    int count = 0;
    int InversePairs2(vector<int> data)
    {
        int n = data.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (data[i] > data[j])
                    count++;
            }
        }
        return count;
    }
    /*** 
     * @description: 归并算法，在使前后两串字符串有序的同时，计算逆序对
     * @param {vector<int>} data
     */
    int InversePairs(vector<int> data)
    {
        int n = data.size();
        vector<int> tmp(n);
        return mergeSort(data, tmp, 0, n - 1) % 1000000007;
    }
    long long mergeSort(vector<int>& nums, vector<int>& tmp, int l, int r)
    {
        if (l >= r)
            return 0;
        int mid = (l + r) >> 1;
        long long inv_count = mergeSort(nums, tmp, l, mid) + mergeSort(nums, tmp, mid + 1, r);
        int i = l, j = mid + 1, pos = l;
        while (i <= mid && j <= r) {
            if (nums[i] <= nums[j]) {
                tmp[pos++] = nums[i];
                i++;
                inv_count += (j - (mid + 1));
            } else {
                tmp[pos++] = nums[j];
                j++;
            }
        }
        for (int k = i; k <= mid; k++) {
            tmp[pos++] = nums[k];
            inv_count += (j - (mid + 1));
        }
        for (int k = j; k <= r; k++) {
            tmp[pos++] = nums[k];
        }
        copy(tmp.begin() + l, tmp.begin() + r + 1, nums.begin() + l);
        return inv_count;
    }
};
int main()
{
    Solution s;
    vector<int> data = { 1, 2, 3, 4, 5, 6, 7, 0 };
    cout << s.InversePairs(data) << endl;
}