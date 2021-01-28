/*
 * @Author: your name
 * @Date: 2021-01-28 23:02:15
 * @LastEditTime: 2021-01-28 23:12:51
 * @LastEditors: Please set LastEditors
 * @Description: 剑指 Offer 40. 最小的k个数
 * 输入整数数组 arr ，找出其中最小的 k 个数。例如，输入4、5、1、6、2、7、3、8这8个数字，则最小的4个数字是1、2、3、4。
 * @FilePath: /offer2/40.cpp
 */

#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        //快排，哈希，小顶堆
        priority_queue<int,vector<int>,greater<int>> q;
    }
};