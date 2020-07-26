/*
 * @Descripttion: 125. 验证回文串
        给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。
        说明：本题中，我们将空字符串定义为有效的回文串。
 * @version: 
 * @Author: Ye Yating
 * @Date: 2020-06-19 20:23:17
 * @LastEditors: Ye Yating
 * @LastEditTime: 2020-06-19 20:51:39
 */ 
#include <string>
#include <iostream>
using namespace std;
//  4 ms    98.82%      7.2 MB      100.00%
bool isPalindrome(string s) {
    int len=s.size();
    if(len==0) return true;
    int start=0,end=len-1;
    while(start<end){
        if(!isalnum(s[start])){
            start++;continue;
        }
        if(!isalnum(s[end])){
            end--;continue;
        }
        if(tolower(s[start])!=tolower(s[end])) return false;
        else{
            start++;end--;
        }
    }
    return true;
}
//递归法 8 ms   85.02%  7.4 MB  100.00%
bool func(string& s,int start,int end){
    if(start>=end) return true;
    if(!isalnum(s[start])) return func(s,start+1,end);
    if(!isalnum(s[end])) return func(s,start,end-1);
    if(tolower(s[start])!=tolower(s[end])) return false;
    else{
        return func(s,start+1,end-1);
    }
}
bool isPalindrome2(string s){
    if(s.size()==0) return true;
    return func(s,0,s.size()-1);
}

int main(){
    cout << isPalindrome2("A man, a plan, a canal: Panama");
}