/*
 * @Author: your name
 * @Date: 2021-01-26 21:04:00
 * @LastEditTime: 2021-01-26 22:17:40
 * @LastEditors: Please set LastEditors
 * @Description: 剑指 Offer 20. 表示数值的字符串
 * 请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。
 * 例如，字符串"+100"、"5e2"、"-123"、"3.1416"、"-1E-16"、"0123"都表示数值，
 * 但"12e"、"1a3.14"、"1.2.3"、"+-5"及"12e+5.4"都不是
 * @FilePath: /offer2/20.cpp
 */
#include <string>
#include <iostream>
using namespace std;
enum STATE{sBlank,flag1,num1,dotNoNum,dot1,num2,e,flag2,num3,eBlank,error};
class Solution {
public:
    bool isNumber(string s) {
        if(s.size()==0) return false;
        STATE state=sBlank;
        for(int i=0;i<s.size();i++){
            switch(state){
                case sBlank:
                    if(s[i]==' ') state=sBlank;
                    else if(s[i]=='-' || s[i]=='+')  state=flag1;
                    else if(isdigit(s[i])) state=num1;
                    else if(s[i]=='.') state=dotNoNum;
                    else state=error;
                    break;
                case flag1:
                    if(isdigit(s[i])) state=num1;
                    else if(s[i]=='.') state=dotNoNum;
                    else state=error;
                    break;
                case num1:
                    if(isdigit(s[i])) state=num1;
                    else if(s[i]=='.') state=dot1;
                    else if(s[i]=='E' || s[i]=='e') state=e;
                    else if(s[i]==' ') state=eBlank;
                    else state=error;
                    break;
                case dotNoNum:
                    if(isdigit(s[i])) state=num2;
                    else state=error;
                    break;
                case dot1:
                    if(isdigit(s[i])) state=num2;
                    else if(s[i]=='E' || s[i]=='e') state=e;
                    else if(s[i]==' ') state=eBlank;
                    else state=error;
                    break;
                case num2:
                    if(isdigit(s[i])) state=num2;
                    else if(s[i]=='E' || s[i]=='e') state=e;
                    else if(s[i]==' ') state=eBlank;
                    else state=error;
                    break;
                case e:
                    if(s[i]=='-' || s[i]=='+')  state=flag2;
                    else if(isdigit(s[i])) state=num3;
                    else state=error;
                    break;
                case flag2:
                    if(isdigit(s[i])) state=num3;
                    else state=error;
                    break;
                case num3:
                    if(isdigit(s[i])) state=num3;
                    else if(s[i]==' ') state=eBlank;
                    else state=error;
                    break;
                case eBlank:
                    if(s[i]==' ') state=eBlank;
                    else state=error;
                    break;
                    
            }
            if(state==error) return false;
        }
        switch (state)
        {
            case num1:
            case num2:
            case num3:
            case dot1:
            case eBlank:
                return true;
            
            default:
                return false;
        }
    }
};
int main(){
    Solution s;
    cout << s.isNumber("1 ") << endl;
}
