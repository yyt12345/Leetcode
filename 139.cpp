/*
 * @Descripttion: 139. 单词拆分
        给定一个非空字符串 s 和一个包含非空单词列表的字典 wordDict，判定 s 是否可以被空格拆分为一个或多个在字典中出现的单词。
    说明：
        拆分时可以重复使用字典中的单词。
        你可以假设字典中没有重复的单词。
 * @version: 
 * @Author: Ye Yating
 * @Date: 2020-06-09 19:08:17
 * @LastEditors: Ye Yating
 * @LastEditTime: 2020-06-09 21:43:12
 */ 
#include <vector>
#include <iostream>
#include <string>
#include <string.h>
using namespace std;
//递归方法 超出时间限制
bool func(string s,int i,vector<string>& wordDict){
    if(i==s.size()) return true;
    bool flag=false;
    for(int j=0;j<wordDict.size();j++){
        if(s.substr(i,wordDict[j].size())==wordDict[j]) 
            if(func(s,i+wordDict[j].size(),wordDict)) return true;
    }
    return false;
}
bool wordBreak(string s, vector<string>& wordDict) {
    if(wordDict.size()==0) return false;
    return func(s,0,wordDict);
}
//动态规划 12 ms    73.03%      7.4 MB  100.00%
bool wordBreak2(string s, vector<string>& wordDict) {
    int n=s.size();
    vector<bool> dp(n+1,false);
    dp[0]=true;
    for(int i=0;i<=n;i++){
        if(dp[i]==true){
            for(string word:wordDict){
                if(s.substr(i,word.size())==word) dp[i+word.size()]=true;
            }
        }
    }
    return dp[n];
}
int main(){
    vector<string> wordDist={"cats","dog","sand","and","cat"};
    cout << wordBreak2("catsandog",wordDist);

}