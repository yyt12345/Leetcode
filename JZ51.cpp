/*
 * @Author: your name
 * @Date: 2020-10-29 10:25:45
 * @LastEditTime: 2020-10-29 10:43:56
 * @LastEditors: Please set LastEditors
 * @Description: 
        给定一个数组A[0,1,...,n-1],请构建一个数组B[0,1,...,n-1],其中B中的元素B[i]=A[0]*A[1]*...*A[i-1]*A[i+1]*...*A[n-1]。不能使用除法。（注意：规定B[0] = A[1] * A[2] * ... * A[n-1]，B[n-1] = A[0] * A[1] * ... * A[n-2];）
        对于A长度为1的情况，B无意义，故而无法构建，因此该情况不会存在。
 * @FilePath: /undefined/home/whh/programming/Leetcode/JZ51.cpp
 */
#include <vector>
using namespace std;
class Solution {
public:
// 暴力法
    vector<int> multiply(const vector<int>& A) {
        int n=A.size();
        vector<int> res(n,1);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j) continue;
                res[i]*=A[j];
            }
        }
        return res;
    }
    vector<int> multiply(const vector<int>& A){
        vector<int> B(A.size(),1);
        for(int i=1;i<A.size();i++)
            B[i]=B[i-1]*A[i-1];
        int tmp=1;
        for(int j=A.size()-2;j>=0;j--){
            tmp*=A[j+1];
            B[j]*=tmp;
        }
        return B;
    }
};