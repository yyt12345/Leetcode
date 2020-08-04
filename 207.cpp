/*
 * @Descripttion: 207. 课程表
        你这个学期必须选修 numCourse 门课程，记为 0 到 numCourse-1 。
        在选修某些课程之前需要一些先修课程。 例如，想要学习课程 0 ，你需要先完成课程 1 ，我们用一个匹配来表示他们：[0,1]
        给定课程总量以及它们的先决条件，请你判断是否可能完成所有课程的学习？
 * @version: 
 * @Author: Ye Yating
 * @Date: 2020-06-04 18:22:43
 * @LastEditors: Ye Yating
 * @LastEditTime: 2020-08-04 11:41:15
 */
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
//拓扑有向图 检索是否存在环问题
//深度优先搜索  对每个节点DFS
class Solution {
private:
    vector<vector<int>> edges;
    vector<int> visited;
    bool valid = true;

public:
    void dfs(int u)
    {
        visited[u] = 1;
        for (const int& v : edges[u]) {
            if (visited[v] == 0) {
                dfs(v);
                if (!valid)
                    return;
            } else if (visited[v] == 1) {
                valid = false;
                return;
            }
        }
        visited[u] = 2;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites)
    {
        edges.resize(numCourses);
        visited.resize(numCourses);
        for (const auto& info : prerequisites) {
            edges[info[1]].push_back(info[0]);
        }
        for (int i = 0; i < numCourses && valid; i++) {
            if (!visited[i])
                dfs(i);
        }
        return valid;
    }
};
//广度优先搜索
// 执行用时：32 ms, 在所有 C++ 提交中击败了93.74% 的用户
// 内存消耗：11.8 MB, 在所有 C++ 提交中击败了89.18% 的用户
class Solution2 {
private:
    vector<vector<int>> edges;
    vector<int> indeg;

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites)
    {
        edges.resize(numCourses);
        indeg.resize(numCourses);
        for (const auto& info : prerequisites) {
            edges[info[1]].push_back(info[0]);
            indeg[info[0]]++;
        }
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indeg[i] == 0)
                q.push(i);
        }
        int visited = 0;
        while (!q.empty()) {
            ++visited;
            int u = q.front();
            q.pop();
            for (int v : edges[u]) {
                --indeg[v];
                if (indeg[v] == 0)
                    q.push(v);
            }
        }
        return visited == numCourses;
    }
};