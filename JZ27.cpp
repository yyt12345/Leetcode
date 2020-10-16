/*
 * @Author: your name
 * @Date: 2020-10-15 09:54:03
 * @LastEditTime: 2020-10-16 09:40:42
 * @LastEditors: Please set LastEditors
 * @Description: 字符串的排列
 * 输入一个字符串,按字典序打印出该字符串中字符的所有排列。例如输入字符串abc,则按字典序打印出由字符a,b,c所能排列出来的所有字符串abc,acb,bac,bca,cab和cba。
 * @FilePath: /undefined/home/whh/programming/Leetcode/JZ27.cpp
 */
//全排列问题
//方法一：全部存入哈西表，并按字典序输出 
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <iostream>
using std::string;
using std::map;
using std::vector;
class Solution {
    vector<string> res;
public:
// 递归法
    vector<string> Permutation(string str) {
          if(str.size()==0) return res;
          Permutation(str,0);
          std::sort(res.begin(),res.end());
          return res;
    }
    void Permutation(string str,int begin){
        if(begin==str.size()){
            res.push_back(str);
            return;
        }
        // map<char,int> charset;
        int n=str.size();
        for(int i=begin;i<n;i++){
            if(i!=begin && str[i]==str[i-1]) continue;
            std::swap(str[i],str[begin]);
            Permutation(str,begin+1);
            std::swap(str[i],str[begin]);
        }
        return;
    }

//字典序法
    vector<string> Permutation2(string str) {
        if(str.size()==0) return res;
        std::sort(str.begin(),str.end());
        res.push_back(str);
        while(true){
            str=nextString(str);
            if(str==" ") break;
            res.push_back(str);
        }
        return res;
    }
    string nextString(string str){
        int i=str.size()-2;
        for(;i>=0 && str[i]>=str[i+1];i--);
        if(i==-1) return " ";
        int j=str.size()-1;
        for(;j>=0 && str[i]>=str[j];j--);
        std::swap(str[i],str[j]);
        std::reverse(str.begin()+i+1,str.end());
        return str;
    }
};
int main(){
    Solution s;
    vector<string> res=s.Permutation2("acb");
    for(auto a:res)
        std::cout << a << std::endl;
    
}