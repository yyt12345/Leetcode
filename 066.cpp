/*
 * @Descripttion: 66. 加一
        给定一个由整数组成的非空数组所表示的非负整数，在该数的基础上加一。
        最高位数字存放在数组的首位， 数组中每个元素只存储单个数字。
        你可以假设除了整数 0 之外，这个整数不会以零开头。
 * @version: 
 * @Author: Ye Yating
 * @Date: 2020-05-30 12:13:52
 * @LastEditors: Ye Yating
 * @LastEditTime: 2020-05-30 12:36:20
 */ 
#include <vector>
#include <iostream>
#include <iterator>
using namespace std;
//0 ms  100.00%     6.8 MB  100.00%
vector<int> plusOne(vector<int>& digits) {
    vector<int>::reverse_iterator it;
    for(it=digits.rbegin();it!=digits.rend();it++){
        if(*it!=9){
            (*it)++;
            break;
        }
        else 
            (*it)=0;
    }
    if(it==digits.rend())
        digits.insert(digits.begin(),1);
    return digits;
}
int main(){
    vector<int> digits={1,2,3,9};
    vector<int> res=plusOne(digits);
    for(auto a:res)
        cout << a << " ";
}