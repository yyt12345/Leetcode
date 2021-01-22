/*
 * @Author: your name
 * @Date: 2020-10-21 19:40:24
 * @LastEditTime: 2020-10-21 21:21:54
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /undefined/home/whh/programming/Leetcode/JZ67.cpp
 */
#include <iostream>
#include <algorithm>
using namespace std;
class Solution {
public:
// 数学方法推倒
    int cutRope(int number) {
        int n=number/3;
        int mod=number%3;
        if(mod==1) return pow(3,n-1)*4;
        else if(mod==2) return pow(3,n)*mod;
        else return pow(3,n);
    }
// 递归
    int back_track(int n){
        if(n<=4) return n;
        int res=0;
        for(int i=1;i<n;i++) 
            res=max(res,back_track(n-i));
        return res;
    }
    int cutRope(int number) {
        if(number<=2) return 1;
        else if(number==3) return 2;
        return back_track(number);
    }
// 进一步优化：小段的线重复计算
    int cutRope(int number) {
        if(number<=2) return 1;
        else if(number==3) return 2;
        vector<int> dp(number+1,0);
        for(int i=0;i<=n;i++){
            if(i<=4) dp[i]=i;
            else{
                for(int j=1;j<i;j++){
                    dp[i]=max(dp[i],dp[i-j]*j);
                }
            }
        }
        return dp[number];
    }
};
int main(){
    Solution s;
    cout << s.cutRope(8) << endl;
}