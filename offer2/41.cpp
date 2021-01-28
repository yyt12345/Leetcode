/*
 * @Author: your name
 * @Date: 2021-01-28 23:13:45
 * @LastEditTime: 2021-01-28 23:32:56
 * @LastEditors: Please set LastEditors
 * @Description: 剑指 Offer 41. 数据流中的中位数
 * 如何得到一个数据流中的中位数？如果从数据流中读出奇数个数值，那么中位数就是所有数值排序之后位于中间的数值。
 * 如果从数据流中读出偶数个数值，那么中位数就是所有数值排序之后中间两个数的平均值。
 * 例如，[2,3,4] 的中位数是 3
 * [2,3] 的中位数是 (2 + 3) / 2 = 2.5
 * 设计一个支持以下两种操作的数据结构：
 * void addNum(int num) - 从数据流中添加一个整数到数据结构中
 * double findMedian() - 返回目前所有元素的中位数。
 * @FilePath: /offer2/41.cpp
 */
#include <queue>
using namespace std;
class MedianFinder {
    priority_queue<int> smallQ;
    priority_queue<int,vector<int>,greater<int>> bigQ;
public:
    /** initialize your data structure here. */
    MedianFinder() {

    }
    
    void addNum(int num) {
        bigQ.push(num);
        smallQ.push(bigQ.top());
        bigQ.pop();
        if(smallQ.size()-bigQ.size()>1) {
            bigQ.push(smallQ.top());
            smallQ.pop();
        }
    }
    
    double findMedian() {
        if(smallQ.size()==0) return -1;
        if(smallQ.size()==bigQ.size()) return (smallQ.top()+bigQ.size())/(double)2;
        else return bigQ.top();
    }
};