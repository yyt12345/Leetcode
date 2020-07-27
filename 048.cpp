/*
 * @Descripttion: 48. 旋转图像
        给定一个 n × n 的二维矩阵表示一个图像。
        将图像顺时针旋转 90 度。
        说明：
        你必须在原地旋转图像，这意味着你需要直接修改输入的二维矩阵。请不要使用另一个矩阵来旋转图像。
 * @version: 
 * @Author: Ye Yating
 * @Date: 2020-07-27 19:44:09
 * @LastEditors: Ye Yating
 * @LastEditTime: 2020-07-27 23:58:04
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