/*
 * @Author: your name
 * @Date: 2021-01-26 19:25:57
 * @LastEditTime: 2021-01-26 19:55:12
 * @LastEditors: Please set LastEditors
 * @Description: 剑指 Offer 17. 打印从1到最大的n位数(考虑大数问题)
 * 输入数字 n，按顺序打印出从 1 到最大的 n 位十进制数。比如输入 3，则打印出 1、2、3 一直到最大的 3 位数 999。
 * @FilePath: /offer2/17.cpp
 */
#include <vector>
#include <iostream>
#include <string>
using namespace std;
class Solution {
    vector<int> res;
    int n;
public:
    int sToi(string s){
        int res=0,tmp=1;
        int n=s.size()-1;
        for(int i=0;i<=n;i++){
            res += (s[n-i]-'0')*tmp;
            tmp*=10;
        }
        return res;
    }
    void dfs(string s){
        if(s.size()==n){
            int n=sToi(s);
            if(n) res.push_back(n);
            return;
        }
        for(int i=0;i<10;i++){
            char tmp='0'+i;
            dfs(s+tmp);
        }
        return;
    }
    vector<int> printNumbers(int n) {
        this->n=n;
        dfs("");
        return res;
    }
};
int main(){
    Solution s;
    vector<int> nums=s.printNumbers(2);
    for(int n:nums)
        cout << n << endl;
}