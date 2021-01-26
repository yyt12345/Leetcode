/*
 * @Author: your name
 * @Date: 2021-01-26 09:42:37
 * @LastEditTime: 2021-01-26 10:42:10
 * @LastEditors: Please set LastEditors
 * @Description: 剑指 Offer 13. 机器人的运动范围
 * 地上有一个m行n列的方格，从坐标 [0,0] 到坐标 [m-1,n-1] 。一个机器人从坐标 [0, 0] 的格子开始移动，它每
 * 次可以向左、右、上、下移动一格（不能移动到方格外），也不能进入行坐标和列坐标的数位之和大于k的格子。
 * 例如，当k为18时，机器人能够进入方格 [35, 37] ，因为3+5+3+7=18。但它不能进入方格 [35, 38]，因为3+5+3+8=19。
 * 请问该机器人能够到达多少个格子？
 * @FilePath: /offer2/13.cpp
 */
#include <vector>
using namespace std;
class Solution {
    int count;
    int rows,cols,th;
    vector<vector<bool> > flag;
public:
    bool isArea(int i,int j){
        if(i<0 || i>=rows || j<0 || j>=cols) return false;
        int sum=0;
        while(i>0){
            sum+=i%10;
            i /= 10;
        }
        while(j>0){
            sum+=j%10;
            j/=10;
        }
        return sum<=th;
    }
    void dfs(int i,int j){
        if(!isArea(i,j)) return;
        if(flag[i][j]) return;

        count++;
        flag[i][j]=true;
        dfs(i+1,j);
        dfs(i,j+1);
        return;
    }
    int movingCount(int m, int n, int k) {
        if(!m || !n) return 0;
        else if(!k) return 1;
        flag.resize(m,vector<bool>(n,false));
        rows=m;
        cols=n;
        th=k;
        dfs(0,0);
        return count;
    }
};
