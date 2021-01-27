/*
 * @Author: your name
 * @Date: 2021-01-27 19:00:20
 * @LastEditTime: 2021-01-27 19:38:13
 * @LastEditors: Please set LastEditors
 * @Description: 剑指 Offer 31. 栈的压入、弹出序列
 * 输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否为该栈的弹出顺序。
 * 假设压入栈的所有数字均不相等。例如，序列 {1,2,3,4,5} 是某栈的压栈序列，序列 {4,5,3,2,1} 
 * 是该压栈序列对应的一个弹出序列，但 {4,3,5,1,2} 就不可能是该压栈序列的弹出序列。
 * @FilePath: /offer2/31.cpp
 */
#include <vector>
#include <stack>
using namespace std;
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        if(pushed.size()==0 && popped.size()==0) return true;
        else if(pushed.size()==0 || popped.size()==0) return false;
        stack<int> s;
        int j=0;
        for(int i=0;i<pushed.size();i++){
            s.push(pushed[i]);
            while(!s.empty() && s.top()==popped[j]){
                s.pop();
                j++;
            }
        }
        return j==popped.size();
    }
};