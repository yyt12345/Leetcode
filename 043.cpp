/*
 * @Descripttion: 43. 字符串相乘
        给定两个以字符串形式表示的非负整数 num1 和 num2，返回 num1 和 num2 的乘积，它们的乘积也表示为字符串形式。
 * @version: 
 * @Author: Ye Yating
 * @Date: 2020-07-23 09:55:15
 * @LastEditors: Ye Yating
 * @LastEditTime: 2020-07-23 11:22:20
 */ 
#include <string>
#include <vector>
#include <iostream>
using namespace std;
// 执行用时：28 ms, 在所有 C++ 提交中击败了22.87% 的用户
// 内存消耗：7.9 MB, 在所有 C++ 提交中击败了100.00% 的用户
string multiply(string num1, string num2) {
    int n=num1.size(),m=num2.size();
    if(num1=="0" || num2=="0") return "0";
    if(n==0 || m==0) return "0";

    vector<int> c(m+n,0);
    for(int j=m-1;j>=0;j--){
        for(int i=n-1;i>=0;i--){
            c[i+j+1]+=(num1[i]-'0')*(num2[j]-'0');
        }
    }
    string res="";
    for(int i=m+n-1;i>0;i--){
        c[i-1]+=c[i]/10;
        c[i]%=10;
        res= to_string(c[i]) + res;
    }
    if(c[0]!=0) res=to_string(c[0])+res;
    return res;

}
// 执行用时：12 ms, 在所有 C++ 提交中击败了50.52% 的用户
// 内存消耗：6.9 MB, 在所有 C++ 提交中击败了100.00% 的用户
string multiply2(string num1, string num2) {
    int n=num1.size(),m=num2.size();
    if(num1=="0" || num2=="0") return "0";
    if(n==0 || m==0) return "0";

    vector<int> c(m+n,0);
    for(int j=m-1;j>=0;j--){
        for(int i=n-1;i>=0;i--){
            int temp= c[i+j+1] + (num1[i]-'0')*(num2[j]-'0');
            c[i+j+1]=temp%10;
            c[i+j]+=temp/10;
        }
    }
    string res="";
    for(int i=0;i<m+n;i++){
        if(i==0 && c[i]==0) continue;
        res.append(to_string(c[i]));
    }
    return res;

}
int main(){
    string num1="123";
    string num2="456";
    cout << multiply2(num1,num2) << endl;
}