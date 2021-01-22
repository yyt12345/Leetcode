/*** 
 * @Author: whh
 * @Date: 2020-12-15 15:20:09
 * @LastEditTime: 2020-12-15 15:40:32
 * @LastEditors: whh
 * @Description: 定义栈的数据结构，请在该类型中实现一个能够得到栈中所含最小元素的min函数（时间复杂度应为O（1））。
 * @FilePath: /Leetcode/JZ20.cpp
 */
#include <algorithm>
#include <stack>
#include <vector>
using namespace std;
class Solution {
    stack<int> s;
    stack<int> minS;

public:
    void push(int value)
    {
        s.push(value);
        if (minS.empty())
            minS.push(value);
        else {
            int tmp = minS.top() < value ? minS.top() : value;
            minS.push(tmp);
        }
    }
    void pop()
    {
        s.pop();
        minS.pop();
    }
    int top()
    {
        return s.top();
    }
    int min()
    {
        return minS.top();
    }
};