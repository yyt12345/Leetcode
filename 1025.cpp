/*
 * @Descripttion: 1025. 除数博弈
        爱丽丝和鲍勃一起玩游戏，他们轮流行动。爱丽丝先手开局。
        最初，黑板上有一个数字 N 。在每个玩家的回合，玩家需要执行以下操作：
            选出任一 x，满足 0 < x < N 且 N % x == 0 。
            用 N - x 替换黑板上的数字 N 。
        如果玩家无法执行这些操作，就会输掉游戏。
        只有在爱丽丝在游戏中取得胜利时才返回 True，否则返回 false。假设两个玩家都以最佳状态参与游戏
 * @version: 
 * @Author: Ye Yating
 * @Date: 2020-07-24 10:26:42
 * @LastEditors: Ye Yating
 * @LastEditTime: 2020-07-25 11:07:38
 */ 
#include <vector>
#include <iostream>
using namespace std;
//     数字N如果是奇数，它的约数必然都是奇数；若为偶数，则其约数可奇可偶。
//     无论N初始为多大的值，游戏最终只会进行到N=2时结束，那么谁轮到N=2时谁就会赢。
//     因为爱丽丝先手，N初始若为偶数，爱丽丝则只需一直选1，使鲍勃一直面临N为奇数的情况，这样爱丽丝稳赢；
//     N初始若为奇数，那么爱丽丝第一次选完之后N必为偶数，那么鲍勃只需一直选1就会稳赢。

// 综述，判断N是奇数还是偶数，即可得出最终结果！
bool divisorGame(int N) {
    return N%2==0;
}

//动态规划
// 执行用时：4 ms, 在所有 C++ 提交中击败了44.19% 的用户
// 内存消耗：6.2 MB, 在所有 C++ 提交中击败了100.00% 的用户
bool divisorGame2(int N) {
   if(N==1) return false;
   else if(N==2) return true;

    vector<bool> dp(N+1,false);
    dp[2]=true;
    for(int i=3;i<=N;i++){
        for(int j=1;j<i;j++){
            if(i%j==0 && dp[i-j]==false){
                dp[i]=true;
                break;
            }
        }
    }
    return dp[N];
}