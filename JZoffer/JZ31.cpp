/*
 * @Author: your name
 * @Date: 2020-10-14 10:02:50
 * @LastEditTime: 2020-11-05 09:28:26
 * @LastEditors: Please set LastEditors
 * @Description: 求出1~13的整数中1出现的次数,并算出100~1300的整数中1出现的次数？为此他特别数了一下1~13中包含1的数字有1、10、11、12、13因此共出现6次,但是对于后面问题他就没辙了。ACMer希望你们帮帮他,并把问题更加普遍化,可以很快的求出任意非负整数区间中1出现的次数（从1 到 n 中1出现的次数）。
 * @FilePath: /undefined/home/whh/programming/Leetcode/JZ31.cpp
 */
#include <vector>
#include <iostream>
using std::vector;
class Solution {
public:

    int NumberOf1Between1AndN_Solution(int n)
    {
        int count=0;
        for(int i=1;i<=n;i++){
            for(int j=i;j>0;j/=10){
                if(j%10==1) count++;
            }
        }
        return count;
        
    }
};
int main(){
    Solution s;
    std::cout << s.NumberOf1Between1AndN_Solution(55) << std::endl;
}