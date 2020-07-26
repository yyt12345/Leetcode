/*
 * @Descripttion: 39. 组合总和
        给定一个无重复元素的数组 candidates 和一个目标数 target ，
        找出 candidates 中所有可以使数字和为 target 的组合。
        candidates 中的数字可以无限制重复被选取。
 * @version: 
 * @Author: Ye Yating
 * @Date: 2020-05-17 12:03:58
 * @LastEditors: Ye Yating
 * @LastEditTime: 2020-05-18 12:22:57
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//  8 ms    85.25%      7.8 MB  100.00%
class Solution {
private:
    vector<vector<int> > res;
    vector<int> candidates;
    vector<int> path;
public:
    void DFS(int start,int target){
        if(target==0){
            res.push_back(path);
            return;
        }
        for(int i=start;i<candidates.size();i++){
            if(target>=candidates[i]){
                path.push_back(candidates[i]);
                DFS(i,target-candidates[i]);
                path.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target)
    {
        sort(candidates.begin(),candidates.end(),greater<int>());
        this->candidates=candidates;
        DFS(0,target);
        return res;
    }
};
int main()
{
    vector<int> candidates = { 2, 3, 6, 7 };
    Solution s;
    vector<vector<int> > res=s.combinationSum(candidates,7);
    for(auto arr:res){
        for(int a:arr)
            cout << a << " ";
        cout << endl;
    }
}