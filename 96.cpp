/*
 * @Descripttion: 96. 不同的二叉搜索树
        给定一个整数 n，求以 1 ... n 为节点组成的二叉搜索树有多少种？
 * @version: 
 * @Author: Ye Yating
 * @Date: 2020-07-21 10:00:59
 * @LastEditors: Ye Yating
 * @LastEditTime: 2020-07-21 11:00:22
 */ 
#include <vector>
#include <iostream>
using namespace std;
// 执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
// 内存消耗：6.2 MB, 在所有 C++ 提交中击败了100.00% 的用户
int numTrees(int n) {
    vector<int> dp(n+1,0);
    dp[0]=1;
    dp[1]=1;
    for(int i=2;i<=n;i++){
        for(int j=0;j<i;j++){
            dp[i]+=dp[j]*dp[i-j-1];
        }
    }
    return dp[n];
}
int main(){
    cout << numTrees(3) << endl;
}