/*
 * @Descripttion: 
 * @version: 
 * @Author: Ye Yating
 * @Date: 2020-07-28 11:31:31
 * @LastEditors: Ye Yating
 * @LastEditTime: 2020-07-28 16:44:18
 */ 
#include <vector>
#include <map>
#include <iterator>
#include <iostream>
using namespace std;
bool contain(vector<int> &temp,int a){
    for(int i=0;i<temp.size();i++){
        if(a==temp[i]) return false;
    }
    return true;
}
//用了Hash的方法 有许多边界条件需要处理
// 执行用时：32 ms, 在所有 C++ 提交中击败了89.80% 的用户
// 内存消耗：11.5 MB, 在所有 C++ 提交中击败了100.00% 的用户
vector<vector<int>> merge(vector<vector<int>>& intervals) {
    map<int,int> hash;
    vector<vector<int> > res;
    vector<int> temp;
    for(auto num:intervals){
        hash[num[0]]--;
        hash[num[1]]++;
        if(num[0]==num[1] && contain(temp,num[0])) temp.push_back(num[0]);
    }
    vector<int> tmp;
    for(map<int,int>::iterator it=hash.begin();it!=hash.end();){
        if(it->second==0){
            it++;
        }else if(it->second<0){
            tmp.push_back(it->first);
            it++;
        }else{
            hash[tmp.back()]++;
            hash[it->first]--;
            if(hash[tmp.back()]==0 && hash[it->first]==0){
                if(tmp.size()==1)res.push_back({tmp.back(),it->first});
            }
            if(hash[tmp.back()]==0)
                tmp.pop_back();
            if(hash[it->first]==0) it++;
        }
    }
    for(auto num:res){
        for(int i=0;i<temp.size();i++){
            if(num[0]<=temp[i] && temp[i]<=num[1]) {
                temp.erase(temp.begin()+i);
                i--;
            }
        }
    }
    for(int a:temp){
        res.push_back({a,a});
    }
    return res;
}
int main(){
    vector<vector<int> > intervals={
        // {1,6},{2,6},{7,7}
        // {2,3},{5,5},{2,2},{3,4},{3,4}
        {2,3},{2,2},{3,3},{1,3},{5,7},{2,2},{4,6}
    };
    vector<vector<int>> res=merge(intervals);
    for(auto num:res){
        cout << num[0] << " " << num[1] << endl;
    }
}