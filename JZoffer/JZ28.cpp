/*
 * @Author: your name
 * @Date: 2020-10-26 10:08:14
 * @LastEditTime: 2020-10-26 11:10:13
 * @LastEditors: Please set LastEditors
 * @Description: 数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。例如输入一个长度为9的数组{1,2,3,2,2,2,5,4,2}。由于数字2在数组中出现了5次
 * ，超过数组长度的一半，因此输出2。如果不存在则输出0。
 * @FilePath: /undefined/home/whh/programming/Leetcode/JZ28.cpp
 */
#include <map>
#include <iostream>
#include <vector>
#include <iterator>
using namespace std;
class Solution {
public:
// 方法一：哈西
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        int n=numbers.size();
        if(n==0) return 0;
        map<int,int> hash;
        for(auto a:numbers) hash[a]++;
        for(auto a:hash){
            if(a.second>n/2) return a.first;
        }
        return 0;
    }
// 方法二：sort+计数
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        int n=numbers.size();
        if(n==0) return 0;
        sort(numbers.begin(),numbers.end());
        int res=numbers[n/2];
        int count=0;
        for(int a:numbers){
            if(a==res) count++;
        }
        if(count>n/2) return res;
        return 0;
    }    
// 方法三： 加入数组中存在众数，那么众数一定大于数组的长度的一半。候选法 时间复杂度O(n)
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        int count=0;
        int win=0;
        for(int n:numbers){
            if(count==0){
                win=n;
                count=1;
            }else{
                if(win==n) count++;
                else count--;
            }
        }
        count=0;
        for(const int n:numbers){
            if(win==n) count++;
        }
        if(count>numbers.size()/2) return win;
        return 0;
    }   
};
int main(){
    Solution s;
    vector<int> nums={1,2,3,4,2,2,2,2,2,5};
    cout << s.MoreThanHalfNum_Solution(nums) << endl;

}