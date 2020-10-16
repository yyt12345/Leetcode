/*
 * @Author: your name
 * @Date: 2020-10-16 10:09:21
 * @LastEditTime: 2020-10-16 10:16:26
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /undefined/home/whh/programming/Leetcode/全组合.cpp
 */
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
class Solution{
public:
    string decodeStr(string str,int code){
        int n=str.size();
        int mask=1<<(n-1);
        string res;
        for(int i=0;i<n;i++){
            if((mask>>i) & code) res.push_back(str[i]);
        }
        return res;
    }
    vector<string> Permutation(string str){
        vector<string> res;
        int count=pow(2,str.size())-1;
        while(count>0){
            res.push_back(decodeStr(str,count--));
        }
        return res;
    }

};
int main(){
    Solution s;
    vector<string> res=s.Permutation("abc");
    for(string a:res)
        cout << a << endl;
}