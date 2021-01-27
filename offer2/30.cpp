/*
 * @Author: your name
 * @Date: 2021-01-27 18:50:34
 * @LastEditTime: 2021-01-27 19:01:02
 * @LastEditors: Please set LastEditors
 * @Description: 剑指 Offer 30. 包含min函数的栈
 * 定义栈的数据结构，请在该类型中实现一个能够得到栈的最小元素的 min 函数在该栈中，
 * 调用 min、push 及 pop 的时间复杂度都是 O(1)。
 * @FilePath: /offer2/30.cpp
 */
#include <stack>
#include <algorithm>
using namespace std;
class MinStack {
    stack<int> stack1,stack2;
public:
    /** initialize your data structure here. */
    MinStack() {

    }
    
    void push(int x) {
        stack1.push(x);
        if(stack2.empty()) stack2.push(x);
        else {
            int tmp=stack2.top()<x?stack2.top():x;
            stack2.push(tmp);
        }     
        return;   
    }
    
    void pop() {
        stack1.pop();
        stack2.pop();
    }
    
    int top() {
        return stack1.top();
    }
    
    int min() {
        return stack2.top();
    }
};