/*
 * @Descripttion: 49. 字母异位词分组
        给定一个字符串数组，将字母异位词组合在一起。字母异位词指字母相同，但排列不同的字符串。
 * @version: 
 * @Author: Ye Yating
 * @Date: 2020-07-27 21:26:18
 * @LastEditors: Ye Yating
 * @LastEditTime: 2020-07-27 23:57:24
 */ 
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <iostream>
using namespace std;
//哈希算法 超过时间限制
vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<map<char,int> > hash;
    vector<vector<string> > res;
    int n=strs.size();
    for(int i=0;i<n;i++){
        map<char,int> temp;
        bool flag=false;
        for(int j=0;j<strs[i].size();j++){
            temp[strs[i][j]]++;
        }
        if(hash.size()==0){
            hash.push_back(temp);
            res.push_back({});
            res[0].push_back(strs[i]);
            continue;
        }
        for(int j=0;j<hash.size();j++){
            auto it1=temp.begin();
            auto it2=hash[j].begin();
            while(it1!=temp.end() && it2!=hash[j].end()){
                if(it1->first!=it2->first || it1->second!=it2->second)
                    break;
                it1++;
                it2++;
            }
            if(it1==temp.end() && it2==hash[j].end()) {
                res[j].push_back(strs[i]);
                flag=true;
                break;
            }
        }
        if(!flag){
            hash.push_back(temp);
            res.push_back({});
            res[hash.size()-1].push_back(strs[i]);
        }
    }
    return res;
}
// 将每个字符串排序 若未乱序字符则相等
// 执行用时：112 ms, 在所有 C++ 提交中击败了21.92% 的用户
// 内存消耗：14.7 MB, 在所有 C++ 提交中击败了100.00% 的用户
vector<vector<string>> groupAnagrams3(vector<string>& strs) {
    vector<vector<string>> res;
    string tmp;
    int sub=0;
    map<string,int> hash;
    for(auto str:strs){
        tmp=str;
        sort(tmp.begin(),tmp.end());
        if(hash.count(tmp)){
            res[hash[tmp]].push_back(str);            
        }else{
            vector<string> vec(1,str);
            res.push_back(vec);
            hash[tmp]=sub++;
        }
    }
    return res;
}
int main(){
    vector<string> strs={"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string> > res=groupAnagrams3(strs);
    for(auto num:res){
        for(string a:num)
            cout << a << " ";
        cout << endl;
    }
}