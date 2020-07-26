/*
 * @Descripttion: 118. 杨辉三角
        给定一个非负整数 numRows，生成杨辉三角的前 numRows 行。
 * @version: 
 * @Author: Ye Yating
 * @Date: 2020-06-04 17:18:14
 * @LastEditors: Ye Yating
 * @LastEditTime: 2020-06-04 17:41:53
 */ 
#include <vector>
#include <iostream>
using namespace std;
//  0 ms    100.00%     6.7 MB  100.00%
vector<vector<int>> generate(int numRows) {
    vector<vector<int> > res;
    vector<int> temp={1};
    if(numRows==0) return {};
    res.push_back(temp);
    for(int i=1;i<numRows;i++){
        temp.insert(temp.begin(),1);
        for(int i=1;i<temp.size()-1;i++)
            temp[i]=temp[i]+temp[i+1];
        res.push_back(temp);
    }
    return res;    
}
int main(){
    vector<vector<int> > res=generate(5);
    for(auto rows:res){
        for(int a:rows)
            cout << a << " ";
        cout << endl;
    }
}
