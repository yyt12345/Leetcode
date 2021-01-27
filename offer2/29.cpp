/*
 * @Author: your name
 * @Date: 2021-01-27 18:17:52
 * @LastEditTime: 2021-01-27 18:47:37
 * @LastEditors: Please set LastEditors
 * @Description: 剑指 Offer 29. 顺时针打印矩阵
 * 输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字。
 * @FilePath: /offer2/29.cpp
 */
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int m=matrix.size();
        if(m==0) return res;
        int n=matrix[0].size();
        if(n==0) return res;

        int rowMin=0,rowMax=m-1,colMin=0,colMax=n-1;
        int i=0,j=0;
        while(rowMin<=rowMax && colMin<=colMax){
            while(j<colMax) res.push_back(matrix[i][j++]);
            while(i<rowMax) res.push_back(matrix[i++][j]);
            rowMin++;colMax--;
            if(rowMin>rowMax || colMin>colMax) break;

            while(j>colMin) res.push_back(matrix[i][j--]);
            while(i>rowMin) res.push_back(matrix[i--][j]);
            rowMax--;colMin++;
        }
        res.push_back(matrix[i][j]);
        return res;
    }
};