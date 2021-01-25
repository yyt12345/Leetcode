/*
 * @Author: your name
 * @Date: 2021-01-25 23:14:41
 * @LastEditTime: 2021-01-25 23:32:10
 * @LastEditors: Please set LastEditors
 * @Description: 剑指 Offer 09. 用两个栈实现队列
 * 用两个栈实现一个队列。队列的声明如下，请实现它的两个函数 appendTail 和 deleteHead ，分别完成在队列尾部
 * 插入整数和在队列头部删除整数的功能。(若队列中没有元素，deleteHead 操作返回 -1 )
 * @FilePath: /offer2/09.cpp
 */
#include <stack>
#include <iostream>
using namespace std;
class CQueue {
    stack<int> stack1,stack2;
public:
    CQueue() {

    }
    
    void appendTail(int value) {
        stack1.push(value);
    }
    
    int deleteHead() {
        if(stack2.empty()){
            while(!stack1.empty()){
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        if(stack2.empty()) return -1;
        int res=stack2.top();
        stack2.pop();
        return res;
    }
};
