/*
 * @Descripttion: 119. 杨辉三角 II
        给定一个非负索引 k，其中 k ≤ 33，返回杨辉三角的第 k 行。
 * @version:    0 ms    100.00%     6.4 MB  100.00%
 * @Author: Ye Yating
 * @Date: 2020-06-04 17:43:09
 * @LastEditors: Ye Yating
 * @LastEditTime: 2020-06-04 17:49:33
 */ 
#include <vector>
#include <iostream>
using namespace std;
vector<int> getRow(int rowIndex) {
    if(rowIndex==0) return {1};
    vector<int> temp={1};
    for(int i=1;i<=rowIndex;i++){
        temp.insert(temp.begin(),1);
        for(int i=1;i<temp.size()-1;i++)
            temp[i]=temp[i]+temp[i+1];
    }
    return temp;
}
int main(){
    vector<int> res=getRow(3);
    for(int a:res)
        cout << a << " ";
}