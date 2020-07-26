/*
 * @Descripttion: 64. 最小路径和
        给定一个包含非负整数的 m x n 网格，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。
        说明：每次只能向下或者向右移动一步。
 * @version: 
 * @Author: Ye Yating
 * @Date: 2020-07-23 09:23:54
 * @LastEditors: Ye Yating
 * @LastEditTime: 2020-07-23 09:23:55
 */ 
#include <vector>
#include <iostream>
using namespace std;
// 执行用时：8 ms, 在所有 C++ 提交中击败了86.80% 的用户
// 内存消耗：8.7 MB, 在所有 C++ 提交中击败了100.00% 的用户
int minPathSum(vector<vector<int>>& grid) {
    int m=grid.size(),n=grid[0].size();
    if(m==0 &&n==0) return 0;

    vector<vector<int> > dp(m, vector<int>(n,0));
    dp[0][0]=grid[0][0];
    for(int j=0;j<m;j++){
        for(int i=0;i<n;i++){
            if(j==0 && i==0) continue;
            int top=INT16_MAX,left=INT16_MAX;
            if(i>0) left=dp[j][i-1];
            if(j>0) top=dp[j-1][i];
            dp[j][i]=grid[j][i]+min(left,top);
        }
    }
    return dp[m-1][n-1];
}
int main(){

}