/*
 * @Descripttion: 40. 组合总和 II
        给定一个数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。
        candidates 中的每个数字在每个组合中只能使用一次。
 * @version: 
 * @Author: Ye Yating
 * @Date: 2020-05-18 12:23:19
 * @LastEditors: Ye Yating
 * @LastEditTime: 2020-05-18 14:22:24
 */ 
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
class Solution
{
private:
    vector<vector<int> > res;
    vector<int> candidates;
    vector<int> path;
public:
    //  0 ms  100.00%     7.1 MB  100.00%
    void DFS(int start,int target){
        if(target==0){
            res.push_back(path);
            return;
        }
        for(int i=start;i<candidates.size();i++){
            if(i>0 && candidates[i]==candidates[i-1] && i!=start) continue;
            if(target>=candidates[i]){
                path.push_back(candidates[i]);
                DFS(i+1,target-candidates[i]);
                path.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end(),greater<int>());
        this->candidates=candidates;
        DFS(0,target);
        return res;
    }
};
int main(){
    Solution s;
    vector<int> candidate={10,1,2,7,6,1,5};
    auto res=s.combinationSum2(candidate,8);
    for(auto arr:res){
        for(int a:arr)
            cout << a << " ";
        cout << endl;
    }
}

