/*
 * @Descripttion: 210. 课程表 II
        现在你总共有 n 门课需要选，记为 0 到 n-1。
        在选修某些课程之前需要一些先修课程。 例如，想要学习课程 0 ，你需要先完成课程 1 ，我们用一个匹配来表示他们: [0,1]
        给定课程总量以及它们的先决条件，返回你为了学完所有课程所安排的学习顺序。
        可能会有多个正确的顺序，你只要返回一种就可以了。如果不可能完成所有课程，返回一个空数组。
 * @version: 
 * @Author: Ye Yating
 * @Date: 2020-08-04 11:39:21
 * @LastEditors: Ye Yating
 * @LastEditTime: 2020-08-04 12:04:12
 */
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
// 深度优先
// 执行用时：36 ms, 在所有 C++ 提交中击败了79.94% 的用户
// 内存消耗：12.3 MB, 在所有 C++ 提交中击败了71.34% 的用户
class Solution {
private:
    vector<vector<int>> edges;
    vector<int> indeg; //入度表
    vector<int> res;

public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites)
    {
        edges.resize(numCourses);
        indeg.resize(numCourses);
        for (const auto& info : prerequisites) {
            edges[info[1]].push_back(info[0]);
            indeg[info[0]]++;
        }
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (!indeg[i])
                q.push(i);
        }
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            res.push_back(u);
            for (const int& v : edges[u]) {
                indeg[v]--;
                if (!indeg[v])
                    q.push(v);
            }
        }
        return res.size() == numCourses ? res : vector<int> {};
    }
};
int main()
{
    vector<vector<int>> prerequisties = {
        { 1, 0 }, { 2, 0 }, { 3, 1 }, { 3, 2 }
    };
    Solution s;
    vector<int> res = s.findOrder(4, prerequisties);
    for (int a : res) {
        cout << a << " ";
    }
    cout << endl;
}