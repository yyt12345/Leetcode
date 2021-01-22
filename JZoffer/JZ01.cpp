/*
 * @Author: your name
 * @Date: 2020-10-14 09:08:36
 * @LastEditTime: 2020-10-14 09:58:18
 * @LastEditors: Please set LastEditors
 * @Description: 在一个二维数组中（每个一维数组的长度相同），每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
 * @FilePath: /undefined/home/whh/programming/Leetcode/JZ01.cpp
 */
#include <vector>
#include <iostream>
using std::vector;
class Solution {
public:
//暴力破解法
    bool Find2(int target, vector<vector<int> > array) {
        for(auto row:array){
            for(int a:row){
                if(a==target) return true;
            }
        }
        return false;
    }
//由于单调递增，使用二分法
//对于数组，在访问之前需判断是否为空数组
    bool Find(int target, vector<vector<int> > array) {
        if(array.size()==0 || array[0].size()==0) return false;
        for(vector<int> row:array){
            int start=0;
            int end=row.size()-1;
            if(row[end]<target) continue;
            else if(row[start]>target) break;
 
            while(start<=end){
                int mid=(start+end)>>1;
                if(row[mid]==target) return true;
                else if(row[mid]<target) start=mid+1;
                else if(row[mid]>target) end=mid-1;
            }
        }
        return false;
    }   

//二维二分法
    bool Find(int target, vector<vector<int> > array) {
        if(array.size()==0 || array[0].size()==0) return false;
        int m=array.size(),n=array[0].size();
        int i=0,j=n-1;
        while(i<m && j>=0){
            if(target==array[i][j]) return true;
            else if(target>array[i][j]) i++;
            else j--;
        }
        return false;

    }
};
int main(){
    vector<vector<int>> arrays={
        {1,2,3,4},
        {3,4,6,7},
        {4,6,7,8},
        {10,11,13,14}
    };
    Solution s;
    std::cout << s.Find(4,arrays) << std::endl;
}