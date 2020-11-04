/*
 * @Author: your name
 * @Date: 2020-11-04 16:04:15
 * @LastEditTime: 2020-11-04 16:18:54
 * @LastEditors: Please set LastEditors
 * @Description: 输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否可能为该栈的弹出顺序。假设压入栈的所有数字均不相等。例如序列1,2,3,4,5是某栈的压入顺序，序列4,5,3,2,1是该压栈
 * 序列对应的一个弹出序列，但4,3,5,1,2就不可能是该压栈序列的弹出序列。（注意：这两个序列的长度是相等的）
 * @FilePath: /undefined/home/whh/programming/Leetcode/JZ21.cpp
 */
#include <stack>
using namespace std;
class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        stack<int> s;
        int m=pushV.size(),n=popV.size();
        int i=0,j=0;
        while(i<m){
            if(!s.empty() && pushV[i]==popV[j]){
                i++;j++;
                while(s.top()==popV[j]){
                    j++;
                    s.pop();
                }
            }else {
                s.push(pushV[i++]);

            }
        }
        return s.empty();
    }
};