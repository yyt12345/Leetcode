/*
 * @Descripttion: 
 * @version: 
 * @Author: Ye Yating
 * @Date: 2020-07-27 19:44:09
 * @LastEditors: Ye Yating
 * @LastEditTime: 2020-07-27 21:26:02
 */ 
#include <vector>
#include <iostream>
using namespace std;
//四个点四个点依次转动
// 执行用时：4 ms, 在所有 C++ 提交中击败了62.79% 的用户
// 内存消耗：7.1 MB, 在所有 C++ 提交中击败了100.00% 的用户
void rotate(vector<vector<int>>& matrix) {
    int m=matrix.size();
    if(m==0) return ;
    for(int i=0;i<m/2;i++){
        for(int j=0;j<m-1-2*i;j++){
            int temp=matrix[i][i+j];
            matrix[i][i+j]=matrix[m-1-j-i][i];
            matrix[m-1-j-i][i]=matrix[m-1-i][m-1-j-i];
            matrix[m-1-i][m-1-j-i]=matrix[j+i][m-1-i];
            matrix[j+i][m-1-i]=temp;
        }
    }
}
int main(){
    vector<vector<int> > matrix={
        {1,2,3,10},
        {4,5,6,11},
        {7,8,9,12},
        {13,14,15,16}
    };
    rotate(matrix);
    for(auto num:matrix){
        for(int a:num)
            cout << a << " ";
        cout << endl;
    }
}