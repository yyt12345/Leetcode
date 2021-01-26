/*
 * @Author: your name
 * @Date: 2021-01-26 09:03:27
 * @LastEditTime: 2021-01-26 09:23:39
 * @LastEditors: Please set LastEditors
 * @Description: 剑指 Offer 12. 矩阵中的路径
 * 请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有字符的路径。路径可以从矩阵中的任意一格开始，每一步
 * 可以在矩阵中向左、右、上、下移动一格。如果一条路径经过了矩阵的某一格，那么该路径不能再次进入该格子。例如，在下面的
 * 3×4的矩阵中包含一条字符串“bfce”的路径（路径中的字母用加粗标出）
 * @FilePath: /offer2/12.cpp
 */
#include <vector>
#include <string>
#include <iostream>
using namespace std;
class Solution {
    int m,n;
    bool dfs(vector<vector<char> >& board,string word,int i,int j,int k){
        if(i<0 || i>=m || j<0 || j>=n || board[i][j]!=word[k]) return false;
        if(k==word.size()-1) return true;

        board[i][j]=' ';
        //为什么逻辑运算比位运算快
        bool res=dfs(board,word,i+1,j,k+1) || dfs(board,word,i-1,j,k+1) || dfs(board,word,i,j-1,k+1) || dfs(board,word,i,j+1,k+1);
        board[i][j]=word[k];
        return res;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        if(word.size()==0) return true;

        m=board.size();
        if(m==0) return false;
        n=board[0].size();
        if(n==0) return false;
        if(word.size()>(m*n)) return false;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++)
                if(dfs(board,word,i,j,0)) return true;
        }
        return false;
    }
};
int main(){
    Solution s;
    vector<vector<char> > board={
        {'a'}
    };
    cout << s.exist(board,"ab") << endl;

}